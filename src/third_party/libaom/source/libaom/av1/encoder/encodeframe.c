/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "config/aom_config.h"
#include "config/aom_dsp_rtcd.h"
#include "config/av1_rtcd.h"

#include "aom_dsp/aom_dsp_common.h"
#include "aom_dsp/binary_codes_writer.h"
#include "aom_ports/mem.h"
#include "aom_ports/aom_timer.h"
#include "aom_ports/system_state.h"

#if CONFIG_MISMATCH_DEBUG
#include "aom_util/debug_util.h"
#endif  // CONFIG_MISMATCH_DEBUG

#include "av1/common/cfl.h"
#include "av1/common/common.h"
#include "av1/common/entropy.h"
#include "av1/common/entropymode.h"
#include "av1/common/idct.h"
#include "av1/common/mv.h"
#include "av1/common/mvref_common.h"
#include "av1/common/pred_common.h"
#include "av1/common/quant_common.h"
#include "av1/common/reconintra.h"
#include "av1/common/reconinter.h"
#include "av1/common/seg_common.h"
#include "av1/common/tile_common.h"
#include "av1/common/warped_motion.h"

#include "av1/encoder/aq_complexity.h"
#include "av1/encoder/aq_cyclicrefresh.h"
#include "av1/encoder/aq_variance.h"
#include "av1/encoder/global_motion_facade.h"
#include "av1/encoder/encodeframe.h"
#include "av1/encoder/encodemb.h"
#include "av1/encoder/encodemv.h"
#include "av1/encoder/encodetxb.h"
#include "av1/encoder/ethread.h"
#include "av1/encoder/extend.h"
#include "av1/encoder/ml.h"
#include "av1/encoder/motion_search_facade.h"
#include "av1/encoder/partition_strategy.h"
#if !CONFIG_REALTIME_ONLY
#include "av1/encoder/partition_model_weights.h"
#endif
#include "av1/encoder/rd.h"
#include "av1/encoder/rdopt.h"
#include "av1/encoder/reconinter_enc.h"
#include "av1/encoder/segmentation.h"
#include "av1/encoder/tokenize.h"
#include "av1/encoder/tpl_model.h"
#include "av1/encoder/var_based_part.h"

#if CONFIG_TUNE_VMAF
#include "av1/encoder/tune_vmaf.h"
#endif

static AOM_INLINE void encode_superblock(const AV1_COMP *const cpi,
                                         TileDataEnc *tile_data, ThreadData *td,
                                         TokenExtra **t, RUN_TYPE dry_run,
                                         BLOCK_SIZE bsize, int *rate);
/*!\cond */
// This is used as a reference when computing the source variance for the
//  purposes of activity masking.
// Eventually this should be replaced by custom no-reference routines,
//  which will be faster.
const uint8_t AV1_VAR_OFFS[MAX_SB_SIZE] = {
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128
};

static const uint16_t AV1_HIGH_VAR_OFFS_8[MAX_SB_SIZE] = {
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
  128, 128, 128, 128, 128, 128, 128, 128
};

static const uint16_t AV1_HIGH_VAR_OFFS_10[MAX_SB_SIZE] = {
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4,
  128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4, 128 * 4
};

static const uint16_t AV1_HIGH_VAR_OFFS_12[MAX_SB_SIZE] = {
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16, 128 * 16,
  128 * 16, 128 * 16
};

typedef struct {
  ENTROPY_CONTEXT a[MAX_MIB_SIZE * MAX_MB_PLANE];
  ENTROPY_CONTEXT l[MAX_MIB_SIZE * MAX_MB_PLANE];
  PARTITION_CONTEXT sa[MAX_MIB_SIZE];
  PARTITION_CONTEXT sl[MAX_MIB_SIZE];
  TXFM_CONTEXT *p_ta;
  TXFM_CONTEXT *p_tl;
  TXFM_CONTEXT ta[MAX_MIB_SIZE];
  TXFM_CONTEXT tl[MAX_MIB_SIZE];
} RD_SEARCH_MACROBLOCK_CONTEXT;

enum { PICK_MODE_RD = 0, PICK_MODE_NONRD };

enum {
  SB_SINGLE_PASS,  // Single pass encoding: all ctxs get updated normally
  SB_DRY_PASS,     // First pass of multi-pass: does not update the ctxs
  SB_WET_PASS      // Second pass of multi-pass: finalize and update the ctx
} UENUM1BYTE(SB_MULTI_PASS_MODE);

// This struct is used to store the statistics used by sb-level multi-pass
// encoding. Currently, this is only used to make a copy of the state before we
// perform the first pass
typedef struct SB_FIRST_PASS_STATS {
  RD_SEARCH_MACROBLOCK_CONTEXT x_ctx;
  RD_COUNTS rd_count;

  int split_count;
  FRAME_COUNTS fc;
  InterModeRdModel inter_mode_rd_models[BLOCK_SIZES_ALL];
  int thresh_freq_fact[BLOCK_SIZES_ALL][MAX_MODES];
  int current_qindex;

#if CONFIG_INTERNAL_STATS
  unsigned int mode_chosen_counts[MAX_MODES];
#endif  // CONFIG_INTERNAL_STATS
} SB_FIRST_PASS_STATS;
/*!\endcond */

unsigned int av1_get_sby_perpixel_variance(const AV1_COMP *cpi,
                                           const struct buf_2d *ref,
                                           BLOCK_SIZE bs) {
  unsigned int sse;
  const unsigned int var =
      cpi->fn_ptr[bs].vf(ref->buf, ref->stride, AV1_VAR_OFFS, 0, &sse);
  return ROUND_POWER_OF_TWO(var, num_pels_log2_lookup[bs]);
}

unsigned int av1_high_get_sby_perpixel_variance(const AV1_COMP *cpi,
                                                const struct buf_2d *ref,
                                                BLOCK_SIZE bs, int bd) {
  unsigned int var, sse;
  assert(bd == 8 || bd == 10 || bd == 12);
  const int off_index = (bd - 8) >> 1;
  const uint16_t *high_var_offs[3] = { AV1_HIGH_VAR_OFFS_8,
                                       AV1_HIGH_VAR_OFFS_10,
                                       AV1_HIGH_VAR_OFFS_12 };
  var =
      cpi->fn_ptr[bs].vf(ref->buf, ref->stride,
                         CONVERT_TO_BYTEPTR(high_var_offs[off_index]), 0, &sse);
  return ROUND_POWER_OF_TWO(var, num_pels_log2_lookup[bs]);
}

static unsigned int get_sby_perpixel_diff_variance(const AV1_COMP *const cpi,
                                                   const struct buf_2d *ref,
                                                   int mi_row, int mi_col,
                                                   BLOCK_SIZE bs) {
  unsigned int sse, var;
  uint8_t *last_y;
  const YV12_BUFFER_CONFIG *last =
      get_ref_frame_yv12_buf(&cpi->common, LAST_FRAME);

  assert(last != NULL);
  last_y =
      &last->y_buffer[mi_row * MI_SIZE * last->y_stride + mi_col * MI_SIZE];
  var = cpi->fn_ptr[bs].vf(ref->buf, ref->stride, last_y, last->y_stride, &sse);
  return ROUND_POWER_OF_TWO(var, num_pels_log2_lookup[bs]);
}

static BLOCK_SIZE get_rd_var_based_fixed_partition(AV1_COMP *cpi, MACROBLOCK *x,
                                                   int mi_row, int mi_col) {
  unsigned int var = get_sby_perpixel_diff_variance(
      cpi, &x->plane[0].src, mi_row, mi_col, BLOCK_64X64);
  if (var < 8)
    return BLOCK_64X64;
  else if (var < 128)
    return BLOCK_32X32;
  else if (var < 2048)
    return BLOCK_16X16;
  else
    return BLOCK_8X8;
}

static int set_deltaq_rdmult(const AV1_COMP *const cpi,
                             const MACROBLOCK *const x) {
  const AV1_COMMON *const cm = &cpi->common;
  const CommonQuantParams *quant_params = &cm->quant_params;
  return av1_compute_rd_mult(cpi, quant_params->base_qindex + x->delta_qindex +
                                      quant_params->y_dc_delta_q);
}

static AOM_INLINE void set_ssim_rdmult(const AV1_COMP *const cpi,
                                       MvCosts *const mv_costs,
                                       const BLOCK_SIZE bsize, const int mi_row,
                                       const int mi_col, int *const rdmult) {
  const AV1_COMMON *const cm = &cpi->common;

  const int bsize_base = BLOCK_16X16;
  const int num_mi_w = mi_size_wide[bsize_base];
  const int num_mi_h = mi_size_high[bsize_base];
  const int num_cols = (cm->mi_params.mi_cols + num_mi_w - 1) / num_mi_w;
  const int num_rows = (cm->mi_params.mi_rows + num_mi_h - 1) / num_mi_h;
  const int num_bcols = (mi_size_wide[bsize] + num_mi_w - 1) / num_mi_w;
  const int num_brows = (mi_size_high[bsize] + num_mi_h - 1) / num_mi_h;
  int row, col;
  double num_of_mi = 0.0;
  double geom_mean_of_scale = 0.0;

  assert(cpi->oxcf.tuning == AOM_TUNE_SSIM);

  aom_clear_system_state();
  for (row = mi_row / num_mi_w;
       row < num_rows && row < mi_row / num_mi_w + num_brows; ++row) {
    for (col = mi_col / num_mi_h;
         col < num_cols && col < mi_col / num_mi_h + num_bcols; ++col) {
      const int index = row * num_cols + col;
      geom_mean_of_scale += log(cpi->ssim_rdmult_scaling_factors[index]);
      num_of_mi += 1.0;
    }
  }
  geom_mean_of_scale = exp(geom_mean_of_scale / num_of_mi);

  *rdmult = (int)((double)(*rdmult) * geom_mean_of_scale + 0.5);
  *rdmult = AOMMAX(*rdmult, 0);
  av1_set_error_per_bit(mv_costs, *rdmult);
  aom_clear_system_state();
}

static int get_hier_tpl_rdmult(const AV1_COMP *const cpi, MACROBLOCK *const x,
                               const BLOCK_SIZE bsize, const int mi_row,
                               const int mi_col, int orig_rdmult) {
  const AV1_COMMON *const cm = &cpi->common;
  assert(IMPLIES(cpi->gf_group.size > 0,
                 cpi->gf_group.index < cpi->gf_group.size));
  const int tpl_idx = cpi->gf_group.index;
  const TplDepFrame *tpl_frame = &cpi->tpl_data.tpl_frame[tpl_idx];
  const int deltaq_rdmult = set_deltaq_rdmult(cpi, x);
  if (tpl_frame->is_valid == 0) return deltaq_rdmult;
  if (!is_frame_tpl_eligible((AV1_COMP *)cpi)) return deltaq_rdmult;
  if (tpl_idx >= MAX_TPL_FRAME_IDX) return deltaq_rdmult;
  if (cpi->superres_mode != AOM_SUPERRES_NONE) return deltaq_rdmult;
  if (cpi->oxcf.aq_mode != NO_AQ) return deltaq_rdmult;

  const int bsize_base = BLOCK_16X16;
  const int num_mi_w = mi_size_wide[bsize_base];
  const int num_mi_h = mi_size_high[bsize_base];
  const int num_cols = (cm->mi_params.mi_cols + num_mi_w - 1) / num_mi_w;
  const int num_rows = (cm->mi_params.mi_rows + num_mi_h - 1) / num_mi_h;
  const int num_bcols = (mi_size_wide[bsize] + num_mi_w - 1) / num_mi_w;
  const int num_brows = (mi_size_high[bsize] + num_mi_h - 1) / num_mi_h;
  int row, col;
  double base_block_count = 0.0;
  double geom_mean_of_scale = 0.0;
  aom_clear_system_state();
  for (row = mi_row / num_mi_w;
       row < num_rows && row < mi_row / num_mi_w + num_brows; ++row) {
    for (col = mi_col / num_mi_h;
         col < num_cols && col < mi_col / num_mi_h + num_bcols; ++col) {
      const int index = row * num_cols + col;
      geom_mean_of_scale += log(cpi->tpl_sb_rdmult_scaling_factors[index]);
      base_block_count += 1.0;
    }
  }
  geom_mean_of_scale = exp(geom_mean_of_scale / base_block_count);
  int rdmult = (int)((double)orig_rdmult * geom_mean_of_scale + 0.5);
  rdmult = AOMMAX(rdmult, 0);
  av1_set_error_per_bit(&x->mv_costs, rdmult);
  aom_clear_system_state();
  if (bsize == cm->seq_params.sb_size) {
    const int rdmult_sb = set_deltaq_rdmult(cpi, x);
    assert(rdmult_sb == rdmult);
    (void)rdmult_sb;
  }
  return rdmult;
}

static int set_segment_rdmult(const AV1_COMP *const cpi, MACROBLOCK *const x,
                              int8_t segment_id) {
  const AV1_COMMON *const cm = &cpi->common;
  av1_init_plane_quantizers(cpi, x, segment_id);
  aom_clear_system_state();
  const int segment_qindex =
      av1_get_qindex(&cm->seg, segment_id, cm->quant_params.base_qindex);
  return av1_compute_rd_mult(cpi,
                             segment_qindex + cm->quant_params.y_dc_delta_q);
}

static AOM_INLINE void setup_block_rdmult(const AV1_COMP *const cpi,
                                          MACROBLOCK *const x, int mi_row,
                                          int mi_col, BLOCK_SIZE bsize,
                                          AQ_MODE aq_mode, MB_MODE_INFO *mbmi) {
  x->rdmult = cpi->rd.RDMULT;

  if (aq_mode != NO_AQ) {
    assert(mbmi != NULL);
    if (aq_mode == VARIANCE_AQ) {
      if (cpi->vaq_refresh) {
        const int energy = bsize <= BLOCK_16X16
                               ? x->mb_energy
                               : av1_log_block_var(cpi, x, bsize);
        mbmi->segment_id = energy;
      }
      x->rdmult = set_segment_rdmult(cpi, x, mbmi->segment_id);
    } else if (aq_mode == COMPLEXITY_AQ) {
      x->rdmult = set_segment_rdmult(cpi, x, mbmi->segment_id);
    } else if (aq_mode == CYCLIC_REFRESH_AQ) {
      // If segment is boosted, use rdmult for that segment.
      if (cyclic_refresh_segment_id_boosted(mbmi->segment_id))
        x->rdmult = av1_cyclic_refresh_get_rdmult(cpi->cyclic_refresh);
    }
  }

  const AV1_COMMON *const cm = &cpi->common;
  if (cm->delta_q_info.delta_q_present_flag &&
      !cpi->sf.rt_sf.use_nonrd_pick_mode) {
    x->rdmult = get_hier_tpl_rdmult(cpi, x, bsize, mi_row, mi_col, x->rdmult);
  }

  if (cpi->oxcf.tuning == AOM_TUNE_SSIM) {
    set_ssim_rdmult(cpi, &x->mv_costs, bsize, mi_row, mi_col, &x->rdmult);
  }
#if CONFIG_TUNE_VMAF
  if (cpi->oxcf.tuning == AOM_TUNE_VMAF_WITHOUT_PREPROCESSING ||
      cpi->oxcf.tuning == AOM_TUNE_VMAF_MAX_GAIN) {
    av1_set_vmaf_rdmult(cpi, x, bsize, mi_row, mi_col, &x->rdmult);
  }
#endif
}

static AOM_INLINE void set_offsets_without_segment_id(
    const AV1_COMP *const cpi, const TileInfo *const tile, MACROBLOCK *const x,
    int mi_row, int mi_col, BLOCK_SIZE bsize) {
  const AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCKD *const xd = &x->e_mbd;
  assert(bsize < BLOCK_SIZES_ALL);
  const int mi_width = mi_size_wide[bsize];
  const int mi_height = mi_size_high[bsize];

  set_mode_info_offsets(&cpi->common.mi_params, &cpi->mbmi_ext_info, x, xd,
                        mi_row, mi_col);

  set_entropy_context(xd, mi_row, mi_col, num_planes);
  xd->above_txfm_context = cm->above_contexts.txfm[tile->tile_row] + mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);

  // Set up destination pointers.
  av1_setup_dst_planes(xd->plane, bsize, &cm->cur_frame->buf, mi_row, mi_col, 0,
                       num_planes);

  // Set up limit values for MV components.
  // Mv beyond the range do not produce new/different prediction block.
  av1_set_mv_limits(&cm->mi_params, &x->mv_limits, mi_row, mi_col, mi_height,
                    mi_width, cpi->oxcf.border_in_pixels);

  set_plane_n4(xd, mi_width, mi_height, num_planes);

  // Set up distance of MB to edge of frame in 1/8th pel units.
  assert(!(mi_col & (mi_width - 1)) && !(mi_row & (mi_height - 1)));
  set_mi_row_col(xd, tile, mi_row, mi_height, mi_col, mi_width,
                 cm->mi_params.mi_rows, cm->mi_params.mi_cols);

  // Set up source buffers.
  av1_setup_src_planes(x, cpi->source, mi_row, mi_col, num_planes, bsize);

  // required by av1_append_sub8x8_mvs_for_idx() and av1_find_best_ref_mvs()
  xd->tile = *tile;
}

static AOM_INLINE void set_offsets(const AV1_COMP *const cpi,
                                   const TileInfo *const tile,
                                   MACROBLOCK *const x, int mi_row, int mi_col,
                                   BLOCK_SIZE bsize) {
  const AV1_COMMON *const cm = &cpi->common;
  const struct segmentation *const seg = &cm->seg;
  MACROBLOCKD *const xd = &x->e_mbd;
  MB_MODE_INFO *mbmi;

  set_offsets_without_segment_id(cpi, tile, x, mi_row, mi_col, bsize);

  // Setup segment ID.
  mbmi = xd->mi[0];
  mbmi->segment_id = 0;
  if (seg->enabled) {
    if (seg->enabled && !cpi->vaq_refresh) {
      const uint8_t *const map =
          seg->update_map ? cpi->enc_seg.map : cm->last_frame_seg_map;
      mbmi->segment_id =
          map ? get_segment_id(&cm->mi_params, map, bsize, mi_row, mi_col) : 0;
    }
    av1_init_plane_quantizers(cpi, x, mbmi->segment_id);
  }
}

static AOM_INLINE void update_filter_type_count(FRAME_COUNTS *counts,
                                                const MACROBLOCKD *xd,
                                                const MB_MODE_INFO *mbmi) {
  int dir;
  for (dir = 0; dir < 2; ++dir) {
    const int ctx = av1_get_pred_context_switchable_interp(xd, dir);
    InterpFilter filter = av1_extract_interp_filter(mbmi->interp_filters, dir);
    ++counts->switchable_interp[ctx][filter];
  }
}

static AOM_INLINE void update_filter_type_cdf(const MACROBLOCKD *xd,
                                              const MB_MODE_INFO *mbmi) {
  int dir;
  for (dir = 0; dir < 2; ++dir) {
    const int ctx = av1_get_pred_context_switchable_interp(xd, dir);
    InterpFilter filter = av1_extract_interp_filter(mbmi->interp_filters, dir);
    update_cdf(xd->tile_ctx->switchable_interp_cdf[ctx], filter,
               SWITCHABLE_FILTERS);
  }
}

static AOM_INLINE void update_global_motion_used(PREDICTION_MODE mode,
                                                 BLOCK_SIZE bsize,
                                                 const MB_MODE_INFO *mbmi,
                                                 RD_COUNTS *rdc) {
  if (mode == GLOBALMV || mode == GLOBAL_GLOBALMV) {
    const int num_4x4s = mi_size_wide[bsize] * mi_size_high[bsize];
    int ref;
    for (ref = 0; ref < 1 + has_second_ref(mbmi); ++ref) {
      rdc->global_motion_used[mbmi->ref_frame[ref]] += num_4x4s;
    }
  }
}

static AOM_INLINE void reset_tx_size(MACROBLOCK *x, MB_MODE_INFO *mbmi,
                                     const TX_MODE tx_mode) {
  MACROBLOCKD *const xd = &x->e_mbd;
  TxfmSearchInfo *txfm_info = &x->txfm_search_info;
  if (xd->lossless[mbmi->segment_id]) {
    mbmi->tx_size = TX_4X4;
  } else if (tx_mode != TX_MODE_SELECT) {
    mbmi->tx_size = tx_size_from_tx_mode(mbmi->sb_type, tx_mode);
  } else {
    BLOCK_SIZE bsize = mbmi->sb_type;
    TX_SIZE min_tx_size = depth_to_tx_size(MAX_TX_DEPTH, bsize);
    mbmi->tx_size = (TX_SIZE)TXSIZEMAX(mbmi->tx_size, min_tx_size);
  }
  if (is_inter_block(mbmi)) {
    memset(mbmi->inter_tx_size, mbmi->tx_size, sizeof(mbmi->inter_tx_size));
  }
  const int stride = xd->tx_type_map_stride;
  const int bw = mi_size_wide[mbmi->sb_type];
  for (int row = 0; row < mi_size_high[mbmi->sb_type]; ++row) {
    memset(xd->tx_type_map + row * stride, DCT_DCT,
           bw * sizeof(xd->tx_type_map[0]));
  }
  av1_zero(txfm_info->blk_skip);
  txfm_info->skip_txfm = 0;
}

// This function will copy the best reference mode information from
// MB_MODE_INFO_EXT_FRAME to MB_MODE_INFO_EXT.
static INLINE void copy_mbmi_ext_frame_to_mbmi_ext(
    MB_MODE_INFO_EXT *mbmi_ext,
    const MB_MODE_INFO_EXT_FRAME *const mbmi_ext_best, uint8_t ref_frame_type) {
  memcpy(mbmi_ext->ref_mv_stack[ref_frame_type], mbmi_ext_best->ref_mv_stack,
         sizeof(mbmi_ext->ref_mv_stack[USABLE_REF_MV_STACK_SIZE]));
  memcpy(mbmi_ext->weight[ref_frame_type], mbmi_ext_best->weight,
         sizeof(mbmi_ext->weight[USABLE_REF_MV_STACK_SIZE]));
  mbmi_ext->mode_context[ref_frame_type] = mbmi_ext_best->mode_context;
  mbmi_ext->ref_mv_count[ref_frame_type] = mbmi_ext_best->ref_mv_count;
  memcpy(mbmi_ext->global_mvs, mbmi_ext_best->global_mvs,
         sizeof(mbmi_ext->global_mvs));
}

static AOM_INLINE void update_state(const AV1_COMP *const cpi, ThreadData *td,
                                    const PICK_MODE_CONTEXT *const ctx,
                                    int mi_row, int mi_col, BLOCK_SIZE bsize,
                                    RUN_TYPE dry_run) {
  int i, x_idx, y;
  const AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  const int num_planes = av1_num_planes(cm);
  RD_COUNTS *const rdc = &td->rd_counts;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  struct macroblock_plane *const p = x->plane;
  struct macroblockd_plane *const pd = xd->plane;
  const MB_MODE_INFO *const mi = &ctx->mic;
  MB_MODE_INFO *const mi_addr = xd->mi[0];
  const struct segmentation *const seg = &cm->seg;
  const int bw = mi_size_wide[mi->sb_type];
  const int bh = mi_size_high[mi->sb_type];
  const int mis = mi_params->mi_stride;
  const int mi_width = mi_size_wide[bsize];
  const int mi_height = mi_size_high[bsize];
  TxfmSearchInfo *txfm_info = &x->txfm_search_info;

  assert(mi->sb_type == bsize);

  *mi_addr = *mi;
  copy_mbmi_ext_frame_to_mbmi_ext(x->mbmi_ext, &ctx->mbmi_ext_best,
                                  av1_ref_frame_type(ctx->mic.ref_frame));

  memcpy(txfm_info->blk_skip, ctx->blk_skip,
         sizeof(txfm_info->blk_skip[0]) * ctx->num_4x4_blk);

  txfm_info->skip_txfm = ctx->rd_stats.skip_txfm;

  xd->tx_type_map = ctx->tx_type_map;
  xd->tx_type_map_stride = mi_size_wide[bsize];
  // If not dry_run, copy the transform type data into the frame level buffer.
  // Encoder will fetch tx types when writing bitstream.
  if (!dry_run) {
    const int grid_idx = get_mi_grid_idx(mi_params, mi_row, mi_col);
    uint8_t *const tx_type_map = mi_params->tx_type_map + grid_idx;
    const int mi_stride = mi_params->mi_stride;
    for (int blk_row = 0; blk_row < bh; ++blk_row) {
      av1_copy_array(tx_type_map + blk_row * mi_stride,
                     xd->tx_type_map + blk_row * xd->tx_type_map_stride, bw);
    }
    xd->tx_type_map = tx_type_map;
    xd->tx_type_map_stride = mi_stride;
  }

  // If segmentation in use
  if (seg->enabled) {
    // For in frame complexity AQ copy the segment id from the segment map.
    if (cpi->oxcf.aq_mode == COMPLEXITY_AQ) {
      const uint8_t *const map =
          seg->update_map ? cpi->enc_seg.map : cm->last_frame_seg_map;
      mi_addr->segment_id =
          map ? get_segment_id(mi_params, map, bsize, mi_row, mi_col) : 0;
      reset_tx_size(x, mi_addr, x->txfm_search_params.tx_mode_search_type);
    }
    // Else for cyclic refresh mode update the segment map, set the segment id
    // and then update the quantizer.
    if (cpi->oxcf.aq_mode == CYCLIC_REFRESH_AQ) {
      av1_cyclic_refresh_update_segment(cpi, mi_addr, mi_row, mi_col, bsize,
                                        ctx->rd_stats.rate, ctx->rd_stats.dist,
                                        txfm_info->skip_txfm);
    }
    if (mi_addr->uv_mode == UV_CFL_PRED && !is_cfl_allowed(xd))
      mi_addr->uv_mode = UV_DC_PRED;
  }

  for (i = 0; i < num_planes; ++i) {
    p[i].coeff = ctx->coeff[i];
    p[i].qcoeff = ctx->qcoeff[i];
    p[i].dqcoeff = ctx->dqcoeff[i];
    p[i].eobs = ctx->eobs[i];
    p[i].txb_entropy_ctx = ctx->txb_entropy_ctx[i];
  }
  for (i = 0; i < 2; ++i) pd[i].color_index_map = ctx->color_index_map[i];
  // Restore the coding context of the MB to that that was in place
  // when the mode was picked for it
  for (y = 0; y < mi_height; y++) {
    for (x_idx = 0; x_idx < mi_width; x_idx++) {
      if ((xd->mb_to_right_edge >> (3 + MI_SIZE_LOG2)) + mi_width > x_idx &&
          (xd->mb_to_bottom_edge >> (3 + MI_SIZE_LOG2)) + mi_height > y) {
        xd->mi[x_idx + y * mis] = mi_addr;
      }
    }
  }

  if (cpi->oxcf.aq_mode) av1_init_plane_quantizers(cpi, x, mi_addr->segment_id);

  if (dry_run) return;

#if CONFIG_INTERNAL_STATS
  {
    unsigned int *const mode_chosen_counts =
        (unsigned int *)cpi->mode_chosen_counts;  // Cast const away.
    if (frame_is_intra_only(cm)) {
      static const int kf_mode_index[] = {
        THR_DC /*DC_PRED*/,
        THR_V_PRED /*V_PRED*/,
        THR_H_PRED /*H_PRED*/,
        THR_D45_PRED /*D45_PRED*/,
        THR_D135_PRED /*D135_PRED*/,
        THR_D113_PRED /*D113_PRED*/,
        THR_D157_PRED /*D157_PRED*/,
        THR_D203_PRED /*D203_PRED*/,
        THR_D67_PRED /*D67_PRED*/,
        THR_SMOOTH,   /*SMOOTH_PRED*/
        THR_SMOOTH_V, /*SMOOTH_V_PRED*/
        THR_SMOOTH_H, /*SMOOTH_H_PRED*/
        THR_PAETH /*PAETH_PRED*/,
      };
      ++mode_chosen_counts[kf_mode_index[mi_addr->mode]];
    } else {
      // Note how often each mode chosen as best
      ++mode_chosen_counts[ctx->best_mode_index];
    }
  }
#endif
  if (!frame_is_intra_only(cm)) {
    if (is_inter_block(mi_addr)) {
      // TODO(sarahparker): global motion stats need to be handled per-tile
      // to be compatible with tile-based threading.
      update_global_motion_used(mi_addr->mode, bsize, mi_addr, rdc);
    }

    if (cm->features.interp_filter == SWITCHABLE &&
        mi_addr->motion_mode != WARPED_CAUSAL &&
        !is_nontrans_global_motion(xd, xd->mi[0])) {
      update_filter_type_count(td->counts, xd, mi_addr);
    }

    rdc->comp_pred_diff[SINGLE_REFERENCE] += ctx->single_pred_diff;
    rdc->comp_pred_diff[COMPOUND_REFERENCE] += ctx->comp_pred_diff;
    rdc->comp_pred_diff[REFERENCE_MODE_SELECT] += ctx->hybrid_pred_diff;
  }

  const int x_mis = AOMMIN(bw, mi_params->mi_cols - mi_col);
  const int y_mis = AOMMIN(bh, mi_params->mi_rows - mi_row);
  if (cm->seq_params.order_hint_info.enable_ref_frame_mvs)
    av1_copy_frame_mvs(cm, mi, mi_row, mi_col, x_mis, y_mis);
}

void av1_setup_src_planes(MACROBLOCK *x, const YV12_BUFFER_CONFIG *src,
                          int mi_row, int mi_col, const int num_planes,
                          BLOCK_SIZE bsize) {
  // Set current frame pointer.
  x->e_mbd.cur_buf = src;

  // We use AOMMIN(num_planes, MAX_MB_PLANE) instead of num_planes to quiet
  // the static analysis warnings.
  for (int i = 0; i < AOMMIN(num_planes, MAX_MB_PLANE); i++) {
    const int is_uv = i > 0;
    setup_pred_plane(
        &x->plane[i].src, bsize, src->buffers[i], src->crop_widths[is_uv],
        src->crop_heights[is_uv], src->strides[is_uv], mi_row, mi_col, NULL,
        x->e_mbd.plane[i].subsampling_x, x->e_mbd.plane[i].subsampling_y);
  }
}

static int use_pb_simple_motion_pred_sse(const AV1_COMP *const cpi) {
  // TODO(debargha, yuec): Not in use, need to implement a speed feature
  // utilizing this data point, and replace '0' by the corresponding speed
  // feature flag.
  return 0 && !frame_is_intra_only(&cpi->common);
}

static void hybrid_intra_mode_search(AV1_COMP *cpi, MACROBLOCK *const x,
                                     RD_STATS *rd_cost, BLOCK_SIZE bsize,
                                     PICK_MODE_CONTEXT *ctx) {
  // TODO(jianj): Investigate the failure of ScalabilityTest in AOM_Q mode,
  // which sets base_qindex to 0 on keyframe.
  if (cpi->oxcf.rc_mode != AOM_CBR || !cpi->sf.rt_sf.hybrid_intra_pickmode ||
      bsize < BLOCK_16X16)
    av1_rd_pick_intra_mode_sb(cpi, x, rd_cost, bsize, ctx, INT64_MAX);
  else
    av1_nonrd_pick_intra_mode(cpi, x, rd_cost, bsize, ctx);
}

static AOM_INLINE void pick_sb_modes(AV1_COMP *const cpi,
                                     TileDataEnc *tile_data,
                                     MACROBLOCK *const x, int mi_row,
                                     int mi_col, RD_STATS *rd_cost,
                                     PARTITION_TYPE partition, BLOCK_SIZE bsize,
                                     PICK_MODE_CONTEXT *ctx, RD_STATS best_rd,
                                     int pick_mode_type) {
  if (best_rd.rdcost < 0) {
    ctx->rd_stats.rdcost = INT64_MAX;
    ctx->rd_stats.skip_txfm = 0;
    av1_invalid_rd_stats(rd_cost);
    return;
  }

  set_offsets(cpi, &tile_data->tile_info, x, mi_row, mi_col, bsize);

  if (ctx->rd_mode_is_ready) {
    assert(ctx->mic.sb_type == bsize);
    assert(ctx->mic.partition == partition);
    rd_cost->rate = ctx->rd_stats.rate;
    rd_cost->dist = ctx->rd_stats.dist;
    rd_cost->rdcost = ctx->rd_stats.rdcost;
    return;
  }

  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCKD *const xd = &x->e_mbd;
  MB_MODE_INFO *mbmi;
  struct macroblock_plane *const p = x->plane;
  struct macroblockd_plane *const pd = xd->plane;
  const AQ_MODE aq_mode = cpi->oxcf.aq_mode;
  TxfmSearchInfo *txfm_info = &x->txfm_search_info;

  int i;

#if CONFIG_COLLECT_COMPONENT_TIMING
  start_timing(cpi, rd_pick_sb_modes_time);
#endif

  aom_clear_system_state();

  mbmi = xd->mi[0];
  mbmi->sb_type = bsize;
  mbmi->partition = partition;

#if CONFIG_RD_DEBUG
  mbmi->mi_row = mi_row;
  mbmi->mi_col = mi_col;
#endif

  // Sets up the tx_type_map buffer in MACROBLOCKD.
  xd->tx_type_map = txfm_info->tx_type_map_;
  xd->tx_type_map_stride = mi_size_wide[bsize];

  for (i = 0; i < num_planes; ++i) {
    p[i].coeff = ctx->coeff[i];
    p[i].qcoeff = ctx->qcoeff[i];
    p[i].dqcoeff = ctx->dqcoeff[i];
    p[i].eobs = ctx->eobs[i];
    p[i].txb_entropy_ctx = ctx->txb_entropy_ctx[i];
  }

  for (i = 0; i < 2; ++i) pd[i].color_index_map = ctx->color_index_map[i];

  ctx->skippable = 0;
  // Set to zero to make sure we do not use the previous encoded frame stats
  mbmi->skip_txfm = 0;
  // Reset skip mode flag.
  mbmi->skip_mode = 0;

  if (is_cur_buf_hbd(xd)) {
    x->source_variance = av1_high_get_sby_perpixel_variance(
        cpi, &x->plane[0].src, bsize, xd->bd);
  } else {
    x->source_variance =
        av1_get_sby_perpixel_variance(cpi, &x->plane[0].src, bsize);
  }
  if (use_pb_simple_motion_pred_sse(cpi)) {
    const FULLPEL_MV start_mv = kZeroFullMv;
    unsigned int var = 0;
    av1_simple_motion_sse_var(cpi, x, mi_row, mi_col, bsize, start_mv, 0,
                              &x->simple_motion_pred_sse, &var);
  }

  // Initialize default mode evaluation params
  set_mode_eval_params(cpi, x, DEFAULT_EVAL);

  // Save rdmult before it might be changed, so it can be restored later.
  const int orig_rdmult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, aq_mode, mbmi);
  // Set error per bit for current rdmult
  av1_set_error_per_bit(&x->mv_costs, x->rdmult);
  av1_rd_cost_update(x->rdmult, &best_rd);

  // Find best coding mode & reconstruct the MB so it is available
  // as a predictor for MBs that follow in the SB
  if (frame_is_intra_only(cm)) {
#if CONFIG_COLLECT_COMPONENT_TIMING
    start_timing(cpi, av1_rd_pick_intra_mode_sb_time);
#endif
    switch (pick_mode_type) {
      case PICK_MODE_RD:
        av1_rd_pick_intra_mode_sb(cpi, x, rd_cost, bsize, ctx, best_rd.rdcost);
        break;
      case PICK_MODE_NONRD:
        hybrid_intra_mode_search(cpi, x, rd_cost, bsize, ctx);
        break;
      default: assert(0 && "Unknown pick mode type.");
    }
#if CONFIG_COLLECT_COMPONENT_TIMING
    end_timing(cpi, av1_rd_pick_intra_mode_sb_time);
#endif
  } else {
#if CONFIG_COLLECT_COMPONENT_TIMING
    start_timing(cpi, av1_rd_pick_inter_mode_sb_time);
#endif
    if (segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_SKIP)) {
      av1_rd_pick_inter_mode_sb_seg_skip(cpi, tile_data, x, mi_row, mi_col,
                                         rd_cost, bsize, ctx, best_rd.rdcost);
    } else {
      // TODO(kyslov): do the same for pick_inter_mode_sb_seg_skip
      switch (pick_mode_type) {
        case PICK_MODE_RD:
          av1_rd_pick_inter_mode_sb(cpi, tile_data, x, rd_cost, bsize, ctx,
                                    best_rd.rdcost);
          break;
        case PICK_MODE_NONRD:
          av1_nonrd_pick_inter_mode_sb(cpi, tile_data, x, rd_cost, bsize, ctx);
          break;
        default: assert(0 && "Unknown pick mode type.");
      }
    }
#if CONFIG_COLLECT_COMPONENT_TIMING
    end_timing(cpi, av1_rd_pick_inter_mode_sb_time);
#endif
  }

  // Examine the resulting rate and for AQ mode 2 make a segment choice.
  if (rd_cost->rate != INT_MAX && aq_mode == COMPLEXITY_AQ &&
      bsize >= BLOCK_16X16) {
    av1_caq_select_segment(cpi, x, bsize, mi_row, mi_col, rd_cost->rate);
  }

  x->rdmult = orig_rdmult;

  // TODO(jingning) The rate-distortion optimization flow needs to be
  // refactored to provide proper exit/return handle.
  if (rd_cost->rate == INT_MAX) rd_cost->rdcost = INT64_MAX;

  ctx->rd_stats.rate = rd_cost->rate;
  ctx->rd_stats.dist = rd_cost->dist;
  ctx->rd_stats.rdcost = rd_cost->rdcost;

#if CONFIG_COLLECT_COMPONENT_TIMING
  end_timing(cpi, rd_pick_sb_modes_time);
#endif
}

