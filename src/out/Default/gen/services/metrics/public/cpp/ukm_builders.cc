
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#include "services/metrics/public/cpp/ukm_builders.h"

namespace ukm {
namespace builders {


const char AbusiveExperienceHeuristic::kEntryName[] = "AbusiveExperienceHeuristic";
const uint64_t AbusiveExperienceHeuristic::kEntryNameHash;

AbusiveExperienceHeuristic::AbusiveExperienceHeuristic(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic::AbusiveExperienceHeuristic(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic::~AbusiveExperienceHeuristic() = default;


const char AbusiveExperienceHeuristic::kDidTabUnderName[] = "DidTabUnder";
const uint64_t AbusiveExperienceHeuristic::kDidTabUnderNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidTabUnder(int64_t value) {
  SetMetricInternal(kDidTabUnderNameHash, value);
  return *this;
}

const char AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptName[] = "DidWindowOpenFromAdScript";
const uint64_t AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidWindowOpenFromAdScript(int64_t value) {
  SetMetricInternal(kDidWindowOpenFromAdScriptNameHash, value);
  return *this;
}

const char AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeName[] = "DidWindowOpenFromAdSubframe";
const uint64_t AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidWindowOpenFromAdSubframe(int64_t value) {
  SetMetricInternal(kDidWindowOpenFromAdSubframeNameHash, value);
  return *this;
}


const char AbusiveExperienceHeuristic_JavaScriptDialog::kEntryName[] = "AbusiveExperienceHeuristic.JavaScriptDialog";
const uint64_t AbusiveExperienceHeuristic_JavaScriptDialog::kEntryNameHash;

AbusiveExperienceHeuristic_JavaScriptDialog::AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_JavaScriptDialog::AbusiveExperienceHeuristic_JavaScriptDialog(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_JavaScriptDialog::~AbusiveExperienceHeuristic_JavaScriptDialog() = default;


const char AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseName[] = "DismissalCause";
const uint64_t AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseNameHash;

AbusiveExperienceHeuristic_JavaScriptDialog& AbusiveExperienceHeuristic_JavaScriptDialog::SetDismissalCause(int64_t value) {
  SetMetricInternal(kDismissalCauseNameHash, value);
  return *this;
}


const char AbusiveExperienceHeuristic_TabUnder::kEntryName[] = "AbusiveExperienceHeuristic.TabUnder";
const uint64_t AbusiveExperienceHeuristic_TabUnder::kEntryNameHash;

AbusiveExperienceHeuristic_TabUnder::AbusiveExperienceHeuristic_TabUnder(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_TabUnder::AbusiveExperienceHeuristic_TabUnder(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_TabUnder::~AbusiveExperienceHeuristic_TabUnder() = default;


const char AbusiveExperienceHeuristic_TabUnder::kDidTabUnderName[] = "DidTabUnder";
const uint64_t AbusiveExperienceHeuristic_TabUnder::kDidTabUnderNameHash;

AbusiveExperienceHeuristic_TabUnder& AbusiveExperienceHeuristic_TabUnder::SetDidTabUnder(int64_t value) {
  SetMetricInternal(kDidTabUnderNameHash, value);
  return *this;
}


const char AbusiveExperienceHeuristic_WindowOpen::kEntryName[] = "AbusiveExperienceHeuristic.WindowOpen";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kEntryNameHash;

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AbusiveExperienceHeuristic_WindowOpen::~AbusiveExperienceHeuristic_WindowOpen() = default;


const char AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptName[] = "FromAdScript";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptNameHash;

AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdScript(int64_t value) {
  SetMetricInternal(kFromAdScriptNameHash, value);
  return *this;
}

const char AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeName[] = "FromAdSubframe";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeNameHash;

AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdSubframe(int64_t value) {
  SetMetricInternal(kFromAdSubframeNameHash, value);
  return *this;
}


const char Accessibility_Renderer::kEntryName[] = "Accessibility.Renderer";
const uint64_t Accessibility_Renderer::kEntryNameHash;

Accessibility_Renderer::Accessibility_Renderer(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Accessibility_Renderer::Accessibility_Renderer(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Accessibility_Renderer::~Accessibility_Renderer() = default;


const char Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsName[] = "CpuTime.SendPendingAccessibilityEvents";
const uint64_t Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsNameHash;

Accessibility_Renderer& Accessibility_Renderer::SetCpuTime_SendPendingAccessibilityEvents(int64_t value) {
  SetMetricInternal(kCpuTime_SendPendingAccessibilityEventsNameHash, value);
  return *this;
}


const char AdFrameLoad::kEntryName[] = "AdFrameLoad";
const uint64_t AdFrameLoad::kEntryNameHash;

AdFrameLoad::AdFrameLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AdFrameLoad::AdFrameLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AdFrameLoad::~AdFrameLoad() = default;


const char AdFrameLoad::kCpuTime_PeakWindowedPercentName[] = "CpuTime.PeakWindowedPercent";
const uint64_t AdFrameLoad::kCpuTime_PeakWindowedPercentNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_PeakWindowedPercent(int64_t value) {
  SetMetricInternal(kCpuTime_PeakWindowedPercentNameHash, value);
  return *this;
}

const char AdFrameLoad::kCpuTime_PreActivationName[] = "CpuTime.PreActivation";
const uint64_t AdFrameLoad::kCpuTime_PreActivationNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_PreActivation(int64_t value) {
  SetMetricInternal(kCpuTime_PreActivationNameHash, value);
  return *this;
}

const char AdFrameLoad::kCpuTime_TotalName[] = "CpuTime.Total";
const uint64_t AdFrameLoad::kCpuTime_TotalNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_Total(int64_t value) {
  SetMetricInternal(kCpuTime_TotalNameHash, value);
  return *this;
}

const char AdFrameLoad::kFrameDepthName[] = "FrameDepth";
const uint64_t AdFrameLoad::kFrameDepthNameHash;

AdFrameLoad& AdFrameLoad::SetFrameDepth(int64_t value) {
  SetMetricInternal(kFrameDepthNameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_CacheBytes2Name[] = "Loading.CacheBytes2";
const uint64_t AdFrameLoad::kLoading_CacheBytes2NameHash;

AdFrameLoad& AdFrameLoad::SetLoading_CacheBytes2(int64_t value) {
  SetMetricInternal(kLoading_CacheBytes2NameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_ImageBytesName[] = "Loading.ImageBytes";
const uint64_t AdFrameLoad::kLoading_ImageBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_ImageBytes(int64_t value) {
  SetMetricInternal(kLoading_ImageBytesNameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_JavascriptBytesName[] = "Loading.JavascriptBytes";
const uint64_t AdFrameLoad::kLoading_JavascriptBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_JavascriptBytes(int64_t value) {
  SetMetricInternal(kLoading_JavascriptBytesNameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_NetworkBytesName[] = "Loading.NetworkBytes";
const uint64_t AdFrameLoad::kLoading_NetworkBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_NetworkBytes(int64_t value) {
  SetMetricInternal(kLoading_NetworkBytesNameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_NumResourcesName[] = "Loading.NumResources";
const uint64_t AdFrameLoad::kLoading_NumResourcesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_NumResources(int64_t value) {
  SetMetricInternal(kLoading_NumResourcesNameHash, value);
  return *this;
}

const char AdFrameLoad::kLoading_VideoBytesName[] = "Loading.VideoBytes";
const uint64_t AdFrameLoad::kLoading_VideoBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_VideoBytes(int64_t value) {
  SetMetricInternal(kLoading_VideoBytesNameHash, value);
  return *this;
}

const char AdFrameLoad::kStatus_CrossOriginName[] = "Status.CrossOrigin";
const uint64_t AdFrameLoad::kStatus_CrossOriginNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_CrossOrigin(int64_t value) {
  SetMetricInternal(kStatus_CrossOriginNameHash, value);
  return *this;
}

const char AdFrameLoad::kStatus_MediaName[] = "Status.Media";
const uint64_t AdFrameLoad::kStatus_MediaNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_Media(int64_t value) {
  SetMetricInternal(kStatus_MediaNameHash, value);
  return *this;
}

const char AdFrameLoad::kStatus_UserActivationName[] = "Status.UserActivation";
const uint64_t AdFrameLoad::kStatus_UserActivationNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_UserActivation(int64_t value) {
  SetMetricInternal(kStatus_UserActivationNameHash, value);
  return *this;
}

const char AdFrameLoad::kTiming_FirstContentfulPaintName[] = "Timing.FirstContentfulPaint";
const uint64_t AdFrameLoad::kTiming_FirstContentfulPaintNameHash;

AdFrameLoad& AdFrameLoad::SetTiming_FirstContentfulPaint(int64_t value) {
  SetMetricInternal(kTiming_FirstContentfulPaintNameHash, value);
  return *this;
}

const char AdFrameLoad::kTiming_InteractiveName[] = "Timing.Interactive";
const uint64_t AdFrameLoad::kTiming_InteractiveNameHash;

AdFrameLoad& AdFrameLoad::SetTiming_Interactive(int64_t value) {
  SetMetricInternal(kTiming_InteractiveNameHash, value);
  return *this;
}

const char AdFrameLoad::kTiming_PreActivationForegroundDurationName[] = "Timing.PreActivationForegroundDuration";
const uint64_t AdFrameLoad::kTiming_PreActivationForegroundDurationNameHash;

AdFrameLoad& AdFrameLoad::SetTiming_PreActivationForegroundDuration(int64_t value) {
  SetMetricInternal(kTiming_PreActivationForegroundDurationNameHash, value);
  return *this;
}

const char AdFrameLoad::kVisibility_FrameHeightName[] = "Visibility.FrameHeight";
const uint64_t AdFrameLoad::kVisibility_FrameHeightNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_FrameHeight(int64_t value) {
  SetMetricInternal(kVisibility_FrameHeightNameHash, value);
  return *this;
}

const char AdFrameLoad::kVisibility_FrameWidthName[] = "Visibility.FrameWidth";
const uint64_t AdFrameLoad::kVisibility_FrameWidthNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_FrameWidth(int64_t value) {
  SetMetricInternal(kVisibility_FrameWidthNameHash, value);
  return *this;
}

const char AdFrameLoad::kVisibility_HiddenName[] = "Visibility.Hidden";
const uint64_t AdFrameLoad::kVisibility_HiddenNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_Hidden(int64_t value) {
  SetMetricInternal(kVisibility_HiddenNameHash, value);
  return *this;
}


const char AdPageLoad::kEntryName[] = "AdPageLoad";
const uint64_t AdPageLoad::kEntryNameHash;

AdPageLoad::AdPageLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AdPageLoad::AdPageLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AdPageLoad::~AdPageLoad() = default;


const char AdPageLoad::kAdBytesName[] = "AdBytes";
const uint64_t AdPageLoad::kAdBytesNameHash;

AdPageLoad& AdPageLoad::SetAdBytes(int64_t value) {
  SetMetricInternal(kAdBytesNameHash, value);
  return *this;
}

const char AdPageLoad::kAdCpuTimeName[] = "AdCpuTime";
const uint64_t AdPageLoad::kAdCpuTimeNameHash;

AdPageLoad& AdPageLoad::SetAdCpuTime(int64_t value) {
  SetMetricInternal(kAdCpuTimeNameHash, value);
  return *this;
}

const char AdPageLoad::kAdJavascriptBytesName[] = "AdJavascriptBytes";
const uint64_t AdPageLoad::kAdJavascriptBytesNameHash;

AdPageLoad& AdPageLoad::SetAdJavascriptBytes(int64_t value) {
  SetMetricInternal(kAdJavascriptBytesNameHash, value);
  return *this;
}

const char AdPageLoad::kAdVideoBytesName[] = "AdVideoBytes";
const uint64_t AdPageLoad::kAdVideoBytesNameHash;

AdPageLoad& AdPageLoad::SetAdVideoBytes(int64_t value) {
  SetMetricInternal(kAdVideoBytesNameHash, value);
  return *this;
}

const char AdPageLoad::kMainframeAdBytesName[] = "MainframeAdBytes";
const uint64_t AdPageLoad::kMainframeAdBytesNameHash;

AdPageLoad& AdPageLoad::SetMainframeAdBytes(int64_t value) {
  SetMetricInternal(kMainframeAdBytesNameHash, value);
  return *this;
}

const char AdPageLoad::kTotalBytesName[] = "TotalBytes";
const uint64_t AdPageLoad::kTotalBytesNameHash;

AdPageLoad& AdPageLoad::SetTotalBytes(int64_t value) {
  SetMetricInternal(kTotalBytesNameHash, value);
  return *this;
}


const char AmpPageLoad::kEntryName[] = "AmpPageLoad";
const uint64_t AmpPageLoad::kEntryNameHash;

AmpPageLoad::AmpPageLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AmpPageLoad::AmpPageLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AmpPageLoad::~AmpPageLoad() = default;


const char AmpPageLoad::kMainFrameAmpPageLoadName[] = "MainFrameAmpPageLoad";
const uint64_t AmpPageLoad::kMainFrameAmpPageLoadNameHash;

AmpPageLoad& AmpPageLoad::SetMainFrameAmpPageLoad(int64_t value) {
  SetMetricInternal(kMainFrameAmpPageLoadNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4Name[] = "SubFrame.InteractiveTiming.FirstInputDelay4";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_FirstInputDelay4(int64_t value) {
  SetMetricInternal(kSubFrame_InteractiveTiming_FirstInputDelay4NameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreName[] = "SubFrame.LayoutInstability.CumulativeShiftScore";
const uint64_t AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_LayoutInstability_CumulativeShiftScore(int64_t value) {
  SetMetricInternal(kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[] = "SubFrame.LayoutInstability.CumulativeShiftScore.BeforeInputOrScroll";
const uint64_t AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value) {
  SetMetricInternal(kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaName[] = "SubFrame.MainFrameToSubFrameNavigationDelta";
const uint64_t AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MainFrameToSubFrameNavigationDelta(int64_t value) {
  SetMetricInternal(kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName[] = "SubFrame.PaintTiming.NavigationToFirstContentfulPaint";
const uint64_t AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_PaintTiming_NavigationToFirstContentfulPaint(int64_t value) {
  SetMetricInternal(kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaintName[] = "SubFrame.PaintTiming.NavigationToLargestContentfulPaint";
const uint64_t AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaintNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_PaintTiming_NavigationToLargestContentfulPaint(int64_t value) {
  SetMetricInternal(kSubFrame_PaintTiming_NavigationToLargestContentfulPaintNameHash, value);
  return *this;
}

const char AmpPageLoad::kSubFrameAmpPageLoadName[] = "SubFrameAmpPageLoad";
const uint64_t AmpPageLoad::kSubFrameAmpPageLoadNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrameAmpPageLoad(int64_t value) {
  SetMetricInternal(kSubFrameAmpPageLoadNameHash, value);
  return *this;
}


const char AppListAppClickData::kEntryName[] = "AppListAppClickData";
const uint64_t AppListAppClickData::kEntryNameHash;

AppListAppClickData::AppListAppClickData(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListAppClickData::AppListAppClickData(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListAppClickData::~AppListAppClickData() = default;


const char AppListAppClickData::kAppLaunchIdName[] = "AppLaunchId";
const uint64_t AppListAppClickData::kAppLaunchIdNameHash;

AppListAppClickData& AppListAppClickData::SetAppLaunchId(int64_t value) {
  SetMetricInternal(kAppLaunchIdNameHash, value);
  return *this;
}

const char AppListAppClickData::kAppTypeName[] = "AppType";
const uint64_t AppListAppClickData::kAppTypeNameHash;

AppListAppClickData& AppListAppClickData::SetAppType(int64_t value) {
  SetMetricInternal(kAppTypeNameHash, value);
  return *this;
}

const char AppListAppClickData::kClickRankName[] = "ClickRank";
const uint64_t AppListAppClickData::kClickRankNameHash;

AppListAppClickData& AppListAppClickData::SetClickRank(int64_t value) {
  SetMetricInternal(kClickRankNameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour00Name[] = "ClicksEachHour00";
const uint64_t AppListAppClickData::kClicksEachHour00NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour00(int64_t value) {
  SetMetricInternal(kClicksEachHour00NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour01Name[] = "ClicksEachHour01";
const uint64_t AppListAppClickData::kClicksEachHour01NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour01(int64_t value) {
  SetMetricInternal(kClicksEachHour01NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour02Name[] = "ClicksEachHour02";
const uint64_t AppListAppClickData::kClicksEachHour02NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour02(int64_t value) {
  SetMetricInternal(kClicksEachHour02NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour03Name[] = "ClicksEachHour03";
const uint64_t AppListAppClickData::kClicksEachHour03NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour03(int64_t value) {
  SetMetricInternal(kClicksEachHour03NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour04Name[] = "ClicksEachHour04";
const uint64_t AppListAppClickData::kClicksEachHour04NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour04(int64_t value) {
  SetMetricInternal(kClicksEachHour04NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour05Name[] = "ClicksEachHour05";
const uint64_t AppListAppClickData::kClicksEachHour05NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour05(int64_t value) {
  SetMetricInternal(kClicksEachHour05NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour06Name[] = "ClicksEachHour06";
const uint64_t AppListAppClickData::kClicksEachHour06NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour06(int64_t value) {
  SetMetricInternal(kClicksEachHour06NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour07Name[] = "ClicksEachHour07";
const uint64_t AppListAppClickData::kClicksEachHour07NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour07(int64_t value) {
  SetMetricInternal(kClicksEachHour07NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour08Name[] = "ClicksEachHour08";
const uint64_t AppListAppClickData::kClicksEachHour08NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour08(int64_t value) {
  SetMetricInternal(kClicksEachHour08NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour09Name[] = "ClicksEachHour09";
const uint64_t AppListAppClickData::kClicksEachHour09NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour09(int64_t value) {
  SetMetricInternal(kClicksEachHour09NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour10Name[] = "ClicksEachHour10";
const uint64_t AppListAppClickData::kClicksEachHour10NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour10(int64_t value) {
  SetMetricInternal(kClicksEachHour10NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour11Name[] = "ClicksEachHour11";
const uint64_t AppListAppClickData::kClicksEachHour11NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour11(int64_t value) {
  SetMetricInternal(kClicksEachHour11NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour12Name[] = "ClicksEachHour12";
const uint64_t AppListAppClickData::kClicksEachHour12NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour12(int64_t value) {
  SetMetricInternal(kClicksEachHour12NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour13Name[] = "ClicksEachHour13";
const uint64_t AppListAppClickData::kClicksEachHour13NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour13(int64_t value) {
  SetMetricInternal(kClicksEachHour13NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour14Name[] = "ClicksEachHour14";
const uint64_t AppListAppClickData::kClicksEachHour14NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour14(int64_t value) {
  SetMetricInternal(kClicksEachHour14NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour15Name[] = "ClicksEachHour15";
const uint64_t AppListAppClickData::kClicksEachHour15NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour15(int64_t value) {
  SetMetricInternal(kClicksEachHour15NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour16Name[] = "ClicksEachHour16";
const uint64_t AppListAppClickData::kClicksEachHour16NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour16(int64_t value) {
  SetMetricInternal(kClicksEachHour16NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour17Name[] = "ClicksEachHour17";
const uint64_t AppListAppClickData::kClicksEachHour17NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour17(int64_t value) {
  SetMetricInternal(kClicksEachHour17NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour18Name[] = "ClicksEachHour18";
const uint64_t AppListAppClickData::kClicksEachHour18NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour18(int64_t value) {
  SetMetricInternal(kClicksEachHour18NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour19Name[] = "ClicksEachHour19";
const uint64_t AppListAppClickData::kClicksEachHour19NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour19(int64_t value) {
  SetMetricInternal(kClicksEachHour19NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour20Name[] = "ClicksEachHour20";
const uint64_t AppListAppClickData::kClicksEachHour20NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour20(int64_t value) {
  SetMetricInternal(kClicksEachHour20NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour21Name[] = "ClicksEachHour21";
const uint64_t AppListAppClickData::kClicksEachHour21NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour21(int64_t value) {
  SetMetricInternal(kClicksEachHour21NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour22Name[] = "ClicksEachHour22";
const uint64_t AppListAppClickData::kClicksEachHour22NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour22(int64_t value) {
  SetMetricInternal(kClicksEachHour22NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksEachHour23Name[] = "ClicksEachHour23";
const uint64_t AppListAppClickData::kClicksEachHour23NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour23(int64_t value) {
  SetMetricInternal(kClicksEachHour23NameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksLast24HoursName[] = "ClicksLast24Hours";
const uint64_t AppListAppClickData::kClicksLast24HoursNameHash;

AppListAppClickData& AppListAppClickData::SetClicksLast24Hours(int64_t value) {
  SetMetricInternal(kClicksLast24HoursNameHash, value);
  return *this;
}

const char AppListAppClickData::kClicksLastHourName[] = "ClicksLastHour";
const uint64_t AppListAppClickData::kClicksLastHourNameHash;

AppListAppClickData& AppListAppClickData::SetClicksLastHour(int64_t value) {
  SetMetricInternal(kClicksLastHourNameHash, value);
  return *this;
}

const char AppListAppClickData::kLastLaunchedFromName[] = "LastLaunchedFrom";
const uint64_t AppListAppClickData::kLastLaunchedFromNameHash;

AppListAppClickData& AppListAppClickData::SetLastLaunchedFrom(int64_t value) {
  SetMetricInternal(kLastLaunchedFromNameHash, value);
  return *this;
}

const char AppListAppClickData::kMostRecentlyUsedIndexName[] = "MostRecentlyUsedIndex";
const uint64_t AppListAppClickData::kMostRecentlyUsedIndexNameHash;

AppListAppClickData& AppListAppClickData::SetMostRecentlyUsedIndex(int64_t value) {
  SetMetricInternal(kMostRecentlyUsedIndexNameHash, value);
  return *this;
}

const char AppListAppClickData::kSequenceNumberName[] = "SequenceNumber";
const uint64_t AppListAppClickData::kSequenceNumberNameHash;

AppListAppClickData& AppListAppClickData::SetSequenceNumber(int64_t value) {
  SetMetricInternal(kSequenceNumberNameHash, value);
  return *this;
}

const char AppListAppClickData::kTimeSinceLastClickName[] = "TimeSinceLastClick";
const uint64_t AppListAppClickData::kTimeSinceLastClickNameHash;

AppListAppClickData& AppListAppClickData::SetTimeSinceLastClick(int64_t value) {
  SetMetricInternal(kTimeSinceLastClickNameHash, value);
  return *this;
}

const char AppListAppClickData::kTotalClicksName[] = "TotalClicks";
const uint64_t AppListAppClickData::kTotalClicksNameHash;

AppListAppClickData& AppListAppClickData::SetTotalClicks(int64_t value) {
  SetMetricInternal(kTotalClicksNameHash, value);
  return *this;
}


const char AppListAppLaunch::kEntryName[] = "AppListAppLaunch";
const uint64_t AppListAppLaunch::kEntryNameHash;

AppListAppLaunch::AppListAppLaunch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListAppLaunch::AppListAppLaunch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListAppLaunch::~AppListAppLaunch() = default;


const char AppListAppLaunch::kAllClicksLast24HoursName[] = "AllClicksLast24Hours";
const uint64_t AppListAppLaunch::kAllClicksLast24HoursNameHash;

AppListAppLaunch& AppListAppLaunch::SetAllClicksLast24Hours(int64_t value) {
  SetMetricInternal(kAllClicksLast24HoursNameHash, value);
  return *this;
}

const char AppListAppLaunch::kAllClicksLastHourName[] = "AllClicksLastHour";
const uint64_t AppListAppLaunch::kAllClicksLastHourNameHash;

AppListAppLaunch& AppListAppLaunch::SetAllClicksLastHour(int64_t value) {
  SetMetricInternal(kAllClicksLastHourNameHash, value);
  return *this;
}

const char AppListAppLaunch::kAppTypeName[] = "AppType";
const uint64_t AppListAppLaunch::kAppTypeNameHash;

AppListAppLaunch& AppListAppLaunch::SetAppType(int64_t value) {
  SetMetricInternal(kAppTypeNameHash, value);
  return *this;
}

const char AppListAppLaunch::kClickMethodName[] = "ClickMethod";
const uint64_t AppListAppLaunch::kClickMethodNameHash;

AppListAppLaunch& AppListAppLaunch::SetClickMethod(int64_t value) {
  SetMetricInternal(kClickMethodNameHash, value);
  return *this;
}

const char AppListAppLaunch::kDayOfWeekName[] = "DayOfWeek";
const uint64_t AppListAppLaunch::kDayOfWeekNameHash;

AppListAppLaunch& AppListAppLaunch::SetDayOfWeek(int64_t value) {
  SetMetricInternal(kDayOfWeekNameHash, value);
  return *this;
}

const char AppListAppLaunch::kDeviceModeName[] = "DeviceMode";
const uint64_t AppListAppLaunch::kDeviceModeNameHash;

AppListAppLaunch& AppListAppLaunch::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char AppListAppLaunch::kDeviceTypeName[] = "DeviceType";
const uint64_t AppListAppLaunch::kDeviceTypeNameHash;

AppListAppLaunch& AppListAppLaunch::SetDeviceType(int64_t value) {
  SetMetricInternal(kDeviceTypeNameHash, value);
  return *this;
}

const char AppListAppLaunch::kHourOfDayName[] = "HourOfDay";
const uint64_t AppListAppLaunch::kHourOfDayNameHash;

AppListAppLaunch& AppListAppLaunch::SetHourOfDay(int64_t value) {
  SetMetricInternal(kHourOfDayNameHash, value);
  return *this;
}

const char AppListAppLaunch::kLaunchedFromName[] = "LaunchedFrom";
const uint64_t AppListAppLaunch::kLaunchedFromNameHash;

AppListAppLaunch& AppListAppLaunch::SetLaunchedFrom(int64_t value) {
  SetMetricInternal(kLaunchedFromNameHash, value);
  return *this;
}

const char AppListAppLaunch::kPositionIndexName[] = "PositionIndex";
const uint64_t AppListAppLaunch::kPositionIndexNameHash;

AppListAppLaunch& AppListAppLaunch::SetPositionIndex(int64_t value) {
  SetMetricInternal(kPositionIndexNameHash, value);
  return *this;
}

const char AppListAppLaunch::kTotalHoursName[] = "TotalHours";
const uint64_t AppListAppLaunch::kTotalHoursNameHash;

AppListAppLaunch& AppListAppLaunch::SetTotalHours(int64_t value) {
  SetMetricInternal(kTotalHoursNameHash, value);
  return *this;
}


const char AppListNonAppImpression::kEntryName[] = "AppListNonAppImpression";
const uint64_t AppListNonAppImpression::kEntryNameHash;

AppListNonAppImpression::AppListNonAppImpression(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListNonAppImpression::AppListNonAppImpression(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

AppListNonAppImpression::~AppListNonAppImpression() = default;


const char AppListNonAppImpression::kCategoryName[] = "Category";
const uint64_t AppListNonAppImpression::kCategoryNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetCategory(int64_t value) {
  SetMetricInternal(kCategoryNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kDayOfWeekName[] = "DayOfWeek";
const uint64_t AppListNonAppImpression::kDayOfWeekNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetDayOfWeek(int64_t value) {
  SetMetricInternal(kDayOfWeekNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kDeviceModeName[] = "DeviceMode";
const uint64_t AppListNonAppImpression::kDeviceModeNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kEventIdName[] = "EventId";
const uint64_t AppListNonAppImpression::kEventIdNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetEventId(int64_t value) {
  SetMetricInternal(kEventIdNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kFileExtensionName[] = "FileExtension";
const uint64_t AppListNonAppImpression::kFileExtensionNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetFileExtension(int64_t value) {
  SetMetricInternal(kFileExtensionNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kHourOfDayName[] = "HourOfDay";
const uint64_t AppListNonAppImpression::kHourOfDayNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetHourOfDay(int64_t value) {
  SetMetricInternal(kHourOfDayNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kIsLaunchedName[] = "IsLaunched";
const uint64_t AppListNonAppImpression::kIsLaunchedNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetIsLaunched(int64_t value) {
  SetMetricInternal(kIsLaunchedNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour00Name[] = "LaunchesAtHour00";
const uint64_t AppListNonAppImpression::kLaunchesAtHour00NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour00(int64_t value) {
  SetMetricInternal(kLaunchesAtHour00NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour01Name[] = "LaunchesAtHour01";
const uint64_t AppListNonAppImpression::kLaunchesAtHour01NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour01(int64_t value) {
  SetMetricInternal(kLaunchesAtHour01NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour02Name[] = "LaunchesAtHour02";
const uint64_t AppListNonAppImpression::kLaunchesAtHour02NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour02(int64_t value) {
  SetMetricInternal(kLaunchesAtHour02NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour03Name[] = "LaunchesAtHour03";
const uint64_t AppListNonAppImpression::kLaunchesAtHour03NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour03(int64_t value) {
  SetMetricInternal(kLaunchesAtHour03NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour04Name[] = "LaunchesAtHour04";
const uint64_t AppListNonAppImpression::kLaunchesAtHour04NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour04(int64_t value) {
  SetMetricInternal(kLaunchesAtHour04NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour05Name[] = "LaunchesAtHour05";
const uint64_t AppListNonAppImpression::kLaunchesAtHour05NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour05(int64_t value) {
  SetMetricInternal(kLaunchesAtHour05NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour06Name[] = "LaunchesAtHour06";
const uint64_t AppListNonAppImpression::kLaunchesAtHour06NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour06(int64_t value) {
  SetMetricInternal(kLaunchesAtHour06NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour07Name[] = "LaunchesAtHour07";
const uint64_t AppListNonAppImpression::kLaunchesAtHour07NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour07(int64_t value) {
  SetMetricInternal(kLaunchesAtHour07NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour08Name[] = "LaunchesAtHour08";
const uint64_t AppListNonAppImpression::kLaunchesAtHour08NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour08(int64_t value) {
  SetMetricInternal(kLaunchesAtHour08NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour09Name[] = "LaunchesAtHour09";
const uint64_t AppListNonAppImpression::kLaunchesAtHour09NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour09(int64_t value) {
  SetMetricInternal(kLaunchesAtHour09NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour10Name[] = "LaunchesAtHour10";
const uint64_t AppListNonAppImpression::kLaunchesAtHour10NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour10(int64_t value) {
  SetMetricInternal(kLaunchesAtHour10NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour11Name[] = "LaunchesAtHour11";
const uint64_t AppListNonAppImpression::kLaunchesAtHour11NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour11(int64_t value) {
  SetMetricInternal(kLaunchesAtHour11NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour12Name[] = "LaunchesAtHour12";
const uint64_t AppListNonAppImpression::kLaunchesAtHour12NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour12(int64_t value) {
  SetMetricInternal(kLaunchesAtHour12NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour13Name[] = "LaunchesAtHour13";
const uint64_t AppListNonAppImpression::kLaunchesAtHour13NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour13(int64_t value) {
  SetMetricInternal(kLaunchesAtHour13NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour14Name[] = "LaunchesAtHour14";
const uint64_t AppListNonAppImpression::kLaunchesAtHour14NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour14(int64_t value) {
  SetMetricInternal(kLaunchesAtHour14NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour15Name[] = "LaunchesAtHour15";
const uint64_t AppListNonAppImpression::kLaunchesAtHour15NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour15(int64_t value) {
  SetMetricInternal(kLaunchesAtHour15NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour16Name[] = "LaunchesAtHour16";
const uint64_t AppListNonAppImpression::kLaunchesAtHour16NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour16(int64_t value) {
  SetMetricInternal(kLaunchesAtHour16NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour17Name[] = "LaunchesAtHour17";
const uint64_t AppListNonAppImpression::kLaunchesAtHour17NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour17(int64_t value) {
  SetMetricInternal(kLaunchesAtHour17NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour18Name[] = "LaunchesAtHour18";
const uint64_t AppListNonAppImpression::kLaunchesAtHour18NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour18(int64_t value) {
  SetMetricInternal(kLaunchesAtHour18NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour19Name[] = "LaunchesAtHour19";
const uint64_t AppListNonAppImpression::kLaunchesAtHour19NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour19(int64_t value) {
  SetMetricInternal(kLaunchesAtHour19NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour20Name[] = "LaunchesAtHour20";
const uint64_t AppListNonAppImpression::kLaunchesAtHour20NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour20(int64_t value) {
  SetMetricInternal(kLaunchesAtHour20NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour21Name[] = "LaunchesAtHour21";
const uint64_t AppListNonAppImpression::kLaunchesAtHour21NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour21(int64_t value) {
  SetMetricInternal(kLaunchesAtHour21NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour22Name[] = "LaunchesAtHour22";
const uint64_t AppListNonAppImpression::kLaunchesAtHour22NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour22(int64_t value) {
  SetMetricInternal(kLaunchesAtHour22NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesAtHour23Name[] = "LaunchesAtHour23";
const uint64_t AppListNonAppImpression::kLaunchesAtHour23NameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesAtHour23(int64_t value) {
  SetMetricInternal(kLaunchesAtHour23NameHash, value);
  return *this;
}

const char AppListNonAppImpression::kLaunchesThisSessionName[] = "LaunchesThisSession";
const uint64_t AppListNonAppImpression::kLaunchesThisSessionNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetLaunchesThisSession(int64_t value) {
  SetMetricInternal(kLaunchesThisSessionNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kPositionName[] = "Position";
const uint64_t AppListNonAppImpression::kPositionNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetPosition(int64_t value) {
  SetMetricInternal(kPositionNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kQueryLengthName[] = "QueryLength";
const uint64_t AppListNonAppImpression::kQueryLengthNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetQueryLength(int64_t value) {
  SetMetricInternal(kQueryLengthNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kRelevanceScoreName[] = "RelevanceScore";
const uint64_t AppListNonAppImpression::kRelevanceScoreNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetRelevanceScore(int64_t value) {
  SetMetricInternal(kRelevanceScoreNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kTimeOfLastLaunchName[] = "TimeOfLastLaunch";
const uint64_t AppListNonAppImpression::kTimeOfLastLaunchNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetTimeOfLastLaunch(int64_t value) {
  SetMetricInternal(kTimeOfLastLaunchNameHash, value);
  return *this;
}

const char AppListNonAppImpression::kTimeSinceLastLaunchName[] = "TimeSinceLastLaunch";
const uint64_t AppListNonAppImpression::kTimeSinceLastLaunchNameHash;

AppListNonAppImpression& AppListNonAppImpression::SetTimeSinceLastLaunch(int64_t value) {
  SetMetricInternal(kTimeSinceLastLaunchNameHash, value);
  return *this;
}


const char Autofill_CardUploadDecision::kEntryName[] = "Autofill.CardUploadDecision";
const uint64_t Autofill_CardUploadDecision::kEntryNameHash;

Autofill_CardUploadDecision::Autofill_CardUploadDecision(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_CardUploadDecision::Autofill_CardUploadDecision(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_CardUploadDecision::~Autofill_CardUploadDecision() = default;


const char Autofill_CardUploadDecision::kUploadDecisionName[] = "UploadDecision";
const uint64_t Autofill_CardUploadDecision::kUploadDecisionNameHash;

Autofill_CardUploadDecision& Autofill_CardUploadDecision::SetUploadDecision(int64_t value) {
  SetMetricInternal(kUploadDecisionNameHash, value);
  return *this;
}


const char Autofill_DeveloperEngagement::kEntryName[] = "Autofill.DeveloperEngagement";
const uint64_t Autofill_DeveloperEngagement::kEntryNameHash;

Autofill_DeveloperEngagement::Autofill_DeveloperEngagement(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_DeveloperEngagement::Autofill_DeveloperEngagement(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_DeveloperEngagement::~Autofill_DeveloperEngagement() = default;


const char Autofill_DeveloperEngagement::kDeveloperEngagementName[] = "DeveloperEngagement";
const uint64_t Autofill_DeveloperEngagement::kDeveloperEngagementNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetDeveloperEngagement(int64_t value) {
  SetMetricInternal(kDeveloperEngagementNameHash, value);
  return *this;
}

const char Autofill_DeveloperEngagement::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_DeveloperEngagement::kFormSignatureNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_DeveloperEngagement::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_DeveloperEngagement::kFormTypesNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetFormTypes(int64_t value) {
  SetMetricInternal(kFormTypesNameHash, value);
  return *this;
}

const char Autofill_DeveloperEngagement::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_DeveloperEngagement::kIsForCreditCardNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetIsForCreditCard(int64_t value) {
  SetMetricInternal(kIsForCreditCardNameHash, value);
  return *this;
}


const char Autofill_FieldFillStatus::kEntryName[] = "Autofill.FieldFillStatus";
const uint64_t Autofill_FieldFillStatus::kEntryNameHash;

Autofill_FieldFillStatus::Autofill_FieldFillStatus(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FieldFillStatus::Autofill_FieldFillStatus(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FieldFillStatus::~Autofill_FieldFillStatus() = default;


const char Autofill_FieldFillStatus::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_FieldFillStatus::kFieldSignatureNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FieldFillStatus::kFormSignatureNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kIsAutofilledName[] = "IsAutofilled";
const uint64_t Autofill_FieldFillStatus::kIsAutofilledNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetIsAutofilled(int64_t value) {
  SetMetricInternal(kIsAutofilledNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FieldFillStatus::kMillisecondsSinceFormParsedNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kPredictionSourceName[] = "PredictionSource";
const uint64_t Autofill_FieldFillStatus::kPredictionSourceNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetPredictionSource(int64_t value) {
  SetMetricInternal(kPredictionSourceNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kValidationEventName[] = "ValidationEvent";
const uint64_t Autofill_FieldFillStatus::kValidationEventNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetValidationEvent(int64_t value) {
  SetMetricInternal(kValidationEventNameHash, value);
  return *this;
}

const char Autofill_FieldFillStatus::kWasPreviouslyAutofilledName[] = "WasPreviouslyAutofilled";
const uint64_t Autofill_FieldFillStatus::kWasPreviouslyAutofilledNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetWasPreviouslyAutofilled(int64_t value) {
  SetMetricInternal(kWasPreviouslyAutofilledNameHash, value);
  return *this;
}


const char Autofill_FieldTypeValidation::kEntryName[] = "Autofill.FieldTypeValidation";
const uint64_t Autofill_FieldTypeValidation::kEntryNameHash;

Autofill_FieldTypeValidation::Autofill_FieldTypeValidation(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FieldTypeValidation::Autofill_FieldTypeValidation(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FieldTypeValidation::~Autofill_FieldTypeValidation() = default;


const char Autofill_FieldTypeValidation::kActualTypeName[] = "ActualType";
const uint64_t Autofill_FieldTypeValidation::kActualTypeNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetActualType(int64_t value) {
  SetMetricInternal(kActualTypeNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_FieldTypeValidation::kFieldSignatureNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FieldTypeValidation::kFormSignatureNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kPredictedTypeName[] = "PredictedType";
const uint64_t Autofill_FieldTypeValidation::kPredictedTypeNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetPredictedType(int64_t value) {
  SetMetricInternal(kPredictedTypeNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kPredictionSourceName[] = "PredictionSource";
const uint64_t Autofill_FieldTypeValidation::kPredictionSourceNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetPredictionSource(int64_t value) {
  SetMetricInternal(kPredictionSourceNameHash, value);
  return *this;
}

const char Autofill_FieldTypeValidation::kValidationEventName[] = "ValidationEvent";
const uint64_t Autofill_FieldTypeValidation::kValidationEventNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetValidationEvent(int64_t value) {
  SetMetricInternal(kValidationEventNameHash, value);
  return *this;
}


const char Autofill_FormEvent::kEntryName[] = "Autofill.FormEvent";
const uint64_t Autofill_FormEvent::kEntryNameHash;

Autofill_FormEvent::Autofill_FormEvent(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FormEvent::Autofill_FormEvent(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FormEvent::~Autofill_FormEvent() = default;


const char Autofill_FormEvent::kAutofillFormEventName[] = "AutofillFormEvent";
const uint64_t Autofill_FormEvent::kAutofillFormEventNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetAutofillFormEvent(int64_t value) {
  SetMetricInternal(kAutofillFormEventNameHash, value);
  return *this;
}

const char Autofill_FormEvent::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_FormEvent::kFormTypesNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetFormTypes(int64_t value) {
  SetMetricInternal(kFormTypesNameHash, value);
  return *this;
}

const char Autofill_FormEvent::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FormEvent::kMillisecondsSinceFormParsedNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}


const char Autofill_FormSubmitted::kEntryName[] = "Autofill.FormSubmitted";
const uint64_t Autofill_FormSubmitted::kEntryNameHash;

Autofill_FormSubmitted::Autofill_FormSubmitted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FormSubmitted::Autofill_FormSubmitted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_FormSubmitted::~Autofill_FormSubmitted() = default;


const char Autofill_FormSubmitted::kAutofillFormSubmittedStateName[] = "AutofillFormSubmittedState";
const uint64_t Autofill_FormSubmitted::kAutofillFormSubmittedStateNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetAutofillFormSubmittedState(int64_t value) {
  SetMetricInternal(kAutofillFormSubmittedStateNameHash, value);
  return *this;
}

const char Autofill_FormSubmitted::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FormSubmitted::kFormSignatureNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_FormSubmitted::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_FormSubmitted::kFormTypesNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetFormTypes(int64_t value) {
  SetMetricInternal(kFormTypesNameHash, value);
  return *this;
}

const char Autofill_FormSubmitted::kHasUpiVpaFieldName[] = "HasUpiVpaField";
const uint64_t Autofill_FormSubmitted::kHasUpiVpaFieldNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetHasUpiVpaField(int64_t value) {
  SetMetricInternal(kHasUpiVpaFieldNameHash, value);
  return *this;
}

const char Autofill_FormSubmitted::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_FormSubmitted::kIsForCreditCardNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetIsForCreditCard(int64_t value) {
  SetMetricInternal(kIsForCreditCardNameHash, value);
  return *this;
}

const char Autofill_FormSubmitted::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FormSubmitted::kMillisecondsSinceFormParsedNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}


const char Autofill_HiddenRepresentationalFieldSkipDecision::kEntryName[] = "Autofill.HiddenRepresentationalFieldSkipDecision";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kEntryNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision::Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_HiddenRepresentationalFieldSkipDecision::Autofill_HiddenRepresentationalFieldSkipDecision(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_HiddenRepresentationalFieldSkipDecision::~Autofill_HiddenRepresentationalFieldSkipDecision() = default;


const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeName[] = "FieldOverallType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldOverallType(int64_t value) {
  SetMetricInternal(kFieldOverallTypeNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldTypeGroup(int64_t value) {
  SetMetricInternal(kFieldTypeGroupNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHeuristicType(int64_t value) {
  SetMetricInternal(kHeuristicTypeNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHtmlFieldMode(int64_t value) {
  SetMetricInternal(kHtmlFieldModeNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHtmlFieldType(int64_t value) {
  SetMetricInternal(kHtmlFieldTypeNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedName[] = "IsSkipped";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetIsSkipped(int64_t value) {
  SetMetricInternal(kIsSkippedNameHash, value);
  return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeName[] = "ServerType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetServerType(int64_t value) {
  SetMetricInternal(kServerTypeNameHash, value);
  return *this;
}


const char Autofill_InteractedWithForm::kEntryName[] = "Autofill.InteractedWithForm";
const uint64_t Autofill_InteractedWithForm::kEntryNameHash;

Autofill_InteractedWithForm::Autofill_InteractedWithForm(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_InteractedWithForm::Autofill_InteractedWithForm(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_InteractedWithForm::~Autofill_InteractedWithForm() = default;


const char Autofill_InteractedWithForm::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_InteractedWithForm::kFormSignatureNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_InteractedWithForm::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_InteractedWithForm::kFormTypesNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetFormTypes(int64_t value) {
  SetMetricInternal(kFormTypesNameHash, value);
  return *this;
}

const char Autofill_InteractedWithForm::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_InteractedWithForm::kIsForCreditCardNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetIsForCreditCard(int64_t value) {
  SetMetricInternal(kIsForCreditCardNameHash, value);
  return *this;
}

const char Autofill_InteractedWithForm::kLocalRecordTypeCountName[] = "LocalRecordTypeCount";
const uint64_t Autofill_InteractedWithForm::kLocalRecordTypeCountNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetLocalRecordTypeCount(int64_t value) {
  SetMetricInternal(kLocalRecordTypeCountNameHash, value);
  return *this;
}

const char Autofill_InteractedWithForm::kServerRecordTypeCountName[] = "ServerRecordTypeCount";
const uint64_t Autofill_InteractedWithForm::kServerRecordTypeCountNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetServerRecordTypeCount(int64_t value) {
  SetMetricInternal(kServerRecordTypeCountNameHash, value);
  return *this;
}


const char Autofill_RepeatedServerTypePredictionRationalized::kEntryName[] = "Autofill.RepeatedServerTypePredictionRationalized";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kEntryNameHash;

Autofill_RepeatedServerTypePredictionRationalized::Autofill_RepeatedServerTypePredictionRationalized(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_RepeatedServerTypePredictionRationalized::Autofill_RepeatedServerTypePredictionRationalized(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_RepeatedServerTypePredictionRationalized::~Autofill_RepeatedServerTypePredictionRationalized() = default;


const char Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeName[] = "FieldNewOverallType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldNewOverallType(int64_t value) {
  SetMetricInternal(kFieldNewOverallTypeNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeName[] = "FieldOldOverallType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldOldOverallType(int64_t value) {
  SetMetricInternal(kFieldOldOverallTypeNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldTypeGroup(int64_t value) {
  SetMetricInternal(kFieldTypeGroupNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHeuristicType(int64_t value) {
  SetMetricInternal(kHeuristicTypeNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHtmlFieldMode(int64_t value) {
  SetMetricInternal(kHtmlFieldModeNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHtmlFieldType(int64_t value) {
  SetMetricInternal(kHtmlFieldTypeNameHash, value);
  return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kServerTypeName[] = "ServerType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kServerTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetServerType(int64_t value) {
  SetMetricInternal(kServerTypeNameHash, value);
  return *this;
}


const char Autofill_SuggestionFilled::kEntryName[] = "Autofill.SuggestionFilled";
const uint64_t Autofill_SuggestionFilled::kEntryNameHash;

Autofill_SuggestionFilled::Autofill_SuggestionFilled(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_SuggestionFilled::Autofill_SuggestionFilled(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_SuggestionFilled::~Autofill_SuggestionFilled() = default;


const char Autofill_SuggestionFilled::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_SuggestionFilled::kFieldSignatureNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_SuggestionFilled::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_SuggestionFilled::kFormSignatureNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_SuggestionFilled::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_SuggestionFilled::kIsForCreditCardNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetIsForCreditCard(int64_t value) {
  SetMetricInternal(kIsForCreditCardNameHash, value);
  return *this;
}

const char Autofill_SuggestionFilled::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_SuggestionFilled::kMillisecondsSinceFormParsedNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}

const char Autofill_SuggestionFilled::kRecordTypeName[] = "RecordType";
const uint64_t Autofill_SuggestionFilled::kRecordTypeNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetRecordType(int64_t value) {
  SetMetricInternal(kRecordTypeNameHash, value);
  return *this;
}


const char Autofill_SuggestionsShown::kEntryName[] = "Autofill.SuggestionsShown";
const uint64_t Autofill_SuggestionsShown::kEntryNameHash;

Autofill_SuggestionsShown::Autofill_SuggestionsShown(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_SuggestionsShown::Autofill_SuggestionsShown(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_SuggestionsShown::~Autofill_SuggestionsShown() = default;


const char Autofill_SuggestionsShown::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_SuggestionsShown::kFieldSignatureNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_SuggestionsShown::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_SuggestionsShown::kFormSignatureNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_SuggestionsShown::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_SuggestionsShown::kHeuristicTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetHeuristicType(int64_t value) {
  SetMetricInternal(kHeuristicTypeNameHash, value);
  return *this;
}

const char Autofill_SuggestionsShown::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_SuggestionsShown::kHtmlFieldTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetHtmlFieldType(int64_t value) {
  SetMetricInternal(kHtmlFieldTypeNameHash, value);
  return *this;
}

const char Autofill_SuggestionsShown::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_SuggestionsShown::kMillisecondsSinceFormParsedNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}

const char Autofill_SuggestionsShown::kServerTypeName[] = "ServerType";
const uint64_t Autofill_SuggestionsShown::kServerTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetServerType(int64_t value) {
  SetMetricInternal(kServerTypeNameHash, value);
  return *this;
}


const char Autofill_TextFieldDidChange::kEntryName[] = "Autofill.TextFieldDidChange";
const uint64_t Autofill_TextFieldDidChange::kEntryNameHash;

Autofill_TextFieldDidChange::Autofill_TextFieldDidChange(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_TextFieldDidChange::Autofill_TextFieldDidChange(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Autofill_TextFieldDidChange::~Autofill_TextFieldDidChange() = default;


const char Autofill_TextFieldDidChange::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_TextFieldDidChange::kFieldSignatureNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFieldSignature(int64_t value) {
  SetMetricInternal(kFieldSignatureNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_TextFieldDidChange::kFieldTypeGroupNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFieldTypeGroup(int64_t value) {
  SetMetricInternal(kFieldTypeGroupNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_TextFieldDidChange::kFormSignatureNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFormSignature(int64_t value) {
  SetMetricInternal(kFormSignatureNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_TextFieldDidChange::kHeuristicTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHeuristicType(int64_t value) {
  SetMetricInternal(kHeuristicTypeNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_TextFieldDidChange::kHtmlFieldModeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHtmlFieldMode(int64_t value) {
  SetMetricInternal(kHtmlFieldModeNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_TextFieldDidChange::kHtmlFieldTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHtmlFieldType(int64_t value) {
  SetMetricInternal(kHtmlFieldTypeNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kIsAutofilledName[] = "IsAutofilled";
const uint64_t Autofill_TextFieldDidChange::kIsAutofilledNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetIsAutofilled(int64_t value) {
  SetMetricInternal(kIsAutofilledNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kIsEmptyName[] = "IsEmpty";
const uint64_t Autofill_TextFieldDidChange::kIsEmptyNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetIsEmpty(int64_t value) {
  SetMetricInternal(kIsEmptyNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetMillisecondsSinceFormParsed(int64_t value) {
  SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
  return *this;
}

const char Autofill_TextFieldDidChange::kServerTypeName[] = "ServerType";
const uint64_t Autofill_TextFieldDidChange::kServerTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetServerType(int64_t value) {
  SetMetricInternal(kServerTypeNameHash, value);
  return *this;
}


const char BackgroundFetch::kEntryName[] = "BackgroundFetch";
const uint64_t BackgroundFetch::kEntryNameHash;

BackgroundFetch::BackgroundFetch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundFetch::BackgroundFetch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundFetch::~BackgroundFetch() = default;


const char BackgroundFetch::kDeniedDueToPermissionsName[] = "DeniedDueToPermissions";
const uint64_t BackgroundFetch::kDeniedDueToPermissionsNameHash;

BackgroundFetch& BackgroundFetch::SetDeniedDueToPermissions(int64_t value) {
  SetMetricInternal(kDeniedDueToPermissionsNameHash, value);
  return *this;
}

const char BackgroundFetch::kDownloadTotalName[] = "DownloadTotal";
const uint64_t BackgroundFetch::kDownloadTotalNameHash;

BackgroundFetch& BackgroundFetch::SetDownloadTotal(int64_t value) {
  SetMetricInternal(kDownloadTotalNameHash, value);
  return *this;
}

const char BackgroundFetch::kHasTitleName[] = "HasTitle";
const uint64_t BackgroundFetch::kHasTitleNameHash;

BackgroundFetch& BackgroundFetch::SetHasTitle(int64_t value) {
  SetMetricInternal(kHasTitleNameHash, value);
  return *this;
}

const char BackgroundFetch::kNumIconsName[] = "NumIcons";
const uint64_t BackgroundFetch::kNumIconsNameHash;

BackgroundFetch& BackgroundFetch::SetNumIcons(int64_t value) {
  SetMetricInternal(kNumIconsNameHash, value);
  return *this;
}

const char BackgroundFetch::kNumRequestsInFetchName[] = "NumRequestsInFetch";
const uint64_t BackgroundFetch::kNumRequestsInFetchNameHash;

BackgroundFetch& BackgroundFetch::SetNumRequestsInFetch(int64_t value) {
  SetMetricInternal(kNumRequestsInFetchNameHash, value);
  return *this;
}

const char BackgroundFetch::kRatioOfIdealToChosenIconSizeName[] = "RatioOfIdealToChosenIconSize";
const uint64_t BackgroundFetch::kRatioOfIdealToChosenIconSizeNameHash;

BackgroundFetch& BackgroundFetch::SetRatioOfIdealToChosenIconSize(int64_t value) {
  SetMetricInternal(kRatioOfIdealToChosenIconSizeNameHash, value);
  return *this;
}


const char BackgroundFetchDeletingRegistration::kEntryName[] = "BackgroundFetchDeletingRegistration";
const uint64_t BackgroundFetchDeletingRegistration::kEntryNameHash;

BackgroundFetchDeletingRegistration::BackgroundFetchDeletingRegistration(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundFetchDeletingRegistration::BackgroundFetchDeletingRegistration(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundFetchDeletingRegistration::~BackgroundFetchDeletingRegistration() = default;


const char BackgroundFetchDeletingRegistration::kUserInitiatedAbortName[] = "UserInitiatedAbort";
const uint64_t BackgroundFetchDeletingRegistration::kUserInitiatedAbortNameHash;

BackgroundFetchDeletingRegistration& BackgroundFetchDeletingRegistration::SetUserInitiatedAbort(int64_t value) {
  SetMetricInternal(kUserInitiatedAbortNameHash, value);
  return *this;
}


const char BackgroundSyncCompleted::kEntryName[] = "BackgroundSyncCompleted";
const uint64_t BackgroundSyncCompleted::kEntryNameHash;

BackgroundSyncCompleted::BackgroundSyncCompleted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundSyncCompleted::BackgroundSyncCompleted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundSyncCompleted::~BackgroundSyncCompleted() = default;


const char BackgroundSyncCompleted::kMaxAttemptsName[] = "MaxAttempts";
const uint64_t BackgroundSyncCompleted::kMaxAttemptsNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetMaxAttempts(int64_t value) {
  SetMetricInternal(kMaxAttemptsNameHash, value);
  return *this;
}

const char BackgroundSyncCompleted::kNumAttemptsName[] = "NumAttempts";
const uint64_t BackgroundSyncCompleted::kNumAttemptsNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetNumAttempts(int64_t value) {
  SetMetricInternal(kNumAttemptsNameHash, value);
  return *this;
}

const char BackgroundSyncCompleted::kStatusName[] = "Status";
const uint64_t BackgroundSyncCompleted::kStatusNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetStatus(int64_t value) {
  SetMetricInternal(kStatusNameHash, value);
  return *this;
}


const char BackgroundSyncRegistered::kEntryName[] = "BackgroundSyncRegistered";
const uint64_t BackgroundSyncRegistered::kEntryNameHash;

BackgroundSyncRegistered::BackgroundSyncRegistered(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundSyncRegistered::BackgroundSyncRegistered(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

BackgroundSyncRegistered::~BackgroundSyncRegistered() = default;


const char BackgroundSyncRegistered::kCanFireName[] = "CanFire";
const uint64_t BackgroundSyncRegistered::kCanFireNameHash;

BackgroundSyncRegistered& BackgroundSyncRegistered::SetCanFire(int64_t value) {
  SetMetricInternal(kCanFireNameHash, value);
  return *this;
}

const char BackgroundSyncRegistered::kIsReregisteredName[] = "IsReregistered";
const uint64_t BackgroundSyncRegistered::kIsReregisteredNameHash;

BackgroundSyncRegistered& BackgroundSyncRegistered::SetIsReregistered(int64_t value) {
  SetMetricInternal(kIsReregisteredNameHash, value);
  return *this;
}


const char Badging::kEntryName[] = "Badging";
const uint64_t Badging::kEntryNameHash;

Badging::Badging(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Badging::Badging(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Badging::~Badging() = default;


const char Badging::kUpdateAppBadgeName[] = "UpdateAppBadge";
const uint64_t Badging::kUpdateAppBadgeNameHash;

Badging& Badging::SetUpdateAppBadge(int64_t value) {
  SetMetricInternal(kUpdateAppBadgeNameHash, value);
  return *this;
}


const char Blink_FindInPage::kEntryName[] = "Blink.FindInPage";
const uint64_t Blink_FindInPage::kEntryNameHash;

Blink_FindInPage::Blink_FindInPage(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_FindInPage::Blink_FindInPage(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_FindInPage::~Blink_FindInPage() = default;


const char Blink_FindInPage::kDidHaveRenderSubtreeMatchName[] = "DidHaveRenderSubtreeMatch";
const uint64_t Blink_FindInPage::kDidHaveRenderSubtreeMatchNameHash;

Blink_FindInPage& Blink_FindInPage::SetDidHaveRenderSubtreeMatch(int64_t value) {
  SetMetricInternal(kDidHaveRenderSubtreeMatchNameHash, value);
  return *this;
}

const char Blink_FindInPage::kDidSearchName[] = "DidSearch";
const uint64_t Blink_FindInPage::kDidSearchNameHash;

Blink_FindInPage& Blink_FindInPage::SetDidSearch(int64_t value) {
  SetMetricInternal(kDidSearchNameHash, value);
  return *this;
}


const char Blink_HTMLParsing::kEntryName[] = "Blink.HTMLParsing";
const uint64_t Blink_HTMLParsing::kEntryNameHash;

Blink_HTMLParsing::Blink_HTMLParsing(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_HTMLParsing::Blink_HTMLParsing(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_HTMLParsing::~Blink_HTMLParsing() = default;


const char Blink_HTMLParsing::kChunkCountName[] = "ChunkCount";
const uint64_t Blink_HTMLParsing::kChunkCountNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetChunkCount(int64_t value) {
  SetMetricInternal(kChunkCountNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kParsingTimeMaxName[] = "ParsingTimeMax";
const uint64_t Blink_HTMLParsing::kParsingTimeMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMax(int64_t value) {
  SetMetricInternal(kParsingTimeMaxNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kParsingTimeMinName[] = "ParsingTimeMin";
const uint64_t Blink_HTMLParsing::kParsingTimeMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMin(int64_t value) {
  SetMetricInternal(kParsingTimeMinNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kParsingTimeTotalName[] = "ParsingTimeTotal";
const uint64_t Blink_HTMLParsing::kParsingTimeTotalNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeTotal(int64_t value) {
  SetMetricInternal(kParsingTimeTotalNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kTokensParsedAverageName[] = "TokensParsedAverage";
const uint64_t Blink_HTMLParsing::kTokensParsedAverageNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedAverage(int64_t value) {
  SetMetricInternal(kTokensParsedAverageNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kTokensParsedMaxName[] = "TokensParsedMax";
const uint64_t Blink_HTMLParsing::kTokensParsedMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMax(int64_t value) {
  SetMetricInternal(kTokensParsedMaxNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kTokensParsedMinName[] = "TokensParsedMin";
const uint64_t Blink_HTMLParsing::kTokensParsedMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMin(int64_t value) {
  SetMetricInternal(kTokensParsedMinNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kYieldedTimeAverageName[] = "YieldedTimeAverage";
const uint64_t Blink_HTMLParsing::kYieldedTimeAverageNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeAverage(int64_t value) {
  SetMetricInternal(kYieldedTimeAverageNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kYieldedTimeMaxName[] = "YieldedTimeMax";
const uint64_t Blink_HTMLParsing::kYieldedTimeMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMax(int64_t value) {
  SetMetricInternal(kYieldedTimeMaxNameHash, value);
  return *this;
}

const char Blink_HTMLParsing::kYieldedTimeMinName[] = "YieldedTimeMin";
const uint64_t Blink_HTMLParsing::kYieldedTimeMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMin(int64_t value) {
  SetMetricInternal(kYieldedTimeMinNameHash, value);
  return *this;
}


const char Blink_PageLoad::kEntryName[] = "Blink.PageLoad";
const uint64_t Blink_PageLoad::kEntryNameHash;

Blink_PageLoad::Blink_PageLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_PageLoad::Blink_PageLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_PageLoad::~Blink_PageLoad() = default;


const char Blink_PageLoad::kAnimateName[] = "Animate";
const uint64_t Blink_PageLoad::kAnimateNameHash;

Blink_PageLoad& Blink_PageLoad::SetAnimate(int64_t value) {
  SetMetricInternal(kAnimateNameHash, value);
  return *this;
}

const char Blink_PageLoad::kCompositingName[] = "Compositing";
const uint64_t Blink_PageLoad::kCompositingNameHash;

Blink_PageLoad& Blink_PageLoad::SetCompositing(int64_t value) {
  SetMetricInternal(kCompositingNameHash, value);
  return *this;
}

const char Blink_PageLoad::kCompositingCommitName[] = "CompositingCommit";
const uint64_t Blink_PageLoad::kCompositingCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetCompositingCommit(int64_t value) {
  SetMetricInternal(kCompositingCommitNameHash, value);
  return *this;
}

const char Blink_PageLoad::kForcedStyleAndLayoutName[] = "ForcedStyleAndLayout";
const uint64_t Blink_PageLoad::kForcedStyleAndLayoutNameHash;

Blink_PageLoad& Blink_PageLoad::SetForcedStyleAndLayout(int64_t value) {
  SetMetricInternal(kForcedStyleAndLayoutNameHash, value);
  return *this;
}

const char Blink_PageLoad::kHandleInputEventsName[] = "HandleInputEvents";
const uint64_t Blink_PageLoad::kHandleInputEventsNameHash;

Blink_PageLoad& Blink_PageLoad::SetHandleInputEvents(int64_t value) {
  SetMetricInternal(kHandleInputEventsNameHash, value);
  return *this;
}

const char Blink_PageLoad::kHitTestDocumentUpdateName[] = "HitTestDocumentUpdate";
const uint64_t Blink_PageLoad::kHitTestDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetHitTestDocumentUpdate(int64_t value) {
  SetMetricInternal(kHitTestDocumentUpdateNameHash, value);
  return *this;
}

const char Blink_PageLoad::kImplCompositorCommitName[] = "ImplCompositorCommit";
const uint64_t Blink_PageLoad::kImplCompositorCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetImplCompositorCommit(int64_t value) {
  SetMetricInternal(kImplCompositorCommitNameHash, value);
  return *this;
}

const char Blink_PageLoad::kIntersectionObservationName[] = "IntersectionObservation";
const uint64_t Blink_PageLoad::kIntersectionObservationNameHash;

Blink_PageLoad& Blink_PageLoad::SetIntersectionObservation(int64_t value) {
  SetMetricInternal(kIntersectionObservationNameHash, value);
  return *this;
}

const char Blink_PageLoad::kLayoutName[] = "Layout";
const uint64_t Blink_PageLoad::kLayoutNameHash;

Blink_PageLoad& Blink_PageLoad::SetLayout(int64_t value) {
  SetMetricInternal(kLayoutNameHash, value);
  return *this;
}

const char Blink_PageLoad::kMainFrameName[] = "MainFrame";
const uint64_t Blink_PageLoad::kMainFrameNameHash;

Blink_PageLoad& Blink_PageLoad::SetMainFrame(int64_t value) {
  SetMetricInternal(kMainFrameNameHash, value);
  return *this;
}

const char Blink_PageLoad::kPaintName[] = "Paint";
const uint64_t Blink_PageLoad::kPaintNameHash;

Blink_PageLoad& Blink_PageLoad::SetPaint(int64_t value) {
  SetMetricInternal(kPaintNameHash, value);
  return *this;
}

const char Blink_PageLoad::kPrePaintName[] = "PrePaint";
const uint64_t Blink_PageLoad::kPrePaintNameHash;

Blink_PageLoad& Blink_PageLoad::SetPrePaint(int64_t value) {
  SetMetricInternal(kPrePaintNameHash, value);
  return *this;
}

const char Blink_PageLoad::kScrollingCoordinatorName[] = "ScrollingCoordinator";
const uint64_t Blink_PageLoad::kScrollingCoordinatorNameHash;

Blink_PageLoad& Blink_PageLoad::SetScrollingCoordinator(int64_t value) {
  SetMetricInternal(kScrollingCoordinatorNameHash, value);
  return *this;
}

const char Blink_PageLoad::kStyleName[] = "Style";
const uint64_t Blink_PageLoad::kStyleNameHash;

Blink_PageLoad& Blink_PageLoad::SetStyle(int64_t value) {
  SetMetricInternal(kStyleNameHash, value);
  return *this;
}

const char Blink_PageLoad::kUpdateLayersName[] = "UpdateLayers";
const uint64_t Blink_PageLoad::kUpdateLayersNameHash;

Blink_PageLoad& Blink_PageLoad::SetUpdateLayers(int64_t value) {
  SetMetricInternal(kUpdateLayersNameHash, value);
  return *this;
}

const char Blink_PageLoad::kWaitForCommitName[] = "WaitForCommit";
const uint64_t Blink_PageLoad::kWaitForCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetWaitForCommit(int64_t value) {
  SetMetricInternal(kWaitForCommitNameHash, value);
  return *this;
}


const char Blink_Script_AsyncScripts::kEntryName[] = "Blink.Script.AsyncScripts";
const uint64_t Blink_Script_AsyncScripts::kEntryNameHash;

Blink_Script_AsyncScripts::Blink_Script_AsyncScripts(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_Script_AsyncScripts::Blink_Script_AsyncScripts(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_Script_AsyncScripts::~Blink_Script_AsyncScripts() = default;


const char Blink_Script_AsyncScripts::kAsyncScriptCountName[] = "AsyncScriptCount";
const uint64_t Blink_Script_AsyncScripts::kAsyncScriptCountNameHash;

Blink_Script_AsyncScripts& Blink_Script_AsyncScripts::SetAsyncScriptCount(int64_t value) {
  SetMetricInternal(kAsyncScriptCountNameHash, value);
  return *this;
}


const char Blink_UpdateTime::kEntryName[] = "Blink.UpdateTime";
const uint64_t Blink_UpdateTime::kEntryNameHash;

Blink_UpdateTime::Blink_UpdateTime(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_UpdateTime::Blink_UpdateTime(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_UpdateTime::~Blink_UpdateTime() = default;


const char Blink_UpdateTime::kAnimateName[] = "Animate";
const uint64_t Blink_UpdateTime::kAnimateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnimate(int64_t value) {
  SetMetricInternal(kAnimateNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kAnimatePercentageName[] = "AnimatePercentage";
const uint64_t Blink_UpdateTime::kAnimatePercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnimatePercentage(int64_t value) {
  SetMetricInternal(kAnimatePercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kCompositingName[] = "Compositing";
const uint64_t Blink_UpdateTime::kCompositingNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositing(int64_t value) {
  SetMetricInternal(kCompositingNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kCompositingCommitName[] = "CompositingCommit";
const uint64_t Blink_UpdateTime::kCompositingCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommit(int64_t value) {
  SetMetricInternal(kCompositingCommitNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kCompositingCommitPercentageName[] = "CompositingCommitPercentage";
const uint64_t Blink_UpdateTime::kCompositingCommitPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommitPercentage(int64_t value) {
  SetMetricInternal(kCompositingCommitPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kCompositingPercentageName[] = "CompositingPercentage";
const uint64_t Blink_UpdateTime::kCompositingPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingPercentage(int64_t value) {
  SetMetricInternal(kCompositingPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kForcedStyleAndLayoutName[] = "ForcedStyleAndLayout";
const uint64_t Blink_UpdateTime::kForcedStyleAndLayoutNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayout(int64_t value) {
  SetMetricInternal(kForcedStyleAndLayoutNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kForcedStyleAndLayoutPercentageName[] = "ForcedStyleAndLayoutPercentage";
const uint64_t Blink_UpdateTime::kForcedStyleAndLayoutPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayoutPercentage(int64_t value) {
  SetMetricInternal(kForcedStyleAndLayoutPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kHandleInputEventsName[] = "HandleInputEvents";
const uint64_t Blink_UpdateTime::kHandleInputEventsNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEvents(int64_t value) {
  SetMetricInternal(kHandleInputEventsNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kHandleInputEventsPercentageName[] = "HandleInputEventsPercentage";
const uint64_t Blink_UpdateTime::kHandleInputEventsPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEventsPercentage(int64_t value) {
  SetMetricInternal(kHandleInputEventsPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kHitTestDocumentUpdateName[] = "HitTestDocumentUpdate";
const uint64_t Blink_UpdateTime::kHitTestDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdate(int64_t value) {
  SetMetricInternal(kHitTestDocumentUpdateNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kHitTestDocumentUpdatePercentageName[] = "HitTestDocumentUpdatePercentage";
const uint64_t Blink_UpdateTime::kHitTestDocumentUpdatePercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdatePercentage(int64_t value) {
  SetMetricInternal(kHitTestDocumentUpdatePercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kImplCompositorCommitName[] = "ImplCompositorCommit";
const uint64_t Blink_UpdateTime::kImplCompositorCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommit(int64_t value) {
  SetMetricInternal(kImplCompositorCommitNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kImplCompositorCommitPercentageName[] = "ImplCompositorCommitPercentage";
const uint64_t Blink_UpdateTime::kImplCompositorCommitPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommitPercentage(int64_t value) {
  SetMetricInternal(kImplCompositorCommitPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kIntersectionObservationName[] = "IntersectionObservation";
const uint64_t Blink_UpdateTime::kIntersectionObservationNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservation(int64_t value) {
  SetMetricInternal(kIntersectionObservationNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kIntersectionObservationPercentageName[] = "IntersectionObservationPercentage";
const uint64_t Blink_UpdateTime::kIntersectionObservationPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationPercentage(int64_t value) {
  SetMetricInternal(kIntersectionObservationPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kLayoutName[] = "Layout";
const uint64_t Blink_UpdateTime::kLayoutNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLayout(int64_t value) {
  SetMetricInternal(kLayoutNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kLayoutPercentageName[] = "LayoutPercentage";
const uint64_t Blink_UpdateTime::kLayoutPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLayoutPercentage(int64_t value) {
  SetMetricInternal(kLayoutPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kMainFrameName[] = "MainFrame";
const uint64_t Blink_UpdateTime::kMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrame(int64_t value) {
  SetMetricInternal(kMainFrameNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kMainFrameIsBeforeFCPName[] = "MainFrameIsBeforeFCP";
const uint64_t Blink_UpdateTime::kMainFrameIsBeforeFCPNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrameIsBeforeFCP(int64_t value) {
  SetMetricInternal(kMainFrameIsBeforeFCPNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kMainFrameReasonsName[] = "MainFrameReasons";
const uint64_t Blink_UpdateTime::kMainFrameReasonsNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrameReasons(int64_t value) {
  SetMetricInternal(kMainFrameReasonsNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kPaintName[] = "Paint";
const uint64_t Blink_UpdateTime::kPaintNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPaint(int64_t value) {
  SetMetricInternal(kPaintNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kPaintPercentageName[] = "PaintPercentage";
const uint64_t Blink_UpdateTime::kPaintPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPaintPercentage(int64_t value) {
  SetMetricInternal(kPaintPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kPrePaintName[] = "PrePaint";
const uint64_t Blink_UpdateTime::kPrePaintNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPrePaint(int64_t value) {
  SetMetricInternal(kPrePaintNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kPrePaintPercentageName[] = "PrePaintPercentage";
const uint64_t Blink_UpdateTime::kPrePaintPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPrePaintPercentage(int64_t value) {
  SetMetricInternal(kPrePaintPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kScrollingCoordinatorName[] = "ScrollingCoordinator";
const uint64_t Blink_UpdateTime::kScrollingCoordinatorNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetScrollingCoordinator(int64_t value) {
  SetMetricInternal(kScrollingCoordinatorNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kScrollingCoordinatorPercentageName[] = "ScrollingCoordinatorPercentage";
const uint64_t Blink_UpdateTime::kScrollingCoordinatorPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetScrollingCoordinatorPercentage(int64_t value) {
  SetMetricInternal(kScrollingCoordinatorPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kStyleName[] = "Style";
const uint64_t Blink_UpdateTime::kStyleNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetStyle(int64_t value) {
  SetMetricInternal(kStyleNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kStylePercentageName[] = "StylePercentage";
const uint64_t Blink_UpdateTime::kStylePercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetStylePercentage(int64_t value) {
  SetMetricInternal(kStylePercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kUpdateLayersName[] = "UpdateLayers";
const uint64_t Blink_UpdateTime::kUpdateLayersNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayers(int64_t value) {
  SetMetricInternal(kUpdateLayersNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kUpdateLayersPercentageName[] = "UpdateLayersPercentage";
const uint64_t Blink_UpdateTime::kUpdateLayersPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayersPercentage(int64_t value) {
  SetMetricInternal(kUpdateLayersPercentageNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kWaitForCommitName[] = "WaitForCommit";
const uint64_t Blink_UpdateTime::kWaitForCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommit(int64_t value) {
  SetMetricInternal(kWaitForCommitNameHash, value);
  return *this;
}

const char Blink_UpdateTime::kWaitForCommitPercentageName[] = "WaitForCommitPercentage";
const uint64_t Blink_UpdateTime::kWaitForCommitPercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommitPercentage(int64_t value) {
  SetMetricInternal(kWaitForCommitPercentageNameHash, value);
  return *this;
}


const char Blink_UseCounter::kEntryName[] = "Blink.UseCounter";
const uint64_t Blink_UseCounter::kEntryNameHash;

Blink_UseCounter::Blink_UseCounter(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_UseCounter::Blink_UseCounter(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Blink_UseCounter::~Blink_UseCounter() = default;


const char Blink_UseCounter::kFeatureName[] = "Feature";
const uint64_t Blink_UseCounter::kFeatureNameHash;

Blink_UseCounter& Blink_UseCounter::SetFeature(int64_t value) {
  SetMetricInternal(kFeatureNameHash, value);
  return *this;
}

const char Blink_UseCounter::kIsMainFrameFeatureName[] = "IsMainFrameFeature";
const uint64_t Blink_UseCounter::kIsMainFrameFeatureNameHash;

Blink_UseCounter& Blink_UseCounter::SetIsMainFrameFeature(int64_t value) {
  SetMetricInternal(kIsMainFrameFeatureNameHash, value);
  return *this;
}


const char ClickInput::kEntryName[] = "ClickInput";
const uint64_t ClickInput::kEntryNameHash;

ClickInput::ClickInput(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ClickInput::ClickInput(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ClickInput::~ClickInput() = default;


const char ClickInput::kExperimental_ClickInputBurstName[] = "Experimental.ClickInputBurst";
const uint64_t ClickInput::kExperimental_ClickInputBurstNameHash;

ClickInput& ClickInput::SetExperimental_ClickInputBurst(int64_t value) {
  SetMetricInternal(kExperimental_ClickInputBurstNameHash, value);
  return *this;
}


const char Compositor_Rendering::kEntryName[] = "Compositor.Rendering";
const uint64_t Compositor_Rendering::kEntryNameHash;

Compositor_Rendering::Compositor_Rendering(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Compositor_Rendering::Compositor_Rendering(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Compositor_Rendering::~Compositor_Rendering() = default;


const char Compositor_Rendering::kCheckerboardedImagesCountName[] = "CheckerboardedImagesCount";
const uint64_t Compositor_Rendering::kCheckerboardedImagesCountNameHash;

Compositor_Rendering& Compositor_Rendering::SetCheckerboardedImagesCount(int64_t value) {
  SetMetricInternal(kCheckerboardedImagesCountNameHash, value);
  return *this;
}


const char Compositor_UserInteraction::kEntryName[] = "Compositor.UserInteraction";
const uint64_t Compositor_UserInteraction::kEntryNameHash;

Compositor_UserInteraction::Compositor_UserInteraction(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Compositor_UserInteraction::Compositor_UserInteraction(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Compositor_UserInteraction::~Compositor_UserInteraction() = default;


const char Compositor_UserInteraction::kCheckerboardedContentAreaName[] = "CheckerboardedContentArea";
const uint64_t Compositor_UserInteraction::kCheckerboardedContentAreaNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedContentArea(int64_t value) {
  SetMetricInternal(kCheckerboardedContentAreaNameHash, value);
  return *this;
}

const char Compositor_UserInteraction::kCheckerboardedContentAreaRatioName[] = "CheckerboardedContentAreaRatio";
const uint64_t Compositor_UserInteraction::kCheckerboardedContentAreaRatioNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedContentAreaRatio(int64_t value) {
  SetMetricInternal(kCheckerboardedContentAreaRatioNameHash, value);
  return *this;
}

const char Compositor_UserInteraction::kCheckerboardedImagesCountName[] = "CheckerboardedImagesCount";
const uint64_t Compositor_UserInteraction::kCheckerboardedImagesCountNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedImagesCount(int64_t value) {
  SetMetricInternal(kCheckerboardedImagesCountNameHash, value);
  return *this;
}

const char Compositor_UserInteraction::kNumMissingTilesName[] = "NumMissingTiles";
const uint64_t Compositor_UserInteraction::kNumMissingTilesNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetNumMissingTiles(int64_t value) {
  SetMetricInternal(kNumMissingTilesNameHash, value);
  return *this;
}


const char ContactsPicker_ShareStatistics::kEntryName[] = "ContactsPicker.ShareStatistics";
const uint64_t ContactsPicker_ShareStatistics::kEntryNameHash;

ContactsPicker_ShareStatistics::ContactsPicker_ShareStatistics(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContactsPicker_ShareStatistics::ContactsPicker_ShareStatistics(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContactsPicker_ShareStatistics::~ContactsPicker_ShareStatistics() = default;


const char ContactsPicker_ShareStatistics::kPropertiesRequestedName[] = "PropertiesRequested";
const uint64_t ContactsPicker_ShareStatistics::kPropertiesRequestedNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetPropertiesRequested(int64_t value) {
  SetMetricInternal(kPropertiesRequestedNameHash, value);
  return *this;
}

const char ContactsPicker_ShareStatistics::kSelectCountName[] = "SelectCount";
const uint64_t ContactsPicker_ShareStatistics::kSelectCountNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetSelectCount(int64_t value) {
  SetMetricInternal(kSelectCountNameHash, value);
  return *this;
}

const char ContactsPicker_ShareStatistics::kSelectPercentageName[] = "SelectPercentage";
const uint64_t ContactsPicker_ShareStatistics::kSelectPercentageNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetSelectPercentage(int64_t value) {
  SetMetricInternal(kSelectPercentageNameHash, value);
  return *this;
}


const char ContentIndex_Added::kEntryName[] = "ContentIndex.Added";
const uint64_t ContentIndex_Added::kEntryNameHash;

ContentIndex_Added::ContentIndex_Added(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_Added::ContentIndex_Added(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_Added::~ContentIndex_Added() = default;


const char ContentIndex_Added::kCategoryName[] = "Category";
const uint64_t ContentIndex_Added::kCategoryNameHash;

ContentIndex_Added& ContentIndex_Added::SetCategory(int64_t value) {
  SetMetricInternal(kCategoryNameHash, value);
  return *this;
}


const char ContentIndex_DeletedByUser::kEntryName[] = "ContentIndex.DeletedByUser";
const uint64_t ContentIndex_DeletedByUser::kEntryNameHash;

ContentIndex_DeletedByUser::ContentIndex_DeletedByUser(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_DeletedByUser::ContentIndex_DeletedByUser(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_DeletedByUser::~ContentIndex_DeletedByUser() = default;


const char ContentIndex_DeletedByUser::kDeletedName[] = "Deleted";
const uint64_t ContentIndex_DeletedByUser::kDeletedNameHash;

ContentIndex_DeletedByUser& ContentIndex_DeletedByUser::SetDeleted(int64_t value) {
  SetMetricInternal(kDeletedNameHash, value);
  return *this;
}


const char ContentIndex_Opened::kEntryName[] = "ContentIndex.Opened";
const uint64_t ContentIndex_Opened::kEntryNameHash;

ContentIndex_Opened::ContentIndex_Opened(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_Opened::ContentIndex_Opened(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContentIndex_Opened::~ContentIndex_Opened() = default;


const char ContentIndex_Opened::kIsOfflineName[] = "IsOffline";
const uint64_t ContentIndex_Opened::kIsOfflineNameHash;

ContentIndex_Opened& ContentIndex_Opened::SetIsOffline(int64_t value) {
  SetMetricInternal(kIsOfflineNameHash, value);
  return *this;
}


const char ContextMenuAndroid_Selected::kEntryName[] = "ContextMenuAndroid.Selected";
const uint64_t ContextMenuAndroid_Selected::kEntryNameHash;

ContextMenuAndroid_Selected::ContextMenuAndroid_Selected(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextMenuAndroid_Selected::ContextMenuAndroid_Selected(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextMenuAndroid_Selected::~ContextMenuAndroid_Selected() = default;


const char ContextMenuAndroid_Selected::kActionName[] = "Action";
const uint64_t ContextMenuAndroid_Selected::kActionNameHash;

ContextMenuAndroid_Selected& ContextMenuAndroid_Selected::SetAction(int64_t value) {
  SetMetricInternal(kActionNameHash, value);
  return *this;
}


const char ContextMenuAndroid_Shown::kEntryName[] = "ContextMenuAndroid.Shown";
const uint64_t ContextMenuAndroid_Shown::kEntryNameHash;

ContextMenuAndroid_Shown::ContextMenuAndroid_Shown(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextMenuAndroid_Shown::ContextMenuAndroid_Shown(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextMenuAndroid_Shown::~ContextMenuAndroid_Shown() = default;


const char ContextMenuAndroid_Shown::kSearchByImageName[] = "SearchByImage";
const uint64_t ContextMenuAndroid_Shown::kSearchByImageNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetSearchByImage(int64_t value) {
  SetMetricInternal(kSearchByImageNameHash, value);
  return *this;
}

const char ContextMenuAndroid_Shown::kSearchWithGoogleLensName[] = "SearchWithGoogleLens";
const uint64_t ContextMenuAndroid_Shown::kSearchWithGoogleLensNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetSearchWithGoogleLens(int64_t value) {
  SetMetricInternal(kSearchWithGoogleLensNameHash, value);
  return *this;
}

const char ContextMenuAndroid_Shown::kShopWithGoogleLensName[] = "ShopWithGoogleLens";
const uint64_t ContextMenuAndroid_Shown::kShopWithGoogleLensNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetShopWithGoogleLens(int64_t value) {
  SetMetricInternal(kShopWithGoogleLensNameHash, value);
  return *this;
}


const char ContextualSearch::kEntryName[] = "ContextualSearch";
const uint64_t ContextualSearch::kEntryNameHash;

ContextualSearch::ContextualSearch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextualSearch::ContextualSearch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ContextualSearch::~ContextualSearch() = default;


const char ContextualSearch::kDidOptInName[] = "DidOptIn";
const uint64_t ContextualSearch::kDidOptInNameHash;

ContextualSearch& ContextualSearch::SetDidOptIn(int64_t value) {
  SetMetricInternal(kDidOptInNameHash, value);
  return *this;
}

const char ContextualSearch::kDurationAfterScrollMsName[] = "DurationAfterScrollMs";
const uint64_t ContextualSearch::kDurationAfterScrollMsNameHash;

ContextualSearch& ContextualSearch::SetDurationAfterScrollMs(int64_t value) {
  SetMetricInternal(kDurationAfterScrollMsNameHash, value);
  return *this;
}

const char ContextualSearch::kEntityImpressionsCountName[] = "EntityImpressionsCount";
const uint64_t ContextualSearch::kEntityImpressionsCountNameHash;

ContextualSearch& ContextualSearch::SetEntityImpressionsCount(int64_t value) {
  SetMetricInternal(kEntityImpressionsCountNameHash, value);
  return *this;
}

const char ContextualSearch::kEntityOpensCountName[] = "EntityOpensCount";
const uint64_t ContextualSearch::kEntityOpensCountNameHash;

ContextualSearch& ContextualSearch::SetEntityOpensCount(int64_t value) {
  SetMetricInternal(kEntityOpensCountNameHash, value);
  return *this;
}

const char ContextualSearch::kFontSizeName[] = "FontSize";
const uint64_t ContextualSearch::kFontSizeNameHash;

ContextualSearch& ContextualSearch::SetFontSize(int64_t value) {
  SetMetricInternal(kFontSizeNameHash, value);
  return *this;
}

const char ContextualSearch::kIsEntityName[] = "IsEntity";
const uint64_t ContextualSearch::kIsEntityNameHash;

ContextualSearch& ContextualSearch::SetIsEntity(int64_t value) {
  SetMetricInternal(kIsEntityNameHash, value);
  return *this;
}

const char ContextualSearch::kIsEntityEligibleName[] = "IsEntityEligible";
const uint64_t ContextualSearch::kIsEntityEligibleNameHash;

ContextualSearch& ContextualSearch::SetIsEntityEligible(int64_t value) {
  SetMetricInternal(kIsEntityEligibleNameHash, value);
  return *this;
}

const char ContextualSearch::kIsHttpName[] = "IsHttp";
const uint64_t ContextualSearch::kIsHttpNameHash;

ContextualSearch& ContextualSearch::SetIsHttp(int64_t value) {
  SetMetricInternal(kIsHttpNameHash, value);
  return *this;
}

const char ContextualSearch::kIsLanguageMismatchName[] = "IsLanguageMismatch";
const uint64_t ContextualSearch::kIsLanguageMismatchNameHash;

ContextualSearch& ContextualSearch::SetIsLanguageMismatch(int64_t value) {
  SetMetricInternal(kIsLanguageMismatchNameHash, value);
  return *this;
}

const char ContextualSearch::kIsLongWordName[] = "IsLongWord";
const uint64_t ContextualSearch::kIsLongWordNameHash;

ContextualSearch& ContextualSearch::SetIsLongWord(int64_t value) {
  SetMetricInternal(kIsLongWordNameHash, value);
  return *this;
}

const char ContextualSearch::kIsSecondTapOverrideName[] = "IsSecondTapOverride";
const uint64_t ContextualSearch::kIsSecondTapOverrideNameHash;

ContextualSearch& ContextualSearch::SetIsSecondTapOverride(int64_t value) {
  SetMetricInternal(kIsSecondTapOverrideNameHash, value);
  return *this;
}

const char ContextualSearch::kIsShortWordName[] = "IsShortWord";
const uint64_t ContextualSearch::kIsShortWordNameHash;

ContextualSearch& ContextualSearch::SetIsShortWord(int64_t value) {
  SetMetricInternal(kIsShortWordNameHash, value);
  return *this;
}

const char ContextualSearch::kIsWordEdgeName[] = "IsWordEdge";
const uint64_t ContextualSearch::kIsWordEdgeNameHash;

ContextualSearch& ContextualSearch::SetIsWordEdge(int64_t value) {
  SetMetricInternal(kIsWordEdgeNameHash, value);
  return *this;
}

const char ContextualSearch::kOpenCountName[] = "OpenCount";
const uint64_t ContextualSearch::kOpenCountNameHash;

ContextualSearch& ContextualSearch::SetOpenCount(int64_t value) {
  SetMetricInternal(kOpenCountNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeRankerDidPredictName[] = "OutcomeRankerDidPredict";
const uint64_t ContextualSearch::kOutcomeRankerDidPredictNameHash;

ContextualSearch& ContextualSearch::SetOutcomeRankerDidPredict(int64_t value) {
  SetMetricInternal(kOutcomeRankerDidPredictNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeRankerPredictionName[] = "OutcomeRankerPrediction";
const uint64_t ContextualSearch::kOutcomeRankerPredictionNameHash;

ContextualSearch& ContextualSearch::SetOutcomeRankerPrediction(int64_t value) {
  SetMetricInternal(kOutcomeRankerPredictionNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeRankerPredictionScoreName[] = "OutcomeRankerPredictionScore";
const uint64_t ContextualSearch::kOutcomeRankerPredictionScoreNameHash;

ContextualSearch& ContextualSearch::SetOutcomeRankerPredictionScore(int64_t value) {
  SetMetricInternal(kOutcomeRankerPredictionScoreNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeWasCardsDataShownName[] = "OutcomeWasCardsDataShown";
const uint64_t ContextualSearch::kOutcomeWasCardsDataShownNameHash;

ContextualSearch& ContextualSearch::SetOutcomeWasCardsDataShown(int64_t value) {
  SetMetricInternal(kOutcomeWasCardsDataShownNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeWasPanelOpenedName[] = "OutcomeWasPanelOpened";
const uint64_t ContextualSearch::kOutcomeWasPanelOpenedNameHash;

ContextualSearch& ContextualSearch::SetOutcomeWasPanelOpened(int64_t value) {
  SetMetricInternal(kOutcomeWasPanelOpenedNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeWasQuickActionClickedName[] = "OutcomeWasQuickActionClicked";
const uint64_t ContextualSearch::kOutcomeWasQuickActionClickedNameHash;

ContextualSearch& ContextualSearch::SetOutcomeWasQuickActionClicked(int64_t value) {
  SetMetricInternal(kOutcomeWasQuickActionClickedNameHash, value);
  return *this;
}

const char ContextualSearch::kOutcomeWasQuickAnswerSeenName[] = "OutcomeWasQuickAnswerSeen";
const uint64_t ContextualSearch::kOutcomeWasQuickAnswerSeenNameHash;

ContextualSearch& ContextualSearch::SetOutcomeWasQuickAnswerSeen(int64_t value) {
  SetMetricInternal(kOutcomeWasQuickAnswerSeenNameHash, value);
  return *this;
}

const char ContextualSearch::kPortionOfElementName[] = "PortionOfElement";
const uint64_t ContextualSearch::kPortionOfElementNameHash;

ContextualSearch& ContextualSearch::SetPortionOfElement(int64_t value) {
  SetMetricInternal(kPortionOfElementNameHash, value);
  return *this;
}

const char ContextualSearch::kPrevious28DayCtrPercentName[] = "Previous28DayCtrPercent";
const uint64_t ContextualSearch::kPrevious28DayCtrPercentNameHash;

ContextualSearch& ContextualSearch::SetPrevious28DayCtrPercent(int64_t value) {
  SetMetricInternal(kPrevious28DayCtrPercentNameHash, value);
  return *this;
}

const char ContextualSearch::kPrevious28DayImpressionsCountName[] = "Previous28DayImpressionsCount";
const uint64_t ContextualSearch::kPrevious28DayImpressionsCountNameHash;

ContextualSearch& ContextualSearch::SetPrevious28DayImpressionsCount(int64_t value) {
  SetMetricInternal(kPrevious28DayImpressionsCountNameHash, value);
  return *this;
}

const char ContextualSearch::kPreviousWeekCtrPercentName[] = "PreviousWeekCtrPercent";
const uint64_t ContextualSearch::kPreviousWeekCtrPercentNameHash;

ContextualSearch& ContextualSearch::SetPreviousWeekCtrPercent(int64_t value) {
  SetMetricInternal(kPreviousWeekCtrPercentNameHash, value);
  return *this;
}

const char ContextualSearch::kPreviousWeekImpressionsCountName[] = "PreviousWeekImpressionsCount";
const uint64_t ContextualSearch::kPreviousWeekImpressionsCountNameHash;

ContextualSearch& ContextualSearch::SetPreviousWeekImpressionsCount(int64_t value) {
  SetMetricInternal(kPreviousWeekImpressionsCountNameHash, value);
  return *this;
}

const char ContextualSearch::kQuickActionImpressionsCountName[] = "QuickActionImpressionsCount";
const uint64_t ContextualSearch::kQuickActionImpressionsCountNameHash;

ContextualSearch& ContextualSearch::SetQuickActionImpressionsCount(int64_t value) {
  SetMetricInternal(kQuickActionImpressionsCountNameHash, value);
  return *this;
}

const char ContextualSearch::kQuickActionsIgnoredName[] = "QuickActionsIgnored";
const uint64_t ContextualSearch::kQuickActionsIgnoredNameHash;

ContextualSearch& ContextualSearch::SetQuickActionsIgnored(int64_t value) {
  SetMetricInternal(kQuickActionsIgnoredNameHash, value);
  return *this;
}

const char ContextualSearch::kQuickActionsTakenName[] = "QuickActionsTaken";
const uint64_t ContextualSearch::kQuickActionsTakenNameHash;

ContextualSearch& ContextualSearch::SetQuickActionsTaken(int64_t value) {
  SetMetricInternal(kQuickActionsTakenNameHash, value);
  return *this;
}

const char ContextualSearch::kQuickAnswerCountName[] = "QuickAnswerCount";
const uint64_t ContextualSearch::kQuickAnswerCountNameHash;

ContextualSearch& ContextualSearch::SetQuickAnswerCount(int64_t value) {
  SetMetricInternal(kQuickAnswerCountNameHash, value);
  return *this;
}

const char ContextualSearch::kScreenTopDpsName[] = "ScreenTopDps";
const uint64_t ContextualSearch::kScreenTopDpsNameHash;

ContextualSearch& ContextualSearch::SetScreenTopDps(int64_t value) {
  SetMetricInternal(kScreenTopDpsNameHash, value);
  return *this;
}

const char ContextualSearch::kTapCountName[] = "TapCount";
const uint64_t ContextualSearch::kTapCountNameHash;

ContextualSearch& ContextualSearch::SetTapCount(int64_t value) {
  SetMetricInternal(kTapCountNameHash, value);
  return *this;
}

const char ContextualSearch::kTapDurationMsName[] = "TapDurationMs";
const uint64_t ContextualSearch::kTapDurationMsNameHash;

ContextualSearch& ContextualSearch::SetTapDurationMs(int64_t value) {
  SetMetricInternal(kTapDurationMsNameHash, value);
  return *this;
}

const char ContextualSearch::kWasScreenBottomName[] = "WasScreenBottom";
const uint64_t ContextualSearch::kWasScreenBottomNameHash;

ContextualSearch& ContextualSearch::SetWasScreenBottom(int64_t value) {
  SetMetricInternal(kWasScreenBottomNameHash, value);
  return *this;
}


const char CPUUsageMeasurement::kEntryName[] = "CPUUsageMeasurement";
const uint64_t CPUUsageMeasurement::kEntryNameHash;

CPUUsageMeasurement::CPUUsageMeasurement(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

CPUUsageMeasurement::CPUUsageMeasurement(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

CPUUsageMeasurement::~CPUUsageMeasurement() = default;


const char CPUUsageMeasurement::kCPUUsageName[] = "CPUUsage";
const uint64_t CPUUsageMeasurement::kCPUUsageNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetCPUUsage(int64_t value) {
  SetMetricInternal(kCPUUsageNameHash, value);
  return *this;
}

const char CPUUsageMeasurement::kEventTypeName[] = "EventType";
const uint64_t CPUUsageMeasurement::kEventTypeNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetEventType(int64_t value) {
  SetMetricInternal(kEventTypeNameHash, value);
  return *this;
}

const char CPUUsageMeasurement::kIsVisibleName[] = "IsVisible";
const uint64_t CPUUsageMeasurement::kIsVisibleNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetIsVisible(int64_t value) {
  SetMetricInternal(kIsVisibleNameHash, value);
  return *this;
}

const char CPUUsageMeasurement::kNumberOfCoresidentTabsName[] = "NumberOfCoresidentTabs";
const uint64_t CPUUsageMeasurement::kNumberOfCoresidentTabsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetNumberOfCoresidentTabs(int64_t value) {
  SetMetricInternal(kNumberOfCoresidentTabsNameHash, value);
  return *this;
}

const char CPUUsageMeasurement::kObservationWindowSizeMsName[] = "ObservationWindowSizeMs";
const uint64_t CPUUsageMeasurement::kObservationWindowSizeMsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetObservationWindowSizeMs(int64_t value) {
  SetMetricInternal(kObservationWindowSizeMsNameHash, value);
  return *this;
}

const char CPUUsageMeasurement::kProcessUptimeMsName[] = "ProcessUptimeMs";
const uint64_t CPUUsageMeasurement::kProcessUptimeMsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetProcessUptimeMs(int64_t value) {
  SetMetricInternal(kProcessUptimeMsNameHash, value);
  return *this;
}


const char DataReductionProxy::kEntryName[] = "DataReductionProxy";
const uint64_t DataReductionProxy::kEntryNameHash;

DataReductionProxy::DataReductionProxy(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

DataReductionProxy::DataReductionProxy(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

DataReductionProxy::~DataReductionProxy() = default;


const char DataReductionProxy::kDataSaverPageUUIDName[] = "DataSaverPageUUID";
const uint64_t DataReductionProxy::kDataSaverPageUUIDNameHash;

DataReductionProxy& DataReductionProxy::SetDataSaverPageUUID(int64_t value) {
  SetMetricInternal(kDataSaverPageUUIDNameHash, value);
  return *this;
}

const char DataReductionProxy::kEstimatedOriginalNetworkBytesName[] = "EstimatedOriginalNetworkBytes";
const uint64_t DataReductionProxy::kEstimatedOriginalNetworkBytesNameHash;

DataReductionProxy& DataReductionProxy::SetEstimatedOriginalNetworkBytes(int64_t value) {
  SetMetricInternal(kEstimatedOriginalNetworkBytesNameHash, value);
  return *this;
}


const char Document_OutliveTimeAfterShutdown::kEntryName[] = "Document.OutliveTimeAfterShutdown";
const uint64_t Document_OutliveTimeAfterShutdown::kEntryNameHash;

Document_OutliveTimeAfterShutdown::Document_OutliveTimeAfterShutdown(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Document_OutliveTimeAfterShutdown::Document_OutliveTimeAfterShutdown(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Document_OutliveTimeAfterShutdown::~Document_OutliveTimeAfterShutdown() = default;


const char Document_OutliveTimeAfterShutdown::kGCCountName[] = "GCCount";
const uint64_t Document_OutliveTimeAfterShutdown::kGCCountNameHash;

Document_OutliveTimeAfterShutdown& Document_OutliveTimeAfterShutdown::SetGCCount(int64_t value) {
  SetMetricInternal(kGCCountNameHash, value);
  return *this;
}


const char DocumentCreated::kEntryName[] = "DocumentCreated";
const uint64_t DocumentCreated::kEntryNameHash;

DocumentCreated::DocumentCreated(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

DocumentCreated::DocumentCreated(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

DocumentCreated::~DocumentCreated() = default;


const char DocumentCreated::kIsCrossOriginFrameName[] = "IsCrossOriginFrame";
const uint64_t DocumentCreated::kIsCrossOriginFrameNameHash;

DocumentCreated& DocumentCreated::SetIsCrossOriginFrame(int64_t value) {
  SetMetricInternal(kIsCrossOriginFrameNameHash, value);
  return *this;
}

const char DocumentCreated::kIsMainFrameName[] = "IsMainFrame";
const uint64_t DocumentCreated::kIsMainFrameNameHash;

DocumentCreated& DocumentCreated::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char DocumentCreated::kNavigationSourceIdName[] = "NavigationSourceId";
const uint64_t DocumentCreated::kNavigationSourceIdNameHash;

DocumentCreated& DocumentCreated::SetNavigationSourceId(int64_t value) {
  SetMetricInternal(kNavigationSourceIdNameHash, value);
  return *this;
}


const char Download_Completed::kEntryName[] = "Download.Completed";
const uint64_t Download_Completed::kEntryNameHash;

Download_Completed::Download_Completed(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Completed::Download_Completed(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Completed::~Download_Completed() = default;


const char Download_Completed::kBytesWastedName[] = "BytesWasted";
const uint64_t Download_Completed::kBytesWastedNameHash;

Download_Completed& Download_Completed::SetBytesWasted(int64_t value) {
  SetMetricInternal(kBytesWastedNameHash, value);
  return *this;
}

const char Download_Completed::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Completed::kDownloadIdNameHash;

Download_Completed& Download_Completed::SetDownloadId(int64_t value) {
  SetMetricInternal(kDownloadIdNameHash, value);
  return *this;
}

const char Download_Completed::kResultingFileSizeName[] = "ResultingFileSize";
const uint64_t Download_Completed::kResultingFileSizeNameHash;

Download_Completed& Download_Completed::SetResultingFileSize(int64_t value) {
  SetMetricInternal(kResultingFileSizeNameHash, value);
  return *this;
}

const char Download_Completed::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Completed::kTimeSinceStartNameHash;

Download_Completed& Download_Completed::SetTimeSinceStart(int64_t value) {
  SetMetricInternal(kTimeSinceStartNameHash, value);
  return *this;
}


const char Download_Interrupted::kEntryName[] = "Download.Interrupted";
const uint64_t Download_Interrupted::kEntryNameHash;

Download_Interrupted::Download_Interrupted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Interrupted::Download_Interrupted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Interrupted::~Download_Interrupted() = default;


const char Download_Interrupted::kBytesWastedName[] = "BytesWasted";
const uint64_t Download_Interrupted::kBytesWastedNameHash;

Download_Interrupted& Download_Interrupted::SetBytesWasted(int64_t value) {
  SetMetricInternal(kBytesWastedNameHash, value);
  return *this;
}

const char Download_Interrupted::kChangeInFileSizeName[] = "ChangeInFileSize";
const uint64_t Download_Interrupted::kChangeInFileSizeNameHash;

Download_Interrupted& Download_Interrupted::SetChangeInFileSize(int64_t value) {
  SetMetricInternal(kChangeInFileSizeNameHash, value);
  return *this;
}

const char Download_Interrupted::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Interrupted::kDownloadIdNameHash;

Download_Interrupted& Download_Interrupted::SetDownloadId(int64_t value) {
  SetMetricInternal(kDownloadIdNameHash, value);
  return *this;
}

const char Download_Interrupted::kReasonName[] = "Reason";
const uint64_t Download_Interrupted::kReasonNameHash;

Download_Interrupted& Download_Interrupted::SetReason(int64_t value) {
  SetMetricInternal(kReasonNameHash, value);
  return *this;
}

const char Download_Interrupted::kResultingFileSizeName[] = "ResultingFileSize";
const uint64_t Download_Interrupted::kResultingFileSizeNameHash;

Download_Interrupted& Download_Interrupted::SetResultingFileSize(int64_t value) {
  SetMetricInternal(kResultingFileSizeNameHash, value);
  return *this;
}

const char Download_Interrupted::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Interrupted::kTimeSinceStartNameHash;

Download_Interrupted& Download_Interrupted::SetTimeSinceStart(int64_t value) {
  SetMetricInternal(kTimeSinceStartNameHash, value);
  return *this;
}


const char Download_Resumed::kEntryName[] = "Download.Resumed";
const uint64_t Download_Resumed::kEntryNameHash;

Download_Resumed::Download_Resumed(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Resumed::Download_Resumed(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Resumed::~Download_Resumed() = default;


const char Download_Resumed::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Resumed::kDownloadIdNameHash;

Download_Resumed& Download_Resumed::SetDownloadId(int64_t value) {
  SetMetricInternal(kDownloadIdNameHash, value);
  return *this;
}

const char Download_Resumed::kModeName[] = "Mode";
const uint64_t Download_Resumed::kModeNameHash;

Download_Resumed& Download_Resumed::SetMode(int64_t value) {
  SetMetricInternal(kModeNameHash, value);
  return *this;
}

const char Download_Resumed::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Resumed::kTimeSinceStartNameHash;

Download_Resumed& Download_Resumed::SetTimeSinceStart(int64_t value) {
  SetMetricInternal(kTimeSinceStartNameHash, value);
  return *this;
}


const char Download_Started::kEntryName[] = "Download.Started";
const uint64_t Download_Started::kEntryNameHash;

Download_Started::Download_Started(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Started::Download_Started(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Download_Started::~Download_Started() = default;


const char Download_Started::kDownloadConnectionSecurityName[] = "DownloadConnectionSecurity";
const uint64_t Download_Started::kDownloadConnectionSecurityNameHash;

Download_Started& Download_Started::SetDownloadConnectionSecurity(int64_t value) {
  SetMetricInternal(kDownloadConnectionSecurityNameHash, value);
  return *this;
}

const char Download_Started::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Started::kDownloadIdNameHash;

Download_Started& Download_Started::SetDownloadId(int64_t value) {
  SetMetricInternal(kDownloadIdNameHash, value);
  return *this;
}

const char Download_Started::kDownloadSourceName[] = "DownloadSource";
const uint64_t Download_Started::kDownloadSourceNameHash;

Download_Started& Download_Started::SetDownloadSource(int64_t value) {
  SetMetricInternal(kDownloadSourceNameHash, value);
  return *this;
}

const char Download_Started::kFileTypeName[] = "FileType";
const uint64_t Download_Started::kFileTypeNameHash;

Download_Started& Download_Started::SetFileType(int64_t value) {
  SetMetricInternal(kFileTypeNameHash, value);
  return *this;
}

const char Download_Started::kIsSameHostDownloadName[] = "IsSameHostDownload";
const uint64_t Download_Started::kIsSameHostDownloadNameHash;

Download_Started& Download_Started::SetIsSameHostDownload(int64_t value) {
  SetMetricInternal(kIsSameHostDownloadNameHash, value);
  return *this;
}


const char Event_ScrollBegin_Touch::kEntryName[] = "Event.ScrollBegin.Touch";
const uint64_t Event_ScrollBegin_Touch::kEntryNameHash;

Event_ScrollBegin_Touch::Event_ScrollBegin_Touch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollBegin_Touch::Event_ScrollBegin_Touch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollBegin_Touch::~Event_ScrollBegin_Touch() = default;


const char Event_ScrollBegin_Touch::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollBegin_Touch::kIsMainThreadNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetIsMainThread(int64_t value) {
  SetMetricInternal(kIsMainThreadNameHash, value);
  return *this;
}

const char Event_ScrollBegin_Touch::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollBegin_Touch::kTimeToHandledNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetTimeToHandled(int64_t value) {
  SetMetricInternal(kTimeToHandledNameHash, value);
  return *this;
}

const char Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetTimeToScrollUpdateSwapBegin(int64_t value) {
  SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
  return *this;
}


const char Event_ScrollBegin_Wheel::kEntryName[] = "Event.ScrollBegin.Wheel";
const uint64_t Event_ScrollBegin_Wheel::kEntryNameHash;

Event_ScrollBegin_Wheel::Event_ScrollBegin_Wheel(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollBegin_Wheel::Event_ScrollBegin_Wheel(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollBegin_Wheel::~Event_ScrollBegin_Wheel() = default;


const char Event_ScrollBegin_Wheel::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollBegin_Wheel::kIsMainThreadNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetIsMainThread(int64_t value) {
  SetMetricInternal(kIsMainThreadNameHash, value);
  return *this;
}

const char Event_ScrollBegin_Wheel::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollBegin_Wheel::kTimeToHandledNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetTimeToHandled(int64_t value) {
  SetMetricInternal(kTimeToHandledNameHash, value);
  return *this;
}

const char Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetTimeToScrollUpdateSwapBegin(int64_t value) {
  SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
  return *this;
}


const char Event_ScrollUpdate_Touch::kEntryName[] = "Event.ScrollUpdate.Touch";
const uint64_t Event_ScrollUpdate_Touch::kEntryNameHash;

Event_ScrollUpdate_Touch::Event_ScrollUpdate_Touch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollUpdate_Touch::Event_ScrollUpdate_Touch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollUpdate_Touch::~Event_ScrollUpdate_Touch() = default;


const char Event_ScrollUpdate_Touch::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollUpdate_Touch::kIsMainThreadNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetIsMainThread(int64_t value) {
  SetMetricInternal(kIsMainThreadNameHash, value);
  return *this;
}

const char Event_ScrollUpdate_Touch::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollUpdate_Touch::kTimeToHandledNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetTimeToHandled(int64_t value) {
  SetMetricInternal(kTimeToHandledNameHash, value);
  return *this;
}

const char Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetTimeToScrollUpdateSwapBegin(int64_t value) {
  SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
  return *this;
}


const char Event_ScrollUpdate_Wheel::kEntryName[] = "Event.ScrollUpdate.Wheel";
const uint64_t Event_ScrollUpdate_Wheel::kEntryNameHash;

Event_ScrollUpdate_Wheel::Event_ScrollUpdate_Wheel(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollUpdate_Wheel::Event_ScrollUpdate_Wheel(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Event_ScrollUpdate_Wheel::~Event_ScrollUpdate_Wheel() = default;


const char Event_ScrollUpdate_Wheel::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollUpdate_Wheel::kIsMainThreadNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetIsMainThread(int64_t value) {
  SetMetricInternal(kIsMainThreadNameHash, value);
  return *this;
}

const char Event_ScrollUpdate_Wheel::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollUpdate_Wheel::kTimeToHandledNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetTimeToHandled(int64_t value) {
  SetMetricInternal(kTimeToHandledNameHash, value);
  return *this;
}

const char Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetTimeToScrollUpdateSwapBegin(int64_t value) {
  SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
  return *this;
}


const char Extensions_CrossOriginFetchFromContentScript3::kEntryName[] = "Extensions.CrossOriginFetchFromContentScript3";
const uint64_t Extensions_CrossOriginFetchFromContentScript3::kEntryNameHash;

Extensions_CrossOriginFetchFromContentScript3::Extensions_CrossOriginFetchFromContentScript3(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Extensions_CrossOriginFetchFromContentScript3::Extensions_CrossOriginFetchFromContentScript3(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Extensions_CrossOriginFetchFromContentScript3::~Extensions_CrossOriginFetchFromContentScript3() = default;


const char Extensions_CrossOriginFetchFromContentScript3::kEventHappenedName[] = "EventHappened";
const uint64_t Extensions_CrossOriginFetchFromContentScript3::kEventHappenedNameHash;

Extensions_CrossOriginFetchFromContentScript3& Extensions_CrossOriginFetchFromContentScript3::SetEventHappened(int64_t value) {
  SetMetricInternal(kEventHappenedNameHash, value);
  return *this;
}


const char FontMatchAttempts::kEntryName[] = "FontMatchAttempts";
const uint64_t FontMatchAttempts::kEntryNameHash;

FontMatchAttempts::FontMatchAttempts(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

FontMatchAttempts::FontMatchAttempts(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

FontMatchAttempts::~FontMatchAttempts() = default;


const char FontMatchAttempts::kLoadContextName[] = "LoadContext";
const uint64_t FontMatchAttempts::kLoadContextNameHash;

FontMatchAttempts& FontMatchAttempts::SetLoadContext(int64_t value) {
  SetMetricInternal(kLoadContextNameHash, value);
  return *this;
}

const char FontMatchAttempts::kLocalFontFailuresName[] = "LocalFontFailures";
const uint64_t FontMatchAttempts::kLocalFontFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetLocalFontFailures(int64_t value) {
  SetMetricInternal(kLocalFontFailuresNameHash, value);
  return *this;
}

const char FontMatchAttempts::kLocalFontSuccessesName[] = "LocalFontSuccesses";
const uint64_t FontMatchAttempts::kLocalFontSuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetLocalFontSuccesses(int64_t value) {
  SetMetricInternal(kLocalFontSuccessesNameHash, value);
  return *this;
}

const char FontMatchAttempts::kSystemFontFamilyFailuresName[] = "SystemFontFamilyFailures";
const uint64_t FontMatchAttempts::kSystemFontFamilyFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilyFailures(int64_t value) {
  SetMetricInternal(kSystemFontFamilyFailuresNameHash, value);
  return *this;
}

const char FontMatchAttempts::kSystemFontFamilySuccessesName[] = "SystemFontFamilySuccesses";
const uint64_t FontMatchAttempts::kSystemFontFamilySuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilySuccesses(int64_t value) {
  SetMetricInternal(kSystemFontFamilySuccessesNameHash, value);
  return *this;
}

const char FontMatchAttempts::kWebFontFamilyFailuresName[] = "WebFontFamilyFailures";
const uint64_t FontMatchAttempts::kWebFontFamilyFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetWebFontFamilyFailures(int64_t value) {
  SetMetricInternal(kWebFontFamilyFailuresNameHash, value);
  return *this;
}

const char FontMatchAttempts::kWebFontFamilySuccessesName[] = "WebFontFamilySuccesses";
const uint64_t FontMatchAttempts::kWebFontFamilySuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetWebFontFamilySuccesses(int64_t value) {
  SetMetricInternal(kWebFontFamilySuccessesNameHash, value);
  return *this;
}


const char GeneratedNavigation::kEntryName[] = "GeneratedNavigation";
const uint64_t GeneratedNavigation::kEntryNameHash;

GeneratedNavigation::GeneratedNavigation(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

GeneratedNavigation::GeneratedNavigation(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

GeneratedNavigation::~GeneratedNavigation() = default;


const char GeneratedNavigation::kFinalURLIsDefaultSearchEngineName[] = "FinalURLIsDefaultSearchEngine";
const uint64_t GeneratedNavigation::kFinalURLIsDefaultSearchEngineNameHash;

GeneratedNavigation& GeneratedNavigation::SetFinalURLIsDefaultSearchEngine(int64_t value) {
  SetMetricInternal(kFinalURLIsDefaultSearchEngineNameHash, value);
  return *this;
}

const char GeneratedNavigation::kFinalURLIsHomePageName[] = "FinalURLIsHomePage";
const uint64_t GeneratedNavigation::kFinalURLIsHomePageNameHash;

GeneratedNavigation& GeneratedNavigation::SetFinalURLIsHomePage(int64_t value) {
  SetMetricInternal(kFinalURLIsHomePageNameHash, value);
  return *this;
}

const char GeneratedNavigation::kFirstURLIsDefaultSearchEngineName[] = "FirstURLIsDefaultSearchEngine";
const uint64_t GeneratedNavigation::kFirstURLIsDefaultSearchEngineNameHash;

GeneratedNavigation& GeneratedNavigation::SetFirstURLIsDefaultSearchEngine(int64_t value) {
  SetMetricInternal(kFirstURLIsDefaultSearchEngineNameHash, value);
  return *this;
}

const char GeneratedNavigation::kFirstURLIsHomePageName[] = "FirstURLIsHomePage";
const uint64_t GeneratedNavigation::kFirstURLIsHomePageNameHash;

GeneratedNavigation& GeneratedNavigation::SetFirstURLIsHomePage(int64_t value) {
  SetMetricInternal(kFirstURLIsHomePageNameHash, value);
  return *this;
}


const char GoogleDocsOfflineExtension::kEntryName[] = "GoogleDocsOfflineExtension";
const uint64_t GoogleDocsOfflineExtension::kEntryNameHash;

GoogleDocsOfflineExtension::GoogleDocsOfflineExtension(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

GoogleDocsOfflineExtension::GoogleDocsOfflineExtension(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

GoogleDocsOfflineExtension::~GoogleDocsOfflineExtension() = default;


const char GoogleDocsOfflineExtension::kResourceRequestedName[] = "ResourceRequested";
const uint64_t GoogleDocsOfflineExtension::kResourceRequestedNameHash;

GoogleDocsOfflineExtension& GoogleDocsOfflineExtension::SetResourceRequested(int64_t value) {
  SetMetricInternal(kResourceRequestedNameHash, value);
  return *this;
}


const char Graphics_Smoothness_EventLatency::kEntryName[] = "Graphics.Smoothness.EventLatency";
const uint64_t Graphics_Smoothness_EventLatency::kEntryNameHash;

Graphics_Smoothness_EventLatency::Graphics_Smoothness_EventLatency(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_EventLatency::Graphics_Smoothness_EventLatency(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_EventLatency::~Graphics_Smoothness_EventLatency() = default;


const char Graphics_Smoothness_EventLatency::kActivationName[] = "Activation";
const uint64_t Graphics_Smoothness_EventLatency::kActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetActivation(int64_t value) {
  SetMetricInternal(kActivationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameName[] = "BeginImplFrameToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetBeginImplFrameToSendBeginMainFrame(int64_t value) {
  SetMetricInternal(kBeginImplFrameToSendBeginMainFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kBrowserToRendererCompositorName[] = "BrowserToRendererCompositor";
const uint64_t Graphics_Smoothness_EventLatency::kBrowserToRendererCompositorNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetBrowserToRendererCompositor(int64_t value) {
  SetMetricInternal(kBrowserToRendererCompositorNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kCommitName[] = "Commit";
const uint64_t Graphics_Smoothness_EventLatency::kCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetCommit(int64_t value) {
  SetMetricInternal(kCommitNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameName[] = "EndActivateToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEndActivateToSubmitCompositorFrame(int64_t value) {
  SetMetricInternal(kEndActivateToSubmitCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kEndCommitToActivationName[] = "EndCommitToActivation";
const uint64_t Graphics_Smoothness_EventLatency::kEndCommitToActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEndCommitToActivation(int64_t value) {
  SetMetricInternal(kEndCommitToActivationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kEventTypeName[] = "EventType";
const uint64_t Graphics_Smoothness_EventLatency::kEventTypeNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEventType(int64_t value) {
  SetMetricInternal(kEventTypeNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kScrollInputTypeName[] = "ScrollInputType";
const uint64_t Graphics_Smoothness_EventLatency::kScrollInputTypeNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetScrollInputType(int64_t value) {
  SetMetricInternal(kScrollInputTypeNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitName[] = "SendBeginMainFrameToCommit";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit(int64_t value) {
  SetMetricInternal(kSendBeginMainFrameToCommitNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kTotalLatencyName[] = "TotalLatency";
const uint64_t Graphics_Smoothness_EventLatency::kTotalLatencyNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetTotalLatency(int64_t value) {
  SetMetricInternal(kTotalLatencyNameHash, value);
  return *this;
}

const char Graphics_Smoothness_EventLatency::kTotalLatencyToSwapEndName[] = "TotalLatencyToSwapEnd";
const uint64_t Graphics_Smoothness_EventLatency::kTotalLatencyToSwapEndNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetTotalLatencyToSwapEnd(int64_t value) {
  SetMetricInternal(kTotalLatencyToSwapEndNameHash, value);
  return *this;
}


const char Graphics_Smoothness_Latency::kEntryName[] = "Graphics.Smoothness.Latency";
const uint64_t Graphics_Smoothness_Latency::kEntryNameHash;

Graphics_Smoothness_Latency::Graphics_Smoothness_Latency(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_Latency::Graphics_Smoothness_Latency(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_Latency::~Graphics_Smoothness_Latency() = default;


const char Graphics_Smoothness_Latency::kActivationName[] = "Activation";
const uint64_t Graphics_Smoothness_Latency::kActivationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetActivation(int64_t value) {
  SetMetricInternal(kActivationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameName[] = "BeginImplFrameToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetBeginImplFrameToSendBeginMainFrame(int64_t value) {
  SetMetricInternal(kBeginImplFrameToSendBeginMainFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kCommitName[] = "Commit";
const uint64_t Graphics_Smoothness_Latency::kCommitNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetCommit(int64_t value) {
  SetMetricInternal(kCommitNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kCompositorAnimationName[] = "CompositorAnimation";
const uint64_t Graphics_Smoothness_Latency::kCompositorAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetCompositorAnimation(int64_t value) {
  SetMetricInternal(kCompositorAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameName[] = "EndActivateToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetEndActivateToSubmitCompositorFrame(int64_t value) {
  SetMetricInternal(kEndActivateToSubmitCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kEndCommitToActivationName[] = "EndCommitToActivation";
const uint64_t Graphics_Smoothness_Latency::kEndCommitToActivationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetEndCommitToActivation(int64_t value) {
  SetMetricInternal(kEndCommitToActivationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kMainThreadAnimationName[] = "MainThreadAnimation";
const uint64_t Graphics_Smoothness_Latency::kMainThreadAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetMainThreadAnimation(int64_t value) {
  SetMetricInternal(kMainThreadAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kMissedFrameName[] = "MissedFrame";
const uint64_t Graphics_Smoothness_Latency::kMissedFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetMissedFrame(int64_t value) {
  SetMetricInternal(kMissedFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kPinchZoomName[] = "PinchZoom";
const uint64_t Graphics_Smoothness_Latency::kPinchZoomNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetPinchZoom(int64_t value) {
  SetMetricInternal(kPinchZoomNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kRAFName[] = "RAF";
const uint64_t Graphics_Smoothness_Latency::kRAFNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetRAF(int64_t value) {
  SetMetricInternal(kRAFNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitName[] = "SendBeginMainFrameToCommit";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit(int64_t value) {
  SetMetricInternal(kSendBeginMainFrameToCommitNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[] = "SubmitCompositorFrameToPresentationCompositorFrame.ReceivedCompositorFrameToStartDraw";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[] = "SubmitCompositorFrameToPresentationCompositorFrame.StartDrawToSwapStart";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame.SubmitToReceiveCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame.SwapEndToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[] = "SubmitCompositorFrameToPresentationCompositorFrame.SwapStartToSwapEnd";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value) {
  SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kTotalLatencyName[] = "TotalLatency";
const uint64_t Graphics_Smoothness_Latency::kTotalLatencyNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetTotalLatency(int64_t value) {
  SetMetricInternal(kTotalLatencyNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kTouchScrollName[] = "TouchScroll";
const uint64_t Graphics_Smoothness_Latency::kTouchScrollNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetTouchScroll(int64_t value) {
  SetMetricInternal(kTouchScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kUnknownName[] = "Unknown";
const uint64_t Graphics_Smoothness_Latency::kUnknownNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetUnknown(int64_t value) {
  SetMetricInternal(kUnknownNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kVideoName[] = "Video";
const uint64_t Graphics_Smoothness_Latency::kVideoNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetVideo(int64_t value) {
  SetMetricInternal(kVideoNameHash, value);
  return *this;
}

const char Graphics_Smoothness_Latency::kWheelScrollName[] = "WheelScroll";
const uint64_t Graphics_Smoothness_Latency::kWheelScrollNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetWheelScroll(int64_t value) {
  SetMetricInternal(kWheelScrollNameHash, value);
  return *this;
}


const char Graphics_Smoothness_PercentDroppedFrames::kEntryName[] = "Graphics.Smoothness.PercentDroppedFrames";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kEntryNameHash;

Graphics_Smoothness_PercentDroppedFrames::Graphics_Smoothness_PercentDroppedFrames(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_PercentDroppedFrames::Graphics_Smoothness_PercentDroppedFrames(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Graphics_Smoothness_PercentDroppedFrames::~Graphics_Smoothness_PercentDroppedFrames() = default;


const char Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsName[] = "AllAnimations";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllAnimations(int64_t value) {
  SetMetricInternal(kAllAnimationsNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsName[] = "AllInteractions";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllInteractions(int64_t value) {
  SetMetricInternal(kAllInteractionsNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kAllSequencesName[] = "AllSequences";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllSequencesNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllSequences(int64_t value) {
  SetMetricInternal(kAllSequencesNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationName[] = "CompositorThread.CompositorAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_CompositorAnimation(int64_t value) {
  SetMetricInternal(kCompositorThread_CompositorAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationName[] = "CompositorThread.MainThreadAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_MainThreadAnimation(int64_t value) {
  SetMetricInternal(kCompositorThread_MainThreadAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomName[] = "CompositorThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_PinchZoom(int64_t value) {
  SetMetricInternal(kCompositorThread_PinchZoomNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFName[] = "CompositorThread.RAF";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_RAF(int64_t value) {
  SetMetricInternal(kCompositorThread_RAFNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollName[] = "CompositorThread.TouchScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_TouchScroll(int64_t value) {
  SetMetricInternal(kCompositorThread_TouchScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_UniversalName[] = "CompositorThread.Universal";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_UniversalNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_Universal(int64_t value) {
  SetMetricInternal(kCompositorThread_UniversalNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoName[] = "CompositorThread.Video";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_Video(int64_t value) {
  SetMetricInternal(kCompositorThread_VideoNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollName[] = "CompositorThread.WheelScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_WheelScroll(int64_t value) {
  SetMetricInternal(kCompositorThread_WheelScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationName[] = "MainThread.CompositorAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_CompositorAnimation(int64_t value) {
  SetMetricInternal(kMainThread_CompositorAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationName[] = "MainThread.MainThreadAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_MainThreadAnimation(int64_t value) {
  SetMetricInternal(kMainThread_MainThreadAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomName[] = "MainThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_PinchZoom(int64_t value) {
  SetMetricInternal(kMainThread_PinchZoomNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFName[] = "MainThread.RAF";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_RAF(int64_t value) {
  SetMetricInternal(kMainThread_RAFNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollName[] = "MainThread.TouchScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_TouchScroll(int64_t value) {
  SetMetricInternal(kMainThread_TouchScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_UniversalName[] = "MainThread.Universal";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_UniversalNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_Universal(int64_t value) {
  SetMetricInternal(kMainThread_UniversalNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoName[] = "MainThread.Video";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_Video(int64_t value) {
  SetMetricInternal(kMainThread_VideoNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollName[] = "MainThread.WheelScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_WheelScroll(int64_t value) {
  SetMetricInternal(kMainThread_WheelScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_CompositorAnimationName[] = "SlowerThread.CompositorAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_CompositorAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_CompositorAnimation(int64_t value) {
  SetMetricInternal(kSlowerThread_CompositorAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_MainThreadAnimationName[] = "SlowerThread.MainThreadAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_MainThreadAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_MainThreadAnimation(int64_t value) {
  SetMetricInternal(kSlowerThread_MainThreadAnimationNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomName[] = "SlowerThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_PinchZoom(int64_t value) {
  SetMetricInternal(kSlowerThread_PinchZoomNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_RAFName[] = "SlowerThread.RAF";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_RAFNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_RAF(int64_t value) {
  SetMetricInternal(kSlowerThread_RAFNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_TouchScrollName[] = "SlowerThread.TouchScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_TouchScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_TouchScroll(int64_t value) {
  SetMetricInternal(kSlowerThread_TouchScrollNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_UniversalName[] = "SlowerThread.Universal";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_UniversalNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_Universal(int64_t value) {
  SetMetricInternal(kSlowerThread_UniversalNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_VideoName[] = "SlowerThread.Video";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_VideoNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_Video(int64_t value) {
  SetMetricInternal(kSlowerThread_VideoNameHash, value);
  return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_WheelScrollName[] = "SlowerThread.WheelScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_WheelScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_WheelScroll(int64_t value) {
  SetMetricInternal(kSlowerThread_WheelScrollNameHash, value);
  return *this;
}


const char HistoryManipulationIntervention::kEntryName[] = "HistoryManipulationIntervention";
const uint64_t HistoryManipulationIntervention::kEntryNameHash;

HistoryManipulationIntervention::HistoryManipulationIntervention(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

HistoryManipulationIntervention::HistoryManipulationIntervention(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

HistoryManipulationIntervention::~HistoryManipulationIntervention() = default;



const char HistoryNavigation::kEntryName[] = "HistoryNavigation";
const uint64_t HistoryNavigation::kEntryNameHash;

HistoryNavigation::HistoryNavigation(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

HistoryNavigation::HistoryNavigation(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

HistoryNavigation::~HistoryNavigation() = default;


const char HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheName[] = "BackForwardCache.IsServedFromBackForwardCache";
const uint64_t HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_IsServedFromBackForwardCache(int64_t value) {
  SetMetricInternal(kBackForwardCache_IsServedFromBackForwardCacheNameHash, value);
  return *this;
}

const char HistoryNavigation::kBackForwardCache_NotRestoredReasonsName[] = "BackForwardCache.NotRestoredReasons";
const uint64_t HistoryNavigation::kBackForwardCache_NotRestoredReasonsNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_NotRestoredReasons(int64_t value) {
  SetMetricInternal(kBackForwardCache_NotRestoredReasonsNameHash, value);
  return *this;
}

const char HistoryNavigation::kCrossOriginSubframesFeaturesName[] = "CrossOriginSubframesFeatures";
const uint64_t HistoryNavigation::kCrossOriginSubframesFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetCrossOriginSubframesFeatures(int64_t value) {
  SetMetricInternal(kCrossOriginSubframesFeaturesNameHash, value);
  return *this;
}

const char HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName[] = "LastCommittedCrossDocumentNavigationSourceIdForTheSameDocument";
const uint64_t HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetLastCommittedCrossDocumentNavigationSourceIdForTheSameDocument(int64_t value) {
  SetMetricInternal(kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash, value);
  return *this;
}

const char HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentName[] = "LastCommittedSourceIdForTheSameDocument";
const uint64_t HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetLastCommittedSourceIdForTheSameDocument(int64_t value) {
  SetMetricInternal(kLastCommittedSourceIdForTheSameDocumentNameHash, value);
  return *this;
}

const char HistoryNavigation::kMainFrameFeaturesName[] = "MainFrameFeatures";
const uint64_t HistoryNavigation::kMainFrameFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetMainFrameFeatures(int64_t value) {
  SetMetricInternal(kMainFrameFeaturesNameHash, value);
  return *this;
}

const char HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentName[] = "NavigatedToTheMostRecentEntryForDocument";
const uint64_t HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetNavigatedToTheMostRecentEntryForDocument(int64_t value) {
  SetMetricInternal(kNavigatedToTheMostRecentEntryForDocumentNameHash, value);
  return *this;
}

const char HistoryNavigation::kSameOriginSubframesFeaturesName[] = "SameOriginSubframesFeatures";
const uint64_t HistoryNavigation::kSameOriginSubframesFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetSameOriginSubframesFeatures(int64_t value) {
  SetMetricInternal(kSameOriginSubframesFeaturesNameHash, value);
  return *this;
}

const char HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentName[] = "TimeSinceNavigatedAwayFromDocument";
const uint64_t HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetTimeSinceNavigatedAwayFromDocument(int64_t value) {
  SetMetricInternal(kTimeSinceNavigatedAwayFromDocumentNameHash, value);
  return *this;
}


const char Identifiability::kEntryName[] = "Identifiability";
const uint64_t Identifiability::kEntryNameHash;

Identifiability::Identifiability(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Identifiability::Identifiability(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Identifiability::~Identifiability() = default;


const char Identifiability::kStudyGeneration_626Name[] = "StudyGeneration.626";
const uint64_t Identifiability::kStudyGeneration_626NameHash;

Identifiability& Identifiability::SetStudyGeneration_626(int64_t value) {
  SetMetricInternal(kStudyGeneration_626NameHash, value);
  return *this;
}


const char InputEvent::kEntryName[] = "InputEvent";
const uint64_t InputEvent::kEntryNameHash;

InputEvent::InputEvent(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

InputEvent::InputEvent(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

InputEvent::~InputEvent() = default;


const char InputEvent::kInteractiveTiming_InputDelayName[] = "InteractiveTiming.InputDelay";
const uint64_t InputEvent::kInteractiveTiming_InputDelayNameHash;

InputEvent& InputEvent::SetInteractiveTiming_InputDelay(int64_t value) {
  SetMetricInternal(kInteractiveTiming_InputDelayNameHash, value);
  return *this;
}

const char InputEvent::kInteractiveTiming_ProcessingTimeName[] = "InteractiveTiming.ProcessingTime";
const uint64_t InputEvent::kInteractiveTiming_ProcessingTimeNameHash;

InputEvent& InputEvent::SetInteractiveTiming_ProcessingTime(int64_t value) {
  SetMetricInternal(kInteractiveTiming_ProcessingTimeNameHash, value);
  return *this;
}


const char Intervention_DocumentWrite_ScriptBlock::kEntryName[] = "Intervention.DocumentWrite.ScriptBlock";
const uint64_t Intervention_DocumentWrite_ScriptBlock::kEntryNameHash;

Intervention_DocumentWrite_ScriptBlock::Intervention_DocumentWrite_ScriptBlock(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Intervention_DocumentWrite_ScriptBlock::Intervention_DocumentWrite_ScriptBlock(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Intervention_DocumentWrite_ScriptBlock::~Intervention_DocumentWrite_ScriptBlock() = default;


const char Intervention_DocumentWrite_ScriptBlock::kDisabled_ReloadName[] = "Disabled.Reload";
const uint64_t Intervention_DocumentWrite_ScriptBlock::kDisabled_ReloadNameHash;

Intervention_DocumentWrite_ScriptBlock& Intervention_DocumentWrite_ScriptBlock::SetDisabled_Reload(int64_t value) {
  SetMetricInternal(kDisabled_ReloadNameHash, value);
  return *this;
}

const char Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteName[] = "ParseTiming.ParseBlockedOnScriptExecutionFromDocumentWrite";
const uint64_t Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteNameHash;

Intervention_DocumentWrite_ScriptBlock& Intervention_DocumentWrite_ScriptBlock::SetParseTiming_ParseBlockedOnScriptExecutionFromDocumentWrite(int64_t value) {
  SetMetricInternal(kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteNameHash, value);
  return *this;
}

const char Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteName[] = "ParseTiming.ParseBlockedOnScriptLoadFromDocumentWrite";
const uint64_t Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteNameHash;

Intervention_DocumentWrite_ScriptBlock& Intervention_DocumentWrite_ScriptBlock::SetParseTiming_ParseBlockedOnScriptLoadFromDocumentWrite(int64_t value) {
  SetMetricInternal(kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteNameHash, value);
  return *this;
}


const char IOS_FindInPageSearchMatches::kEntryName[] = "IOS.FindInPageSearchMatches";
const uint64_t IOS_FindInPageSearchMatches::kEntryNameHash;

IOS_FindInPageSearchMatches::IOS_FindInPageSearchMatches(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_FindInPageSearchMatches::IOS_FindInPageSearchMatches(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_FindInPageSearchMatches::~IOS_FindInPageSearchMatches() = default;


const char IOS_FindInPageSearchMatches::kHasMatchesName[] = "HasMatches";
const uint64_t IOS_FindInPageSearchMatches::kHasMatchesNameHash;

IOS_FindInPageSearchMatches& IOS_FindInPageSearchMatches::SetHasMatches(int64_t value) {
  SetMetricInternal(kHasMatchesNameHash, value);
  return *this;
}


const char IOS_PageZoomChanged::kEntryName[] = "IOS.PageZoomChanged";
const uint64_t IOS_PageZoomChanged::kEntryNameHash;

IOS_PageZoomChanged::IOS_PageZoomChanged(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_PageZoomChanged::IOS_PageZoomChanged(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_PageZoomChanged::~IOS_PageZoomChanged() = default;


const char IOS_PageZoomChanged::kContentSizeCategoryName[] = "ContentSizeCategory";
const uint64_t IOS_PageZoomChanged::kContentSizeCategoryNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetContentSizeCategory(int64_t value) {
  SetMetricInternal(kContentSizeCategoryNameHash, value);
  return *this;
}

const char IOS_PageZoomChanged::kOverallZoomLevelName[] = "OverallZoomLevel";
const uint64_t IOS_PageZoomChanged::kOverallZoomLevelNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetOverallZoomLevel(int64_t value) {
  SetMetricInternal(kOverallZoomLevelNameHash, value);
  return *this;
}

const char IOS_PageZoomChanged::kUserZoomLevelName[] = "UserZoomLevel";
const uint64_t IOS_PageZoomChanged::kUserZoomLevelNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetUserZoomLevel(int64_t value) {
  SetMetricInternal(kUserZoomLevelNameHash, value);
  return *this;
}


const char IOS_RendererGone::kEntryName[] = "IOS.RendererGone";
const uint64_t IOS_RendererGone::kEntryNameHash;

IOS_RendererGone::IOS_RendererGone(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_RendererGone::IOS_RendererGone(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_RendererGone::~IOS_RendererGone() = default;


const char IOS_RendererGone::kAliveRecentlyRendererCountName[] = "AliveRecentlyRendererCount";
const uint64_t IOS_RendererGone::kAliveRecentlyRendererCountNameHash;

IOS_RendererGone& IOS_RendererGone::SetAliveRecentlyRendererCount(int64_t value) {
  SetMetricInternal(kAliveRecentlyRendererCountNameHash, value);
  return *this;
}

const char IOS_RendererGone::kAliveRendererCountName[] = "AliveRendererCount";
const uint64_t IOS_RendererGone::kAliveRendererCountNameHash;

IOS_RendererGone& IOS_RendererGone::SetAliveRendererCount(int64_t value) {
  SetMetricInternal(kAliveRendererCountNameHash, value);
  return *this;
}

const char IOS_RendererGone::kInForegroundName[] = "InForeground";
const uint64_t IOS_RendererGone::kInForegroundNameHash;

IOS_RendererGone& IOS_RendererGone::SetInForeground(int64_t value) {
  SetMetricInternal(kInForegroundNameHash, value);
  return *this;
}

const char IOS_RendererGone::kSawMemoryWarningName[] = "SawMemoryWarning";
const uint64_t IOS_RendererGone::kSawMemoryWarningNameHash;

IOS_RendererGone& IOS_RendererGone::SetSawMemoryWarning(int64_t value) {
  SetMetricInternal(kSawMemoryWarningNameHash, value);
  return *this;
}


const char IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryName[] = "IOS.URLMismatchInLegacyAndSlimNavigationManager";
const uint64_t IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryNameHash;

IOS_URLMismatchInLegacyAndSlimNavigationManager::IOS_URLMismatchInLegacyAndSlimNavigationManager(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_URLMismatchInLegacyAndSlimNavigationManager::IOS_URLMismatchInLegacyAndSlimNavigationManager(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

IOS_URLMismatchInLegacyAndSlimNavigationManager::~IOS_URLMismatchInLegacyAndSlimNavigationManager() = default;


const char IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchName[] = "HasMismatch";
const uint64_t IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchNameHash;

IOS_URLMismatchInLegacyAndSlimNavigationManager& IOS_URLMismatchInLegacyAndSlimNavigationManager::SetHasMismatch(int64_t value) {
  SetMetricInternal(kHasMismatchNameHash, value);
  return *this;
}


const char Layout_DisplayCutout_StateChanged::kEntryName[] = "Layout.DisplayCutout.StateChanged";
const uint64_t Layout_DisplayCutout_StateChanged::kEntryNameHash;

Layout_DisplayCutout_StateChanged::Layout_DisplayCutout_StateChanged(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Layout_DisplayCutout_StateChanged::Layout_DisplayCutout_StateChanged(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Layout_DisplayCutout_StateChanged::~Layout_DisplayCutout_StateChanged() = default;


const char Layout_DisplayCutout_StateChanged::kIsMainFrameName[] = "IsMainFrame";
const uint64_t Layout_DisplayCutout_StateChanged::kIsMainFrameNameHash;

Layout_DisplayCutout_StateChanged& Layout_DisplayCutout_StateChanged::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char Layout_DisplayCutout_StateChanged::kSafeAreasPresentName[] = "SafeAreasPresent";
const uint64_t Layout_DisplayCutout_StateChanged::kSafeAreasPresentNameHash;

Layout_DisplayCutout_StateChanged& Layout_DisplayCutout_StateChanged::SetSafeAreasPresent(int64_t value) {
  SetMetricInternal(kSafeAreasPresentNameHash, value);
  return *this;
}

const char Layout_DisplayCutout_StateChanged::kViewportFit_AppliedName[] = "ViewportFit.Applied";
const uint64_t Layout_DisplayCutout_StateChanged::kViewportFit_AppliedNameHash;

Layout_DisplayCutout_StateChanged& Layout_DisplayCutout_StateChanged::SetViewportFit_Applied(int64_t value) {
  SetMetricInternal(kViewportFit_AppliedNameHash, value);
  return *this;
}

const char Layout_DisplayCutout_StateChanged::kViewportFit_IgnoredReasonName[] = "ViewportFit.IgnoredReason";
const uint64_t Layout_DisplayCutout_StateChanged::kViewportFit_IgnoredReasonNameHash;

Layout_DisplayCutout_StateChanged& Layout_DisplayCutout_StateChanged::SetViewportFit_IgnoredReason(int64_t value) {
  SetMetricInternal(kViewportFit_IgnoredReasonNameHash, value);
  return *this;
}

const char Layout_DisplayCutout_StateChanged::kViewportFit_SuppliedName[] = "ViewportFit.Supplied";
const uint64_t Layout_DisplayCutout_StateChanged::kViewportFit_SuppliedNameHash;

Layout_DisplayCutout_StateChanged& Layout_DisplayCutout_StateChanged::SetViewportFit_Supplied(int64_t value) {
  SetMetricInternal(kViewportFit_SuppliedNameHash, value);
  return *this;
}


const char LoadingPredictor::kEntryName[] = "LoadingPredictor";
const uint64_t LoadingPredictor::kEntryNameHash;

LoadingPredictor::LoadingPredictor(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LoadingPredictor::LoadingPredictor(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LoadingPredictor::~LoadingPredictor() = default;


const char LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsName[] = "LocalPredictionCorrectlyPredictedOrigins";
const uint64_t LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetLocalPredictionCorrectlyPredictedOrigins(int64_t value) {
  SetMetricInternal(kLocalPredictionCorrectlyPredictedOriginsNameHash, value);
  return *this;
}

const char LoadingPredictor::kLocalPredictionOriginsName[] = "LocalPredictionOrigins";
const uint64_t LoadingPredictor::kLocalPredictionOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetLocalPredictionOrigins(int64_t value) {
  SetMetricInternal(kLocalPredictionOriginsNameHash, value);
  return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsName[] = "OptimizationGuidePredictionCorrectlyPredictedOrigins";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionCorrectlyPredictedOrigins(int64_t value) {
  SetMetricInternal(kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash, value);
  return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName[] = "OptimizationGuidePredictionCorrectlyPredictedSubresources";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionCorrectlyPredictedSubresources(int64_t value) {
  SetMetricInternal(kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash, value);
  return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionDecisionName[] = "OptimizationGuidePredictionDecision";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionDecisionNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionDecision(int64_t value) {
  SetMetricInternal(kOptimizationGuidePredictionDecisionNameHash, value);
  return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionOriginsName[] = "OptimizationGuidePredictionOrigins";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionOrigins(int64_t value) {
  SetMetricInternal(kOptimizationGuidePredictionOriginsNameHash, value);
  return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionSubresourcesName[] = "OptimizationGuidePredictionSubresources";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionSubresourcesNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionSubresources(int64_t value) {
  SetMetricInternal(kOptimizationGuidePredictionSubresourcesNameHash, value);
  return *this;
}


const char LocalNetworkRequests::kEntryName[] = "LocalNetworkRequests";
const uint64_t LocalNetworkRequests::kEntryNameHash;

LocalNetworkRequests::LocalNetworkRequests(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LocalNetworkRequests::LocalNetworkRequests(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LocalNetworkRequests::~LocalNetworkRequests() = default;


const char LocalNetworkRequests::kCount_FailedName[] = "Count.Failed";
const uint64_t LocalNetworkRequests::kCount_FailedNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetCount_Failed(int64_t value) {
  SetMetricInternal(kCount_FailedNameHash, value);
  return *this;
}

const char LocalNetworkRequests::kCount_SuccessfulName[] = "Count.Successful";
const uint64_t LocalNetworkRequests::kCount_SuccessfulNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetCount_Successful(int64_t value) {
  SetMetricInternal(kCount_SuccessfulNameHash, value);
  return *this;
}

const char LocalNetworkRequests::kPortTypeName[] = "PortType";
const uint64_t LocalNetworkRequests::kPortTypeNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetPortType(int64_t value) {
  SetMetricInternal(kPortTypeNameHash, value);
  return *this;
}

const char LocalNetworkRequests::kResourceTypeName[] = "ResourceType";
const uint64_t LocalNetworkRequests::kResourceTypeNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetResourceType(int64_t value) {
  SetMetricInternal(kResourceTypeNameHash, value);
  return *this;
}


const char LookalikeUrl_NavigationSuggestion::kEntryName[] = "LookalikeUrl.NavigationSuggestion";
const uint64_t LookalikeUrl_NavigationSuggestion::kEntryNameHash;

LookalikeUrl_NavigationSuggestion::LookalikeUrl_NavigationSuggestion(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LookalikeUrl_NavigationSuggestion::LookalikeUrl_NavigationSuggestion(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

LookalikeUrl_NavigationSuggestion::~LookalikeUrl_NavigationSuggestion() = default;


const char LookalikeUrl_NavigationSuggestion::kMatchTypeName[] = "MatchType";
const uint64_t LookalikeUrl_NavigationSuggestion::kMatchTypeNameHash;

LookalikeUrl_NavigationSuggestion& LookalikeUrl_NavigationSuggestion::SetMatchType(int64_t value) {
  SetMetricInternal(kMatchTypeNameHash, value);
  return *this;
}

const char LookalikeUrl_NavigationSuggestion::kUserActionName[] = "UserAction";
const uint64_t LookalikeUrl_NavigationSuggestion::kUserActionNameHash;

LookalikeUrl_NavigationSuggestion& LookalikeUrl_NavigationSuggestion::SetUserAction(int64_t value) {
  SetMetricInternal(kUserActionNameHash, value);
  return *this;
}


const char MainFrameNavigation::kEntryName[] = "MainFrameNavigation";
const uint64_t MainFrameNavigation::kEntryNameHash;

MainFrameNavigation::MainFrameNavigation(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MainFrameNavigation::MainFrameNavigation(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MainFrameNavigation::~MainFrameNavigation() = default;


const char MainFrameNavigation::kDidCommitName[] = "DidCommit";
const uint64_t MainFrameNavigation::kDidCommitNameHash;

MainFrameNavigation& MainFrameNavigation::SetDidCommit(int64_t value) {
  SetMetricInternal(kDidCommitNameHash, value);
  return *this;
}


const char Media_Autoplay_Attempt::kEntryName[] = "Media.Autoplay.Attempt";
const uint64_t Media_Autoplay_Attempt::kEntryNameHash;

Media_Autoplay_Attempt::Media_Autoplay_Attempt(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_Attempt::Media_Autoplay_Attempt(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_Attempt::~Media_Autoplay_Attempt() = default;


const char Media_Autoplay_Attempt::kAudioTrackName[] = "AudioTrack";
const uint64_t Media_Autoplay_Attempt::kAudioTrackNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetAudioTrack(int64_t value) {
  SetMetricInternal(kAudioTrackNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kHighMediaEngagementName[] = "HighMediaEngagement";
const uint64_t Media_Autoplay_Attempt::kHighMediaEngagementNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetHighMediaEngagement(int64_t value) {
  SetMetricInternal(kHighMediaEngagementNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kMutedName[] = "Muted";
const uint64_t Media_Autoplay_Attempt::kMutedNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetMuted(int64_t value) {
  SetMetricInternal(kMutedNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kSourceName[] = "Source";
const uint64_t Media_Autoplay_Attempt::kSourceNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetSource(int64_t value) {
  SetMetricInternal(kSourceNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kUserGestureRequiredName[] = "UserGestureRequired";
const uint64_t Media_Autoplay_Attempt::kUserGestureRequiredNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureRequired(int64_t value) {
  SetMetricInternal(kUserGestureRequiredNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kUserGestureStatusName[] = "UserGestureStatus";
const uint64_t Media_Autoplay_Attempt::kUserGestureStatusNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureStatus(int64_t value) {
  SetMetricInternal(kUserGestureStatusNameHash, value);
  return *this;
}

const char Media_Autoplay_Attempt::kVideoTrackName[] = "VideoTrack";
const uint64_t Media_Autoplay_Attempt::kVideoTrackNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetVideoTrack(int64_t value) {
  SetMetricInternal(kVideoTrackNameHash, value);
  return *this;
}


const char Media_Autoplay_AudioContext::kEntryName[] = "Media.Autoplay.AudioContext";
const uint64_t Media_Autoplay_AudioContext::kEntryNameHash;

Media_Autoplay_AudioContext::Media_Autoplay_AudioContext(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_AudioContext::Media_Autoplay_AudioContext(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_AudioContext::~Media_Autoplay_AudioContext() = default;


const char Media_Autoplay_AudioContext::kSourceNodeStartedName[] = "SourceNodeStarted";
const uint64_t Media_Autoplay_AudioContext::kSourceNodeStartedNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetSourceNodeStarted(int64_t value) {
  SetMetricInternal(kSourceNodeStartedNameHash, value);
  return *this;
}

const char Media_Autoplay_AudioContext::kStatusName[] = "Status";
const uint64_t Media_Autoplay_AudioContext::kStatusNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetStatus(int64_t value) {
  SetMetricInternal(kStatusNameHash, value);
  return *this;
}

const char Media_Autoplay_AudioContext::kUnlockTypeName[] = "UnlockType";
const uint64_t Media_Autoplay_AudioContext::kUnlockTypeNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetUnlockType(int64_t value) {
  SetMetricInternal(kUnlockTypeNameHash, value);
  return *this;
}


const char Media_Autoplay_Muted_UnmuteAction::kEntryName[] = "Media.Autoplay.Muted.UnmuteAction";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kEntryNameHash;

Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Autoplay_Muted_UnmuteAction::~Media_Autoplay_Muted_UnmuteAction() = default;


const char Media_Autoplay_Muted_UnmuteAction::kResultName[] = "Result";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kResultNameHash;

Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetResult(int64_t value) {
  SetMetricInternal(kResultNameHash, value);
  return *this;
}

const char Media_Autoplay_Muted_UnmuteAction::kSourceName[] = "Source";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kSourceNameHash;

Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetSource(int64_t value) {
  SetMetricInternal(kSourceNameHash, value);
  return *this;
}


const char Media_BasicPlayback::kEntryName[] = "Media.BasicPlayback";
const uint64_t Media_BasicPlayback::kEntryNameHash;

Media_BasicPlayback::Media_BasicPlayback(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_BasicPlayback::Media_BasicPlayback(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_BasicPlayback::~Media_BasicPlayback() = default;


const char Media_BasicPlayback::kAudioCodecName[] = "AudioCodec";
const uint64_t Media_BasicPlayback::kAudioCodecNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioCodec(int64_t value) {
  SetMetricInternal(kAudioCodecNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kAudioCodecProfileName[] = "AudioCodecProfile";
const uint64_t Media_BasicPlayback::kAudioCodecProfileNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioCodecProfile(int64_t value) {
  SetMetricInternal(kAudioCodecProfileNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kAudioDecoderNameName[] = "AudioDecoderName";
const uint64_t Media_BasicPlayback::kAudioDecoderNameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioDecoderName(int64_t value) {
  SetMetricInternal(kAudioDecoderNameNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kAudioEncryptionSchemeName[] = "AudioEncryptionScheme";
const uint64_t Media_BasicPlayback::kAudioEncryptionSchemeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioEncryptionScheme(int64_t value) {
  SetMetricInternal(kAudioEncryptionSchemeNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kAutoplayInitiatedName[] = "AutoplayInitiated";
const uint64_t Media_BasicPlayback::kAutoplayInitiatedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAutoplayInitiated(int64_t value) {
  SetMetricInternal(kAutoplayInitiatedNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kCompletedRebuffersCountName[] = "CompletedRebuffersCount";
const uint64_t Media_BasicPlayback::kCompletedRebuffersCountNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetCompletedRebuffersCount(int64_t value) {
  SetMetricInternal(kCompletedRebuffersCountNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kCompletedRebuffersDurationName[] = "CompletedRebuffersDuration";
const uint64_t Media_BasicPlayback::kCompletedRebuffersDurationNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetCompletedRebuffersDuration(int64_t value) {
  SetMetricInternal(kCompletedRebuffersDurationNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kDurationName[] = "Duration";
const uint64_t Media_BasicPlayback::kDurationNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetDuration(int64_t value) {
  SetMetricInternal(kDurationNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kHasAudioName[] = "HasAudio";
const uint64_t Media_BasicPlayback::kHasAudioNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetHasAudio(int64_t value) {
  SetMetricInternal(kHasAudioNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kHasVideoName[] = "HasVideo";
const uint64_t Media_BasicPlayback::kHasVideoNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetHasVideo(int64_t value) {
  SetMetricInternal(kHasVideoNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kIsBackgroundName[] = "IsBackground";
const uint64_t Media_BasicPlayback::kIsBackgroundNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsBackground(int64_t value) {
  SetMetricInternal(kIsBackgroundNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kIsEMEName[] = "IsEME";
const uint64_t Media_BasicPlayback::kIsEMENameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsEME(int64_t value) {
  SetMetricInternal(kIsEMENameHash, value);
  return *this;
}

const char Media_BasicPlayback::kIsMSEName[] = "IsMSE";
const uint64_t Media_BasicPlayback::kIsMSENameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsMSE(int64_t value) {
  SetMetricInternal(kIsMSENameHash, value);
  return *this;
}

const char Media_BasicPlayback::kIsMutedName[] = "IsMuted";
const uint64_t Media_BasicPlayback::kIsMutedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsMuted(int64_t value) {
  SetMetricInternal(kIsMutedNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_BasicPlayback::kIsTopFrameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsTopFrame(int64_t value) {
  SetMetricInternal(kIsTopFrameNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kLastPipelineStatusName[] = "LastPipelineStatus";
const uint64_t Media_BasicPlayback::kLastPipelineStatusNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetLastPipelineStatus(int64_t value) {
  SetMetricInternal(kLastPipelineStatusNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kMeanTimeBetweenRebuffersName[] = "MeanTimeBetweenRebuffers";
const uint64_t Media_BasicPlayback::kMeanTimeBetweenRebuffersNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetMeanTimeBetweenRebuffers(int64_t value) {
  SetMetricInternal(kMeanTimeBetweenRebuffersNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kPlayerIDName[] = "PlayerID";
const uint64_t Media_BasicPlayback::kPlayerIDNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetPlayerID(int64_t value) {
  SetMetricInternal(kPlayerIDNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kRebuffersCountName[] = "RebuffersCount";
const uint64_t Media_BasicPlayback::kRebuffersCountNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetRebuffersCount(int64_t value) {
  SetMetricInternal(kRebuffersCountNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoCodecName[] = "VideoCodec";
const uint64_t Media_BasicPlayback::kVideoCodecNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoCodec(int64_t value) {
  SetMetricInternal(kVideoCodecNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoCodecProfileName[] = "VideoCodecProfile";
const uint64_t Media_BasicPlayback::kVideoCodecProfileNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoCodecProfile(int64_t value) {
  SetMetricInternal(kVideoCodecProfileNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoDecoderNameName[] = "VideoDecoderName";
const uint64_t Media_BasicPlayback::kVideoDecoderNameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoDecoderName(int64_t value) {
  SetMetricInternal(kVideoDecoderNameNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoEncryptionSchemeName[] = "VideoEncryptionScheme";
const uint64_t Media_BasicPlayback::kVideoEncryptionSchemeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoEncryptionScheme(int64_t value) {
  SetMetricInternal(kVideoEncryptionSchemeNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoFramesDecodedName[] = "VideoFramesDecoded";
const uint64_t Media_BasicPlayback::kVideoFramesDecodedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoFramesDecoded(int64_t value) {
  SetMetricInternal(kVideoFramesDecodedNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoFramesDroppedName[] = "VideoFramesDropped";
const uint64_t Media_BasicPlayback::kVideoFramesDroppedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoFramesDropped(int64_t value) {
  SetMetricInternal(kVideoFramesDroppedNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoNaturalHeightName[] = "VideoNaturalHeight";
const uint64_t Media_BasicPlayback::kVideoNaturalHeightNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoNaturalHeight(int64_t value) {
  SetMetricInternal(kVideoNaturalHeightNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kVideoNaturalWidthName[] = "VideoNaturalWidth";
const uint64_t Media_BasicPlayback::kVideoNaturalWidthNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoNaturalWidth(int64_t value) {
  SetMetricInternal(kVideoNaturalWidthNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTimeName[] = "WatchTime";
const uint64_t Media_BasicPlayback::kWatchTimeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime(int64_t value) {
  SetMetricInternal(kWatchTimeNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_ACName[] = "WatchTime.AC";
const uint64_t Media_BasicPlayback::kWatchTime_ACNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_AC(int64_t value) {
  SetMetricInternal(kWatchTime_ACNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_BatteryName[] = "WatchTime.Battery";
const uint64_t Media_BasicPlayback::kWatchTime_BatteryNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_Battery(int64_t value) {
  SetMetricInternal(kWatchTime_BatteryNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayFullscreenName[] = "WatchTime.DisplayFullscreen";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayFullscreenNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayFullscreen(int64_t value) {
  SetMetricInternal(kWatchTime_DisplayFullscreenNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayInlineName[] = "WatchTime.DisplayInline";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayInlineNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayInline(int64_t value) {
  SetMetricInternal(kWatchTime_DisplayInlineNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayPictureInPictureName[] = "WatchTime.DisplayPictureInPicture";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayPictureInPictureNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayPictureInPicture(int64_t value) {
  SetMetricInternal(kWatchTime_DisplayPictureInPictureNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_NativeControlsOffName[] = "WatchTime.NativeControlsOff";
const uint64_t Media_BasicPlayback::kWatchTime_NativeControlsOffNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_NativeControlsOff(int64_t value) {
  SetMetricInternal(kWatchTime_NativeControlsOffNameHash, value);
  return *this;
}

const char Media_BasicPlayback::kWatchTime_NativeControlsOnName[] = "WatchTime.NativeControlsOn";
const uint64_t Media_BasicPlayback::kWatchTime_NativeControlsOnNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_NativeControlsOn(int64_t value) {
  SetMetricInternal(kWatchTime_NativeControlsOnNameHash, value);
  return *this;
}


const char Media_EME_ApiPromiseRejection::kEntryName[] = "Media.EME.ApiPromiseRejection";
const uint64_t Media_EME_ApiPromiseRejection::kEntryNameHash;

Media_EME_ApiPromiseRejection::Media_EME_ApiPromiseRejection(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_ApiPromiseRejection::Media_EME_ApiPromiseRejection(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_ApiPromiseRejection::~Media_EME_ApiPromiseRejection() = default;


const char Media_EME_ApiPromiseRejection::kApiName[] = "Api";
const uint64_t Media_EME_ApiPromiseRejection::kApiNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetApi(int64_t value) {
  SetMetricInternal(kApiNameHash, value);
  return *this;
}

const char Media_EME_ApiPromiseRejection::kSystemCodeName[] = "SystemCode";
const uint64_t Media_EME_ApiPromiseRejection::kSystemCodeNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetSystemCode(int64_t value) {
  SetMetricInternal(kSystemCodeNameHash, value);
  return *this;
}


const char Media_EME_CreateMediaKeys::kEntryName[] = "Media.EME.CreateMediaKeys";
const uint64_t Media_EME_CreateMediaKeys::kEntryNameHash;

Media_EME_CreateMediaKeys::Media_EME_CreateMediaKeys(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_CreateMediaKeys::Media_EME_CreateMediaKeys(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_CreateMediaKeys::~Media_EME_CreateMediaKeys() = default;


const char Media_EME_CreateMediaKeys::kIsAdFrameName[] = "IsAdFrame";
const uint64_t Media_EME_CreateMediaKeys::kIsAdFrameNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsAdFrame(int64_t value) {
  SetMetricInternal(kIsAdFrameNameHash, value);
  return *this;
}

const char Media_EME_CreateMediaKeys::kIsCrossOriginName[] = "IsCrossOrigin";
const uint64_t Media_EME_CreateMediaKeys::kIsCrossOriginNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsCrossOrigin(int64_t value) {
  SetMetricInternal(kIsCrossOriginNameHash, value);
  return *this;
}

const char Media_EME_CreateMediaKeys::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_EME_CreateMediaKeys::kIsTopFrameNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsTopFrame(int64_t value) {
  SetMetricInternal(kIsTopFrameNameHash, value);
  return *this;
}

const char Media_EME_CreateMediaKeys::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_CreateMediaKeys::kKeySystemNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetKeySystem(int64_t value) {
  SetMetricInternal(kKeySystemNameHash, value);
  return *this;
}


const char Media_EME_RequestMediaKeySystemAccess::kEntryName[] = "Media.EME.RequestMediaKeySystemAccess";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kEntryNameHash;

Media_EME_RequestMediaKeySystemAccess::Media_EME_RequestMediaKeySystemAccess(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_RequestMediaKeySystemAccess::Media_EME_RequestMediaKeySystemAccess(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_EME_RequestMediaKeySystemAccess::~Media_EME_RequestMediaKeySystemAccess() = default;


const char Media_EME_RequestMediaKeySystemAccess::kIsAdFrameName[] = "IsAdFrame";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsAdFrameNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsAdFrame(int64_t value) {
  SetMetricInternal(kIsAdFrameNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginName[] = "IsCrossOrigin";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsCrossOrigin(int64_t value) {
  SetMetricInternal(kIsCrossOriginNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsTopFrameNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsTopFrame(int64_t value) {
  SetMetricInternal(kIsTopFrameNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kKeySystemNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetKeySystem(int64_t value) {
  SetMetricInternal(kKeySystemNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesName[] = "VideoCapabilities";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities(int64_t value) {
  SetMetricInternal(kVideoCapabilitiesNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessName[] = "VideoCapabilities.HasEmptyRobustness";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities_HasEmptyRobustness(int64_t value) {
  SetMetricInternal(kVideoCapabilities_HasEmptyRobustnessNameHash, value);
  return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessName[] = "VideoCapabilities.HasHwSecureAllRobustness";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities_HasHwSecureAllRobustness(int64_t value) {
  SetMetricInternal(kVideoCapabilities_HasHwSecureAllRobustnessNameHash, value);
  return *this;
}


const char Media_Engagement_SessionFinished::kEntryName[] = "Media.Engagement.SessionFinished";
const uint64_t Media_Engagement_SessionFinished::kEntryNameHash;

Media_Engagement_SessionFinished::Media_Engagement_SessionFinished(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Engagement_SessionFinished::Media_Engagement_SessionFinished(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Engagement_SessionFinished::~Media_Engagement_SessionFinished() = default;


const char Media_Engagement_SessionFinished::kEngagement_IsHighName[] = "Engagement.IsHigh";
const uint64_t Media_Engagement_SessionFinished::kEngagement_IsHighNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetEngagement_IsHigh(int64_t value) {
  SetMetricInternal(kEngagement_IsHighNameHash, value);
  return *this;
}

const char Media_Engagement_SessionFinished::kEngagement_ScoreName[] = "Engagement.Score";
const uint64_t Media_Engagement_SessionFinished::kEngagement_ScoreNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetEngagement_Score(int64_t value) {
  SetMetricInternal(kEngagement_ScoreNameHash, value);
  return *this;
}

const char Media_Engagement_SessionFinished::kPlaybacks_TotalName[] = "Playbacks.Total";
const uint64_t Media_Engagement_SessionFinished::kPlaybacks_TotalNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlaybacks_Total(int64_t value) {
  SetMetricInternal(kPlaybacks_TotalNameHash, value);
  return *this;
}

const char Media_Engagement_SessionFinished::kPlayer_Audible_DeltaName[] = "Player.Audible.Delta";
const uint64_t Media_Engagement_SessionFinished::kPlayer_Audible_DeltaNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlayer_Audible_Delta(int64_t value) {
  SetMetricInternal(kPlayer_Audible_DeltaNameHash, value);
  return *this;
}

const char Media_Engagement_SessionFinished::kPlayer_Significant_DeltaName[] = "Player.Significant.Delta";
const uint64_t Media_Engagement_SessionFinished::kPlayer_Significant_DeltaNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlayer_Significant_Delta(int64_t value) {
  SetMetricInternal(kPlayer_Significant_DeltaNameHash, value);
  return *this;
}

const char Media_Engagement_SessionFinished::kVisits_TotalName[] = "Visits.Total";
const uint64_t Media_Engagement_SessionFinished::kVisits_TotalNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetVisits_Total(int64_t value) {
  SetMetricInternal(kVisits_TotalNameHash, value);
  return *this;
}


const char Media_Engagement_ShortPlaybackIgnored::kEntryName[] = "Media.Engagement.ShortPlaybackIgnored";
const uint64_t Media_Engagement_ShortPlaybackIgnored::kEntryNameHash;

Media_Engagement_ShortPlaybackIgnored::Media_Engagement_ShortPlaybackIgnored(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Engagement_ShortPlaybackIgnored::Media_Engagement_ShortPlaybackIgnored(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Engagement_ShortPlaybackIgnored::~Media_Engagement_ShortPlaybackIgnored() = default;


const char Media_Engagement_ShortPlaybackIgnored::kLengthName[] = "Length";
const uint64_t Media_Engagement_ShortPlaybackIgnored::kLengthNameHash;

Media_Engagement_ShortPlaybackIgnored& Media_Engagement_ShortPlaybackIgnored::SetLength(int64_t value) {
  SetMetricInternal(kLengthNameHash, value);
  return *this;
}


const char Media_Feed_Discover::kEntryName[] = "Media.Feed.Discover";
const uint64_t Media_Feed_Discover::kEntryNameHash;

Media_Feed_Discover::Media_Feed_Discover(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Feed_Discover::Media_Feed_Discover(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Feed_Discover::~Media_Feed_Discover() = default;


const char Media_Feed_Discover::kHasMediaFeedName[] = "HasMediaFeed";
const uint64_t Media_Feed_Discover::kHasMediaFeedNameHash;

Media_Feed_Discover& Media_Feed_Discover::SetHasMediaFeed(int64_t value) {
  SetMetricInternal(kHasMediaFeedNameHash, value);
  return *this;
}


const char Media_GlobalMediaControls_ActionButtonPressed::kEntryName[] = "Media.GlobalMediaControls.ActionButtonPressed";
const uint64_t Media_GlobalMediaControls_ActionButtonPressed::kEntryNameHash;

Media_GlobalMediaControls_ActionButtonPressed::Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_GlobalMediaControls_ActionButtonPressed::Media_GlobalMediaControls_ActionButtonPressed(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_GlobalMediaControls_ActionButtonPressed::~Media_GlobalMediaControls_ActionButtonPressed() = default;


const char Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionName[] = "MediaSessionAction";
const uint64_t Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionNameHash;

Media_GlobalMediaControls_ActionButtonPressed& Media_GlobalMediaControls_ActionButtonPressed::SetMediaSessionAction(int64_t value) {
  SetMetricInternal(kMediaSessionActionNameHash, value);
  return *this;
}


const char Media_Learning_PredictionRecord::kEntryName[] = "Media.Learning.PredictionRecord";
const uint64_t Media_Learning_PredictionRecord::kEntryNameHash;

Media_Learning_PredictionRecord::Media_Learning_PredictionRecord(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Learning_PredictionRecord::Media_Learning_PredictionRecord(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_Learning_PredictionRecord::~Media_Learning_PredictionRecord() = default;


const char Media_Learning_PredictionRecord::kLearningTaskName[] = "LearningTask";
const uint64_t Media_Learning_PredictionRecord::kLearningTaskNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetLearningTask(int64_t value) {
  SetMetricInternal(kLearningTaskNameHash, value);
  return *this;
}

const char Media_Learning_PredictionRecord::kObservedValueName[] = "ObservedValue";
const uint64_t Media_Learning_PredictionRecord::kObservedValueNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetObservedValue(int64_t value) {
  SetMetricInternal(kObservedValueNameHash, value);
  return *this;
}

const char Media_Learning_PredictionRecord::kPredictedValueName[] = "PredictedValue";
const uint64_t Media_Learning_PredictionRecord::kPredictedValueNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetPredictedValue(int64_t value) {
  SetMetricInternal(kPredictedValueNameHash, value);
  return *this;
}

const char Media_Learning_PredictionRecord::kTrainingDataSizeName[] = "TrainingDataSize";
const uint64_t Media_Learning_PredictionRecord::kTrainingDataSizeNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetTrainingDataSize(int64_t value) {
  SetMetricInternal(kTrainingDataSizeNameHash, value);
  return *this;
}

const char Media_Learning_PredictionRecord::kTrainingDataTotalWeightName[] = "TrainingDataTotalWeight";
const uint64_t Media_Learning_PredictionRecord::kTrainingDataTotalWeightNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetTrainingDataTotalWeight(int64_t value) {
  SetMetricInternal(kTrainingDataTotalWeightNameHash, value);
  return *this;
}


const char Media_SiteMuted::kEntryName[] = "Media.SiteMuted";
const uint64_t Media_SiteMuted::kEntryNameHash;

Media_SiteMuted::Media_SiteMuted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_SiteMuted::Media_SiteMuted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_SiteMuted::~Media_SiteMuted() = default;


const char Media_SiteMuted::kMuteReasonName[] = "MuteReason";
const uint64_t Media_SiteMuted::kMuteReasonNameHash;

Media_SiteMuted& Media_SiteMuted::SetMuteReason(int64_t value) {
  SetMetricInternal(kMuteReasonNameHash, value);
  return *this;
}


const char Media_VideoDecodePerfRecord::kEntryName[] = "Media.VideoDecodePerfRecord";
const uint64_t Media_VideoDecodePerfRecord::kEntryNameHash;

Media_VideoDecodePerfRecord::Media_VideoDecodePerfRecord(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_VideoDecodePerfRecord::Media_VideoDecodePerfRecord(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_VideoDecodePerfRecord::~Media_VideoDecodePerfRecord() = default;


const char Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientName[] = "Perf.ApiWouldClaimIsPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_ApiWouldClaimIsPowerEfficient(int64_t value) {
  SetMetricInternal(kPerf_ApiWouldClaimIsPowerEfficientNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothName[] = "Perf.ApiWouldClaimIsSmooth";
const uint64_t Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_ApiWouldClaimIsSmooth(int64_t value) {
  SetMetricInternal(kPerf_ApiWouldClaimIsSmoothNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedName[] = "Perf.PastVideoFramesDecoded";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesDecoded(int64_t value) {
  SetMetricInternal(kPerf_PastVideoFramesDecodedNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedName[] = "Perf.PastVideoFramesDropped";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesDropped(int64_t value) {
  SetMetricInternal(kPerf_PastVideoFramesDroppedNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientName[] = "Perf.PastVideoFramesPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesPowerEfficient(int64_t value) {
  SetMetricInternal(kPerf_PastVideoFramesPowerEfficientNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientName[] = "Perf.RecordIsPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_RecordIsPowerEfficient(int64_t value) {
  SetMetricInternal(kPerf_RecordIsPowerEfficientNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothName[] = "Perf.RecordIsSmooth";
const uint64_t Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_RecordIsSmooth(int64_t value) {
  SetMetricInternal(kPerf_RecordIsSmoothNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedName[] = "Perf.VideoFramesDecoded";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesDecoded(int64_t value) {
  SetMetricInternal(kPerf_VideoFramesDecodedNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedName[] = "Perf.VideoFramesDropped";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesDropped(int64_t value) {
  SetMetricInternal(kPerf_VideoFramesDroppedNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientName[] = "Perf.VideoFramesPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesPowerEfficient(int64_t value) {
  SetMetricInternal(kPerf_VideoFramesPowerEfficientNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_CodecProfileName[] = "Video.CodecProfile";
const uint64_t Media_VideoDecodePerfRecord::kVideo_CodecProfileNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_CodecProfile(int64_t value) {
  SetMetricInternal(kVideo_CodecProfileNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_EME_KeySystemName[] = "Video.EME.KeySystem";
const uint64_t Media_VideoDecodePerfRecord::kVideo_EME_KeySystemNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_EME_KeySystem(int64_t value) {
  SetMetricInternal(kVideo_EME_KeySystemNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsName[] = "Video.EME.UseHwSecureCodecs";
const uint64_t Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_EME_UseHwSecureCodecs(int64_t value) {
  SetMetricInternal(kVideo_EME_UseHwSecureCodecsNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_FramesPerSecondName[] = "Video.FramesPerSecond";
const uint64_t Media_VideoDecodePerfRecord::kVideo_FramesPerSecondNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_FramesPerSecond(int64_t value) {
  SetMetricInternal(kVideo_FramesPerSecondNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_InTopFrameName[] = "Video.InTopFrame";
const uint64_t Media_VideoDecodePerfRecord::kVideo_InTopFrameNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_InTopFrame(int64_t value) {
  SetMetricInternal(kVideo_InTopFrameNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_NaturalHeightName[] = "Video.NaturalHeight";
const uint64_t Media_VideoDecodePerfRecord::kVideo_NaturalHeightNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_NaturalHeight(int64_t value) {
  SetMetricInternal(kVideo_NaturalHeightNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_NaturalWidthName[] = "Video.NaturalWidth";
const uint64_t Media_VideoDecodePerfRecord::kVideo_NaturalWidthNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_NaturalWidth(int64_t value) {
  SetMetricInternal(kVideo_NaturalWidthNameHash, value);
  return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_PlayerIDName[] = "Video.PlayerID";
const uint64_t Media_VideoDecodePerfRecord::kVideo_PlayerIDNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_PlayerID(int64_t value) {
  SetMetricInternal(kVideo_PlayerIDNameHash, value);
  return *this;
}


const char Media_WebAudio_AudioContext_AudibleTime::kEntryName[] = "Media.WebAudio.AudioContext.AudibleTime";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kEntryNameHash;

Media_WebAudio_AudioContext_AudibleTime::Media_WebAudio_AudioContext_AudibleTime(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_WebAudio_AudioContext_AudibleTime::Media_WebAudio_AudioContext_AudibleTime(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_WebAudio_AudioContext_AudibleTime::~Media_WebAudio_AudioContext_AudibleTime() = default;


const char Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeName[] = "AudibleTime";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeNameHash;

Media_WebAudio_AudioContext_AudibleTime& Media_WebAudio_AudioContext_AudibleTime::SetAudibleTime(int64_t value) {
  SetMetricInternal(kAudibleTimeNameHash, value);
  return *this;
}

const char Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameName[] = "IsMainFrame";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameNameHash;

Media_WebAudio_AudioContext_AudibleTime& Media_WebAudio_AudioContext_AudibleTime::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}


const char Media_WebMediaPlayerState::kEntryName[] = "Media.WebMediaPlayerState";
const uint64_t Media_WebMediaPlayerState::kEntryNameHash;

Media_WebMediaPlayerState::Media_WebMediaPlayerState(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_WebMediaPlayerState::Media_WebMediaPlayerState(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Media_WebMediaPlayerState::~Media_WebMediaPlayerState() = default;


const char Media_WebMediaPlayerState::kContainerNameName[] = "ContainerName";
const uint64_t Media_WebMediaPlayerState::kContainerNameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetContainerName(int64_t value) {
  SetMetricInternal(kContainerNameNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kFinalPipelineStatusName[] = "FinalPipelineStatus";
const uint64_t Media_WebMediaPlayerState::kFinalPipelineStatusNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetFinalPipelineStatus(int64_t value) {
  SetMetricInternal(kFinalPipelineStatusNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kIsEMEName[] = "IsEME";
const uint64_t Media_WebMediaPlayerState::kIsEMENameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsEME(int64_t value) {
  SetMetricInternal(kIsEMENameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kIsMSEName[] = "IsMSE";
const uint64_t Media_WebMediaPlayerState::kIsMSENameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsMSE(int64_t value) {
  SetMetricInternal(kIsMSENameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_WebMediaPlayerState::kIsTopFrameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsTopFrame(int64_t value) {
  SetMetricInternal(kIsTopFrameNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kPlayerIDName[] = "PlayerID";
const uint64_t Media_WebMediaPlayerState::kPlayerIDNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetPlayerID(int64_t value) {
  SetMetricInternal(kPlayerIDNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kTimeToFirstFrameName[] = "TimeToFirstFrame";
const uint64_t Media_WebMediaPlayerState::kTimeToFirstFrameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToFirstFrame(int64_t value) {
  SetMetricInternal(kTimeToFirstFrameNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kTimeToMetadataName[] = "TimeToMetadata";
const uint64_t Media_WebMediaPlayerState::kTimeToMetadataNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToMetadata(int64_t value) {
  SetMetricInternal(kTimeToMetadataNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kTimeToPlayReadyName[] = "TimeToPlayReady";
const uint64_t Media_WebMediaPlayerState::kTimeToPlayReadyNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToPlayReady(int64_t value) {
  SetMetricInternal(kTimeToPlayReadyNameHash, value);
  return *this;
}

const char Media_WebMediaPlayerState::kURLSchemeName[] = "URLScheme";
const uint64_t Media_WebMediaPlayerState::kURLSchemeNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetURLScheme(int64_t value) {
  SetMetricInternal(kURLSchemeNameHash, value);
  return *this;
}


const char MediaRouter_TabMirroringStarted::kEntryName[] = "MediaRouter.TabMirroringStarted";
const uint64_t MediaRouter_TabMirroringStarted::kEntryNameHash;

MediaRouter_TabMirroringStarted::MediaRouter_TabMirroringStarted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MediaRouter_TabMirroringStarted::MediaRouter_TabMirroringStarted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MediaRouter_TabMirroringStarted::~MediaRouter_TabMirroringStarted() = default;


const char MediaRouter_TabMirroringStarted::kAudioStateName[] = "AudioState";
const uint64_t MediaRouter_TabMirroringStarted::kAudioStateNameHash;

MediaRouter_TabMirroringStarted& MediaRouter_TabMirroringStarted::SetAudioState(int64_t value) {
  SetMetricInternal(kAudioStateNameHash, value);
  return *this;
}


const char Memory_Experimental::kEntryName[] = "Memory.Experimental";
const uint64_t Memory_Experimental::kEntryNameHash;

Memory_Experimental::Memory_Experimental(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Memory_Experimental::Memory_Experimental(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Memory_Experimental::~Memory_Experimental() = default;


const char Memory_Experimental::kArrayBufferName[] = "ArrayBuffer";
const uint64_t Memory_Experimental::kArrayBufferNameHash;

Memory_Experimental& Memory_Experimental::SetArrayBuffer(int64_t value) {
  SetMetricInternal(kArrayBufferNameHash, value);
  return *this;
}

const char Memory_Experimental::kBlinkGCName[] = "BlinkGC";
const uint64_t Memory_Experimental::kBlinkGCNameHash;

Memory_Experimental& Memory_Experimental::SetBlinkGC(int64_t value) {
  SetMetricInternal(kBlinkGCNameHash, value);
  return *this;
}

const char Memory_Experimental::kBlinkGC_AllocatedObjectsName[] = "BlinkGC.AllocatedObjects";
const uint64_t Memory_Experimental::kBlinkGC_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetBlinkGC_AllocatedObjects(int64_t value) {
  SetMetricInternal(kBlinkGC_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kCanvasResourceProvider_SkSurfaceName[] = "CanvasResourceProvider.SkSurface";
const uint64_t Memory_Experimental::kCanvasResourceProvider_SkSurfaceNameHash;

Memory_Experimental& Memory_Experimental::SetCanvasResourceProvider_SkSurface(int64_t value) {
  SetMetricInternal(kCanvasResourceProvider_SkSurfaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kCommandBufferName[] = "CommandBuffer";
const uint64_t Memory_Experimental::kCommandBufferNameHash;

Memory_Experimental& Memory_Experimental::SetCommandBuffer(int64_t value) {
  SetMetricInternal(kCommandBufferNameHash, value);
  return *this;
}

const char Memory_Experimental::kDiscardableName[] = "Discardable";
const uint64_t Memory_Experimental::kDiscardableNameHash;

Memory_Experimental& Memory_Experimental::SetDiscardable(int64_t value) {
  SetMetricInternal(kDiscardableNameHash, value);
  return *this;
}

const char Memory_Experimental::kDownloadServiceName[] = "DownloadService";
const uint64_t Memory_Experimental::kDownloadServiceNameHash;

Memory_Experimental& Memory_Experimental::SetDownloadService(int64_t value) {
  SetMetricInternal(kDownloadServiceNameHash, value);
  return *this;
}

const char Memory_Experimental::kExtensions_ValueStoreName[] = "Extensions.ValueStore";
const uint64_t Memory_Experimental::kExtensions_ValueStoreNameHash;

Memory_Experimental& Memory_Experimental::SetExtensions_ValueStore(int64_t value) {
  SetMetricInternal(kExtensions_ValueStoreNameHash, value);
  return *this;
}

const char Memory_Experimental::kFontCachesName[] = "FontCaches";
const uint64_t Memory_Experimental::kFontCachesNameHash;

Memory_Experimental& Memory_Experimental::SetFontCaches(int64_t value) {
  SetMetricInternal(kFontCachesNameHash, value);
  return *this;
}

const char Memory_Experimental::kGpuMemoryName[] = "GpuMemory";
const uint64_t Memory_Experimental::kGpuMemoryNameHash;

Memory_Experimental& Memory_Experimental::SetGpuMemory(int64_t value) {
  SetMetricInternal(kGpuMemoryNameHash, value);
  return *this;
}

const char Memory_Experimental::kHistoryName[] = "History";
const uint64_t Memory_Experimental::kHistoryNameHash;

Memory_Experimental& Memory_Experimental::SetHistory(int64_t value) {
  SetMetricInternal(kHistoryNameHash, value);
  return *this;
}

const char Memory_Experimental::kIsVisibleName[] = "IsVisible";
const uint64_t Memory_Experimental::kIsVisibleNameHash;

Memory_Experimental& Memory_Experimental::SetIsVisible(int64_t value) {
  SetMetricInternal(kIsVisibleNameHash, value);
  return *this;
}

const char Memory_Experimental::kJavaHeapName[] = "JavaHeap";
const uint64_t Memory_Experimental::kJavaHeapNameHash;

Memory_Experimental& Memory_Experimental::SetJavaHeap(int64_t value) {
  SetMetricInternal(kJavaHeapNameHash, value);
  return *this;
}

const char Memory_Experimental::kLevelDatabaseName[] = "LevelDatabase";
const uint64_t Memory_Experimental::kLevelDatabaseNameHash;

Memory_Experimental& Memory_Experimental::SetLevelDatabase(int64_t value) {
  SetMetricInternal(kLevelDatabaseNameHash, value);
  return *this;
}

const char Memory_Experimental::kMallocName[] = "Malloc";
const uint64_t Memory_Experimental::kMallocNameHash;

Memory_Experimental& Memory_Experimental::SetMalloc(int64_t value) {
  SetMetricInternal(kMallocNameHash, value);
  return *this;
}

const char Memory_Experimental::kMalloc_AllocatedObjectsName[] = "Malloc.AllocatedObjects";
const uint64_t Memory_Experimental::kMalloc_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetMalloc_AllocatedObjects(int64_t value) {
  SetMetricInternal(kMalloc_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kNetName[] = "Net";
const uint64_t Memory_Experimental::kNetNameHash;

Memory_Experimental& Memory_Experimental::SetNet(int64_t value) {
  SetMetricInternal(kNetNameHash, value);
  return *this;
}

const char Memory_Experimental::kNet_UrlRequestContextName[] = "Net.UrlRequestContext";
const uint64_t Memory_Experimental::kNet_UrlRequestContextNameHash;

Memory_Experimental& Memory_Experimental::SetNet_UrlRequestContext(int64_t value) {
  SetMetricInternal(kNet_UrlRequestContextNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfAdSubframesName[] = "NumberOfAdSubframes";
const uint64_t Memory_Experimental::kNumberOfAdSubframesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfAdSubframes(int64_t value) {
  SetMetricInternal(kNumberOfAdSubframesNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfArrayBufferContentsName[] = "NumberOfArrayBufferContents";
const uint64_t Memory_Experimental::kNumberOfArrayBufferContentsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfArrayBufferContents(int64_t value) {
  SetMetricInternal(kNumberOfArrayBufferContentsNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfDetachedScriptStatesName[] = "NumberOfDetachedScriptStates";
const uint64_t Memory_Experimental::kNumberOfDetachedScriptStatesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfDetachedScriptStates(int64_t value) {
  SetMetricInternal(kNumberOfDetachedScriptStatesNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfDocumentsName[] = "NumberOfDocuments";
const uint64_t Memory_Experimental::kNumberOfDocumentsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfDocuments(int64_t value) {
  SetMetricInternal(kNumberOfDocumentsNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfExtensionsName[] = "NumberOfExtensions";
const uint64_t Memory_Experimental::kNumberOfExtensionsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfExtensions(int64_t value) {
  SetMetricInternal(kNumberOfExtensionsNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfFramesName[] = "NumberOfFrames";
const uint64_t Memory_Experimental::kNumberOfFramesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfFrames(int64_t value) {
  SetMetricInternal(kNumberOfFramesNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfLayoutObjectsName[] = "NumberOfLayoutObjects";
const uint64_t Memory_Experimental::kNumberOfLayoutObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfLayoutObjects(int64_t value) {
  SetMetricInternal(kNumberOfLayoutObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfMojoHandlesName[] = "NumberOfMojoHandles";
const uint64_t Memory_Experimental::kNumberOfMojoHandlesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfMojoHandles(int64_t value) {
  SetMetricInternal(kNumberOfMojoHandlesNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfNodesName[] = "NumberOfNodes";
const uint64_t Memory_Experimental::kNumberOfNodesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfNodes(int64_t value) {
  SetMetricInternal(kNumberOfNodesNameHash, value);
  return *this;
}

const char Memory_Experimental::kNumberOfWebMediaPlayersName[] = "NumberOfWebMediaPlayers";
const uint64_t Memory_Experimental::kNumberOfWebMediaPlayersNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfWebMediaPlayers(int64_t value) {
  SetMetricInternal(kNumberOfWebMediaPlayersNameHash, value);
  return *this;
}

const char Memory_Experimental::kOmniboxSuggestionsName[] = "OmniboxSuggestions";
const uint64_t Memory_Experimental::kOmniboxSuggestionsNameHash;

Memory_Experimental& Memory_Experimental::SetOmniboxSuggestions(int64_t value) {
  SetMetricInternal(kOmniboxSuggestionsNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAllocName[] = "PartitionAlloc";
const uint64_t Memory_Experimental::kPartitionAllocNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc(int64_t value) {
  SetMetricInternal(kPartitionAllocNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAlloc_AllocatedObjectsName[] = "PartitionAlloc.AllocatedObjects";
const uint64_t Memory_Experimental::kPartitionAlloc_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_AllocatedObjects(int64_t value) {
  SetMetricInternal(kPartitionAlloc_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferName[] = "PartitionAlloc.Partitions.ArrayBuffer";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_ArrayBuffer(int64_t value) {
  SetMetricInternal(kPartitionAlloc_Partitions_ArrayBufferNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_BufferName[] = "PartitionAlloc.Partitions.Buffer";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_BufferNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_Buffer(int64_t value) {
  SetMetricInternal(kPartitionAlloc_Partitions_BufferNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_FastMallocName[] = "PartitionAlloc.Partitions.FastMalloc";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_FastMallocNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_FastMalloc(int64_t value) {
  SetMetricInternal(kPartitionAlloc_Partitions_FastMallocNameHash, value);
  return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_LayoutName[] = "PartitionAlloc.Partitions.Layout";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_LayoutNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_Layout(int64_t value) {
  SetMetricInternal(kPartitionAlloc_Partitions_LayoutNameHash, value);
  return *this;
}

const char Memory_Experimental::kPrivateMemoryFootprintName[] = "PrivateMemoryFootprint";
const uint64_t Memory_Experimental::kPrivateMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetPrivateMemoryFootprint(int64_t value) {
  SetMetricInternal(kPrivateMemoryFootprintNameHash, value);
  return *this;
}

const char Memory_Experimental::kPrivateSwapFootprintName[] = "PrivateSwapFootprint";
const uint64_t Memory_Experimental::kPrivateSwapFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetPrivateSwapFootprint(int64_t value) {
  SetMetricInternal(kPrivateSwapFootprintNameHash, value);
  return *this;
}

const char Memory_Experimental::kProcessTypeName[] = "ProcessType";
const uint64_t Memory_Experimental::kProcessTypeNameHash;

Memory_Experimental& Memory_Experimental::SetProcessType(int64_t value) {
  SetMetricInternal(kProcessTypeNameHash, value);
  return *this;
}

const char Memory_Experimental::kResidentName[] = "Resident";
const uint64_t Memory_Experimental::kResidentNameHash;

Memory_Experimental& Memory_Experimental::SetResident(int64_t value) {
  SetMetricInternal(kResidentNameHash, value);
  return *this;
}

const char Memory_Experimental::kSharedMemoryFootprintName[] = "SharedMemoryFootprint";
const uint64_t Memory_Experimental::kSharedMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetSharedMemoryFootprint(int64_t value) {
  SetMetricInternal(kSharedMemoryFootprintNameHash, value);
  return *this;
}

const char Memory_Experimental::kSiteStorageName[] = "SiteStorage";
const uint64_t Memory_Experimental::kSiteStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage(int64_t value) {
  SetMetricInternal(kSiteStorageNameHash, value);
  return *this;
}

const char Memory_Experimental::kSiteStorage_BlobStorageName[] = "SiteStorage.BlobStorage";
const uint64_t Memory_Experimental::kSiteStorage_BlobStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_BlobStorage(int64_t value) {
  SetMetricInternal(kSiteStorage_BlobStorageNameHash, value);
  return *this;
}

const char Memory_Experimental::kSiteStorage_IndexDBName[] = "SiteStorage.IndexDB";
const uint64_t Memory_Experimental::kSiteStorage_IndexDBNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_IndexDB(int64_t value) {
  SetMetricInternal(kSiteStorage_IndexDBNameHash, value);
  return *this;
}

const char Memory_Experimental::kSiteStorage_LocalStorageName[] = "SiteStorage.LocalStorage";
const uint64_t Memory_Experimental::kSiteStorage_LocalStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_LocalStorage(int64_t value) {
  SetMetricInternal(kSiteStorage_LocalStorageNameHash, value);
  return *this;
}

const char Memory_Experimental::kSiteStorage_SessionStorageName[] = "SiteStorage.SessionStorage";
const uint64_t Memory_Experimental::kSiteStorage_SessionStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_SessionStorage(int64_t value) {
  SetMetricInternal(kSiteStorage_SessionStorageNameHash, value);
  return *this;
}

const char Memory_Experimental::kSkiaName[] = "Skia";
const uint64_t Memory_Experimental::kSkiaNameHash;

Memory_Experimental& Memory_Experimental::SetSkia(int64_t value) {
  SetMetricInternal(kSkiaNameHash, value);
  return *this;
}

const char Memory_Experimental::kSkia_SkGlyphCacheName[] = "Skia.SkGlyphCache";
const uint64_t Memory_Experimental::kSkia_SkGlyphCacheNameHash;

Memory_Experimental& Memory_Experimental::SetSkia_SkGlyphCache(int64_t value) {
  SetMetricInternal(kSkia_SkGlyphCacheNameHash, value);
  return *this;
}

const char Memory_Experimental::kSkia_SkResourceCacheName[] = "Skia.SkResourceCache";
const uint64_t Memory_Experimental::kSkia_SkResourceCacheNameHash;

Memory_Experimental& Memory_Experimental::SetSkia_SkResourceCache(int64_t value) {
  SetMetricInternal(kSkia_SkResourceCacheNameHash, value);
  return *this;
}

const char Memory_Experimental::kSqliteName[] = "Sqlite";
const uint64_t Memory_Experimental::kSqliteNameHash;

Memory_Experimental& Memory_Experimental::SetSqlite(int64_t value) {
  SetMetricInternal(kSqliteNameHash, value);
  return *this;
}

const char Memory_Experimental::kSyncName[] = "Sync";
const uint64_t Memory_Experimental::kSyncNameHash;

Memory_Experimental& Memory_Experimental::SetSync(int64_t value) {
  SetMetricInternal(kSyncNameHash, value);
  return *this;
}

const char Memory_Experimental::kTabRestoreName[] = "TabRestore";
const uint64_t Memory_Experimental::kTabRestoreNameHash;

Memory_Experimental& Memory_Experimental::SetTabRestore(int64_t value) {
  SetMetricInternal(kTabRestoreNameHash, value);
  return *this;
}

const char Memory_Experimental::kTimeSinceLastNavigationName[] = "TimeSinceLastNavigation";
const uint64_t Memory_Experimental::kTimeSinceLastNavigationNameHash;

Memory_Experimental& Memory_Experimental::SetTimeSinceLastNavigation(int64_t value) {
  SetMetricInternal(kTimeSinceLastNavigationNameHash, value);
  return *this;
}

const char Memory_Experimental::kTimeSinceLastVisibilityChangeName[] = "TimeSinceLastVisibilityChange";
const uint64_t Memory_Experimental::kTimeSinceLastVisibilityChangeNameHash;

Memory_Experimental& Memory_Experimental::SetTimeSinceLastVisibilityChange(int64_t value) {
  SetMetricInternal(kTimeSinceLastVisibilityChangeNameHash, value);
  return *this;
}

const char Memory_Experimental::kTotal2_PrivateMemoryFootprintName[] = "Total2.PrivateMemoryFootprint";
const uint64_t Memory_Experimental::kTotal2_PrivateMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetTotal2_PrivateMemoryFootprint(int64_t value) {
  SetMetricInternal(kTotal2_PrivateMemoryFootprintNameHash, value);
  return *this;
}

const char Memory_Experimental::kTotal2_SharedMemoryFootprintName[] = "Total2.SharedMemoryFootprint";
const uint64_t Memory_Experimental::kTotal2_SharedMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetTotal2_SharedMemoryFootprint(int64_t value) {
  SetMetricInternal(kTotal2_SharedMemoryFootprintNameHash, value);
  return *this;
}

const char Memory_Experimental::kUIName[] = "UI";
const uint64_t Memory_Experimental::kUINameHash;

Memory_Experimental& Memory_Experimental::SetUI(int64_t value) {
  SetMetricInternal(kUINameHash, value);
  return *this;
}

const char Memory_Experimental::kUptimeName[] = "Uptime";
const uint64_t Memory_Experimental::kUptimeNameHash;

Memory_Experimental& Memory_Experimental::SetUptime(int64_t value) {
  SetMetricInternal(kUptimeNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8Name[] = "V8";
const uint64_t Memory_Experimental::kV8NameHash;

Memory_Experimental& Memory_Experimental::SetV8(int64_t value) {
  SetMetricInternal(kV8NameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_AllocatedObjectsName[] = "V8.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_MainName[] = "V8.Main";
const uint64_t Memory_Experimental::kV8_MainNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main(int64_t value) {
  SetMetricInternal(kV8_MainNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_AllocatedObjectsName[] = "V8.Main.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_GlobalHandlesName[] = "V8.Main.GlobalHandles";
const uint64_t Memory_Experimental::kV8_Main_GlobalHandlesNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_GlobalHandles(int64_t value) {
  SetMetricInternal(kV8_Main_GlobalHandlesNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_HeapName[] = "V8.Main.Heap";
const uint64_t Memory_Experimental::kV8_Main_HeapNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap(int64_t value) {
  SetMetricInternal(kV8_Main_HeapNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_AllocatedObjectsName[] = "V8.Main.Heap.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceName[] = "V8.Main.Heap.CodeLargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeLargeObjectSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_CodeLargeObjectSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.CodeLargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeSpaceName[] = "V8.Main.Heap.CodeSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_CodeSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsName[] = "V8.Main.Heap.CodeSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceName[] = "V8.Main.Heap.LargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_LargeObjectSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_LargeObjectSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.LargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_LargeObjectSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_MapSpaceName[] = "V8.Main.Heap.MapSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_MapSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_MapSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_MapSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsName[] = "V8.Main.Heap.MapSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_MapSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceName[] = "V8.Main.Heap.NewLargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewLargeObjectSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_NewLargeObjectSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.NewLargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewLargeObjectSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewSpaceName[] = "V8.Main.Heap.NewSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_NewSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsName[] = "V8.Main.Heap.NewSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_OldSpaceName[] = "V8.Main.Heap.OldSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_OldSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_OldSpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_OldSpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsName[] = "V8.Main.Heap.OldSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_OldSpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceName[] = "V8.Main.Heap.ReadOnlySpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_ReadOnlySpace(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_ReadOnlySpaceNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName[] = "V8.Main.Heap.ReadOnlySpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_ReadOnlySpace_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Main_MallocName[] = "V8.Main.Malloc";
const uint64_t Memory_Experimental::kV8_Main_MallocNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Malloc(int64_t value) {
  SetMetricInternal(kV8_Main_MallocNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_WorkersName[] = "V8.Workers";
const uint64_t Memory_Experimental::kV8_WorkersNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Workers(int64_t value) {
  SetMetricInternal(kV8_WorkersNameHash, value);
  return *this;
}

const char Memory_Experimental::kV8_Workers_AllocatedObjectsName[] = "V8.Workers.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Workers_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Workers_AllocatedObjects(int64_t value) {
  SetMetricInternal(kV8_Workers_AllocatedObjectsNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCacheName[] = "WebCache";
const uint64_t Memory_Experimental::kWebCacheNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache(int64_t value) {
  SetMetricInternal(kWebCacheNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_CSSStylesheetResourcesName[] = "WebCache.CSSStylesheetResources";
const uint64_t Memory_Experimental::kWebCache_CSSStylesheetResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_CSSStylesheetResources(int64_t value) {
  SetMetricInternal(kWebCache_CSSStylesheetResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsName[] = "WebCache.EncodedSizeDuplicatedInDataUrls";
const uint64_t Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_EncodedSizeDuplicatedInDataUrls(int64_t value) {
  SetMetricInternal(kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_FontResourcesName[] = "WebCache.FontResources";
const uint64_t Memory_Experimental::kWebCache_FontResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_FontResources(int64_t value) {
  SetMetricInternal(kWebCache_FontResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_ImageResourcesName[] = "WebCache.ImageResources";
const uint64_t Memory_Experimental::kWebCache_ImageResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_ImageResources(int64_t value) {
  SetMetricInternal(kWebCache_ImageResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_OtherResourcesName[] = "WebCache.OtherResources";
const uint64_t Memory_Experimental::kWebCache_OtherResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_OtherResources(int64_t value) {
  SetMetricInternal(kWebCache_OtherResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_ScriptResourcesName[] = "WebCache.ScriptResources";
const uint64_t Memory_Experimental::kWebCache_ScriptResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_ScriptResources(int64_t value) {
  SetMetricInternal(kWebCache_ScriptResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_V8CodeCacheName[] = "WebCache.V8CodeCache";
const uint64_t Memory_Experimental::kWebCache_V8CodeCacheNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_V8CodeCache(int64_t value) {
  SetMetricInternal(kWebCache_V8CodeCacheNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebCache_XSLStylesheetResourcesName[] = "WebCache.XSLStylesheetResources";
const uint64_t Memory_Experimental::kWebCache_XSLStylesheetResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_XSLStylesheetResources(int64_t value) {
  SetMetricInternal(kWebCache_XSLStylesheetResourcesNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebMediaPlayer_AudioName[] = "WebMediaPlayer.Audio";
const uint64_t Memory_Experimental::kWebMediaPlayer_AudioNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Audio(int64_t value) {
  SetMetricInternal(kWebMediaPlayer_AudioNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebMediaPlayer_DataSourceName[] = "WebMediaPlayer.DataSource";
const uint64_t Memory_Experimental::kWebMediaPlayer_DataSourceNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_DataSource(int64_t value) {
  SetMetricInternal(kWebMediaPlayer_DataSourceNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebMediaPlayer_DemuxerName[] = "WebMediaPlayer.Demuxer";
const uint64_t Memory_Experimental::kWebMediaPlayer_DemuxerNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Demuxer(int64_t value) {
  SetMetricInternal(kWebMediaPlayer_DemuxerNameHash, value);
  return *this;
}

const char Memory_Experimental::kWebMediaPlayer_VideoName[] = "WebMediaPlayer.Video";
const uint64_t Memory_Experimental::kWebMediaPlayer_VideoNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Video(int64_t value) {
  SetMetricInternal(kWebMediaPlayer_VideoNameHash, value);
  return *this;
}


const char Memory_TabFootprint::kEntryName[] = "Memory.TabFootprint";
const uint64_t Memory_TabFootprint::kEntryNameHash;

Memory_TabFootprint::Memory_TabFootprint(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Memory_TabFootprint::Memory_TabFootprint(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Memory_TabFootprint::~Memory_TabFootprint() = default;


const char Memory_TabFootprint::kMainFrameProcessPMFName[] = "MainFrameProcessPMF";
const uint64_t Memory_TabFootprint::kMainFrameProcessPMFNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetMainFrameProcessPMF(int64_t value) {
  SetMetricInternal(kMainFrameProcessPMFNameHash, value);
  return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_ExcludedName[] = "SubFrameProcessPMF.Excluded";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_ExcludedNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Excluded(int64_t value) {
  SetMetricInternal(kSubFrameProcessPMF_ExcludedNameHash, value);
  return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_IncludedName[] = "SubFrameProcessPMF.Included";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_IncludedNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Included(int64_t value) {
  SetMetricInternal(kSubFrameProcessPMF_IncludedNameHash, value);
  return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_TotalName[] = "SubFrameProcessPMF.Total";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_TotalNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Total(int64_t value) {
  SetMetricInternal(kSubFrameProcessPMF_TotalNameHash, value);
  return *this;
}

const char Memory_TabFootprint::kTabPMFName[] = "TabPMF";
const uint64_t Memory_TabFootprint::kTabPMFNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetTabPMF(int64_t value) {
  SetMetricInternal(kTabPMFNameHash, value);
  return *this;
}


const char MixedContentAutoupgrade_ResourceRequest::kEntryName[] = "MixedContentAutoupgrade.ResourceRequest";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kEntryNameHash;

MixedContentAutoupgrade_ResourceRequest::MixedContentAutoupgrade_ResourceRequest(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MixedContentAutoupgrade_ResourceRequest::MixedContentAutoupgrade_ResourceRequest(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MixedContentAutoupgrade_ResourceRequest::~MixedContentAutoupgrade_ResourceRequest() = default;


const char MixedContentAutoupgrade_ResourceRequest::kCodeName[] = "Code";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kCodeNameHash;

MixedContentAutoupgrade_ResourceRequest& MixedContentAutoupgrade_ResourceRequest::SetCode(int64_t value) {
  SetMetricInternal(kCodeNameHash, value);
  return *this;
}

const char MixedContentAutoupgrade_ResourceRequest::kStatusName[] = "Status";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kStatusNameHash;

MixedContentAutoupgrade_ResourceRequest& MixedContentAutoupgrade_ResourceRequest::SetStatus(int64_t value) {
  SetMetricInternal(kStatusNameHash, value);
  return *this;
}


const char MobileMenu_DirectShare::kEntryName[] = "MobileMenu.DirectShare";
const uint64_t MobileMenu_DirectShare::kEntryNameHash;

MobileMenu_DirectShare::MobileMenu_DirectShare(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_DirectShare::MobileMenu_DirectShare(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_DirectShare::~MobileMenu_DirectShare() = default;


const char MobileMenu_DirectShare::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_DirectShare::kHasOccurredNameHash;

MobileMenu_DirectShare& MobileMenu_DirectShare::SetHasOccurred(int64_t value) {
  SetMetricInternal(kHasOccurredNameHash, value);
  return *this;
}


const char MobileMenu_FindInPage::kEntryName[] = "MobileMenu.FindInPage";
const uint64_t MobileMenu_FindInPage::kEntryNameHash;

MobileMenu_FindInPage::MobileMenu_FindInPage(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_FindInPage::MobileMenu_FindInPage(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_FindInPage::~MobileMenu_FindInPage() = default;


const char MobileMenu_FindInPage::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_FindInPage::kHasOccurredNameHash;

MobileMenu_FindInPage& MobileMenu_FindInPage::SetHasOccurred(int64_t value) {
  SetMetricInternal(kHasOccurredNameHash, value);
  return *this;
}


const char MobileMenu_Share::kEntryName[] = "MobileMenu.Share";
const uint64_t MobileMenu_Share::kEntryNameHash;

MobileMenu_Share::MobileMenu_Share(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_Share::MobileMenu_Share(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

MobileMenu_Share::~MobileMenu_Share() = default;


const char MobileMenu_Share::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_Share::kHasOccurredNameHash;

MobileMenu_Share& MobileMenu_Share::SetHasOccurred(int64_t value) {
  SetMetricInternal(kHasOccurredNameHash, value);
  return *this;
}


const char NavigationPredictorAnchorElementMetrics::kEntryName[] = "NavigationPredictorAnchorElementMetrics";
const uint64_t NavigationPredictorAnchorElementMetrics::kEntryNameHash;

NavigationPredictorAnchorElementMetrics::NavigationPredictorAnchorElementMetrics(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorAnchorElementMetrics::NavigationPredictorAnchorElementMetrics(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorAnchorElementMetrics::~NavigationPredictorAnchorElementMetrics() = default;


const char NavigationPredictorAnchorElementMetrics::kAnchorIndexName[] = "AnchorIndex";
const uint64_t NavigationPredictorAnchorElementMetrics::kAnchorIndexNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetAnchorIndex(int64_t value) {
  SetMetricInternal(kAnchorIndexNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kContainsImageName[] = "ContainsImage";
const uint64_t NavigationPredictorAnchorElementMetrics::kContainsImageNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetContainsImage(int64_t value) {
  SetMetricInternal(kContainsImageNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kIsInIframeName[] = "IsInIframe";
const uint64_t NavigationPredictorAnchorElementMetrics::kIsInIframeNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetIsInIframe(int64_t value) {
  SetMetricInternal(kIsInIframeNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneName[] = "IsURLIncrementedByOne";
const uint64_t NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetIsURLIncrementedByOne(int64_t value) {
  SetMetricInternal(kIsURLIncrementedByOneNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPercentClickableAreaName[] = "PercentClickableArea";
const uint64_t NavigationPredictorAnchorElementMetrics::kPercentClickableAreaNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPercentClickableArea(int64_t value) {
  SetMetricInternal(kPercentClickableAreaNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceName[] = "PercentVerticalDistance";
const uint64_t NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPercentVerticalDistance(int64_t value) {
  SetMetricInternal(kPercentVerticalDistanceNameHash, value);
  return *this;
}

const char NavigationPredictorAnchorElementMetrics::kSameOriginName[] = "SameOrigin";
const uint64_t NavigationPredictorAnchorElementMetrics::kSameOriginNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetSameOrigin(int64_t value) {
  SetMetricInternal(kSameOriginNameHash, value);
  return *this;
}


const char NavigationPredictorPageLinkClick::kEntryName[] = "NavigationPredictorPageLinkClick";
const uint64_t NavigationPredictorPageLinkClick::kEntryNameHash;

NavigationPredictorPageLinkClick::NavigationPredictorPageLinkClick(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorPageLinkClick::NavigationPredictorPageLinkClick(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorPageLinkClick::~NavigationPredictorPageLinkClick() = default;


const char NavigationPredictorPageLinkClick::kAnchorElementIndexName[] = "AnchorElementIndex";
const uint64_t NavigationPredictorPageLinkClick::kAnchorElementIndexNameHash;

NavigationPredictorPageLinkClick& NavigationPredictorPageLinkClick::SetAnchorElementIndex(int64_t value) {
  SetMetricInternal(kAnchorElementIndexNameHash, value);
  return *this;
}


const char NavigationPredictorPageLinkMetrics::kEntryName[] = "NavigationPredictorPageLinkMetrics";
const uint64_t NavigationPredictorPageLinkMetrics::kEntryNameHash;

NavigationPredictorPageLinkMetrics::NavigationPredictorPageLinkMetrics(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorPageLinkMetrics::NavigationPredictorPageLinkMetrics(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NavigationPredictorPageLinkMetrics::~NavigationPredictorPageLinkMetrics() = default;


const char NavigationPredictorPageLinkMetrics::kMedianLinkLocationName[] = "MedianLinkLocation";
const uint64_t NavigationPredictorPageLinkMetrics::kMedianLinkLocationNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetMedianLinkLocation(int64_t value) {
  SetMetricInternal(kMedianLinkLocationNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageName[] = "NumberOfAnchors.ContainsImage";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_ContainsImage(int64_t value) {
  SetMetricInternal(kNumberOfAnchors_ContainsImageNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeName[] = "NumberOfAnchors.InIframe";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_InIframe(int64_t value) {
  SetMetricInternal(kNumberOfAnchors_InIframeNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostName[] = "NumberOfAnchors.SameHost";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_SameHost(int64_t value) {
  SetMetricInternal(kNumberOfAnchors_SameHostNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalName[] = "NumberOfAnchors.Total";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_Total(int64_t value) {
  SetMetricInternal(kNumberOfAnchors_TotalNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedName[] = "NumberOfAnchors.URLIncremented";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_URLIncremented(int64_t value) {
  SetMetricInternal(kNumberOfAnchors_URLIncrementedNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kTotalClickableSpaceName[] = "TotalClickableSpace";
const uint64_t NavigationPredictorPageLinkMetrics::kTotalClickableSpaceNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetTotalClickableSpace(int64_t value) {
  SetMetricInternal(kTotalClickableSpaceNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kViewport_HeightName[] = "Viewport.Height";
const uint64_t NavigationPredictorPageLinkMetrics::kViewport_HeightNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetViewport_Height(int64_t value) {
  SetMetricInternal(kViewport_HeightNameHash, value);
  return *this;
}

const char NavigationPredictorPageLinkMetrics::kViewport_WidthName[] = "Viewport.Width";
const uint64_t NavigationPredictorPageLinkMetrics::kViewport_WidthNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetViewport_Width(int64_t value) {
  SetMetricInternal(kViewport_WidthNameHash, value);
  return *this;
}


const char Net_LegacyTLSVersion::kEntryName[] = "Net.LegacyTLSVersion";
const uint64_t Net_LegacyTLSVersion::kEntryNameHash;

Net_LegacyTLSVersion::Net_LegacyTLSVersion(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Net_LegacyTLSVersion::Net_LegacyTLSVersion(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Net_LegacyTLSVersion::~Net_LegacyTLSVersion() = default;


const char Net_LegacyTLSVersion::kIsAdResourceName[] = "IsAdResource";
const uint64_t Net_LegacyTLSVersion::kIsAdResourceNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsAdResource(int64_t value) {
  SetMetricInternal(kIsAdResourceNameHash, value);
  return *this;
}

const char Net_LegacyTLSVersion::kIsMainFrameName[] = "IsMainFrame";
const uint64_t Net_LegacyTLSVersion::kIsMainFrameNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char Net_LegacyTLSVersion::kIsSubresourceName[] = "IsSubresource";
const uint64_t Net_LegacyTLSVersion::kIsSubresourceNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsSubresource(int64_t value) {
  SetMetricInternal(kIsSubresourceNameHash, value);
  return *this;
}


const char NoStatePrefetch::kEntryName[] = "NoStatePrefetch";
const uint64_t NoStatePrefetch::kEntryNameHash;

NoStatePrefetch::NoStatePrefetch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NoStatePrefetch::NoStatePrefetch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

NoStatePrefetch::~NoStatePrefetch() = default;


const char NoStatePrefetch::kPrefetchedRecently_FinalStatusName[] = "PrefetchedRecently.FinalStatus";
const uint64_t NoStatePrefetch::kPrefetchedRecently_FinalStatusNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_FinalStatus(int64_t value) {
  SetMetricInternal(kPrefetchedRecently_FinalStatusNameHash, value);
  return *this;
}

const char NoStatePrefetch::kPrefetchedRecently_OriginName[] = "PrefetchedRecently.Origin";
const uint64_t NoStatePrefetch::kPrefetchedRecently_OriginNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_Origin(int64_t value) {
  SetMetricInternal(kPrefetchedRecently_OriginNameHash, value);
  return *this;
}

const char NoStatePrefetch::kPrefetchedRecently_PrefetchAgeName[] = "PrefetchedRecently.PrefetchAge";
const uint64_t NoStatePrefetch::kPrefetchedRecently_PrefetchAgeNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_PrefetchAge(int64_t value) {
  SetMetricInternal(kPrefetchedRecently_PrefetchAgeNameHash, value);
  return *this;
}


const char Notification::kEntryName[] = "Notification";
const uint64_t Notification::kEntryNameHash;

Notification::Notification(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Notification::Notification(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Notification::~Notification() = default;


const char Notification::kClosedReasonName[] = "ClosedReason";
const uint64_t Notification::kClosedReasonNameHash;

Notification& Notification::SetClosedReason(int64_t value) {
  SetMetricInternal(kClosedReasonNameHash, value);
  return *this;
}

const char Notification::kDidReplaceAnotherNotificationName[] = "DidReplaceAnotherNotification";
const uint64_t Notification::kDidReplaceAnotherNotificationNameHash;

Notification& Notification::SetDidReplaceAnotherNotification(int64_t value) {
  SetMetricInternal(kDidReplaceAnotherNotificationNameHash, value);
  return *this;
}

const char Notification::kDidUserOpenSettingsName[] = "DidUserOpenSettings";
const uint64_t Notification::kDidUserOpenSettingsNameHash;

Notification& Notification::SetDidUserOpenSettings(int64_t value) {
  SetMetricInternal(kDidUserOpenSettingsNameHash, value);
  return *this;
}

const char Notification::kHasBadgeName[] = "HasBadge";
const uint64_t Notification::kHasBadgeNameHash;

Notification& Notification::SetHasBadge(int64_t value) {
  SetMetricInternal(kHasBadgeNameHash, value);
  return *this;
}

const char Notification::kHasIconName[] = "HasIcon";
const uint64_t Notification::kHasIconNameHash;

Notification& Notification::SetHasIcon(int64_t value) {
  SetMetricInternal(kHasIconNameHash, value);
  return *this;
}

const char Notification::kHasImageName[] = "HasImage";
const uint64_t Notification::kHasImageNameHash;

Notification& Notification::SetHasImage(int64_t value) {
  SetMetricInternal(kHasImageNameHash, value);
  return *this;
}

const char Notification::kHasRenotifyName[] = "HasRenotify";
const uint64_t Notification::kHasRenotifyNameHash;

Notification& Notification::SetHasRenotify(int64_t value) {
  SetMetricInternal(kHasRenotifyNameHash, value);
  return *this;
}

const char Notification::kHasTagName[] = "HasTag";
const uint64_t Notification::kHasTagNameHash;

Notification& Notification::SetHasTag(int64_t value) {
  SetMetricInternal(kHasTagNameHash, value);
  return *this;
}

const char Notification::kIsSilentName[] = "IsSilent";
const uint64_t Notification::kIsSilentNameHash;

Notification& Notification::SetIsSilent(int64_t value) {
  SetMetricInternal(kIsSilentNameHash, value);
  return *this;
}

const char Notification::kNumActionButtonClicksName[] = "NumActionButtonClicks";
const uint64_t Notification::kNumActionButtonClicksNameHash;

Notification& Notification::SetNumActionButtonClicks(int64_t value) {
  SetMetricInternal(kNumActionButtonClicksNameHash, value);
  return *this;
}

const char Notification::kNumActionsName[] = "NumActions";
const uint64_t Notification::kNumActionsNameHash;

Notification& Notification::SetNumActions(int64_t value) {
  SetMetricInternal(kNumActionsNameHash, value);
  return *this;
}

const char Notification::kNumClicksName[] = "NumClicks";
const uint64_t Notification::kNumClicksNameHash;

Notification& Notification::SetNumClicks(int64_t value) {
  SetMetricInternal(kNumClicksNameHash, value);
  return *this;
}

const char Notification::kRequireInteractionName[] = "RequireInteraction";
const uint64_t Notification::kRequireInteractionNameHash;

Notification& Notification::SetRequireInteraction(int64_t value) {
  SetMetricInternal(kRequireInteractionNameHash, value);
  return *this;
}

const char Notification::kTimeUntilCloseName[] = "TimeUntilClose";
const uint64_t Notification::kTimeUntilCloseNameHash;

Notification& Notification::SetTimeUntilClose(int64_t value) {
  SetMetricInternal(kTimeUntilCloseNameHash, value);
  return *this;
}

const char Notification::kTimeUntilFirstClickName[] = "TimeUntilFirstClick";
const uint64_t Notification::kTimeUntilFirstClickNameHash;

Notification& Notification::SetTimeUntilFirstClick(int64_t value) {
  SetMetricInternal(kTimeUntilFirstClickNameHash, value);
  return *this;
}

const char Notification::kTimeUntilLastClickName[] = "TimeUntilLastClick";
const uint64_t Notification::kTimeUntilLastClickNameHash;

Notification& Notification::SetTimeUntilLastClick(int64_t value) {
  SetMetricInternal(kTimeUntilLastClickNameHash, value);
  return *this;
}


const char OptimizationGuide::kEntryName[] = "OptimizationGuide";
const uint64_t OptimizationGuide::kEntryNameHash;

OptimizationGuide::OptimizationGuide(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

OptimizationGuide::OptimizationGuide(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

OptimizationGuide::~OptimizationGuide() = default;


const char OptimizationGuide::kNavigationHintsFetchAttemptStatusName[] = "NavigationHintsFetchAttemptStatus";
const uint64_t OptimizationGuide::kNavigationHintsFetchAttemptStatusNameHash;

OptimizationGuide& OptimizationGuide::SetNavigationHintsFetchAttemptStatus(int64_t value) {
  SetMetricInternal(kNavigationHintsFetchAttemptStatusNameHash, value);
  return *this;
}

const char OptimizationGuide::kNavigationHintsFetchRequestLatencyName[] = "NavigationHintsFetchRequestLatency";
const uint64_t OptimizationGuide::kNavigationHintsFetchRequestLatencyNameHash;

OptimizationGuide& OptimizationGuide::SetNavigationHintsFetchRequestLatency(int64_t value) {
  SetMetricInternal(kNavigationHintsFetchRequestLatencyNameHash, value);
  return *this;
}

const char OptimizationGuide::kPainfulPageLoadModelPredictionScoreName[] = "PainfulPageLoadModelPredictionScore";
const uint64_t OptimizationGuide::kPainfulPageLoadModelPredictionScoreNameHash;

OptimizationGuide& OptimizationGuide::SetPainfulPageLoadModelPredictionScore(int64_t value) {
  SetMetricInternal(kPainfulPageLoadModelPredictionScoreNameHash, value);
  return *this;
}

const char OptimizationGuide::kPainfulPageLoadModelVersionName[] = "PainfulPageLoadModelVersion";
const uint64_t OptimizationGuide::kPainfulPageLoadModelVersionNameHash;

OptimizationGuide& OptimizationGuide::SetPainfulPageLoadModelVersion(int64_t value) {
  SetMetricInternal(kPainfulPageLoadModelVersionNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeatureEffectiveConnectionTypeName[] = "PredictionModelFeatureEffectiveConnectionType";
const uint64_t OptimizationGuide::kPredictionModelFeatureEffectiveConnectionTypeNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeatureEffectiveConnectionType(int64_t value) {
  SetMetricInternal(kPredictionModelFeatureEffectiveConnectionTypeNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeatureIsSameOriginNavigationName[] = "PredictionModelFeatureIsSameOriginNavigation";
const uint64_t OptimizationGuide::kPredictionModelFeatureIsSameOriginNavigationNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeatureIsSameOriginNavigation(int64_t value) {
  SetMetricInternal(kPredictionModelFeatureIsSameOriginNavigationNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionMeanName[] = "PredictionModelFeatureNavigationToFCPSessionMean";
const uint64_t OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionMeanNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeatureNavigationToFCPSessionMean(int64_t value) {
  SetMetricInternal(kPredictionModelFeatureNavigationToFCPSessionMeanNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionStdDevName[] = "PredictionModelFeatureNavigationToFCPSessionStdDev";
const uint64_t OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionStdDevNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeatureNavigationToFCPSessionStdDev(int64_t value) {
  SetMetricInternal(kPredictionModelFeatureNavigationToFCPSessionStdDevNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeaturePageTransitionName[] = "PredictionModelFeaturePageTransition";
const uint64_t OptimizationGuide::kPredictionModelFeaturePageTransitionNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeaturePageTransition(int64_t value) {
  SetMetricInternal(kPredictionModelFeaturePageTransitionNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeaturePreviousPageLoadNavigationToFCPName[] = "PredictionModelFeaturePreviousPageLoadNavigationToFCP";
const uint64_t OptimizationGuide::kPredictionModelFeaturePreviousPageLoadNavigationToFCPNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeaturePreviousPageLoadNavigationToFCP(int64_t value) {
  SetMetricInternal(kPredictionModelFeaturePreviousPageLoadNavigationToFCPNameHash, value);
  return *this;
}

const char OptimizationGuide::kPredictionModelFeatureSiteEngagementScoreName[] = "PredictionModelFeatureSiteEngagementScore";
const uint64_t OptimizationGuide::kPredictionModelFeatureSiteEngagementScoreNameHash;

OptimizationGuide& OptimizationGuide::SetPredictionModelFeatureSiteEngagementScore(int64_t value) {
  SetMetricInternal(kPredictionModelFeatureSiteEngagementScoreNameHash, value);
  return *this;
}

const char OptimizationGuide::kRegisteredOptimizationTargetsName[] = "RegisteredOptimizationTargets";
const uint64_t OptimizationGuide::kRegisteredOptimizationTargetsNameHash;

OptimizationGuide& OptimizationGuide::SetRegisteredOptimizationTargets(int64_t value) {
  SetMetricInternal(kRegisteredOptimizationTargetsNameHash, value);
  return *this;
}

const char OptimizationGuide::kRegisteredOptimizationTypesName[] = "RegisteredOptimizationTypes";
const uint64_t OptimizationGuide::kRegisteredOptimizationTypesNameHash;

OptimizationGuide& OptimizationGuide::SetRegisteredOptimizationTypes(int64_t value) {
  SetMetricInternal(kRegisteredOptimizationTypesNameHash, value);
  return *this;
}


const char PageDomainInfo::kEntryName[] = "PageDomainInfo";
const uint64_t PageDomainInfo::kEntryNameHash;

PageDomainInfo::PageDomainInfo(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageDomainInfo::PageDomainInfo(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageDomainInfo::~PageDomainInfo() = default;


const char PageDomainInfo::kDomainTypeName[] = "DomainType";
const uint64_t PageDomainInfo::kDomainTypeNameHash;

PageDomainInfo& PageDomainInfo::SetDomainType(int64_t value) {
  SetMetricInternal(kDomainTypeNameHash, value);
  return *this;
}


const char PageForegroundSession::kEntryName[] = "PageForegroundSession";
const uint64_t PageForegroundSession::kEntryNameHash;

PageForegroundSession::PageForegroundSession(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageForegroundSession::PageForegroundSession(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageForegroundSession::~PageForegroundSession() = default;


const char PageForegroundSession::kForegroundDurationName[] = "ForegroundDuration";
const uint64_t PageForegroundSession::kForegroundDurationNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundDuration(int64_t value) {
  SetMetricInternal(kForegroundDurationNameHash, value);
  return *this;
}

const char PageForegroundSession::kForegroundNumInputEventsName[] = "ForegroundNumInputEvents";
const uint64_t PageForegroundSession::kForegroundNumInputEventsNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundNumInputEvents(int64_t value) {
  SetMetricInternal(kForegroundNumInputEventsNameHash, value);
  return *this;
}

const char PageForegroundSession::kForegroundTotalAdjustedInputDelayName[] = "ForegroundTotalAdjustedInputDelay";
const uint64_t PageForegroundSession::kForegroundTotalAdjustedInputDelayNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundTotalAdjustedInputDelay(int64_t value) {
  SetMetricInternal(kForegroundTotalAdjustedInputDelayNameHash, value);
  return *this;
}

const char PageForegroundSession::kForegroundTotalInputDelayName[] = "ForegroundTotalInputDelay";
const uint64_t PageForegroundSession::kForegroundTotalInputDelayNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundTotalInputDelay(int64_t value) {
  SetMetricInternal(kForegroundTotalInputDelayNameHash, value);
  return *this;
}


const char PageInfoBubble::kEntryName[] = "PageInfoBubble";
const uint64_t PageInfoBubble::kEntryNameHash;

PageInfoBubble::PageInfoBubble(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageInfoBubble::PageInfoBubble(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageInfoBubble::~PageInfoBubble() = default;


const char PageInfoBubble::kActionTakenName[] = "ActionTaken";
const uint64_t PageInfoBubble::kActionTakenNameHash;

PageInfoBubble& PageInfoBubble::SetActionTaken(int64_t value) {
  SetMetricInternal(kActionTakenNameHash, value);
  return *this;
}


const char PageLoad::kEntryName[] = "PageLoad";
const uint64_t PageLoad::kEntryNameHash;

PageLoad::PageLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad::PageLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad::~PageLoad() = default;


const char PageLoad::kCpuTimeName[] = "CpuTime";
const uint64_t PageLoad::kCpuTimeNameHash;

PageLoad& PageLoad::SetCpuTime(int64_t value) {
  SetMetricInternal(kCpuTimeNameHash, value);
  return *this;
}

const char PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredName[] = "DocumentTiming.NavigationToDOMContentLoadedEventFired";
const uint64_t PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash;

PageLoad& PageLoad::SetDocumentTiming_NavigationToDOMContentLoadedEventFired(int64_t value) {
  SetMetricInternal(kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash, value);
  return *this;
}

const char PageLoad::kDocumentTiming_NavigationToLoadEventFiredName[] = "DocumentTiming.NavigationToLoadEventFired";
const uint64_t PageLoad::kDocumentTiming_NavigationToLoadEventFiredNameHash;

PageLoad& PageLoad::SetDocumentTiming_NavigationToLoadEventFired(int64_t value) {
  SetMetricInternal(kDocumentTiming_NavigationToLoadEventFiredNameHash, value);
  return *this;
}

const char PageLoad::kExperimental_InputToNavigationStartName[] = "Experimental.InputToNavigationStart";
const uint64_t PageLoad::kExperimental_InputToNavigationStartNameHash;

PageLoad& PageLoad::SetExperimental_InputToNavigationStart(int64_t value) {
  SetMetricInternal(kExperimental_InputToNavigationStartNameHash, value);
  return *this;
}

const char PageLoad::kExperimental_Navigation_UserInitiatedName[] = "Experimental.Navigation.UserInitiated";
const uint64_t PageLoad::kExperimental_Navigation_UserInitiatedNameHash;

PageLoad& PageLoad::SetExperimental_Navigation_UserInitiated(int64_t value) {
  SetMetricInternal(kExperimental_Navigation_UserInitiatedNameHash, value);
  return *this;
}

const char PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintName[] = "Experimental.PaintTiming.NavigationToFirstMeaningfulPaint";
const uint64_t PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash;

PageLoad& PageLoad::SetExperimental_PaintTiming_NavigationToFirstMeaningfulPaint(int64_t value) {
  SetMetricInternal(kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputDelay4Name[] = "InteractiveTiming.FirstInputDelay4";
const uint64_t PageLoad::kInteractiveTiming_FirstInputDelay4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputDelay4(int64_t value) {
  SetMetricInternal(kInteractiveTiming_FirstInputDelay4NameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputProcessingTimesName[] = "InteractiveTiming.FirstInputProcessingTimes";
const uint64_t PageLoad::kInteractiveTiming_FirstInputProcessingTimesNameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputProcessingTimes(int64_t value) {
  SetMetricInternal(kInteractiveTiming_FirstInputProcessingTimesNameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputTimestamp4Name[] = "InteractiveTiming.FirstInputTimestamp4";
const uint64_t PageLoad::kInteractiveTiming_FirstInputTimestamp4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputTimestamp4(int64_t value) {
  SetMetricInternal(kInteractiveTiming_FirstInputTimestamp4NameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_FirstScrollDelayName[] = "InteractiveTiming.FirstScrollDelay";
const uint64_t PageLoad::kInteractiveTiming_FirstScrollDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstScrollDelay(int64_t value) {
  SetMetricInternal(kInteractiveTiming_FirstScrollDelayNameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_LongestInputDelay4Name[] = "InteractiveTiming.LongestInputDelay4";
const uint64_t PageLoad::kInteractiveTiming_LongestInputDelay4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_LongestInputDelay4(int64_t value) {
  SetMetricInternal(kInteractiveTiming_LongestInputDelay4NameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_LongestInputTimestamp4Name[] = "InteractiveTiming.LongestInputTimestamp4";
const uint64_t PageLoad::kInteractiveTiming_LongestInputTimestamp4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_LongestInputTimestamp4(int64_t value) {
  SetMetricInternal(kInteractiveTiming_LongestInputTimestamp4NameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_NumInputEventsName[] = "InteractiveTiming.NumInputEvents";
const uint64_t PageLoad::kInteractiveTiming_NumInputEventsNameHash;

PageLoad& PageLoad::SetInteractiveTiming_NumInputEvents(int64_t value) {
  SetMetricInternal(kInteractiveTiming_NumInputEventsNameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_TotalAdjustedInputDelayName[] = "InteractiveTiming.TotalAdjustedInputDelay";
const uint64_t PageLoad::kInteractiveTiming_TotalAdjustedInputDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_TotalAdjustedInputDelay(int64_t value) {
  SetMetricInternal(kInteractiveTiming_TotalAdjustedInputDelayNameHash, value);
  return *this;
}

const char PageLoad::kInteractiveTiming_TotalInputDelayName[] = "InteractiveTiming.TotalInputDelay";
const uint64_t PageLoad::kInteractiveTiming_TotalInputDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_TotalInputDelay(int64_t value) {
  SetMetricInternal(kInteractiveTiming_TotalInputDelayNameHash, value);
  return *this;
}

const char PageLoad::kIsCrossProcessNavigationName[] = "IsCrossProcessNavigation";
const uint64_t PageLoad::kIsCrossProcessNavigationNameHash;

PageLoad& PageLoad::SetIsCrossProcessNavigation(int64_t value) {
  SetMetricInternal(kIsCrossProcessNavigationNameHash, value);
  return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScoreName[] = "LayoutInstability.CumulativeShiftScore";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScoreNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore(int64_t value) {
  SetMetricInternal(kLayoutInstability_CumulativeShiftScoreNameHash, value);
  return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameName[] = "LayoutInstability.CumulativeShiftScore.MainFrame";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore_MainFrame(int64_t value) {
  SetMetricInternal(kLayoutInstability_CumulativeShiftScore_MainFrameNameHash, value);
  return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName[] = "LayoutInstability.CumulativeShiftScore.MainFrame.BeforeInputOrScroll";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScroll(int64_t value) {
  SetMetricInternal(kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash, value);
  return *this;
}

const char PageLoad::kMainDocumentSequenceNumberName[] = "MainDocumentSequenceNumber";
const uint64_t PageLoad::kMainDocumentSequenceNumberNameHash;

PageLoad& PageLoad::SetMainDocumentSequenceNumber(int64_t value) {
  SetMetricInternal(kMainDocumentSequenceNumberNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_ConnectDelayName[] = "MainFrameResource.ConnectDelay";
const uint64_t PageLoad::kMainFrameResource_ConnectDelayNameHash;

PageLoad& PageLoad::SetMainFrameResource_ConnectDelay(int64_t value) {
  SetMetricInternal(kMainFrameResource_ConnectDelayNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_DNSDelayName[] = "MainFrameResource.DNSDelay";
const uint64_t PageLoad::kMainFrameResource_DNSDelayNameHash;

PageLoad& PageLoad::SetMainFrameResource_DNSDelay(int64_t value) {
  SetMetricInternal(kMainFrameResource_DNSDelayNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_HttpProtocolSchemeName[] = "MainFrameResource.HttpProtocolScheme";
const uint64_t PageLoad::kMainFrameResource_HttpProtocolSchemeNameHash;

PageLoad& PageLoad::SetMainFrameResource_HttpProtocolScheme(int64_t value) {
  SetMetricInternal(kMainFrameResource_HttpProtocolSchemeNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartName[] = "MainFrameResource.NavigationStartToReceiveHeadersStart";
const uint64_t PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_NavigationStartToReceiveHeadersStart(int64_t value) {
  SetMetricInternal(kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_NavigationStartToRequestStartName[] = "MainFrameResource.NavigationStartToRequestStart";
const uint64_t PageLoad::kMainFrameResource_NavigationStartToRequestStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_NavigationStartToRequestStart(int64_t value) {
  SetMetricInternal(kMainFrameResource_NavigationStartToRequestStartNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_RedirectCountName[] = "MainFrameResource.RedirectCount";
const uint64_t PageLoad::kMainFrameResource_RedirectCountNameHash;

PageLoad& PageLoad::SetMainFrameResource_RedirectCount(int64_t value) {
  SetMetricInternal(kMainFrameResource_RedirectCountNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndName[] = "MainFrameResource.RequestStartToReceiveHeadersEnd";
const uint64_t PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndNameHash;

PageLoad& PageLoad::SetMainFrameResource_RequestStartToReceiveHeadersEnd(int64_t value) {
  SetMetricInternal(kMainFrameResource_RequestStartToReceiveHeadersEndNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_RequestStartToSendStartName[] = "MainFrameResource.RequestStartToSendStart";
const uint64_t PageLoad::kMainFrameResource_RequestStartToSendStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_RequestStartToSendStart(int64_t value) {
  SetMetricInternal(kMainFrameResource_RequestStartToSendStartNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndName[] = "MainFrameResource.SendStartToReceiveHeadersEnd";
const uint64_t PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndNameHash;

PageLoad& PageLoad::SetMainFrameResource_SendStartToReceiveHeadersEnd(int64_t value) {
  SetMetricInternal(kMainFrameResource_SendStartToReceiveHeadersEndNameHash, value);
  return *this;
}

const char PageLoad::kMainFrameResource_SocketReusedName[] = "MainFrameResource.SocketReused";
const uint64_t PageLoad::kMainFrameResource_SocketReusedNameHash;

PageLoad& PageLoad::SetMainFrameResource_SocketReused(int64_t value) {
  SetMetricInternal(kMainFrameResource_SocketReusedNameHash, value);
  return *this;
}

const char PageLoad::kNavigation_PageEndReason2Name[] = "Navigation.PageEndReason2";
const uint64_t PageLoad::kNavigation_PageEndReason2NameHash;

PageLoad& PageLoad::SetNavigation_PageEndReason2(int64_t value) {
  SetMetricInternal(kNavigation_PageEndReason2NameHash, value);
  return *this;
}

const char PageLoad::kNavigation_PageTransitionName[] = "Navigation.PageTransition";
const uint64_t PageLoad::kNavigation_PageTransitionNameHash;

PageLoad& PageLoad::SetNavigation_PageTransition(int64_t value) {
  SetMetricInternal(kNavigation_PageTransitionNameHash, value);
  return *this;
}

const char PageLoad::kNavigationEntryOffsetName[] = "NavigationEntryOffset";
const uint64_t PageLoad::kNavigationEntryOffsetNameHash;

PageLoad& PageLoad::SetNavigationEntryOffset(int64_t value) {
  SetMetricInternal(kNavigationEntryOffsetNameHash, value);
  return *this;
}

const char PageLoad::kNet_CacheBytes2Name[] = "Net.CacheBytes2";
const uint64_t PageLoad::kNet_CacheBytes2NameHash;

PageLoad& PageLoad::SetNet_CacheBytes2(int64_t value) {
  SetMetricInternal(kNet_CacheBytes2NameHash, value);
  return *this;
}

const char PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartName[] = "Net.DownstreamKbpsEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_DownstreamKbpsEstimate_OnNavigationStart(int64_t value) {
  SetMetricInternal(kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash, value);
  return *this;
}

const char PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartName[] = "Net.EffectiveConnectionType2.OnNavigationStart";
const uint64_t PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_EffectiveConnectionType2_OnNavigationStart(int64_t value) {
  SetMetricInternal(kNet_EffectiveConnectionType2_OnNavigationStartNameHash, value);
  return *this;
}

const char PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadName[] = "Net.ErrorCode.OnFailedProvisionalLoad";
const uint64_t PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadNameHash;

PageLoad& PageLoad::SetNet_ErrorCode_OnFailedProvisionalLoad(int64_t value) {
  SetMetricInternal(kNet_ErrorCode_OnFailedProvisionalLoadNameHash, value);
  return *this;
}

const char PageLoad::kNet_HttpResponseCodeName[] = "Net.HttpResponseCode";
const uint64_t PageLoad::kNet_HttpResponseCodeNameHash;

PageLoad& PageLoad::SetNet_HttpResponseCode(int64_t value) {
  SetMetricInternal(kNet_HttpResponseCodeNameHash, value);
  return *this;
}

const char PageLoad::kNet_HttpRttEstimate_OnNavigationStartName[] = "Net.HttpRttEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_HttpRttEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_HttpRttEstimate_OnNavigationStart(int64_t value) {
  SetMetricInternal(kNet_HttpRttEstimate_OnNavigationStartNameHash, value);
  return *this;
}

const char PageLoad::kNet_ImageBytesName[] = "Net.ImageBytes";
const uint64_t PageLoad::kNet_ImageBytesNameHash;

PageLoad& PageLoad::SetNet_ImageBytes(int64_t value) {
  SetMetricInternal(kNet_ImageBytesNameHash, value);
  return *this;
}

const char PageLoad::kNet_ImageSubframeBytesName[] = "Net.ImageSubframeBytes";
const uint64_t PageLoad::kNet_ImageSubframeBytesNameHash;

PageLoad& PageLoad::SetNet_ImageSubframeBytes(int64_t value) {
  SetMetricInternal(kNet_ImageSubframeBytesNameHash, value);
  return *this;
}

const char PageLoad::kNet_JavaScriptBytesName[] = "Net.JavaScriptBytes";
const uint64_t PageLoad::kNet_JavaScriptBytesNameHash;

PageLoad& PageLoad::SetNet_JavaScriptBytes(int64_t value) {
  SetMetricInternal(kNet_JavaScriptBytesNameHash, value);
  return *this;
}

const char PageLoad::kNet_JavaScriptMaxBytesName[] = "Net.JavaScriptMaxBytes";
const uint64_t PageLoad::kNet_JavaScriptMaxBytesNameHash;

PageLoad& PageLoad::SetNet_JavaScriptMaxBytes(int64_t value) {
  SetMetricInternal(kNet_JavaScriptMaxBytesNameHash, value);
  return *this;
}

const char PageLoad::kNet_MediaBytesName[] = "Net.MediaBytes";
const uint64_t PageLoad::kNet_MediaBytesNameHash;

PageLoad& PageLoad::SetNet_MediaBytes(int64_t value) {
  SetMetricInternal(kNet_MediaBytesNameHash, value);
  return *this;
}

const char PageLoad::kNet_NetworkBytes2Name[] = "Net.NetworkBytes2";
const uint64_t PageLoad::kNet_NetworkBytes2NameHash;

PageLoad& PageLoad::SetNet_NetworkBytes2(int64_t value) {
  SetMetricInternal(kNet_NetworkBytes2NameHash, value);
  return *this;
}

const char PageLoad::kNet_TransportRttEstimate_OnNavigationStartName[] = "Net.TransportRttEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_TransportRttEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_TransportRttEstimate_OnNavigationStart(int64_t value) {
  SetMetricInternal(kNet_TransportRttEstimate_OnNavigationStartNameHash, value);
  return *this;
}

const char PageLoad::kPageTiming_ForegroundDurationName[] = "PageTiming.ForegroundDuration";
const uint64_t PageLoad::kPageTiming_ForegroundDurationNameHash;

PageLoad& PageLoad::SetPageTiming_ForegroundDuration(int64_t value) {
  SetMetricInternal(kPageTiming_ForegroundDurationNameHash, value);
  return *this;
}

const char PageLoad::kPageTiming_NavigationToFailedProvisionalLoadName[] = "PageTiming.NavigationToFailedProvisionalLoad";
const uint64_t PageLoad::kPageTiming_NavigationToFailedProvisionalLoadNameHash;

PageLoad& PageLoad::SetPageTiming_NavigationToFailedProvisionalLoad(int64_t value) {
  SetMetricInternal(kPageTiming_NavigationToFailedProvisionalLoadNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaintName[] = "PaintTiming.NavigationToExperimentalLargestContentfulPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToExperimentalLargestContentfulPaint(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToExperimentalLargestContentfulPaintNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameName[] = "PaintTiming.NavigationToExperimentalLargestContentfulPaint.MainFrame";
const uint64_t PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrame(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToFirstContentfulPaintName[] = "PaintTiming.NavigationToFirstContentfulPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToFirstContentfulPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToFirstContentfulPaint(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToFirstContentfulPaintNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToFirstPaintName[] = "PaintTiming.NavigationToFirstPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToFirstPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToFirstPaint(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToFirstPaintNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaintName[] = "PaintTiming.NavigationToLargestContentfulPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaintNameHash, value);
  return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaint_MainFrameName[] = "PaintTiming.NavigationToLargestContentfulPaint.MainFrame";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaint_MainFrameNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint_MainFrame(int64_t value) {
  SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaint_MainFrameNameHash, value);
  return *this;
}

const char PageLoad::kParseTiming_NavigationToParseStartName[] = "ParseTiming.NavigationToParseStart";
const uint64_t PageLoad::kParseTiming_NavigationToParseStartNameHash;

PageLoad& PageLoad::SetParseTiming_NavigationToParseStart(int64_t value) {
  SetMetricInternal(kParseTiming_NavigationToParseStartNameHash, value);
  return *this;
}

const char PageLoad::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t PageLoad::kSiteEngagementScoreNameHash;

PageLoad& PageLoad::SetSiteEngagementScore(int64_t value) {
  SetMetricInternal(kSiteEngagementScoreNameHash, value);
  return *this;
}

const char PageLoad::kThirdPartyCookieBlockingEnabledForSiteName[] = "ThirdPartyCookieBlockingEnabledForSite";
const uint64_t PageLoad::kThirdPartyCookieBlockingEnabledForSiteNameHash;

PageLoad& PageLoad::SetThirdPartyCookieBlockingEnabledForSite(int64_t value) {
  SetMetricInternal(kThirdPartyCookieBlockingEnabledForSiteNameHash, value);
  return *this;
}

const char PageLoad::kWasCachedName[] = "WasCached";
const uint64_t PageLoad::kWasCachedNameHash;

PageLoad& PageLoad::SetWasCached(int64_t value) {
  SetMetricInternal(kWasCachedNameHash, value);
  return *this;
}


const char PageLoad_FromGoogleSearch::kEntryName[] = "PageLoad.FromGoogleSearch";
const uint64_t PageLoad_FromGoogleSearch::kEntryNameHash;

PageLoad_FromGoogleSearch::PageLoad_FromGoogleSearch(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_FromGoogleSearch::PageLoad_FromGoogleSearch(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_FromGoogleSearch::~PageLoad_FromGoogleSearch() = default;



const char PageLoad_Internal::kEntryName[] = "PageLoad.Internal";
const uint64_t PageLoad_Internal::kEntryNameHash;

PageLoad_Internal::PageLoad_Internal(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_Internal::PageLoad_Internal(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_Internal::~PageLoad_Internal() = default;


const char PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeName[] = "PaintTiming.ExperimentalLargestContentfulPaint.ContentType";
const uint64_t PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_ExperimentalLargestContentfulPaint_ContentType(int64_t value) {
  SetMetricInternal(kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeNameHash, value);
  return *this;
}

const char PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateName[] = "PaintTiming.ExperimentalLargestContentfulPaint.TerminationState";
const uint64_t PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_ExperimentalLargestContentfulPaint_TerminationState(int64_t value) {
  SetMetricInternal(kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateNameHash, value);
  return *this;
}

const char PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeName[] = "PaintTiming.LargestContentfulPaint.ContentType";
const uint64_t PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_LargestContentfulPaint_ContentType(int64_t value) {
  SetMetricInternal(kPaintTiming_LargestContentfulPaint_ContentTypeNameHash, value);
  return *this;
}

const char PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateName[] = "PaintTiming.LargestContentfulPaint.TerminationState";
const uint64_t PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_LargestContentfulPaint_TerminationState(int64_t value) {
  SetMetricInternal(kPaintTiming_LargestContentfulPaint_TerminationStateNameHash, value);
  return *this;
}


const char PageLoad_ServiceWorkerControlled::kEntryName[] = "PageLoad.ServiceWorkerControlled";
const uint64_t PageLoad_ServiceWorkerControlled::kEntryNameHash;

PageLoad_ServiceWorkerControlled::PageLoad_ServiceWorkerControlled(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_ServiceWorkerControlled::PageLoad_ServiceWorkerControlled(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_ServiceWorkerControlled::~PageLoad_ServiceWorkerControlled() = default;



const char PageLoad_SignedExchange::kEntryName[] = "PageLoad.SignedExchange";
const uint64_t PageLoad_SignedExchange::kEntryNameHash;

PageLoad_SignedExchange::PageLoad_SignedExchange(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_SignedExchange::PageLoad_SignedExchange(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageLoad_SignedExchange::~PageLoad_SignedExchange() = default;


const char PageLoad_SignedExchange::kServedFromGoogleCacheName[] = "ServedFromGoogleCache";
const uint64_t PageLoad_SignedExchange::kServedFromGoogleCacheNameHash;

PageLoad_SignedExchange& PageLoad_SignedExchange::SetServedFromGoogleCache(int64_t value) {
  SetMetricInternal(kServedFromGoogleCacheNameHash, value);
  return *this;
}


const char PageWithPassword::kEntryName[] = "PageWithPassword";
const uint64_t PageWithPassword::kEntryNameHash;

PageWithPassword::PageWithPassword(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageWithPassword::PageWithPassword(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PageWithPassword::~PageWithPassword() = default;


const char PageWithPassword::kFormManagerAvailableName[] = "FormManagerAvailable";
const uint64_t PageWithPassword::kFormManagerAvailableNameHash;

PageWithPassword& PageWithPassword::SetFormManagerAvailable(int64_t value) {
  SetMetricInternal(kFormManagerAvailableNameHash, value);
  return *this;
}

const char PageWithPassword::kPageLevelUserActionName[] = "PageLevelUserAction";
const uint64_t PageWithPassword::kPageLevelUserActionNameHash;

PageWithPassword& PageWithPassword::SetPageLevelUserAction(int64_t value) {
  SetMetricInternal(kPageLevelUserActionNameHash, value);
  return *this;
}

const char PageWithPassword::kProvisionalSaveFailureName[] = "ProvisionalSaveFailure";
const uint64_t PageWithPassword::kProvisionalSaveFailureNameHash;

PageWithPassword& PageWithPassword::SetProvisionalSaveFailure(int64_t value) {
  SetMetricInternal(kProvisionalSaveFailureNameHash, value);
  return *this;
}

const char PageWithPassword::kUserModifiedPasswordFieldName[] = "UserModifiedPasswordField";
const uint64_t PageWithPassword::kUserModifiedPasswordFieldNameHash;

PageWithPassword& PageWithPassword::SetUserModifiedPasswordField(int64_t value) {
  SetMetricInternal(kUserModifiedPasswordFieldNameHash, value);
  return *this;
}


const char PaintPreviewCapture::kEntryName[] = "PaintPreviewCapture";
const uint64_t PaintPreviewCapture::kEntryNameHash;

PaintPreviewCapture::PaintPreviewCapture(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaintPreviewCapture::PaintPreviewCapture(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaintPreviewCapture::~PaintPreviewCapture() = default;


const char PaintPreviewCapture::kBlinkCaptureTimeName[] = "BlinkCaptureTime";
const uint64_t PaintPreviewCapture::kBlinkCaptureTimeNameHash;

PaintPreviewCapture& PaintPreviewCapture::SetBlinkCaptureTime(int64_t value) {
  SetMetricInternal(kBlinkCaptureTimeNameHash, value);
  return *this;
}

const char PaintPreviewCapture::kCompressedOnDiskSizeName[] = "CompressedOnDiskSize";
const uint64_t PaintPreviewCapture::kCompressedOnDiskSizeNameHash;

PaintPreviewCapture& PaintPreviewCapture::SetCompressedOnDiskSize(int64_t value) {
  SetMetricInternal(kCompressedOnDiskSizeNameHash, value);
  return *this;
}


const char PasswordForm::kEntryName[] = "PasswordForm";
const uint64_t PasswordForm::kEntryNameHash;

PasswordForm::PasswordForm(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PasswordForm::PasswordForm(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PasswordForm::~PasswordForm() = default;


const char PasswordForm::kContext_FormSignatureName[] = "Context.FormSignature";
const uint64_t PasswordForm::kContext_FormSignatureNameHash;

PasswordForm& PasswordForm::SetContext_FormSignature(int64_t value) {
  SetMetricInternal(kContext_FormSignatureNameHash, value);
  return *this;
}

const char PasswordForm::kDynamicFormChangesName[] = "DynamicFormChanges";
const uint64_t PasswordForm::kDynamicFormChangesNameHash;

PasswordForm& PasswordForm::SetDynamicFormChanges(int64_t value) {
  SetMetricInternal(kDynamicFormChangesNameHash, value);
  return *this;
}

const char PasswordForm::kFill_FirstFillingResultInRendererName[] = "Fill.FirstFillingResultInRenderer";
const uint64_t PasswordForm::kFill_FirstFillingResultInRendererNameHash;

PasswordForm& PasswordForm::SetFill_FirstFillingResultInRenderer(int64_t value) {
  SetMetricInternal(kFill_FirstFillingResultInRendererNameHash, value);
  return *this;
}

const char PasswordForm::kFill_FirstWaitForUsernameReasonName[] = "Fill.FirstWaitForUsernameReason";
const uint64_t PasswordForm::kFill_FirstWaitForUsernameReasonNameHash;

PasswordForm& PasswordForm::SetFill_FirstWaitForUsernameReason(int64_t value) {
  SetMetricInternal(kFill_FirstWaitForUsernameReasonNameHash, value);
  return *this;
}

const char PasswordForm::kFillOnLoadName[] = "FillOnLoad";
const uint64_t PasswordForm::kFillOnLoadNameHash;

PasswordForm& PasswordForm::SetFillOnLoad(int64_t value) {
  SetMetricInternal(kFillOnLoadNameHash, value);
  return *this;
}

const char PasswordForm::kGeneration_GeneratedPasswordName[] = "Generation.GeneratedPassword";
const uint64_t PasswordForm::kGeneration_GeneratedPasswordNameHash;

PasswordForm& PasswordForm::SetGeneration_GeneratedPassword(int64_t value) {
  SetMetricInternal(kGeneration_GeneratedPasswordNameHash, value);
  return *this;
}

const char PasswordForm::kGeneration_GeneratedPasswordModifiedName[] = "Generation.GeneratedPasswordModified";
const uint64_t PasswordForm::kGeneration_GeneratedPasswordModifiedNameHash;

PasswordForm& PasswordForm::SetGeneration_GeneratedPasswordModified(int64_t value) {
  SetMetricInternal(kGeneration_GeneratedPasswordModifiedNameHash, value);
  return *this;
}

const char PasswordForm::kGeneration_PopupShownName[] = "Generation.PopupShown";
const uint64_t PasswordForm::kGeneration_PopupShownNameHash;

PasswordForm& PasswordForm::SetGeneration_PopupShown(int64_t value) {
  SetMetricInternal(kGeneration_PopupShownNameHash, value);
  return *this;
}

const char PasswordForm::kManagerFill_ActionName[] = "ManagerFill.Action";
const uint64_t PasswordForm::kManagerFill_ActionNameHash;

PasswordForm& PasswordForm::SetManagerFill_Action(int64_t value) {
  SetMetricInternal(kManagerFill_ActionNameHash, value);
  return *this;
}

const char PasswordForm::kManagerFill_AssistanceName[] = "ManagerFill.Assistance";
const uint64_t PasswordForm::kManagerFill_AssistanceNameHash;

PasswordForm& PasswordForm::SetManagerFill_Assistance(int64_t value) {
  SetMetricInternal(kManagerFill_AssistanceNameHash, value);
  return *this;
}

const char PasswordForm::kReadonlyWhenFillingName[] = "ReadonlyWhenFilling";
const uint64_t PasswordForm::kReadonlyWhenFillingNameHash;

PasswordForm& PasswordForm::SetReadonlyWhenFilling(int64_t value) {
  SetMetricInternal(kReadonlyWhenFillingNameHash, value);
  return *this;
}

const char PasswordForm::kReadonlyWhenSavingName[] = "ReadonlyWhenSaving";
const uint64_t PasswordForm::kReadonlyWhenSavingNameHash;

PasswordForm& PasswordForm::SetReadonlyWhenSaving(int64_t value) {
  SetMetricInternal(kReadonlyWhenSavingNameHash, value);
  return *this;
}

const char PasswordForm::kSaving_Prompt_InteractionName[] = "Saving.Prompt.Interaction";
const uint64_t PasswordForm::kSaving_Prompt_InteractionNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Interaction(int64_t value) {
  SetMetricInternal(kSaving_Prompt_InteractionNameHash, value);
  return *this;
}

const char PasswordForm::kSaving_Prompt_ShownName[] = "Saving.Prompt.Shown";
const uint64_t PasswordForm::kSaving_Prompt_ShownNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Shown(int64_t value) {
  SetMetricInternal(kSaving_Prompt_ShownNameHash, value);
  return *this;
}

const char PasswordForm::kSaving_Prompt_TriggerName[] = "Saving.Prompt.Trigger";
const uint64_t PasswordForm::kSaving_Prompt_TriggerNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Trigger(int64_t value) {
  SetMetricInternal(kSaving_Prompt_TriggerNameHash, value);
  return *this;
}

const char PasswordForm::kSaving_ShowedManualFallbackForSavingName[] = "Saving.ShowedManualFallbackForSaving";
const uint64_t PasswordForm::kSaving_ShowedManualFallbackForSavingNameHash;

PasswordForm& PasswordForm::SetSaving_ShowedManualFallbackForSaving(int64_t value) {
  SetMetricInternal(kSaving_ShowedManualFallbackForSavingNameHash, value);
  return *this;
}

const char PasswordForm::kSubmission_IndicatorName[] = "Submission.Indicator";
const uint64_t PasswordForm::kSubmission_IndicatorNameHash;

PasswordForm& PasswordForm::SetSubmission_Indicator(int64_t value) {
  SetMetricInternal(kSubmission_IndicatorNameHash, value);
  return *this;
}

const char PasswordForm::kSubmission_ObservedName[] = "Submission.Observed";
const uint64_t PasswordForm::kSubmission_ObservedNameHash;

PasswordForm& PasswordForm::SetSubmission_Observed(int64_t value) {
  SetMetricInternal(kSubmission_ObservedNameHash, value);
  return *this;
}

const char PasswordForm::kSubmission_SubmissionResultName[] = "Submission.SubmissionResult";
const uint64_t PasswordForm::kSubmission_SubmissionResultNameHash;

PasswordForm& PasswordForm::SetSubmission_SubmissionResult(int64_t value) {
  SetMetricInternal(kSubmission_SubmissionResultNameHash, value);
  return *this;
}

const char PasswordForm::kSubmission_SubmittedFormTypeName[] = "Submission.SubmittedFormType";
const uint64_t PasswordForm::kSubmission_SubmittedFormTypeNameHash;

PasswordForm& PasswordForm::SetSubmission_SubmittedFormType(int64_t value) {
  SetMetricInternal(kSubmission_SubmittedFormTypeNameHash, value);
  return *this;
}

const char PasswordForm::kUpdating_Prompt_InteractionName[] = "Updating.Prompt.Interaction";
const uint64_t PasswordForm::kUpdating_Prompt_InteractionNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Interaction(int64_t value) {
  SetMetricInternal(kUpdating_Prompt_InteractionNameHash, value);
  return *this;
}

const char PasswordForm::kUpdating_Prompt_ShownName[] = "Updating.Prompt.Shown";
const uint64_t PasswordForm::kUpdating_Prompt_ShownNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Shown(int64_t value) {
  SetMetricInternal(kUpdating_Prompt_ShownNameHash, value);
  return *this;
}

const char PasswordForm::kUpdating_Prompt_TriggerName[] = "Updating.Prompt.Trigger";
const uint64_t PasswordForm::kUpdating_Prompt_TriggerNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Trigger(int64_t value) {
  SetMetricInternal(kUpdating_Prompt_TriggerNameHash, value);
  return *this;
}

const char PasswordForm::kUser_Action_CorrectedUsernameInFormName[] = "User.Action.CorrectedUsernameInForm";
const uint64_t PasswordForm::kUser_Action_CorrectedUsernameInFormNameHash;

PasswordForm& PasswordForm::SetUser_Action_CorrectedUsernameInForm(int64_t value) {
  SetMetricInternal(kUser_Action_CorrectedUsernameInFormNameHash, value);
  return *this;
}

const char PasswordForm::kUser_Action_EditedUsernameInBubbleName[] = "User.Action.EditedUsernameInBubble";
const uint64_t PasswordForm::kUser_Action_EditedUsernameInBubbleNameHash;

PasswordForm& PasswordForm::SetUser_Action_EditedUsernameInBubble(int64_t value) {
  SetMetricInternal(kUser_Action_EditedUsernameInBubbleNameHash, value);
  return *this;
}

const char PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleName[] = "User.Action.SelectedDifferentPasswordInBubble";
const uint64_t PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleNameHash;

PasswordForm& PasswordForm::SetUser_Action_SelectedDifferentPasswordInBubble(int64_t value) {
  SetMetricInternal(kUser_Action_SelectedDifferentPasswordInBubbleNameHash, value);
  return *this;
}

const char PasswordForm::kUser_Action_TriggeredManualFallbackForSavingName[] = "User.Action.TriggeredManualFallbackForSaving";
const uint64_t PasswordForm::kUser_Action_TriggeredManualFallbackForSavingNameHash;

PasswordForm& PasswordForm::SetUser_Action_TriggeredManualFallbackForSaving(int64_t value) {
  SetMetricInternal(kUser_Action_TriggeredManualFallbackForSavingNameHash, value);
  return *this;
}


const char PaymentApp_CheckoutEvents::kEntryName[] = "PaymentApp.CheckoutEvents";
const uint64_t PaymentApp_CheckoutEvents::kEntryNameHash;

PaymentApp_CheckoutEvents::PaymentApp_CheckoutEvents(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentApp_CheckoutEvents::PaymentApp_CheckoutEvents(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentApp_CheckoutEvents::~PaymentApp_CheckoutEvents() = default;


const char PaymentApp_CheckoutEvents::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentApp_CheckoutEvents::kCompletionStatusNameHash;

PaymentApp_CheckoutEvents& PaymentApp_CheckoutEvents::SetCompletionStatus(int64_t value) {
  SetMetricInternal(kCompletionStatusNameHash, value);
  return *this;
}

const char PaymentApp_CheckoutEvents::kEventsName[] = "Events";
const uint64_t PaymentApp_CheckoutEvents::kEventsNameHash;

PaymentApp_CheckoutEvents& PaymentApp_CheckoutEvents::SetEvents(int64_t value) {
  SetMetricInternal(kEventsNameHash, value);
  return *this;
}


const char PaymentRequest_CheckoutEvents::kEntryName[] = "PaymentRequest.CheckoutEvents";
const uint64_t PaymentRequest_CheckoutEvents::kEntryNameHash;

PaymentRequest_CheckoutEvents::PaymentRequest_CheckoutEvents(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentRequest_CheckoutEvents::PaymentRequest_CheckoutEvents(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentRequest_CheckoutEvents::~PaymentRequest_CheckoutEvents() = default;


const char PaymentRequest_CheckoutEvents::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentRequest_CheckoutEvents::kCompletionStatusNameHash;

PaymentRequest_CheckoutEvents& PaymentRequest_CheckoutEvents::SetCompletionStatus(int64_t value) {
  SetMetricInternal(kCompletionStatusNameHash, value);
  return *this;
}

const char PaymentRequest_CheckoutEvents::kEventsName[] = "Events";
const uint64_t PaymentRequest_CheckoutEvents::kEventsNameHash;

PaymentRequest_CheckoutEvents& PaymentRequest_CheckoutEvents::SetEvents(int64_t value) {
  SetMetricInternal(kEventsNameHash, value);
  return *this;
}


const char PaymentRequest_TransactionAmount::kEntryName[] = "PaymentRequest.TransactionAmount";
const uint64_t PaymentRequest_TransactionAmount::kEntryNameHash;

PaymentRequest_TransactionAmount::PaymentRequest_TransactionAmount(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentRequest_TransactionAmount::PaymentRequest_TransactionAmount(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PaymentRequest_TransactionAmount::~PaymentRequest_TransactionAmount() = default;


const char PaymentRequest_TransactionAmount::kCategoryName[] = "Category";
const uint64_t PaymentRequest_TransactionAmount::kCategoryNameHash;

PaymentRequest_TransactionAmount& PaymentRequest_TransactionAmount::SetCategory(int64_t value) {
  SetMetricInternal(kCategoryNameHash, value);
  return *this;
}

const char PaymentRequest_TransactionAmount::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentRequest_TransactionAmount::kCompletionStatusNameHash;

PaymentRequest_TransactionAmount& PaymentRequest_TransactionAmount::SetCompletionStatus(int64_t value) {
  SetMetricInternal(kCompletionStatusNameHash, value);
  return *this;
}


const char Pepper_Broker::kEntryName[] = "Pepper.Broker";
const uint64_t Pepper_Broker::kEntryNameHash;

Pepper_Broker::Pepper_Broker(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Pepper_Broker::Pepper_Broker(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Pepper_Broker::~Pepper_Broker() = default;



const char PeriodicBackgroundSyncEventCompleted::kEntryName[] = "PeriodicBackgroundSyncEventCompleted";
const uint64_t PeriodicBackgroundSyncEventCompleted::kEntryNameHash;

PeriodicBackgroundSyncEventCompleted::PeriodicBackgroundSyncEventCompleted(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PeriodicBackgroundSyncEventCompleted::PeriodicBackgroundSyncEventCompleted(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PeriodicBackgroundSyncEventCompleted::~PeriodicBackgroundSyncEventCompleted() = default;


const char PeriodicBackgroundSyncEventCompleted::kMaxAttemptsName[] = "MaxAttempts";
const uint64_t PeriodicBackgroundSyncEventCompleted::kMaxAttemptsNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetMaxAttempts(int64_t value) {
  SetMetricInternal(kMaxAttemptsNameHash, value);
  return *this;
}

const char PeriodicBackgroundSyncEventCompleted::kNumAttemptsName[] = "NumAttempts";
const uint64_t PeriodicBackgroundSyncEventCompleted::kNumAttemptsNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetNumAttempts(int64_t value) {
  SetMetricInternal(kNumAttemptsNameHash, value);
  return *this;
}

const char PeriodicBackgroundSyncEventCompleted::kStatusName[] = "Status";
const uint64_t PeriodicBackgroundSyncEventCompleted::kStatusNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetStatus(int64_t value) {
  SetMetricInternal(kStatusNameHash, value);
  return *this;
}


const char PeriodicBackgroundSyncRegistered::kEntryName[] = "PeriodicBackgroundSyncRegistered";
const uint64_t PeriodicBackgroundSyncRegistered::kEntryNameHash;

PeriodicBackgroundSyncRegistered::PeriodicBackgroundSyncRegistered(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PeriodicBackgroundSyncRegistered::PeriodicBackgroundSyncRegistered(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PeriodicBackgroundSyncRegistered::~PeriodicBackgroundSyncRegistered() = default;


const char PeriodicBackgroundSyncRegistered::kIsReregisteredName[] = "IsReregistered";
const uint64_t PeriodicBackgroundSyncRegistered::kIsReregisteredNameHash;

PeriodicBackgroundSyncRegistered& PeriodicBackgroundSyncRegistered::SetIsReregistered(int64_t value) {
  SetMetricInternal(kIsReregisteredNameHash, value);
  return *this;
}

const char PeriodicBackgroundSyncRegistered::kMinIntervalMsName[] = "MinIntervalMs";
const uint64_t PeriodicBackgroundSyncRegistered::kMinIntervalMsNameHash;

PeriodicBackgroundSyncRegistered& PeriodicBackgroundSyncRegistered::SetMinIntervalMs(int64_t value) {
  SetMetricInternal(kMinIntervalMsNameHash, value);
  return *this;
}


const char Permission::kEntryName[] = "Permission";
const uint64_t Permission::kEntryNameHash;

Permission::Permission(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Permission::Permission(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Permission::~Permission() = default;


const char Permission::kActionName[] = "Action";
const uint64_t Permission::kActionNameHash;

Permission& Permission::SetAction(int64_t value) {
  SetMetricInternal(kActionNameHash, value);
  return *this;
}

const char Permission::kGestureName[] = "Gesture";
const uint64_t Permission::kGestureNameHash;

Permission& Permission::SetGesture(int64_t value) {
  SetMetricInternal(kGestureNameHash, value);
  return *this;
}

const char Permission::kPermissionTypeName[] = "PermissionType";
const uint64_t Permission::kPermissionTypeNameHash;

Permission& Permission::SetPermissionType(int64_t value) {
  SetMetricInternal(kPermissionTypeNameHash, value);
  return *this;
}

const char Permission::kPriorDismissalsName[] = "PriorDismissals";
const uint64_t Permission::kPriorDismissalsNameHash;

Permission& Permission::SetPriorDismissals(int64_t value) {
  SetMetricInternal(kPriorDismissalsNameHash, value);
  return *this;
}

const char Permission::kPriorIgnoresName[] = "PriorIgnores";
const uint64_t Permission::kPriorIgnoresNameHash;

Permission& Permission::SetPriorIgnores(int64_t value) {
  SetMetricInternal(kPriorIgnoresNameHash, value);
  return *this;
}

const char Permission::kPromptDispositionName[] = "PromptDisposition";
const uint64_t Permission::kPromptDispositionNameHash;

Permission& Permission::SetPromptDisposition(int64_t value) {
  SetMetricInternal(kPromptDispositionNameHash, value);
  return *this;
}

const char Permission::kSourceName[] = "Source";
const uint64_t Permission::kSourceNameHash;

Permission& Permission::SetSource(int64_t value) {
  SetMetricInternal(kSourceNameHash, value);
  return *this;
}


const char Plugins_FlashInstance::kEntryName[] = "Plugins.FlashInstance";
const uint64_t Plugins_FlashInstance::kEntryNameHash;

Plugins_FlashInstance::Plugins_FlashInstance(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Plugins_FlashInstance::Plugins_FlashInstance(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Plugins_FlashInstance::~Plugins_FlashInstance() = default;



const char Popup_Closed::kEntryName[] = "Popup.Closed";
const uint64_t Popup_Closed::kEntryNameHash;

Popup_Closed::Popup_Closed(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Popup_Closed::Popup_Closed(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Popup_Closed::~Popup_Closed() = default;


const char Popup_Closed::kEngagementTimeName[] = "EngagementTime";
const uint64_t Popup_Closed::kEngagementTimeNameHash;

Popup_Closed& Popup_Closed::SetEngagementTime(int64_t value) {
  SetMetricInternal(kEngagementTimeNameHash, value);
  return *this;
}

const char Popup_Closed::kNumActivationInteractionsName[] = "NumActivationInteractions";
const uint64_t Popup_Closed::kNumActivationInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumActivationInteractions(int64_t value) {
  SetMetricInternal(kNumActivationInteractionsNameHash, value);
  return *this;
}

const char Popup_Closed::kNumGestureScrollBeginInteractionsName[] = "NumGestureScrollBeginInteractions";
const uint64_t Popup_Closed::kNumGestureScrollBeginInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumGestureScrollBeginInteractions(int64_t value) {
  SetMetricInternal(kNumGestureScrollBeginInteractionsNameHash, value);
  return *this;
}

const char Popup_Closed::kNumInteractionsName[] = "NumInteractions";
const uint64_t Popup_Closed::kNumInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumInteractions(int64_t value) {
  SetMetricInternal(kNumInteractionsNameHash, value);
  return *this;
}

const char Popup_Closed::kSafeBrowsingStatusName[] = "SafeBrowsingStatus";
const uint64_t Popup_Closed::kSafeBrowsingStatusNameHash;

Popup_Closed& Popup_Closed::SetSafeBrowsingStatus(int64_t value) {
  SetMetricInternal(kSafeBrowsingStatusNameHash, value);
  return *this;
}

const char Popup_Closed::kTrustedName[] = "Trusted";
const uint64_t Popup_Closed::kTrustedNameHash;

Popup_Closed& Popup_Closed::SetTrusted(int64_t value) {
  SetMetricInternal(kTrustedNameHash, value);
  return *this;
}

const char Popup_Closed::kUserInitiatedCloseName[] = "UserInitiatedClose";
const uint64_t Popup_Closed::kUserInitiatedCloseNameHash;

Popup_Closed& Popup_Closed::SetUserInitiatedClose(int64_t value) {
  SetMetricInternal(kUserInitiatedCloseNameHash, value);
  return *this;
}

const char Popup_Closed::kWindowOpenDispositionName[] = "WindowOpenDisposition";
const uint64_t Popup_Closed::kWindowOpenDispositionNameHash;

Popup_Closed& Popup_Closed::SetWindowOpenDisposition(int64_t value) {
  SetMetricInternal(kWindowOpenDispositionNameHash, value);
  return *this;
}


const char Popup_Page::kEntryName[] = "Popup.Page";
const uint64_t Popup_Page::kEntryNameHash;

Popup_Page::Popup_Page(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Popup_Page::Popup_Page(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Popup_Page::~Popup_Page() = default;


const char Popup_Page::kAllowedName[] = "Allowed";
const uint64_t Popup_Page::kAllowedNameHash;

Popup_Page& Popup_Page::SetAllowed(int64_t value) {
  SetMetricInternal(kAllowedNameHash, value);
  return *this;
}


const char Portal_Activate::kEntryName[] = "Portal.Activate";
const uint64_t Portal_Activate::kEntryNameHash;

Portal_Activate::Portal_Activate(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Portal_Activate::Portal_Activate(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Portal_Activate::~Portal_Activate() = default;


const char Portal_Activate::kPaintTiming_PortalActivationToFirstPaintName[] = "PaintTiming.PortalActivationToFirstPaint";
const uint64_t Portal_Activate::kPaintTiming_PortalActivationToFirstPaintNameHash;

Portal_Activate& Portal_Activate::SetPaintTiming_PortalActivationToFirstPaint(int64_t value) {
  SetMetricInternal(kPaintTiming_PortalActivationToFirstPaintNameHash, value);
  return *this;
}

const char Portal_Activate::kPortalActivationName[] = "PortalActivation";
const uint64_t Portal_Activate::kPortalActivationNameHash;

Portal_Activate& Portal_Activate::SetPortalActivation(int64_t value) {
  SetMetricInternal(kPortalActivationNameHash, value);
  return *this;
}

const char Portal_Activate::kPortalActivationBeforeLCPName[] = "PortalActivationBeforeLCP";
const uint64_t Portal_Activate::kPortalActivationBeforeLCPNameHash;

Portal_Activate& Portal_Activate::SetPortalActivationBeforeLCP(int64_t value) {
  SetMetricInternal(kPortalActivationBeforeLCPNameHash, value);
  return *this;
}


const char PrefetchProxy::kEntryName[] = "PrefetchProxy";
const uint64_t PrefetchProxy::kEntryNameHash;

PrefetchProxy::PrefetchProxy(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PrefetchProxy::PrefetchProxy(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PrefetchProxy::~PrefetchProxy() = default;


const char PrefetchProxy::kcount_css_js_loaded_cache_before_fcpName[] = "count_css_js_loaded_cache_before_fcp";
const uint64_t PrefetchProxy::kcount_css_js_loaded_cache_before_fcpNameHash;

PrefetchProxy& PrefetchProxy::Setcount_css_js_loaded_cache_before_fcp(int64_t value) {
  SetMetricInternal(kcount_css_js_loaded_cache_before_fcpNameHash, value);
  return *this;
}

const char PrefetchProxy::kcount_css_js_loaded_network_before_fcpName[] = "count_css_js_loaded_network_before_fcp";
const uint64_t PrefetchProxy::kcount_css_js_loaded_network_before_fcpNameHash;

PrefetchProxy& PrefetchProxy::Setcount_css_js_loaded_network_before_fcp(int64_t value) {
  SetMetricInternal(kcount_css_js_loaded_network_before_fcpNameHash, value);
  return *this;
}

const char PrefetchProxy::kdays_since_last_visit_to_originName[] = "days_since_last_visit_to_origin";
const uint64_t PrefetchProxy::kdays_since_last_visit_to_originNameHash;

PrefetchProxy& PrefetchProxy::Setdays_since_last_visit_to_origin(int64_t value) {
  SetMetricInternal(kdays_since_last_visit_to_originNameHash, value);
  return *this;
}

const char PrefetchProxy::kmainpage_request_had_cookiesName[] = "mainpage_request_had_cookies";
const uint64_t PrefetchProxy::kmainpage_request_had_cookiesNameHash;

PrefetchProxy& PrefetchProxy::Setmainpage_request_had_cookies(int64_t value) {
  SetMetricInternal(kmainpage_request_had_cookiesNameHash, value);
  return *this;
}

const char PrefetchProxy::kordered_eligible_pages_bitmaskName[] = "ordered_eligible_pages_bitmask";
const uint64_t PrefetchProxy::kordered_eligible_pages_bitmaskNameHash;

PrefetchProxy& PrefetchProxy::Setordered_eligible_pages_bitmask(int64_t value) {
  SetMetricInternal(kordered_eligible_pages_bitmaskNameHash, value);
  return *this;
}

const char PrefetchProxy::kprefetch_attempted_countName[] = "prefetch_attempted_count";
const uint64_t PrefetchProxy::kprefetch_attempted_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_attempted_count(int64_t value) {
  SetMetricInternal(kprefetch_attempted_countNameHash, value);
  return *this;
}

const char PrefetchProxy::kprefetch_eligible_countName[] = "prefetch_eligible_count";
const uint64_t PrefetchProxy::kprefetch_eligible_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_eligible_count(int64_t value) {
  SetMetricInternal(kprefetch_eligible_countNameHash, value);
  return *this;
}

const char PrefetchProxy::kprefetch_successful_countName[] = "prefetch_successful_count";
const uint64_t PrefetchProxy::kprefetch_successful_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_successful_count(int64_t value) {
  SetMetricInternal(kprefetch_successful_countNameHash, value);
  return *this;
}


const char PrefetchProxy_AfterSRPClick::kEntryName[] = "PrefetchProxy.AfterSRPClick";
const uint64_t PrefetchProxy_AfterSRPClick::kEntryNameHash;

PrefetchProxy_AfterSRPClick::PrefetchProxy_AfterSRPClick(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PrefetchProxy_AfterSRPClick::PrefetchProxy_AfterSRPClick(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PrefetchProxy_AfterSRPClick::~PrefetchProxy_AfterSRPClick() = default;


const char PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionName[] = "ClickedLinkSRPPosition";
const uint64_t PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetClickedLinkSRPPosition(int64_t value) {
  SetMetricInternal(kClickedLinkSRPPositionNameHash, value);
  return *this;
}

const char PrefetchProxy_AfterSRPClick::kProbeLatencyMsName[] = "ProbeLatencyMs";
const uint64_t PrefetchProxy_AfterSRPClick::kProbeLatencyMsNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetProbeLatencyMs(int64_t value) {
  SetMetricInternal(kProbeLatencyMsNameHash, value);
  return *this;
}

const char PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusName[] = "SRPClickPrefetchStatus";
const uint64_t PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetSRPClickPrefetchStatus(int64_t value) {
  SetMetricInternal(kSRPClickPrefetchStatusNameHash, value);
  return *this;
}

const char PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountName[] = "SRPPrefetchEligibleCount";
const uint64_t PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetSRPPrefetchEligibleCount(int64_t value) {
  SetMetricInternal(kSRPPrefetchEligibleCountNameHash, value);
  return *this;
}


const char Previews::kEntryName[] = "Previews";
const uint64_t Previews::kEntryNameHash;

Previews::Previews(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Previews::Previews(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Previews::~Previews() = default;


const char Previews::kdefer_all_scriptName[] = "defer_all_script";
const uint64_t Previews::kdefer_all_scriptNameHash;

Previews& Previews::Setdefer_all_script(int64_t value) {
  SetMetricInternal(kdefer_all_scriptNameHash, value);
  return *this;
}

const char Previews::kdefer_all_script_eligibility_reasonName[] = "defer_all_script_eligibility_reason";
const uint64_t Previews::kdefer_all_script_eligibility_reasonNameHash;

Previews& Previews::Setdefer_all_script_eligibility_reason(int64_t value) {
  SetMetricInternal(kdefer_all_script_eligibility_reasonNameHash, value);
  return *this;
}

const char Previews::klite_pageName[] = "lite_page";
const uint64_t Previews::klite_pageNameHash;

Previews& Previews::Setlite_page(int64_t value) {
  SetMetricInternal(klite_pageNameHash, value);
  return *this;
}

const char Previews::knoscriptName[] = "noscript";
const uint64_t Previews::knoscriptNameHash;

Previews& Previews::Setnoscript(int64_t value) {
  SetMetricInternal(knoscriptNameHash, value);
  return *this;
}

const char Previews::knoscript_eligibility_reasonName[] = "noscript_eligibility_reason";
const uint64_t Previews::knoscript_eligibility_reasonNameHash;

Previews& Previews::Setnoscript_eligibility_reason(int64_t value) {
  SetMetricInternal(knoscript_eligibility_reasonNameHash, value);
  return *this;
}

const char Previews::koffline_eligibility_reasonName[] = "offline_eligibility_reason";
const uint64_t Previews::koffline_eligibility_reasonNameHash;

Previews& Previews::Setoffline_eligibility_reason(int64_t value) {
  SetMetricInternal(koffline_eligibility_reasonNameHash, value);
  return *this;
}

const char Previews::koffline_previewName[] = "offline_preview";
const uint64_t Previews::koffline_previewNameHash;

Previews& Previews::Setoffline_preview(int64_t value) {
  SetMetricInternal(koffline_previewNameHash, value);
  return *this;
}

const char Previews::kopt_outName[] = "opt_out";
const uint64_t Previews::kopt_outNameHash;

Previews& Previews::Setopt_out(int64_t value) {
  SetMetricInternal(kopt_outNameHash, value);
  return *this;
}

const char Previews::korigin_opt_outName[] = "origin_opt_out";
const uint64_t Previews::korigin_opt_outNameHash;

Previews& Previews::Setorigin_opt_out(int64_t value) {
  SetMetricInternal(korigin_opt_outNameHash, value);
  return *this;
}

const char Previews::kpreviews_likelyName[] = "previews_likely";
const uint64_t Previews::kpreviews_likelyNameHash;

Previews& Previews::Setpreviews_likely(int64_t value) {
  SetMetricInternal(kpreviews_likelyNameHash, value);
  return *this;
}

const char Previews::kproxy_lite_page_eligibility_reasonName[] = "proxy_lite_page_eligibility_reason";
const uint64_t Previews::kproxy_lite_page_eligibility_reasonNameHash;

Previews& Previews::Setproxy_lite_page_eligibility_reason(int64_t value) {
  SetMetricInternal(kproxy_lite_page_eligibility_reasonNameHash, value);
  return *this;
}

const char Previews::kresource_loading_hintsName[] = "resource_loading_hints";
const uint64_t Previews::kresource_loading_hintsNameHash;

Previews& Previews::Setresource_loading_hints(int64_t value) {
  SetMetricInternal(kresource_loading_hintsNameHash, value);
  return *this;
}

const char Previews::kresource_loading_hints_eligibility_reasonName[] = "resource_loading_hints_eligibility_reason";
const uint64_t Previews::kresource_loading_hints_eligibility_reasonNameHash;

Previews& Previews::Setresource_loading_hints_eligibility_reason(int64_t value) {
  SetMetricInternal(kresource_loading_hints_eligibility_reasonNameHash, value);
  return *this;
}

const char Previews::ksave_data_enabledName[] = "save_data_enabled";
const uint64_t Previews::ksave_data_enabledNameHash;

Previews& Previews::Setsave_data_enabled(int64_t value) {
  SetMetricInternal(ksave_data_enabledNameHash, value);
  return *this;
}


const char PreviewsCoinFlip::kEntryName[] = "PreviewsCoinFlip";
const uint64_t PreviewsCoinFlip::kEntryNameHash;

PreviewsCoinFlip::PreviewsCoinFlip(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsCoinFlip::PreviewsCoinFlip(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsCoinFlip::~PreviewsCoinFlip() = default;


const char PreviewsCoinFlip::kcoin_flip_resultName[] = "coin_flip_result";
const uint64_t PreviewsCoinFlip::kcoin_flip_resultNameHash;

PreviewsCoinFlip& PreviewsCoinFlip::Setcoin_flip_result(int64_t value) {
  SetMetricInternal(kcoin_flip_resultNameHash, value);
  return *this;
}


const char PreviewsDeferAllScript::kEntryName[] = "PreviewsDeferAllScript";
const uint64_t PreviewsDeferAllScript::kEntryNameHash;

PreviewsDeferAllScript::PreviewsDeferAllScript(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsDeferAllScript::PreviewsDeferAllScript(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsDeferAllScript::~PreviewsDeferAllScript() = default;


const char PreviewsDeferAllScript::kforce_deferred_scripts_mainframeName[] = "force_deferred_scripts_mainframe";
const uint64_t PreviewsDeferAllScript::kforce_deferred_scripts_mainframeNameHash;

PreviewsDeferAllScript& PreviewsDeferAllScript::Setforce_deferred_scripts_mainframe(int64_t value) {
  SetMetricInternal(kforce_deferred_scripts_mainframeNameHash, value);
  return *this;
}

const char PreviewsDeferAllScript::kforce_deferred_scripts_mainframe_externalName[] = "force_deferred_scripts_mainframe_external";
const uint64_t PreviewsDeferAllScript::kforce_deferred_scripts_mainframe_externalNameHash;

PreviewsDeferAllScript& PreviewsDeferAllScript::Setforce_deferred_scripts_mainframe_external(int64_t value) {
  SetMetricInternal(kforce_deferred_scripts_mainframe_externalNameHash, value);
  return *this;
}


const char PreviewsResourceLoadingHints::kEntryName[] = "PreviewsResourceLoadingHints";
const uint64_t PreviewsResourceLoadingHints::kEntryNameHash;

PreviewsResourceLoadingHints::PreviewsResourceLoadingHints(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsResourceLoadingHints::PreviewsResourceLoadingHints(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PreviewsResourceLoadingHints::~PreviewsResourceLoadingHints() = default;


const char PreviewsResourceLoadingHints::kblocked_high_priorityName[] = "blocked_high_priority";
const uint64_t PreviewsResourceLoadingHints::kblocked_high_priorityNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setblocked_high_priority(int64_t value) {
  SetMetricInternal(kblocked_high_priorityNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kblocked_low_priorityName[] = "blocked_low_priority";
const uint64_t PreviewsResourceLoadingHints::kblocked_low_priorityNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setblocked_low_priority(int64_t value) {
  SetMetricInternal(kblocked_low_priorityNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kblocked_medium_priorityName[] = "blocked_medium_priority";
const uint64_t PreviewsResourceLoadingHints::kblocked_medium_priorityNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setblocked_medium_priority(int64_t value) {
  SetMetricInternal(kblocked_medium_priorityNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kblocked_very_high_priorityName[] = "blocked_very_high_priority";
const uint64_t PreviewsResourceLoadingHints::kblocked_very_high_priorityNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setblocked_very_high_priority(int64_t value) {
  SetMetricInternal(kblocked_very_high_priorityNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kblocked_very_low_priorityName[] = "blocked_very_low_priority";
const uint64_t PreviewsResourceLoadingHints::kblocked_very_low_priorityNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setblocked_very_low_priority(int64_t value) {
  SetMetricInternal(kblocked_very_low_priorityNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kpatterns_to_block_totalName[] = "patterns_to_block_total";
const uint64_t PreviewsResourceLoadingHints::kpatterns_to_block_totalNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setpatterns_to_block_total(int64_t value) {
  SetMetricInternal(kpatterns_to_block_totalNameHash, value);
  return *this;
}

const char PreviewsResourceLoadingHints::kpatterns_to_block_usedName[] = "patterns_to_block_used";
const uint64_t PreviewsResourceLoadingHints::kpatterns_to_block_usedNameHash;

PreviewsResourceLoadingHints& PreviewsResourceLoadingHints::Setpatterns_to_block_used(int64_t value) {
  SetMetricInternal(kpatterns_to_block_usedNameHash, value);
  return *this;
}


const char PublicImageCompressionDataUse::kEntryName[] = "PublicImageCompressionDataUse";
const uint64_t PublicImageCompressionDataUse::kEntryNameHash;

PublicImageCompressionDataUse::PublicImageCompressionDataUse(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PublicImageCompressionDataUse::PublicImageCompressionDataUse(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PublicImageCompressionDataUse::~PublicImageCompressionDataUse() = default;


const char PublicImageCompressionDataUse::kCompressibleImageBytesName[] = "CompressibleImageBytes";
const uint64_t PublicImageCompressionDataUse::kCompressibleImageBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetCompressibleImageBytes(int64_t value) {
  SetMetricInternal(kCompressibleImageBytesNameHash, value);
  return *this;
}

const char PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableAndMissingInHintsBytesName[] = "IneligibleImageHintsUnavailableAndMissingInHintsBytes";
const uint64_t PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableAndMissingInHintsBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetIneligibleImageHintsUnavailableAndMissingInHintsBytes(int64_t value) {
  SetMetricInternal(kIneligibleImageHintsUnavailableAndMissingInHintsBytesNameHash, value);
  return *this;
}

const char PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableButCompressibleBytesName[] = "IneligibleImageHintsUnavailableButCompressibleBytes";
const uint64_t PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableButCompressibleBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetIneligibleImageHintsUnavailableButCompressibleBytes(int64_t value) {
  SetMetricInternal(kIneligibleImageHintsUnavailableButCompressibleBytesNameHash, value);
  return *this;
}

const char PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableBytesName[] = "IneligibleImageHintsUnavailableBytes";
const uint64_t PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetIneligibleImageHintsUnavailableBytes(int64_t value) {
  SetMetricInternal(kIneligibleImageHintsUnavailableBytesNameHash, value);
  return *this;
}

const char PublicImageCompressionDataUse::kIneligibleMissingInImageHintsBytesName[] = "IneligibleMissingInImageHintsBytes";
const uint64_t PublicImageCompressionDataUse::kIneligibleMissingInImageHintsBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetIneligibleMissingInImageHintsBytes(int64_t value) {
  SetMetricInternal(kIneligibleMissingInImageHintsBytesNameHash, value);
  return *this;
}

const char PublicImageCompressionDataUse::kIneligibleOtherImageBytesName[] = "IneligibleOtherImageBytes";
const uint64_t PublicImageCompressionDataUse::kIneligibleOtherImageBytesNameHash;

PublicImageCompressionDataUse& PublicImageCompressionDataUse::SetIneligibleOtherImageBytes(int64_t value) {
  SetMetricInternal(kIneligibleOtherImageBytesNameHash, value);
  return *this;
}


const char PWA_Visit::kEntryName[] = "PWA.Visit";
const uint64_t PWA_Visit::kEntryNameHash;

PWA_Visit::PWA_Visit(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PWA_Visit::PWA_Visit(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

PWA_Visit::~PWA_Visit() = default;


const char PWA_Visit::kLaunchSourceName[] = "LaunchSource";
const uint64_t PWA_Visit::kLaunchSourceNameHash;

PWA_Visit& PWA_Visit::SetLaunchSource(int64_t value) {
  SetMetricInternal(kLaunchSourceNameHash, value);
  return *this;
}

const char PWA_Visit::kWebAPKableSiteVisitName[] = "WebAPKableSiteVisit";
const uint64_t PWA_Visit::kWebAPKableSiteVisitNameHash;

PWA_Visit& PWA_Visit::SetWebAPKableSiteVisit(int64_t value) {
  SetMetricInternal(kWebAPKableSiteVisitNameHash, value);
  return *this;
}


const char ReaderModeActivated::kEntryName[] = "ReaderModeActivated";
const uint64_t ReaderModeActivated::kEntryNameHash;

ReaderModeActivated::ReaderModeActivated(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ReaderModeActivated::ReaderModeActivated(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ReaderModeActivated::~ReaderModeActivated() = default;


const char ReaderModeActivated::kActivatedViaOmniboxName[] = "ActivatedViaOmnibox";
const uint64_t ReaderModeActivated::kActivatedViaOmniboxNameHash;

ReaderModeActivated& ReaderModeActivated::SetActivatedViaOmnibox(int64_t value) {
  SetMetricInternal(kActivatedViaOmniboxNameHash, value);
  return *this;
}


const char ReaderModeReceivedDistillability::kEntryName[] = "ReaderModeReceivedDistillability";
const uint64_t ReaderModeReceivedDistillability::kEntryNameHash;

ReaderModeReceivedDistillability::ReaderModeReceivedDistillability(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ReaderModeReceivedDistillability::ReaderModeReceivedDistillability(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ReaderModeReceivedDistillability::~ReaderModeReceivedDistillability() = default;


const char ReaderModeReceivedDistillability::kIsPageDistillableName[] = "IsPageDistillable";
const uint64_t ReaderModeReceivedDistillability::kIsPageDistillableNameHash;

ReaderModeReceivedDistillability& ReaderModeReceivedDistillability::SetIsPageDistillable(int64_t value) {
  SetMetricInternal(kIsPageDistillableNameHash, value);
  return *this;
}


const char RendererSchedulerTask::kEntryName[] = "RendererSchedulerTask";
const uint64_t RendererSchedulerTask::kEntryNameHash;

RendererSchedulerTask::RendererSchedulerTask(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

RendererSchedulerTask::RendererSchedulerTask(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

RendererSchedulerTask::~RendererSchedulerTask() = default;


const char RendererSchedulerTask::kFrameStatusName[] = "FrameStatus";
const uint64_t RendererSchedulerTask::kFrameStatusNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetFrameStatus(int64_t value) {
  SetMetricInternal(kFrameStatusNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kIsOOPIFName[] = "IsOOPIF";
const uint64_t RendererSchedulerTask::kIsOOPIFNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetIsOOPIF(int64_t value) {
  SetMetricInternal(kIsOOPIFNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kPageSchedulersName[] = "PageSchedulers";
const uint64_t RendererSchedulerTask::kPageSchedulersNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetPageSchedulers(int64_t value) {
  SetMetricInternal(kPageSchedulersNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kQueueTypeName[] = "QueueType";
const uint64_t RendererSchedulerTask::kQueueTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetQueueType(int64_t value) {
  SetMetricInternal(kQueueTypeNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kRendererAudibleName[] = "RendererAudible";
const uint64_t RendererSchedulerTask::kRendererAudibleNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererAudible(int64_t value) {
  SetMetricInternal(kRendererAudibleNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kRendererBackgroundedName[] = "RendererBackgrounded";
const uint64_t RendererSchedulerTask::kRendererBackgroundedNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererBackgrounded(int64_t value) {
  SetMetricInternal(kRendererBackgroundedNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kRendererHiddenName[] = "RendererHidden";
const uint64_t RendererSchedulerTask::kRendererHiddenNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererHidden(int64_t value) {
  SetMetricInternal(kRendererHiddenNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kSecondsSinceBackgroundedName[] = "SecondsSinceBackgrounded";
const uint64_t RendererSchedulerTask::kSecondsSinceBackgroundedNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetSecondsSinceBackgrounded(int64_t value) {
  SetMetricInternal(kSecondsSinceBackgroundedNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kTaskCPUDurationName[] = "TaskCPUDuration";
const uint64_t RendererSchedulerTask::kTaskCPUDurationNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskCPUDuration(int64_t value) {
  SetMetricInternal(kTaskCPUDurationNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kTaskDurationName[] = "TaskDuration";
const uint64_t RendererSchedulerTask::kTaskDurationNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskDuration(int64_t value) {
  SetMetricInternal(kTaskDurationNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kTaskTypeName[] = "TaskType";
const uint64_t RendererSchedulerTask::kTaskTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskType(int64_t value) {
  SetMetricInternal(kTaskTypeNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kThreadTypeName[] = "ThreadType";
const uint64_t RendererSchedulerTask::kThreadTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetThreadType(int64_t value) {
  SetMetricInternal(kThreadTypeNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kUseCaseName[] = "UseCase";
const uint64_t RendererSchedulerTask::kUseCaseNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetUseCase(int64_t value) {
  SetMetricInternal(kUseCaseNameHash, value);
  return *this;
}

const char RendererSchedulerTask::kVersionName[] = "Version";
const uint64_t RendererSchedulerTask::kVersionNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetVersion(int64_t value) {
  SetMetricInternal(kVersionNameHash, value);
  return *this;
}


const char ResponsivenessMeasurement::kEntryName[] = "ResponsivenessMeasurement";
const uint64_t ResponsivenessMeasurement::kEntryNameHash;

ResponsivenessMeasurement::ResponsivenessMeasurement(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ResponsivenessMeasurement::ResponsivenessMeasurement(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ResponsivenessMeasurement::~ResponsivenessMeasurement() = default;


const char ResponsivenessMeasurement::kExpectedTaskQueueingDurationName[] = "ExpectedTaskQueueingDuration";
const uint64_t ResponsivenessMeasurement::kExpectedTaskQueueingDurationNameHash;

ResponsivenessMeasurement& ResponsivenessMeasurement::SetExpectedTaskQueueingDuration(int64_t value) {
  SetMetricInternal(kExpectedTaskQueueingDurationNameHash, value);
  return *this;
}


const char SameSiteDifferentSchemeRequest::kEntryName[] = "SameSiteDifferentSchemeRequest";
const uint64_t SameSiteDifferentSchemeRequest::kEntryNameHash;

SameSiteDifferentSchemeRequest::SameSiteDifferentSchemeRequest(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SameSiteDifferentSchemeRequest::SameSiteDifferentSchemeRequest(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SameSiteDifferentSchemeRequest::~SameSiteDifferentSchemeRequest() = default;



const char SameSiteDifferentSchemeResponse::kEntryName[] = "SameSiteDifferentSchemeResponse";
const uint64_t SameSiteDifferentSchemeResponse::kEntryNameHash;

SameSiteDifferentSchemeResponse::SameSiteDifferentSchemeResponse(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SameSiteDifferentSchemeResponse::SameSiteDifferentSchemeResponse(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SameSiteDifferentSchemeResponse::~SameSiteDifferentSchemeResponse() = default;



const char SchemefulSameSiteContextDowngrade::kEntryName[] = "SchemefulSameSiteContextDowngrade";
const uint64_t SchemefulSameSiteContextDowngrade::kEntryNameHash;

SchemefulSameSiteContextDowngrade::SchemefulSameSiteContextDowngrade(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SchemefulSameSiteContextDowngrade::SchemefulSameSiteContextDowngrade(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SchemefulSameSiteContextDowngrade::~SchemefulSameSiteContextDowngrade() = default;


const char SchemefulSameSiteContextDowngrade::kRequestPerCookieName[] = "RequestPerCookie";
const uint64_t SchemefulSameSiteContextDowngrade::kRequestPerCookieNameHash;

SchemefulSameSiteContextDowngrade& SchemefulSameSiteContextDowngrade::SetRequestPerCookie(int64_t value) {
  SetMetricInternal(kRequestPerCookieNameHash, value);
  return *this;
}

const char SchemefulSameSiteContextDowngrade::kResponsePerCookieName[] = "ResponsePerCookie";
const uint64_t SchemefulSameSiteContextDowngrade::kResponsePerCookieNameHash;

SchemefulSameSiteContextDowngrade& SchemefulSameSiteContextDowngrade::SetResponsePerCookie(int64_t value) {
  SetMetricInternal(kResponsePerCookieNameHash, value);
  return *this;
}


const char ScreenBrightness::kEntryName[] = "ScreenBrightness";
const uint64_t ScreenBrightness::kEntryNameHash;

ScreenBrightness::ScreenBrightness(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ScreenBrightness::ScreenBrightness(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

ScreenBrightness::~ScreenBrightness() = default;


const char ScreenBrightness::kBatteryPercentName[] = "BatteryPercent";
const uint64_t ScreenBrightness::kBatteryPercentNameHash;

ScreenBrightness& ScreenBrightness::SetBatteryPercent(int64_t value) {
  SetMetricInternal(kBatteryPercentNameHash, value);
  return *this;
}

const char ScreenBrightness::kBrightnessName[] = "Brightness";
const uint64_t ScreenBrightness::kBrightnessNameHash;

ScreenBrightness& ScreenBrightness::SetBrightness(int64_t value) {
  SetMetricInternal(kBrightnessNameHash, value);
  return *this;
}

const char ScreenBrightness::kDayOfWeekName[] = "DayOfWeek";
const uint64_t ScreenBrightness::kDayOfWeekNameHash;

ScreenBrightness& ScreenBrightness::SetDayOfWeek(int64_t value) {
  SetMetricInternal(kDayOfWeekNameHash, value);
  return *this;
}

const char ScreenBrightness::kDeviceModeName[] = "DeviceMode";
const uint64_t ScreenBrightness::kDeviceModeNameHash;

ScreenBrightness& ScreenBrightness::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char ScreenBrightness::kHourOfDayName[] = "HourOfDay";
const uint64_t ScreenBrightness::kHourOfDayNameHash;

ScreenBrightness& ScreenBrightness::SetHourOfDay(int64_t value) {
  SetMetricInternal(kHourOfDayNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsAutoclickEnabledName[] = "IsAutoclickEnabled";
const uint64_t ScreenBrightness::kIsAutoclickEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsAutoclickEnabled(int64_t value) {
  SetMetricInternal(kIsAutoclickEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsBrailleDisplayConnectedName[] = "IsBrailleDisplayConnected";
const uint64_t ScreenBrightness::kIsBrailleDisplayConnectedNameHash;

ScreenBrightness& ScreenBrightness::SetIsBrailleDisplayConnected(int64_t value) {
  SetMetricInternal(kIsBrailleDisplayConnectedNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsCaretHighlightEnabledName[] = "IsCaretHighlightEnabled";
const uint64_t ScreenBrightness::kIsCaretHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsCaretHighlightEnabled(int64_t value) {
  SetMetricInternal(kIsCaretHighlightEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsCursorHighlightEnabledName[] = "IsCursorHighlightEnabled";
const uint64_t ScreenBrightness::kIsCursorHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsCursorHighlightEnabled(int64_t value) {
  SetMetricInternal(kIsCursorHighlightEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsFocusHighlightEnabledName[] = "IsFocusHighlightEnabled";
const uint64_t ScreenBrightness::kIsFocusHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsFocusHighlightEnabled(int64_t value) {
  SetMetricInternal(kIsFocusHighlightEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsHighContrastEnabledName[] = "IsHighContrastEnabled";
const uint64_t ScreenBrightness::kIsHighContrastEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsHighContrastEnabled(int64_t value) {
  SetMetricInternal(kIsHighContrastEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsLargeCursorEnabledName[] = "IsLargeCursorEnabled";
const uint64_t ScreenBrightness::kIsLargeCursorEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsLargeCursorEnabled(int64_t value) {
  SetMetricInternal(kIsLargeCursorEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsMagnifierEnabledName[] = "IsMagnifierEnabled";
const uint64_t ScreenBrightness::kIsMagnifierEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsMagnifierEnabled(int64_t value) {
  SetMetricInternal(kIsMagnifierEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsMonoAudioEnabledName[] = "IsMonoAudioEnabled";
const uint64_t ScreenBrightness::kIsMonoAudioEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsMonoAudioEnabled(int64_t value) {
  SetMetricInternal(kIsMonoAudioEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsSelectToSpeakEnabledName[] = "IsSelectToSpeakEnabled";
const uint64_t ScreenBrightness::kIsSelectToSpeakEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSelectToSpeakEnabled(int64_t value) {
  SetMetricInternal(kIsSelectToSpeakEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsSpokenFeedbackEnabledName[] = "IsSpokenFeedbackEnabled";
const uint64_t ScreenBrightness::kIsSpokenFeedbackEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSpokenFeedbackEnabled(int64_t value) {
  SetMetricInternal(kIsSpokenFeedbackEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsSwitchAccessEnabledName[] = "IsSwitchAccessEnabled";
const uint64_t ScreenBrightness::kIsSwitchAccessEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSwitchAccessEnabled(int64_t value) {
  SetMetricInternal(kIsSwitchAccessEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsVideoPlayingName[] = "IsVideoPlaying";
const uint64_t ScreenBrightness::kIsVideoPlayingNameHash;

ScreenBrightness& ScreenBrightness::SetIsVideoPlaying(int64_t value) {
  SetMetricInternal(kIsVideoPlayingNameHash, value);
  return *this;
}

const char ScreenBrightness::kIsVirtualKeyboardEnabledName[] = "IsVirtualKeyboardEnabled";
const uint64_t ScreenBrightness::kIsVirtualKeyboardEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsVirtualKeyboardEnabled(int64_t value) {
  SetMetricInternal(kIsVirtualKeyboardEnabledNameHash, value);
  return *this;
}

const char ScreenBrightness::kLastActivityTimeSecName[] = "LastActivityTimeSec";
const uint64_t ScreenBrightness::kLastActivityTimeSecNameHash;

ScreenBrightness& ScreenBrightness::SetLastActivityTimeSec(int64_t value) {
  SetMetricInternal(kLastActivityTimeSecNameHash, value);
  return *this;
}

const char ScreenBrightness::kNightLightTemperaturePercentName[] = "NightLightTemperaturePercent";
const uint64_t ScreenBrightness::kNightLightTemperaturePercentNameHash;

ScreenBrightness& ScreenBrightness::SetNightLightTemperaturePercent(int64_t value) {
  SetMetricInternal(kNightLightTemperaturePercentNameHash, value);
  return *this;
}

const char ScreenBrightness::kNumRecentKeyEventsName[] = "NumRecentKeyEvents";
const uint64_t ScreenBrightness::kNumRecentKeyEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentKeyEvents(int64_t value) {
  SetMetricInternal(kNumRecentKeyEventsNameHash, value);
  return *this;
}

const char ScreenBrightness::kNumRecentMouseEventsName[] = "NumRecentMouseEvents";
const uint64_t ScreenBrightness::kNumRecentMouseEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentMouseEvents(int64_t value) {
  SetMetricInternal(kNumRecentMouseEventsNameHash, value);
  return *this;
}

const char ScreenBrightness::kNumRecentStylusEventsName[] = "NumRecentStylusEvents";
const uint64_t ScreenBrightness::kNumRecentStylusEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentStylusEvents(int64_t value) {
  SetMetricInternal(kNumRecentStylusEventsNameHash, value);
  return *this;
}

const char ScreenBrightness::kNumRecentTouchEventsName[] = "NumRecentTouchEvents";
const uint64_t ScreenBrightness::kNumRecentTouchEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentTouchEvents(int64_t value) {
  SetMetricInternal(kNumRecentTouchEventsNameHash, value);
  return *this;
}

const char ScreenBrightness::kOnBatteryName[] = "OnBattery";
const uint64_t ScreenBrightness::kOnBatteryNameHash;

ScreenBrightness& ScreenBrightness::SetOnBattery(int64_t value) {
  SetMetricInternal(kOnBatteryNameHash, value);
  return *this;
}

const char ScreenBrightness::kPreviousBrightnessName[] = "PreviousBrightness";
const uint64_t ScreenBrightness::kPreviousBrightnessNameHash;

ScreenBrightness& ScreenBrightness::SetPreviousBrightness(int64_t value) {
  SetMetricInternal(kPreviousBrightnessNameHash, value);
  return *this;
}

const char ScreenBrightness::kReasonName[] = "Reason";
const uint64_t ScreenBrightness::kReasonNameHash;

ScreenBrightness& ScreenBrightness::SetReason(int64_t value) {
  SetMetricInternal(kReasonNameHash, value);
  return *this;
}

const char ScreenBrightness::kRecentTimeActiveSecName[] = "RecentTimeActiveSec";
const uint64_t ScreenBrightness::kRecentTimeActiveSecNameHash;

ScreenBrightness& ScreenBrightness::SetRecentTimeActiveSec(int64_t value) {
  SetMetricInternal(kRecentTimeActiveSecNameHash, value);
  return *this;
}

const char ScreenBrightness::kSequenceIdName[] = "SequenceId";
const uint64_t ScreenBrightness::kSequenceIdNameHash;

ScreenBrightness& ScreenBrightness::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char ScreenBrightness::kTimeSinceLastEventSecName[] = "TimeSinceLastEventSec";
const uint64_t ScreenBrightness::kTimeSinceLastEventSecNameHash;

ScreenBrightness& ScreenBrightness::SetTimeSinceLastEventSec(int64_t value) {
  SetMetricInternal(kTimeSinceLastEventSecNameHash, value);
  return *this;
}


const char Security_SafetyTip::kEntryName[] = "Security.SafetyTip";
const uint64_t Security_SafetyTip::kEntryNameHash;

Security_SafetyTip::Security_SafetyTip(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Security_SafetyTip::Security_SafetyTip(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Security_SafetyTip::~Security_SafetyTip() = default;


const char Security_SafetyTip::kSafetyTipInteractionName[] = "SafetyTipInteraction";
const uint64_t Security_SafetyTip::kSafetyTipInteractionNameHash;

Security_SafetyTip& Security_SafetyTip::SetSafetyTipInteraction(int64_t value) {
  SetMetricInternal(kSafetyTipInteractionNameHash, value);
  return *this;
}

const char Security_SafetyTip::kSafetyTipStatusName[] = "SafetyTipStatus";
const uint64_t Security_SafetyTip::kSafetyTipStatusNameHash;

Security_SafetyTip& Security_SafetyTip::SetSafetyTipStatus(int64_t value) {
  SetMetricInternal(kSafetyTipStatusNameHash, value);
  return *this;
}

const char Security_SafetyTip::kTriggeredKeywordsHeuristicsName[] = "TriggeredKeywordsHeuristics";
const uint64_t Security_SafetyTip::kTriggeredKeywordsHeuristicsNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredKeywordsHeuristics(int64_t value) {
  SetMetricInternal(kTriggeredKeywordsHeuristicsNameHash, value);
  return *this;
}

const char Security_SafetyTip::kTriggeredLookalikeHeuristicsName[] = "TriggeredLookalikeHeuristics";
const uint64_t Security_SafetyTip::kTriggeredLookalikeHeuristicsNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredLookalikeHeuristics(int64_t value) {
  SetMetricInternal(kTriggeredLookalikeHeuristicsNameHash, value);
  return *this;
}

const char Security_SafetyTip::kTriggeredServerSideBlocklistName[] = "TriggeredServerSideBlocklist";
const uint64_t Security_SafetyTip::kTriggeredServerSideBlocklistNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredServerSideBlocklist(int64_t value) {
  SetMetricInternal(kTriggeredServerSideBlocklistNameHash, value);
  return *this;
}

const char Security_SafetyTip::kUserPreviouslyIgnoredName[] = "UserPreviouslyIgnored";
const uint64_t Security_SafetyTip::kUserPreviouslyIgnoredNameHash;

Security_SafetyTip& Security_SafetyTip::SetUserPreviouslyIgnored(int64_t value) {
  SetMetricInternal(kUserPreviouslyIgnoredNameHash, value);
  return *this;
}


const char Security_SiteEngagement::kEntryName[] = "Security.SiteEngagement";
const uint64_t Security_SiteEngagement::kEntryNameHash;

Security_SiteEngagement::Security_SiteEngagement(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Security_SiteEngagement::Security_SiteEngagement(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Security_SiteEngagement::~Security_SiteEngagement() = default;


const char Security_SiteEngagement::kFinalSecurityLevelName[] = "FinalSecurityLevel";
const uint64_t Security_SiteEngagement::kFinalSecurityLevelNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetFinalSecurityLevel(int64_t value) {
  SetMetricInternal(kFinalSecurityLevelNameHash, value);
  return *this;
}

const char Security_SiteEngagement::kInitialSecurityLevelName[] = "InitialSecurityLevel";
const uint64_t Security_SiteEngagement::kInitialSecurityLevelNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetInitialSecurityLevel(int64_t value) {
  SetMetricInternal(kInitialSecurityLevelNameHash, value);
  return *this;
}

const char Security_SiteEngagement::kSafetyTipStatusName[] = "SafetyTipStatus";
const uint64_t Security_SiteEngagement::kSafetyTipStatusNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetSafetyTipStatus(int64_t value) {
  SetMetricInternal(kSafetyTipStatusNameHash, value);
  return *this;
}

const char Security_SiteEngagement::kScoreDeltaName[] = "ScoreDelta";
const uint64_t Security_SiteEngagement::kScoreDeltaNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetScoreDelta(int64_t value) {
  SetMetricInternal(kScoreDeltaNameHash, value);
  return *this;
}

const char Security_SiteEngagement::kScoreFinalName[] = "ScoreFinal";
const uint64_t Security_SiteEngagement::kScoreFinalNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetScoreFinal(int64_t value) {
  SetMetricInternal(kScoreFinalNameHash, value);
  return *this;
}


const char Sharing_ClickToCall::kEntryName[] = "Sharing.ClickToCall";
const uint64_t Sharing_ClickToCall::kEntryNameHash;

Sharing_ClickToCall::Sharing_ClickToCall(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Sharing_ClickToCall::Sharing_ClickToCall(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Sharing_ClickToCall::~Sharing_ClickToCall() = default;


const char Sharing_ClickToCall::kEntryPointName[] = "EntryPoint";
const uint64_t Sharing_ClickToCall::kEntryPointNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetEntryPoint(int64_t value) {
  SetMetricInternal(kEntryPointNameHash, value);
  return *this;
}

const char Sharing_ClickToCall::kHasAppsName[] = "HasApps";
const uint64_t Sharing_ClickToCall::kHasAppsNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetHasApps(int64_t value) {
  SetMetricInternal(kHasAppsNameHash, value);
  return *this;
}

const char Sharing_ClickToCall::kHasDevicesName[] = "HasDevices";
const uint64_t Sharing_ClickToCall::kHasDevicesNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetHasDevices(int64_t value) {
  SetMetricInternal(kHasDevicesNameHash, value);
  return *this;
}

const char Sharing_ClickToCall::kSelectionName[] = "Selection";
const uint64_t Sharing_ClickToCall::kSelectionNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetSelection(int64_t value) {
  SetMetricInternal(kSelectionNameHash, value);
  return *this;
}


const char SmartCharging::kEntryName[] = "SmartCharging";
const uint64_t SmartCharging::kEntryNameHash;

SmartCharging::SmartCharging(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SmartCharging::SmartCharging(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SmartCharging::~SmartCharging() = default;


const char SmartCharging::kBatteryPercentageName[] = "BatteryPercentage";
const uint64_t SmartCharging::kBatteryPercentageNameHash;

SmartCharging& SmartCharging::SetBatteryPercentage(int64_t value) {
  SetMetricInternal(kBatteryPercentageNameHash, value);
  return *this;
}

const char SmartCharging::kBatteryPercentageBeforeLastChargeName[] = "BatteryPercentageBeforeLastCharge";
const uint64_t SmartCharging::kBatteryPercentageBeforeLastChargeNameHash;

SmartCharging& SmartCharging::SetBatteryPercentageBeforeLastCharge(int64_t value) {
  SetMetricInternal(kBatteryPercentageBeforeLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kBatteryPercentageOfLastChargeName[] = "BatteryPercentageOfLastCharge";
const uint64_t SmartCharging::kBatteryPercentageOfLastChargeNameHash;

SmartCharging& SmartCharging::SetBatteryPercentageOfLastCharge(int64_t value) {
  SetMetricInternal(kBatteryPercentageOfLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kDayOfMonthName[] = "DayOfMonth";
const uint64_t SmartCharging::kDayOfMonthNameHash;

SmartCharging& SmartCharging::SetDayOfMonth(int64_t value) {
  SetMetricInternal(kDayOfMonthNameHash, value);
  return *this;
}

const char SmartCharging::kDayOfWeekName[] = "DayOfWeek";
const uint64_t SmartCharging::kDayOfWeekNameHash;

SmartCharging& SmartCharging::SetDayOfWeek(int64_t value) {
  SetMetricInternal(kDayOfWeekNameHash, value);
  return *this;
}

const char SmartCharging::kDeviceModeName[] = "DeviceMode";
const uint64_t SmartCharging::kDeviceModeNameHash;

SmartCharging& SmartCharging::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char SmartCharging::kDeviceTypeName[] = "DeviceType";
const uint64_t SmartCharging::kDeviceTypeNameHash;

SmartCharging& SmartCharging::SetDeviceType(int64_t value) {
  SetMetricInternal(kDeviceTypeNameHash, value);
  return *this;
}

const char SmartCharging::kDurationOfLastChargeName[] = "DurationOfLastCharge";
const uint64_t SmartCharging::kDurationOfLastChargeNameHash;

SmartCharging& SmartCharging::SetDurationOfLastCharge(int64_t value) {
  SetMetricInternal(kDurationOfLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kDurationRecentAudioPlayingName[] = "DurationRecentAudioPlaying";
const uint64_t SmartCharging::kDurationRecentAudioPlayingNameHash;

SmartCharging& SmartCharging::SetDurationRecentAudioPlaying(int64_t value) {
  SetMetricInternal(kDurationRecentAudioPlayingNameHash, value);
  return *this;
}

const char SmartCharging::kDurationRecentVideoPlayingName[] = "DurationRecentVideoPlaying";
const uint64_t SmartCharging::kDurationRecentVideoPlayingNameHash;

SmartCharging& SmartCharging::SetDurationRecentVideoPlaying(int64_t value) {
  SetMetricInternal(kDurationRecentVideoPlayingNameHash, value);
  return *this;
}

const char SmartCharging::kEventIdName[] = "EventId";
const uint64_t SmartCharging::kEventIdNameHash;

SmartCharging& SmartCharging::SetEventId(int64_t value) {
  SetMetricInternal(kEventIdNameHash, value);
  return *this;
}

const char SmartCharging::kHaltFromLastChargeName[] = "HaltFromLastCharge";
const uint64_t SmartCharging::kHaltFromLastChargeNameHash;

SmartCharging& SmartCharging::SetHaltFromLastCharge(int64_t value) {
  SetMetricInternal(kHaltFromLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kIsChargingName[] = "IsCharging";
const uint64_t SmartCharging::kIsChargingNameHash;

SmartCharging& SmartCharging::SetIsCharging(int64_t value) {
  SetMetricInternal(kIsChargingNameHash, value);
  return *this;
}

const char SmartCharging::kMonthName[] = "Month";
const uint64_t SmartCharging::kMonthNameHash;

SmartCharging& SmartCharging::SetMonth(int64_t value) {
  SetMetricInternal(kMonthNameHash, value);
  return *this;
}

const char SmartCharging::kNumRecentKeyEventsName[] = "NumRecentKeyEvents";
const uint64_t SmartCharging::kNumRecentKeyEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentKeyEvents(int64_t value) {
  SetMetricInternal(kNumRecentKeyEventsNameHash, value);
  return *this;
}

const char SmartCharging::kNumRecentMouseEventsName[] = "NumRecentMouseEvents";
const uint64_t SmartCharging::kNumRecentMouseEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentMouseEvents(int64_t value) {
  SetMetricInternal(kNumRecentMouseEventsNameHash, value);
  return *this;
}

const char SmartCharging::kNumRecentStylusEventsName[] = "NumRecentStylusEvents";
const uint64_t SmartCharging::kNumRecentStylusEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentStylusEvents(int64_t value) {
  SetMetricInternal(kNumRecentStylusEventsNameHash, value);
  return *this;
}

const char SmartCharging::kNumRecentTouchEventsName[] = "NumRecentTouchEvents";
const uint64_t SmartCharging::kNumRecentTouchEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentTouchEvents(int64_t value) {
  SetMetricInternal(kNumRecentTouchEventsNameHash, value);
  return *this;
}

const char SmartCharging::kReasonName[] = "Reason";
const uint64_t SmartCharging::kReasonNameHash;

SmartCharging& SmartCharging::SetReason(int64_t value) {
  SetMetricInternal(kReasonNameHash, value);
  return *this;
}

const char SmartCharging::kScreenBrightnessPercentName[] = "ScreenBrightnessPercent";
const uint64_t SmartCharging::kScreenBrightnessPercentNameHash;

SmartCharging& SmartCharging::SetScreenBrightnessPercent(int64_t value) {
  SetMetricInternal(kScreenBrightnessPercentNameHash, value);
  return *this;
}

const char SmartCharging::kTimeOfTheDayName[] = "TimeOfTheDay";
const uint64_t SmartCharging::kTimeOfTheDayNameHash;

SmartCharging& SmartCharging::SetTimeOfTheDay(int64_t value) {
  SetMetricInternal(kTimeOfTheDayNameHash, value);
  return *this;
}

const char SmartCharging::kTimeSinceLastChargeName[] = "TimeSinceLastCharge";
const uint64_t SmartCharging::kTimeSinceLastChargeNameHash;

SmartCharging& SmartCharging::SetTimeSinceLastCharge(int64_t value) {
  SetMetricInternal(kTimeSinceLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kTimezoneDifferenceFromLastChargeName[] = "TimezoneDifferenceFromLastCharge";
const uint64_t SmartCharging::kTimezoneDifferenceFromLastChargeNameHash;

SmartCharging& SmartCharging::SetTimezoneDifferenceFromLastCharge(int64_t value) {
  SetMetricInternal(kTimezoneDifferenceFromLastChargeNameHash, value);
  return *this;
}

const char SmartCharging::kVoltageName[] = "Voltage";
const uint64_t SmartCharging::kVoltageNameHash;

SmartCharging& SmartCharging::SetVoltage(int64_t value) {
  SetMetricInternal(kVoltageNameHash, value);
  return *this;
}


const char SMSReceiver::kEntryName[] = "SMSReceiver";
const uint64_t SMSReceiver::kEntryNameHash;

SMSReceiver::SMSReceiver(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SMSReceiver::SMSReceiver(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SMSReceiver::~SMSReceiver() = default;


const char SMSReceiver::kOutcomeName[] = "Outcome";
const uint64_t SMSReceiver::kOutcomeNameHash;

SMSReceiver& SMSReceiver::SetOutcome(int64_t value) {
  SetMetricInternal(kOutcomeNameHash, value);
  return *this;
}


const char SSL_MixedContentShown::kEntryName[] = "SSL.MixedContentShown";
const uint64_t SSL_MixedContentShown::kEntryNameHash;

SSL_MixedContentShown::SSL_MixedContentShown(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SSL_MixedContentShown::SSL_MixedContentShown(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SSL_MixedContentShown::~SSL_MixedContentShown() = default;


const char SSL_MixedContentShown::kTypeName[] = "Type";
const uint64_t SSL_MixedContentShown::kTypeNameHash;

SSL_MixedContentShown& SSL_MixedContentShown::SetType(int64_t value) {
  SetMetricInternal(kTypeNameHash, value);
  return *this;
}


const char SubresourceFilter::kEntryName[] = "SubresourceFilter";
const uint64_t SubresourceFilter::kEntryNameHash;

SubresourceFilter::SubresourceFilter(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SubresourceFilter::SubresourceFilter(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

SubresourceFilter::~SubresourceFilter() = default;


const char SubresourceFilter::kActivationDecisionName[] = "ActivationDecision";
const uint64_t SubresourceFilter::kActivationDecisionNameHash;

SubresourceFilter& SubresourceFilter::SetActivationDecision(int64_t value) {
  SetMetricInternal(kActivationDecisionNameHash, value);
  return *this;
}

const char SubresourceFilter::kDryRunName[] = "DryRun";
const uint64_t SubresourceFilter::kDryRunNameHash;

SubresourceFilter& SubresourceFilter::SetDryRun(int64_t value) {
  SetMetricInternal(kDryRunNameHash, value);
  return *this;
}

const char SubresourceFilter::kEnforcementRedirectPositionName[] = "EnforcementRedirectPosition";
const uint64_t SubresourceFilter::kEnforcementRedirectPositionNameHash;

SubresourceFilter& SubresourceFilter::SetEnforcementRedirectPosition(int64_t value) {
  SetMetricInternal(kEnforcementRedirectPositionNameHash, value);
  return *this;
}


const char Tab_RendererOOM::kEntryName[] = "Tab.RendererOOM";
const uint64_t Tab_RendererOOM::kEntryNameHash;

Tab_RendererOOM::Tab_RendererOOM(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Tab_RendererOOM::Tab_RendererOOM(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Tab_RendererOOM::~Tab_RendererOOM() = default;


const char Tab_RendererOOM::kTimeSinceLastNavigationName[] = "TimeSinceLastNavigation";
const uint64_t Tab_RendererOOM::kTimeSinceLastNavigationNameHash;

Tab_RendererOOM& Tab_RendererOOM::SetTimeSinceLastNavigation(int64_t value) {
  SetMetricInternal(kTimeSinceLastNavigationNameHash, value);
  return *this;
}


const char Tab_Screenshot::kEntryName[] = "Tab.Screenshot";
const uint64_t Tab_Screenshot::kEntryNameHash;

Tab_Screenshot::Tab_Screenshot(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Tab_Screenshot::Tab_Screenshot(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Tab_Screenshot::~Tab_Screenshot() = default;


const char Tab_Screenshot::kHasOccurredName[] = "HasOccurred";
const uint64_t Tab_Screenshot::kHasOccurredNameHash;

Tab_Screenshot& Tab_Screenshot::SetHasOccurred(int64_t value) {
  SetMetricInternal(kHasOccurredNameHash, value);
  return *this;
}


const char TabManager_Background_FirstAlertFired::kEntryName[] = "TabManager.Background.FirstAlertFired";
const uint64_t TabManager_Background_FirstAlertFired::kEntryNameHash;

TabManager_Background_FirstAlertFired::TabManager_Background_FirstAlertFired(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstAlertFired::TabManager_Background_FirstAlertFired(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstAlertFired::~TabManager_Background_FirstAlertFired() = default;


const char TabManager_Background_FirstAlertFired::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstAlertFired::kIsMainFrameNameHash;

TabManager_Background_FirstAlertFired& TabManager_Background_FirstAlertFired::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char TabManager_Background_FirstAlertFired::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstAlertFired::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstAlertFired& TabManager_Background_FirstAlertFired::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_Background_FirstAudioStarts::kEntryName[] = "TabManager.Background.FirstAudioStarts";
const uint64_t TabManager_Background_FirstAudioStarts::kEntryNameHash;

TabManager_Background_FirstAudioStarts::TabManager_Background_FirstAudioStarts(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstAudioStarts::TabManager_Background_FirstAudioStarts(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstAudioStarts::~TabManager_Background_FirstAudioStarts() = default;


const char TabManager_Background_FirstAudioStarts::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstAudioStarts::kIsMainFrameNameHash;

TabManager_Background_FirstAudioStarts& TabManager_Background_FirstAudioStarts::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstAudioStarts& TabManager_Background_FirstAudioStarts::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_Background_FirstFaviconUpdated::kEntryName[] = "TabManager.Background.FirstFaviconUpdated";
const uint64_t TabManager_Background_FirstFaviconUpdated::kEntryNameHash;

TabManager_Background_FirstFaviconUpdated::TabManager_Background_FirstFaviconUpdated(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstFaviconUpdated::TabManager_Background_FirstFaviconUpdated(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstFaviconUpdated::~TabManager_Background_FirstFaviconUpdated() = default;


const char TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstFaviconUpdated& TabManager_Background_FirstFaviconUpdated::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_Background_FirstNonPersistentNotificationCreated::kEntryName[] = "TabManager.Background.FirstNonPersistentNotificationCreated";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kEntryNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated::TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstNonPersistentNotificationCreated::TabManager_Background_FirstNonPersistentNotificationCreated(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstNonPersistentNotificationCreated::~TabManager_Background_FirstNonPersistentNotificationCreated() = default;


const char TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated& TabManager_Background_FirstNonPersistentNotificationCreated::SetIsMainFrame(int64_t value) {
  SetMetricInternal(kIsMainFrameNameHash, value);
  return *this;
}

const char TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated& TabManager_Background_FirstNonPersistentNotificationCreated::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_Background_FirstTitleUpdated::kEntryName[] = "TabManager.Background.FirstTitleUpdated";
const uint64_t TabManager_Background_FirstTitleUpdated::kEntryNameHash;

TabManager_Background_FirstTitleUpdated::TabManager_Background_FirstTitleUpdated(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstTitleUpdated::TabManager_Background_FirstTitleUpdated(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_FirstTitleUpdated::~TabManager_Background_FirstTitleUpdated() = default;


const char TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstTitleUpdated& TabManager_Background_FirstTitleUpdated::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_Background_ForegroundedOrClosed::kEntryName[] = "TabManager.Background.ForegroundedOrClosed";
const uint64_t TabManager_Background_ForegroundedOrClosed::kEntryNameHash;

TabManager_Background_ForegroundedOrClosed::TabManager_Background_ForegroundedOrClosed(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_ForegroundedOrClosed::TabManager_Background_ForegroundedOrClosed(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Background_ForegroundedOrClosed::~TabManager_Background_ForegroundedOrClosed() = default;


const char TabManager_Background_ForegroundedOrClosed::kIsDiscardedName[] = "IsDiscarded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kIsDiscardedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetIsDiscarded(int64_t value) {
  SetMetricInternal(kIsDiscardedNameHash, value);
  return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kIsForegroundedName[] = "IsForegrounded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kIsForegroundedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetIsForegrounded(int64_t value) {
  SetMetricInternal(kIsForegroundedNameHash, value);
  return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kLabelIdName[] = "LabelId";
const uint64_t TabManager_Background_ForegroundedOrClosed::kLabelIdNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetLabelId(int64_t value) {
  SetMetricInternal(kLabelIdNameHash, value);
  return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}


const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName[] = "TabManager.BackgroundTabOpening.ForegroundTab.ExpectedTaskQueueingDurationInfo";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::~TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo() = default;


const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabLoadingCountName[] = "BackgroundTabLoadingCount";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabLoadingCountNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetBackgroundTabLoadingCount(int64_t value) {
  SetMetricInternal(kBackgroundTabLoadingCountNameHash, value);
  return *this;
}

const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabOpeningSessionIdName[] = "BackgroundTabOpeningSessionId";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabOpeningSessionIdNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetBackgroundTabOpeningSessionId(int64_t value) {
  SetMetricInternal(kBackgroundTabOpeningSessionIdNameHash, value);
  return *this;
}

const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabPendingCountName[] = "BackgroundTabPendingCount";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabPendingCountNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetBackgroundTabPendingCount(int64_t value) {
  SetMetricInternal(kBackgroundTabPendingCountNameHash, value);
  return *this;
}

const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName[] = "ExpectedTaskQueueingDuration";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetExpectedTaskQueueingDuration(int64_t value) {
  SetMetricInternal(kExpectedTaskQueueingDurationNameHash, value);
  return *this;
}

const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash;

TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSystemTabCount(int64_t value) {
  SetMetricInternal(kSystemTabCountNameHash, value);
  return *this;
}


const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryName[] = "TabManager.Experimental.BackgroundTabOpening.TabSwitchLoadStopped";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::~TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped() = default;


const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountName[] = "BackgroundTabLoadingCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabLoadingCount(int64_t value) {
  SetMetricInternal(kBackgroundTabLoadingCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdName[] = "BackgroundTabOpeningSessionId";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabOpeningSessionId(int64_t value) {
  SetMetricInternal(kBackgroundTabOpeningSessionIdNameHash, value);
  return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountName[] = "BackgroundTabPendingCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabPendingCount(int64_t value) {
  SetMetricInternal(kBackgroundTabPendingCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetSystemTabCount(int64_t value) {
  SetMetricInternal(kSystemTabCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeName[] = "TabSwitchLoadTime";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetTabSwitchLoadTime(int64_t value) {
  SetMetricInternal(kTabSwitchLoadTimeNameHash, value);
  return *this;
}


const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryName[] = "TabManager.Experimental.SessionRestore.ForegroundTab.PageLoad";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::~TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad() = default;


const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::SetSessionRestoreTabCount(int64_t value) {
  SetMetricInternal(kSessionRestoreTabCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::SetSystemTabCount(int64_t value) {
  SetMetricInternal(kSystemTabCountNameHash, value);
  return *this;
}


const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryName[] = "TabManager.Experimental.SessionRestore.TabSwitchLoadStopped";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::~TabManager_Experimental_SessionRestore_TabSwitchLoadStopped() = default;


const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdName[] = "SessionRestoreSessionId";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSessionRestoreSessionId(int64_t value) {
  SetMetricInternal(kSessionRestoreSessionIdNameHash, value);
  return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSessionRestoreTabCount(int64_t value) {
  SetMetricInternal(kSessionRestoreTabCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSystemTabCount(int64_t value) {
  SetMetricInternal(kSystemTabCountNameHash, value);
  return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeName[] = "TabSwitchLoadTime";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetTabSwitchLoadTime(int64_t value) {
  SetMetricInternal(kTabSwitchLoadTimeNameHash, value);
  return *this;
}


const char TabManager_LifecycleStateChange::kEntryName[] = "TabManager.LifecycleStateChange";
const uint64_t TabManager_LifecycleStateChange::kEntryNameHash;

TabManager_LifecycleStateChange::TabManager_LifecycleStateChange(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_LifecycleStateChange::TabManager_LifecycleStateChange(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_LifecycleStateChange::~TabManager_LifecycleStateChange() = default;


const char TabManager_LifecycleStateChange::kFailureGlobalBlacklistName[] = "FailureGlobalBlacklist";
const uint64_t TabManager_LifecycleStateChange::kFailureGlobalBlacklistNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureGlobalBlacklist(int64_t value) {
  SetMetricInternal(kFailureGlobalBlacklistNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicAudioName[] = "FailureHeuristicAudio";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicAudioNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicAudio(int64_t value) {
  SetMetricInternal(kFailureHeuristicAudioNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicFaviconName[] = "FailureHeuristicFavicon";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicFaviconNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicFavicon(int64_t value) {
  SetMetricInternal(kFailureHeuristicFaviconNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationName[] = "FailureHeuristicInsufficientObservation";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicInsufficientObservation(int64_t value) {
  SetMetricInternal(kFailureHeuristicInsufficientObservationNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicNotificationsName[] = "FailureHeuristicNotifications";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicNotificationsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicNotifications(int64_t value) {
  SetMetricInternal(kFailureHeuristicNotificationsNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicTitleName[] = "FailureHeuristicTitle";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicTitleNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicTitle(int64_t value) {
  SetMetricInternal(kFailureHeuristicTitleNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutName[] = "FailureLifecyclesEnterprisePolicyOptOut";
const uint64_t TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLifecyclesEnterprisePolicyOptOut(int64_t value) {
  SetMetricInternal(kFailureLifecyclesEnterprisePolicyOptOutNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateCapturingName[] = "FailureLiveStateCapturing";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateCapturingNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateCapturing(int64_t value) {
  SetMetricInternal(kFailureLiveStateCapturingNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureName[] = "FailureLiveStateDesktopCapture";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateDesktopCapture(int64_t value) {
  SetMetricInternal(kFailureLiveStateDesktopCaptureNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenName[] = "FailureLiveStateDevToolsOpen";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateDevToolsOpen(int64_t value) {
  SetMetricInternal(kFailureLiveStateDevToolsOpenNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedName[] = "FailureLiveStateExtensionDisallowed";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateExtensionDisallowed(int64_t value) {
  SetMetricInternal(kFailureLiveStateExtensionDisallowedNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateFormEntryName[] = "FailureLiveStateFormEntry";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateFormEntryNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateFormEntry(int64_t value) {
  SetMetricInternal(kFailureLiveStateFormEntryNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionName[] = "FailureLiveStateHasNotificationsPermission";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateHasNotificationsPermission(int64_t value) {
  SetMetricInternal(kFailureLiveStateHasNotificationsPermissionNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateIsPDFName[] = "FailureLiveStateIsPDF";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateIsPDFNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateIsPDF(int64_t value) {
  SetMetricInternal(kFailureLiveStateIsPDFNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateMirroringName[] = "FailureLiveStateMirroring";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateMirroringNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateMirroring(int64_t value) {
  SetMetricInternal(kFailureLiveStateMirroringNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioName[] = "FailureLiveStatePlayingAudio";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStatePlayingAudio(int64_t value) {
  SetMetricInternal(kFailureLiveStatePlayingAudioNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceName[] = "FailureLiveStateSharingBrowsingInstance";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateSharingBrowsingInstance(int64_t value) {
  SetMetricInternal(kFailureLiveStateSharingBrowsingInstanceNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothName[] = "FailureLiveStateUsingBluetooth";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingBluetooth(int64_t value) {
  SetMetricInternal(kFailureLiveStateUsingBluetoothNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockName[] = "FailureLiveStateUsingIndexedDBLock";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingIndexedDBLock(int64_t value) {
  SetMetricInternal(kFailureLiveStateUsingIndexedDBLockNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockName[] = "FailureLiveStateUsingWebLock";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebLock(int64_t value) {
  SetMetricInternal(kFailureLiveStateUsingWebLockNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsName[] = "FailureLiveStateUsingWebSockets";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebSockets(int64_t value) {
  SetMetricInternal(kFailureLiveStateUsingWebSocketsNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBName[] = "FailureLiveStateUsingWebUSB";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebUSB(int64_t value) {
  SetMetricInternal(kFailureLiveStateUsingWebUSBNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateVisibleName[] = "FailureLiveStateVisible";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateVisibleNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateVisible(int64_t value) {
  SetMetricInternal(kFailureLiveStateVisibleNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveWebAppName[] = "FailureLiveWebApp";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveWebAppNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveWebApp(int64_t value) {
  SetMetricInternal(kFailureLiveWebAppNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureOriginTrialOptOutName[] = "FailureOriginTrialOptOut";
const uint64_t TabManager_LifecycleStateChange::kFailureOriginTrialOptOutNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureOriginTrialOptOut(int64_t value) {
  SetMetricInternal(kFailureOriginTrialOptOutNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kFailureOriginTrialUnknownName[] = "FailureOriginTrialUnknown";
const uint64_t TabManager_LifecycleStateChange::kFailureOriginTrialUnknownNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureOriginTrialUnknown(int64_t value) {
  SetMetricInternal(kFailureOriginTrialUnknownNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kLifecycleStateChangeReasonName[] = "LifecycleStateChangeReason";
const uint64_t TabManager_LifecycleStateChange::kLifecycleStateChangeReasonNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetLifecycleStateChangeReason(int64_t value) {
  SetMetricInternal(kLifecycleStateChangeReasonNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kNewLifecycleStateName[] = "NewLifecycleState";
const uint64_t TabManager_LifecycleStateChange::kNewLifecycleStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetNewLifecycleState(int64_t value) {
  SetMetricInternal(kNewLifecycleStateNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kOldLifecycleStateName[] = "OldLifecycleState";
const uint64_t TabManager_LifecycleStateChange::kOldLifecycleStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetOldLifecycleState(int64_t value) {
  SetMetricInternal(kOldLifecycleStateNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kOutcomeName[] = "Outcome";
const uint64_t TabManager_LifecycleStateChange::kOutcomeNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetOutcome(int64_t value) {
  SetMetricInternal(kOutcomeNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kSuccessGlobalWhitelistName[] = "SuccessGlobalWhitelist";
const uint64_t TabManager_LifecycleStateChange::kSuccessGlobalWhitelistNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessGlobalWhitelist(int64_t value) {
  SetMetricInternal(kSuccessGlobalWhitelistNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kSuccessHeuristicName[] = "SuccessHeuristic";
const uint64_t TabManager_LifecycleStateChange::kSuccessHeuristicNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessHeuristic(int64_t value) {
  SetMetricInternal(kSuccessHeuristicNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kSuccessOriginTrialOptInName[] = "SuccessOriginTrialOptIn";
const uint64_t TabManager_LifecycleStateChange::kSuccessOriginTrialOptInNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessOriginTrialOptIn(int64_t value) {
  SetMetricInternal(kSuccessOriginTrialOptInNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kTimeSinceNavigationMsName[] = "TimeSinceNavigationMs";
const uint64_t TabManager_LifecycleStateChange::kTimeSinceNavigationMsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTimeSinceNavigationMs(int64_t value) {
  SetMetricInternal(kTimeSinceNavigationMsNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsName[] = "TimeSinceVisibilityStateChangeMs";
const uint64_t TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTimeSinceVisibilityStateChangeMs(int64_t value) {
  SetMetricInternal(kTimeSinceVisibilityStateChangeMsNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kTransitionForcedName[] = "TransitionForced";
const uint64_t TabManager_LifecycleStateChange::kTransitionForcedNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTransitionForced(int64_t value) {
  SetMetricInternal(kTransitionForcedNameHash, value);
  return *this;
}

const char TabManager_LifecycleStateChange::kVisibilityStateName[] = "VisibilityState";
const uint64_t TabManager_LifecycleStateChange::kVisibilityStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetVisibilityState(int64_t value) {
  SetMetricInternal(kVisibilityStateNameHash, value);
  return *this;
}


const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName[] = "TabManager.SessionRestore.ForegroundTab.ExpectedTaskQueueingDurationInfo";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::~TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo() = default;


const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName[] = "ExpectedTaskQueueingDuration";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetExpectedTaskQueueingDuration(int64_t value) {
  SetMetricInternal(kExpectedTaskQueueingDurationNameHash, value);
  return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdName[] = "SessionRestoreSessionId";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSessionRestoreSessionId(int64_t value) {
  SetMetricInternal(kSessionRestoreSessionIdNameHash, value);
  return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSessionRestoreTabCount(int64_t value) {
  SetMetricInternal(kSessionRestoreTabCountNameHash, value);
  return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSystemTabCount(int64_t value) {
  SetMetricInternal(kSystemTabCountNameHash, value);
  return *this;
}


const char TabManager_TabLifetime::kEntryName[] = "TabManager.TabLifetime";
const uint64_t TabManager_TabLifetime::kEntryNameHash;

TabManager_TabLifetime::TabManager_TabLifetime(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_TabLifetime::TabManager_TabLifetime(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_TabLifetime::~TabManager_TabLifetime() = default;


const char TabManager_TabLifetime::kTimeSinceNavigationName[] = "TimeSinceNavigation";
const uint64_t TabManager_TabLifetime::kTimeSinceNavigationNameHash;

TabManager_TabLifetime& TabManager_TabLifetime::SetTimeSinceNavigation(int64_t value) {
  SetMetricInternal(kTimeSinceNavigationNameHash, value);
  return *this;
}


const char TabManager_TabMetrics::kEntryName[] = "TabManager.TabMetrics";
const uint64_t TabManager_TabMetrics::kEntryNameHash;

TabManager_TabMetrics::TabManager_TabMetrics(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_TabMetrics::TabManager_TabMetrics(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_TabMetrics::~TabManager_TabMetrics() = default;


const char TabManager_TabMetrics::kContentTypeName[] = "ContentType";
const uint64_t TabManager_TabMetrics::kContentTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetContentType(int64_t value) {
  SetMetricInternal(kContentTypeNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kDefaultProtocolHandlerName[] = "DefaultProtocolHandler";
const uint64_t TabManager_TabMetrics::kDefaultProtocolHandlerNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetDefaultProtocolHandler(int64_t value) {
  SetMetricInternal(kDefaultProtocolHandlerNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kHasBeforeUnloadHandlerName[] = "HasBeforeUnloadHandler";
const uint64_t TabManager_TabMetrics::kHasBeforeUnloadHandlerNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetHasBeforeUnloadHandler(int64_t value) {
  SetMetricInternal(kHasBeforeUnloadHandlerNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kHasFormEntryName[] = "HasFormEntry";
const uint64_t TabManager_TabMetrics::kHasFormEntryNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetHasFormEntry(int64_t value) {
  SetMetricInternal(kHasFormEntryNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kIsExtensionProtectedName[] = "IsExtensionProtected";
const uint64_t TabManager_TabMetrics::kIsExtensionProtectedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetIsExtensionProtected(int64_t value) {
  SetMetricInternal(kIsExtensionProtectedNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kIsPinnedName[] = "IsPinned";
const uint64_t TabManager_TabMetrics::kIsPinnedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetIsPinned(int64_t value) {
  SetMetricInternal(kIsPinnedNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kKeyEventCountName[] = "KeyEventCount";
const uint64_t TabManager_TabMetrics::kKeyEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetKeyEventCount(int64_t value) {
  SetMetricInternal(kKeyEventCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kLabelIdName[] = "LabelId";
const uint64_t TabManager_TabMetrics::kLabelIdNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetLabelId(int64_t value) {
  SetMetricInternal(kLabelIdNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kMouseEventCountName[] = "MouseEventCount";
const uint64_t TabManager_TabMetrics::kMouseEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetMouseEventCount(int64_t value) {
  SetMetricInternal(kMouseEventCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kMRUIndexName[] = "MRUIndex";
const uint64_t TabManager_TabMetrics::kMRUIndexNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetMRUIndex(int64_t value) {
  SetMetricInternal(kMRUIndexNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kNavigationEntryCountName[] = "NavigationEntryCount";
const uint64_t TabManager_TabMetrics::kNavigationEntryCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetNavigationEntryCount(int64_t value) {
  SetMetricInternal(kNavigationEntryCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kNumReactivationBeforeName[] = "NumReactivationBefore";
const uint64_t TabManager_TabMetrics::kNumReactivationBeforeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetNumReactivationBefore(int64_t value) {
  SetMetricInternal(kNumReactivationBeforeNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kPageTransitionCoreTypeName[] = "PageTransitionCoreType";
const uint64_t TabManager_TabMetrics::kPageTransitionCoreTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionCoreType(int64_t value) {
  SetMetricInternal(kPageTransitionCoreTypeNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kPageTransitionFromAddressBarName[] = "PageTransitionFromAddressBar";
const uint64_t TabManager_TabMetrics::kPageTransitionFromAddressBarNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionFromAddressBar(int64_t value) {
  SetMetricInternal(kPageTransitionFromAddressBarNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kPageTransitionIsRedirectName[] = "PageTransitionIsRedirect";
const uint64_t TabManager_TabMetrics::kPageTransitionIsRedirectNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionIsRedirect(int64_t value) {
  SetMetricInternal(kPageTransitionIsRedirectNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kQueryIdName[] = "QueryId";
const uint64_t TabManager_TabMetrics::kQueryIdNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetQueryId(int64_t value) {
  SetMetricInternal(kQueryIdNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t TabManager_TabMetrics::kSiteEngagementScoreNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetSiteEngagementScore(int64_t value) {
  SetMetricInternal(kSiteEngagementScoreNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_TabMetrics::kTimeFromBackgroundedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTimeFromBackgrounded(int64_t value) {
  SetMetricInternal(kTimeFromBackgroundedNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kTotalTabCountName[] = "TotalTabCount";
const uint64_t TabManager_TabMetrics::kTotalTabCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTotalTabCount(int64_t value) {
  SetMetricInternal(kTotalTabCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kTouchEventCountName[] = "TouchEventCount";
const uint64_t TabManager_TabMetrics::kTouchEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTouchEventCount(int64_t value) {
  SetMetricInternal(kTouchEventCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kWasRecentlyAudibleName[] = "WasRecentlyAudible";
const uint64_t TabManager_TabMetrics::kWasRecentlyAudibleNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWasRecentlyAudible(int64_t value) {
  SetMetricInternal(kWasRecentlyAudibleNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kWindowIsActiveName[] = "WindowIsActive";
const uint64_t TabManager_TabMetrics::kWindowIsActiveNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowIsActive(int64_t value) {
  SetMetricInternal(kWindowIsActiveNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kWindowShowStateName[] = "WindowShowState";
const uint64_t TabManager_TabMetrics::kWindowShowStateNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowShowState(int64_t value) {
  SetMetricInternal(kWindowShowStateNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kWindowTabCountName[] = "WindowTabCount";
const uint64_t TabManager_TabMetrics::kWindowTabCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowTabCount(int64_t value) {
  SetMetricInternal(kWindowTabCountNameHash, value);
  return *this;
}

const char TabManager_TabMetrics::kWindowTypeName[] = "WindowType";
const uint64_t TabManager_TabMetrics::kWindowTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowType(int64_t value) {
  SetMetricInternal(kWindowTypeNameHash, value);
  return *this;
}


const char TabManager_WindowMetrics::kEntryName[] = "TabManager.WindowMetrics";
const uint64_t TabManager_WindowMetrics::kEntryNameHash;

TabManager_WindowMetrics::TabManager_WindowMetrics(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_WindowMetrics::TabManager_WindowMetrics(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TabManager_WindowMetrics::~TabManager_WindowMetrics() = default;


const char TabManager_WindowMetrics::kIsActiveName[] = "IsActive";
const uint64_t TabManager_WindowMetrics::kIsActiveNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetIsActive(int64_t value) {
  SetMetricInternal(kIsActiveNameHash, value);
  return *this;
}

const char TabManager_WindowMetrics::kShowStateName[] = "ShowState";
const uint64_t TabManager_WindowMetrics::kShowStateNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetShowState(int64_t value) {
  SetMetricInternal(kShowStateNameHash, value);
  return *this;
}

const char TabManager_WindowMetrics::kTabCountName[] = "TabCount";
const uint64_t TabManager_WindowMetrics::kTabCountNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetTabCount(int64_t value) {
  SetMetricInternal(kTabCountNameHash, value);
  return *this;
}

const char TabManager_WindowMetrics::kTypeName[] = "Type";
const uint64_t TabManager_WindowMetrics::kTypeNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetType(int64_t value) {
  SetMetricInternal(kTypeNameHash, value);
  return *this;
}

const char TabManager_WindowMetrics::kWindowIdName[] = "WindowId";
const uint64_t TabManager_WindowMetrics::kWindowIdNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetWindowId(int64_t value) {
  SetMetricInternal(kWindowIdNameHash, value);
  return *this;
}


const char TouchToFill_Shown::kEntryName[] = "TouchToFill.Shown";
const uint64_t TouchToFill_Shown::kEntryNameHash;

TouchToFill_Shown::TouchToFill_Shown(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TouchToFill_Shown::TouchToFill_Shown(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TouchToFill_Shown::~TouchToFill_Shown() = default;


const char TouchToFill_Shown::kUserActionName[] = "UserAction";
const uint64_t TouchToFill_Shown::kUserActionNameHash;

TouchToFill_Shown& TouchToFill_Shown::SetUserAction(int64_t value) {
  SetMetricInternal(kUserActionNameHash, value);
  return *this;
}


const char Translate::kEntryName[] = "Translate";
const uint64_t Translate::kEntryNameHash;

Translate::Translate(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Translate::Translate(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

Translate::~Translate() = default;


const char Translate::kAcceptCountName[] = "AcceptCount";
const uint64_t Translate::kAcceptCountNameHash;

Translate& Translate::SetAcceptCount(int64_t value) {
  SetMetricInternal(kAcceptCountNameHash, value);
  return *this;
}

const char Translate::kCountryName[] = "Country";
const uint64_t Translate::kCountryNameHash;

Translate& Translate::SetCountry(int64_t value) {
  SetMetricInternal(kCountryNameHash, value);
  return *this;
}

const char Translate::kDeclineCountName[] = "DeclineCount";
const uint64_t Translate::kDeclineCountNameHash;

Translate& Translate::SetDeclineCount(int64_t value) {
  SetMetricInternal(kDeclineCountNameHash, value);
  return *this;
}

const char Translate::kEventTypeName[] = "EventType";
const uint64_t Translate::kEventTypeNameHash;

Translate& Translate::SetEventType(int64_t value) {
  SetMetricInternal(kEventTypeNameHash, value);
  return *this;
}

const char Translate::kIgnoreCountName[] = "IgnoreCount";
const uint64_t Translate::kIgnoreCountNameHash;

Translate& Translate::SetIgnoreCount(int64_t value) {
  SetMetricInternal(kIgnoreCountNameHash, value);
  return *this;
}

const char Translate::kRankerResponseName[] = "RankerResponse";
const uint64_t Translate::kRankerResponseNameHash;

Translate& Translate::SetRankerResponse(int64_t value) {
  SetMetricInternal(kRankerResponseNameHash, value);
  return *this;
}

const char Translate::kRankerVersionName[] = "RankerVersion";
const uint64_t Translate::kRankerVersionNameHash;

Translate& Translate::SetRankerVersion(int64_t value) {
  SetMetricInternal(kRankerVersionNameHash, value);
  return *this;
}

const char Translate::kSourceLanguageName[] = "SourceLanguage";
const uint64_t Translate::kSourceLanguageNameHash;

Translate& Translate::SetSourceLanguage(int64_t value) {
  SetMetricInternal(kSourceLanguageNameHash, value);
  return *this;
}

const char Translate::kTargetLanguageName[] = "TargetLanguage";
const uint64_t Translate::kTargetLanguageNameHash;

Translate& Translate::SetTargetLanguage(int64_t value) {
  SetMetricInternal(kTargetLanguageNameHash, value);
  return *this;
}


const char TrustedWebActivity_Open::kEntryName[] = "TrustedWebActivity.Open";
const uint64_t TrustedWebActivity_Open::kEntryNameHash;

TrustedWebActivity_Open::TrustedWebActivity_Open(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TrustedWebActivity_Open::TrustedWebActivity_Open(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

TrustedWebActivity_Open::~TrustedWebActivity_Open() = default;


const char TrustedWebActivity_Open::kHasOccurredName[] = "HasOccurred";
const uint64_t TrustedWebActivity_Open::kHasOccurredNameHash;

TrustedWebActivity_Open& TrustedWebActivity_Open::SetHasOccurred(int64_t value) {
  SetMetricInternal(kHasOccurredNameHash, value);
  return *this;
}


const char UserActivity::kEntryName[] = "UserActivity";
const uint64_t UserActivity::kEntryNameHash;

UserActivity::UserActivity(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserActivity::UserActivity(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserActivity::~UserActivity() = default;


const char UserActivity::kBatteryPercentName[] = "BatteryPercent";
const uint64_t UserActivity::kBatteryPercentNameHash;

UserActivity& UserActivity::SetBatteryPercent(int64_t value) {
  SetMetricInternal(kBatteryPercentNameHash, value);
  return *this;
}

const char UserActivity::kDeviceManagementName[] = "DeviceManagement";
const uint64_t UserActivity::kDeviceManagementNameHash;

UserActivity& UserActivity::SetDeviceManagement(int64_t value) {
  SetMetricInternal(kDeviceManagementNameHash, value);
  return *this;
}

const char UserActivity::kDeviceModeName[] = "DeviceMode";
const uint64_t UserActivity::kDeviceModeNameHash;

UserActivity& UserActivity::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char UserActivity::kDeviceTypeName[] = "DeviceType";
const uint64_t UserActivity::kDeviceTypeNameHash;

UserActivity& UserActivity::SetDeviceType(int64_t value) {
  SetMetricInternal(kDeviceTypeNameHash, value);
  return *this;
}

const char UserActivity::kEventLogDurationName[] = "EventLogDuration";
const uint64_t UserActivity::kEventLogDurationNameHash;

UserActivity& UserActivity::SetEventLogDuration(int64_t value) {
  SetMetricInternal(kEventLogDurationNameHash, value);
  return *this;
}

const char UserActivity::kEventReasonName[] = "EventReason";
const uint64_t UserActivity::kEventReasonNameHash;

UserActivity& UserActivity::SetEventReason(int64_t value) {
  SetMetricInternal(kEventReasonNameHash, value);
  return *this;
}

const char UserActivity::kEventTypeName[] = "EventType";
const uint64_t UserActivity::kEventTypeNameHash;

UserActivity& UserActivity::SetEventType(int64_t value) {
  SetMetricInternal(kEventTypeNameHash, value);
  return *this;
}

const char UserActivity::kKeyEventsInLastHourName[] = "KeyEventsInLastHour";
const uint64_t UserActivity::kKeyEventsInLastHourNameHash;

UserActivity& UserActivity::SetKeyEventsInLastHour(int64_t value) {
  SetMetricInternal(kKeyEventsInLastHourNameHash, value);
  return *this;
}

const char UserActivity::kLastActivityDayName[] = "LastActivityDay";
const uint64_t UserActivity::kLastActivityDayNameHash;

UserActivity& UserActivity::SetLastActivityDay(int64_t value) {
  SetMetricInternal(kLastActivityDayNameHash, value);
  return *this;
}

const char UserActivity::kLastActivityTimeName[] = "LastActivityTime";
const uint64_t UserActivity::kLastActivityTimeNameHash;

UserActivity& UserActivity::SetLastActivityTime(int64_t value) {
  SetMetricInternal(kLastActivityTimeNameHash, value);
  return *this;
}

const char UserActivity::kLastUserActivityTimeName[] = "LastUserActivityTime";
const uint64_t UserActivity::kLastUserActivityTimeNameHash;

UserActivity& UserActivity::SetLastUserActivityTime(int64_t value) {
  SetMetricInternal(kLastUserActivityTimeNameHash, value);
  return *this;
}

const char UserActivity::kModelAppliedName[] = "ModelApplied";
const uint64_t UserActivity::kModelAppliedNameHash;

UserActivity& UserActivity::SetModelApplied(int64_t value) {
  SetMetricInternal(kModelAppliedNameHash, value);
  return *this;
}

const char UserActivity::kModelDecisionThresholdName[] = "ModelDecisionThreshold";
const uint64_t UserActivity::kModelDecisionThresholdNameHash;

UserActivity& UserActivity::SetModelDecisionThreshold(int64_t value) {
  SetMetricInternal(kModelDecisionThresholdNameHash, value);
  return *this;
}

const char UserActivity::kModelInactivityScoreName[] = "ModelInactivityScore";
const uint64_t UserActivity::kModelInactivityScoreNameHash;

UserActivity& UserActivity::SetModelInactivityScore(int64_t value) {
  SetMetricInternal(kModelInactivityScoreNameHash, value);
  return *this;
}

const char UserActivity::kModelResponseName[] = "ModelResponse";
const uint64_t UserActivity::kModelResponseNameHash;

UserActivity& UserActivity::SetModelResponse(int64_t value) {
  SetMetricInternal(kModelResponseNameHash, value);
  return *this;
}

const char UserActivity::kMouseEventsInLastHourName[] = "MouseEventsInLastHour";
const uint64_t UserActivity::kMouseEventsInLastHourNameHash;

UserActivity& UserActivity::SetMouseEventsInLastHour(int64_t value) {
  SetMetricInternal(kMouseEventsInLastHourNameHash, value);
  return *this;
}

const char UserActivity::kOnBatteryName[] = "OnBattery";
const uint64_t UserActivity::kOnBatteryNameHash;

UserActivity& UserActivity::SetOnBattery(int64_t value) {
  SetMetricInternal(kOnBatteryNameHash, value);
  return *this;
}

const char UserActivity::kPreviousNegativeActionsCountName[] = "PreviousNegativeActionsCount";
const uint64_t UserActivity::kPreviousNegativeActionsCountNameHash;

UserActivity& UserActivity::SetPreviousNegativeActionsCount(int64_t value) {
  SetMetricInternal(kPreviousNegativeActionsCountNameHash, value);
  return *this;
}

const char UserActivity::kPreviousPositiveActionsCountName[] = "PreviousPositiveActionsCount";
const uint64_t UserActivity::kPreviousPositiveActionsCountNameHash;

UserActivity& UserActivity::SetPreviousPositiveActionsCount(int64_t value) {
  SetMetricInternal(kPreviousPositiveActionsCountNameHash, value);
  return *this;
}

const char UserActivity::kRecentTimeActiveName[] = "RecentTimeActive";
const uint64_t UserActivity::kRecentTimeActiveNameHash;

UserActivity& UserActivity::SetRecentTimeActive(int64_t value) {
  SetMetricInternal(kRecentTimeActiveNameHash, value);
  return *this;
}

const char UserActivity::kRecentVideoPlayingTimeName[] = "RecentVideoPlayingTime";
const uint64_t UserActivity::kRecentVideoPlayingTimeNameHash;

UserActivity& UserActivity::SetRecentVideoPlayingTime(int64_t value) {
  SetMetricInternal(kRecentVideoPlayingTimeNameHash, value);
  return *this;
}

const char UserActivity::kScreenDimDelayName[] = "ScreenDimDelay";
const uint64_t UserActivity::kScreenDimDelayNameHash;

UserActivity& UserActivity::SetScreenDimDelay(int64_t value) {
  SetMetricInternal(kScreenDimDelayNameHash, value);
  return *this;
}

const char UserActivity::kScreenDimmedInitiallyName[] = "ScreenDimmedInitially";
const uint64_t UserActivity::kScreenDimmedInitiallyNameHash;

UserActivity& UserActivity::SetScreenDimmedInitially(int64_t value) {
  SetMetricInternal(kScreenDimmedInitiallyNameHash, value);
  return *this;
}

const char UserActivity::kScreenDimOccurredName[] = "ScreenDimOccurred";
const uint64_t UserActivity::kScreenDimOccurredNameHash;

UserActivity& UserActivity::SetScreenDimOccurred(int64_t value) {
  SetMetricInternal(kScreenDimOccurredNameHash, value);
  return *this;
}

const char UserActivity::kScreenDimToOffDelayName[] = "ScreenDimToOffDelay";
const uint64_t UserActivity::kScreenDimToOffDelayNameHash;

UserActivity& UserActivity::SetScreenDimToOffDelay(int64_t value) {
  SetMetricInternal(kScreenDimToOffDelayNameHash, value);
  return *this;
}

const char UserActivity::kScreenLockedInitiallyName[] = "ScreenLockedInitially";
const uint64_t UserActivity::kScreenLockedInitiallyNameHash;

UserActivity& UserActivity::SetScreenLockedInitially(int64_t value) {
  SetMetricInternal(kScreenLockedInitiallyNameHash, value);
  return *this;
}

const char UserActivity::kScreenLockOccurredName[] = "ScreenLockOccurred";
const uint64_t UserActivity::kScreenLockOccurredNameHash;

UserActivity& UserActivity::SetScreenLockOccurred(int64_t value) {
  SetMetricInternal(kScreenLockOccurredNameHash, value);
  return *this;
}

const char UserActivity::kScreenOffInitiallyName[] = "ScreenOffInitially";
const uint64_t UserActivity::kScreenOffInitiallyNameHash;

UserActivity& UserActivity::SetScreenOffInitially(int64_t value) {
  SetMetricInternal(kScreenOffInitiallyNameHash, value);
  return *this;
}

const char UserActivity::kScreenOffOccurredName[] = "ScreenOffOccurred";
const uint64_t UserActivity::kScreenOffOccurredNameHash;

UserActivity& UserActivity::SetScreenOffOccurred(int64_t value) {
  SetMetricInternal(kScreenOffOccurredNameHash, value);
  return *this;
}

const char UserActivity::kSequenceIdName[] = "SequenceId";
const uint64_t UserActivity::kSequenceIdNameHash;

UserActivity& UserActivity::SetSequenceId(int64_t value) {
  SetMetricInternal(kSequenceIdNameHash, value);
  return *this;
}

const char UserActivity::kTimeSinceLastKeyName[] = "TimeSinceLastKey";
const uint64_t UserActivity::kTimeSinceLastKeyNameHash;

UserActivity& UserActivity::SetTimeSinceLastKey(int64_t value) {
  SetMetricInternal(kTimeSinceLastKeyNameHash, value);
  return *this;
}

const char UserActivity::kTimeSinceLastMouseName[] = "TimeSinceLastMouse";
const uint64_t UserActivity::kTimeSinceLastMouseNameHash;

UserActivity& UserActivity::SetTimeSinceLastMouse(int64_t value) {
  SetMetricInternal(kTimeSinceLastMouseNameHash, value);
  return *this;
}

const char UserActivity::kTimeSinceLastTouchName[] = "TimeSinceLastTouch";
const uint64_t UserActivity::kTimeSinceLastTouchNameHash;

UserActivity& UserActivity::SetTimeSinceLastTouch(int64_t value) {
  SetMetricInternal(kTimeSinceLastTouchNameHash, value);
  return *this;
}

const char UserActivity::kTimeSinceLastVideoEndedName[] = "TimeSinceLastVideoEnded";
const uint64_t UserActivity::kTimeSinceLastVideoEndedNameHash;

UserActivity& UserActivity::SetTimeSinceLastVideoEnded(int64_t value) {
  SetMetricInternal(kTimeSinceLastVideoEndedNameHash, value);
  return *this;
}

const char UserActivity::kTouchEventsInLastHourName[] = "TouchEventsInLastHour";
const uint64_t UserActivity::kTouchEventsInLastHourNameHash;

UserActivity& UserActivity::SetTouchEventsInLastHour(int64_t value) {
  SetMetricInternal(kTouchEventsInLastHourNameHash, value);
  return *this;
}


const char UserActivityId::kEntryName[] = "UserActivityId";
const uint64_t UserActivityId::kEntryNameHash;

UserActivityId::UserActivityId(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserActivityId::UserActivityId(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserActivityId::~UserActivityId() = default;


const char UserActivityId::kActivityIdName[] = "ActivityId";
const uint64_t UserActivityId::kActivityIdNameHash;

UserActivityId& UserActivityId::SetActivityId(int64_t value) {
  SetMetricInternal(kActivityIdNameHash, value);
  return *this;
}

const char UserActivityId::kContentTypeName[] = "ContentType";
const uint64_t UserActivityId::kContentTypeNameHash;

UserActivityId& UserActivityId::SetContentType(int64_t value) {
  SetMetricInternal(kContentTypeNameHash, value);
  return *this;
}

const char UserActivityId::kHasFormEntryName[] = "HasFormEntry";
const uint64_t UserActivityId::kHasFormEntryNameHash;

UserActivityId& UserActivityId::SetHasFormEntry(int64_t value) {
  SetMetricInternal(kHasFormEntryNameHash, value);
  return *this;
}

const char UserActivityId::kIsActiveName[] = "IsActive";
const uint64_t UserActivityId::kIsActiveNameHash;

UserActivityId& UserActivityId::SetIsActive(int64_t value) {
  SetMetricInternal(kIsActiveNameHash, value);
  return *this;
}

const char UserActivityId::kIsBrowserFocusedName[] = "IsBrowserFocused";
const uint64_t UserActivityId::kIsBrowserFocusedNameHash;

UserActivityId& UserActivityId::SetIsBrowserFocused(int64_t value) {
  SetMetricInternal(kIsBrowserFocusedNameHash, value);
  return *this;
}

const char UserActivityId::kIsBrowserVisibleName[] = "IsBrowserVisible";
const uint64_t UserActivityId::kIsBrowserVisibleNameHash;

UserActivityId& UserActivityId::SetIsBrowserVisible(int64_t value) {
  SetMetricInternal(kIsBrowserVisibleNameHash, value);
  return *this;
}

const char UserActivityId::kIsTopmostBrowserName[] = "IsTopmostBrowser";
const uint64_t UserActivityId::kIsTopmostBrowserNameHash;

UserActivityId& UserActivityId::SetIsTopmostBrowser(int64_t value) {
  SetMetricInternal(kIsTopmostBrowserNameHash, value);
  return *this;
}

const char UserActivityId::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t UserActivityId::kSiteEngagementScoreNameHash;

UserActivityId& UserActivityId::SetSiteEngagementScore(int64_t value) {
  SetMetricInternal(kSiteEngagementScoreNameHash, value);
  return *this;
}


const char UserSettingsEvent::kEntryName[] = "UserSettingsEvent";
const uint64_t UserSettingsEvent::kEntryNameHash;

UserSettingsEvent::UserSettingsEvent(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserSettingsEvent::UserSettingsEvent(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

UserSettingsEvent::~UserSettingsEvent() = default;


const char UserSettingsEvent::kAccessibilityIdName[] = "AccessibilityId";
const uint64_t UserSettingsEvent::kAccessibilityIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetAccessibilityId(int64_t value) {
  SetMetricInternal(kAccessibilityIdNameHash, value);
  return *this;
}

const char UserSettingsEvent::kBatteryPercentageName[] = "BatteryPercentage";
const uint64_t UserSettingsEvent::kBatteryPercentageNameHash;

UserSettingsEvent& UserSettingsEvent::SetBatteryPercentage(int64_t value) {
  SetMetricInternal(kBatteryPercentageNameHash, value);
  return *this;
}

const char UserSettingsEvent::kCountryName[] = "Country";
const uint64_t UserSettingsEvent::kCountryNameHash;

UserSettingsEvent& UserSettingsEvent::SetCountry(int64_t value) {
  SetMetricInternal(kCountryNameHash, value);
  return *this;
}

const char UserSettingsEvent::kCurrentValueName[] = "CurrentValue";
const uint64_t UserSettingsEvent::kCurrentValueNameHash;

UserSettingsEvent& UserSettingsEvent::SetCurrentValue(int64_t value) {
  SetMetricInternal(kCurrentValueNameHash, value);
  return *this;
}

const char UserSettingsEvent::kDayOfWeekName[] = "DayOfWeek";
const uint64_t UserSettingsEvent::kDayOfWeekNameHash;

UserSettingsEvent& UserSettingsEvent::SetDayOfWeek(int64_t value) {
  SetMetricInternal(kDayOfWeekNameHash, value);
  return *this;
}

const char UserSettingsEvent::kDeviceModeName[] = "DeviceMode";
const uint64_t UserSettingsEvent::kDeviceModeNameHash;

UserSettingsEvent& UserSettingsEvent::SetDeviceMode(int64_t value) {
  SetMetricInternal(kDeviceModeNameHash, value);
  return *this;
}

const char UserSettingsEvent::kDeviceOrientationName[] = "DeviceOrientation";
const uint64_t UserSettingsEvent::kDeviceOrientationNameHash;

UserSettingsEvent& UserSettingsEvent::SetDeviceOrientation(int64_t value) {
  SetMetricInternal(kDeviceOrientationNameHash, value);
  return *this;
}

const char UserSettingsEvent::kEventIdName[] = "EventId";
const uint64_t UserSettingsEvent::kEventIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetEventId(int64_t value) {
  SetMetricInternal(kEventIdNameHash, value);
  return *this;
}

const char UserSettingsEvent::kHasNightLightScheduleName[] = "HasNightLightSchedule";
const uint64_t UserSettingsEvent::kHasNightLightScheduleNameHash;

UserSettingsEvent& UserSettingsEvent::SetHasNightLightSchedule(int64_t value) {
  SetMetricInternal(kHasNightLightScheduleNameHash, value);
  return *this;
}

const char UserSettingsEvent::kHasWifiSecurityName[] = "HasWifiSecurity";
const uint64_t UserSettingsEvent::kHasWifiSecurityNameHash;

UserSettingsEvent& UserSettingsEvent::SetHasWifiSecurity(int64_t value) {
  SetMetricInternal(kHasWifiSecurityNameHash, value);
  return *this;
}

const char UserSettingsEvent::kHourOfDayName[] = "HourOfDay";
const uint64_t UserSettingsEvent::kHourOfDayNameHash;

UserSettingsEvent& UserSettingsEvent::SetHourOfDay(int64_t value) {
  SetMetricInternal(kHourOfDayNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsAfterSunsetName[] = "IsAfterSunset";
const uint64_t UserSettingsEvent::kIsAfterSunsetNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsAfterSunset(int64_t value) {
  SetMetricInternal(kIsAfterSunsetNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsChargingName[] = "IsCharging";
const uint64_t UserSettingsEvent::kIsChargingNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsCharging(int64_t value) {
  SetMetricInternal(kIsChargingNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsFromSearchName[] = "IsFromSearch";
const uint64_t UserSettingsEvent::kIsFromSearchNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsFromSearch(int64_t value) {
  SetMetricInternal(kIsFromSearchNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsPairedBluetoothDeviceName[] = "IsPairedBluetoothDevice";
const uint64_t UserSettingsEvent::kIsPairedBluetoothDeviceNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPairedBluetoothDevice(int64_t value) {
  SetMetricInternal(kIsPairedBluetoothDeviceNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsPlayingAudioName[] = "IsPlayingAudio";
const uint64_t UserSettingsEvent::kIsPlayingAudioNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPlayingAudio(int64_t value) {
  SetMetricInternal(kIsPlayingAudioNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsPlayingVideoName[] = "IsPlayingVideo";
const uint64_t UserSettingsEvent::kIsPlayingVideoNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPlayingVideo(int64_t value) {
  SetMetricInternal(kIsPlayingVideoNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsRecentlyFullscreenName[] = "IsRecentlyFullscreen";
const uint64_t UserSettingsEvent::kIsRecentlyFullscreenNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsRecentlyFullscreen(int64_t value) {
  SetMetricInternal(kIsRecentlyFullscreenNameHash, value);
  return *this;
}

const char UserSettingsEvent::kIsRecentlyPresentingName[] = "IsRecentlyPresenting";
const uint64_t UserSettingsEvent::kIsRecentlyPresentingNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsRecentlyPresenting(int64_t value) {
  SetMetricInternal(kIsRecentlyPresentingNameHash, value);
  return *this;
}

const char UserSettingsEvent::kNetworkStatusName[] = "NetworkStatus";
const uint64_t UserSettingsEvent::kNetworkStatusNameHash;

UserSettingsEvent& UserSettingsEvent::SetNetworkStatus(int64_t value) {
  SetMetricInternal(kNetworkStatusNameHash, value);
  return *this;
}

const char UserSettingsEvent::kPreviousValueName[] = "PreviousValue";
const uint64_t UserSettingsEvent::kPreviousValueNameHash;

UserSettingsEvent& UserSettingsEvent::SetPreviousValue(int64_t value) {
  SetMetricInternal(kPreviousValueNameHash, value);
  return *this;
}

const char UserSettingsEvent::kSettingIdName[] = "SettingId";
const uint64_t UserSettingsEvent::kSettingIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetSettingId(int64_t value) {
  SetMetricInternal(kSettingIdNameHash, value);
  return *this;
}

const char UserSettingsEvent::kSettingTypeName[] = "SettingType";
const uint64_t UserSettingsEvent::kSettingTypeNameHash;

UserSettingsEvent& UserSettingsEvent::SetSettingType(int64_t value) {
  SetMetricInternal(kSettingTypeNameHash, value);
  return *this;
}

const char UserSettingsEvent::kSignalStrengthName[] = "SignalStrength";
const uint64_t UserSettingsEvent::kSignalStrengthNameHash;

UserSettingsEvent& UserSettingsEvent::SetSignalStrength(int64_t value) {
  SetMetricInternal(kSignalStrengthNameHash, value);
  return *this;
}

const char UserSettingsEvent::kTimeSinceLastSettingsChangeName[] = "TimeSinceLastSettingsChange";
const uint64_t UserSettingsEvent::kTimeSinceLastSettingsChangeNameHash;

UserSettingsEvent& UserSettingsEvent::SetTimeSinceLastSettingsChange(int64_t value) {
  SetMetricInternal(kTimeSinceLastSettingsChangeNameHash, value);
  return *this;
}

const char UserSettingsEvent::kUsedCellularInSessionName[] = "UsedCellularInSession";
const uint64_t UserSettingsEvent::kUsedCellularInSessionNameHash;

UserSettingsEvent& UserSettingsEvent::SetUsedCellularInSession(int64_t value) {
  SetMetricInternal(kUsedCellularInSessionNameHash, value);
  return *this;
}


const char VirtualKeyboard_Open::kEntryName[] = "VirtualKeyboard.Open";
const uint64_t VirtualKeyboard_Open::kEntryNameHash;

VirtualKeyboard_Open::VirtualKeyboard_Open(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

VirtualKeyboard_Open::VirtualKeyboard_Open(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

VirtualKeyboard_Open::~VirtualKeyboard_Open() = default;


const char VirtualKeyboard_Open::kTextInputTypeName[] = "TextInputType";
const uint64_t VirtualKeyboard_Open::kTextInputTypeNameHash;

VirtualKeyboard_Open& VirtualKeyboard_Open::SetTextInputType(int64_t value) {
  SetMetricInternal(kTextInputTypeNameHash, value);
  return *this;
}


const char WebAPK_Install::kEntryName[] = "WebAPK.Install";
const uint64_t WebAPK_Install::kEntryNameHash;

WebAPK_Install::WebAPK_Install(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Install::WebAPK_Install(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Install::~WebAPK_Install() = default;


const char WebAPK_Install::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Install::kAppVersionNameHash;

WebAPK_Install& WebAPK_Install::SetAppVersion(int64_t value) {
  SetMetricInternal(kAppVersionNameHash, value);
  return *this;
}

const char WebAPK_Install::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Install::kDistributorNameHash;

WebAPK_Install& WebAPK_Install::SetDistributor(int64_t value) {
  SetMetricInternal(kDistributorNameHash, value);
  return *this;
}

const char WebAPK_Install::kInstallName[] = "Install";
const uint64_t WebAPK_Install::kInstallNameHash;

WebAPK_Install& WebAPK_Install::SetInstall(int64_t value) {
  SetMetricInternal(kInstallNameHash, value);
  return *this;
}


const char WebAPK_SessionEnd::kEntryName[] = "WebAPK.SessionEnd";
const uint64_t WebAPK_SessionEnd::kEntryNameHash;

WebAPK_SessionEnd::WebAPK_SessionEnd(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_SessionEnd::WebAPK_SessionEnd(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_SessionEnd::~WebAPK_SessionEnd() = default;


const char WebAPK_SessionEnd::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_SessionEnd::kAppVersionNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetAppVersion(int64_t value) {
  SetMetricInternal(kAppVersionNameHash, value);
  return *this;
}

const char WebAPK_SessionEnd::kDistributorName[] = "Distributor";
const uint64_t WebAPK_SessionEnd::kDistributorNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetDistributor(int64_t value) {
  SetMetricInternal(kDistributorNameHash, value);
  return *this;
}

const char WebAPK_SessionEnd::kSessionDurationName[] = "SessionDuration";
const uint64_t WebAPK_SessionEnd::kSessionDurationNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetSessionDuration(int64_t value) {
  SetMetricInternal(kSessionDurationNameHash, value);
  return *this;
}


const char WebAPK_Uninstall::kEntryName[] = "WebAPK.Uninstall";
const uint64_t WebAPK_Uninstall::kEntryNameHash;

WebAPK_Uninstall::WebAPK_Uninstall(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Uninstall::WebAPK_Uninstall(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Uninstall::~WebAPK_Uninstall() = default;


const char WebAPK_Uninstall::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Uninstall::kAppVersionNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetAppVersion(int64_t value) {
  SetMetricInternal(kAppVersionNameHash, value);
  return *this;
}

const char WebAPK_Uninstall::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Uninstall::kDistributorNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetDistributor(int64_t value) {
  SetMetricInternal(kDistributorNameHash, value);
  return *this;
}

const char WebAPK_Uninstall::kInstalledDurationName[] = "InstalledDuration";
const uint64_t WebAPK_Uninstall::kInstalledDurationNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetInstalledDuration(int64_t value) {
  SetMetricInternal(kInstalledDurationNameHash, value);
  return *this;
}

const char WebAPK_Uninstall::kLifetimeLaunchesName[] = "LifetimeLaunches";
const uint64_t WebAPK_Uninstall::kLifetimeLaunchesNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetLifetimeLaunches(int64_t value) {
  SetMetricInternal(kLifetimeLaunchesNameHash, value);
  return *this;
}

const char WebAPK_Uninstall::kUninstallName[] = "Uninstall";
const uint64_t WebAPK_Uninstall::kUninstallNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetUninstall(int64_t value) {
  SetMetricInternal(kUninstallNameHash, value);
  return *this;
}


const char WebAPK_Visit::kEntryName[] = "WebAPK.Visit";
const uint64_t WebAPK_Visit::kEntryNameHash;

WebAPK_Visit::WebAPK_Visit(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Visit::WebAPK_Visit(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebAPK_Visit::~WebAPK_Visit() = default;


const char WebAPK_Visit::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Visit::kAppVersionNameHash;

WebAPK_Visit& WebAPK_Visit::SetAppVersion(int64_t value) {
  SetMetricInternal(kAppVersionNameHash, value);
  return *this;
}

const char WebAPK_Visit::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Visit::kDistributorNameHash;

WebAPK_Visit& WebAPK_Visit::SetDistributor(int64_t value) {
  SetMetricInternal(kDistributorNameHash, value);
  return *this;
}

const char WebAPK_Visit::kLaunchName[] = "Launch";
const uint64_t WebAPK_Visit::kLaunchNameHash;

WebAPK_Visit& WebAPK_Visit::SetLaunch(int64_t value) {
  SetMetricInternal(kLaunchNameHash, value);
  return *this;
}

const char WebAPK_Visit::kLaunchSourceName[] = "LaunchSource";
const uint64_t WebAPK_Visit::kLaunchSourceNameHash;

WebAPK_Visit& WebAPK_Visit::SetLaunchSource(int64_t value) {
  SetMetricInternal(kLaunchSourceNameHash, value);
  return *this;
}


const char WebApp_DailyInteraction::kEntryName[] = "WebApp.DailyInteraction";
const uint64_t WebApp_DailyInteraction::kEntryNameHash;

WebApp_DailyInteraction::WebApp_DailyInteraction(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebApp_DailyInteraction::WebApp_DailyInteraction(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebApp_DailyInteraction::~WebApp_DailyInteraction() = default;


const char WebApp_DailyInteraction::kBackgroundDurationName[] = "BackgroundDuration";
const uint64_t WebApp_DailyInteraction::kBackgroundDurationNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetBackgroundDuration(int64_t value) {
  SetMetricInternal(kBackgroundDurationNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kDisplayModeName[] = "DisplayMode";
const uint64_t WebApp_DailyInteraction::kDisplayModeNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetDisplayMode(int64_t value) {
  SetMetricInternal(kDisplayModeNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kForegroundDurationName[] = "ForegroundDuration";
const uint64_t WebApp_DailyInteraction::kForegroundDurationNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetForegroundDuration(int64_t value) {
  SetMetricInternal(kForegroundDurationNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kInstalledName[] = "Installed";
const uint64_t WebApp_DailyInteraction::kInstalledNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetInstalled(int64_t value) {
  SetMetricInternal(kInstalledNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kInstallSourceName[] = "InstallSource";
const uint64_t WebApp_DailyInteraction::kInstallSourceNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetInstallSource(int64_t value) {
  SetMetricInternal(kInstallSourceNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kNumSessionsName[] = "NumSessions";
const uint64_t WebApp_DailyInteraction::kNumSessionsNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetNumSessions(int64_t value) {
  SetMetricInternal(kNumSessionsNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kPromotableName[] = "Promotable";
const uint64_t WebApp_DailyInteraction::kPromotableNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetPromotable(int64_t value) {
  SetMetricInternal(kPromotableNameHash, value);
  return *this;
}

const char WebApp_DailyInteraction::kUsedName[] = "Used";
const uint64_t WebApp_DailyInteraction::kUsedNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetUsed(int64_t value) {
  SetMetricInternal(kUsedNameHash, value);
  return *this;
}


const char WebRTC_AddressHarvesting::kEntryName[] = "WebRTC.AddressHarvesting";
const uint64_t WebRTC_AddressHarvesting::kEntryNameHash;

WebRTC_AddressHarvesting::WebRTC_AddressHarvesting(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebRTC_AddressHarvesting::WebRTC_AddressHarvesting(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebRTC_AddressHarvesting::~WebRTC_AddressHarvesting() = default;


const char WebRTC_AddressHarvesting::kUsagePatternName[] = "UsagePattern";
const uint64_t WebRTC_AddressHarvesting::kUsagePatternNameHash;

WebRTC_AddressHarvesting& WebRTC_AddressHarvesting::SetUsagePattern(int64_t value) {
  SetMetricInternal(kUsagePatternNameHash, value);
  return *this;
}


const char WebRTC_ComplexSdp::kEntryName[] = "WebRTC.ComplexSdp";
const uint64_t WebRTC_ComplexSdp::kEntryNameHash;

WebRTC_ComplexSdp::WebRTC_ComplexSdp(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebRTC_ComplexSdp::WebRTC_ComplexSdp(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

WebRTC_ComplexSdp::~WebRTC_ComplexSdp() = default;


const char WebRTC_ComplexSdp::kCategoryName[] = "Category";
const uint64_t WebRTC_ComplexSdp::kCategoryNameHash;

WebRTC_ComplexSdp& WebRTC_ComplexSdp::SetCategory(int64_t value) {
  SetMetricInternal(kCategoryNameHash, value);
  return *this;
}


const char XR_WebXR::kEntryName[] = "XR.WebXR";
const uint64_t XR_WebXR::kEntryNameHash;

XR_WebXR::XR_WebXR(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR::XR_WebXR(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR::~XR_WebXR() = default;


const char XR_WebXR::kDidGetXRInputSourcesName[] = "DidGetXRInputSources";
const uint64_t XR_WebXR::kDidGetXRInputSourcesNameHash;

XR_WebXR& XR_WebXR::SetDidGetXRInputSources(int64_t value) {
  SetMetricInternal(kDidGetXRInputSourcesNameHash, value);
  return *this;
}

const char XR_WebXR::kDidRequestAvailableDevicesName[] = "DidRequestAvailableDevices";
const uint64_t XR_WebXR::kDidRequestAvailableDevicesNameHash;

XR_WebXR& XR_WebXR::SetDidRequestAvailableDevices(int64_t value) {
  SetMetricInternal(kDidRequestAvailableDevicesNameHash, value);
  return *this;
}

const char XR_WebXR::kDidRequestPoseName[] = "DidRequestPose";
const uint64_t XR_WebXR::kDidRequestPoseNameHash;

XR_WebXR& XR_WebXR::SetDidRequestPose(int64_t value) {
  SetMetricInternal(kDidRequestPoseNameHash, value);
  return *this;
}

const char XR_WebXR::kDidRequestPresentationName[] = "DidRequestPresentation";
const uint64_t XR_WebXR::kDidRequestPresentationNameHash;

XR_WebXR& XR_WebXR::SetDidRequestPresentation(int64_t value) {
  SetMetricInternal(kDidRequestPresentationNameHash, value);
  return *this;
}

const char XR_WebXR::kDidUseNavigatorXRName[] = "DidUseNavigatorXR";
const uint64_t XR_WebXR::kDidUseNavigatorXRNameHash;

XR_WebXR& XR_WebXR::SetDidUseNavigatorXR(int64_t value) {
  SetMetricInternal(kDidUseNavigatorXRNameHash, value);
  return *this;
}

const char XR_WebXR::kReturnedDeviceName[] = "ReturnedDevice";
const uint64_t XR_WebXR::kReturnedDeviceNameHash;

XR_WebXR& XR_WebXR::SetReturnedDevice(int64_t value) {
  SetMetricInternal(kReturnedDeviceNameHash, value);
  return *this;
}

const char XR_WebXR::kReturnedPresentationCapableDeviceName[] = "ReturnedPresentationCapableDevice";
const uint64_t XR_WebXR::kReturnedPresentationCapableDeviceNameHash;

XR_WebXR& XR_WebXR::SetReturnedPresentationCapableDevice(int64_t value) {
  SetMetricInternal(kReturnedPresentationCapableDeviceNameHash, value);
  return *this;
}


const char XR_WebXR_Session::kEntryName[] = "XR.WebXR.Session";
const uint64_t XR_WebXR_Session::kEntryNameHash;

XR_WebXR_Session::XR_WebXR_Session(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR_Session::XR_WebXR_Session(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR_Session::~XR_WebXR_Session() = default;


const char XR_WebXR_Session::kDurationName[] = "Duration";
const uint64_t XR_WebXR_Session::kDurationNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetDuration(int64_t value) {
  SetMetricInternal(kDurationNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureRequest_BoundedFloorName[] = "FeatureRequest.BoundedFloor";
const uint64_t XR_WebXR_Session::kFeatureRequest_BoundedFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_BoundedFloor(int64_t value) {
  SetMetricInternal(kFeatureRequest_BoundedFloorNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureRequest_LocalName[] = "FeatureRequest.Local";
const uint64_t XR_WebXR_Session::kFeatureRequest_LocalNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Local(int64_t value) {
  SetMetricInternal(kFeatureRequest_LocalNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureRequest_LocalFloorName[] = "FeatureRequest.LocalFloor";
const uint64_t XR_WebXR_Session::kFeatureRequest_LocalFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_LocalFloor(int64_t value) {
  SetMetricInternal(kFeatureRequest_LocalFloorNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureRequest_UnboundedName[] = "FeatureRequest.Unbounded";
const uint64_t XR_WebXR_Session::kFeatureRequest_UnboundedNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Unbounded(int64_t value) {
  SetMetricInternal(kFeatureRequest_UnboundedNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureRequest_ViewerName[] = "FeatureRequest.Viewer";
const uint64_t XR_WebXR_Session::kFeatureRequest_ViewerNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Viewer(int64_t value) {
  SetMetricInternal(kFeatureRequest_ViewerNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureUse_BoundedFloorName[] = "FeatureUse.BoundedFloor";
const uint64_t XR_WebXR_Session::kFeatureUse_BoundedFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_BoundedFloor(int64_t value) {
  SetMetricInternal(kFeatureUse_BoundedFloorNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureUse_LocalName[] = "FeatureUse.Local";
const uint64_t XR_WebXR_Session::kFeatureUse_LocalNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Local(int64_t value) {
  SetMetricInternal(kFeatureUse_LocalNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureUse_LocalFloorName[] = "FeatureUse.LocalFloor";
const uint64_t XR_WebXR_Session::kFeatureUse_LocalFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_LocalFloor(int64_t value) {
  SetMetricInternal(kFeatureUse_LocalFloorNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureUse_UnboundedName[] = "FeatureUse.Unbounded";
const uint64_t XR_WebXR_Session::kFeatureUse_UnboundedNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Unbounded(int64_t value) {
  SetMetricInternal(kFeatureUse_UnboundedNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kFeatureUse_ViewerName[] = "FeatureUse.Viewer";
const uint64_t XR_WebXR_Session::kFeatureUse_ViewerNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Viewer(int64_t value) {
  SetMetricInternal(kFeatureUse_ViewerNameHash, value);
  return *this;
}

const char XR_WebXR_Session::kModeName[] = "Mode";
const uint64_t XR_WebXR_Session::kModeNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetMode(int64_t value) {
  SetMetricInternal(kModeNameHash, value);
  return *this;
}


const char XR_WebXR_SessionRequest::kEntryName[] = "XR.WebXR.SessionRequest";
const uint64_t XR_WebXR_SessionRequest::kEntryNameHash;

XR_WebXR_SessionRequest::XR_WebXR_SessionRequest(ukm::SourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR_SessionRequest::XR_WebXR_SessionRequest(base::UkmSourceId source_id) :
  ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash) {
}

XR_WebXR_SessionRequest::~XR_WebXR_SessionRequest() = default;


const char XR_WebXR_SessionRequest::kFeature_BoundedFloorName[] = "Feature.BoundedFloor";
const uint64_t XR_WebXR_SessionRequest::kFeature_BoundedFloorNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_BoundedFloor(int64_t value) {
  SetMetricInternal(kFeature_BoundedFloorNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kFeature_LocalName[] = "Feature.Local";
const uint64_t XR_WebXR_SessionRequest::kFeature_LocalNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Local(int64_t value) {
  SetMetricInternal(kFeature_LocalNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kFeature_LocalFloorName[] = "Feature.LocalFloor";
const uint64_t XR_WebXR_SessionRequest::kFeature_LocalFloorNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_LocalFloor(int64_t value) {
  SetMetricInternal(kFeature_LocalFloorNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kFeature_UnboundedName[] = "Feature.Unbounded";
const uint64_t XR_WebXR_SessionRequest::kFeature_UnboundedNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Unbounded(int64_t value) {
  SetMetricInternal(kFeature_UnboundedNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kFeature_ViewerName[] = "Feature.Viewer";
const uint64_t XR_WebXR_SessionRequest::kFeature_ViewerNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Viewer(int64_t value) {
  SetMetricInternal(kFeature_ViewerNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kModeName[] = "Mode";
const uint64_t XR_WebXR_SessionRequest::kModeNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetMode(int64_t value) {
  SetMetricInternal(kModeNameHash, value);
  return *this;
}

const char XR_WebXR_SessionRequest::kStatusName[] = "Status";
const uint64_t XR_WebXR_SessionRequest::kStatusNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetStatus(int64_t value) {
  SetMetricInternal(kStatusNameHash, value);
  return *this;
}



}  // namespace builders
}  // namespace ukm
