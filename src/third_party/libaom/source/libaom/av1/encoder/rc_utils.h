/*
 * Copyright (c) 2020, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#ifndef AOM_AV1_ENCODER_RC_UTILS_H_
#define AOM_AV1_ENCODER_RC_UTILS_H_

#include "av1/encoder/encoder.h"
#include "aom_dsp/psnr.h"

#ifdef __cplusplus
extern "C" {
#endif

static AOM_INLINE void set_rc_buffer_sizes(RATE_CONTROL *rc,
                                           const AV1EncoderConfig *oxcf) {
  const int64_t bandwidth = oxcf->target_bandwidth;
  const int64_t starting = oxcf->starting_buffer_level_ms;
  const int64_t optimal = oxcf->optimal_buffer_level_ms;
  const int64_t maximum = oxcf->maximum_buffer_size_ms;

  rc->starting_buffer_level = starting * bandwidth / 1000;
  rc->optimal_buffer_level =
      (optimal == 0) ? bandwidth / 8 : optimal * bandwidth / 1000;
  rc->maximum_buffer_size =
      (maximum == 0) ? bandwidth / 8 : maximum * bandwidth / 1000;
}

static AOM_INLINE void config_target_level(AV1_COMP *const cpi,
                                           AV1_LEVEL target_level, int tier) {
  aom_clear_system_state();

  AV1EncoderConfig *const oxcf = &cpi->oxcf;
  SequenceHeader *const seq_params = &cpi->common.seq_params;
  TileConfig *const tile_cfg = &oxcf->tile_cfg;

  // Adjust target bitrate to be no larger than 70% of level limit.
  const BITSTREAM_PROFILE profile = seq_params->profile;
  const double level_bitrate_limit =
      av1_get_max_bitrate_for_level(target_level, tier, profile);
  const int64_t max_bitrate = (int64_t)(level_bitrate_limit * 0.70);
  oxcf->target_bandwidth = AOMMIN(oxcf->target_bandwidth, max_bitrate);
  // Also need to update cpi->twopass.bits_left.
  TWO_PASS *const twopass = &cpi->twopass;
  FIRSTPASS_STATS *stats = twopass->stats_buf_ctx->total_stats;
  if (stats != NULL)
    cpi->twopass.bits_left =
        (int64_t)(stats->duration * cpi->oxcf.target_bandwidth / 10000000.0);

  // Adjust max over-shoot percentage.
  oxcf->over_shoot_pct = 0;

  // Adjust max quantizer.
  oxcf->worst_allowed_q = 255;

  // Adjust number of tiles and tile columns to be under level limit.
  int max_tiles, max_tile_cols;
  av1_get_max_tiles_for_level(target_level, &max_tiles, &max_tile_cols);
  while (tile_cfg->tile_columns > 0 &&
         (1 << tile_cfg->tile_columns) > max_tile_cols) {
    --tile_cfg->tile_columns;
  }
  const int tile_cols = (1 << tile_cfg->tile_columns);
  while (tile_cfg->tile_rows > 0 &&
         tile_cols * (1 << tile_cfg->tile_rows) > max_tiles) {
    --tile_cfg->tile_rows;
  }

  // Adjust min compression ratio.
  const int still_picture = seq_params->still_picture;
  const double min_cr =
      av1_get_min_cr_for_level(target_level, tier, still_picture);
  oxcf->min_cr = AOMMAX(oxcf->min_cr, (unsigned int)(min_cr * 100));
}

#if !CONFIG_REALTIME_ONLY
// Function to test for conditions that indicate we should loop
// back and recode a frame.
static AOM_INLINE int recode_loop_test(AV1_COMP *cpi, int high_limit,
                                       int low_limit, int q, int maxq,
                                       int minq) {
  const RATE_CONTROL *const rc = &cpi->rc;
  const AV1EncoderConfig *const oxcf = &cpi->oxcf;
  const int frame_is_kfgfarf = frame_is_kf_gf_arf(cpi);
  int force_recode = 0;

  if ((rc->projected_frame_size >= rc->max_frame_bandwidth) ||
      (cpi->sf.hl_sf.recode_loop == ALLOW_RECODE) ||
      (frame_is_kfgfarf &&
       (cpi->sf.hl_sf.recode_loop == ALLOW_RECODE_KFARFGF))) {
    // TODO(agrange) high_limit could be greater than the scale-down threshold.
    if ((rc->projected_frame_size > high_limit && q < maxq) ||
        (rc->projected_frame_size < low_limit && q > minq)) {
      force_recode = 1;
    } else if (cpi->oxcf.rc_mode == AOM_CQ) {
      // Deal with frame undershoot and whether or not we are
      // below the automatically set cq level.
      if (q > oxcf->cq_level &&
          rc->projected_frame_size < ((rc->this_frame_target * 7) >> 3)) {
        force_recode = 1;
      }
    }
  }
  return force_recode;
}

static AOM_INLINE double av1_get_gfu_boost_projection_factor(double min_factor,
                                                             double max_factor,
                                                             int frame_count) {
  double factor = sqrt((double)frame_count);
  factor = AOMMIN(factor, max_factor);
  factor = AOMMAX(factor, min_factor);
  factor = (200.0 + 10.0 * factor);
  return factor;
}

static AOM_INLINE int get_gfu_boost_from_r0_lap(double min_factor,
                                                double max_factor, double r0,
                                                int frames_to_key) {
  double factor = av1_get_gfu_boost_projection_factor(min_factor, max_factor,
                                                      frames_to_key);
  const int boost = (int)rint(factor / r0);
  return boost;
}

static AOM_INLINE double av1_get_kf_boost_projection_factor(int frame_count) {
  double factor = sqrt((double)frame_count);
  factor = AOMMIN(factor, 10.0);
  factor = AOMMAX(factor, 4.0);
  factor = (75.0 + 14.0 * factor);
  return factor;
}

static AOM_INLINE int get_kf_boost_from_r0(double r0, int frames_to_key) {
  double factor = av1_get_kf_boost_projection_factor(frames_to_key);
  const int boost = (int)rint(factor / r0);
  return boost;
}

static AOM_INLINE int get_regulated_q_overshoot(AV1_COMP *const cpi, int q_low,
                                                int q_high, int top_index,
                                                int bottom_index) {
  const AV1_COMMON *const cm = &cpi->common;
  const RATE_CONTROL *const rc = &cpi->rc;

  av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);

  int q_regulated =
      av1_rc_regulate_q(cpi, rc->this_frame_target, bottom_index,
                        AOMMAX(q_high, top_index), cm->width, cm->height);

  int retries = 0;
  while (q_regulated < q_low && retries < 10) {
    av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);
    q_regulated =
        av1_rc_regulate_q(cpi, rc->this_frame_target, bottom_index,
                          AOMMAX(q_high, top_index), cm->width, cm->height);
    retries++;
  }
  return q_regulated;
}

static AOM_INLINE int get_regulated_q_undershoot(AV1_COMP *const cpi,
                                                 int q_high, int top_index,
                                                 int bottom_index) {
  const AV1_COMMON *const cm = &cpi->common;
  const RATE_CONTROL *const rc = &cpi->rc;

  av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);
  int q_regulated = av1_rc_regulate_q(cpi, rc->this_frame_target, bottom_index,
                                      top_index, cm->width, cm->height);

  int retries = 0;
  while (q_regulated > q_high && retries < 10) {
    av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);
    q_regulated = av1_rc_regulate_q(cpi, rc->this_frame_target, bottom_index,
                                    top_index, cm->width, cm->height);
    retries++;
  }
  return q_regulated;
}

// Called after encode_with_recode_loop() has just encoded a frame and packed
// its bitstream.  This function works out whether we under- or over-shot
// our bitrate target and adjusts q as appropriate.  Also decides whether
// or not we should do another recode loop, indicated by *loop
static AOM_INLINE void recode_loop_update_q(
    AV1_COMP *const cpi, int *const loop, int *const q, int *const q_low,
    int *const q_high, const int top_index, const int bottom_index,
    int *const undershoot_seen, int *const overshoot_seen,
    int *const low_cr_seen, const int loop_at_this_size) {
  AV1_COMMON *const cm = &cpi->common;
  RATE_CONTROL *const rc = &cpi->rc;
  *loop = 0;

  const int min_cr = cpi->oxcf.min_cr;
  if (min_cr > 0) {
    aom_clear_system_state();
    const double compression_ratio =
        av1_get_compression_ratio(cm, rc->projected_frame_size >> 3);
    const double target_cr = min_cr / 100.0;
    if (compression_ratio < target_cr) {
      *low_cr_seen = 1;
      if (*q < rc->worst_quality) {
        const double cr_ratio = target_cr / compression_ratio;
        const int projected_q = AOMMAX(*q + 1, (int)(*q * cr_ratio * cr_ratio));
        *q = AOMMIN(AOMMIN(projected_q, *q + 32), rc->worst_quality);
        *q_low = AOMMAX(*q, *q_low);
        *q_high = AOMMAX(*q, *q_high);
        *loop = 1;
      }
    }
    if (*low_cr_seen) return;
  }

  if (cpi->oxcf.rc_mode == AOM_Q) return;

  const int last_q = *q;
  int frame_over_shoot_limit = 0, frame_under_shoot_limit = 0;
  av1_rc_compute_frame_size_bounds(cpi, rc->this_frame_target,
                                   &frame_under_shoot_limit,
                                   &frame_over_shoot_limit);
  if (frame_over_shoot_limit == 0) frame_over_shoot_limit = 1;

  if (cm->current_frame.frame_type == KEY_FRAME && rc->this_key_frame_forced &&
      rc->projected_frame_size < rc->max_frame_bandwidth) {
    int64_t kf_err;
    const int64_t high_err_target = cpi->ambient_err;
    const int64_t low_err_target = cpi->ambient_err >> 1;

#if CONFIG_AV1_HIGHBITDEPTH
    if (cm->seq_params.use_highbitdepth) {
      kf_err = aom_highbd_get_y_sse(cpi->source, &cm->cur_frame->buf);
    } else {
      kf_err = aom_get_y_sse(cpi->source, &cm->cur_frame->buf);
    }
#else
    kf_err = aom_get_y_sse(cpi->source, &cm->cur_frame->buf);
#endif
    // Prevent possible divide by zero error below for perfect KF
    kf_err += !kf_err;

    // The key frame is not good enough or we can afford
    // to make it better without undue risk of popping.
    if ((kf_err > high_err_target &&
         rc->projected_frame_size <= frame_over_shoot_limit) ||
        (kf_err > low_err_target &&
         rc->projected_frame_size <= frame_under_shoot_limit)) {
      // Lower q_high
      *q_high = AOMMAX(*q - 1, *q_low);

      // Adjust Q
      *q = (int)((*q * high_err_target) / kf_err);
      *q = AOMMIN(*q, (*q_high + *q_low) >> 1);
    } else if (kf_err < low_err_target &&
               rc->projected_frame_size >= frame_under_shoot_limit) {
      // The key frame is much better than the previous frame
      // Raise q_low
      *q_low = AOMMIN(*q + 1, *q_high);

      // Adjust Q
      *q = (int)((*q * low_err_target) / kf_err);
      *q = AOMMIN(*q, (*q_high + *q_low + 1) >> 1);
    }

    // Clamp Q to upper and lower limits:
    *q = clamp(*q, *q_low, *q_high);
    *loop = (*q != last_q);
    return;
  }

  if (recode_loop_test(cpi, frame_over_shoot_limit, frame_under_shoot_limit, *q,
                       AOMMAX(*q_high, top_index), bottom_index)) {
    // Is the projected frame size out of range and are we allowed
    // to attempt to recode.

    // Frame size out of permitted range:
    // Update correction factor & compute new Q to try...
    // Frame is too large
    if (rc->projected_frame_size > rc->this_frame_target) {
      // Special case if the projected size is > the max allowed.
      if (*q == *q_high &&
          rc->projected_frame_size >= rc->max_frame_bandwidth) {
        const double q_val_high_current =
            av1_convert_qindex_to_q(*q_high, cm->seq_params.bit_depth);
        const double q_val_high_new =
            q_val_high_current *
            ((double)rc->projected_frame_size / rc->max_frame_bandwidth);
        *q_high = av1_find_qindex(q_val_high_new, cm->seq_params.bit_depth,
                                  rc->best_quality, rc->worst_quality);
      }

      // Raise Qlow as to at least the current value
      *q_low = AOMMIN(*q + 1, *q_high);

      if (*undershoot_seen || loop_at_this_size > 2 ||
          (loop_at_this_size == 2 && !frame_is_intra_only(cm))) {
        av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);

        *q = (*q_high + *q_low + 1) / 2;
      } else if (loop_at_this_size == 2 && frame_is_intra_only(cm)) {
        const int q_mid = (*q_high + *q_low + 1) / 2;
        const int q_regulated = get_regulated_q_overshoot(
            cpi, *q_low, *q_high, top_index, bottom_index);
        // Get 'q' in-between 'q_mid' and 'q_regulated' for a smooth
        // transition between loop_at_this_size < 2 and loop_at_this_size > 2.
        *q = (q_mid + q_regulated + 1) / 2;
      } else {
        *q = get_regulated_q_overshoot(cpi, *q_low, *q_high, top_index,
                                       bottom_index);
      }

      *overshoot_seen = 1;
    } else {
      // Frame is too small
      *q_high = AOMMAX(*q - 1, *q_low);

      if (*overshoot_seen || loop_at_this_size > 2 ||
          (loop_at_this_size == 2 && !frame_is_intra_only(cm))) {
        av1_rc_update_rate_correction_factors(cpi, cm->width, cm->height);
        *q = (*q_high + *q_low) / 2;
      } else if (loop_at_this_size == 2 && frame_is_intra_only(cm)) {
        const int q_mid = (*q_high + *q_low) / 2;
        const int q_regulated =
            get_regulated_q_undershoot(cpi, *q_high, top_index, bottom_index);
        // Get 'q' in-between 'q_mid' and 'q_regulated' for a smooth
        // transition between loop_at_this_size < 2 and loop_at_this_size > 2.
        *q = (q_mid + q_regulated) / 2;

        // Special case reset for qlow for constrained quality.
        // This should only trigger where there is very substantial
        // undershoot on a frame and the auto cq level is above
        // the user passsed in value.
        if (cpi->oxcf.rc_mode == AOM_CQ && q_regulated < *q_low) {
          *q_low = *q;
        }
      } else {
        *q = get_regulated_q_undershoot(cpi, *q_high, top_index, bottom_index);

        // Special case reset for qlow for constrained quality.
        // This should only trigger where there is very substantial
        // undershoot on a frame and the auto cq level is above
        // the user passsed in value.
        if (cpi->oxcf.rc_mode == AOM_CQ && *q < *q_low) {
          *q_low = *q;
        }
      }

      *undershoot_seen = 1;
    }

    // Clamp Q to upper and lower limits:
    *q = clamp(*q, *q_low, *q_high);
  }

  *loop = (*q != last_q);
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AOM_AV1_ENCODER_RC_UTILS_H_
