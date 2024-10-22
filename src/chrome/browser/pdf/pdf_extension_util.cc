// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/pdf/pdf_extension_util.h"

#include "base/strings/string_util.h"
#include "base/values.h"
#include "chrome/browser/browser_process.h"
#include "chrome/common/chrome_content_client.h"
#include "chrome/grit/browser_resources.h"
#include "components/strings/grit/components_strings.h"
#include "components/zoom/page_zoom_constants.h"
#include "pdf/pdf_features.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/resource/resource_bundle.h"
#include "ui/base/webui/web_ui_util.h"

#if defined(OS_CHROMEOS)
#include "chrome/browser/chromeos/login/ui/login_display_host.h"
#endif  // defined(OS_CHROMEOS)

namespace pdf_extension_util {

namespace {

// Tags in the manifest to be replaced.
const char kNameTag[] = "<NAME>";

// Adds strings that are used both by the stand-alone PDF Viewer and the Print
// Preview PDF Viewer.
void AddCommonStrings(base::Value* dict) {
  static constexpr webui::LocalizedString kPdfResources[] = {
      {"errorDialogTitle", IDS_PDF_ERROR_DIALOG_TITLE},
      {"pageLoadFailed", IDS_PDF_PAGE_LOAD_FAILED},
      {"pageLoading", IDS_PDF_PAGE_LOADING},
      {"pageReload", IDS_PDF_PAGE_RELOAD_BUTTON},
      {"tooltipFitToPage", IDS_PDF_TOOLTIP_FIT_PAGE},
      {"tooltipFitToWidth", IDS_PDF_TOOLTIP_FIT_WIDTH},
      {"tooltipTwoUpViewDisable", IDS_PDF_TOOLTIP_TWO_UP_VIEW_DISABLE},
      {"tooltipTwoUpViewEnable", IDS_PDF_TOOLTIP_TWO_UP_VIEW_ENABLE},
      {"tooltipZoomIn", IDS_PDF_TOOLTIP_ZOOM_IN},
      {"tooltipZoomOut", IDS_PDF_TOOLTIP_ZOOM_OUT},
  };
  for (const auto& resource : kPdfResources)
    dict->SetStringKey(resource.name, l10n_util::GetStringUTF16(resource.id));

  dict->SetStringKey("presetZoomFactors", zoom::GetPresetZoomFactorsAsJSON());
}

// Adds strings that are used only by the stand-alone PDF Viewer.
void AddPdfViewerStrings(base::Value* dict) {
  static constexpr webui::LocalizedString kPdfResources[] = {
    {"bookmarks", IDS_PDF_BOOKMARKS},
    {"downloadEdited", IDS_PDF_DOWNLOAD_EDITED},
    {"downloadOriginal", IDS_PDF_DOWNLOAD_ORIGINAL},
    {"labelPageNumber", IDS_PDF_LABEL_PAGE_NUMBER},
    {"passwordDialogTitle", IDS_PDF_PASSWORD_DIALOG_TITLE},
    {"passwordInvalid", IDS_PDF_PASSWORD_INVALID},
    {"passwordPrompt", IDS_PDF_NEED_PASSWORD},
    {"passwordSubmit", IDS_PDF_PASSWORD_SUBMIT},
    {"tooltipDownload", IDS_PDF_TOOLTIP_DOWNLOAD},
    {"tooltipPrint", IDS_PDF_TOOLTIP_PRINT},
    {"tooltipRotateCW", IDS_PDF_TOOLTIP_ROTATE_CW},
#if defined(OS_CHROMEOS)
    {"tooltipAnnotate", IDS_PDF_ANNOTATION_ANNOTATE},
    {"annotationDocumentTooLarge", IDS_PDF_ANNOTATION_DOCUMENT_TOO_LARGE},
    {"annotationDocumentProtected", IDS_PDF_ANNOTATION_DOCUMENT_PROTECTED},
    {"annotationDocumentRotated", IDS_PDF_ANNOTATION_DOCUMENT_ROTATED},
    {"annotationPen", IDS_PDF_ANNOTATION_PEN},
    {"annotationHighlighter", IDS_PDF_ANNOTATION_HIGHLIGHTER},
    {"annotationEraser", IDS_PDF_ANNOTATION_ERASER},
    {"annotationUndo", IDS_PDF_ANNOTATION_UNDO},
    {"annotationRedo", IDS_PDF_ANNOTATION_REDO},
    {"annotationExpand", IDS_PDF_ANNOTATION_EXPAND},
    {"annotationColorBlack", IDS_PDF_ANNOTATION_COLOR_BLACK},
    {"annotationColorRed", IDS_PDF_ANNOTATION_COLOR_RED},
    {"annotationColorYellow", IDS_PDF_ANNOTATION_COLOR_YELLOW},
    {"annotationColorGreen", IDS_PDF_ANNOTATION_COLOR_GREEN},
    {"annotationColorCyan", IDS_PDF_ANNOTATION_COLOR_CYAN},
    {"annotationColorPurple", IDS_PDF_ANNOTATION_COLOR_PURPLE},
    {"annotationColorBrown", IDS_PDF_ANNOTATION_COLOR_BROWN},
    {"annotationColorWhite", IDS_PDF_ANNOTATION_COLOR_WHITE},
    {"annotationColorCrimson", IDS_PDF_ANNOTATION_COLOR_CRIMSON},
    {"annotationColorAmber", IDS_PDF_ANNOTATION_COLOR_AMBER},
    {"annotationColorAvocadoGreen", IDS_PDF_ANNOTATION_COLOR_AVOCADO_GREEN},
    {"annotationColorCobaltBlue", IDS_PDF_ANNOTATION_COLOR_COBALT_BLUE},
    {"annotationColorDeepPurple", IDS_PDF_ANNOTATION_COLOR_DEEP_PURPLE},
    {"annotationColorDarkBrown", IDS_PDF_ANNOTATION_COLOR_DARK_BROWN},
    {"annotationColorDarkGrey", IDS_PDF_ANNOTATION_COLOR_DARK_GREY},
    {"annotationColorHotPink", IDS_PDF_ANNOTATION_COLOR_HOT_PINK},
    {"annotationColorOrange", IDS_PDF_ANNOTATION_COLOR_ORANGE},
    {"annotationColorLime", IDS_PDF_ANNOTATION_COLOR_LIME},
    {"annotationColorBlue", IDS_PDF_ANNOTATION_COLOR_BLUE},
    {"annotationColorViolet", IDS_PDF_ANNOTATION_COLOR_VIOLET},
    {"annotationColorTeal", IDS_PDF_ANNOTATION_COLOR_TEAL},
    {"annotationColorLightGrey", IDS_PDF_ANNOTATION_COLOR_LIGHT_GREY},
    {"annotationColorLightPink", IDS_PDF_ANNOTATION_COLOR_LIGHT_PINK},
    {"annotationColorLightOrange", IDS_PDF_ANNOTATION_COLOR_LIGHT_ORANGE},
    {"annotationColorLightGreen", IDS_PDF_ANNOTATION_COLOR_LIGHT_GREEN},
    {"annotationColorLightBlue", IDS_PDF_ANNOTATION_COLOR_LIGHT_BLUE},
    {"annotationColorLavender", IDS_PDF_ANNOTATION_COLOR_LAVENDER},
    {"annotationColorLightTeal", IDS_PDF_ANNOTATION_COLOR_LIGHT_TEAL},
    {"annotationSize1", IDS_PDF_ANNOTATION_SIZE1},
    {"annotationSize2", IDS_PDF_ANNOTATION_SIZE2},
    {"annotationSize3", IDS_PDF_ANNOTATION_SIZE3},
    {"annotationSize4", IDS_PDF_ANNOTATION_SIZE4},
    {"annotationSize8", IDS_PDF_ANNOTATION_SIZE8},
    {"annotationSize12", IDS_PDF_ANNOTATION_SIZE12},
    {"annotationSize16", IDS_PDF_ANNOTATION_SIZE16},
    {"annotationSize20", IDS_PDF_ANNOTATION_SIZE20},
    {"annotationFormWarningTitle", IDS_PDF_DISCARD_FORM_CHANGES},
    {"annotationFormWarningDetail", IDS_PDF_DISCARD_FORM_CHANGES_DETAIL},
    {"annotationFormWarningKeepEditing", IDS_PDF_KEEP_EDITING},
    {"annotationFormWarningDiscard", IDS_PDF_DISCARD},
#endif  // defined(OS_CHROMEOS)
  };
  for (const auto& resource : kPdfResources)
    dict->SetStringKey(resource.name, l10n_util::GetStringUTF16(resource.id));

  webui::SetLoadTimeDataDefaults(g_browser_process->GetApplicationLocale(),
                                 static_cast<base::DictionaryValue*>(dict));
}

}  // namespace

std::string GetManifest() {
  std::string manifest_contents = ui::ResourceBundle::GetSharedInstance()
                                      .GetRawDataResource(IDR_PDF_MANIFEST)
                                      .as_string();
  DCHECK(manifest_contents.find(kNameTag) != std::string::npos);
  base::ReplaceFirstSubstringAfterOffset(
      &manifest_contents, 0, kNameTag,
      ChromeContentClient::kPDFExtensionPluginName);

  return manifest_contents;
}

void AddStrings(PdfViewerContext context, base::Value* dict) {
  AddCommonStrings(dict);
  if (context == PdfViewerContext::kPdfViewer ||
      context == PdfViewerContext::kAll) {
    AddPdfViewerStrings(dict);
  }
  if (context == PdfViewerContext::kPrintPreview ||
      context == PdfViewerContext::kAll) {
    // Nothing to do yet, since there are no PrintPreview-only strings.
  }
}

void AddAdditionalData(base::Value* dict) {
  dict->SetKey("pdfFormSaveEnabled",
               base::Value(base::FeatureList::IsEnabled(
                   chrome_pdf::features::kSaveEditedPDFForm)));
  dict->SetKey("pdfTwoUpViewEnabled",
               base::Value(base::FeatureList::IsEnabled(
                   chrome_pdf::features::kPDFTwoUpView)));
  dict->SetKey("pdfViewerUpdateEnabled",
               base::Value(base::FeatureList::IsEnabled(
                   chrome_pdf::features::kPDFViewerUpdate)));

  bool enable_printing = true;
  bool enable_annotations = false;
#if defined(OS_CHROMEOS)
  // For Chrome OS, enable printing only if we are not at OOBE.
  enable_printing = !chromeos::LoginDisplayHost::default_host();
  enable_annotations = true;
#endif  // defined(OS_CHROMEOS)
  dict->SetKey("printingEnabled", base::Value(enable_printing));
  dict->SetKey("pdfAnnotationsEnabled", base::Value(enable_annotations));
}

}  // namespace pdf_extension_util
