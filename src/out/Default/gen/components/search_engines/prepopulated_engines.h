// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE SCHEMA DEFINITION AND DESCRIPTION IN
//   ../../components/search_engines/prepopulated_engines_schema.json
//   ../../components/search_engines/prepopulated_engines.json
// DO NOT EDIT.

#ifndef PREPOPULATED_ENGINES_H_
#define PREPOPULATED_ENGINES_H_

#include <cstddef>

#include "components/search_engines/search_engine_type.h"

namespace TemplateURLPrepopulateData {

struct PrepopulatedEngine {
  const wchar_t* const name;
  const wchar_t* const keyword;
  const char* const favicon_url;
  const char* const search_url;
  const char* const encoding;
  const char* const suggest_url;
  const char* const image_url;
  const char* const new_tab_url;
  const char* const contextual_search_url;
  const char* const logo_url;
  const char* const doodle_url;
  const char* const search_url_post_params;
  const char* const suggest_url_post_params;
  const char* const image_url_post_params;
  const char* const * alternate_urls;
  const size_t alternate_urls_size;
  const SearchEngineType type;
  const int id;
};

extern const int kMaxPrepopulatedEngineID;
extern const int kCurrentDataVersion;

extern const PrepopulatedEngine atlas_sk;
extern const PrepopulatedEngine yahoo_uk;
extern const PrepopulatedEngine yahoo_jp;
extern const PrepopulatedEngine neti;
extern const PrepopulatedEngine sogou;
extern const PrepopulatedEngine coccoc;
extern const PrepopulatedEngine rambler;
extern const PrepopulatedEngine yahoo_br;
extern const PrepopulatedEngine yandex_com;
extern const PrepopulatedEngine imesh;
extern const PrepopulatedEngine baidu;
extern const PrepopulatedEngine yahoo_ch;
extern const PrepopulatedEngine duckduckgo;
extern const PrepopulatedEngine yahoo_co;
extern const PrepopulatedEngine yahoo_cl;
extern const PrepopulatedEngine yahoo_ca;
extern const PrepopulatedEngine sweetim;
extern const PrepopulatedEngine zoznam;
extern const PrepopulatedEngine metager_de;
extern const PrepopulatedEngine mail_ru;
extern const PrepopulatedEngine ecosia;
extern const PrepopulatedEngine google;
extern const PrepopulatedEngine incredibar;
extern const PrepopulatedEngine givero;
extern const PrepopulatedEngine goo;
extern const PrepopulatedEngine sapo;
extern const PrepopulatedEngine sweetpacks;
extern const PrepopulatedEngine gmx_es;
extern const PrepopulatedEngine yahoo_dk;
extern const PrepopulatedEngine iminent;
extern const PrepopulatedEngine yandex_ua;
extern const PrepopulatedEngine yahoo_de;
extern const PrepopulatedEngine yahoo_th;
extern const PrepopulatedEngine tut;
extern const PrepopulatedEngine wp;
extern const PrepopulatedEngine ask;
extern const PrepopulatedEngine yahoo_tr;
extern const PrepopulatedEngine yahoo_ph;
extern const PrepopulatedEngine yahoo_tw;
extern const PrepopulatedEngine atlas_cz;
extern const PrepopulatedEngine ok;
extern const PrepopulatedEngine yandex_tr;
extern const PrepopulatedEngine yahoo_es;
extern const PrepopulatedEngine libero;
extern const PrepopulatedEngine terra_ar;
extern const PrepopulatedEngine oceanhero;
extern const PrepopulatedEngine funmoods;
extern const PrepopulatedEngine yahoo_nz;
extern const PrepopulatedEngine yahoo_qc;
extern const PrepopulatedEngine terra_es;
extern const PrepopulatedEngine yahoo_mx;
extern const PrepopulatedEngine yahoo_nl;
extern const PrepopulatedEngine yahoo_my;
extern const PrepopulatedEngine snapdo;
extern const PrepopulatedEngine daum;
extern const PrepopulatedEngine yahoo_fr;
extern const PrepopulatedEngine nigma;
extern const PrepopulatedEngine gmx;
extern const PrepopulatedEngine yahoo_fi;
extern const PrepopulatedEngine gmx_gb;
extern const PrepopulatedEngine yandex_by;
extern const PrepopulatedEngine conduit;
extern const PrepopulatedEngine yahoo_ve;
extern const PrepopulatedEngine yahoo;
extern const PrepopulatedEngine yahoo_vn;
extern const PrepopulatedEngine delta;
extern const PrepopulatedEngine qwant;
extern const PrepopulatedEngine gmx_de;
extern const PrepopulatedEngine yandex_ru;
extern const PrepopulatedEngine walla;
extern const PrepopulatedEngine seznam_sk;
extern const PrepopulatedEngine yahoo_hk;
extern const PrepopulatedEngine gmx_at;
extern const PrepopulatedEngine in;
extern const PrepopulatedEngine avg;
extern const PrepopulatedEngine yahoo_sg;
extern const PrepopulatedEngine yahoo_se;
extern const PrepopulatedEngine softonic;
extern const PrepopulatedEngine search_results;
extern const PrepopulatedEngine info_com;
extern const PrepopulatedEngine privacywall;
extern const PrepopulatedEngine metager_gb;
extern const PrepopulatedEngine seznam_cz;
extern const PrepopulatedEngine searchnu;
extern const PrepopulatedEngine babylon;
extern const PrepopulatedEngine yahoo_pe;
extern const PrepopulatedEngine delfi_lv;
extern const PrepopulatedEngine delfi_lt;
extern const PrepopulatedEngine yahoo_in;
extern const PrepopulatedEngine gmx_fr;
extern const PrepopulatedEngine yahoo_id;
extern const PrepopulatedEngine yahoo_at;
extern const PrepopulatedEngine yahoo_au;
extern const PrepopulatedEngine yahoo_ar;
extern const PrepopulatedEngine bing;
extern const PrepopulatedEngine so_360;
extern const PrepopulatedEngine naver;
extern const PrepopulatedEngine yandex_kz;

extern const PrepopulatedEngine* const kAllEngines[];
extern const size_t kAllEnginesLength;

}  // namespace TemplateURLPrepopulateData

#endif  // PREPOPULATED_ENGINES_H_