static AOM_INLINE void update_inter_mode_stats(FRAME_CONTEXT *fc,
                                               FRAME_COUNTS *counts,
                                               PREDICTION_MODE mode,
                                               int16_t mode_context) {
  (void)counts;

  int16_t mode_ctx = mode_context & NEWMV_CTX_MASK;
  if (mode == NEWMV) {
#if CONFIG_ENTROPY_STATS
    ++counts->newmv_mode[mode_ctx][0];
#endif
    update_cdf(fc->newmv_cdf[mode_ctx], 0, 2);
    return;
  }

#if CONFIG_ENTROPY_STATS
  ++counts->newmv_mode[mode_ctx][1];
#endif
  update_cdf(fc->newmv_cdf[mode_ctx], 1, 2);

  mode_ctx = (mode_context >> GLOBALMV_OFFSET) & GLOBALMV_CTX_MASK;
  if (mode == GLOBALMV) {
#if CONFIG_ENTROPY_STATS
    ++counts->zeromv_mode[mode_ctx][0];
#endif
    update_cdf(fc->zeromv_cdf[mode_ctx], 0, 2);
    return;
  }

#if CONFIG_ENTROPY_STATS
  ++counts->zeromv_mode[mode_ctx][1];
#endif
  update_cdf(fc->zeromv_cdf[mode_ctx], 1, 2);

  mode_ctx = (mode_context >> REFMV_OFFSET) & REFMV_CTX_MASK;
#if CONFIG_ENTROPY_STATS
  ++counts->refmv_mode[mode_ctx][mode != NEARESTMV];
#endif
  update_cdf(fc->refmv_cdf[mode_ctx], mode != NEARESTMV, 2);
}

static AOM_INLINE void update_palette_cdf(MACROBLOCKD *xd,
                                          const MB_MODE_INFO *const mbmi,
                                          FRAME_COUNTS *counts) {
  FRAME_CONTEXT *fc = xd->tile_ctx;
  const BLOCK_SIZE bsize = mbmi->sb_type;
  const PALETTE_MODE_INFO *const pmi = &mbmi->palette_mode_info;
  const int palette_bsize_ctx = av1_get_palette_bsize_ctx(bsize);

  (void)counts;

  if (mbmi->mode == DC_PRED) {
    const int n = pmi->palette_size[0];
    const int palette_mode_ctx = av1_get_palette_mode_ctx(xd);

#if CONFIG_ENTROPY_STATS
    ++counts->palette_y_mode[palette_bsize_ctx][palette_mode_ctx][n > 0];
#endif
    update_cdf(fc->palette_y_mode_cdf[palette_bsize_ctx][palette_mode_ctx],
               n > 0, 2);
    if (n > 0) {
#if CONFIG_ENTROPY_STATS
      ++counts->palette_y_size[palette_bsize_ctx][n - PALETTE_MIN_SIZE];
#endif
      update_cdf(fc->palette_y_size_cdf[palette_bsize_ctx],
                 n - PALETTE_MIN_SIZE, PALETTE_SIZES);
    }
  }

  if (mbmi->uv_mode == UV_DC_PRED) {
    const int n = pmi->palette_size[1];
    const int palette_uv_mode_ctx = (pmi->palette_size[0] > 0);

#if CONFIG_ENTROPY_STATS
    ++counts->palette_uv_mode[palette_uv_mode_ctx][n > 0];
#endif
    update_cdf(fc->palette_uv_mode_cdf[palette_uv_mode_ctx], n > 0, 2);

    if (n > 0) {
#if CONFIG_ENTROPY_STATS
      ++counts->palette_uv_size[palette_bsize_ctx][n - PALETTE_MIN_SIZE];
#endif
      update_cdf(fc->palette_uv_size_cdf[palette_bsize_ctx],
                 n - PALETTE_MIN_SIZE, PALETTE_SIZES);
    }
  }
}

static AOM_INLINE void sum_intra_stats(const AV1_COMMON *const cm,
                                       FRAME_COUNTS *counts, MACROBLOCKD *xd,
                                       const MB_MODE_INFO *const mbmi,
                                       const MB_MODE_INFO *above_mi,
                                       const MB_MODE_INFO *left_mi,
                                       const int intraonly) {
  FRAME_CONTEXT *fc = xd->tile_ctx;
  const PREDICTION_MODE y_mode = mbmi->mode;
  (void)counts;
  const BLOCK_SIZE bsize = mbmi->sb_type;

  if (intraonly) {
#if CONFIG_ENTROPY_STATS
    const PREDICTION_MODE above = av1_above_block_mode(above_mi);
    const PREDICTION_MODE left = av1_left_block_mode(left_mi);
    const int above_ctx = intra_mode_context[above];
    const int left_ctx = intra_mode_context[left];
    ++counts->kf_y_mode[above_ctx][left_ctx][y_mode];
#endif  // CONFIG_ENTROPY_STATS
    update_cdf(get_y_mode_cdf(fc, above_mi, left_mi), y_mode, INTRA_MODES);
  } else {
#if CONFIG_ENTROPY_STATS
    ++counts->y_mode[size_group_lookup[bsize]][y_mode];
#endif  // CONFIG_ENTROPY_STATS
    update_cdf(fc->y_mode_cdf[size_group_lookup[bsize]], y_mode, INTRA_MODES);
  }

  if (av1_filter_intra_allowed(cm, mbmi)) {
    const int use_filter_intra_mode =
        mbmi->filter_intra_mode_info.use_filter_intra;
#if CONFIG_ENTROPY_STATS
    ++counts->filter_intra[mbmi->sb_type][use_filter_intra_mode];
    if (use_filter_intra_mode) {
      ++counts
            ->filter_intra_mode[mbmi->filter_intra_mode_info.filter_intra_mode];
    }
#endif  // CONFIG_ENTROPY_STATS
    update_cdf(fc->filter_intra_cdfs[mbmi->sb_type], use_filter_intra_mode, 2);
    if (use_filter_intra_mode) {
      update_cdf(fc->filter_intra_mode_cdf,
                 mbmi->filter_intra_mode_info.filter_intra_mode,
                 FILTER_INTRA_MODES);
    }
  }
  if (av1_is_directional_mode(mbmi->mode) && av1_use_angle_delta(bsize)) {
#if CONFIG_ENTROPY_STATS
    ++counts->angle_delta[mbmi->mode - V_PRED]
                         [mbmi->angle_delta[PLANE_TYPE_Y] + MAX_ANGLE_DELTA];
#endif
    update_cdf(fc->angle_delta_cdf[mbmi->mode - V_PRED],
               mbmi->angle_delta[PLANE_TYPE_Y] + MAX_ANGLE_DELTA,
               2 * MAX_ANGLE_DELTA + 1);
  }

  if (!xd->is_chroma_ref) return;

  const UV_PREDICTION_MODE uv_mode = mbmi->uv_mode;
  const CFL_ALLOWED_TYPE cfl_allowed = is_cfl_allowed(xd);
#if CONFIG_ENTROPY_STATS
  ++counts->uv_mode[cfl_allowed][y_mode][uv_mode];
#endif  // CONFIG_ENTROPY_STATS
  update_cdf(fc->uv_mode_cdf[cfl_allowed][y_mode], uv_mode,
             UV_INTRA_MODES - !cfl_allowed);
  if (uv_mode == UV_CFL_PRED) {
    const int8_t joint_sign = mbmi->cfl_alpha_signs;
    const uint8_t idx = mbmi->cfl_alpha_idx;

#if CONFIG_ENTROPY_STATS
    ++counts->cfl_sign[joint_sign];
#endif
    update_cdf(fc->cfl_sign_cdf, joint_sign, CFL_JOINT_SIGNS);
    if (CFL_SIGN_U(joint_sign) != CFL_SIGN_ZERO) {
      aom_cdf_prob *cdf_u = fc->cfl_alpha_cdf[CFL_CONTEXT_U(joint_sign)];

#if CONFIG_ENTROPY_STATS
      ++counts->cfl_alpha[CFL_CONTEXT_U(joint_sign)][CFL_IDX_U(idx)];
#endif
      update_cdf(cdf_u, CFL_IDX_U(idx), CFL_ALPHABET_SIZE);
    }
    if (CFL_SIGN_V(joint_sign) != CFL_SIGN_ZERO) {
      aom_cdf_prob *cdf_v = fc->cfl_alpha_cdf[CFL_CONTEXT_V(joint_sign)];

#if CONFIG_ENTROPY_STATS
      ++counts->cfl_alpha[CFL_CONTEXT_V(joint_sign)][CFL_IDX_V(idx)];
#endif
      update_cdf(cdf_v, CFL_IDX_V(idx), CFL_ALPHABET_SIZE);
    }
  }
  if (av1_is_directional_mode(get_uv_mode(uv_mode)) &&
      av1_use_angle_delta(bsize)) {
#if CONFIG_ENTROPY_STATS
    ++counts->angle_delta[uv_mode - UV_V_PRED]
                         [mbmi->angle_delta[PLANE_TYPE_UV] + MAX_ANGLE_DELTA];
#endif
    update_cdf(fc->angle_delta_cdf[uv_mode - UV_V_PRED],
               mbmi->angle_delta[PLANE_TYPE_UV] + MAX_ANGLE_DELTA,
               2 * MAX_ANGLE_DELTA + 1);
  }
  if (av1_allow_palette(cm->features.allow_screen_content_tools, bsize)) {
    update_palette_cdf(xd, mbmi, counts);
  }
}

static AOM_INLINE void update_stats(const AV1_COMMON *const cm,
                                    ThreadData *td) {
  MACROBLOCK *x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  const MB_MODE_INFO *const mbmi = xd->mi[0];
  const MB_MODE_INFO_EXT *const mbmi_ext = x->mbmi_ext;
  const CurrentFrame *const current_frame = &cm->current_frame;
  const BLOCK_SIZE bsize = mbmi->sb_type;
  FRAME_CONTEXT *fc = xd->tile_ctx;
  const int seg_ref_active =
      segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_REF_FRAME);

  if (current_frame->skip_mode_info.skip_mode_flag && !seg_ref_active &&
      is_comp_ref_allowed(bsize)) {
    const int skip_mode_ctx = av1_get_skip_mode_context(xd);
#if CONFIG_ENTROPY_STATS
    td->counts->skip_mode[skip_mode_ctx][mbmi->skip_mode]++;
#endif
    update_cdf(fc->skip_mode_cdfs[skip_mode_ctx], mbmi->skip_mode, 2);
  }

  if (!mbmi->skip_mode && !seg_ref_active) {
    const int skip_ctx = av1_get_skip_txfm_context(xd);
#if CONFIG_ENTROPY_STATS
    td->counts->skip_txfm[skip_ctx][mbmi->skip_txfm]++;
#endif
    update_cdf(fc->skip_txfm_cdfs[skip_ctx], mbmi->skip_txfm, 2);
  }

#if CONFIG_ENTROPY_STATS
  // delta quant applies to both intra and inter
  const int super_block_upper_left =
      ((xd->mi_row & (cm->seq_params.mib_size - 1)) == 0) &&
      ((xd->mi_col & (cm->seq_params.mib_size - 1)) == 0);
  const DeltaQInfo *const delta_q_info = &cm->delta_q_info;
  if (delta_q_info->delta_q_present_flag &&
      (bsize != cm->seq_params.sb_size || !mbmi->skip_txfm) &&
      super_block_upper_left) {
    const int dq = (mbmi->current_qindex - xd->current_base_qindex) /
                   delta_q_info->delta_q_res;
    const int absdq = abs(dq);
    for (int i = 0; i < AOMMIN(absdq, DELTA_Q_SMALL); ++i) {
      td->counts->delta_q[i][1]++;
    }
    if (absdq < DELTA_Q_SMALL) td->counts->delta_q[absdq][0]++;
    if (delta_q_info->delta_lf_present_flag) {
      if (delta_q_info->delta_lf_multi) {
        const int frame_lf_count =
            av1_num_planes(cm) > 1 ? FRAME_LF_COUNT : FRAME_LF_COUNT - 2;
        for (int lf_id = 0; lf_id < frame_lf_count; ++lf_id) {
          const int delta_lf = (mbmi->delta_lf[lf_id] - xd->delta_lf[lf_id]) /
                               delta_q_info->delta_lf_res;
          const int abs_delta_lf = abs(delta_lf);
          for (int i = 0; i < AOMMIN(abs_delta_lf, DELTA_LF_SMALL); ++i) {
            td->counts->delta_lf_multi[lf_id][i][1]++;
          }
          if (abs_delta_lf < DELTA_LF_SMALL)
            td->counts->delta_lf_multi[lf_id][abs_delta_lf][0]++;
        }
      } else {
        const int delta_lf =
            (mbmi->delta_lf_from_base - xd->delta_lf_from_base) /
            delta_q_info->delta_lf_res;
        const int abs_delta_lf = abs(delta_lf);
        for (int i = 0; i < AOMMIN(abs_delta_lf, DELTA_LF_SMALL); ++i) {
          td->counts->delta_lf[i][1]++;
        }
        if (abs_delta_lf < DELTA_LF_SMALL)
          td->counts->delta_lf[abs_delta_lf][0]++;
      }
    }
  }
#endif

  if (!is_inter_block(mbmi)) {
    sum_intra_stats(cm, td->counts, xd, mbmi, xd->above_mbmi, xd->left_mbmi,
                    frame_is_intra_only(cm));
  }

  if (av1_allow_intrabc(cm)) {
    update_cdf(fc->intrabc_cdf, is_intrabc_block(mbmi), 2);
#if CONFIG_ENTROPY_STATS
    ++td->counts->intrabc[is_intrabc_block(mbmi)];
#endif  // CONFIG_ENTROPY_STATS
  }

  if (frame_is_intra_only(cm) || mbmi->skip_mode) return;

  FRAME_COUNTS *const counts = td->counts;
  const int inter_block = is_inter_block(mbmi);

  if (!seg_ref_active) {
#if CONFIG_ENTROPY_STATS
    counts->intra_inter[av1_get_intra_inter_context(xd)][inter_block]++;
#endif
    update_cdf(fc->intra_inter_cdf[av1_get_intra_inter_context(xd)],
               inter_block, 2);
    // If the segment reference feature is enabled we have only a single
    // reference frame allowed for the segment so exclude it from
    // the reference frame counts used to work out probabilities.
    if (inter_block) {
      const MV_REFERENCE_FRAME ref0 = mbmi->ref_frame[0];
      const MV_REFERENCE_FRAME ref1 = mbmi->ref_frame[1];
      if (current_frame->reference_mode == REFERENCE_MODE_SELECT) {
        if (is_comp_ref_allowed(bsize)) {
#if CONFIG_ENTROPY_STATS
          counts->comp_inter[av1_get_reference_mode_context(xd)]
                            [has_second_ref(mbmi)]++;
#endif  // CONFIG_ENTROPY_STATS
          update_cdf(av1_get_reference_mode_cdf(xd), has_second_ref(mbmi), 2);
        }
      }

      if (has_second_ref(mbmi)) {
        const COMP_REFERENCE_TYPE comp_ref_type = has_uni_comp_refs(mbmi)
                                                      ? UNIDIR_COMP_REFERENCE
                                                      : BIDIR_COMP_REFERENCE;
        update_cdf(av1_get_comp_reference_type_cdf(xd), comp_ref_type,
                   COMP_REFERENCE_TYPES);
#if CONFIG_ENTROPY_STATS
        counts->comp_ref_type[av1_get_comp_reference_type_context(xd)]
                             [comp_ref_type]++;
#endif  // CONFIG_ENTROPY_STATS

        if (comp_ref_type == UNIDIR_COMP_REFERENCE) {
          const int bit = (ref0 == BWDREF_FRAME);
          update_cdf(av1_get_pred_cdf_uni_comp_ref_p(xd), bit, 2);
#if CONFIG_ENTROPY_STATS
          counts
              ->uni_comp_ref[av1_get_pred_context_uni_comp_ref_p(xd)][0][bit]++;
#endif  // CONFIG_ENTROPY_STATS
          if (!bit) {
            const int bit1 = (ref1 == LAST3_FRAME || ref1 == GOLDEN_FRAME);
            update_cdf(av1_get_pred_cdf_uni_comp_ref_p1(xd), bit1, 2);
#if CONFIG_ENTROPY_STATS
            counts->uni_comp_ref[av1_get_pred_context_uni_comp_ref_p1(xd)][1]
                                [bit1]++;
#endif  // CONFIG_ENTROPY_STATS
            if (bit1) {
              update_cdf(av1_get_pred_cdf_uni_comp_ref_p2(xd),
                         ref1 == GOLDEN_FRAME, 2);
#if CONFIG_ENTROPY_STATS
              counts->uni_comp_ref[av1_get_pred_context_uni_comp_ref_p2(xd)][2]
                                  [ref1 == GOLDEN_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
            }
          }
        } else {
          const int bit = (ref0 == GOLDEN_FRAME || ref0 == LAST3_FRAME);
          update_cdf(av1_get_pred_cdf_comp_ref_p(xd), bit, 2);
#if CONFIG_ENTROPY_STATS
          counts->comp_ref[av1_get_pred_context_comp_ref_p(xd)][0][bit]++;
#endif  // CONFIG_ENTROPY_STATS
          if (!bit) {
            update_cdf(av1_get_pred_cdf_comp_ref_p1(xd), ref0 == LAST2_FRAME,
                       2);
#if CONFIG_ENTROPY_STATS
            counts->comp_ref[av1_get_pred_context_comp_ref_p1(xd)][1]
                            [ref0 == LAST2_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          } else {
            update_cdf(av1_get_pred_cdf_comp_ref_p2(xd), ref0 == GOLDEN_FRAME,
                       2);
#if CONFIG_ENTROPY_STATS
            counts->comp_ref[av1_get_pred_context_comp_ref_p2(xd)][2]
                            [ref0 == GOLDEN_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          }
          update_cdf(av1_get_pred_cdf_comp_bwdref_p(xd), ref1 == ALTREF_FRAME,
                     2);
#if CONFIG_ENTROPY_STATS
          counts->comp_bwdref[av1_get_pred_context_comp_bwdref_p(xd)][0]
                             [ref1 == ALTREF_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          if (ref1 != ALTREF_FRAME) {
            update_cdf(av1_get_pred_cdf_comp_bwdref_p1(xd),
                       ref1 == ALTREF2_FRAME, 2);
#if CONFIG_ENTROPY_STATS
            counts->comp_bwdref[av1_get_pred_context_comp_bwdref_p1(xd)][1]
                               [ref1 == ALTREF2_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          }
        }
      } else {
        const int bit = (ref0 >= BWDREF_FRAME);
        update_cdf(av1_get_pred_cdf_single_ref_p1(xd), bit, 2);
#if CONFIG_ENTROPY_STATS
        counts->single_ref[av1_get_pred_context_single_ref_p1(xd)][0][bit]++;
#endif  // CONFIG_ENTROPY_STATS
        if (bit) {
          assert(ref0 <= ALTREF_FRAME);
          update_cdf(av1_get_pred_cdf_single_ref_p2(xd), ref0 == ALTREF_FRAME,
                     2);
#if CONFIG_ENTROPY_STATS
          counts->single_ref[av1_get_pred_context_single_ref_p2(xd)][1]
                            [ref0 == ALTREF_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          if (ref0 != ALTREF_FRAME) {
            update_cdf(av1_get_pred_cdf_single_ref_p6(xd),
                       ref0 == ALTREF2_FRAME, 2);
#if CONFIG_ENTROPY_STATS
            counts->single_ref[av1_get_pred_context_single_ref_p6(xd)][5]
                              [ref0 == ALTREF2_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          }
        } else {
          const int bit1 = !(ref0 == LAST2_FRAME || ref0 == LAST_FRAME);
          update_cdf(av1_get_pred_cdf_single_ref_p3(xd), bit1, 2);
#if CONFIG_ENTROPY_STATS
          counts->single_ref[av1_get_pred_context_single_ref_p3(xd)][2][bit1]++;
#endif  // CONFIG_ENTROPY_STATS
          if (!bit1) {
            update_cdf(av1_get_pred_cdf_single_ref_p4(xd), ref0 != LAST_FRAME,
                       2);
#if CONFIG_ENTROPY_STATS
            counts->single_ref[av1_get_pred_context_single_ref_p4(xd)][3]
                              [ref0 != LAST_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          } else {
            update_cdf(av1_get_pred_cdf_single_ref_p5(xd), ref0 != LAST3_FRAME,
                       2);
#if CONFIG_ENTROPY_STATS
            counts->single_ref[av1_get_pred_context_single_ref_p5(xd)][4]
                              [ref0 != LAST3_FRAME]++;
#endif  // CONFIG_ENTROPY_STATS
          }
        }
      }

      if (cm->seq_params.enable_interintra_compound &&
          is_interintra_allowed(mbmi)) {
        const int bsize_group = size_group_lookup[bsize];
        if (mbmi->ref_frame[1] == INTRA_FRAME) {
#if CONFIG_ENTROPY_STATS
          counts->interintra[bsize_group][1]++;
#endif
          update_cdf(fc->interintra_cdf[bsize_group], 1, 2);
#if CONFIG_ENTROPY_STATS
          counts->interintra_mode[bsize_group][mbmi->interintra_mode]++;
#endif
          update_cdf(fc->interintra_mode_cdf[bsize_group],
                     mbmi->interintra_mode, INTERINTRA_MODES);
          if (av1_is_wedge_used(bsize)) {
#if CONFIG_ENTROPY_STATS
            counts->wedge_interintra[bsize][mbmi->use_wedge_interintra]++;
#endif
            update_cdf(fc->wedge_interintra_cdf[bsize],
                       mbmi->use_wedge_interintra, 2);
            if (mbmi->use_wedge_interintra) {
#if CONFIG_ENTROPY_STATS
              counts->wedge_idx[bsize][mbmi->interintra_wedge_index]++;
#endif
              update_cdf(fc->wedge_idx_cdf[bsize], mbmi->interintra_wedge_index,
                         16);
            }
          }
        } else {
#if CONFIG_ENTROPY_STATS
          counts->interintra[bsize_group][0]++;
#endif
          update_cdf(fc->interintra_cdf[bsize_group], 0, 2);
        }
      }

      const MOTION_MODE motion_allowed =
          cm->features.switchable_motion_mode
              ? motion_mode_allowed(xd->global_motion, xd, mbmi,
                                    cm->features.allow_warped_motion)
              : SIMPLE_TRANSLATION;
      if (mbmi->ref_frame[1] != INTRA_FRAME) {
        if (motion_allowed == WARPED_CAUSAL) {
#if CONFIG_ENTROPY_STATS
          counts->motion_mode[bsize][mbmi->motion_mode]++;
#endif
          update_cdf(fc->motion_mode_cdf[bsize], mbmi->motion_mode,
                     MOTION_MODES);
        } else if (motion_allowed == OBMC_CAUSAL) {
#if CONFIG_ENTROPY_STATS
          counts->obmc[bsize][mbmi->motion_mode == OBMC_CAUSAL]++;
#endif
          update_cdf(fc->obmc_cdf[bsize], mbmi->motion_mode == OBMC_CAUSAL, 2);
        }
      }

      if (has_second_ref(mbmi)) {
        assert(current_frame->reference_mode != SINGLE_REFERENCE &&
               is_inter_compound_mode(mbmi->mode) &&
               mbmi->motion_mode == SIMPLE_TRANSLATION);

        const int masked_compound_used = is_any_masked_compound_used(bsize) &&
                                         cm->seq_params.enable_masked_compound;
        if (masked_compound_used) {
          const int comp_group_idx_ctx = get_comp_group_idx_context(xd);
#if CONFIG_ENTROPY_STATS
          ++counts->comp_group_idx[comp_group_idx_ctx][mbmi->comp_group_idx];
#endif
          update_cdf(fc->comp_group_idx_cdf[comp_group_idx_ctx],
                     mbmi->comp_group_idx, 2);
        }

        if (mbmi->comp_group_idx == 0) {
          const int comp_index_ctx = get_comp_index_context(cm, xd);
#if CONFIG_ENTROPY_STATS
          ++counts->compound_index[comp_index_ctx][mbmi->compound_idx];
#endif
          update_cdf(fc->compound_index_cdf[comp_index_ctx], mbmi->compound_idx,
                     2);
        } else {
          assert(masked_compound_used);
          if (is_interinter_compound_used(COMPOUND_WEDGE, bsize)) {
#if CONFIG_ENTROPY_STATS
            ++counts->compound_type[bsize][mbmi->interinter_comp.type -
                                           COMPOUND_WEDGE];
#endif
            update_cdf(fc->compound_type_cdf[bsize],
                       mbmi->interinter_comp.type - COMPOUND_WEDGE,
                       MASKED_COMPOUND_TYPES);
          }
        }
      }
      if (mbmi->interinter_comp.type == COMPOUND_WEDGE) {
        if (is_interinter_compound_used(COMPOUND_WEDGE, bsize)) {
#if CONFIG_ENTROPY_STATS
          counts->wedge_idx[bsize][mbmi->interinter_comp.wedge_index]++;
#endif
          update_cdf(fc->wedge_idx_cdf[bsize],
                     mbmi->interinter_comp.wedge_index, 16);
        }
      }
    }
  }

  if (inter_block && cm->features.interp_filter == SWITCHABLE &&
      mbmi->motion_mode != WARPED_CAUSAL &&
      !is_nontrans_global_motion(xd, mbmi)) {
    update_filter_type_cdf(xd, mbmi);
  }
  if (inter_block &&
      !segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_SKIP)) {
    const PREDICTION_MODE mode = mbmi->mode;
    const int16_t mode_ctx =
        av1_mode_context_analyzer(mbmi_ext->mode_context, mbmi->ref_frame);
    if (has_second_ref(mbmi)) {
#if CONFIG_ENTROPY_STATS
      ++counts->inter_compound_mode[mode_ctx][INTER_COMPOUND_OFFSET(mode)];
#endif
      update_cdf(fc->inter_compound_mode_cdf[mode_ctx],
                 INTER_COMPOUND_OFFSET(mode), INTER_COMPOUND_MODES);
    } else {
      update_inter_mode_stats(fc, counts, mode, mode_ctx);
    }

    const int new_mv = mbmi->mode == NEWMV || mbmi->mode == NEW_NEWMV;
    if (new_mv) {
      const uint8_t ref_frame_type = av1_ref_frame_type(mbmi->ref_frame);
      for (int idx = 0; idx < 2; ++idx) {
        if (mbmi_ext->ref_mv_count[ref_frame_type] > idx + 1) {
          const uint8_t drl_ctx =
              av1_drl_ctx(mbmi_ext->weight[ref_frame_type], idx);
          update_cdf(fc->drl_cdf[drl_ctx], mbmi->ref_mv_idx != idx, 2);
#if CONFIG_ENTROPY_STATS
          ++counts->drl_mode[drl_ctx][mbmi->ref_mv_idx != idx];
#endif
          if (mbmi->ref_mv_idx == idx) break;
        }
      }
    }

    if (have_nearmv_in_inter_mode(mbmi->mode)) {
      const uint8_t ref_frame_type = av1_ref_frame_type(mbmi->ref_frame);
      for (int idx = 1; idx < 3; ++idx) {
        if (mbmi_ext->ref_mv_count[ref_frame_type] > idx + 1) {
          const uint8_t drl_ctx =
              av1_drl_ctx(mbmi_ext->weight[ref_frame_type], idx);
          update_cdf(fc->drl_cdf[drl_ctx], mbmi->ref_mv_idx != idx - 1, 2);
#if CONFIG_ENTROPY_STATS
          ++counts->drl_mode[drl_ctx][mbmi->ref_mv_idx != idx - 1];
#endif
          if (mbmi->ref_mv_idx == idx - 1) break;
        }
      }
    }
    if (have_newmv_in_inter_mode(mbmi->mode)) {
      const int allow_hp = cm->features.cur_frame_force_integer_mv
                               ? MV_SUBPEL_NONE
                               : cm->features.allow_high_precision_mv;
      if (new_mv) {
        for (int ref = 0; ref < 1 + has_second_ref(mbmi); ++ref) {
          const int_mv ref_mv = av1_get_ref_mv(x, ref);
          av1_update_mv_stats(&mbmi->mv[ref].as_mv, &ref_mv.as_mv, &fc->nmvc,
                              allow_hp);
        }
      } else if (mbmi->mode == NEAREST_NEWMV || mbmi->mode == NEAR_NEWMV) {
        const int ref = 1;
        const int_mv ref_mv = av1_get_ref_mv(x, ref);
        av1_update_mv_stats(&mbmi->mv[ref].as_mv, &ref_mv.as_mv, &fc->nmvc,
                            allow_hp);
      } else if (mbmi->mode == NEW_NEARESTMV || mbmi->mode == NEW_NEARMV) {
        const int ref = 0;
        const int_mv ref_mv = av1_get_ref_mv(x, ref);
        av1_update_mv_stats(&mbmi->mv[ref].as_mv, &ref_mv.as_mv, &fc->nmvc,
                            allow_hp);
      }
    }
  }
}

static AOM_INLINE void restore_context(MACROBLOCK *x,
                                       const RD_SEARCH_MACROBLOCK_CONTEXT *ctx,
                                       int mi_row, int mi_col, BLOCK_SIZE bsize,
                                       const int num_planes) {
  MACROBLOCKD *xd = &x->e_mbd;
  int p;
  const int num_4x4_blocks_wide = mi_size_wide[bsize];
  const int num_4x4_blocks_high = mi_size_high[bsize];
  int mi_width = mi_size_wide[bsize];
  int mi_height = mi_size_high[bsize];
  for (p = 0; p < num_planes; p++) {
    int tx_col = mi_col;
    int tx_row = mi_row & MAX_MIB_MASK;
    memcpy(
        xd->above_entropy_context[p] + (tx_col >> xd->plane[p].subsampling_x),
        ctx->a + num_4x4_blocks_wide * p,
        (sizeof(ENTROPY_CONTEXT) * num_4x4_blocks_wide) >>
            xd->plane[p].subsampling_x);
    memcpy(xd->left_entropy_context[p] + (tx_row >> xd->plane[p].subsampling_y),
           ctx->l + num_4x4_blocks_high * p,
           (sizeof(ENTROPY_CONTEXT) * num_4x4_blocks_high) >>
               xd->plane[p].subsampling_y);
  }
  memcpy(xd->above_partition_context + mi_col, ctx->sa,
         sizeof(*xd->above_partition_context) * mi_width);
  memcpy(xd->left_partition_context + (mi_row & MAX_MIB_MASK), ctx->sl,
         sizeof(xd->left_partition_context[0]) * mi_height);
  xd->above_txfm_context = ctx->p_ta;
  xd->left_txfm_context = ctx->p_tl;
  memcpy(xd->above_txfm_context, ctx->ta,
         sizeof(*xd->above_txfm_context) * mi_width);
  memcpy(xd->left_txfm_context, ctx->tl,
         sizeof(*xd->left_txfm_context) * mi_height);
}

static AOM_INLINE void save_context(const MACROBLOCK *x,
                                    RD_SEARCH_MACROBLOCK_CONTEXT *ctx,
                                    int mi_row, int mi_col, BLOCK_SIZE bsize,
                                    const int num_planes) {
  const MACROBLOCKD *xd = &x->e_mbd;
  int p;
  int mi_width = mi_size_wide[bsize];
  int mi_height = mi_size_high[bsize];

  // buffer the above/left context information of the block in search.
  for (p = 0; p < num_planes; ++p) {
    int tx_col = mi_col;
    int tx_row = mi_row & MAX_MIB_MASK;
    memcpy(
        ctx->a + mi_width * p,
        xd->above_entropy_context[p] + (tx_col >> xd->plane[p].subsampling_x),
        (sizeof(ENTROPY_CONTEXT) * mi_width) >> xd->plane[p].subsampling_x);
    memcpy(ctx->l + mi_height * p,
           xd->left_entropy_context[p] + (tx_row >> xd->plane[p].subsampling_y),
           (sizeof(ENTROPY_CONTEXT) * mi_height) >> xd->plane[p].subsampling_y);
  }
  memcpy(ctx->sa, xd->above_partition_context + mi_col,
         sizeof(*xd->above_partition_context) * mi_width);
  memcpy(ctx->sl, xd->left_partition_context + (mi_row & MAX_MIB_MASK),
         sizeof(xd->left_partition_context[0]) * mi_height);
  memcpy(ctx->ta, xd->above_txfm_context,
         sizeof(*xd->above_txfm_context) * mi_width);
  memcpy(ctx->tl, xd->left_txfm_context,
         sizeof(*xd->left_txfm_context) * mi_height);
  ctx->p_ta = xd->above_txfm_context;
  ctx->p_tl = xd->left_txfm_context;
}

static AOM_INLINE void encode_b(const AV1_COMP *const cpi,
                                TileDataEnc *tile_data, ThreadData *td,
                                TokenExtra **tp, int mi_row, int mi_col,
                                RUN_TYPE dry_run, BLOCK_SIZE bsize,
                                PARTITION_TYPE partition,
                                PICK_MODE_CONTEXT *const ctx, int *rate) {
  TileInfo *const tile = &tile_data->tile_info;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *xd = &x->e_mbd;

  set_offsets_without_segment_id(cpi, tile, x, mi_row, mi_col, bsize);
  const int origin_mult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, NO_AQ, NULL);
  MB_MODE_INFO *mbmi = xd->mi[0];
  mbmi->partition = partition;
  update_state(cpi, td, ctx, mi_row, mi_col, bsize, dry_run);

  if (!dry_run) {
    x->mbmi_ext_frame->cb_offset = x->cb_offset;
    assert(x->cb_offset <
           (1 << num_pels_log2_lookup[cpi->common.seq_params.sb_size]));
  }

  encode_superblock(cpi, tile_data, td, tp, dry_run, bsize, rate);

  if (!dry_run) {
    const AV1_COMMON *const cm = &cpi->common;
    x->cb_offset += block_size_wide[bsize] * block_size_high[bsize];
    if (bsize == cpi->common.seq_params.sb_size && mbmi->skip_txfm == 1 &&
        cm->delta_q_info.delta_lf_present_flag) {
      const int frame_lf_count =
          av1_num_planes(cm) > 1 ? FRAME_LF_COUNT : FRAME_LF_COUNT - 2;
      for (int lf_id = 0; lf_id < frame_lf_count; ++lf_id)
        mbmi->delta_lf[lf_id] = xd->delta_lf[lf_id];
      mbmi->delta_lf_from_base = xd->delta_lf_from_base;
    }
    if (has_second_ref(mbmi)) {
      if (mbmi->compound_idx == 0 ||
          mbmi->interinter_comp.type == COMPOUND_AVERAGE)
        mbmi->comp_group_idx = 0;
      else
        mbmi->comp_group_idx = 1;
    }

    // delta quant applies to both intra and inter
    const int super_block_upper_left =
        ((mi_row & (cm->seq_params.mib_size - 1)) == 0) &&
        ((mi_col & (cm->seq_params.mib_size - 1)) == 0);
    const DeltaQInfo *const delta_q_info = &cm->delta_q_info;
    if (delta_q_info->delta_q_present_flag &&
        (bsize != cm->seq_params.sb_size || !mbmi->skip_txfm) &&
        super_block_upper_left) {
      xd->current_base_qindex = mbmi->current_qindex;
      if (delta_q_info->delta_lf_present_flag) {
        if (delta_q_info->delta_lf_multi) {
          const int frame_lf_count =
              av1_num_planes(cm) > 1 ? FRAME_LF_COUNT : FRAME_LF_COUNT - 2;
          for (int lf_id = 0; lf_id < frame_lf_count; ++lf_id) {
            xd->delta_lf[lf_id] = mbmi->delta_lf[lf_id];
          }
        } else {
          xd->delta_lf_from_base = mbmi->delta_lf_from_base;
        }
      }
    }

    RD_COUNTS *rdc = &td->rd_counts;
    if (mbmi->skip_mode) {
      assert(!frame_is_intra_only(cm));
      rdc->skip_mode_used_flag = 1;
      if (cm->current_frame.reference_mode == REFERENCE_MODE_SELECT) {
        assert(has_second_ref(mbmi));
        rdc->compound_ref_used_flag = 1;
      }
      set_ref_ptrs(cm, xd, mbmi->ref_frame[0], mbmi->ref_frame[1]);
    } else {
      const int seg_ref_active =
          segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_REF_FRAME);
      if (!seg_ref_active) {
        // If the segment reference feature is enabled we have only a single
        // reference frame allowed for the segment so exclude it from
        // the reference frame counts used to work out probabilities.
        if (is_inter_block(mbmi)) {
          av1_collect_neighbors_ref_counts(xd);
          if (cm->current_frame.reference_mode == REFERENCE_MODE_SELECT) {
            if (has_second_ref(mbmi)) {
              // This flag is also updated for 4x4 blocks
              rdc->compound_ref_used_flag = 1;
            }
          }
          set_ref_ptrs(cm, xd, mbmi->ref_frame[0], mbmi->ref_frame[1]);
        }
      }
    }

    if (tile_data->allow_update_cdf) update_stats(&cpi->common, td);

    // Gather obmc and warped motion count to update the probability.
    if ((!cpi->sf.inter_sf.disable_obmc &&
         cpi->sf.inter_sf.prune_obmc_prob_thresh > 0) ||
        (cm->features.allow_warped_motion &&
         cpi->sf.inter_sf.prune_warped_prob_thresh > 0)) {
      const int inter_block = is_inter_block(mbmi);
      const int seg_ref_active =
          segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_REF_FRAME);
      if (!seg_ref_active && inter_block) {
        const MOTION_MODE motion_allowed =
            cm->features.switchable_motion_mode
                ? motion_mode_allowed(xd->global_motion, xd, mbmi,
                                      cm->features.allow_warped_motion)
                : SIMPLE_TRANSLATION;

        if (mbmi->ref_frame[1] != INTRA_FRAME) {
          if (motion_allowed >= OBMC_CAUSAL) {
            td->rd_counts.obmc_used[bsize][mbmi->motion_mode == OBMC_CAUSAL]++;
          }
          if (motion_allowed == WARPED_CAUSAL) {
            td->rd_counts.warped_used[mbmi->motion_mode == WARPED_CAUSAL]++;
          }
        }
      }
    }
  }
  // TODO(Ravi/Remya): Move this copy function to a better logical place
  // This function will copy the best mode information from block
  // level (x->mbmi_ext) to frame level (cpi->mbmi_ext_info.frame_base). This
  // frame level buffer (cpi->mbmi_ext_info.frame_base) will be used during
  // bitstream preparation.
  av1_copy_mbmi_ext_to_mbmi_ext_frame(x->mbmi_ext_frame, x->mbmi_ext,
                                      av1_ref_frame_type(xd->mi[0]->ref_frame));
  x->rdmult = origin_mult;
}

static AOM_INLINE void encode_sb(const AV1_COMP *const cpi, ThreadData *td,
                                 TileDataEnc *tile_data, TokenExtra **tp,
                                 int mi_row, int mi_col, RUN_TYPE dry_run,
                                 BLOCK_SIZE bsize, PC_TREE *pc_tree,
                                 int *rate) {
  assert(bsize < BLOCK_SIZES_ALL);
  const AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  assert(bsize < BLOCK_SIZES_ALL);
  const int hbs = mi_size_wide[bsize] / 2;
  const int is_partition_root = bsize >= BLOCK_8X8;
  const int ctx = is_partition_root
                      ? partition_plane_context(xd, mi_row, mi_col, bsize)
                      : -1;
  const PARTITION_TYPE partition = pc_tree->partitioning;
  const BLOCK_SIZE subsize = get_partition_subsize(bsize, partition);
  int quarter_step = mi_size_wide[bsize] / 4;
  int i;
  BLOCK_SIZE bsize2 = get_partition_subsize(bsize, PARTITION_SPLIT);

  if (mi_row >= mi_params->mi_rows || mi_col >= mi_params->mi_cols) return;
  if (subsize == BLOCK_INVALID) return;

  if (!dry_run && ctx >= 0) {
    const int has_rows = (mi_row + hbs) < mi_params->mi_rows;
    const int has_cols = (mi_col + hbs) < mi_params->mi_cols;

    if (has_rows && has_cols) {
#if CONFIG_ENTROPY_STATS
      td->counts->partition[ctx][partition]++;
#endif

      if (tile_data->allow_update_cdf) {
        FRAME_CONTEXT *fc = xd->tile_ctx;
        update_cdf(fc->partition_cdf[ctx], partition,
                   partition_cdf_length(bsize));
      }
    }
  }

  switch (partition) {
    case PARTITION_NONE:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, subsize,
               partition, pc_tree->none, rate);
      break;
    case PARTITION_VERT:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, subsize,
               partition, pc_tree->vertical[0], rate);
      if (mi_col + hbs < mi_params->mi_cols) {
        encode_b(cpi, tile_data, td, tp, mi_row, mi_col + hbs, dry_run, subsize,
                 partition, pc_tree->vertical[1], rate);
      }
      break;
    case PARTITION_HORZ:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, subsize,
               partition, pc_tree->horizontal[0], rate);
      if (mi_row + hbs < mi_params->mi_rows) {
        encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col, dry_run, subsize,
                 partition, pc_tree->horizontal[1], rate);
      }
      break;
    case PARTITION_SPLIT:
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, dry_run, subsize,
                pc_tree->split[0], rate);
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col + hbs, dry_run, subsize,
                pc_tree->split[1], rate);
      encode_sb(cpi, td, tile_data, tp, mi_row + hbs, mi_col, dry_run, subsize,
                pc_tree->split[2], rate);
      encode_sb(cpi, td, tile_data, tp, mi_row + hbs, mi_col + hbs, dry_run,
                subsize, pc_tree->split[3], rate);
      break;

    case PARTITION_HORZ_A:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, bsize2,
               partition, pc_tree->horizontala[0], rate);
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col + hbs, dry_run, bsize2,
               partition, pc_tree->horizontala[1], rate);
      encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col, dry_run, subsize,
               partition, pc_tree->horizontala[2], rate);
      break;
    case PARTITION_HORZ_B:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, subsize,
               partition, pc_tree->horizontalb[0], rate);
      encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col, dry_run, bsize2,
               partition, pc_tree->horizontalb[1], rate);
      encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col + hbs, dry_run,
               bsize2, partition, pc_tree->horizontalb[2], rate);
      break;
    case PARTITION_VERT_A:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, bsize2,
               partition, pc_tree->verticala[0], rate);
      encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col, dry_run, bsize2,
               partition, pc_tree->verticala[1], rate);
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col + hbs, dry_run, subsize,
               partition, pc_tree->verticala[2], rate);

      break;
    case PARTITION_VERT_B:
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col, dry_run, subsize,
               partition, pc_tree->verticalb[0], rate);
      encode_b(cpi, tile_data, td, tp, mi_row, mi_col + hbs, dry_run, bsize2,
               partition, pc_tree->verticalb[1], rate);
      encode_b(cpi, tile_data, td, tp, mi_row + hbs, mi_col + hbs, dry_run,
               bsize2, partition, pc_tree->verticalb[2], rate);
      break;
    case PARTITION_HORZ_4:
      for (i = 0; i < 4; ++i) {
        int this_mi_row = mi_row + i * quarter_step;
        if (i > 0 && this_mi_row >= mi_params->mi_rows) break;

        encode_b(cpi, tile_data, td, tp, this_mi_row, mi_col, dry_run, subsize,
                 partition, pc_tree->horizontal4[i], rate);
      }
      break;
    case PARTITION_VERT_4:
      for (i = 0; i < 4; ++i) {
        int this_mi_col = mi_col + i * quarter_step;
        if (i > 0 && this_mi_col >= mi_params->mi_cols) break;
        encode_b(cpi, tile_data, td, tp, mi_row, this_mi_col, dry_run, subsize,
                 partition, pc_tree->vertical4[i], rate);
      }
      break;
    default: assert(0 && "Invalid partition type."); break;
  }

  update_ext_partition_context(xd, mi_row, mi_col, subsize, bsize, partition);
}

static AOM_INLINE void set_partial_sb_partition(
    const AV1_COMMON *const cm, MB_MODE_INFO *mi, int bh_in, int bw_in,
    int mi_rows_remaining, int mi_cols_remaining, BLOCK_SIZE bsize,
    MB_MODE_INFO **mib) {
  int bh = bh_in;
  int r, c;
  for (r = 0; r < cm->seq_params.mib_size; r += bh) {
    int bw = bw_in;
    for (c = 0; c < cm->seq_params.mib_size; c += bw) {
      const int grid_index = get_mi_grid_idx(&cm->mi_params, r, c);
      const int mi_index = get_alloc_mi_idx(&cm->mi_params, r, c);
      mib[grid_index] = mi + mi_index;
      mib[grid_index]->sb_type = find_partition_size(
          bsize, mi_rows_remaining - r, mi_cols_remaining - c, &bh, &bw);
    }
  }
}

// This function attempts to set all mode info entries in a given superblock
// to the same block partition size.
// However, at the bottom and right borders of the image the requested size
// may not be allowed in which case this code attempts to choose the largest
// allowable partition.
static AOM_INLINE void set_fixed_partitioning(AV1_COMP *cpi,
                                              const TileInfo *const tile,
                                              MB_MODE_INFO **mib, int mi_row,
                                              int mi_col, BLOCK_SIZE bsize) {
  AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  const int mi_rows_remaining = tile->mi_row_end - mi_row;
  const int mi_cols_remaining = tile->mi_col_end - mi_col;
  MB_MODE_INFO *const mi_upper_left =
      mi_params->mi_alloc + get_alloc_mi_idx(mi_params, mi_row, mi_col);
  int bh = mi_size_high[bsize];
  int bw = mi_size_wide[bsize];

  assert(bsize >= mi_params->mi_alloc_bsize &&
         "Attempted to use bsize < mi_params->mi_alloc_bsize");
  assert((mi_rows_remaining > 0) && (mi_cols_remaining > 0));

  // Apply the requested partition size to the SB if it is all "in image"
  if ((mi_cols_remaining >= cm->seq_params.mib_size) &&
      (mi_rows_remaining >= cm->seq_params.mib_size)) {
    for (int block_row = 0; block_row < cm->seq_params.mib_size;
         block_row += bh) {
      for (int block_col = 0; block_col < cm->seq_params.mib_size;
           block_col += bw) {
        const int grid_index = get_mi_grid_idx(mi_params, block_row, block_col);
        const int mi_index = get_alloc_mi_idx(mi_params, block_row, block_col);
        mib[grid_index] = mi_upper_left + mi_index;
        mib[grid_index]->sb_type = bsize;
      }
    }
  } else {
    // Else this is a partial SB.
    set_partial_sb_partition(cm, mi_upper_left, bh, bw, mi_rows_remaining,
                             mi_cols_remaining, bsize, mib);
  }
}

/*!\brief AV1 block partition search (partition estimation and partial search).
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Encode the block by applying pre-calculated partition patterns that are
 * represented by coding block sizes stored in the mbmi array. Minor partition
 * adjustments are tested and applied if they lead to lower rd costs. The
 * partition types are limited to a basic set: none, horz, vert, and split.
 *
 * \param[in]    cpi       Top-level encoder structure
 * \param[in]    td        Pointer to thread data
 * \param[in]    tile_data Pointer to struct holding adaptive
                           data/contexts/models for the tile during encoding
 * \param[in]    mib       Array representing MB_MODE_INFO pointers for mi
                           blocks starting from the first pixel of the current
                           block
 * \param[in]    tp        Pointer to the starting token
 * \param[in]    mi_row    Row coordinate of the block in a step size of MI_SIZE
 * \param[in]    mi_col    Column coordinate of the block in a step size of
                           MI_SIZE
 * \param[in]    bsize     Current block size
 * \param[in]    rate      Pointer to the final rate for encoding the current
                           block
 * \param[in]    dist      Pointer to the final distortion of the current block
 * \param[in]    do_recon  Whether the reconstruction function needs to be run,
                           either for finalizing a superblock or providing
                           reference for future sub-partitions
 * \param[in]    pc_tree   Pointer to the PC_TREE node holding the picked
                           partitions and mode info for the current block
 *
 * \return Nothing is returned. The pc_tree struct is modified to store the
 * picked partition and modes. The rate and dist are also updated with those
 * corresponding to the best partition found.
 */
static AOM_INLINE void rd_use_partition(
    AV1_COMP *cpi, ThreadData *td, TileDataEnc *tile_data, MB_MODE_INFO **mib,
    TokenExtra **tp, int mi_row, int mi_col, BLOCK_SIZE bsize, int *rate,
    int64_t *dist, int do_recon, PC_TREE *pc_tree) {
  AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  const int num_planes = av1_num_planes(cm);
  TileInfo *const tile_info = &tile_data->tile_info;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  const ModeCosts *mode_costs = &x->mode_costs;
  const int bs = mi_size_wide[bsize];
  const int hbs = bs / 2;
  const int pl = (bsize >= BLOCK_8X8)
                     ? partition_plane_context(xd, mi_row, mi_col, bsize)
                     : 0;
  const PARTITION_TYPE partition =
      (bsize >= BLOCK_8X8) ? get_partition(cm, mi_row, mi_col, bsize)
                           : PARTITION_NONE;
  const BLOCK_SIZE subsize = get_partition_subsize(bsize, partition);
  RD_SEARCH_MACROBLOCK_CONTEXT x_ctx;
  RD_STATS last_part_rdc, none_rdc, chosen_rdc, invalid_rdc;
  BLOCK_SIZE sub_subsize = BLOCK_4X4;
  int splits_below = 0;
  BLOCK_SIZE bs_type = mib[0]->sb_type;

  if (pc_tree->none == NULL) {
    pc_tree->none = av1_alloc_pmc(cm, bsize, &td->shared_coeff_buf);
  }
  PICK_MODE_CONTEXT *ctx_none = pc_tree->none;

  if (mi_row >= mi_params->mi_rows || mi_col >= mi_params->mi_cols) return;

  assert(mi_size_wide[bsize] == mi_size_high[bsize]);

  av1_invalid_rd_stats(&last_part_rdc);
  av1_invalid_rd_stats(&none_rdc);
  av1_invalid_rd_stats(&chosen_rdc);
  av1_invalid_rd_stats(&invalid_rdc);

  pc_tree->partitioning = partition;

  xd->above_txfm_context =
      cm->above_contexts.txfm[tile_info->tile_row] + mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);
  save_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);

  if (bsize == BLOCK_16X16 && cpi->vaq_refresh) {
    set_offsets(cpi, tile_info, x, mi_row, mi_col, bsize);
    x->mb_energy = av1_log_block_var(cpi, x, bsize);
  }

  // Save rdmult before it might be changed, so it can be restored later.
  const int orig_rdmult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, NO_AQ, NULL);

  if (cpi->sf.part_sf.partition_search_type == VAR_BASED_PARTITION &&
      ((cpi->sf.part_sf.adjust_var_based_rd_partitioning == 2 &&
        bsize <= BLOCK_32X32) ||
       (cpi->sf.part_sf.adjust_var_based_rd_partitioning == 1 &&
        cm->quant_params.base_qindex > 190 && bsize <= BLOCK_32X32 &&
        !frame_is_intra_only(cm)))) {
    // Check if any of the sub blocks are further split.
    if (partition == PARTITION_SPLIT && subsize > BLOCK_8X8) {
      sub_subsize = get_partition_subsize(subsize, PARTITION_SPLIT);
      splits_below = 1;
      for (int i = 0; i < 4; i++) {
        int jj = i >> 1, ii = i & 0x01;
        MB_MODE_INFO *this_mi = mib[jj * hbs * mi_params->mi_stride + ii * hbs];
        if (this_mi && this_mi->sb_type >= sub_subsize) {
          splits_below = 0;
        }
      }
    }

    // If partition is not none try none unless each of the 4 splits are split
    // even further..
    if (partition != PARTITION_NONE && !splits_below &&
        mi_row + hbs < mi_params->mi_rows &&
        mi_col + hbs < mi_params->mi_cols) {
      pc_tree->partitioning = PARTITION_NONE;
      pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &none_rdc,
                    PARTITION_NONE, bsize, ctx_none, invalid_rdc, PICK_MODE_RD);

      if (none_rdc.rate < INT_MAX) {
        none_rdc.rate += mode_costs->partition_cost[pl][PARTITION_NONE];
        none_rdc.rdcost = RDCOST(x->rdmult, none_rdc.rate, none_rdc.dist);
      }

      restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
      mib[0]->sb_type = bs_type;
      pc_tree->partitioning = partition;
    }
  }

  for (int i = 0; i < 4; ++i) {
    pc_tree->split[i] = av1_alloc_pc_tree_node(subsize);
    pc_tree->split[i]->index = i;
  }
  switch (partition) {
    case PARTITION_NONE:
      pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &last_part_rdc,
                    PARTITION_NONE, bsize, ctx_none, invalid_rdc, PICK_MODE_RD);
      break;
    case PARTITION_HORZ:
      for (int i = 0; i < 2; ++i) {
        pc_tree->horizontal[i] =
            av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
      }
      pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &last_part_rdc,
                    PARTITION_HORZ, subsize, pc_tree->horizontal[0],
                    invalid_rdc, PICK_MODE_RD);
      if (last_part_rdc.rate != INT_MAX && bsize >= BLOCK_8X8 &&
          mi_row + hbs < mi_params->mi_rows) {
        RD_STATS tmp_rdc;
        const PICK_MODE_CONTEXT *const ctx_h = pc_tree->horizontal[0];
        av1_init_rd_stats(&tmp_rdc);
        update_state(cpi, td, ctx_h, mi_row, mi_col, subsize, 1);
        encode_superblock(cpi, tile_data, td, tp, DRY_RUN_NORMAL, subsize,
                          NULL);
        pick_sb_modes(cpi, tile_data, x, mi_row + hbs, mi_col, &tmp_rdc,
                      PARTITION_HORZ, subsize, pc_tree->horizontal[1],
                      invalid_rdc, PICK_MODE_RD);
        if (tmp_rdc.rate == INT_MAX || tmp_rdc.dist == INT64_MAX) {
          av1_invalid_rd_stats(&last_part_rdc);
          break;
        }
        last_part_rdc.rate += tmp_rdc.rate;
        last_part_rdc.dist += tmp_rdc.dist;
        last_part_rdc.rdcost += tmp_rdc.rdcost;
      }
      break;
    case PARTITION_VERT:
      for (int i = 0; i < 2; ++i) {
        pc_tree->vertical[i] =
            av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
      }
      pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &last_part_rdc,
                    PARTITION_VERT, subsize, pc_tree->vertical[0], invalid_rdc,
                    PICK_MODE_RD);
      if (last_part_rdc.rate != INT_MAX && bsize >= BLOCK_8X8 &&
          mi_col + hbs < mi_params->mi_cols) {
        RD_STATS tmp_rdc;
        const PICK_MODE_CONTEXT *const ctx_v = pc_tree->vertical[0];
        av1_init_rd_stats(&tmp_rdc);
        update_state(cpi, td, ctx_v, mi_row, mi_col, subsize, 1);
        encode_superblock(cpi, tile_data, td, tp, DRY_RUN_NORMAL, subsize,
                          NULL);
        pick_sb_modes(cpi, tile_data, x, mi_row, mi_col + hbs, &tmp_rdc,
                      PARTITION_VERT, subsize,
                      pc_tree->vertical[bsize > BLOCK_8X8], invalid_rdc,
                      PICK_MODE_RD);
        if (tmp_rdc.rate == INT_MAX || tmp_rdc.dist == INT64_MAX) {
          av1_invalid_rd_stats(&last_part_rdc);
          break;
        }
        last_part_rdc.rate += tmp_rdc.rate;
        last_part_rdc.dist += tmp_rdc.dist;
        last_part_rdc.rdcost += tmp_rdc.rdcost;
      }
      break;
    case PARTITION_SPLIT:
      if (cpi->sf.part_sf.adjust_var_based_rd_partitioning == 1 &&
          none_rdc.rate < INT_MAX && none_rdc.skip_txfm == 1) {
        av1_invalid_rd_stats(&last_part_rdc);
        break;
      }
      last_part_rdc.rate = 0;
      last_part_rdc.dist = 0;
      last_part_rdc.rdcost = 0;
      for (int i = 0; i < 4; i++) {
        int x_idx = (i & 1) * hbs;
        int y_idx = (i >> 1) * hbs;
        int jj = i >> 1, ii = i & 0x01;
        RD_STATS tmp_rdc;
        if ((mi_row + y_idx >= mi_params->mi_rows) ||
            (mi_col + x_idx >= mi_params->mi_cols))
          continue;

        av1_init_rd_stats(&tmp_rdc);
        rd_use_partition(cpi, td, tile_data,
                         mib + jj * hbs * mi_params->mi_stride + ii * hbs, tp,
                         mi_row + y_idx, mi_col + x_idx, subsize, &tmp_rdc.rate,
                         &tmp_rdc.dist, i != 3, pc_tree->split[i]);
        if (tmp_rdc.rate == INT_MAX || tmp_rdc.dist == INT64_MAX) {
          av1_invalid_rd_stats(&last_part_rdc);
          break;
        }
        last_part_rdc.rate += tmp_rdc.rate;
        last_part_rdc.dist += tmp_rdc.dist;
      }
      break;
    case PARTITION_VERT_A:
    case PARTITION_VERT_B:
    case PARTITION_HORZ_A:
    case PARTITION_HORZ_B:
    case PARTITION_HORZ_4:
    case PARTITION_VERT_4:
      assert(0 && "Cannot handle extended partition types");
    default: assert(0); break;
  }

  if (last_part_rdc.rate < INT_MAX) {
    last_part_rdc.rate += mode_costs->partition_cost[pl][partition];
    last_part_rdc.rdcost =
        RDCOST(x->rdmult, last_part_rdc.rate, last_part_rdc.dist);
  }

  if ((cpi->sf.part_sf.partition_search_type == VAR_BASED_PARTITION &&
       cpi->sf.part_sf.adjust_var_based_rd_partitioning > 2) &&
      partition != PARTITION_SPLIT && bsize > BLOCK_8X8 &&
      (mi_row + bs < mi_params->mi_rows ||
       mi_row + hbs == mi_params->mi_rows) &&
      (mi_col + bs < mi_params->mi_cols ||
       mi_col + hbs == mi_params->mi_cols)) {
    BLOCK_SIZE split_subsize = get_partition_subsize(bsize, PARTITION_SPLIT);
    chosen_rdc.rate = 0;
    chosen_rdc.dist = 0;

    restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
    pc_tree->partitioning = PARTITION_SPLIT;

    // Split partition.
    for (int i = 0; i < 4; i++) {
      int x_idx = (i & 1) * hbs;
      int y_idx = (i >> 1) * hbs;
      RD_STATS tmp_rdc;

      if ((mi_row + y_idx >= mi_params->mi_rows) ||
          (mi_col + x_idx >= mi_params->mi_cols))
        continue;

      save_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
      pc_tree->split[i]->partitioning = PARTITION_NONE;
      if (pc_tree->split[i]->none == NULL)
        pc_tree->split[i]->none =
            av1_alloc_pmc(cm, split_subsize, &td->shared_coeff_buf);
      pick_sb_modes(cpi, tile_data, x, mi_row + y_idx, mi_col + x_idx, &tmp_rdc,
                    PARTITION_SPLIT, split_subsize, pc_tree->split[i]->none,
                    invalid_rdc, PICK_MODE_RD);

      restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
      if (tmp_rdc.rate == INT_MAX || tmp_rdc.dist == INT64_MAX) {
        av1_invalid_rd_stats(&chosen_rdc);
        break;
      }

      chosen_rdc.rate += tmp_rdc.rate;
      chosen_rdc.dist += tmp_rdc.dist;

      if (i != 3)
        encode_sb(cpi, td, tile_data, tp, mi_row + y_idx, mi_col + x_idx,
                  OUTPUT_ENABLED, split_subsize, pc_tree->split[i], NULL);

      chosen_rdc.rate += mode_costs->partition_cost[pl][PARTITION_NONE];
    }
    if (chosen_rdc.rate < INT_MAX) {
      chosen_rdc.rate += mode_costs->partition_cost[pl][PARTITION_SPLIT];
      chosen_rdc.rdcost = RDCOST(x->rdmult, chosen_rdc.rate, chosen_rdc.dist);
    }
  }

  // If last_part is better set the partitioning to that.
  if (last_part_rdc.rdcost < chosen_rdc.rdcost) {
    mib[0]->sb_type = bsize;
    if (bsize >= BLOCK_8X8) pc_tree->partitioning = partition;
    chosen_rdc = last_part_rdc;
  }
  // If none was better set the partitioning to that.
  if (none_rdc.rdcost < chosen_rdc.rdcost) {
    if (bsize >= BLOCK_8X8) pc_tree->partitioning = PARTITION_NONE;
    chosen_rdc = none_rdc;
  }

  restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);

  // We must have chosen a partitioning and encoding or we'll fail later on.
  // No other opportunities for success.
  if (bsize == cm->seq_params.sb_size)
    assert(chosen_rdc.rate < INT_MAX && chosen_rdc.dist < INT64_MAX);

  if (do_recon) {
    if (bsize == cm->seq_params.sb_size) {
      // NOTE: To get estimate for rate due to the tokens, use:
      // int rate_coeffs = 0;
      // encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, DRY_RUN_COSTCOEFFS,
      //           bsize, pc_tree, &rate_coeffs);
      x->cb_offset = 0;
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, OUTPUT_ENABLED, bsize,
                pc_tree, NULL);
    } else {
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, DRY_RUN_NORMAL, bsize,
                pc_tree, NULL);
    }
  }

  *rate = chosen_rdc.rate;
  *dist = chosen_rdc.dist;
  x->rdmult = orig_rdmult;
}

static AOM_INLINE void encode_b_nonrd(const AV1_COMP *const cpi,
                                      TileDataEnc *tile_data, ThreadData *td,
                                      TokenExtra **tp, int mi_row, int mi_col,
                                      RUN_TYPE dry_run, BLOCK_SIZE bsize,
                                      PARTITION_TYPE partition,
                                      PICK_MODE_CONTEXT *const ctx, int *rate) {
  TileInfo *const tile = &tile_data->tile_info;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *xd = &x->e_mbd;
  set_offsets_without_segment_id(cpi, tile, x, mi_row, mi_col, bsize);
  const int origin_mult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, NO_AQ, NULL);
  MB_MODE_INFO *mbmi = xd->mi[0];
  mbmi->partition = partition;
  // Nonrd pickmode does not currently support second/combined reference.
  assert(!has_second_ref(mbmi));
  update_state(cpi, td, ctx, mi_row, mi_col, bsize, dry_run);
  if (!dry_run) {
    x->mbmi_ext_frame->cb_offset = x->cb_offset;
    assert(x->cb_offset <
           (1 << num_pels_log2_lookup[cpi->common.seq_params.sb_size]));
  }
  encode_superblock(cpi, tile_data, td, tp, dry_run, bsize, rate);
  if (!dry_run) {
    x->cb_offset += block_size_wide[bsize] * block_size_high[bsize];
    if (tile_data->allow_update_cdf) update_stats(&cpi->common, td);
  }
  // TODO(Ravi/Remya): Move this copy function to a better logical place
  // This function will copy the best mode information from block
  // level (x->mbmi_ext) to frame level (cpi->mbmi_ext_info.frame_base). This
  // frame level buffer (cpi->mbmi_ext_info.frame_base) will be used during
  // bitstream preparation.
  av1_copy_mbmi_ext_to_mbmi_ext_frame(x->mbmi_ext_frame, x->mbmi_ext,
                                      av1_ref_frame_type(xd->mi[0]->ref_frame));
  x->rdmult = origin_mult;
}

static AOM_INLINE void pick_sb_modes_nonrd(AV1_COMP *const cpi,
                                           TileDataEnc *tile_data,
                                           MACROBLOCK *const x, int mi_row,
                                           int mi_col, RD_STATS *rd_cost,
                                           BLOCK_SIZE bsize,
                                           PICK_MODE_CONTEXT *ctx) {
  set_offsets(cpi, &tile_data->tile_info, x, mi_row, mi_col, bsize);
  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCKD *const xd = &x->e_mbd;
  MB_MODE_INFO *mbmi = xd->mi[0];
  struct macroblock_plane *const p = x->plane;
  struct macroblockd_plane *const pd = xd->plane;
  const AQ_MODE aq_mode = cpi->oxcf.aq_mode;
  TxfmSearchInfo *txfm_info = &x->txfm_search_info;
  int i;
#if CONFIG_COLLECT_COMPONENT_TIMING
  start_timing(cpi, rd_pick_sb_modes_time);
#endif
  aom_clear_system_state();
  // Sets up the tx_type_map buffer in MACROBLOCKD.
  xd->tx_type_map = txfm_info->tx_type_map_;
  xd->tx_type_map_stride = mi_size_wide[bsize];
  for (i = 0; i < num_planes; ++i) {
    p[i].coeff = ctx->coeff[i];
    p[i].qcoeff = ctx->qcoeff[i];
    p[i].dqcoeff = ctx->dqcoeff[i];
    p[i].eobs = ctx->eobs[i];
    p[i].txb_entropy_ctx = ctx->txb_entropy_ctx[i];
  }
  for (i = 0; i < 2; ++i) pd[i].color_index_map = ctx->color_index_map[i];
  if (is_cur_buf_hbd(xd)) {
    x->source_variance = av1_high_get_sby_perpixel_variance(
        cpi, &x->plane[0].src, bsize, xd->bd);
  } else {
    x->source_variance =
        av1_get_sby_perpixel_variance(cpi, &x->plane[0].src, bsize);
  }
  // Save rdmult before it might be changed, so it can be restored later.
  const int orig_rdmult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, aq_mode, mbmi);
  // Set error per bit for current rdmult
  av1_set_error_per_bit(&x->mv_costs, x->rdmult);
  // Find best coding mode & reconstruct the MB so it is available
  // as a predictor for MBs that follow in the SB
  if (frame_is_intra_only(cm)) {
#if CONFIG_COLLECT_COMPONENT_TIMING
    start_timing(cpi, av1_rd_pick_intra_mode_sb_time);
#endif
    hybrid_intra_mode_search(cpi, x, rd_cost, bsize, ctx);
#if CONFIG_COLLECT_COMPONENT_TIMING
    end_timing(cpi, av1_rd_pick_intra_mode_sb_time);
#endif
  } else {
#if CONFIG_COLLECT_COMPONENT_TIMING
    start_timing(cpi, av1_rd_pick_inter_mode_sb_time);
#endif
    if (segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_SKIP)) {
      RD_STATS invalid_rd;
      av1_invalid_rd_stats(&invalid_rd);
      // TODO(kyslov): add av1_nonrd_pick_inter_mode_sb_seg_skip
      av1_rd_pick_inter_mode_sb_seg_skip(cpi, tile_data, x, mi_row, mi_col,
                                         rd_cost, bsize, ctx,
                                         invalid_rd.rdcost);
    } else {
      av1_nonrd_pick_inter_mode_sb(cpi, tile_data, x, rd_cost, bsize, ctx);
    }
#if CONFIG_COLLECT_COMPONENT_TIMING
    end_timing(cpi, av1_rd_pick_inter_mode_sb_time);
#endif
  }
  x->rdmult = orig_rdmult;
  ctx->rd_stats.rate = rd_cost->rate;
  ctx->rd_stats.dist = rd_cost->dist;
  ctx->rd_stats.rdcost = rd_cost->rdcost;
#if CONFIG_COLLECT_COMPONENT_TIMING
  end_timing(cpi, rd_pick_sb_modes_time);
#endif
}

static int is_leaf_split_partition(AV1_COMMON *cm, int mi_row, int mi_col,
                                   BLOCK_SIZE bsize) {
  const int bs = mi_size_wide[bsize];
  const int hbs = bs / 2;
  assert(bsize >= BLOCK_8X8);
  const BLOCK_SIZE subsize = get_partition_subsize(bsize, PARTITION_SPLIT);

  for (int i = 0; i < 4; i++) {
    int x_idx = (i & 1) * hbs;
    int y_idx = (i >> 1) * hbs;
    if ((mi_row + y_idx >= cm->mi_params.mi_rows) ||
        (mi_col + x_idx >= cm->mi_params.mi_cols))
      return 0;
    if (get_partition(cm, mi_row + y_idx, mi_col + x_idx, subsize) !=
            PARTITION_NONE &&
        subsize != BLOCK_8X8)
      return 0;
  }
  return 1;
}

static AOM_INLINE int do_slipt_check(BLOCK_SIZE bsize) {
  return (bsize == BLOCK_16X16 || bsize == BLOCK_32X32);
}

/*!\brief AV1 block partition application (minimal RD search).
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Encode the block by applying pre-calculated partition patterns that are
 * represented by coding block sizes stored in the mbmi array. The only
 * partition adjustment allowed is merging leaf split nodes if it leads to a
 * lower rd cost. The partition types are limited to a basic set: none, horz,
 * vert, and split. This function is only used in the real-time mode.
 *
 * \param[in]    cpi       Top-level encoder structure
 * \param[in]    td        Pointer to thread data
 * \param[in]    tile_data Pointer to struct holding adaptive
                           data/contexts/models for the tile during encoding
 * \param[in]    mib       Array representing MB_MODE_INFO pointers for mi
                           blocks starting from the first pixel of the current
                           block
 * \param[in]    tp        Pointer to the starting token
 * \param[in]    mi_row    Row coordinate of the block in a step size of MI_SIZE
 * \param[in]    mi_col    Column coordinate of the block in a step size of
                           MI_SIZE
 * \param[in]    bsize     Current block size
 * \param[in]    pc_tree   Pointer to the PC_TREE node holding the picked
                           partitions and mode info for the current block
 *
 * \return Nothing is returned. The pc_tree struct is modified to store the
 * picked partition and modes.
 */
static AOM_INLINE void nonrd_use_partition(AV1_COMP *cpi, ThreadData *td,
                                           TileDataEnc *tile_data,
                                           MB_MODE_INFO **mib, TokenExtra **tp,
                                           int mi_row, int mi_col,
                                           BLOCK_SIZE bsize, PC_TREE *pc_tree) {
  AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  TileInfo *const tile_info = &tile_data->tile_info;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  const ModeCosts *mode_costs = &x->mode_costs;
  // Only square blocks from 8x8 to 128x128 are supported
  assert(bsize >= BLOCK_8X8 && bsize <= BLOCK_128X128);
  const int bs = mi_size_wide[bsize];
  const int hbs = bs / 2;
  const PARTITION_TYPE partition =
      (bsize >= BLOCK_8X8) ? get_partition(cm, mi_row, mi_col, bsize)
                           : PARTITION_NONE;
  BLOCK_SIZE subsize = get_partition_subsize(bsize, partition);
  assert(subsize <= BLOCK_LARGEST);
  const int pl = (bsize >= BLOCK_8X8)
                     ? partition_plane_context(xd, mi_row, mi_col, bsize)
                     : 0;

  RD_STATS dummy_cost;
  av1_invalid_rd_stats(&dummy_cost);

  if (mi_row >= mi_params->mi_rows || mi_col >= mi_params->mi_cols) return;

  assert(mi_size_wide[bsize] == mi_size_high[bsize]);

  pc_tree->partitioning = partition;

  xd->above_txfm_context =
      cm->above_contexts.txfm[tile_info->tile_row] + mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);

  // Initialize default mode evaluation params
  set_mode_eval_params(cpi, x, DEFAULT_EVAL);

  switch (partition) {
    case PARTITION_NONE:
      pc_tree->none = av1_alloc_pmc(cm, bsize, &td->shared_coeff_buf);
      if (cpi->sf.rt_sf.nonrd_check_partition_split && do_slipt_check(bsize) &&
          !frame_is_intra_only(cm)) {
        RD_STATS split_rdc, none_rdc, block_rdc;
        RD_SEARCH_MACROBLOCK_CONTEXT x_ctx;

        av1_init_rd_stats(&split_rdc);
        av1_invalid_rd_stats(&none_rdc);

        save_context(x, &x_ctx, mi_row, mi_col, bsize, 3);
        subsize = get_partition_subsize(bsize, PARTITION_SPLIT);
        pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col, &none_rdc, bsize,
                            pc_tree->none);
        none_rdc.rate += mode_costs->partition_cost[pl][PARTITION_NONE];
        none_rdc.rdcost = RDCOST(x->rdmult, none_rdc.rate, none_rdc.dist);
        restore_context(x, &x_ctx, mi_row, mi_col, bsize, 3);

        for (int i = 0; i < 4; i++) {
          av1_invalid_rd_stats(&block_rdc);
          const int x_idx = (i & 1) * hbs;
          const int y_idx = (i >> 1) * hbs;
          if (mi_row + y_idx >= mi_params->mi_rows ||
              mi_col + x_idx >= mi_params->mi_cols)
            continue;
          xd->above_txfm_context =
              cm->above_contexts.txfm[tile_info->tile_row] + mi_col + x_idx;
          xd->left_txfm_context =
              xd->left_txfm_context_buffer + ((mi_row + y_idx) & MAX_MIB_MASK);
          pc_tree->split[i]->partitioning = PARTITION_NONE;
          pick_sb_modes_nonrd(cpi, tile_data, x, mi_row + y_idx, mi_col + x_idx,
                              &block_rdc, subsize, pc_tree->split[i]->none);
          split_rdc.rate += block_rdc.rate;
          split_rdc.dist += block_rdc.dist;

          encode_b_nonrd(cpi, tile_data, td, tp, mi_row + y_idx, mi_col + x_idx,
                         1, subsize, PARTITION_NONE, pc_tree->split[i]->none,
                         NULL);
        }
        split_rdc.rate += mode_costs->partition_cost[pl][PARTITION_SPLIT];
        split_rdc.rdcost = RDCOST(x->rdmult, split_rdc.rate, split_rdc.dist);
        restore_context(x, &x_ctx, mi_row, mi_col, bsize, 3);

        if (none_rdc.rdcost < split_rdc.rdcost) {
          mib[0]->sb_type = bsize;
          pc_tree->partitioning = PARTITION_NONE;
          encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col, 0, bsize,
                         partition, pc_tree->none, NULL);
        } else {
          mib[0]->sb_type = subsize;
          pc_tree->partitioning = PARTITION_SPLIT;
          for (int i = 0; i < 4; i++) {
            const int x_idx = (i & 1) * hbs;
            const int y_idx = (i >> 1) * hbs;
            if (mi_row + y_idx >= mi_params->mi_rows ||
                mi_col + x_idx >= mi_params->mi_cols)
              continue;
            encode_b_nonrd(cpi, tile_data, td, tp, mi_row + y_idx,
                           mi_col + x_idx, 0, subsize, PARTITION_NONE,
                           pc_tree->split[i]->none, NULL);
          }
        }

      } else {
        pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col, &dummy_cost,
                            bsize, pc_tree->none);
        encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col, 0, bsize,
                       partition, pc_tree->none, NULL);
      }
      break;
    case PARTITION_VERT:
      for (int i = 0; i < 2; ++i) {
        pc_tree->vertical[i] =
            av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
      }
      pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col, &dummy_cost,
                          subsize, pc_tree->vertical[0]);
      encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col, 0, subsize,
                     PARTITION_VERT, pc_tree->vertical[0], NULL);
      if (mi_col + hbs < mi_params->mi_cols && bsize > BLOCK_8X8) {
        pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col + hbs,
                            &dummy_cost, subsize, pc_tree->vertical[1]);
        encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col + hbs, 0, subsize,
                       PARTITION_VERT, pc_tree->vertical[1], NULL);
      }
      break;
    case PARTITION_HORZ:
      for (int i = 0; i < 2; ++i) {
        pc_tree->horizontal[i] =
            av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
      }
      pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col, &dummy_cost,
                          subsize, pc_tree->horizontal[0]);
      encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col, 0, subsize,
                     PARTITION_HORZ, pc_tree->horizontal[0], NULL);

      if (mi_row + hbs < mi_params->mi_rows && bsize > BLOCK_8X8) {
        pick_sb_modes_nonrd(cpi, tile_data, x, mi_row + hbs, mi_col,
                            &dummy_cost, subsize, pc_tree->horizontal[1]);
        encode_b_nonrd(cpi, tile_data, td, tp, mi_row + hbs, mi_col, 0, subsize,
                       PARTITION_HORZ, pc_tree->horizontal[1], NULL);
      }
      break;
    case PARTITION_SPLIT:
      for (int i = 0; i < 4; ++i) {
        pc_tree->split[i] = av1_alloc_pc_tree_node(subsize);
        pc_tree->split[i]->index = i;
      }
      if (cpi->sf.rt_sf.nonrd_check_partition_merge_mode &&
          is_leaf_split_partition(cm, mi_row, mi_col, bsize) &&
          !frame_is_intra_only(cm) && bsize <= BLOCK_32X32) {
        RD_SEARCH_MACROBLOCK_CONTEXT x_ctx;
        RD_STATS split_rdc, none_rdc;
        av1_invalid_rd_stats(&split_rdc);
        av1_invalid_rd_stats(&none_rdc);
        save_context(x, &x_ctx, mi_row, mi_col, bsize, 3);
        xd->above_txfm_context =
            cm->above_contexts.txfm[tile_info->tile_row] + mi_col;
        xd->left_txfm_context =
            xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);
        pc_tree->partitioning = PARTITION_NONE;
        pc_tree->none = av1_alloc_pmc(cm, bsize, &td->shared_coeff_buf);
        pick_sb_modes_nonrd(cpi, tile_data, x, mi_row, mi_col, &none_rdc, bsize,
                            pc_tree->none);
        none_rdc.rate += mode_costs->partition_cost[pl][PARTITION_NONE];
        none_rdc.rdcost = RDCOST(x->rdmult, none_rdc.rate, none_rdc.dist);
        restore_context(x, &x_ctx, mi_row, mi_col, bsize, 3);
        if (cpi->sf.rt_sf.nonrd_check_partition_merge_mode != 2 ||
            none_rdc.skip_txfm != 1 || pc_tree->none->mic.mode == NEWMV) {
          av1_init_rd_stats(&split_rdc);
          for (int i = 0; i < 4; i++) {
            RD_STATS block_rdc;
            av1_invalid_rd_stats(&block_rdc);
            int x_idx = (i & 1) * hbs;
            int y_idx = (i >> 1) * hbs;
            if ((mi_row + y_idx >= mi_params->mi_rows) ||
                (mi_col + x_idx >= mi_params->mi_cols))
              continue;
            xd->above_txfm_context =
                cm->above_contexts.txfm[tile_info->tile_row] + mi_col + x_idx;
            xd->left_txfm_context = xd->left_txfm_context_buffer +
                                    ((mi_row + y_idx) & MAX_MIB_MASK);
            if (pc_tree->split[i]->none == NULL)
              pc_tree->split[i]->none =
                  av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
            pc_tree->split[i]->partitioning = PARTITION_NONE;
            pick_sb_modes_nonrd(cpi, tile_data, x, mi_row + y_idx,
                                mi_col + x_idx, &block_rdc, subsize,
                                pc_tree->split[i]->none);
            split_rdc.rate += block_rdc.rate;
            split_rdc.dist += block_rdc.dist;

            encode_b_nonrd(cpi, tile_data, td, tp, mi_row + y_idx,
                           mi_col + x_idx, 1, subsize, PARTITION_NONE,
                           pc_tree->split[i]->none, NULL);
          }
          restore_context(x, &x_ctx, mi_row, mi_col, bsize, 3);
          split_rdc.rate += mode_costs->partition_cost[pl][PARTITION_SPLIT];
          split_rdc.rdcost = RDCOST(x->rdmult, split_rdc.rate, split_rdc.dist);
        }
        if (none_rdc.rdcost < split_rdc.rdcost) {
          mib[0]->sb_type = bsize;
          pc_tree->partitioning = PARTITION_NONE;
          encode_b_nonrd(cpi, tile_data, td, tp, mi_row, mi_col, 0, bsize,
                         partition, pc_tree->none, NULL);
        } else {
          mib[0]->sb_type = subsize;
          pc_tree->partitioning = PARTITION_SPLIT;
          for (int i = 0; i < 4; i++) {
            int x_idx = (i & 1) * hbs;
            int y_idx = (i >> 1) * hbs;
            if ((mi_row + y_idx >= mi_params->mi_rows) ||
                (mi_col + x_idx >= mi_params->mi_cols))
              continue;

            if (pc_tree->split[i]->none == NULL)
              pc_tree->split[i]->none =
                  av1_alloc_pmc(cm, subsize, &td->shared_coeff_buf);
            encode_b_nonrd(cpi, tile_data, td, tp, mi_row + y_idx,
                           mi_col + x_idx, 0, subsize, PARTITION_NONE,
                           pc_tree->split[i]->none, NULL);
          }
        }
      } else {
        for (int i = 0; i < 4; i++) {
          int x_idx = (i & 1) * hbs;
          int y_idx = (i >> 1) * hbs;
          int jj = i >> 1, ii = i & 0x01;
          if ((mi_row + y_idx >= mi_params->mi_rows) ||
              (mi_col + x_idx >= mi_params->mi_cols))
            continue;
          nonrd_use_partition(cpi, td, tile_data,
                              mib + jj * hbs * mi_params->mi_stride + ii * hbs,
                              tp, mi_row + y_idx, mi_col + x_idx, subsize,
                              pc_tree->split[i]);
        }
      }
      break;
    case PARTITION_VERT_A:
    case PARTITION_VERT_B:
    case PARTITION_HORZ_A:
    case PARTITION_HORZ_B:
    case PARTITION_HORZ_4:
    case PARTITION_VERT_4:
      assert(0 && "Cannot handle extended partition types");
    default: assert(0); break;
  }
}

#if !CONFIG_REALTIME_ONLY
static const FIRSTPASS_STATS *read_one_frame_stats(const TWO_PASS *p, int frm) {
  assert(frm >= 0);
  if (frm < 0 ||
      p->stats_buf_ctx->stats_in_start + frm > p->stats_buf_ctx->stats_in_end) {
    return NULL;
  }

  return &p->stats_buf_ctx->stats_in_start[frm];
}
// Checks to see if a super block is on a horizontal image edge.
// In most cases this is the "real" edge unless there are formatting
// bars embedded in the stream.
static int active_h_edge(const AV1_COMP *cpi, int mi_row, int mi_step) {
  int top_edge = 0;
  int bottom_edge = cpi->common.mi_params.mi_rows;
  int is_active_h_edge = 0;

  // For two pass account for any formatting bars detected.
  if (is_stat_consumption_stage_twopass(cpi)) {
    const AV1_COMMON *const cm = &cpi->common;
    const FIRSTPASS_STATS *const this_frame_stats = read_one_frame_stats(
        &cpi->twopass, cm->current_frame.display_order_hint);
    if (this_frame_stats == NULL) return AOM_CODEC_ERROR;

    // The inactive region is specified in MBs not mi units.
    // The image edge is in the following MB row.
    top_edge += (int)(this_frame_stats->inactive_zone_rows * 4);

    bottom_edge -= (int)(this_frame_stats->inactive_zone_rows * 4);
    bottom_edge = AOMMAX(top_edge, bottom_edge);
  }

  if (((top_edge >= mi_row) && (top_edge < (mi_row + mi_step))) ||
      ((bottom_edge >= mi_row) && (bottom_edge < (mi_row + mi_step)))) {
    is_active_h_edge = 1;
  }
  return is_active_h_edge;
}

// Checks to see if a super block is on a vertical image edge.
// In most cases this is the "real" edge unless there are formatting
// bars embedded in the stream.
static int active_v_edge(const AV1_COMP *cpi, int mi_col, int mi_step) {
  int left_edge = 0;
  int right_edge = cpi->common.mi_params.mi_cols;
  int is_active_v_edge = 0;

  // For two pass account for any formatting bars detected.
  if (is_stat_consumption_stage_twopass(cpi)) {
    const AV1_COMMON *const cm = &cpi->common;
    const FIRSTPASS_STATS *const this_frame_stats = read_one_frame_stats(
        &cpi->twopass, cm->current_frame.display_order_hint);
    if (this_frame_stats == NULL) return AOM_CODEC_ERROR;

    // The inactive region is specified in MBs not mi units.
    // The image edge is in the following MB row.
    left_edge += (int)(this_frame_stats->inactive_zone_cols * 4);

    right_edge -= (int)(this_frame_stats->inactive_zone_cols * 4);
    right_edge = AOMMAX(left_edge, right_edge);
  }

  if (((left_edge >= mi_col) && (left_edge < (mi_col + mi_step))) ||
      ((right_edge >= mi_col) && (right_edge < (mi_col + mi_step)))) {
    is_active_v_edge = 1;
  }
  return is_active_v_edge;
}
#endif  // !CONFIG_REALTIME_ONLY

#if !CONFIG_REALTIME_ONLY
// Try searching for an encoding for the given subblock. Returns zero if the
// rdcost is already too high (to tell the caller not to bother searching for
// encodings of further subblocks).
static int rd_try_subblock(AV1_COMP *const cpi, ThreadData *td,
                           TileDataEnc *tile_data, TokenExtra **tp, int is_last,
                           int mi_row, int mi_col, BLOCK_SIZE subsize,
                           RD_STATS best_rdcost, RD_STATS *sum_rdc,
                           PARTITION_TYPE partition,
                           PICK_MODE_CONTEXT *this_ctx) {
  MACROBLOCK *const x = &td->mb;
  const int orig_mult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, subsize, NO_AQ, NULL);

  av1_rd_cost_update(x->rdmult, &best_rdcost);

  RD_STATS rdcost_remaining;
  av1_rd_stats_subtraction(x->rdmult, &best_rdcost, sum_rdc, &rdcost_remaining);
  RD_STATS this_rdc;
  pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &this_rdc, partition,
                subsize, this_ctx, rdcost_remaining, PICK_MODE_RD);

  if (this_rdc.rate == INT_MAX) {
    sum_rdc->rdcost = INT64_MAX;
  } else {
    sum_rdc->rate += this_rdc.rate;
    sum_rdc->dist += this_rdc.dist;
    av1_rd_cost_update(x->rdmult, sum_rdc);
  }

  if (sum_rdc->rdcost >= best_rdcost.rdcost) {
    x->rdmult = orig_mult;
    return 0;
  }

  if (!is_last) {
    update_state(cpi, td, this_ctx, mi_row, mi_col, subsize, 1);
    encode_superblock(cpi, tile_data, td, tp, DRY_RUN_NORMAL, subsize, NULL);
  }

  x->rdmult = orig_mult;
  return 1;
}

// Tests an AB partition, and updates the encoder status, the pick mode
// contexts, the best rdcost, and the best partition.
static bool rd_test_partition3(AV1_COMP *const cpi, ThreadData *td,
                               TileDataEnc *tile_data, TokenExtra **tp,
                               PC_TREE *pc_tree, RD_STATS *best_rdc,
                               PICK_MODE_CONTEXT *ctxs[SUB_PARTITIONS_AB],
                               int mi_row, int mi_col, BLOCK_SIZE bsize,
                               PARTITION_TYPE partition,
                               const BLOCK_SIZE ab_subsize[SUB_PARTITIONS_AB],
                               const int ab_mi_pos[SUB_PARTITIONS_AB][2]) {
  const MACROBLOCK *const x = &td->mb;
  const MACROBLOCKD *const xd = &x->e_mbd;
  const int pl = partition_plane_context(xd, mi_row, mi_col, bsize);
  RD_STATS sum_rdc;
  av1_init_rd_stats(&sum_rdc);
  sum_rdc.rate = x->mode_costs.partition_cost[pl][partition];
  sum_rdc.rdcost = RDCOST(x->rdmult, sum_rdc.rate, 0);
  // Loop over sub-partitions in AB partition type.
  for (int i = 0; i < SUB_PARTITIONS_AB; i++) {
    if (!rd_try_subblock(cpi, td, tile_data, tp, i == SUB_PARTITIONS_AB - 1,
                         ab_mi_pos[i][0], ab_mi_pos[i][1], ab_subsize[i],
                         *best_rdc, &sum_rdc, partition, ctxs[i]))
      return false;
  }

  av1_rd_cost_update(x->rdmult, &sum_rdc);
  if (sum_rdc.rdcost >= best_rdc->rdcost) return false;
  sum_rdc.rdcost = RDCOST(x->rdmult, sum_rdc.rate, sum_rdc.dist);
  if (sum_rdc.rdcost >= best_rdc->rdcost) return false;

  *best_rdc = sum_rdc;
  pc_tree->partitioning = partition;
  return true;
}

static AOM_INLINE void reset_simple_motion_tree_partition(
    SIMPLE_MOTION_DATA_TREE *sms_tree, BLOCK_SIZE bsize) {
  sms_tree->partitioning = PARTITION_NONE;

  if (bsize >= BLOCK_8X8) {
    BLOCK_SIZE subsize = get_partition_subsize(bsize, PARTITION_SPLIT);
    for (int idx = 0; idx < 4; ++idx)
      reset_simple_motion_tree_partition(sms_tree->split[idx], subsize);
  }
}

// Record the ref frames that have been selected by square partition blocks.
static AOM_INLINE void update_picked_ref_frames_mask(MACROBLOCK *const x,
                                                     int ref_type,
                                                     BLOCK_SIZE bsize,
                                                     int mib_size, int mi_row,
                                                     int mi_col) {
  assert(mi_size_wide[bsize] == mi_size_high[bsize]);
  const int sb_size_mask = mib_size - 1;
  const int mi_row_in_sb = mi_row & sb_size_mask;
  const int mi_col_in_sb = mi_col & sb_size_mask;
  const int mi_size = mi_size_wide[bsize];
  for (int i = mi_row_in_sb; i < mi_row_in_sb + mi_size; ++i) {
    for (int j = mi_col_in_sb; j < mi_col_in_sb + mi_size; ++j) {
      x->picked_ref_frames_mask[i * 32 + j] |= 1 << ref_type;
    }
  }
}

/*!\cond */
// This structure contains block size related
// variables for use in rd_pick_partition().
typedef struct {
  // Half of block width to determine block edge.
  int mi_step;

  // Block row and column indices.
  int mi_row;
  int mi_col;

  // Block edge row and column indices.
  int mi_row_edge;
  int mi_col_edge;

  // Block width of current partition block.
  int width;

  // Block width of minimum partition size allowed.
  int min_partition_size_1d;

  // Flag to indicate if partition is 8x8 or higher size.
  int bsize_at_least_8x8;

  // Indicates edge blocks in frame.
  int has_rows;
  int has_cols;

  // Block size of current partition.
  BLOCK_SIZE bsize;

  // Size of current sub-partition.
  BLOCK_SIZE subsize;

  // Size of split partition.
  BLOCK_SIZE split_bsize2;
} PartitionBlkParams;

// Structure holding state variables for partition search.
typedef struct {
  // Intra partitioning related info.
  PartitionSearchInfo *intra_part_info;

  // Parameters related to partition block size.
  PartitionBlkParams part_blk_params;

  // Win flags for HORZ and VERT partition evaluations.
  RD_RECT_PART_WIN_INFO split_part_rect_win[4];

  // RD cost for the current block of given partition type.
  RD_STATS this_rdc;

  // RD cost summed across all blocks of partition type.
  RD_STATS sum_rdc;

  // Array holding partition type cost.
  int tmp_partition_cost[PARTITION_TYPES];

  // Pointer to partition cost buffer
  int *partition_cost;

  // RD costs for different partition types.
  int64_t none_rd;
  int64_t split_rd[4];
  // RD costs for rectangular partitions.
  // rect_part_rd[0][i] is the RD cost of ith partition index of PARTITION_HORZ.
  // rect_part_rd[1][i] is the RD cost of ith partition index of PARTITION_VERT.
  int64_t rect_part_rd[NUM_RECT_PARTS][2];

  // Flags indicating if the corresponding partition was winner or not.
  // Used to bypass similar blocks during AB partition evaluation.
  int is_split_ctx_is_ready[2];
  int is_rect_ctx_is_ready[NUM_RECT_PARTS];

  // Flags to prune/skip particular partition size evaluation.
  int terminate_partition_search;
  int partition_none_allowed;
  int partition_rect_allowed[NUM_RECT_PARTS];
  int do_rectangular_split;
  int do_square_split;
  int prune_rect_part[NUM_RECT_PARTS];

  // Chroma subsampling in x and y directions.
  int ss_x;
  int ss_y;

  // Partition plane context index.
  int pl_ctx_idx;

  // This flag will be set if best partition is found from the search.
  bool found_best_partition;
} PartitionSearchState;
/*!\endcond */

// Initialize state variables of partition search used in rd_pick_partition().
static AOM_INLINE void init_partition_search_state_params(
    MACROBLOCK *x, AV1_COMP *const cpi, PartitionSearchState *part_search_state,
    int mi_row, int mi_col, BLOCK_SIZE bsize) {
  MACROBLOCKD *const xd = &x->e_mbd;
  const AV1_COMMON *const cm = &cpi->common;
  PartitionBlkParams *blk_params = &part_search_state->part_blk_params;
  const CommonModeInfoParams *const mi_params = &cpi->common.mi_params;

  // Initialization of block size related parameters.
  blk_params->mi_step = mi_size_wide[bsize] / 2;
  blk_params->mi_row = mi_row;
  blk_params->mi_col = mi_col;
  blk_params->mi_row_edge = mi_row + blk_params->mi_step;
  blk_params->mi_col_edge = mi_col + blk_params->mi_step;
  blk_params->width = block_size_wide[bsize];
  blk_params->min_partition_size_1d =
      block_size_wide[x->sb_enc.min_partition_size];
  blk_params->subsize = get_partition_subsize(bsize, PARTITION_SPLIT);
  blk_params->split_bsize2 = blk_params->subsize;
  blk_params->bsize_at_least_8x8 = (bsize >= BLOCK_8X8);
  blk_params->bsize = bsize;

  // Check if the partition corresponds to edge block.
  blk_params->has_rows = (blk_params->mi_row_edge < mi_params->mi_rows);
  blk_params->has_cols = (blk_params->mi_col_edge < mi_params->mi_cols);

  // Update intra partitioning related info.
  part_search_state->intra_part_info = &x->part_search_info;
  // Prepare for segmentation CNN-based partitioning for intra-frame.
  if (frame_is_intra_only(cm) && bsize == BLOCK_64X64) {
    part_search_state->intra_part_info->quad_tree_idx = 0;
    part_search_state->intra_part_info->cnn_output_valid = 0;
  }

  // Set partition plane context index.
  part_search_state->pl_ctx_idx =
      blk_params->bsize_at_least_8x8
          ? partition_plane_context(xd, mi_row, mi_col, bsize)
          : 0;

  // Partition cost buffer update
  ModeCosts *mode_costs = &x->mode_costs;
  part_search_state->partition_cost =
      mode_costs->partition_cost[part_search_state->pl_ctx_idx];

  // Initialize HORZ and VERT win flags as true for all split partitions.
  for (int i = 0; i < 4; i++) {
    part_search_state->split_part_rect_win[i].rect_part_win[HORZ] = true;
    part_search_state->split_part_rect_win[i].rect_part_win[VERT] = true;
  }

  // Initialize the rd cost.
  av1_init_rd_stats(&part_search_state->this_rdc);

  // Initialize RD costs for partition types to 0.
  part_search_state->none_rd = 0;
  av1_zero(part_search_state->split_rd);
  av1_zero(part_search_state->rect_part_rd);

  // Initialize SPLIT partition to be not ready.
  av1_zero(part_search_state->is_split_ctx_is_ready);
  // Initialize HORZ and VERT partitions to be not ready.
  av1_zero(part_search_state->is_rect_ctx_is_ready);

  // Chroma subsampling.
  part_search_state->ss_x = x->e_mbd.plane[1].subsampling_x;
  part_search_state->ss_y = x->e_mbd.plane[1].subsampling_y;

  // Initialize partition search flags to defaults.
  part_search_state->terminate_partition_search = 0;
  part_search_state->do_square_split = blk_params->bsize_at_least_8x8;
  part_search_state->do_rectangular_split =
      cpi->oxcf.part_cfg.enable_rect_partitions;
  av1_zero(part_search_state->prune_rect_part);

  // Initialize allowed partition types for the partition block.
  part_search_state->partition_none_allowed =
      blk_params->has_rows && blk_params->has_cols;
  part_search_state->partition_rect_allowed[HORZ] =
      blk_params->has_cols && blk_params->bsize_at_least_8x8 &&
      cpi->oxcf.part_cfg.enable_rect_partitions &&
      get_plane_block_size(get_partition_subsize(bsize, PARTITION_HORZ),
                           part_search_state->ss_x,
                           part_search_state->ss_y) != BLOCK_INVALID;
  part_search_state->partition_rect_allowed[VERT] =
      blk_params->has_rows && blk_params->bsize_at_least_8x8 &&
      cpi->oxcf.part_cfg.enable_rect_partitions &&
      get_plane_block_size(get_partition_subsize(bsize, PARTITION_VERT),
                           part_search_state->ss_x,
                           part_search_state->ss_y) != BLOCK_INVALID;

  // Reset the flag indicating whether a partition leading to a rdcost lower
  // than the bound best_rdc has been found.
  part_search_state->found_best_partition = false;
}

// Override partition cost buffer for the edge blocks.
static AOM_INLINE void set_partition_cost_for_edge_blk(
    AV1_COMMON const *cm, PartitionSearchState *part_search_state) {
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  assert(blk_params.bsize_at_least_8x8 && part_search_state->pl_ctx_idx >= 0);
  const aom_cdf_prob *partition_cdf =
      cm->fc->partition_cdf[part_search_state->pl_ctx_idx];
  const int max_cost = av1_cost_symbol(0);
  for (PARTITION_TYPE i = 0; i < PARTITION_TYPES; ++i)
    part_search_state->tmp_partition_cost[i] = max_cost;
  if (blk_params.has_cols) {
    // At the bottom, the two possibilities are HORZ and SPLIT.
    aom_cdf_prob bot_cdf[2];
    partition_gather_vert_alike(bot_cdf, partition_cdf, blk_params.bsize);
    static const int bot_inv_map[2] = { PARTITION_HORZ, PARTITION_SPLIT };
    av1_cost_tokens_from_cdf(part_search_state->tmp_partition_cost, bot_cdf,
                             bot_inv_map);
  } else if (blk_params.has_rows) {
    // At the right, the two possibilities are VERT and SPLIT.
    aom_cdf_prob rhs_cdf[2];
    partition_gather_horz_alike(rhs_cdf, partition_cdf, blk_params.bsize);
    static const int rhs_inv_map[2] = { PARTITION_VERT, PARTITION_SPLIT };
    av1_cost_tokens_from_cdf(part_search_state->tmp_partition_cost, rhs_cdf,
                             rhs_inv_map);
  } else {
    // At the bottom right, we always split.
    part_search_state->tmp_partition_cost[PARTITION_SPLIT] = 0;
  }
  // Override the partition cost buffer.
  part_search_state->partition_cost = part_search_state->tmp_partition_cost;
}

// Reset the partition search state flags when
// must_find_valid_partition is equal to 1.
static AOM_INLINE void reset_part_limitations(
    AV1_COMP *const cpi, PartitionSearchState *part_search_state) {
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  const int is_rect_part_allowed =
      blk_params.bsize_at_least_8x8 &&
      cpi->oxcf.part_cfg.enable_rect_partitions &&
      (blk_params.width > blk_params.min_partition_size_1d);
  part_search_state->do_square_split =
      blk_params.bsize_at_least_8x8 &&
      (blk_params.width > blk_params.min_partition_size_1d);
  part_search_state->partition_none_allowed =
      blk_params.has_rows && blk_params.has_cols &&
      (blk_params.width >= blk_params.min_partition_size_1d);
  part_search_state->partition_rect_allowed[HORZ] =
      blk_params.has_cols && is_rect_part_allowed &&
      get_plane_block_size(
          get_partition_subsize(blk_params.bsize, PARTITION_HORZ),
          part_search_state->ss_x, part_search_state->ss_y) != BLOCK_INVALID;
  part_search_state->partition_rect_allowed[VERT] =
      blk_params.has_rows && is_rect_part_allowed &&
      get_plane_block_size(
          get_partition_subsize(blk_params.bsize, PARTITION_VERT),
          part_search_state->ss_x, part_search_state->ss_y) != BLOCK_INVALID;
  part_search_state->terminate_partition_search = 0;
}

// Rectangular partitions evaluation at sub-block level.
static AOM_INLINE void rd_pick_rect_partition(
    AV1_COMP *const cpi, TileDataEnc *tile_data, MACROBLOCK *x,
    PICK_MODE_CONTEXT *cur_partition_ctx,
    PartitionSearchState *part_search_state, RD_STATS *best_rdc, const int idx,
    int mi_row, int mi_col, BLOCK_SIZE bsize, PARTITION_TYPE partition_type) {
  // Obtain the remainder from the best rd cost
  // for further processing of partition.
  RD_STATS best_remain_rdcost;
  av1_rd_stats_subtraction(x->rdmult, best_rdc, &part_search_state->sum_rdc,
                           &best_remain_rdcost);

  // Obtain the best mode for the partition sub-block.
  pick_sb_modes(cpi, tile_data, x, mi_row, mi_col, &part_search_state->this_rdc,
                partition_type, bsize, cur_partition_ctx, best_remain_rdcost,
                PICK_MODE_RD);
  av1_rd_cost_update(x->rdmult, &part_search_state->this_rdc);

  // Update the partition rd cost with the current sub-block rd.
  if (part_search_state->this_rdc.rate == INT_MAX) {
    part_search_state->sum_rdc.rdcost = INT64_MAX;
  } else {
    part_search_state->sum_rdc.rate += part_search_state->this_rdc.rate;
    part_search_state->sum_rdc.dist += part_search_state->this_rdc.dist;
    av1_rd_cost_update(x->rdmult, &part_search_state->sum_rdc);
  }
  const RECT_PART_TYPE rect_part =
      partition_type == PARTITION_HORZ ? HORZ : VERT;
  part_search_state->rect_part_rd[rect_part][idx] =
      part_search_state->this_rdc.rdcost;
}

typedef int (*active_edge_info)(const AV1_COMP *cpi, int mi_col, int mi_step);

// Checks if HORZ / VERT partition search is allowed.
static AOM_INLINE int is_rect_part_allowed(
    const AV1_COMP *cpi, PartitionSearchState *part_search_state,
    active_edge_info *active_edge, RECT_PART_TYPE rect_part, const int mi_pos) {
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  const int is_part_allowed =
      (!part_search_state->terminate_partition_search &&
       part_search_state->partition_rect_allowed[rect_part] &&
       !part_search_state->prune_rect_part[rect_part] &&
       (part_search_state->do_rectangular_split ||
        active_edge[rect_part](cpi, mi_pos, blk_params.mi_step)));
  return is_part_allowed;
}

// Rectangular partition types search function.
static AOM_INLINE void rectangular_partition_search(
    AV1_COMP *const cpi, ThreadData *td, TileDataEnc *tile_data,
    TokenExtra **tp, MACROBLOCK *x, PC_TREE *pc_tree,
    RD_SEARCH_MACROBLOCK_CONTEXT *x_ctx,
    PartitionSearchState *part_search_state, RD_STATS *best_rdc,
    RD_RECT_PART_WIN_INFO *rect_part_win_info) {
  const AV1_COMMON *const cm = &cpi->common;
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  RD_STATS *sum_rdc = &part_search_state->sum_rdc;
  const int rect_partition_type[NUM_RECT_PARTS] = { PARTITION_HORZ,
                                                    PARTITION_VERT };

  // mi_pos_rect[NUM_RECT_PARTS][i][0]: mi_row postion of HORZ and VERT
  //                                    partition types for ith sub-partition.
  // mi_pos_rect[NUM_RECT_PARTS][i][1]: mi_col postion of HORZ and VERT
  //                                    partition types for ith sub-partition.
  const int mi_pos_rect[NUM_RECT_PARTS][2][2] = {
    { { blk_params.mi_row, blk_params.mi_col },
      { blk_params.mi_row_edge, blk_params.mi_col } },
    { { blk_params.mi_row, blk_params.mi_col },
      { blk_params.mi_row, blk_params.mi_col_edge } }
  };

  // Initialize active edge_type function pointer
  // for HOZR and VERT partition types.
  active_edge_info active_edge_type[NUM_RECT_PARTS] = { active_h_edge,
                                                        active_v_edge };

  // Indicates edge blocks for HORZ and VERT partition types.
  const int is_not_edge_block[NUM_RECT_PARTS] = { blk_params.has_rows,
                                                  blk_params.has_cols };

  // Initialize pc tree context for HORZ and VERT partition types.
  PICK_MODE_CONTEXT **cur_ctx[NUM_RECT_PARTS][2] = {
    { &pc_tree->horizontal[0], &pc_tree->horizontal[1] },
    { &pc_tree->vertical[0], &pc_tree->vertical[1] }
  };

  // Loop over rectangular partition types.
  for (RECT_PART_TYPE i = HORZ; i < NUM_RECT_PARTS; i++) {
    assert(IMPLIES(!cpi->oxcf.part_cfg.enable_rect_partitions,
                   !part_search_state->partition_rect_allowed[i]));

    // Check if the HORZ / VERT partition search is to be performed.
    if (!is_rect_part_allowed(cpi, part_search_state, active_edge_type, i,
                              mi_pos_rect[i][0][i]))
      continue;

    // Sub-partition idx.
    int sub_part_idx = 0;
    PARTITION_TYPE partition_type = rect_partition_type[i];
    blk_params.subsize =
        get_partition_subsize(blk_params.bsize, partition_type);
    assert(blk_params.subsize <= BLOCK_LARGEST);
    av1_init_rd_stats(sum_rdc);
    for (int j = 0; j < 2; j++) {
      if (cur_ctx[i][j][0] == NULL) {
        cur_ctx[i][j][0] =
            av1_alloc_pmc(cm, blk_params.subsize, &td->shared_coeff_buf);
      }
    }
    sum_rdc->rate = part_search_state->partition_cost[partition_type];
    sum_rdc->rdcost = RDCOST(x->rdmult, sum_rdc->rate, 0);
#if CONFIG_COLLECT_PARTITION_STATS
    if (best_rdc.rdcost - sum_rdc->rdcost >= 0) {
      partition_attempts[partition_type] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
#endif

    // First sub-partition evaluation in HORZ / VERT partition type.
    rd_pick_rect_partition(
        cpi, tile_data, x, cur_ctx[i][sub_part_idx][0], part_search_state,
        best_rdc, 0, mi_pos_rect[i][sub_part_idx][0],
        mi_pos_rect[i][sub_part_idx][1], blk_params.subsize, partition_type);

    // Start of second sub-partition evaluation.
    // Evaluate second sub-partition if the first sub-partition cost
    // is less than the best cost and if it is not an edge block.
    if (sum_rdc->rdcost < best_rdc->rdcost && is_not_edge_block[i]) {
      const MB_MODE_INFO *const mbmi = &cur_ctx[i][sub_part_idx][0]->mic;
      const PALETTE_MODE_INFO *const pmi = &mbmi->palette_mode_info;
      // Neither palette mode nor cfl predicted.
      if (pmi->palette_size[PLANE_TYPE_Y] == 0 &&
          pmi->palette_size[PLANE_TYPE_UV] == 0) {
        if (mbmi->uv_mode != UV_CFL_PRED)
          part_search_state->is_rect_ctx_is_ready[i] = 1;
      }
      update_state(cpi, td, cur_ctx[i][sub_part_idx][0], blk_params.mi_row,
                   blk_params.mi_col, blk_params.subsize, DRY_RUN_NORMAL);
      encode_superblock(cpi, tile_data, td, tp, DRY_RUN_NORMAL,
                        blk_params.subsize, NULL);

      // Second sub-partition evaluation in HORZ / VERT partition type.
      sub_part_idx = 1;
      rd_pick_rect_partition(
          cpi, tile_data, x, cur_ctx[i][sub_part_idx][0], part_search_state,
          best_rdc, 1, mi_pos_rect[i][sub_part_idx][0],
          mi_pos_rect[i][sub_part_idx][1], blk_params.subsize, partition_type);
    }
#if CONFIG_COLLECT_PARTITION_STATS
    if (partition_timer_on) {
      aom_usec_timer_mark(&partition_timer);
      int64_t time = aom_usec_timer_elapsed(&partition_timer);
      partition_times[partition_type] += time;
      partition_timer_on = 0;
    }
#endif
    // Update HORZ / VERT best partition.
    if (sum_rdc->rdcost < best_rdc->rdcost) {
      sum_rdc->rdcost = RDCOST(x->rdmult, sum_rdc->rate, sum_rdc->dist);
      if (sum_rdc->rdcost < best_rdc->rdcost) {
        *best_rdc = *sum_rdc;
        part_search_state->found_best_partition = true;
        pc_tree->partitioning = partition_type;
      }
    } else {
      // Update HORZ / VERT win flag.
      if (rect_part_win_info != NULL)
        rect_part_win_info->rect_part_win[i] = false;
    }
    restore_context(x, x_ctx, blk_params.mi_row, blk_params.mi_col,
                    blk_params.bsize, av1_num_planes(cm));
  }
}

// AB partition type evaluation.
static void rd_pick_ab_part(
    AV1_COMP *const cpi, ThreadData *td, TileDataEnc *tile_data,
    TokenExtra **tp, MACROBLOCK *x, RD_SEARCH_MACROBLOCK_CONTEXT *x_ctx,
    PC_TREE *pc_tree, PICK_MODE_CONTEXT *dst_ctxs[SUB_PARTITIONS_AB],
    PartitionSearchState *part_search_state, RD_STATS *best_rdc,
    const BLOCK_SIZE ab_subsize[SUB_PARTITIONS_AB],
    const int ab_mi_pos[SUB_PARTITIONS_AB][2], const PARTITION_TYPE part_type) {
  const AV1_COMMON *const cm = &cpi->common;
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  const int mi_row = blk_params.mi_row;
  const int mi_col = blk_params.mi_col;
  const int bsize = blk_params.bsize;

#if CONFIG_COLLECT_PARTITION_STATS
  {
    RD_STATS tmp_sum_rdc;
    av1_init_rd_stats(&tmp_sum_rdc);
    tmp_sum_rdc.rate =
        x->partition_cost[part_search_state->pl_ctx_idx][part_type];
    tmp_sum_rdc.rdcost = RDCOST(x->rdmult, tmp_sum_rdc.rate, 0);
    if (best_rdc->rdcost - tmp_sum_rdc.rdcost >= 0) {
      partition_attempts[part_type] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
  }
#endif

  // Test this partition and update the best partition.
  part_search_state->found_best_partition |= rd_test_partition3(
      cpi, td, tile_data, tp, pc_tree, best_rdc, dst_ctxs, mi_row, mi_col,
      bsize, part_type, ab_subsize, ab_mi_pos);

#if CONFIG_COLLECT_PARTITION_STATS
  if (partition_timer_on) {
    aom_usec_timer_mark(&partition_timer);
    int64_t time = aom_usec_timer_elapsed(&partition_timer);
    partition_times[part_type] += time;
    partition_timer_on = 0;
  }
#endif
  restore_context(x, x_ctx, mi_row, mi_col, bsize, av1_num_planes(cm));
}

// Check if AB partitions search is allowed.
static AOM_INLINE int is_ab_part_allowed(
    PartitionSearchState *part_search_state,
    const int ab_partitions_allowed[NUM_AB_PARTS], const int ab_part_type) {
  const int is_horz_ab = (ab_part_type >> 1);
  const int is_part_allowed =
      (!part_search_state->terminate_partition_search &&
       part_search_state->partition_rect_allowed[is_horz_ab] &&
       ab_partitions_allowed[ab_part_type]);
  return is_part_allowed;
}

// Set mode search context.
static AOM_INLINE void set_mode_search_ctx(
    PC_TREE *pc_tree, const int is_ctx_ready[NUM_AB_PARTS][2],
    PICK_MODE_CONTEXT **mode_srch_ctx[NUM_AB_PARTS][2]) {
  mode_srch_ctx[HORZ_B][0] = &pc_tree->horizontal[0];
  mode_srch_ctx[VERT_B][0] = &pc_tree->vertical[0];

  if (is_ctx_ready[HORZ_A][0])
    mode_srch_ctx[HORZ_A][0] = &pc_tree->split[0]->none;

  if (is_ctx_ready[VERT_A][0])
    mode_srch_ctx[VERT_A][0] = &pc_tree->split[0]->none;

  if (is_ctx_ready[HORZ_A][1])
    mode_srch_ctx[HORZ_A][1] = &pc_tree->split[1]->none;
}

// AB Partitions type search.
static AOM_INLINE void ab_partitions_search(
    AV1_COMP *const cpi, ThreadData *td, TileDataEnc *tile_data,
    TokenExtra **tp, MACROBLOCK *x, RD_SEARCH_MACROBLOCK_CONTEXT *x_ctx,
    PC_TREE *pc_tree, PartitionSearchState *part_search_state,
    RD_STATS *best_rdc, RD_RECT_PART_WIN_INFO *rect_part_win_info,
    int pb_source_variance, int ext_partition_allowed) {
  const AV1_COMMON *const cm = &cpi->common;
  PartitionBlkParams blk_params = part_search_state->part_blk_params;
  const int mi_row = blk_params.mi_row;
  const int mi_col = blk_params.mi_col;
  const int bsize = blk_params.bsize;

  int ab_partitions_allowed[NUM_AB_PARTS] = { 1, 1, 1, 1 };
  // Prune AB partitions
  av1_prune_ab_partitions(
      cpi, x, pc_tree, bsize, pb_source_variance, best_rdc->rdcost,
      part_search_state->rect_part_rd, part_search_state->split_rd,
      rect_part_win_info, ext_partition_allowed,
      part_search_state->partition_rect_allowed[HORZ],
      part_search_state->partition_rect_allowed[VERT],
      &ab_partitions_allowed[HORZ_A], &ab_partitions_allowed[HORZ_B],
      &ab_partitions_allowed[VERT_A], &ab_partitions_allowed[VERT_B]);

  // Flags to indicate whether the mode search is done.
  const int is_ctx_ready[NUM_AB_PARTS][2] = {
    { part_search_state->is_split_ctx_is_ready[0],
      part_search_state->is_split_ctx_is_ready[1] },
    { part_search_state->is_rect_ctx_is_ready[HORZ], 0 },
    { part_search_state->is_split_ctx_is_ready[0], 0 },
    { part_search_state->is_rect_ctx_is_ready[VERT], 0 }
  };

  // Current partition context.
  PICK_MODE_CONTEXT **cur_part_ctxs[NUM_AB_PARTS] = { pc_tree->horizontala,
                                                      pc_tree->horizontalb,
                                                      pc_tree->verticala,
                                                      pc_tree->verticalb };

  // Context of already evaluted partition types.
  PICK_MODE_CONTEXT **mode_srch_ctx[NUM_AB_PARTS][2];
  // Set context of already evaluted partition types.
  set_mode_search_ctx(pc_tree, is_ctx_ready, mode_srch_ctx);

  // Array of sub-partition size of AB partition types.
  const BLOCK_SIZE ab_subsize[NUM_AB_PARTS][SUB_PARTITIONS_AB] = {
    { blk_params.split_bsize2, blk_params.split_bsize2,
      get_partition_subsize(bsize, PARTITION_HORZ_A) },
    { get_partition_subsize(bsize, PARTITION_HORZ_B), blk_params.split_bsize2,
      blk_params.split_bsize2 },
    { blk_params.split_bsize2, blk_params.split_bsize2,
      get_partition_subsize(bsize, PARTITION_VERT_A) },
    { get_partition_subsize(bsize, PARTITION_VERT_B), blk_params.split_bsize2,
      blk_params.split_bsize2 }
  };

  // Array of mi_row, mi_col positions corresponds to each sub-partition in AB
  // partition types.
  const int ab_mi_pos[NUM_AB_PARTS][SUB_PARTITIONS_AB][2] = {
    { { mi_row, mi_col },
      { mi_row, blk_params.mi_col_edge },
      { blk_params.mi_row_edge, mi_col } },
    { { mi_row, mi_col },
      { blk_params.mi_row_edge, mi_col },
      { blk_params.mi_row_edge, blk_params.mi_col_edge } },
    { { mi_row, mi_col },
      { blk_params.mi_row_edge, mi_col },
      { mi_row, blk_params.mi_col_edge } },
    { { mi_row, mi_col },
      { mi_row, blk_params.mi_col_edge },
      { blk_params.mi_row_edge, blk_params.mi_col_edge } }
  };

  // Loop over AB partition types.
  for (AB_PART_TYPE ab_part_type = 0; ab_part_type < NUM_AB_PARTS;
       ab_part_type++) {
    const PARTITION_TYPE part_type = ab_part_type + PARTITION_HORZ_A;

    // Check if the AB partition search is to be performed.
    if (!is_ab_part_allowed(part_search_state, ab_partitions_allowed,
                            ab_part_type))
      continue;

    blk_params.subsize = get_partition_subsize(bsize, part_type);
    for (int i = 0; i < SUB_PARTITIONS_AB; i++) {
      // Set AB partition context.
      cur_part_ctxs[ab_part_type][i] =
          av1_alloc_pmc(cm, ab_subsize[ab_part_type][i], &td->shared_coeff_buf);
      // Set mode as not ready.
      cur_part_ctxs[ab_part_type][i]->rd_mode_is_ready = 0;
    }

    // Copy of mode search results if the ctx is ready.
    if (is_ctx_ready[ab_part_type][0]) {
      av1_copy_tree_context(cur_part_ctxs[ab_part_type][0],
                            mode_srch_ctx[ab_part_type][0][0]);
      cur_part_ctxs[ab_part_type][0]->mic.partition = part_type;
      cur_part_ctxs[ab_part_type][0]->rd_mode_is_ready = 1;
      if (is_ctx_ready[ab_part_type][1]) {
        av1_copy_tree_context(cur_part_ctxs[ab_part_type][1],
                              mode_srch_ctx[ab_part_type][1][0]);
        cur_part_ctxs[ab_part_type][1]->mic.partition = part_type;
        cur_part_ctxs[ab_part_type][1]->rd_mode_is_ready = 1;
      }
    }

    // Evaluation of AB partition type.
    rd_pick_ab_part(cpi, td, tile_data, tp, x, x_ctx, pc_tree,
                    cur_part_ctxs[ab_part_type], part_search_state, best_rdc,
                    ab_subsize[ab_part_type], ab_mi_pos[ab_part_type],
                    part_type);
  }
}

/*!\brief AV1 block partition search (full search).
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Searches for the best partition pattern for a block based on the
 * rate-distortion cost, and returns a bool value to indicate whether a valid
 * partition pattern is found. The partition can recursively go down to the
 * smallest block size.
 *
 * \param[in]    cpi                Top-level encoder structure
 * \param[in]    td                 Pointer to thread data
 * \param[in]    tile_data          Pointer to struct holding adaptive
                                    data/contexts/models for the tile during
                                    encoding
 * \param[in]    tp                 Pointer to the starting token
 * \param[in]    mi_row             Row coordinate of the block in a step size
                                    of MI_SIZE
 * \param[in]    mi_col             Column coordinate of the block in a step
                                    size of MI_SIZE
 * \param[in]    bsize              Current block size
 * \param[in]    rd_cost            Pointer to the final rd cost of the block
 * \param[in]    best_rdc           Upper bound of rd cost of a valid partition
 * \param[in]    pc_tree            Pointer to the PC_TREE node storing the
                                    picked partitions and mode info for the
                                    current block
 * \param[in]    sms_tree           Pointer to struct holding simple motion
                                    search data for the current block
 * \param[in]    none_rd            Pointer to the rd cost in the case of not
                                    splitting the current block
 * \param[in]    multi_pass_mode    SB_SINGLE_PASS/SB_DRY_PASS/SB_WET_PASS
 * \param[in]    rect_part_win_info Pointer to struct storing whether horz/vert
                                    partition outperforms previously tested
                                    partitions
 *
 * \return A bool value is returned indicating if a valid partition is found.
 * The pc_tree struct is modified to store the picked partition and modes.
 * The rd_cost struct is also updated with the RD stats corresponding to the
 * best partition found.
 */
static bool rd_pick_partition(AV1_COMP *const cpi, ThreadData *td,
                              TileDataEnc *tile_data, TokenExtra **tp,
                              int mi_row, int mi_col, BLOCK_SIZE bsize,
                              RD_STATS *rd_cost, RD_STATS best_rdc,
                              PC_TREE *pc_tree,
                              SIMPLE_MOTION_DATA_TREE *sms_tree,
                              int64_t *none_rd,
                              SB_MULTI_PASS_MODE multi_pass_mode,
                              RD_RECT_PART_WIN_INFO *rect_part_win_info) {
  const AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  const int num_planes = av1_num_planes(cm);
  TileInfo *const tile_info = &tile_data->tile_info;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  RD_SEARCH_MACROBLOCK_CONTEXT x_ctx;
  const TokenExtra *const tp_orig = *tp;
  PartitionSearchState part_search_state;
  // Initialization of state variables used in partition search.
  init_partition_search_state_params(x, cpi, &part_search_state, mi_row, mi_col,
                                     bsize);
  PartitionBlkParams blk_params = part_search_state.part_blk_params;
  const PartitionCfg *const part_cfg = &cpi->oxcf.part_cfg;

  sms_tree->partitioning = PARTITION_NONE;
  if (best_rdc.rdcost < 0) {
    av1_invalid_rd_stats(rd_cost);
    return part_search_state.found_best_partition;
  }
  if (bsize == cm->seq_params.sb_size) x->must_find_valid_partition = 0;

  // Override skipping rectangular partition operations for edge blocks.
  if (none_rd) *none_rd = 0;
  (void)*tp_orig;

#if CONFIG_COLLECT_PARTITION_STATS
  int partition_decisions[EXT_PARTITION_TYPES] = { 0 };
  int partition_attempts[EXT_PARTITION_TYPES] = { 0 };
  int64_t partition_times[EXT_PARTITION_TYPES] = { 0 };
  struct aom_usec_timer partition_timer = { 0 };
  int partition_timer_on = 0;
#if CONFIG_COLLECT_PARTITION_STATS == 2
  PartitionStats *part_stats = &cpi->partition_stats;
#endif
#endif

  // Override partition costs at the edges of the frame in the same
  // way as in read_partition (see decodeframe.c).
  if (!(blk_params.has_rows && blk_params.has_cols))
    set_partition_cost_for_edge_blk(cm, &part_search_state);

  // Disable rectangular partitions for inner blocks when the current block is
  // forced to only use square partitions.
  if (bsize > cpi->sf.part_sf.use_square_partition_only_threshold) {
    part_search_state.partition_rect_allowed[HORZ] &= !blk_params.has_rows;
    part_search_state.partition_rect_allowed[VERT] &= !blk_params.has_cols;
  }

#ifndef NDEBUG
  // Nothing should rely on the default value of this array (which is just
  // leftover from encoding the previous block. Setting it to fixed pattern
  // when debugging.
  // bit 0, 1, 2 are blk_skip of each plane
  // bit 4, 5, 6 are initialization checking of each plane
  memset(x->txfm_search_info.blk_skip, 0x77,
         sizeof(x->txfm_search_info.blk_skip));
#endif  // NDEBUG

  assert(mi_size_wide[bsize] == mi_size_high[bsize]);

  // Set buffers and offsets.
  set_offsets(cpi, tile_info, x, mi_row, mi_col, bsize);

  // Save rdmult before it might be changed, so it can be restored later.
  const int orig_rdmult = x->rdmult;
  setup_block_rdmult(cpi, x, mi_row, mi_col, bsize, NO_AQ, NULL);

  // Update rd cost of the bound using the current multiplier.
  av1_rd_cost_update(x->rdmult, &best_rdc);

  if (bsize == BLOCK_16X16 && cpi->vaq_refresh)
    x->mb_energy = av1_log_block_var(cpi, x, bsize);

  // Set the context.
  xd->above_txfm_context =
      cm->above_contexts.txfm[tile_info->tile_row] + mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);
  save_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);

  int *partition_horz_allowed = &part_search_state.partition_rect_allowed[HORZ];
  int *partition_vert_allowed = &part_search_state.partition_rect_allowed[VERT];
  int *prune_horz = &part_search_state.prune_rect_part[HORZ];
  int *prune_vert = &part_search_state.prune_rect_part[VERT];
  // Pruning: before searching any partition type, using source and simple
  // motion search results to prune out unlikely partitions.
  av1_prune_partitions_before_search(
      cpi, x, mi_row, mi_col, bsize, sms_tree,
      &part_search_state.partition_none_allowed, partition_horz_allowed,
      partition_vert_allowed, &part_search_state.do_rectangular_split,
      &part_search_state.do_square_split, prune_horz, prune_vert);

  // Pruning: eliminating partition types leading to coding block sizes outside
  // the min and max bsize limitations set from the encoder.
  av1_prune_partitions_by_max_min_bsize(
      &x->sb_enc, bsize, blk_params.has_rows && blk_params.has_cols,
      &part_search_state.partition_none_allowed, partition_horz_allowed,
      partition_vert_allowed, &part_search_state.do_square_split);

  // Partition search
BEGIN_PARTITION_SEARCH:
  // If a valid partition is required, usually when the first round cannot find
  // a valid one under the cost limit after pruning, reset the limitations on
  // partition types.
  if (x->must_find_valid_partition)
    reset_part_limitations(cpi, &part_search_state);

  // Partition block source pixel variance.
  unsigned int pb_source_variance = UINT_MAX;

  // Partition block sse after simple motion compensation, not in use now,
  // but will be used for upcoming speed features.
  unsigned int pb_simple_motion_pred_sse = UINT_MAX;
  (void)pb_simple_motion_pred_sse;

  // PARTITION_NONE
  if (pc_tree->none == NULL)
    pc_tree->none = av1_alloc_pmc(cm, bsize, &td->shared_coeff_buf);
  PICK_MODE_CONTEXT *ctx_none = pc_tree->none;
  if ((blk_params.width <= blk_params.min_partition_size_1d) &&
      blk_params.has_rows && blk_params.has_cols)
    part_search_state.partition_none_allowed = 1;
  assert(part_search_state.terminate_partition_search == 0);
  int64_t part_none_rd = INT64_MAX;
  if (cpi->is_screen_content_type)
    part_search_state.partition_none_allowed =
        blk_params.has_rows && blk_params.has_cols;
  if (part_search_state.partition_none_allowed) {
    int pt_cost = 0;
    if (blk_params.bsize_at_least_8x8) {
      pt_cost = part_search_state.partition_cost[PARTITION_NONE] < INT_MAX
                    ? part_search_state.partition_cost[PARTITION_NONE]
                    : 0;
    }
    RD_STATS partition_rdcost;
    av1_init_rd_stats(&partition_rdcost);
    partition_rdcost.rate = pt_cost;
    av1_rd_cost_update(x->rdmult, &partition_rdcost);
    RD_STATS best_remain_rdcost;
    av1_rd_stats_subtraction(x->rdmult, &best_rdc, &partition_rdcost,
                             &best_remain_rdcost);
#if CONFIG_COLLECT_PARTITION_STATS
    if (best_remain_rdcost >= 0) {
      partition_attempts[PARTITION_NONE] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
#endif
    pick_sb_modes(cpi, tile_data, x, mi_row, mi_col,
                  &part_search_state.this_rdc, PARTITION_NONE, bsize, ctx_none,
                  best_remain_rdcost, PICK_MODE_RD);
    av1_rd_cost_update(x->rdmult, &part_search_state.this_rdc);
#if CONFIG_COLLECT_PARTITION_STATS
    if (partition_timer_on) {
      aom_usec_timer_mark(&partition_timer);
      int64_t time = aom_usec_timer_elapsed(&partition_timer);
      partition_times[PARTITION_NONE] += time;
      partition_timer_on = 0;
    }
#endif
    pb_source_variance = x->source_variance;
    pb_simple_motion_pred_sse = x->simple_motion_pred_sse;
    if (none_rd) *none_rd = part_search_state.this_rdc.rdcost;
    part_search_state.none_rd = part_search_state.this_rdc.rdcost;
    if (part_search_state.this_rdc.rate != INT_MAX) {
      // Record picked ref frame to prune ref frames for other partition types.
      if (cpi->sf.inter_sf.prune_ref_frame_for_rect_partitions) {
        const int ref_type = av1_ref_frame_type(ctx_none->mic.ref_frame);
        update_picked_ref_frames_mask(x, ref_type, bsize,
                                      cm->seq_params.mib_size, mi_row, mi_col);
      }

      // Calculate the total cost and update the best partition.
      if (blk_params.bsize_at_least_8x8) {
        part_search_state.this_rdc.rate += pt_cost;
        part_search_state.this_rdc.rdcost =
            RDCOST(x->rdmult, part_search_state.this_rdc.rate,
                   part_search_state.this_rdc.dist);
      }
      part_none_rd = part_search_state.this_rdc.rdcost;
      if (part_search_state.this_rdc.rdcost < best_rdc.rdcost) {
        // Adjust dist breakout threshold according to the partition size.
        const int64_t dist_breakout_thr =
            cpi->sf.part_sf.partition_search_breakout_dist_thr >>
            ((2 * (MAX_SB_SIZE_LOG2 - 2)) -
             (mi_size_wide_log2[bsize] + mi_size_high_log2[bsize]));
        const int rate_breakout_thr =
            cpi->sf.part_sf.partition_search_breakout_rate_thr *
            num_pels_log2_lookup[bsize];

        best_rdc = part_search_state.this_rdc;
        part_search_state.found_best_partition = true;
        if (blk_params.bsize_at_least_8x8) {
          pc_tree->partitioning = PARTITION_NONE;
        }

        // Early termination: if the rd cost is very low, early terminate at
        // PARTITION_NONE and skip all other partitions.
        if (!frame_is_intra_only(cm) &&
            (part_search_state.do_square_split ||
             part_search_state.do_rectangular_split) &&
            !x->e_mbd.lossless[xd->mi[0]->segment_id] && ctx_none->skippable) {
          const int use_ml_based_breakout =
              bsize <= cpi->sf.part_sf.use_square_partition_only_threshold &&
              bsize > BLOCK_4X4 && xd->bd == 8;
          if (use_ml_based_breakout) {
            if (av1_ml_predict_breakout(cpi, bsize, x,
                                        &part_search_state.this_rdc,
                                        pb_source_variance)) {
              part_search_state.do_square_split = 0;
              part_search_state.do_rectangular_split = 0;
            }
          }

          // If all y, u, v transform blocks in this partition are skippable,
          // and the dist & rate are within the thresholds, the partition
          // search is terminated for current branch of the partition search
          // tree. The dist & rate thresholds are set to 0 at speed 0 to
          // disable the early termination at that speed.
          if (best_rdc.dist < dist_breakout_thr &&
              best_rdc.rate < rate_breakout_thr) {
            part_search_state.do_square_split = 0;
            part_search_state.do_rectangular_split = 0;
          }
        }

        // Early termination: using simple_motion_search features and the
        // rate, distortion, and rdcost of PARTITION_NONE, a DNN will make a
        // decision on early terminating at PARTITION_NONE.
        if (cpi->sf.part_sf.simple_motion_search_early_term_none &&
            cm->show_frame && !frame_is_intra_only(cm) &&
            bsize >= BLOCK_16X16 &&
            blk_params.mi_row_edge < mi_params->mi_rows &&
            blk_params.mi_col_edge < mi_params->mi_cols &&
            part_search_state.this_rdc.rdcost < INT64_MAX &&
            part_search_state.this_rdc.rdcost >= 0 &&
            part_search_state.this_rdc.rate < INT_MAX &&
            part_search_state.this_rdc.rate >= 0 &&
            (part_search_state.do_square_split ||
             part_search_state.do_rectangular_split)) {
          av1_simple_motion_search_early_term_none(
              cpi, x, sms_tree, mi_row, mi_col, bsize,
              &part_search_state.this_rdc,
              &part_search_state.terminate_partition_search);
        }
      }
    }

    restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
  }

  // PARTITION_SPLIT
  int64_t part_split_rd = INT64_MAX;
  blk_params.subsize = get_partition_subsize(bsize, PARTITION_SPLIT);
  if ((!part_search_state.terminate_partition_search &&
       part_search_state.do_square_split)) {
    for (int i = 0; i < 4; ++i) {
      if (pc_tree->split[i] == NULL)
        pc_tree->split[i] = av1_alloc_pc_tree_node(blk_params.subsize);
      pc_tree->split[i]->index = i;
    }
    av1_init_rd_stats(&part_search_state.sum_rdc);
    part_search_state.sum_rdc.rate =
        part_search_state.partition_cost[PARTITION_SPLIT];
    part_search_state.sum_rdc.rdcost =
        RDCOST(x->rdmult, part_search_state.sum_rdc.rate, 0);

    int idx;
#if CONFIG_COLLECT_PARTITION_STATS
    if (best_rdc.rdcost - part_search_state.sum_rdc.rdcost >= 0) {
      partition_attempts[PARTITION_SPLIT] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
#endif
    // Recursive partition search on 4 sub-blocks.
    for (idx = 0; idx < 4 && part_search_state.sum_rdc.rdcost < best_rdc.rdcost;
         ++idx) {
      const int x_idx = (idx & 1) * blk_params.mi_step;
      const int y_idx = (idx >> 1) * blk_params.mi_step;

      if (mi_row + y_idx >= mi_params->mi_rows ||
          mi_col + x_idx >= mi_params->mi_cols)
        continue;

      pc_tree->split[idx]->index = idx;
      int64_t *p_split_rd = &part_search_state.split_rd[idx];

      RD_STATS best_remain_rdcost;
      av1_rd_stats_subtraction(x->rdmult, &best_rdc, &part_search_state.sum_rdc,
                               &best_remain_rdcost);

      int curr_quad_tree_idx = 0;
      if (frame_is_intra_only(cm) && bsize <= BLOCK_64X64) {
        curr_quad_tree_idx = part_search_state.intra_part_info->quad_tree_idx;
        part_search_state.intra_part_info->quad_tree_idx =
            4 * curr_quad_tree_idx + idx + 1;
      }
      if (!rd_pick_partition(cpi, td, tile_data, tp, mi_row + y_idx,
                             mi_col + x_idx, blk_params.subsize,
                             &part_search_state.this_rdc, best_remain_rdcost,
                             pc_tree->split[idx], sms_tree->split[idx],
                             p_split_rd, multi_pass_mode,
                             &part_search_state.split_part_rect_win[idx])) {
        av1_invalid_rd_stats(&part_search_state.sum_rdc);
        break;
      }
      if (frame_is_intra_only(cm) && bsize <= BLOCK_64X64) {
        part_search_state.intra_part_info->quad_tree_idx = curr_quad_tree_idx;
      }

      part_search_state.sum_rdc.rate += part_search_state.this_rdc.rate;
      part_search_state.sum_rdc.dist += part_search_state.this_rdc.dist;
      av1_rd_cost_update(x->rdmult, &part_search_state.sum_rdc);
      if (idx <= 1 && (bsize <= BLOCK_8X8 ||
                       pc_tree->split[idx]->partitioning == PARTITION_NONE)) {
        const MB_MODE_INFO *const mbmi = &pc_tree->split[idx]->none->mic;
        const PALETTE_MODE_INFO *const pmi = &mbmi->palette_mode_info;
        // Neither palette mode nor cfl predicted.
        if (pmi->palette_size[0] == 0 && pmi->palette_size[1] == 0) {
          if (mbmi->uv_mode != UV_CFL_PRED)
            part_search_state.is_split_ctx_is_ready[idx] = 1;
        }
      }
    }
#if CONFIG_COLLECT_PARTITION_STATS
    if (partition_timer_on) {
      aom_usec_timer_mark(&partition_timer);
      int64_t time = aom_usec_timer_elapsed(&partition_timer);
      partition_times[PARTITION_SPLIT] += time;
      partition_timer_on = 0;
    }
#endif
    const int reached_last_index = (idx == 4);

    // Calculate the total cost and update the best partition.
    part_split_rd = part_search_state.sum_rdc.rdcost;
    if (reached_last_index &&
        part_search_state.sum_rdc.rdcost < best_rdc.rdcost) {
      part_search_state.sum_rdc.rdcost =
          RDCOST(x->rdmult, part_search_state.sum_rdc.rate,
                 part_search_state.sum_rdc.dist);
      if (part_search_state.sum_rdc.rdcost < best_rdc.rdcost) {
        best_rdc = part_search_state.sum_rdc;
        part_search_state.found_best_partition = true;
        pc_tree->partitioning = PARTITION_SPLIT;
      }
    } else if (cpi->sf.part_sf.less_rectangular_check_level > 0) {
      // Skip rectangular partition test when partition type none gives better
      // rd than partition type split.
      if (cpi->sf.part_sf.less_rectangular_check_level == 2 || idx <= 2) {
        const int partition_none_valid = part_search_state.none_rd > 0;
        const int partition_none_better =
            part_search_state.none_rd < part_search_state.sum_rdc.rdcost;
        part_search_state.do_rectangular_split &=
            !(partition_none_valid && partition_none_better);
      }
    }

    restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
  }  // if (do_split)

  // Early termination: using the rd costs of PARTITION_NONE and subblocks
  // from PARTITION_SPLIT to determine an early breakout.
  if (cpi->sf.part_sf.ml_early_term_after_part_split_level &&
      !frame_is_intra_only(cm) &&
      !part_search_state.terminate_partition_search &&
      part_search_state.do_rectangular_split &&
      (part_search_state.partition_rect_allowed[HORZ] ||
       part_search_state.partition_rect_allowed[VERT])) {
    av1_ml_early_term_after_split(
        cpi, x, sms_tree, bsize, best_rdc.rdcost, part_none_rd, part_split_rd,
        part_search_state.split_rd, mi_row, mi_col,
        &part_search_state.terminate_partition_search);
  }

  // Pruning: using the rd costs of PARTITION_NONE and subblocks from
  // PARTITION_SPLIT to prune out rectangular partitions in some directions.
  if (!cpi->sf.part_sf.ml_early_term_after_part_split_level &&
      cpi->sf.part_sf.ml_prune_rect_partition && !frame_is_intra_only(cm) &&
      (part_search_state.partition_rect_allowed[HORZ] ||
       part_search_state.partition_rect_allowed[VERT]) &&
      !(part_search_state.prune_rect_part[HORZ] ||
        part_search_state.prune_rect_part[VERT]) &&
      !part_search_state.terminate_partition_search) {
    av1_setup_src_planes(x, cpi->source, mi_row, mi_col, num_planes, bsize);
    av1_ml_prune_rect_partition(
        cpi, x, bsize, best_rdc.rdcost, part_search_state.none_rd,
        part_search_state.split_rd, prune_horz, prune_vert);
  }

  // Rectangular partitions search stage.
  rectangular_partition_search(cpi, td, tile_data, tp, x, pc_tree, &x_ctx,
                               &part_search_state, &best_rdc,
                               rect_part_win_info);

  if (pb_source_variance == UINT_MAX) {
    av1_setup_src_planes(x, cpi->source, mi_row, mi_col, num_planes, bsize);
    if (is_cur_buf_hbd(xd)) {
      pb_source_variance = av1_high_get_sby_perpixel_variance(
          cpi, &x->plane[0].src, bsize, xd->bd);
    } else {
      pb_source_variance =
          av1_get_sby_perpixel_variance(cpi, &x->plane[0].src, bsize);
    }
  }

  // Update prediction errors from simple motion search.
  if (use_pb_simple_motion_pred_sse(cpi) &&
      pb_simple_motion_pred_sse == UINT_MAX) {
    const FULLPEL_MV start_mv = kZeroFullMv;
    unsigned int var = 0;

    av1_simple_motion_sse_var(cpi, x, mi_row, mi_col, bsize, start_mv, 0,
                              &pb_simple_motion_pred_sse, &var);
  }

  assert(IMPLIES(!part_cfg->enable_rect_partitions,
                 !part_search_state.do_rectangular_split));

  const int ext_partition_allowed =
      part_search_state.do_rectangular_split &&
      bsize > cpi->sf.part_sf.ext_partition_eval_thresh &&
      blk_params.has_rows && blk_params.has_cols;

  // AB partitions search stage.
  ab_partitions_search(cpi, td, tile_data, tp, x, &x_ctx, pc_tree,
                       &part_search_state, &best_rdc, rect_part_win_info,
                       pb_source_variance, ext_partition_allowed);

  // partition4_allowed is 1 if we can use a PARTITION_HORZ_4 or
  // PARTITION_VERT_4 for this block. This is almost the same as
  // ext_partition_allowed, except that we don't allow 128x32 or 32x128
  // blocks, so we require that bsize is not BLOCK_128X128.
  const int partition4_allowed = part_cfg->enable_1to4_partitions &&
                                 ext_partition_allowed &&
                                 bsize != BLOCK_128X128;

  int partition_horz4_allowed =
      partition4_allowed && part_search_state.partition_rect_allowed[HORZ] &&
      get_plane_block_size(get_partition_subsize(bsize, PARTITION_HORZ_4),
                           part_search_state.ss_x,
                           part_search_state.ss_y) != BLOCK_INVALID;
  int partition_vert4_allowed =
      partition4_allowed && part_search_state.partition_rect_allowed[VERT] &&
      get_plane_block_size(get_partition_subsize(bsize, PARTITION_VERT_4),
                           part_search_state.ss_x,
                           part_search_state.ss_y) != BLOCK_INVALID;

  // Pruning: pruning out 4-way partitions based on the current best partition.
  if (cpi->sf.part_sf.prune_ext_partition_types_search_level == 2) {
    partition_horz4_allowed &= (pc_tree->partitioning == PARTITION_HORZ ||
                                pc_tree->partitioning == PARTITION_HORZ_A ||
                                pc_tree->partitioning == PARTITION_HORZ_B ||
                                pc_tree->partitioning == PARTITION_SPLIT ||
                                pc_tree->partitioning == PARTITION_NONE);
    partition_vert4_allowed &= (pc_tree->partitioning == PARTITION_VERT ||
                                pc_tree->partitioning == PARTITION_VERT_A ||
                                pc_tree->partitioning == PARTITION_VERT_B ||
                                pc_tree->partitioning == PARTITION_SPLIT ||
                                pc_tree->partitioning == PARTITION_NONE);
  }

  // Pruning: pruning out some 4-way partitions using a DNN taking rd costs of
  // sub-blocks from basic partition types.
  if (cpi->sf.part_sf.ml_prune_4_partition && partition4_allowed &&
      part_search_state.partition_rect_allowed[HORZ] &&
      part_search_state.partition_rect_allowed[VERT]) {
    av1_ml_prune_4_partition(cpi, x, bsize, pc_tree->partitioning,
                             best_rdc.rdcost, part_search_state.rect_part_rd,
                             part_search_state.split_rd,
                             &partition_horz4_allowed, &partition_vert4_allowed,
                             pb_source_variance, mi_row, mi_col);
  }

  if (blk_params.width < (blk_params.min_partition_size_1d << 2)) {
    partition_horz4_allowed = 0;
    partition_vert4_allowed = 0;
  }

  // Pruning: pruning out 4-way partitions based on the number of horz/vert wins
  // in the current block and sub-blocks in PARTITION_SPLIT.
  if (cpi->sf.part_sf.prune_4_partition_using_split_info &&
      (partition_horz4_allowed || partition_vert4_allowed)) {
    // Count of child blocks in which HORZ or VERT partition has won
    int num_child_horz_win = 0, num_child_vert_win = 0;
    for (int idx = 0; idx < 4; idx++) {
      num_child_horz_win +=
          (part_search_state.split_part_rect_win[idx].rect_part_win[HORZ]) ? 1
                                                                           : 0;
      num_child_vert_win +=
          (part_search_state.split_part_rect_win[idx].rect_part_win[VERT]) ? 1
                                                                           : 0;
    }

    // Prune HORZ4/VERT4 partitions based on number of HORZ/VERT winners of
    // split partiitons.
    // Conservative pruning for high quantizers.
    const int num_win_thresh = AOMMIN(3 * (MAXQ - x->qindex) / MAXQ + 1, 3);
    if (num_child_horz_win < num_win_thresh) {
      partition_horz4_allowed = 0;
    }
    if (num_child_vert_win < num_win_thresh) {
      partition_vert4_allowed = 0;
    }
  }

  // PARTITION_HORZ_4
  assert(IMPLIES(!part_cfg->enable_rect_partitions, !partition_horz4_allowed));
  if (!part_search_state.terminate_partition_search &&
      partition_horz4_allowed && blk_params.has_rows &&
      (part_search_state.do_rectangular_split ||
       active_h_edge(cpi, mi_row, blk_params.mi_step))) {
    av1_init_rd_stats(&part_search_state.sum_rdc);
    const int quarter_step = mi_size_high[bsize] / 4;

    blk_params.subsize = get_partition_subsize(bsize, PARTITION_HORZ_4);
    part_search_state.sum_rdc.rate =
        part_search_state.partition_cost[PARTITION_HORZ_4];
    part_search_state.sum_rdc.rdcost =
        RDCOST(x->rdmult, part_search_state.sum_rdc.rate, 0);

    for (int i = 0; i < 4; ++i) {
      pc_tree->horizontal4[i] =
          av1_alloc_pmc(cm, blk_params.subsize, &td->shared_coeff_buf);
    }

#if CONFIG_COLLECT_PARTITION_STATS
    if (best_rdc.rdcost - part_search_state.sum_rdc.rdcost >= 0) {
      partition_attempts[PARTITION_HORZ_4] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
#endif
    for (int i = 0; i < 4; ++i) {
      const int this_mi_row = mi_row + i * quarter_step;

      if (i > 0 && this_mi_row >= mi_params->mi_rows) break;

      PICK_MODE_CONTEXT *ctx_this = pc_tree->horizontal4[i];

      ctx_this->rd_mode_is_ready = 0;
      if (!rd_try_subblock(cpi, td, tile_data, tp, (i == 3), this_mi_row,
                           mi_col, blk_params.subsize, best_rdc,
                           &part_search_state.sum_rdc, PARTITION_HORZ_4,
                           ctx_this)) {
        av1_invalid_rd_stats(&part_search_state.sum_rdc);
        break;
      }
    }

    // Calculate the total cost and update the best partition.
    av1_rd_cost_update(x->rdmult, &part_search_state.sum_rdc);
    if (part_search_state.sum_rdc.rdcost < best_rdc.rdcost) {
      best_rdc = part_search_state.sum_rdc;
      part_search_state.found_best_partition = true;
      pc_tree->partitioning = PARTITION_HORZ_4;
    }

#if CONFIG_COLLECT_PARTITION_STATS
    if (partition_timer_on) {
      aom_usec_timer_mark(&partition_timer);
      int64_t time = aom_usec_timer_elapsed(&partition_timer);
      partition_times[PARTITION_HORZ_4] += time;
      partition_timer_on = 0;
    }
#endif
    restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
  }

  // PARTITION_VERT_4
  assert(IMPLIES(!part_cfg->enable_rect_partitions, !partition_vert4_allowed));
  if (!part_search_state.terminate_partition_search &&
      partition_vert4_allowed && blk_params.has_cols &&
      (part_search_state.do_rectangular_split ||
       active_v_edge(cpi, mi_row, blk_params.mi_step))) {
    av1_init_rd_stats(&part_search_state.sum_rdc);
    const int quarter_step = mi_size_wide[bsize] / 4;

    blk_params.subsize = get_partition_subsize(bsize, PARTITION_VERT_4);
    part_search_state.sum_rdc.rate =
        part_search_state.partition_cost[PARTITION_VERT_4];
    part_search_state.sum_rdc.rdcost =
        RDCOST(x->rdmult, part_search_state.sum_rdc.rate, 0);

    for (int i = 0; i < 4; ++i)
      pc_tree->vertical4[i] =
          av1_alloc_pmc(cm, blk_params.subsize, &td->shared_coeff_buf);

#if CONFIG_COLLECT_PARTITION_STATS
    if (best_rdc.rdcost - part_search_state.sum_rdc.rdcost >= 0) {
      partition_attempts[PARTITION_VERT_4] += 1;
      aom_usec_timer_start(&partition_timer);
      partition_timer_on = 1;
    }
#endif
    for (int i = 0; i < 4; ++i) {
      const int this_mi_col = mi_col + i * quarter_step;

      if (i > 0 && this_mi_col >= mi_params->mi_cols) break;

      PICK_MODE_CONTEXT *ctx_this = pc_tree->vertical4[i];

      ctx_this->rd_mode_is_ready = 0;
      if (!rd_try_subblock(cpi, td, tile_data, tp, (i == 3), mi_row,
                           this_mi_col, blk_params.subsize, best_rdc,
                           &part_search_state.sum_rdc, PARTITION_VERT_4,
                           ctx_this)) {
        av1_invalid_rd_stats(&part_search_state.sum_rdc);
        break;
      }
    }

    // Calculate the total cost and update the best partition
    av1_rd_cost_update(x->rdmult, &part_search_state.sum_rdc);
    if (part_search_state.sum_rdc.rdcost < best_rdc.rdcost) {
      best_rdc = part_search_state.sum_rdc;
      part_search_state.found_best_partition = true;
      pc_tree->partitioning = PARTITION_VERT_4;
    }
#if CONFIG_COLLECT_PARTITION_STATS
    if (partition_timer_on) {
      aom_usec_timer_mark(&partition_timer);
      int64_t time = aom_usec_timer_elapsed(&partition_timer);
      partition_times[PARTITION_VERT_4] += time;
      partition_timer_on = 0;
    }
#endif
    restore_context(x, &x_ctx, mi_row, mi_col, bsize, num_planes);
  }

  if (bsize == cm->seq_params.sb_size &&
      !part_search_state.found_best_partition) {
    // Did not find a valid partition, go back and search again, with less
    // constraint on which partition types to search.
    x->must_find_valid_partition = 1;
#if CONFIG_COLLECT_PARTITION_STATS == 2
    part_stats->partition_redo += 1;
#endif
    goto BEGIN_PARTITION_SEARCH;
  }

  // Store the final rd cost
  *rd_cost = best_rdc;

  // Also record the best partition in simple motion data tree because it is
  // necessary for the related speed features.
  sms_tree->partitioning = pc_tree->partitioning;

#if CONFIG_COLLECT_PARTITION_STATS
  if (best_rdc.rate < INT_MAX && best_rdc.dist < INT64_MAX) {
    partition_decisions[pc_tree->partitioning] += 1;
  }
#endif

#if CONFIG_COLLECT_PARTITION_STATS == 1
  // If CONFIG_COLLECT_PARTITION_STATS is 1, then print out the stats for each
  // prediction block.
  FILE *f = fopen("data.csv", "a");
  fprintf(f, "%d,%d,%d,", bsize, cm->show_frame, frame_is_intra_only(cm));
  for (int idx = 0; idx < EXT_PARTITION_TYPES; idx++) {
    fprintf(f, "%d,", partition_decisions[idx]);
  }
  for (int idx = 0; idx < EXT_PARTITION_TYPES; idx++) {
    fprintf(f, "%d,", partition_attempts[idx]);
  }
  for (int idx = 0; idx < EXT_PARTITION_TYPES; idx++) {
    fprintf(f, "%ld,", partition_times[idx]);
  }
  fprintf(f, "\n");
  fclose(f);
#endif

#if CONFIG_COLLECT_PARTITION_STATS == 2
  // If CONFIG_COLLECTION_PARTITION_STATS is 2, then we print out the stats for
  // the whole clip. So we need to pass the information upstream to the encoder.
  const int bsize_idx = av1_get_bsize_idx_for_part_stats(bsize);
  int *agg_attempts = part_stats->partition_attempts[bsize_idx];
  int *agg_decisions = part_stats->partition_decisions[bsize_idx];
  int64_t *agg_times = part_stats->partition_times[bsize_idx];
  for (int idx = 0; idx < EXT_PARTITION_TYPES; idx++) {
    agg_attempts[idx] += partition_attempts[idx];
    agg_decisions[idx] += partition_decisions[idx];
    agg_times[idx] += partition_times[idx];
  }
#endif

  // Reset the PC_TREE deallocation flag.
  int pc_tree_dealloc = 0;

  // If a valid partition is found and reconstruction is required for future
  // sub-blocks in the same group.
  if (part_search_state.found_best_partition && pc_tree->index != 3) {
    if (bsize == cm->seq_params.sb_size) {
      // Encode the superblock.
      const int emit_output = multi_pass_mode != SB_DRY_PASS;
      const RUN_TYPE run_type = emit_output ? OUTPUT_ENABLED : DRY_RUN_NORMAL;

      x->cb_offset = 0;
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, run_type, bsize,
                pc_tree, NULL);
      // Dealloc the whole PC_TREE after a superblock is done.
      av1_free_pc_tree_recursive(pc_tree, num_planes, 0, 0);
      pc_tree_dealloc = 1;
    } else {
      // Encode the smaller blocks in DRY_RUN mode.
      encode_sb(cpi, td, tile_data, tp, mi_row, mi_col, DRY_RUN_NORMAL, bsize,
                pc_tree, NULL);
    }
  }

  // If the tree still exists (non-superblock), dealloc most nodes, only keep
  // nodes for the best partition and PARTITION_NONE.
  if (pc_tree_dealloc == 0)
    av1_free_pc_tree_recursive(pc_tree, num_planes, 1, 1);

  if (bsize == cm->seq_params.sb_size) {
    assert(best_rdc.rate < INT_MAX);
    assert(best_rdc.dist < INT64_MAX);
  } else {
    assert(tp_orig == *tp);
  }

  // Restore the rd multiplier.
  x->rdmult = orig_rdmult;
  return part_search_state.found_best_partition;
}

#endif  // !CONFIG_REALTIME_ONLY
#undef NUM_SIMPLE_MOTION_FEATURES

#if !CONFIG_REALTIME_ONLY

static int get_rdmult_delta(AV1_COMP *cpi, BLOCK_SIZE bsize, int analysis_type,
                            int mi_row, int mi_col, int orig_rdmult) {
  AV1_COMMON *const cm = &cpi->common;
  assert(IMPLIES(cpi->gf_group.size > 0,
                 cpi->gf_group.index < cpi->gf_group.size));
  const int tpl_idx = cpi->gf_group.index;
  TplParams *const tpl_data = &cpi->tpl_data;
  TplDepFrame *tpl_frame = &tpl_data->tpl_frame[tpl_idx];
  TplDepStats *tpl_stats = tpl_frame->tpl_stats_ptr;
  const uint8_t block_mis_log2 = tpl_data->tpl_stats_block_mis_log2;
  int tpl_stride = tpl_frame->stride;
  int64_t intra_cost = 0;
  int64_t mc_dep_cost = 0;
  const int mi_wide = mi_size_wide[bsize];
  const int mi_high = mi_size_high[bsize];

  if (tpl_frame->is_valid == 0) return orig_rdmult;

  if (!is_frame_tpl_eligible(cpi)) return orig_rdmult;

  if (cpi->gf_group.index >= MAX_TPL_FRAME_IDX) return orig_rdmult;

  int64_t mc_count = 0, mc_saved = 0;
  int mi_count = 0;
  const int mi_col_sr =
      coded_to_superres_mi(mi_col, cm->superres_scale_denominator);
  const int mi_col_end_sr =
      coded_to_superres_mi(mi_col + mi_wide, cm->superres_scale_denominator);
  const int mi_cols_sr = av1_pixels_to_mi(cm->superres_upscaled_width);
  const int step = 1 << block_mis_log2;
  for (int row = mi_row; row < mi_row + mi_high; row += step) {
    for (int col = mi_col_sr; col < mi_col_end_sr; col += step) {
      if (row >= cm->mi_params.mi_rows || col >= mi_cols_sr) continue;
      TplDepStats *this_stats =
          &tpl_stats[av1_tpl_ptr_pos(row, col, tpl_stride, block_mis_log2)];
      int64_t mc_dep_delta =
          RDCOST(tpl_frame->base_rdmult, this_stats->mc_dep_rate,
                 this_stats->mc_dep_dist);
      intra_cost += this_stats->recrf_dist << RDDIV_BITS;
      mc_dep_cost += (this_stats->recrf_dist << RDDIV_BITS) + mc_dep_delta;
      mc_count += this_stats->mc_count;
      mc_saved += this_stats->mc_saved;
      mi_count++;
    }
  }

  aom_clear_system_state();

  double beta = 1.0;
  if (analysis_type == 0) {
    if (mc_dep_cost > 0 && intra_cost > 0) {
      const double r0 = cpi->rd.r0;
      const double rk = (double)intra_cost / mc_dep_cost;
      beta = (r0 / rk);
    }
  } else if (analysis_type == 1) {
    const double mc_count_base = (mi_count * cpi->rd.mc_count_base);
    beta = (mc_count + 1.0) / (mc_count_base + 1.0);
    beta = pow(beta, 0.5);
  } else if (analysis_type == 2) {
    const double mc_saved_base = (mi_count * cpi->rd.mc_saved_base);
    beta = (mc_saved + 1.0) / (mc_saved_base + 1.0);
    beta = pow(beta, 0.5);
  }

  int rdmult = av1_get_adaptive_rdmult(cpi, beta);

  aom_clear_system_state();

  rdmult = AOMMIN(rdmult, orig_rdmult * 3 / 2);
  rdmult = AOMMAX(rdmult, orig_rdmult * 1 / 2);

  rdmult = AOMMAX(1, rdmult);

  return rdmult;
}

static void get_tpl_stats_sb(AV1_COMP *cpi, BLOCK_SIZE bsize, int mi_row,
                             int mi_col, SuperBlockEnc *sb_enc) {
  sb_enc->tpl_data_count = 0;

  if (!cpi->oxcf.enable_tpl_model) return;
  if (cpi->superres_mode != AOM_SUPERRES_NONE) return;
  if (cpi->common.current_frame.frame_type == KEY_FRAME) return;
  const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);
  if (update_type == INTNL_OVERLAY_UPDATE || update_type == OVERLAY_UPDATE)
    return;
  assert(IMPLIES(cpi->gf_group.size > 0,
                 cpi->gf_group.index < cpi->gf_group.size));

  AV1_COMMON *const cm = &cpi->common;
  const int gf_group_index = cpi->gf_group.index;
  TplParams *const tpl_data = &cpi->tpl_data;
  TplDepFrame *tpl_frame = &tpl_data->tpl_frame[gf_group_index];
  TplDepStats *tpl_stats = tpl_frame->tpl_stats_ptr;
  int tpl_stride = tpl_frame->stride;
  const int mi_wide = mi_size_wide[bsize];
  const int mi_high = mi_size_high[bsize];

  if (tpl_frame->is_valid == 0) return;
  if (gf_group_index >= MAX_TPL_FRAME_IDX) return;

  int mi_count = 0;
  int count = 0;
  const int mi_col_sr =
      coded_to_superres_mi(mi_col, cm->superres_scale_denominator);
  const int mi_col_end_sr =
      coded_to_superres_mi(mi_col + mi_wide, cm->superres_scale_denominator);
  // mi_cols_sr is mi_cols at superres case.
  const int mi_cols_sr = av1_pixels_to_mi(cm->superres_upscaled_width);

  // TPL store unit size is not the same as the motion estimation unit size.
  // Here always use motion estimation size to avoid getting repetitive inter/
  // intra cost.
  const BLOCK_SIZE tpl_bsize = convert_length_to_bsize(MC_FLOW_BSIZE_1D);
  const int step = mi_size_wide[tpl_bsize];
  assert(mi_size_wide[tpl_bsize] == mi_size_high[tpl_bsize]);

  // Stride is only based on SB size, and we fill in values for every 16x16
  // block in a SB.
  sb_enc->tpl_stride = (mi_col_end_sr - mi_col_sr) / step;

  for (int row = mi_row; row < mi_row + mi_high; row += step) {
    for (int col = mi_col_sr; col < mi_col_end_sr; col += step) {
      // Handle partial SB, so that no invalid values are used later.
      if (row >= cm->mi_params.mi_rows || col >= mi_cols_sr) {
        sb_enc->tpl_inter_cost[count] = INT64_MAX;
        sb_enc->tpl_intra_cost[count] = INT64_MAX;
        for (int i = 0; i < INTER_REFS_PER_FRAME; ++i) {
          sb_enc->tpl_mv[count][i].as_int = INVALID_MV;
        }
        count++;
        continue;
      }

      TplDepStats *this_stats = &tpl_stats[av1_tpl_ptr_pos(
          row, col, tpl_stride, tpl_data->tpl_stats_block_mis_log2)];
      sb_enc->tpl_inter_cost[count] = this_stats->inter_cost;
      sb_enc->tpl_intra_cost[count] = this_stats->intra_cost;
      memcpy(sb_enc->tpl_mv[count], this_stats->mv, sizeof(this_stats->mv));
      mi_count++;
      count++;
    }
  }

  sb_enc->tpl_data_count = mi_count;
}

// analysis_type 0: Use mc_dep_cost and intra_cost
// analysis_type 1: Use count of best inter predictor chosen
// analysis_type 2: Use cost reduction from intra to inter for best inter
//                  predictor chosen
static int get_q_for_deltaq_objective(AV1_COMP *const cpi, BLOCK_SIZE bsize,
                                      int mi_row, int mi_col) {
  AV1_COMMON *const cm = &cpi->common;
  assert(IMPLIES(cpi->gf_group.size > 0,
                 cpi->gf_group.index < cpi->gf_group.size));
  const int tpl_idx = cpi->gf_group.index;
  TplParams *const tpl_data = &cpi->tpl_data;
  TplDepFrame *tpl_frame = &tpl_data->tpl_frame[tpl_idx];
  TplDepStats *tpl_stats = tpl_frame->tpl_stats_ptr;
  const uint8_t block_mis_log2 = tpl_data->tpl_stats_block_mis_log2;
  int tpl_stride = tpl_frame->stride;
  int64_t intra_cost = 0;
  int64_t mc_dep_cost = 0;
  const int mi_wide = mi_size_wide[bsize];
  const int mi_high = mi_size_high[bsize];
  const int base_qindex = cm->quant_params.base_qindex;

  if (tpl_frame->is_valid == 0) return base_qindex;

  if (!is_frame_tpl_eligible(cpi)) return base_qindex;

  if (cpi->gf_group.index >= MAX_TPL_FRAME_IDX) return base_qindex;

  int64_t mc_count = 0, mc_saved = 0;
  int mi_count = 0;
  const int mi_col_sr =
      coded_to_superres_mi(mi_col, cm->superres_scale_denominator);
  const int mi_col_end_sr =
      coded_to_superres_mi(mi_col + mi_wide, cm->superres_scale_denominator);
  const int mi_cols_sr = av1_pixels_to_mi(cm->superres_upscaled_width);
  const int step = 1 << block_mis_log2;
  for (int row = mi_row; row < mi_row + mi_high; row += step) {
    for (int col = mi_col_sr; col < mi_col_end_sr; col += step) {
      if (row >= cm->mi_params.mi_rows || col >= mi_cols_sr) continue;
      TplDepStats *this_stats =
          &tpl_stats[av1_tpl_ptr_pos(row, col, tpl_stride, block_mis_log2)];
      int64_t mc_dep_delta =
          RDCOST(tpl_frame->base_rdmult, this_stats->mc_dep_rate,
                 this_stats->mc_dep_dist);
      intra_cost += this_stats->recrf_dist << RDDIV_BITS;
      mc_dep_cost += (this_stats->recrf_dist << RDDIV_BITS) + mc_dep_delta;
      mc_count += this_stats->mc_count;
      mc_saved += this_stats->mc_saved;
      mi_count++;
    }
  }

  aom_clear_system_state();

  int offset = 0;
  double beta = 1.0;
  if (mc_dep_cost > 0 && intra_cost > 0) {
    const double r0 = cpi->rd.r0;
    const double rk = (double)intra_cost / mc_dep_cost;
    beta = (r0 / rk);
    assert(beta > 0.0);
  }
  offset = av1_get_deltaq_offset(cpi, base_qindex, beta);
  aom_clear_system_state();

  const DeltaQInfo *const delta_q_info = &cm->delta_q_info;
  offset = AOMMIN(offset, delta_q_info->delta_q_res * 9 - 1);
  offset = AOMMAX(offset, -delta_q_info->delta_q_res * 9 + 1);
  int qindex = cm->quant_params.base_qindex + offset;
  qindex = AOMMIN(qindex, MAXQ);
  qindex = AOMMAX(qindex, MINQ);

  return qindex;
}

static AOM_INLINE void setup_delta_q(AV1_COMP *const cpi, ThreadData *td,
                                     MACROBLOCK *const x,
                                     const TileInfo *const tile_info,
                                     int mi_row, int mi_col, int num_planes) {
  AV1_COMMON *const cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  const DeltaQInfo *const delta_q_info = &cm->delta_q_info;
  assert(delta_q_info->delta_q_present_flag);

  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;
  // Delta-q modulation based on variance
  av1_setup_src_planes(x, cpi->source, mi_row, mi_col, num_planes, sb_size);

  int current_qindex = cm->quant_params.base_qindex;
  if (cpi->oxcf.deltaq_mode == DELTA_Q_PERCEPTUAL) {
    if (DELTA_Q_PERCEPTUAL_MODULATION == 1) {
      const int block_wavelet_energy_level =
          av1_block_wavelet_energy_level(cpi, x, sb_size);
      x->sb_energy_level = block_wavelet_energy_level;
      current_qindex = av1_compute_q_from_energy_level_deltaq_mode(
          cpi, block_wavelet_energy_level);
    } else {
      const int block_var_level = av1_log_block_var(cpi, x, sb_size);
      x->sb_energy_level = block_var_level;
      current_qindex =
          av1_compute_q_from_energy_level_deltaq_mode(cpi, block_var_level);
    }
  } else if (cpi->oxcf.deltaq_mode == DELTA_Q_OBJECTIVE &&
             cpi->oxcf.enable_tpl_model) {
    // Setup deltaq based on tpl stats
    current_qindex = get_q_for_deltaq_objective(cpi, sb_size, mi_row, mi_col);
  }

  const int delta_q_res = delta_q_info->delta_q_res;
  // Right now aq only works with tpl model. So if tpl is disabled, we set the
  // current_qindex to base_qindex.
  if (cpi->oxcf.enable_tpl_model && cpi->oxcf.deltaq_mode != NO_DELTA_Q) {
    current_qindex =
        clamp(current_qindex, delta_q_res, 256 - delta_q_info->delta_q_res);
  } else {
    current_qindex = cm->quant_params.base_qindex;
  }

  MACROBLOCKD *const xd = &x->e_mbd;
  const int sign_deltaq_index =
      current_qindex - xd->current_base_qindex >= 0 ? 1 : -1;
  const int deltaq_deadzone = delta_q_res / 4;
  const int qmask = ~(delta_q_res - 1);
  int abs_deltaq_index = abs(current_qindex - xd->current_base_qindex);
  abs_deltaq_index = (abs_deltaq_index + deltaq_deadzone) & qmask;
  current_qindex =
      xd->current_base_qindex + sign_deltaq_index * abs_deltaq_index;
  current_qindex = AOMMAX(current_qindex, MINQ + 1);
  assert(current_qindex > 0);

  x->delta_qindex = current_qindex - cm->quant_params.base_qindex;
  set_offsets(cpi, tile_info, x, mi_row, mi_col, sb_size);
  xd->mi[0]->current_qindex = current_qindex;
  av1_init_plane_quantizers(cpi, x, xd->mi[0]->segment_id);

  // keep track of any non-zero delta-q used
  td->deltaq_used |= (x->delta_qindex != 0);

  if (cpi->oxcf.deltalf_mode) {
    const int delta_lf_res = delta_q_info->delta_lf_res;
    const int lfmask = ~(delta_lf_res - 1);
    const int delta_lf_from_base =
        ((x->delta_qindex / 2 + delta_lf_res / 2) & lfmask);
    const int8_t delta_lf =
        (int8_t)clamp(delta_lf_from_base, -MAX_LOOP_FILTER, MAX_LOOP_FILTER);
    const int frame_lf_count =
        av1_num_planes(cm) > 1 ? FRAME_LF_COUNT : FRAME_LF_COUNT - 2;
    const int mib_size = cm->seq_params.mib_size;

    // pre-set the delta lf for loop filter. Note that this value is set
    // before mi is assigned for each block in current superblock
    for (int j = 0; j < AOMMIN(mib_size, mi_params->mi_rows - mi_row); j++) {
      for (int k = 0; k < AOMMIN(mib_size, mi_params->mi_cols - mi_col); k++) {
        const int grid_idx = get_mi_grid_idx(mi_params, mi_row + j, mi_col + k);
        mi_params->mi_grid_base[grid_idx]->delta_lf_from_base = delta_lf;
        for (int lf_id = 0; lf_id < frame_lf_count; ++lf_id) {
          mi_params->mi_grid_base[grid_idx]->delta_lf[lf_id] = delta_lf;
        }
      }
    }
  }
}
#endif  // !CONFIG_REALTIME_ONLY

#define AVG_CDF_WEIGHT_LEFT 3
#define AVG_CDF_WEIGHT_TOP_RIGHT 1

static AOM_INLINE void avg_cdf_symbol(aom_cdf_prob *cdf_ptr_left,
                                      aom_cdf_prob *cdf_ptr_tr, int num_cdfs,
                                      int cdf_stride, int nsymbs, int wt_left,
                                      int wt_tr) {
  for (int i = 0; i < num_cdfs; i++) {
    for (int j = 0; j <= nsymbs; j++) {
      cdf_ptr_left[i * cdf_stride + j] =
          (aom_cdf_prob)(((int)cdf_ptr_left[i * cdf_stride + j] * wt_left +
                          (int)cdf_ptr_tr[i * cdf_stride + j] * wt_tr +
                          ((wt_left + wt_tr) / 2)) /
                         (wt_left + wt_tr));
      assert(cdf_ptr_left[i * cdf_stride + j] >= 0 &&
             cdf_ptr_left[i * cdf_stride + j] < CDF_PROB_TOP);
    }
  }
}

#define AVERAGE_CDF(cname_left, cname_tr, nsymbs) \
  AVG_CDF_STRIDE(cname_left, cname_tr, nsymbs, CDF_SIZE(nsymbs))

#define AVG_CDF_STRIDE(cname_left, cname_tr, nsymbs, cdf_stride)           \
  do {                                                                     \
    aom_cdf_prob *cdf_ptr_left = (aom_cdf_prob *)cname_left;               \
    aom_cdf_prob *cdf_ptr_tr = (aom_cdf_prob *)cname_tr;                   \
    int array_size = (int)sizeof(cname_left) / sizeof(aom_cdf_prob);       \
    int num_cdfs = array_size / cdf_stride;                                \
    avg_cdf_symbol(cdf_ptr_left, cdf_ptr_tr, num_cdfs, cdf_stride, nsymbs, \
                   wt_left, wt_tr);                                        \
  } while (0)

static AOM_INLINE void avg_nmv(nmv_context *nmv_left, nmv_context *nmv_tr,
                               int wt_left, int wt_tr) {
  AVERAGE_CDF(nmv_left->joints_cdf, nmv_tr->joints_cdf, 4);
  for (int i = 0; i < 2; i++) {
    AVERAGE_CDF(nmv_left->comps[i].classes_cdf, nmv_tr->comps[i].classes_cdf,
                MV_CLASSES);
    AVERAGE_CDF(nmv_left->comps[i].class0_fp_cdf,
                nmv_tr->comps[i].class0_fp_cdf, MV_FP_SIZE);
    AVERAGE_CDF(nmv_left->comps[i].fp_cdf, nmv_tr->comps[i].fp_cdf, MV_FP_SIZE);
    AVERAGE_CDF(nmv_left->comps[i].sign_cdf, nmv_tr->comps[i].sign_cdf, 2);
    AVERAGE_CDF(nmv_left->comps[i].class0_hp_cdf,
                nmv_tr->comps[i].class0_hp_cdf, 2);
    AVERAGE_CDF(nmv_left->comps[i].hp_cdf, nmv_tr->comps[i].hp_cdf, 2);
    AVERAGE_CDF(nmv_left->comps[i].class0_cdf, nmv_tr->comps[i].class0_cdf,
                CLASS0_SIZE);
    AVERAGE_CDF(nmv_left->comps[i].bits_cdf, nmv_tr->comps[i].bits_cdf, 2);
  }
}

// In case of row-based multi-threading of encoder, since we always
// keep a top - right sync, we can average the top - right SB's CDFs and
// the left SB's CDFs and use the same for current SB's encoding to
// improve the performance. This function facilitates the averaging
// of CDF and used only when row-mt is enabled in encoder.
static AOM_INLINE void avg_cdf_symbols(FRAME_CONTEXT *ctx_left,
                                       FRAME_CONTEXT *ctx_tr, int wt_left,
                                       int wt_tr) {
  AVERAGE_CDF(ctx_left->txb_skip_cdf, ctx_tr->txb_skip_cdf, 2);
  AVERAGE_CDF(ctx_left->eob_extra_cdf, ctx_tr->eob_extra_cdf, 2);
  AVERAGE_CDF(ctx_left->dc_sign_cdf, ctx_tr->dc_sign_cdf, 2);
  AVERAGE_CDF(ctx_left->eob_flag_cdf16, ctx_tr->eob_flag_cdf16, 5);
  AVERAGE_CDF(ctx_left->eob_flag_cdf32, ctx_tr->eob_flag_cdf32, 6);
  AVERAGE_CDF(ctx_left->eob_flag_cdf64, ctx_tr->eob_flag_cdf64, 7);
  AVERAGE_CDF(ctx_left->eob_flag_cdf128, ctx_tr->eob_flag_cdf128, 8);
  AVERAGE_CDF(ctx_left->eob_flag_cdf256, ctx_tr->eob_flag_cdf256, 9);
  AVERAGE_CDF(ctx_left->eob_flag_cdf512, ctx_tr->eob_flag_cdf512, 10);
  AVERAGE_CDF(ctx_left->eob_flag_cdf1024, ctx_tr->eob_flag_cdf1024, 11);
  AVERAGE_CDF(ctx_left->coeff_base_eob_cdf, ctx_tr->coeff_base_eob_cdf, 3);
  AVERAGE_CDF(ctx_left->coeff_base_cdf, ctx_tr->coeff_base_cdf, 4);
  AVERAGE_CDF(ctx_left->coeff_br_cdf, ctx_tr->coeff_br_cdf, BR_CDF_SIZE);
  AVERAGE_CDF(ctx_left->newmv_cdf, ctx_tr->newmv_cdf, 2);
  AVERAGE_CDF(ctx_left->zeromv_cdf, ctx_tr->zeromv_cdf, 2);
  AVERAGE_CDF(ctx_left->refmv_cdf, ctx_tr->refmv_cdf, 2);
  AVERAGE_CDF(ctx_left->drl_cdf, ctx_tr->drl_cdf, 2);
  AVERAGE_CDF(ctx_left->inter_compound_mode_cdf,
              ctx_tr->inter_compound_mode_cdf, INTER_COMPOUND_MODES);
  AVERAGE_CDF(ctx_left->compound_type_cdf, ctx_tr->compound_type_cdf,
              MASKED_COMPOUND_TYPES);
  AVERAGE_CDF(ctx_left->wedge_idx_cdf, ctx_tr->wedge_idx_cdf, 16);
  AVERAGE_CDF(ctx_left->interintra_cdf, ctx_tr->interintra_cdf, 2);
  AVERAGE_CDF(ctx_left->wedge_interintra_cdf, ctx_tr->wedge_interintra_cdf, 2);
  AVERAGE_CDF(ctx_left->interintra_mode_cdf, ctx_tr->interintra_mode_cdf,
              INTERINTRA_MODES);
  AVERAGE_CDF(ctx_left->motion_mode_cdf, ctx_tr->motion_mode_cdf, MOTION_MODES);
  AVERAGE_CDF(ctx_left->obmc_cdf, ctx_tr->obmc_cdf, 2);
  AVERAGE_CDF(ctx_left->palette_y_size_cdf, ctx_tr->palette_y_size_cdf,
              PALETTE_SIZES);
  AVERAGE_CDF(ctx_left->palette_uv_size_cdf, ctx_tr->palette_uv_size_cdf,
              PALETTE_SIZES);
  for (int j = 0; j < PALETTE_SIZES; j++) {
    int nsymbs = j + PALETTE_MIN_SIZE;
    AVG_CDF_STRIDE(ctx_left->palette_y_color_index_cdf[j],
                   ctx_tr->palette_y_color_index_cdf[j], nsymbs,
                   CDF_SIZE(PALETTE_COLORS));
    AVG_CDF_STRIDE(ctx_left->palette_uv_color_index_cdf[j],
                   ctx_tr->palette_uv_color_index_cdf[j], nsymbs,
                   CDF_SIZE(PALETTE_COLORS));
  }
  AVERAGE_CDF(ctx_left->palette_y_mode_cdf, ctx_tr->palette_y_mode_cdf, 2);
  AVERAGE_CDF(ctx_left->palette_uv_mode_cdf, ctx_tr->palette_uv_mode_cdf, 2);
  AVERAGE_CDF(ctx_left->comp_inter_cdf, ctx_tr->comp_inter_cdf, 2);
  AVERAGE_CDF(ctx_left->single_ref_cdf, ctx_tr->single_ref_cdf, 2);
  AVERAGE_CDF(ctx_left->comp_ref_type_cdf, ctx_tr->comp_ref_type_cdf, 2);
  AVERAGE_CDF(ctx_left->uni_comp_ref_cdf, ctx_tr->uni_comp_ref_cdf, 2);
  AVERAGE_CDF(ctx_left->comp_ref_cdf, ctx_tr->comp_ref_cdf, 2);
  AVERAGE_CDF(ctx_left->comp_bwdref_cdf, ctx_tr->comp_bwdref_cdf, 2);
  AVERAGE_CDF(ctx_left->txfm_partition_cdf, ctx_tr->txfm_partition_cdf, 2);
  AVERAGE_CDF(ctx_left->compound_index_cdf, ctx_tr->compound_index_cdf, 2);
  AVERAGE_CDF(ctx_left->comp_group_idx_cdf, ctx_tr->comp_group_idx_cdf, 2);
  AVERAGE_CDF(ctx_left->skip_mode_cdfs, ctx_tr->skip_mode_cdfs, 2);
  AVERAGE_CDF(ctx_left->skip_txfm_cdfs, ctx_tr->skip_txfm_cdfs, 2);
  AVERAGE_CDF(ctx_left->intra_inter_cdf, ctx_tr->intra_inter_cdf, 2);
  avg_nmv(&ctx_left->nmvc, &ctx_tr->nmvc, wt_left, wt_tr);
  avg_nmv(&ctx_left->ndvc, &ctx_tr->ndvc, wt_left, wt_tr);
  AVERAGE_CDF(ctx_left->intrabc_cdf, ctx_tr->intrabc_cdf, 2);
  AVERAGE_CDF(ctx_left->seg.tree_cdf, ctx_tr->seg.tree_cdf, MAX_SEGMENTS);
  AVERAGE_CDF(ctx_left->seg.pred_cdf, ctx_tr->seg.pred_cdf, 2);
  AVERAGE_CDF(ctx_left->seg.spatial_pred_seg_cdf,
              ctx_tr->seg.spatial_pred_seg_cdf, MAX_SEGMENTS);
  AVERAGE_CDF(ctx_left->filter_intra_cdfs, ctx_tr->filter_intra_cdfs, 2);
  AVERAGE_CDF(ctx_left->filter_intra_mode_cdf, ctx_tr->filter_intra_mode_cdf,
              FILTER_INTRA_MODES);
  AVERAGE_CDF(ctx_left->switchable_restore_cdf, ctx_tr->switchable_restore_cdf,
              RESTORE_SWITCHABLE_TYPES);
  AVERAGE_CDF(ctx_left->wiener_restore_cdf, ctx_tr->wiener_restore_cdf, 2);
  AVERAGE_CDF(ctx_left->sgrproj_restore_cdf, ctx_tr->sgrproj_restore_cdf, 2);
  AVERAGE_CDF(ctx_left->y_mode_cdf, ctx_tr->y_mode_cdf, INTRA_MODES);
  AVG_CDF_STRIDE(ctx_left->uv_mode_cdf[0], ctx_tr->uv_mode_cdf[0],
                 UV_INTRA_MODES - 1, CDF_SIZE(UV_INTRA_MODES));
  AVERAGE_CDF(ctx_left->uv_mode_cdf[1], ctx_tr->uv_mode_cdf[1], UV_INTRA_MODES);
  for (int i = 0; i < PARTITION_CONTEXTS; i++) {
    if (i < 4) {
      AVG_CDF_STRIDE(ctx_left->partition_cdf[i], ctx_tr->partition_cdf[i], 4,
                     CDF_SIZE(10));
    } else if (i < 16) {
      AVERAGE_CDF(ctx_left->partition_cdf[i], ctx_tr->partition_cdf[i], 10);
    } else {
      AVG_CDF_STRIDE(ctx_left->partition_cdf[i], ctx_tr->partition_cdf[i], 8,
                     CDF_SIZE(10));
    }
  }
  AVERAGE_CDF(ctx_left->switchable_interp_cdf, ctx_tr->switchable_interp_cdf,
              SWITCHABLE_FILTERS);
  AVERAGE_CDF(ctx_left->kf_y_cdf, ctx_tr->kf_y_cdf, INTRA_MODES);
  AVERAGE_CDF(ctx_left->angle_delta_cdf, ctx_tr->angle_delta_cdf,
              2 * MAX_ANGLE_DELTA + 1);
  AVG_CDF_STRIDE(ctx_left->tx_size_cdf[0], ctx_tr->tx_size_cdf[0], MAX_TX_DEPTH,
                 CDF_SIZE(MAX_TX_DEPTH + 1));
  AVERAGE_CDF(ctx_left->tx_size_cdf[1], ctx_tr->tx_size_cdf[1],
              MAX_TX_DEPTH + 1);
  AVERAGE_CDF(ctx_left->tx_size_cdf[2], ctx_tr->tx_size_cdf[2],
              MAX_TX_DEPTH + 1);
  AVERAGE_CDF(ctx_left->tx_size_cdf[3], ctx_tr->tx_size_cdf[3],
              MAX_TX_DEPTH + 1);
  AVERAGE_CDF(ctx_left->delta_q_cdf, ctx_tr->delta_q_cdf, DELTA_Q_PROBS + 1);
  AVERAGE_CDF(ctx_left->delta_lf_cdf, ctx_tr->delta_lf_cdf, DELTA_LF_PROBS + 1);
  for (int i = 0; i < FRAME_LF_COUNT; i++) {
    AVERAGE_CDF(ctx_left->delta_lf_multi_cdf[i], ctx_tr->delta_lf_multi_cdf[i],
                DELTA_LF_PROBS + 1);
  }
  AVG_CDF_STRIDE(ctx_left->intra_ext_tx_cdf[1], ctx_tr->intra_ext_tx_cdf[1], 7,
                 CDF_SIZE(TX_TYPES));
  AVG_CDF_STRIDE(ctx_left->intra_ext_tx_cdf[2], ctx_tr->intra_ext_tx_cdf[2], 5,
                 CDF_SIZE(TX_TYPES));
  AVG_CDF_STRIDE(ctx_left->inter_ext_tx_cdf[1], ctx_tr->inter_ext_tx_cdf[1], 16,
                 CDF_SIZE(TX_TYPES));
  AVG_CDF_STRIDE(ctx_left->inter_ext_tx_cdf[2], ctx_tr->inter_ext_tx_cdf[2], 12,
                 CDF_SIZE(TX_TYPES));
  AVG_CDF_STRIDE(ctx_left->inter_ext_tx_cdf[3], ctx_tr->inter_ext_tx_cdf[3], 2,
                 CDF_SIZE(TX_TYPES));
  AVERAGE_CDF(ctx_left->cfl_sign_cdf, ctx_tr->cfl_sign_cdf, CFL_JOINT_SIGNS);
  AVERAGE_CDF(ctx_left->cfl_alpha_cdf, ctx_tr->cfl_alpha_cdf,
              CFL_ALPHABET_SIZE);
}

#if !CONFIG_REALTIME_ONLY
static AOM_INLINE void adjust_rdmult_tpl_model(AV1_COMP *cpi, MACROBLOCK *x,
                                               int mi_row, int mi_col) {
  const BLOCK_SIZE sb_size = cpi->common.seq_params.sb_size;
  const int orig_rdmult = cpi->rd.RDMULT;

  assert(IMPLIES(cpi->gf_group.size > 0,
                 cpi->gf_group.index < cpi->gf_group.size));
  const int gf_group_index = cpi->gf_group.index;
  if (cpi->oxcf.enable_tpl_model && cpi->oxcf.aq_mode == NO_AQ &&
      cpi->oxcf.deltaq_mode == NO_DELTA_Q && gf_group_index > 0 &&
      cpi->gf_group.update_type[gf_group_index] == ARF_UPDATE) {
    const int dr =
        get_rdmult_delta(cpi, sb_size, 0, mi_row, mi_col, orig_rdmult);
    x->rdmult = dr;
  }
}
#endif

// Grade the temporal variation of the source by comparing the current sb and
// its collocated block in the last frame.
static void source_content_sb(AV1_COMP *cpi, MACROBLOCK *x, int offset) {
  unsigned int tmp_sse;
  unsigned int tmp_variance;
  const BLOCK_SIZE bsize = cpi->common.seq_params.sb_size;
  uint8_t *src_y = cpi->source->y_buffer;
  int src_ystride = cpi->source->y_stride;
  uint8_t *last_src_y = cpi->last_source->y_buffer;
  int last_src_ystride = cpi->last_source->y_stride;
  uint64_t avg_source_sse_threshold = 100000;        // ~5*5*(64*64)
  uint64_t avg_source_sse_threshold_high = 1000000;  // ~15*15*(64*64)
  uint64_t sum_sq_thresh = 10000;  // sum = sqrt(thresh / 64*64)) ~1.5
#if CONFIG_AV1_HIGHBITDEPTH
  MACROBLOCKD *xd = &x->e_mbd;
  if (xd->cur_buf->flags & YV12_FLAG_HIGHBITDEPTH) return;
#endif
  src_y += offset;
  last_src_y += offset;
  tmp_variance = cpi->fn_ptr[bsize].vf(src_y, src_ystride, last_src_y,
                                       last_src_ystride, &tmp_sse);
  // Note: tmp_sse - tmp_variance = ((sum * sum) >> 12)
  // Detect large lighting change.
  if (tmp_variance < (tmp_sse >> 1) && (tmp_sse - tmp_variance) > sum_sq_thresh)
    x->content_state_sb = kLowVarHighSumdiff;
  else if (tmp_sse < avg_source_sse_threshold)
    x->content_state_sb = kLowSad;
  else if (tmp_sse > avg_source_sse_threshold_high)
    x->content_state_sb = kHighSad;
}

/*!\brief Encode a superblock (minimal RD search involved)
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Encodes the superblock by a pre-determined partition pattern, only minor
 * rd-based searches are allowed to adjust the initial pattern. It is only used
 * by realtime encoding.
 */
static AOM_INLINE void encode_nonrd_sb(AV1_COMP *cpi, ThreadData *td,
                                       TileDataEnc *tile_data, TokenExtra **tp,
                                       const int mi_row, const int mi_col,
                                       const int seg_skip) {
  AV1_COMMON *const cm = &cpi->common;
  MACROBLOCK *const x = &td->mb;
  const SPEED_FEATURES *const sf = &cpi->sf;
  const TileInfo *const tile_info = &tile_data->tile_info;
  MB_MODE_INFO **mi = cm->mi_params.mi_grid_base +
                      get_mi_grid_idx(&cm->mi_params, mi_row, mi_col);
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;

  // Grade the temporal variation of the sb, the grade will be used to decide
  // fast mode search strategy for coding blocks
  if (sf->rt_sf.source_metrics_sb_nonrd &&
      cpi->svc.number_spatial_layers <= 1 &&
      cm->current_frame.frame_type != KEY_FRAME) {
    int offset = cpi->source->y_stride * (mi_row << 2) + (mi_col << 2);
    source_content_sb(cpi, x, offset);
  }

  // Set the partition
  if (sf->part_sf.partition_search_type == FIXED_PARTITION || seg_skip) {
    // set a fixed-size partition
    set_offsets(cpi, tile_info, x, mi_row, mi_col, sb_size);
    const BLOCK_SIZE bsize =
        seg_skip ? sb_size : sf->part_sf.always_this_block_size;
    set_fixed_partitioning(cpi, tile_info, mi, mi_row, mi_col, bsize);
  } else if (cpi->partition_search_skippable_frame) {
    // set a fixed-size partition for which the size is determined by the source
    // variance
    set_offsets(cpi, tile_info, x, mi_row, mi_col, sb_size);
    const BLOCK_SIZE bsize =
        get_rd_var_based_fixed_partition(cpi, x, mi_row, mi_col);
    set_fixed_partitioning(cpi, tile_info, mi, mi_row, mi_col, bsize);
  } else if (sf->part_sf.partition_search_type == VAR_BASED_PARTITION) {
    // set a variance-based partition
    set_offsets_without_segment_id(cpi, tile_info, x, mi_row, mi_col, sb_size);
    av1_choose_var_based_partitioning(cpi, tile_info, td, x, mi_row, mi_col);
  }
  assert(sf->part_sf.partition_search_type == FIXED_PARTITION || seg_skip ||
         cpi->partition_search_skippable_frame ||
         sf->part_sf.partition_search_type == VAR_BASED_PARTITION);
  td->mb.cb_offset = 0;

  // Adjust and encode the superblock
  PC_TREE *const pc_root = av1_alloc_pc_tree_node(sb_size);
  nonrd_use_partition(cpi, td, tile_data, mi, tp, mi_row, mi_col, sb_size,
                      pc_root);
  av1_free_pc_tree_recursive(pc_root, av1_num_planes(cm), 0, 0);
}

// Memset the mbmis at the current superblock to 0
static INLINE void reset_mbmi(CommonModeInfoParams *const mi_params,
                              BLOCK_SIZE sb_size, int mi_row, int mi_col) {
  // size of sb in unit of mi (BLOCK_4X4)
  const int sb_size_mi = mi_size_wide[sb_size];
  const int mi_alloc_size_1d = mi_size_wide[mi_params->mi_alloc_bsize];
  // size of sb in unit of allocated mi size
  const int sb_size_alloc_mi = mi_size_wide[sb_size] / mi_alloc_size_1d;
  assert(mi_params->mi_alloc_stride % sb_size_alloc_mi == 0 &&
         "mi is not allocated as a multiple of sb!");
  assert(mi_params->mi_stride % sb_size_mi == 0 &&
         "mi_grid_base is not allocated as a multiple of sb!");

  const int mi_rows = mi_size_high[sb_size];
  for (int cur_mi_row = 0; cur_mi_row < mi_rows; cur_mi_row++) {
    assert(get_mi_grid_idx(mi_params, 0, mi_col + mi_alloc_size_1d) <
           mi_params->mi_stride);
    const int mi_grid_idx =
        get_mi_grid_idx(mi_params, mi_row + cur_mi_row, mi_col);
    const int alloc_mi_idx =
        get_alloc_mi_idx(mi_params, mi_row + cur_mi_row, mi_col);
    memset(&mi_params->mi_grid_base[mi_grid_idx], 0,
           sb_size_mi * sizeof(*mi_params->mi_grid_base));
    memset(&mi_params->tx_type_map[mi_grid_idx], 0,
           sb_size_mi * sizeof(*mi_params->tx_type_map));
    if (cur_mi_row % mi_alloc_size_1d == 0) {
      memset(&mi_params->mi_alloc[alloc_mi_idx], 0,
             sb_size_alloc_mi * sizeof(*mi_params->mi_alloc));
    }
  }
}

static INLINE void backup_sb_state(SB_FIRST_PASS_STATS *sb_fp_stats,
                                   const AV1_COMP *cpi, ThreadData *td,
                                   const TileDataEnc *tile_data, int mi_row,
                                   int mi_col) {
  MACROBLOCK *x = &td->mb;
  MACROBLOCKD *xd = &x->e_mbd;
  const TileInfo *tile_info = &tile_data->tile_info;

  const AV1_COMMON *cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;

  xd->above_txfm_context =
      cm->above_contexts.txfm[tile_info->tile_row] + mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (mi_row & MAX_MIB_MASK);
  save_context(x, &sb_fp_stats->x_ctx, mi_row, mi_col, sb_size, num_planes);

  sb_fp_stats->rd_count = cpi->td.rd_counts;
  sb_fp_stats->split_count = x->txfm_search_info.txb_split_count;

  sb_fp_stats->fc = *td->counts;

  memcpy(sb_fp_stats->inter_mode_rd_models, tile_data->inter_mode_rd_models,
         sizeof(sb_fp_stats->inter_mode_rd_models));

  memcpy(sb_fp_stats->thresh_freq_fact, x->thresh_freq_fact,
         sizeof(sb_fp_stats->thresh_freq_fact));

  const int alloc_mi_idx = get_alloc_mi_idx(&cm->mi_params, mi_row, mi_col);
  sb_fp_stats->current_qindex =
      cm->mi_params.mi_alloc[alloc_mi_idx].current_qindex;

#if CONFIG_INTERNAL_STATS
  memcpy(sb_fp_stats->mode_chosen_counts, cpi->mode_chosen_counts,
         sizeof(sb_fp_stats->mode_chosen_counts));
#endif  // CONFIG_INTERNAL_STATS
}

static INLINE void restore_sb_state(const SB_FIRST_PASS_STATS *sb_fp_stats,
                                    AV1_COMP *cpi, ThreadData *td,
                                    TileDataEnc *tile_data, int mi_row,
                                    int mi_col) {
  MACROBLOCK *x = &td->mb;

  const AV1_COMMON *cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;

  restore_context(x, &sb_fp_stats->x_ctx, mi_row, mi_col, sb_size, num_planes);

  cpi->td.rd_counts = sb_fp_stats->rd_count;
  x->txfm_search_info.txb_split_count = sb_fp_stats->split_count;

  *td->counts = sb_fp_stats->fc;

  memcpy(tile_data->inter_mode_rd_models, sb_fp_stats->inter_mode_rd_models,
         sizeof(sb_fp_stats->inter_mode_rd_models));
  memcpy(x->thresh_freq_fact, sb_fp_stats->thresh_freq_fact,
         sizeof(sb_fp_stats->thresh_freq_fact));

  const int alloc_mi_idx = get_alloc_mi_idx(&cm->mi_params, mi_row, mi_col);
  cm->mi_params.mi_alloc[alloc_mi_idx].current_qindex =
      sb_fp_stats->current_qindex;

#if CONFIG_INTERNAL_STATS
  memcpy(cpi->mode_chosen_counts, sb_fp_stats->mode_chosen_counts,
         sizeof(sb_fp_stats->mode_chosen_counts));
#endif  // CONFIG_INTERNAL_STATS
}

#if !CONFIG_REALTIME_ONLY
static void init_ref_frame_space(AV1_COMP *cpi, ThreadData *td, int mi_row,
                                 int mi_col) {
  const AV1_COMMON *cm = &cpi->common;
  const CommonModeInfoParams *const mi_params = &cm->mi_params;
  MACROBLOCK *x = &td->mb;
  const int frame_idx = cpi->gf_group.index;
  TplParams *const tpl_data = &cpi->tpl_data;
  TplDepFrame *tpl_frame = &tpl_data->tpl_frame[frame_idx];
  const uint8_t block_mis_log2 = tpl_data->tpl_stats_block_mis_log2;

  av1_zero(x->tpl_keep_ref_frame);

  if (tpl_frame->is_valid == 0) return;
  if (!is_frame_tpl_eligible(cpi)) return;
  if (frame_idx >= MAX_TPL_FRAME_IDX) return;
  if (cpi->superres_mode != AOM_SUPERRES_NONE) return;
  if (cpi->oxcf.aq_mode != NO_AQ) return;

  const int is_overlay = cpi->gf_group.update_type[frame_idx] == OVERLAY_UPDATE;
  if (is_overlay) {
    memset(x->tpl_keep_ref_frame, 1, sizeof(x->tpl_keep_ref_frame));
    return;
  }

  TplDepStats *tpl_stats = tpl_frame->tpl_stats_ptr;
  const int tpl_stride = tpl_frame->stride;
  int64_t inter_cost[INTER_REFS_PER_FRAME] = { 0 };
  const int step = 1 << block_mis_log2;
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;
  const int mi_row_end =
      AOMMIN(mi_size_high[sb_size] + mi_row, mi_params->mi_rows);
  const int mi_col_end =
      AOMMIN(mi_size_wide[sb_size] + mi_col, mi_params->mi_cols);

  for (int row = mi_row; row < mi_row_end; row += step) {
    for (int col = mi_col; col < mi_col_end; col += step) {
      const TplDepStats *this_stats =
          &tpl_stats[av1_tpl_ptr_pos(row, col, tpl_stride, block_mis_log2)];
      int64_t tpl_pred_error[INTER_REFS_PER_FRAME] = { 0 };
      // Find the winner ref frame idx for the current block
      int64_t best_inter_cost = this_stats->pred_error[0];
      int best_rf_idx = 0;
      for (int idx = 1; idx < INTER_REFS_PER_FRAME; ++idx) {
        if ((this_stats->pred_error[idx] < best_inter_cost) &&
            (this_stats->pred_error[idx] != 0)) {
          best_inter_cost = this_stats->pred_error[idx];
          best_rf_idx = idx;
        }
      }
      // tpl_pred_error is the pred_error reduction of best_ref w.r.t.
      // LAST_FRAME.
      tpl_pred_error[best_rf_idx] = this_stats->pred_error[best_rf_idx] -
                                    this_stats->pred_error[LAST_FRAME - 1];

      for (int rf_idx = 1; rf_idx < INTER_REFS_PER_FRAME; ++rf_idx)
        inter_cost[rf_idx] += tpl_pred_error[rf_idx];
    }
  }

  int rank_index[INTER_REFS_PER_FRAME - 1];
  for (int idx = 0; idx < INTER_REFS_PER_FRAME - 1; ++idx) {
    rank_index[idx] = idx + 1;
    for (int i = idx; i > 0; --i) {
      if (inter_cost[rank_index[i - 1]] > inter_cost[rank_index[i]]) {
        const int tmp = rank_index[i - 1];
        rank_index[i - 1] = rank_index[i];
        rank_index[i] = tmp;
      }
    }
  }

  x->tpl_keep_ref_frame[INTRA_FRAME] = 1;
  x->tpl_keep_ref_frame[LAST_FRAME] = 1;

  int cutoff_ref = 0;
  for (int idx = 0; idx < INTER_REFS_PER_FRAME - 1; ++idx) {
    x->tpl_keep_ref_frame[rank_index[idx] + LAST_FRAME] = 1;
    if (idx > 2) {
      if (!cutoff_ref) {
        // If the predictive coding gains are smaller than the previous more
        // relevant frame over certain amount, discard this frame and all the
        // frames afterwards.
        if (llabs(inter_cost[rank_index[idx]]) <
                llabs(inter_cost[rank_index[idx - 1]]) / 8 ||
            inter_cost[rank_index[idx]] == 0)
          cutoff_ref = 1;
      }

      if (cutoff_ref) x->tpl_keep_ref_frame[rank_index[idx] + LAST_FRAME] = 0;
    }
  }
}
#endif  // !CONFIG_REALTIME_ONLY

// This function initializes the stats for encode_rd_sb.
static INLINE void init_encode_rd_sb(AV1_COMP *cpi, ThreadData *td,
                                     const TileDataEnc *tile_data,
                                     SIMPLE_MOTION_DATA_TREE *sms_root,
                                     RD_STATS *rd_cost, int mi_row, int mi_col,
                                     int gather_tpl_data) {
  const AV1_COMMON *cm = &cpi->common;
  const TileInfo *tile_info = &tile_data->tile_info;
  MACROBLOCK *x = &td->mb;

  const SPEED_FEATURES *sf = &cpi->sf;
  const int use_simple_motion_search =
      (sf->part_sf.simple_motion_search_split ||
       sf->part_sf.simple_motion_search_prune_rect ||
       sf->part_sf.simple_motion_search_early_term_none ||
       sf->part_sf.ml_early_term_after_part_split_level) &&
      !frame_is_intra_only(cm);
  if (use_simple_motion_search) {
    init_simple_motion_search_mvs(sms_root);
  }

#if !CONFIG_REALTIME_ONLY
  init_ref_frame_space(cpi, td, mi_row, mi_col);
  x->sb_energy_level = 0;
  x->part_search_info.cnn_output_valid = 0;
  if (gather_tpl_data) {
    if (cm->delta_q_info.delta_q_present_flag) {
      const int num_planes = av1_num_planes(cm);
      const BLOCK_SIZE sb_size = cm->seq_params.sb_size;
      setup_delta_q(cpi, td, x, tile_info, mi_row, mi_col, num_planes);
      av1_tpl_rdmult_setup_sb(cpi, x, sb_size, mi_row, mi_col);
    }
    if (cpi->oxcf.enable_tpl_model) {
      adjust_rdmult_tpl_model(cpi, x, mi_row, mi_col);
    }
  }
#else
  (void)tile_info;
  (void)mi_row;
  (void)mi_col;
  (void)gather_tpl_data;
#endif

  // Reset hash state for transform/mode rd hash information
  reset_hash_records(&x->txfm_search_info, cpi->sf.tx_sf.use_inter_txb_hash);
  av1_zero(x->picked_ref_frames_mask);
  av1_invalid_rd_stats(rd_cost);
}

#if !CONFIG_REALTIME_ONLY
static AOM_INLINE BLOCK_SIZE dim_to_size(int dim) {
  switch (dim) {
    case 4: return BLOCK_4X4;
    case 8: return BLOCK_8X8;
    case 16: return BLOCK_16X16;
    case 32: return BLOCK_32X32;
    case 64: return BLOCK_64X64;
    case 128: return BLOCK_128X128;
    default: assert(0); return 0;
  }
}

static AOM_INLINE void set_max_min_partition_size(SuperBlockEnc *sb_enc,
                                                  AV1_COMP *cpi, MACROBLOCK *x,
                                                  const SPEED_FEATURES *sf,
                                                  BLOCK_SIZE sb_size,
                                                  int mi_row, int mi_col) {
  const AV1_COMMON *cm = &cpi->common;

  sb_enc->max_partition_size =
      AOMMIN(sf->part_sf.default_max_partition_size,
             dim_to_size(cpi->oxcf.part_cfg.max_partition_size));
  sb_enc->min_partition_size =
      AOMMAX(sf->part_sf.default_min_partition_size,
             dim_to_size(cpi->oxcf.part_cfg.min_partition_size));
  sb_enc->max_partition_size =
      AOMMIN(sb_enc->max_partition_size, cm->seq_params.sb_size);
  sb_enc->min_partition_size =
      AOMMIN(sb_enc->min_partition_size, cm->seq_params.sb_size);

  if (use_auto_max_partition(cpi, sb_size, mi_row, mi_col)) {
    float features[FEATURE_SIZE_MAX_MIN_PART_PRED] = { 0.0f };

    av1_get_max_min_partition_features(cpi, x, mi_row, mi_col, features);
    sb_enc->max_partition_size =
        AOMMAX(AOMMIN(av1_predict_max_partition(cpi, x, features),
                      sb_enc->max_partition_size),
               sb_enc->min_partition_size);
  }
}
#endif  // !CONFIG_REALTIME_ONLY

/*!\brief Encode a superblock (RD-search-based)
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Conducts partition search for a superblock, based on rate-distortion costs,
 * from scratch or adjusting from a pre-calculated partition pattern.
 */
static AOM_INLINE void encode_rd_sb(AV1_COMP *cpi, ThreadData *td,
                                    TileDataEnc *tile_data, TokenExtra **tp,
                                    const int mi_row, const int mi_col,
                                    const int seg_skip) {
  AV1_COMMON *const cm = &cpi->common;
  MACROBLOCK *const x = &td->mb;
  const SPEED_FEATURES *const sf = &cpi->sf;
  const TileInfo *const tile_info = &tile_data->tile_info;
  MB_MODE_INFO **mi = cm->mi_params.mi_grid_base +
                      get_mi_grid_idx(&cm->mi_params, mi_row, mi_col);
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;
  const int num_planes = av1_num_planes(cm);
  int dummy_rate;
  int64_t dummy_dist;
  RD_STATS dummy_rdc;
  SIMPLE_MOTION_DATA_TREE *const sms_root = td->sms_root;

#if CONFIG_REALTIME_ONLY
  (void)seg_skip;
#endif  // CONFIG_REALTIME_ONLY

  init_encode_rd_sb(cpi, td, tile_data, sms_root, &dummy_rdc, mi_row, mi_col,
                    1);

  // Encode the superblock
  if (sf->part_sf.partition_search_type == VAR_BASED_PARTITION) {
    // partition search starting from a variance-based partition
    set_offsets_without_segment_id(cpi, tile_info, x, mi_row, mi_col, sb_size);
    av1_choose_var_based_partitioning(cpi, tile_info, td, x, mi_row, mi_col);
    PC_TREE *const pc_root = av1_alloc_pc_tree_node(sb_size);
    rd_use_partition(cpi, td, tile_data, mi, tp, mi_row, mi_col, sb_size,
                     &dummy_rate, &dummy_dist, 1, pc_root);
    av1_free_pc_tree_recursive(pc_root, num_planes, 0, 0);
  }
#if !CONFIG_REALTIME_ONLY
  else if (sf->part_sf.partition_search_type == FIXED_PARTITION || seg_skip) {
    // partition search by adjusting a fixed-size partition
    set_offsets(cpi, tile_info, x, mi_row, mi_col, sb_size);
    const BLOCK_SIZE bsize =
        seg_skip ? sb_size : sf->part_sf.always_this_block_size;
    set_fixed_partitioning(cpi, tile_info, mi, mi_row, mi_col, bsize);
    PC_TREE *const pc_root = av1_alloc_pc_tree_node(sb_size);
    rd_use_partition(cpi, td, tile_data, mi, tp, mi_row, mi_col, sb_size,
                     &dummy_rate, &dummy_dist, 1, pc_root);
    av1_free_pc_tree_recursive(pc_root, num_planes, 0, 0);
  } else if (cpi->partition_search_skippable_frame) {
    // partition search by adjusting a fixed-size partition for which the size
    // is determined by the source variance
    set_offsets(cpi, tile_info, x, mi_row, mi_col, sb_size);
    const BLOCK_SIZE bsize =
        get_rd_var_based_fixed_partition(cpi, x, mi_row, mi_col);
    set_fixed_partitioning(cpi, tile_info, mi, mi_row, mi_col, bsize);
    PC_TREE *const pc_root = av1_alloc_pc_tree_node(sb_size);
    rd_use_partition(cpi, td, tile_data, mi, tp, mi_row, mi_col, sb_size,
                     &dummy_rate, &dummy_dist, 1, pc_root);
    av1_free_pc_tree_recursive(pc_root, num_planes, 0, 0);
  } else {
    // The most exhaustive recursive partition search
    SuperBlockEnc *sb_enc = &x->sb_enc;
    // No stats for overlay frames. Exclude key frame.
    get_tpl_stats_sb(cpi, sb_size, mi_row, mi_col, sb_enc);

    // Reset the tree for simple motion search data
    reset_simple_motion_tree_partition(sms_root, sb_size);

#if CONFIG_COLLECT_COMPONENT_TIMING
    start_timing(cpi, rd_pick_partition_time);
#endif

    // Estimate the maximum square partition block size, which will be used
    // as the starting block size for partitioning the sb
    set_max_min_partition_size(sb_enc, cpi, x, sf, sb_size, mi_row, mi_col);

    // The superblock can be searched only once, or twice consecutively for
    // better quality. Note that the meaning of passes here is different from
    // the general concept of 1-pass/2-pass encoders.
    const int num_passes = cpi->oxcf.sb_multipass_unit_test ? 2 : 1;

    if (num_passes == 1) {
      PC_TREE *const pc_root = av1_alloc_pc_tree_node(sb_size);
      rd_pick_partition(cpi, td, tile_data, tp, mi_row, mi_col, sb_size,
                        &dummy_rdc, dummy_rdc, pc_root, sms_root, NULL,
                        SB_SINGLE_PASS, NULL);
    } else {
      // First pass
      SB_FIRST_PASS_STATS sb_fp_stats;
      backup_sb_state(&sb_fp_stats, cpi, td, tile_data, mi_row, mi_col);
      PC_TREE *const pc_root_p0 = av1_alloc_pc_tree_node(sb_size);
      rd_pick_partition(cpi, td, tile_data, tp, mi_row, mi_col, sb_size,
                        &dummy_rdc, dummy_rdc, pc_root_p0, sms_root, NULL,
                        SB_DRY_PASS, NULL);

      // Second pass
      init_encode_rd_sb(cpi, td, tile_data, sms_root, &dummy_rdc, mi_row,
                        mi_col, 0);
      reset_mbmi(&cm->mi_params, sb_size, mi_row, mi_col);
      reset_simple_motion_tree_partition(sms_root, sb_size);

      restore_sb_state(&sb_fp_stats, cpi, td, tile_data, mi_row, mi_col);

      PC_TREE *const pc_root_p1 = av1_alloc_pc_tree_node(sb_size);
      rd_pick_partition(cpi, td, tile_data, tp, mi_row, mi_col, sb_size,
                        &dummy_rdc, dummy_rdc, pc_root_p1, sms_root, NULL,
                        SB_WET_PASS, NULL);
    }
    // Reset to 0 so that it wouldn't be used elsewhere mistakenly.
    sb_enc->tpl_data_count = 0;
#if CONFIG_COLLECT_COMPONENT_TIMING
    end_timing(cpi, rd_pick_partition_time);
#endif
  }
#endif  // !CONFIG_REALTIME_ONLY

  // Update the inter rd model
  // TODO(angiebird): Let inter_mode_rd_model_estimation support multi-tile.
  if (cpi->sf.inter_sf.inter_mode_rd_model_estimation == 1 &&
      cm->tiles.cols == 1 && cm->tiles.rows == 1) {
    av1_inter_mode_data_fit(tile_data, x->rdmult);
  }
}

// Update the rate costs of some symbols according to the frequency directed
// by speed features
static AOM_INLINE void set_cost_upd_freq(AV1_COMP *cpi, ThreadData *td,
                                         const TileInfo *const tile_info,
                                         const int mi_row, const int mi_col) {
  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;

  switch (cpi->oxcf.coeff_cost_upd_freq) {
    case COST_UPD_TILE:  // Tile level
      if (mi_row != tile_info->mi_row_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SBROW:  // SB row level in tile
      if (mi_col != tile_info->mi_col_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SB:  // SB level
      if (cpi->sf.inter_sf.disable_sb_level_coeff_cost_upd &&
          mi_col != tile_info->mi_col_start)
        break;
      av1_fill_coeff_costs(&x->coeff_costs, xd->tile_ctx, num_planes);
      break;
    default: assert(0);
  }

  switch (cpi->oxcf.mode_cost_upd_freq) {
    case COST_UPD_TILE:  // Tile level
      if (mi_row != tile_info->mi_row_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SBROW:  // SB row level in tile
      if (mi_col != tile_info->mi_col_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SB:  // SB level
      av1_fill_mode_rates(cm, &x->mode_costs, xd->tile_ctx);
      break;
    default: assert(0);
  }
  switch (cpi->oxcf.mv_cost_upd_freq) {
    case COST_UPD_OFF: break;
    case COST_UPD_TILE:  // Tile level
      if (mi_row != tile_info->mi_row_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SBROW:  // SB row level in tile
      if (mi_col != tile_info->mi_col_start) break;
      AOM_FALLTHROUGH_INTENDED;
    case COST_UPD_SB:  // SB level
      if (cpi->sf.inter_sf.disable_sb_level_mv_cost_upd &&
          mi_col != tile_info->mi_col_start)
        break;
      av1_fill_mv_costs(xd->tile_ctx, cm->features.cur_frame_force_integer_mv,
                        cm->features.allow_high_precision_mv, &x->mv_costs);
      break;
    default: assert(0);
  }
}

/*!\brief Encode a superblock row by breaking it into superblocks
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 * Do partition and mode search for an sb row: one row of superblocks filling up
 * the width of the current tile.
 */
static AOM_INLINE void encode_sb_row(AV1_COMP *cpi, ThreadData *td,
                                     TileDataEnc *tile_data, int mi_row,
                                     TokenExtra **tp) {
  AV1_COMMON *const cm = &cpi->common;
  const TileInfo *const tile_info = &tile_data->tile_info;
  MultiThreadInfo *const mt_info = &cpi->mt_info;
  AV1EncRowMultiThreadInfo *const enc_row_mt = &mt_info->enc_row_mt;
  AV1EncRowMultiThreadSync *const row_mt_sync = &tile_data->row_mt_sync;
  bool row_mt_enabled = mt_info->row_mt_enabled;
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  const int sb_cols_in_tile = av1_get_sb_cols_in_tile(cm, tile_data->tile_info);
  const BLOCK_SIZE sb_size = cm->seq_params.sb_size;
  const int mib_size = cm->seq_params.mib_size;
  const int mib_size_log2 = cm->seq_params.mib_size_log2;
  const int sb_row = (mi_row - tile_info->mi_row_start) >> mib_size_log2;
  const int use_nonrd_mode = cpi->sf.rt_sf.use_nonrd_pick_mode;

#if CONFIG_COLLECT_COMPONENT_TIMING
  start_timing(cpi, encode_sb_time);
#endif

  // Initialize the left context for the new SB row
  av1_zero_left_context(xd);

  // Reset delta for quantizer and loof filters at the beginning of every tile
  if (mi_row == tile_info->mi_row_start || row_mt_enabled) {
    if (cm->delta_q_info.delta_q_present_flag)
      xd->current_base_qindex = cm->quant_params.base_qindex;
    if (cm->delta_q_info.delta_lf_present_flag) {
      av1_reset_loop_filter_delta(xd, av1_num_planes(cm));
    }
  }

  reset_thresh_freq_fact(x);

  // Code each SB in the row
  for (int mi_col = tile_info->mi_col_start, sb_col_in_tile = 0;
       mi_col < tile_info->mi_col_end; mi_col += mib_size, sb_col_in_tile++) {
    (*(enc_row_mt->sync_read_ptr))(row_mt_sync, sb_row, sb_col_in_tile);

    if (tile_data->allow_update_cdf && row_mt_enabled &&
        (tile_info->mi_row_start != mi_row)) {
      if ((tile_info->mi_col_start == mi_col)) {
        // restore frame context at the 1st column sb
        memcpy(xd->tile_ctx, x->row_ctx, sizeof(*xd->tile_ctx));
      } else {
        // update context
        int wt_left = AVG_CDF_WEIGHT_LEFT;
        int wt_tr = AVG_CDF_WEIGHT_TOP_RIGHT;
        if (tile_info->mi_col_end > (mi_col + mib_size))
          avg_cdf_symbols(xd->tile_ctx, x->row_ctx + sb_col_in_tile, wt_left,
                          wt_tr);
        else
          avg_cdf_symbols(xd->tile_ctx, x->row_ctx + sb_col_in_tile - 1,
                          wt_left, wt_tr);
      }
    }

    // Update the rate cost tables for some symbols
    set_cost_upd_freq(cpi, td, tile_info, mi_row, mi_col);

    // Reset color coding related parameters
    x->color_sensitivity[0] = 0;
    x->color_sensitivity[1] = 0;
    x->content_state_sb = 0;

    xd->cur_frame_force_integer_mv = cm->features.cur_frame_force_integer_mv;
    x->source_variance = UINT_MAX;
    x->simple_motion_pred_sse = UINT_MAX;
    td->mb.cb_coef_buff = av1_get_cb_coeff_buffer(cpi, mi_row, mi_col);

    // Get segment id and skip flag
    const struct segmentation *const seg = &cm->seg;
    int seg_skip = 0;
    if (seg->enabled) {
      const uint8_t *const map =
          seg->update_map ? cpi->enc_seg.map : cm->last_frame_seg_map;
      const int segment_id =
          map ? get_segment_id(&cm->mi_params, map, sb_size, mi_row, mi_col)
              : 0;
      seg_skip = segfeature_active(seg, segment_id, SEG_LVL_SKIP);
    }

    // encode the superblock
    if (use_nonrd_mode) {
      encode_nonrd_sb(cpi, td, tile_data, tp, mi_row, mi_col, seg_skip);
    } else {
      encode_rd_sb(cpi, td, tile_data, tp, mi_row, mi_col, seg_skip);
    }

    // Update the top-right context in row_mt coding
    if (tile_data->allow_update_cdf && row_mt_enabled &&
        (tile_info->mi_row_end > (mi_row + mib_size))) {
      if (sb_cols_in_tile == 1)
        memcpy(x->row_ctx, xd->tile_ctx, sizeof(*xd->tile_ctx));
      else if (sb_col_in_tile >= 1)
        memcpy(x->row_ctx + sb_col_in_tile - 1, xd->tile_ctx,
               sizeof(*xd->tile_ctx));
    }
    (*(enc_row_mt->sync_write_ptr))(row_mt_sync, sb_row, sb_col_in_tile,
                                    sb_cols_in_tile);
  }
#if CONFIG_COLLECT_COMPONENT_TIMING
  end_timing(cpi, encode_sb_time);
#endif
}

static AOM_INLINE void init_encode_frame_mb_context(AV1_COMP *cpi) {
  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCK *const x = &cpi->td.mb;
  MACROBLOCKD *const xd = &x->e_mbd;

  // Copy data over into macro block data structures.
  av1_setup_src_planes(x, cpi->source, 0, 0, num_planes,
                       cm->seq_params.sb_size);

  av1_setup_block_planes(xd, cm->seq_params.subsampling_x,
                         cm->seq_params.subsampling_y, num_planes);
}

void av1_alloc_tile_data(AV1_COMP *cpi) {
  AV1_COMMON *const cm = &cpi->common;
  const int tile_cols = cm->tiles.cols;
  const int tile_rows = cm->tiles.rows;

  if (cpi->tile_data != NULL) aom_free(cpi->tile_data);
  CHECK_MEM_ERROR(
      cm, cpi->tile_data,
      aom_memalign(32, tile_cols * tile_rows * sizeof(*cpi->tile_data)));

  cpi->allocated_tiles = tile_cols * tile_rows;
}

void av1_init_tile_data(AV1_COMP *cpi) {
  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  const int tile_cols = cm->tiles.cols;
  const int tile_rows = cm->tiles.rows;
  int tile_col, tile_row;
  TokenInfo *const token_info = &cpi->token_info;
  TokenExtra *pre_tok = token_info->tile_tok[0][0];
  TokenList *tplist = token_info->tplist[0][0];
  unsigned int tile_tok = 0;
  int tplist_count = 0;

  for (tile_row = 0; tile_row < tile_rows; ++tile_row) {
    for (tile_col = 0; tile_col < tile_cols; ++tile_col) {
      TileDataEnc *const tile_data =
          &cpi->tile_data[tile_row * tile_cols + tile_col];
      TileInfo *const tile_info = &tile_data->tile_info;
      av1_tile_init(tile_info, cm, tile_row, tile_col);
      tile_data->firstpass_top_mv = kZeroMv;

      if (pre_tok != NULL && tplist != NULL) {
        token_info->tile_tok[tile_row][tile_col] = pre_tok + tile_tok;
        pre_tok = token_info->tile_tok[tile_row][tile_col];
        tile_tok = allocated_tokens(*tile_info,
                                    cm->seq_params.mib_size_log2 + MI_SIZE_LOG2,
                                    num_planes);
        token_info->tplist[tile_row][tile_col] = tplist + tplist_count;
        tplist = token_info->tplist[tile_row][tile_col];
        tplist_count = av1_get_sb_rows_in_tile(cm, tile_data->tile_info);
      }
      tile_data->allow_update_cdf = !cm->tiles.large_scale;
      tile_data->allow_update_cdf =
          tile_data->allow_update_cdf && !cm->features.disable_cdf_update;
      tile_data->tctx = *cm->fc;
    }
  }
}

/*!\brief Encode a superblock row
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 */
void av1_encode_sb_row(AV1_COMP *cpi, ThreadData *td, int tile_row,
                       int tile_col, int mi_row) {
  AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  const int tile_cols = cm->tiles.cols;
  TileDataEnc *this_tile = &cpi->tile_data[tile_row * tile_cols + tile_col];
  const TileInfo *const tile_info = &this_tile->tile_info;
  TokenExtra *tok = NULL;
  TokenList *const tplist = cpi->token_info.tplist[tile_row][tile_col];
  const int sb_row_in_tile =
      (mi_row - tile_info->mi_row_start) >> cm->seq_params.mib_size_log2;
  const int tile_mb_cols =
      (tile_info->mi_col_end - tile_info->mi_col_start + 2) >> 2;
  const int num_mb_rows_in_sb =
      ((1 << (cm->seq_params.mib_size_log2 + MI_SIZE_LOG2)) + 8) >> 4;

  get_start_tok(cpi, tile_row, tile_col, mi_row, &tok,
                cm->seq_params.mib_size_log2 + MI_SIZE_LOG2, num_planes);
  tplist[sb_row_in_tile].start = tok;

  encode_sb_row(cpi, td, this_tile, mi_row, &tok);

  tplist[sb_row_in_tile].count =
      (unsigned int)(tok - tplist[sb_row_in_tile].start);

  assert((unsigned int)(tok - tplist[sb_row_in_tile].start) <=
         get_token_alloc(num_mb_rows_in_sb, tile_mb_cols,
                         cm->seq_params.mib_size_log2 + MI_SIZE_LOG2,
                         num_planes));

  (void)tile_mb_cols;
  (void)num_mb_rows_in_sb;
}

/*!\brief Encode a tile
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 */
void av1_encode_tile(AV1_COMP *cpi, ThreadData *td, int tile_row,
                     int tile_col) {
  AV1_COMMON *const cm = &cpi->common;
  TileDataEnc *const this_tile =
      &cpi->tile_data[tile_row * cm->tiles.cols + tile_col];
  const TileInfo *const tile_info = &this_tile->tile_info;

  if (!cpi->sf.rt_sf.use_nonrd_pick_mode) av1_inter_mode_data_init(this_tile);

  av1_zero_above_context(cm, &td->mb.e_mbd, tile_info->mi_col_start,
                         tile_info->mi_col_end, tile_row);
  av1_init_above_context(&cm->above_contexts, av1_num_planes(cm), tile_row,
                         &td->mb.e_mbd);

  if (cpi->oxcf.intra_mode_cfg.enable_cfl_intra)
    cfl_init(&td->mb.e_mbd.cfl, &cm->seq_params);

  av1_crc32c_calculator_init(
      &td->mb.txfm_search_info.mb_rd_record.crc_calculator);

  for (int mi_row = tile_info->mi_row_start; mi_row < tile_info->mi_row_end;
       mi_row += cm->seq_params.mib_size) {
    av1_encode_sb_row(cpi, td, tile_row, tile_col, mi_row);
  }
}

/*!\brief Break one frame into tiles and encode the tiles
 *
 * \ingroup partition_search
 * \callgraph
 * \callergraph
 *
 * \param[in]    cpi    Top-level encoder structure
 */
static AOM_INLINE void encode_tiles(AV1_COMP *cpi) {
  AV1_COMMON *const cm = &cpi->common;
  const int tile_cols = cm->tiles.cols;
  const int tile_rows = cm->tiles.rows;
  int tile_col, tile_row;

  assert(IMPLIES(cpi->tile_data == NULL,
                 cpi->allocated_tiles < tile_cols * tile_rows));
  if (cpi->allocated_tiles < tile_cols * tile_rows) av1_alloc_tile_data(cpi);

  av1_init_tile_data(cpi);

  for (tile_row = 0; tile_row < tile_rows; ++tile_row) {
    for (tile_col = 0; tile_col < tile_cols; ++tile_col) {
      TileDataEnc *const this_tile =
          &cpi->tile_data[tile_row * cm->tiles.cols + tile_col];
      cpi->td.intrabc_used = 0;
      cpi->td.deltaq_used = 0;
      cpi->td.mb.e_mbd.tile_ctx = &this_tile->tctx;
      cpi->td.mb.tile_pb_ctx = &this_tile->tctx;
      av1_encode_tile(cpi, &cpi->td, tile_row, tile_col);
      cpi->intrabc_used |= cpi->td.intrabc_used;
      cpi->deltaq_used |= cpi->td.deltaq_used;
    }
  }
}

// Set the relative distance of a reference frame w.r.t. current frame
static AOM_INLINE void set_rel_frame_dist(
    const AV1_COMMON *const cm, RefFrameDistanceInfo *const ref_frame_dist_info,
    const int ref_frame_flags) {
  const OrderHintInfo *const order_hint_info = &cm->seq_params.order_hint_info;
  MV_REFERENCE_FRAME ref_frame;
  int min_past_dist = INT32_MAX, min_future_dist = INT32_MAX;
  ref_frame_dist_info->nearest_past_ref = NONE_FRAME;
  ref_frame_dist_info->nearest_future_ref = NONE_FRAME;
  for (ref_frame = LAST_FRAME; ref_frame <= ALTREF_FRAME; ++ref_frame) {
    ref_frame_dist_info->ref_relative_dist[ref_frame - LAST_FRAME] = 0;
    if (ref_frame_flags & av1_ref_frame_flag_list[ref_frame]) {
      int dist = av1_encoder_get_relative_dist(
          order_hint_info,
          cm->cur_frame->ref_display_order_hint[ref_frame - LAST_FRAME],
          cm->current_frame.display_order_hint);
      ref_frame_dist_info->ref_relative_dist[ref_frame - LAST_FRAME] = dist;
      // Get the nearest ref_frame in the past
      if (abs(dist) < min_past_dist && dist < 0) {
        ref_frame_dist_info->nearest_past_ref = ref_frame;
        min_past_dist = abs(dist);
      }
      // Get the nearest ref_frame in the future
      if (dist < min_future_dist && dist > 0) {
        ref_frame_dist_info->nearest_future_ref = ref_frame;
        min_future_dist = dist;
      }
    }
  }
}

static INLINE int refs_are_one_sided(const AV1_COMMON *cm) {
  assert(!frame_is_intra_only(cm));

  int one_sided_refs = 1;
  for (int ref = LAST_FRAME; ref <= ALTREF_FRAME; ++ref) {
    const RefCntBuffer *const buf = get_ref_frame_buf(cm, ref);
    if (buf == NULL) continue;

    const int ref_display_order_hint = buf->display_order_hint;
    if (av1_encoder_get_relative_dist(
            &cm->seq_params.order_hint_info, ref_display_order_hint,
            (int)cm->current_frame.display_order_hint) > 0) {
      one_sided_refs = 0;  // bwd reference
      break;
    }
  }
  return one_sided_refs;
}

static INLINE void get_skip_mode_ref_offsets(const AV1_COMMON *cm,
                                             int ref_order_hint[2]) {
  const SkipModeInfo *const skip_mode_info = &cm->current_frame.skip_mode_info;
  ref_order_hint[0] = ref_order_hint[1] = 0;
  if (!skip_mode_info->skip_mode_allowed) return;

  const RefCntBuffer *const buf_0 =
      get_ref_frame_buf(cm, LAST_FRAME + skip_mode_info->ref_frame_idx_0);
  const RefCntBuffer *const buf_1 =
      get_ref_frame_buf(cm, LAST_FRAME + skip_mode_info->ref_frame_idx_1);
  assert(buf_0 != NULL && buf_1 != NULL);

  ref_order_hint[0] = buf_0->order_hint;
  ref_order_hint[1] = buf_1->order_hint;
}

static int check_skip_mode_enabled(AV1_COMP *const cpi) {
  AV1_COMMON *const cm = &cpi->common;

  av1_setup_skip_mode_allowed(cm);
  if (!cm->current_frame.skip_mode_info.skip_mode_allowed) return 0;

  // Turn off skip mode if the temporal distances of the reference pair to the
  // current frame are different by more than 1 frame.
  const int cur_offset = (int)cm->current_frame.order_hint;
  int ref_offset[2];
  get_skip_mode_ref_offsets(cm, ref_offset);
  const int cur_to_ref0 = get_relative_dist(&cm->seq_params.order_hint_info,
                                            cur_offset, ref_offset[0]);
  const int cur_to_ref1 = abs(get_relative_dist(&cm->seq_params.order_hint_info,
                                                cur_offset, ref_offset[1]));
  if (abs(cur_to_ref0 - cur_to_ref1) > 1) return 0;

  // High Latency: Turn off skip mode if all refs are fwd.
  if (cpi->all_one_sided_refs && cpi->oxcf.gf_cfg.lag_in_frames > 0) return 0;

  static const int flag_list[REF_FRAMES] = { 0,
                                             AOM_LAST_FLAG,
                                             AOM_LAST2_FLAG,
                                             AOM_LAST3_FLAG,
                                             AOM_GOLD_FLAG,
                                             AOM_BWD_FLAG,
                                             AOM_ALT2_FLAG,
                                             AOM_ALT_FLAG };
  const int ref_frame[2] = {
    cm->current_frame.skip_mode_info.ref_frame_idx_0 + LAST_FRAME,
    cm->current_frame.skip_mode_info.ref_frame_idx_1 + LAST_FRAME
  };
  if (!(cpi->ref_frame_flags & flag_list[ref_frame[0]]) ||
      !(cpi->ref_frame_flags & flag_list[ref_frame[1]]))
    return 0;

  return 1;
}

static AOM_INLINE void set_default_interp_skip_flags(
    const AV1_COMMON *cm, InterpSearchFlags *interp_search_flags) {
  const int num_planes = av1_num_planes(cm);
  interp_search_flags->default_interp_skip_flags =
      (num_planes == 1) ? INTERP_SKIP_LUMA_EVAL_CHROMA
                        : INTERP_SKIP_LUMA_SKIP_CHROMA;
}

static AOM_INLINE void setup_prune_ref_frame_mask(AV1_COMP *cpi) {
  if (!cpi->sf.rt_sf.use_nonrd_pick_mode &&
      cpi->sf.inter_sf.selective_ref_frame >= 2) {
    AV1_COMMON *const cm = &cpi->common;
    const OrderHintInfo *const order_hint_info =
        &cm->seq_params.order_hint_info;
    const int cur_frame_display_order_hint =
        cm->current_frame.display_order_hint;
    unsigned int *ref_display_order_hint =
        cm->cur_frame->ref_display_order_hint;
    const int arf2_dist = av1_encoder_get_relative_dist(
        order_hint_info, ref_display_order_hint[ALTREF2_FRAME - LAST_FRAME],
        cur_frame_display_order_hint);
    const int bwd_dist = av1_encoder_get_relative_dist(
        order_hint_info, ref_display_order_hint[BWDREF_FRAME - LAST_FRAME],
        cur_frame_display_order_hint);

    for (int ref_idx = REF_FRAMES; ref_idx < MODE_CTX_REF_FRAMES; ++ref_idx) {
      MV_REFERENCE_FRAME rf[2];
      av1_set_ref_frame(rf, ref_idx);
      if (!(cpi->ref_frame_flags & av1_ref_frame_flag_list[rf[0]]) ||
          !(cpi->ref_frame_flags & av1_ref_frame_flag_list[rf[1]])) {
        continue;
      }

      if (!cpi->all_one_sided_refs) {
        int ref_dist[2];
        for (int i = 0; i < 2; ++i) {
          ref_dist[i] = av1_encoder_get_relative_dist(
              order_hint_info, ref_display_order_hint[rf[i] - LAST_FRAME],
              cur_frame_display_order_hint);
        }

        // One-sided compound is used only when all reference frames are
        // one-sided.
        if ((ref_dist[0] > 0) == (ref_dist[1] > 0)) {
          cpi->prune_ref_frame_mask |= 1 << ref_idx;
        }
      }

      if (cpi->sf.inter_sf.selective_ref_frame >= 4 &&
          (rf[0] == ALTREF2_FRAME || rf[1] == ALTREF2_FRAME) &&
          (cpi->ref_frame_flags & av1_ref_frame_flag_list[BWDREF_FRAME])) {
        // Check if both ALTREF2_FRAME and BWDREF_FRAME are future references.
        if (arf2_dist > 0 && bwd_dist > 0 && bwd_dist <= arf2_dist) {
          // Drop ALTREF2_FRAME as a reference if BWDREF_FRAME is a closer
          // reference to the current frame than ALTREF2_FRAME
          cpi->prune_ref_frame_mask |= 1 << ref_idx;
        }
      }
    }
  }
}

#define CHECK_PRECOMPUTED_REF_FRAME_MAP 0

/*!\brief Encoder setup(only for the current frame), encoding, and recontruction
 * for a single frame
 *
 * \ingroup high_level_algo
 * \callgraph
 * \callergraph
 */
static AOM_INLINE void encode_frame_internal(AV1_COMP *cpi) {
  ThreadData *const td = &cpi->td;
  MACROBLOCK *const x = &td->mb;
  AV1_COMMON *const cm = &cpi->common;
  CommonModeInfoParams *const mi_params = &cm->mi_params;
  FeatureFlags *const features = &cm->features;
  MACROBLOCKD *const xd = &x->e_mbd;
  RD_COUNTS *const rdc = &cpi->td.rd_counts;
  FrameProbInfo *const frame_probs = &cpi->frame_probs;
  IntraBCHashInfo *const intrabc_hash_info = &x->intrabc_hash_info;
  MultiThreadInfo *const mt_info = &cpi->mt_info;
  AV1EncRowMultiThreadInfo *const enc_row_mt = &mt_info->enc_row_mt;
  const AV1EncoderConfig *const oxcf = &cpi->oxcf;
  int i;

  if (!cpi->sf.rt_sf.use_nonrd_pick_mode) {
    mi_params->setup_mi(mi_params);
  }

  set_mi_offsets(mi_params, xd, 0, 0);

  av1_zero(*td->counts);
  av1_zero(rdc->comp_pred_diff);
  av1_zero(rdc->tx_type_used);
  av1_zero(rdc->obmc_used);
  av1_zero(rdc->warped_used);

  // Reset the flag.
  cpi->intrabc_used = 0;
  // Need to disable intrabc when superres is selected
  if (av1_superres_scaled(cm)) {
    features->allow_intrabc = 0;
  }

  features->allow_intrabc &= (oxcf->kf_cfg.enable_intrabc);

  if (features->allow_warped_motion &&
      cpi->sf.inter_sf.prune_warped_prob_thresh > 0) {
    const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);
    if (frame_probs->warped_probs[update_type] <
        cpi->sf.inter_sf.prune_warped_prob_thresh)
      features->allow_warped_motion = 0;
  }

  int hash_table_created = 0;
  if (!is_stat_generation_stage(cpi) && av1_use_hash_me(cpi) &&
      !cpi->sf.rt_sf.use_nonrd_pick_mode) {
    // TODO(any): move this outside of the recoding loop to avoid recalculating
    // the hash table.
    // add to hash table
    const int pic_width = cpi->source->y_crop_width;
    const int pic_height = cpi->source->y_crop_height;
    uint32_t *block_hash_values[2][2];
    int8_t *is_block_same[2][3];
    int k, j;

    for (k = 0; k < 2; k++) {
      for (j = 0; j < 2; j++) {
        CHECK_MEM_ERROR(cm, block_hash_values[k][j],
                        aom_malloc(sizeof(uint32_t) * pic_width * pic_height));
      }

      for (j = 0; j < 3; j++) {
        CHECK_MEM_ERROR(cm, is_block_same[k][j],
                        aom_malloc(sizeof(int8_t) * pic_width * pic_height));
      }
    }

    av1_hash_table_init(intrabc_hash_info);
    av1_hash_table_create(&intrabc_hash_info->intrabc_hash_table);
    hash_table_created = 1;
    av1_generate_block_2x2_hash_value(intrabc_hash_info, cpi->source,
                                      block_hash_values[0], is_block_same[0]);
    // Hash data generated for screen contents is used for intraBC ME
    const int min_alloc_size = block_size_wide[mi_params->mi_alloc_bsize];
    const int max_sb_size =
        (1 << (cm->seq_params.mib_size_log2 + MI_SIZE_LOG2));
    int src_idx = 0;
    for (int size = 4; size <= max_sb_size; size *= 2, src_idx = !src_idx) {
      const int dst_idx = !src_idx;
      av1_generate_block_hash_value(
          intrabc_hash_info, cpi->source, size, block_hash_values[src_idx],
          block_hash_values[dst_idx], is_block_same[src_idx],
          is_block_same[dst_idx]);
      if (size >= min_alloc_size) {
        av1_add_to_hash_map_by_row_with_precal_data(
            &intrabc_hash_info->intrabc_hash_table, block_hash_values[dst_idx],
            is_block_same[dst_idx][2], pic_width, pic_height, size);
      }
    }

    for (k = 0; k < 2; k++) {
      for (j = 0; j < 2; j++) {
        aom_free(block_hash_values[k][j]);
      }

      for (j = 0; j < 3; j++) {
        aom_free(is_block_same[k][j]);
      }
    }
  }

  const CommonQuantParams *quant_params = &cm->quant_params;
  for (i = 0; i < MAX_SEGMENTS; ++i) {
    const int qindex =
        cm->seg.enabled ? av1_get_qindex(&cm->seg, i, quant_params->base_qindex)
                        : quant_params->base_qindex;
    xd->lossless[i] =
        qindex == 0 && quant_params->y_dc_delta_q == 0 &&
        quant_params->u_dc_delta_q == 0 && quant_params->u_ac_delta_q == 0 &&
        quant_params->v_dc_delta_q == 0 && quant_params->v_ac_delta_q == 0;
    if (xd->lossless[i]) cpi->enc_seg.has_lossless_segment = 1;
    xd->qindex[i] = qindex;
    if (xd->lossless[i]) {
      cpi->optimize_seg_arr[i] = NO_TRELLIS_OPT;
    } else {
      cpi->optimize_seg_arr[i] = cpi->sf.rd_sf.optimize_coefficients;
    }
  }
  features->coded_lossless = is_coded_lossless(cm, xd);
  features->all_lossless = features->coded_lossless && !av1_superres_scaled(cm);

  // Fix delta q resolution for the moment
  cm->delta_q_info.delta_q_res = 0;
  if (oxcf->deltaq_mode == DELTA_Q_OBJECTIVE)
    cm->delta_q_info.delta_q_res = DEFAULT_DELTA_Q_RES_OBJECTIVE;
  else if (oxcf->deltaq_mode == DELTA_Q_PERCEPTUAL)
    cm->delta_q_info.delta_q_res = DEFAULT_DELTA_Q_RES_PERCEPTUAL;
  // Set delta_q_present_flag before it is used for the first time
  cm->delta_q_info.delta_lf_res = DEFAULT_DELTA_LF_RES;
  cm->delta_q_info.delta_q_present_flag = oxcf->deltaq_mode != NO_DELTA_Q;

  // Turn off cm->delta_q_info.delta_q_present_flag if objective delta_q is used
  // for ineligible frames. That effectively will turn off row_mt usage.
  // Note objective delta_q and tpl eligible frames are only altref frames
  // currently.
  if (cm->delta_q_info.delta_q_present_flag) {
    if (oxcf->deltaq_mode == DELTA_Q_OBJECTIVE && !is_frame_tpl_eligible(cpi))
      cm->delta_q_info.delta_q_present_flag = 0;
  }

  // Reset delta_q_used flag
  cpi->deltaq_used = 0;

  cm->delta_q_info.delta_lf_present_flag =
      cm->delta_q_info.delta_q_present_flag && oxcf->deltalf_mode;
  cm->delta_q_info.delta_lf_multi = DEFAULT_DELTA_LF_MULTI;

  // update delta_q_present_flag and delta_lf_present_flag based on
  // base_qindex
  cm->delta_q_info.delta_q_present_flag &= quant_params->base_qindex > 0;
  cm->delta_q_info.delta_lf_present_flag &= quant_params->base_qindex > 0;

  av1_frame_init_quantizer(cpi);
  av1_initialize_rd_consts(cpi);
  av1_set_sad_per_bit(cpi, &x->mv_costs, quant_params->base_qindex);

  init_encode_frame_mb_context(cpi);
  set_default_interp_skip_flags(cm, &cpi->interp_search_flags);
  if (cm->prev_frame && cm->prev_frame->seg.enabled)
    cm->last_frame_seg_map = cm->prev_frame->seg_map;
  else
    cm->last_frame_seg_map = NULL;
  if (features->allow_intrabc || features->coded_lossless) {
    av1_set_default_ref_deltas(cm->lf.ref_deltas);
    av1_set_default_mode_deltas(cm->lf.mode_deltas);
  } else if (cm->prev_frame) {
    memcpy(cm->lf.ref_deltas, cm->prev_frame->ref_deltas, REF_FRAMES);
    memcpy(cm->lf.mode_deltas, cm->prev_frame->mode_deltas, MAX_MODE_LF_DELTAS);
  }
  memcpy(cm->cur_frame->ref_deltas, cm->lf.ref_deltas, REF_FRAMES);
  memcpy(cm->cur_frame->mode_deltas, cm->lf.mode_deltas, MAX_MODE_LF_DELTAS);

  cpi->all_one_sided_refs =
      frame_is_intra_only(cm) ? 0 : refs_are_one_sided(cm);

  cpi->prune_ref_frame_mask = 0;
  // Figure out which ref frames can be skipped at frame level.
  setup_prune_ref_frame_mask(cpi);

  x->txfm_search_info.txb_split_count = 0;
#if CONFIG_SPEED_STATS
  x->txfm_search_info.tx_search_count = 0;
#endif  // CONFIG_SPEED_STATS

#if CONFIG_COLLECT_COMPONENT_TIMING
  start_timing(cpi, av1_compute_global_motion_time);
#endif
  av1_compute_global_motion_facade(cpi);
#if CONFIG_COLLECT_COMPONENT_TIMING
  end_timing(cpi, av1_compute_global_motion_time);
#endif

#if CONFIG_COLLECT_COMPONENT_TIMING
  start_timing(cpi, av1_setup_motion_field_time);
#endif
  if (features->allow_ref_frame_mvs) av1_setup_motion_field(cm);
#if CONFIG_COLLECT_COMPONENT_TIMING
  end_timing(cpi, av1_setup_motion_field_time);
#endif

  cm->current_frame.skip_mode_info.skip_mode_flag =
      check_skip_mode_enabled(cpi);

  enc_row_mt->sync_read_ptr = av1_row_mt_sync_read_dummy;
  enc_row_mt->sync_write_ptr = av1_row_mt_sync_write_dummy;
  mt_info->row_mt_enabled = 0;

  if (oxcf->row_mt && (oxcf->max_threads > 1)) {
    mt_info->row_mt_enabled = 1;
    enc_row_mt->sync_read_ptr = av1_row_mt_sync_read;
    enc_row_mt->sync_write_ptr = av1_row_mt_sync_write;
    av1_encode_tiles_row_mt(cpi);
  } else {
    if (AOMMIN(oxcf->max_threads, cm->tiles.cols * cm->tiles.rows) > 1)
      av1_encode_tiles_mt(cpi);
    else
      encode_tiles(cpi);
  }

  // If intrabc is allowed but never selected, reset the allow_intrabc flag.
  if (features->allow_intrabc && !cpi->intrabc_used) {
    features->allow_intrabc = 0;
  }
  if (features->allow_intrabc) {
    cm->delta_q_info.delta_lf_present_flag = 0;
  }

  if (cm->delta_q_info.delta_q_present_flag && cpi->deltaq_used == 0) {
    cm->delta_q_info.delta_q_present_flag = 0;
  }

  // Set the transform size appropriately before bitstream creation
  const MODE_EVAL_TYPE eval_type =
      cpi->sf.winner_mode_sf.enable_winner_mode_for_tx_size_srch
          ? WINNER_MODE_EVAL
          : DEFAULT_EVAL;
  const TX_SIZE_SEARCH_METHOD tx_search_type =
      cpi->winner_mode_params.tx_size_search_methods[eval_type];
  assert(oxcf->txfm_cfg.enable_tx64 || tx_search_type != USE_LARGESTALL);
  features->tx_mode = select_tx_mode(cm, tx_search_type);

  if (cpi->sf.tx_sf.tx_type_search.prune_tx_type_using_stats) {
    const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);

    for (i = 0; i < TX_SIZES_ALL; i++) {
      int sum = 0;
      int j;
      int left = 1024;

      for (j = 0; j < TX_TYPES; j++)
        sum += cpi->td.rd_counts.tx_type_used[i][j];

      for (j = TX_TYPES - 1; j >= 0; j--) {
        const int new_prob =
            sum ? 1024 * cpi->td.rd_counts.tx_type_used[i][j] / sum
                : (j ? 0 : 1024);
        int prob =
            (frame_probs->tx_type_probs[update_type][i][j] + new_prob) >> 1;
        left -= prob;
        if (j == 0) prob += left;
        frame_probs->tx_type_probs[update_type][i][j] = prob;
      }
    }
  }

  if (!cpi->sf.inter_sf.disable_obmc &&
      cpi->sf.inter_sf.prune_obmc_prob_thresh > 0) {
    const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);

    for (i = 0; i < BLOCK_SIZES_ALL; i++) {
      int sum = 0;
      for (int j = 0; j < 2; j++) sum += cpi->td.rd_counts.obmc_used[i][j];

      const int new_prob =
          sum ? 128 * cpi->td.rd_counts.obmc_used[i][1] / sum : 0;
      frame_probs->obmc_probs[update_type][i] =
          (frame_probs->obmc_probs[update_type][i] + new_prob) >> 1;
    }
  }

  if (features->allow_warped_motion &&
      cpi->sf.inter_sf.prune_warped_prob_thresh > 0) {
    const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);
    int sum = 0;
    for (i = 0; i < 2; i++) sum += cpi->td.rd_counts.warped_used[i];
    const int new_prob = sum ? 128 * cpi->td.rd_counts.warped_used[1] / sum : 0;
    frame_probs->warped_probs[update_type] =
        (frame_probs->warped_probs[update_type] + new_prob) >> 1;
  }

  if (cm->current_frame.frame_type != KEY_FRAME &&
      cpi->sf.interp_sf.adaptive_interp_filter_search == 2 &&
      features->interp_filter == SWITCHABLE) {
    const FRAME_UPDATE_TYPE update_type = get_frame_update_type(&cpi->gf_group);

    for (i = 0; i < SWITCHABLE_FILTER_CONTEXTS; i++) {
      int sum = 0;
      int j;
      int left = 1536;

      for (j = 0; j < SWITCHABLE_FILTERS; j++) {
        sum += cpi->td.counts->switchable_interp[i][j];
      }

      for (j = SWITCHABLE_FILTERS - 1; j >= 0; j--) {
        const int new_prob =
            sum ? 1536 * cpi->td.counts->switchable_interp[i][j] / sum
                : (j ? 0 : 1536);
        int prob = (frame_probs->switchable_interp_probs[update_type][i][j] +
                    new_prob) >>
                   1;
        left -= prob;
        if (j == 0) prob += left;
        frame_probs->switchable_interp_probs[update_type][i][j] = prob;
      }
    }
  }

  if ((!is_stat_generation_stage(cpi) && av1_use_hash_me(cpi) &&
       !cpi->sf.rt_sf.use_nonrd_pick_mode) ||
      hash_table_created) {
    av1_hash_table_destroy(&intrabc_hash_info->intrabc_hash_table);
  }
}

/*!\brief Setup reference frame buffers and encode a frame
 *
 * \ingroup high_level_algo
 * \callgraph
 * \callergraph
 *
 * \param[in]    cpi    Top-level encoder structure
 */
void av1_encode_frame(AV1_COMP *cpi) {
  AV1_COMMON *const cm = &cpi->common;
  CurrentFrame *const current_frame = &cm->current_frame;
  FeatureFlags *const features = &cm->features;
  const int num_planes = av1_num_planes(cm);
  // Indicates whether or not to use a default reduced set for ext-tx
  // rather than the potential full set of 16 transforms
  features->reduced_tx_set_used = cpi->oxcf.txfm_cfg.reduced_tx_type_set;

  // Make sure segment_id is no larger than last_active_segid.
  if (cm->seg.enabled && cm->seg.update_map) {
    const int mi_rows = cm->mi_params.mi_rows;
    const int mi_cols = cm->mi_params.mi_cols;
    const int last_active_segid = cm->seg.last_active_segid;
    uint8_t *map = cpi->enc_seg.map;
    for (int mi_row = 0; mi_row < mi_rows; ++mi_row) {
      for (int mi_col = 0; mi_col < mi_cols; ++mi_col) {
        map[mi_col] = AOMMIN(map[mi_col], last_active_segid);
      }
      map += mi_cols;
    }
  }

  av1_setup_frame_buf_refs(cm);
  enforce_max_ref_frames(cpi, &cpi->ref_frame_flags);
  set_rel_frame_dist(&cpi->common, &cpi->ref_frame_dist_info,
                     cpi->ref_frame_flags);
  av1_setup_frame_sign_bias(cm);

#if CHECK_PRECOMPUTED_REF_FRAME_MAP
  GF_GROUP *gf_group = &cpi->gf_group;
  // TODO(yuec): The check is disabled on OVERLAY frames for now, because info
  // in cpi->gf_group has been refreshed for the next GOP when the check is
  // performed for OVERLAY frames. Since we have not support inter-GOP ref
  // frame map computation, the precomputed ref map for an OVERLAY frame is all
  // -1 at this point (although it is meaning before gf_group is refreshed).
  if (!frame_is_intra_only(cm) && gf_group->index != 0) {
    const RefCntBuffer *const golden_buf = get_ref_frame_buf(cm, GOLDEN_FRAME);

    if (golden_buf) {
      const int golden_order_hint = golden_buf->order_hint;

      for (int ref = LAST_FRAME; ref < EXTREF_FRAME; ++ref) {
        const RefCntBuffer *const buf = get_ref_frame_buf(cm, ref);
        const int ref_disp_idx_precomputed =
            gf_group->ref_frame_disp_idx[gf_group->index][ref - LAST_FRAME];

        (void)ref_disp_idx_precomputed;

        if (buf != NULL) {
          const int ref_disp_idx =
              get_relative_dist(&cm->seq_params.order_hint_info,
                                buf->order_hint, golden_order_hint);

          if (ref_disp_idx >= 0)
            assert(ref_disp_idx == ref_disp_idx_precomputed);
          else
            assert(ref_disp_idx_precomputed == -1);
        } else {
          assert(ref_disp_idx_precomputed == -1);
        }
      }
    }
  }
#endif

#if CONFIG_MISMATCH_DEBUG
  mismatch_reset_frame(num_planes);
#else
  (void)num_planes;
#endif

  if (cpi->sf.hl_sf.frame_parameter_update) {
    RD_COUNTS *const rdc = &cpi->td.rd_counts;

    if (frame_is_intra_only(cm))
      current_frame->reference_mode = SINGLE_REFERENCE;
    else
      current_frame->reference_mode = REFERENCE_MODE_SELECT;

    features->interp_filter = SWITCHABLE;
    if (cm->tiles.large_scale) features->interp_filter = EIGHTTAP_REGULAR;

    features->switchable_motion_mode = 1;

    rdc->compound_ref_used_flag = 0;
    rdc->skip_mode_used_flag = 0;

    encode_frame_internal(cpi);

    if (current_frame->reference_mode == REFERENCE_MODE_SELECT) {
      // Use a flag that includes 4x4 blocks
      if (rdc->compound_ref_used_flag == 0) {
        current_frame->reference_mode = SINGLE_REFERENCE;
#if CONFIG_ENTROPY_STATS
        av1_zero(cpi->td.counts->comp_inter);
#endif  // CONFIG_ENTROPY_STATS
      }
    }
    // Re-check on the skip mode status as reference mode may have been
    // changed.
    SkipModeInfo *const skip_mode_info = &current_frame->skip_mode_info;
    if (frame_is_intra_only(cm) ||
        current_frame->reference_mode == SINGLE_REFERENCE) {
      skip_mode_info->skip_mode_allowed = 0;
      skip_mode_info->skip_mode_flag = 0;
    }
    if (skip_mode_info->skip_mode_flag && rdc->skip_mode_used_flag == 0)
      skip_mode_info->skip_mode_flag = 0;

    if (!cm->tiles.large_scale) {
      if (features->tx_mode == TX_MODE_SELECT &&
          cpi->td.mb.txfm_search_info.txb_split_count == 0)
        features->tx_mode = TX_MODE_LARGEST;
    }
  } else {
    encode_frame_internal(cpi);
  }
}

static AOM_INLINE void update_txfm_count(MACROBLOCK *x, MACROBLOCKD *xd,
                                         FRAME_COUNTS *counts, TX_SIZE tx_size,
                                         int depth, int blk_row, int blk_col,
                                         uint8_t allow_update_cdf) {
  MB_MODE_INFO *mbmi = xd->mi[0];
  const BLOCK_SIZE bsize = mbmi->sb_type;
  const int max_blocks_high = max_block_high(xd, bsize, 0);
  const int max_blocks_wide = max_block_wide(xd, bsize, 0);
  int ctx = txfm_partition_context(xd->above_txfm_context + blk_col,
                                   xd->left_txfm_context + blk_row,
                                   mbmi->sb_type, tx_size);
  const int txb_size_index = av1_get_txb_size_index(bsize, blk_row, blk_col);
  const TX_SIZE plane_tx_size = mbmi->inter_tx_size[txb_size_index];

  if (blk_row >= max_blocks_high || blk_col >= max_blocks_wide) return;
  assert(tx_size > TX_4X4);

  if (depth == MAX_VARTX_DEPTH) {
    // Don't add to counts in this case
    mbmi->tx_size = tx_size;
    txfm_partition_update(xd->above_txfm_context + blk_col,
                          xd->left_txfm_context + blk_row, tx_size, tx_size);
    return;
  }

  if (tx_size == plane_tx_size) {
#if CONFIG_ENTROPY_STATS
    ++counts->txfm_partition[ctx][0];
#endif
    if (allow_update_cdf)
      update_cdf(xd->tile_ctx->txfm_partition_cdf[ctx], 0, 2);
    mbmi->tx_size = tx_size;
    txfm_partition_update(xd->above_txfm_context + blk_col,
                          xd->left_txfm_context + blk_row, tx_size, tx_size);
  } else {
    const TX_SIZE sub_txs = sub_tx_size_map[tx_size];
    const int bsw = tx_size_wide_unit[sub_txs];
    const int bsh = tx_size_high_unit[sub_txs];

#if CONFIG_ENTROPY_STATS
    ++counts->txfm_partition[ctx][1];
#endif
    if (allow_update_cdf)
      update_cdf(xd->tile_ctx->txfm_partition_cdf[ctx], 1, 2);
    ++x->txfm_search_info.txb_split_count;

    if (sub_txs == TX_4X4) {
      mbmi->inter_tx_size[txb_size_index] = TX_4X4;
      mbmi->tx_size = TX_4X4;
      txfm_partition_update(xd->above_txfm_context + blk_col,
                            xd->left_txfm_context + blk_row, TX_4X4, tx_size);
      return;
    }

    for (int row = 0; row < tx_size_high_unit[tx_size]; row += bsh) {
      for (int col = 0; col < tx_size_wide_unit[tx_size]; col += bsw) {
        int offsetr = row;
        int offsetc = col;

        update_txfm_count(x, xd, counts, sub_txs, depth + 1, blk_row + offsetr,
                          blk_col + offsetc, allow_update_cdf);
      }
    }
  }
}

static AOM_INLINE void tx_partition_count_update(const AV1_COMMON *const cm,
                                                 MACROBLOCK *x,
                                                 BLOCK_SIZE plane_bsize,
                                                 FRAME_COUNTS *td_counts,
                                                 uint8_t allow_update_cdf) {
  MACROBLOCKD *xd = &x->e_mbd;
  const int mi_width = mi_size_wide[plane_bsize];
  const int mi_height = mi_size_high[plane_bsize];
  const TX_SIZE max_tx_size = get_vartx_max_txsize(xd, plane_bsize, 0);
  const int bh = tx_size_high_unit[max_tx_size];
  const int bw = tx_size_wide_unit[max_tx_size];

  xd->above_txfm_context =
      cm->above_contexts.txfm[xd->tile.tile_row] + xd->mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (xd->mi_row & MAX_MIB_MASK);

  for (int idy = 0; idy < mi_height; idy += bh) {
    for (int idx = 0; idx < mi_width; idx += bw) {
      update_txfm_count(x, xd, td_counts, max_tx_size, 0, idy, idx,
                        allow_update_cdf);
    }
  }
}

static AOM_INLINE void set_txfm_context(MACROBLOCKD *xd, TX_SIZE tx_size,
                                        int blk_row, int blk_col) {
  MB_MODE_INFO *mbmi = xd->mi[0];
  const BLOCK_SIZE bsize = mbmi->sb_type;
  const int max_blocks_high = max_block_high(xd, bsize, 0);
  const int max_blocks_wide = max_block_wide(xd, bsize, 0);
  const int txb_size_index = av1_get_txb_size_index(bsize, blk_row, blk_col);
  const TX_SIZE plane_tx_size = mbmi->inter_tx_size[txb_size_index];

  if (blk_row >= max_blocks_high || blk_col >= max_blocks_wide) return;

  if (tx_size == plane_tx_size) {
    mbmi->tx_size = tx_size;
    txfm_partition_update(xd->above_txfm_context + blk_col,
                          xd->left_txfm_context + blk_row, tx_size, tx_size);

  } else {
    if (tx_size == TX_8X8) {
      mbmi->inter_tx_size[txb_size_index] = TX_4X4;
      mbmi->tx_size = TX_4X4;
      txfm_partition_update(xd->above_txfm_context + blk_col,
                            xd->left_txfm_context + blk_row, TX_4X4, tx_size);
      return;
    }
    const TX_SIZE sub_txs = sub_tx_size_map[tx_size];
    const int bsw = tx_size_wide_unit[sub_txs];
    const int bsh = tx_size_high_unit[sub_txs];
    for (int row = 0; row < tx_size_high_unit[tx_size]; row += bsh) {
      for (int col = 0; col < tx_size_wide_unit[tx_size]; col += bsw) {
        const int offsetr = blk_row + row;
        const int offsetc = blk_col + col;
        if (offsetr >= max_blocks_high || offsetc >= max_blocks_wide) continue;
        set_txfm_context(xd, sub_txs, offsetr, offsetc);
      }
    }
  }
}

static AOM_INLINE void tx_partition_set_contexts(const AV1_COMMON *const cm,
                                                 MACROBLOCKD *xd,
                                                 BLOCK_SIZE plane_bsize) {
  const int mi_width = mi_size_wide[plane_bsize];
  const int mi_height = mi_size_high[plane_bsize];
  const TX_SIZE max_tx_size = get_vartx_max_txsize(xd, plane_bsize, 0);
  const int bh = tx_size_high_unit[max_tx_size];
  const int bw = tx_size_wide_unit[max_tx_size];

  xd->above_txfm_context =
      cm->above_contexts.txfm[xd->tile.tile_row] + xd->mi_col;
  xd->left_txfm_context =
      xd->left_txfm_context_buffer + (xd->mi_row & MAX_MIB_MASK);

  for (int idy = 0; idy < mi_height; idy += bh) {
    for (int idx = 0; idx < mi_width; idx += bw) {
      set_txfm_context(xd, max_tx_size, idy, idx);
    }
  }
}

static AOM_INLINE void encode_superblock(const AV1_COMP *const cpi,
                                         TileDataEnc *tile_data, ThreadData *td,
                                         TokenExtra **t, RUN_TYPE dry_run,
                                         BLOCK_SIZE bsize, int *rate) {
  const AV1_COMMON *const cm = &cpi->common;
  const int num_planes = av1_num_planes(cm);
  MACROBLOCK *const x = &td->mb;
  MACROBLOCKD *const xd = &x->e_mbd;
  MB_MODE_INFO **mi_4x4 = xd->mi;
  MB_MODE_INFO *mbmi = mi_4x4[0];
  const int seg_skip =
      segfeature_active(&cm->seg, mbmi->segment_id, SEG_LVL_SKIP);
  const int mis = cm->mi_params.mi_stride;
  const int mi_width = mi_size_wide[bsize];
  const int mi_height = mi_size_high[bsize];
  const int is_inter = is_inter_block(mbmi);

  // Initialize tx_mode and tx_size_search_method
  TxfmSearchParams *txfm_params = &x->txfm_search_params;
  set_tx_size_search_method(
      cm, &cpi->winner_mode_params, txfm_params,
      cpi->sf.winner_mode_sf.enable_winner_mode_for_tx_size_srch, 1);

  const int mi_row = xd->mi_row;
  const int mi_col = xd->mi_col;
  if (!is_inter) {
    xd->cfl.store_y = store_cfl_required(cm, xd);
    mbmi->skip_txfm = 1;
    for (int plane = 0; plane < num_planes; ++plane) {
      av1_encode_intra_block_plane(cpi, x, bsize, plane, dry_run,
                                   cpi->optimize_seg_arr[mbmi->segment_id]);
    }

    // If there is at least one lossless segment, force the skip for intra
    // block to be 0, in order to avoid the segment_id to be changed by in
    // write_segment_id().
    if (!cpi->common.seg.segid_preskip && cpi->common.seg.update_map &&
        cpi->enc_seg.has_lossless_segment)
      mbmi->skip_txfm = 0;

    xd->cfl.store_y = 0;
    if (av1_allow_palette(cm->features.allow_screen_content_tools, bsize)) {
      for (int plane = 0; plane < AOMMIN(2, num_planes); ++plane) {
        if (mbmi->palette_mode_info.palette_size[plane] > 0) {
          if (!dry_run) {
            av1_tokenize_color_map(x, plane, t, bsize, mbmi->tx_size,
                                   PALETTE_MAP, tile_data->allow_update_cdf,
                                   td->counts);
          } else if (dry_run == DRY_RUN_COSTCOEFFS) {
            rate +=
                av1_cost_color_map(x, plane, bsize, mbmi->tx_size, PALETTE_MAP);
          }
        }
      }
    }

    av1_update_txb_context(cpi, td, dry_run, bsize,
                           tile_data->allow_update_cdf);
  } else {
    int ref;
    const int is_compound = has_second_ref(mbmi);

    set_ref_ptrs(cm, xd, mbmi->ref_frame[0], mbmi->ref_frame[1]);
    for (ref = 0; ref < 1 + is_compound; ++ref) {
      const YV12_BUFFER_CONFIG *cfg =
          get_ref_frame_yv12_buf(cm, mbmi->ref_frame[ref]);
      assert(IMPLIES(!is_intrabc_block(mbmi), cfg));
      av1_setup_pre_planes(xd, ref, cfg, mi_row, mi_col,
                           xd->block_ref_scale_factors[ref], num_planes);
    }
    int start_plane = (cpi->sf.rt_sf.reuse_inter_pred_nonrd) ? 1 : 0;
    av1_enc_build_inter_predictor(cm, xd, mi_row, mi_col, NULL, bsize,
                                  start_plane, av1_num_planes(cm) - 1);
    if (mbmi->motion_mode == OBMC_CAUSAL) {
      assert(cpi->oxcf.motion_mode_cfg.enable_obmc);
      av1_build_obmc_inter_predictors_sb(cm, xd);
    }

#if CONFIG_MISMATCH_DEBUG
    if (dry_run == OUTPUT_ENABLED) {
      for (int plane = 0; plane < num_planes; ++plane) {
        const struct macroblockd_plane *pd = &xd->plane[plane];
        int pixel_c, pixel_r;
        mi_to_pixel_loc(&pixel_c, &pixel_r, mi_col, mi_row, 0, 0,
                        pd->subsampling_x, pd->subsampling_y);
        if (!is_chroma_reference(mi_row, mi_col, bsize, pd->subsampling_x,
                                 pd->subsampling_y))
          continue;
        mismatch_record_block_pre(pd->dst.buf, pd->dst.stride,
                                  cm->current_frame.order_hint, plane, pixel_c,
                                  pixel_r, pd->width, pd->height,
                                  xd->cur_buf->flags & YV12_FLAG_HIGHBITDEPTH);
      }
    }
#else
    (void)num_planes;
#endif

    av1_encode_sb(cpi, x, bsize, dry_run);
    av1_tokenize_sb_vartx(cpi, td, dry_run, bsize, rate,
                          tile_data->allow_update_cdf);
  }

  if (!dry_run) {
    if (av1_allow_intrabc(cm) && is_intrabc_block(mbmi)) td->intrabc_used = 1;
    if (txfm_params->tx_mode_search_type == TX_MODE_SELECT &&
        !xd->lossless[mbmi->segment_id] && mbmi->sb_type > BLOCK_4X4 &&
        !(is_inter && (mbmi->skip_txfm || seg_skip))) {
      if (is_inter) {
        tx_partition_count_update(cm, x, bsize, td->counts,
                                  tile_data->allow_update_cdf);
      } else {
        if (mbmi->tx_size != max_txsize_rect_lookup[bsize])
          ++x->txfm_search_info.txb_split_count;
        if (block_signals_txsize(bsize)) {
          const int tx_size_ctx = get_tx_size_context(xd);
          const int32_t tx_size_cat = bsize_to_tx_size_cat(bsize);
          const int depth = tx_size_to_depth(mbmi->tx_size, bsize);
          const int max_depths = bsize_to_max_depth(bsize);

          if (tile_data->allow_update_cdf)
            update_cdf(xd->tile_ctx->tx_size_cdf[tx_size_cat][tx_size_ctx],
                       depth, max_depths + 1);
#if CONFIG_ENTROPY_STATS
          ++td->counts->intra_tx_size[tx_size_cat][tx_size_ctx][depth];
#endif
        }
      }
      assert(IMPLIES(is_rect_tx(mbmi->tx_size), is_rect_tx_allowed(xd, mbmi)));
    } else {
      int i, j;
      TX_SIZE intra_tx_size;
      // The new intra coding scheme requires no change of transform size
      if (is_inter) {
        if (xd->lossless[mbmi->segment_id]) {
          intra_tx_size = TX_4X4;
        } else {
          intra_tx_size =
              tx_size_from_tx_mode(bsize, txfm_params->tx_mode_search_type);
        }
      } else {
        intra_tx_size = mbmi->tx_size;
      }

      for (j = 0; j < mi_height; j++)
        for (i = 0; i < mi_width; i++)
          if (mi_col + i < cm->mi_params.mi_cols &&
              mi_row + j < cm->mi_params.mi_rows)
            mi_4x4[mis * j + i]->tx_size = intra_tx_size;

      if (intra_tx_size != max_txsize_rect_lookup[bsize])
        ++x->txfm_search_info.txb_split_count;
    }
  }

  if (txfm_params->tx_mode_search_type == TX_MODE_SELECT &&
      block_signals_txsize(mbmi->sb_type) && is_inter &&
      !(mbmi->skip_txfm || seg_skip) && !xd->lossless[mbmi->segment_id]) {
    if (dry_run) tx_partition_set_contexts(cm, xd, bsize);
  } else {
    TX_SIZE tx_size = mbmi->tx_size;
    // The new intra coding scheme requires no change of transform size
    if (is_inter) {
      if (xd->lossless[mbmi->segment_id]) {
        tx_size = TX_4X4;
      } else {
        tx_size = tx_size_from_tx_mode(bsize, txfm_params->tx_mode_search_type);
      }
    } else {
      tx_size = (bsize > BLOCK_4X4) ? tx_size : TX_4X4;
    }
    mbmi->tx_size = tx_size;
    set_txfm_ctxs(tx_size, xd->width, xd->height,
                  (mbmi->skip_txfm || seg_skip) && is_inter_block(mbmi), xd);
  }

  if (is_inter_block(mbmi) && !xd->is_chroma_ref && is_cfl_allowed(xd)) {
    cfl_store_block(xd, mbmi->sb_type, mbmi->tx_size);
  }
}
