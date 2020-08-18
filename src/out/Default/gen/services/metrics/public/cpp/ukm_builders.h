
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#ifndef SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H
#define SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H

#include <cstdint>

#include "services/metrics/public/cpp/ukm_entry_builder_base.h"

namespace ukm {
namespace builders {


class AbusiveExperienceHeuristic final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AbusiveExperienceHeuristic(ukm::SourceId source_id);
  explicit AbusiveExperienceHeuristic(base::UkmSourceId source_id);
  ~AbusiveExperienceHeuristic() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4325886147604803651);


  static const char kDidTabUnderName[];
  static constexpr uint64_t kDidTabUnderNameHash = UINT64_C(1632877231929054164);
  AbusiveExperienceHeuristic& SetDidTabUnder(int64_t value);

  static const char kDidWindowOpenFromAdScriptName[];
  static constexpr uint64_t kDidWindowOpenFromAdScriptNameHash = UINT64_C(10997250432509201161);
  AbusiveExperienceHeuristic& SetDidWindowOpenFromAdScript(int64_t value);

  static const char kDidWindowOpenFromAdSubframeName[];
  static constexpr uint64_t kDidWindowOpenFromAdSubframeNameHash = UINT64_C(12530977728503802279);
  AbusiveExperienceHeuristic& SetDidWindowOpenFromAdSubframe(int64_t value);

};

class AbusiveExperienceHeuristic_JavaScriptDialog final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceId source_id);
  explicit AbusiveExperienceHeuristic_JavaScriptDialog(base::UkmSourceId source_id);
  ~AbusiveExperienceHeuristic_JavaScriptDialog() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2140536877907621174);


  static const char kDismissalCauseName[];
  static constexpr uint64_t kDismissalCauseNameHash = UINT64_C(253402870863803684);
  AbusiveExperienceHeuristic_JavaScriptDialog& SetDismissalCause(int64_t value);

};

class AbusiveExperienceHeuristic_TabUnder final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AbusiveExperienceHeuristic_TabUnder(ukm::SourceId source_id);
  explicit AbusiveExperienceHeuristic_TabUnder(base::UkmSourceId source_id);
  ~AbusiveExperienceHeuristic_TabUnder() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14027824048938333848);


  static const char kDidTabUnderName[];
  static constexpr uint64_t kDidTabUnderNameHash = UINT64_C(1632877231929054164);
  AbusiveExperienceHeuristic_TabUnder& SetDidTabUnder(int64_t value);

};

class AbusiveExperienceHeuristic_WindowOpen final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AbusiveExperienceHeuristic_WindowOpen(ukm::SourceId source_id);
  explicit AbusiveExperienceHeuristic_WindowOpen(base::UkmSourceId source_id);
  ~AbusiveExperienceHeuristic_WindowOpen() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9914911288513336680);


  static const char kFromAdScriptName[];
  static constexpr uint64_t kFromAdScriptNameHash = UINT64_C(15256588101172132306);
  AbusiveExperienceHeuristic_WindowOpen& SetFromAdScript(int64_t value);

  static const char kFromAdSubframeName[];
  static constexpr uint64_t kFromAdSubframeNameHash = UINT64_C(11195998530139223421);
  AbusiveExperienceHeuristic_WindowOpen& SetFromAdSubframe(int64_t value);

};

class Accessibility_Renderer final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Accessibility_Renderer(ukm::SourceId source_id);
  explicit Accessibility_Renderer(base::UkmSourceId source_id);
  ~Accessibility_Renderer() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11928696798041860883);


  static const char kCpuTime_SendPendingAccessibilityEventsName[];
  static constexpr uint64_t kCpuTime_SendPendingAccessibilityEventsNameHash = UINT64_C(10923305255192224661);
  Accessibility_Renderer& SetCpuTime_SendPendingAccessibilityEvents(int64_t value);

};

class AdFrameLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AdFrameLoad(ukm::SourceId source_id);
  explicit AdFrameLoad(base::UkmSourceId source_id);
  ~AdFrameLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9171478480016060997);


  static const char kCpuTime_PeakWindowedPercentName[];
  static constexpr uint64_t kCpuTime_PeakWindowedPercentNameHash = UINT64_C(10694907416106821570);
  AdFrameLoad& SetCpuTime_PeakWindowedPercent(int64_t value);

  static const char kCpuTime_PreActivationName[];
  static constexpr uint64_t kCpuTime_PreActivationNameHash = UINT64_C(5794315328615334038);
  AdFrameLoad& SetCpuTime_PreActivation(int64_t value);

  static const char kCpuTime_TotalName[];
  static constexpr uint64_t kCpuTime_TotalNameHash = UINT64_C(15350101520340136860);
  AdFrameLoad& SetCpuTime_Total(int64_t value);

  static const char kFrameDepthName[];
  static constexpr uint64_t kFrameDepthNameHash = UINT64_C(5259598389912370111);
  AdFrameLoad& SetFrameDepth(int64_t value);

  static const char kLoading_CacheBytes2Name[];
  static constexpr uint64_t kLoading_CacheBytes2NameHash = UINT64_C(2812659824544278329);
  AdFrameLoad& SetLoading_CacheBytes2(int64_t value);

  static const char kLoading_ImageBytesName[];
  static constexpr uint64_t kLoading_ImageBytesNameHash = UINT64_C(4267019114733925172);
  AdFrameLoad& SetLoading_ImageBytes(int64_t value);

  static const char kLoading_JavascriptBytesName[];
  static constexpr uint64_t kLoading_JavascriptBytesNameHash = UINT64_C(9762950567105973962);
  AdFrameLoad& SetLoading_JavascriptBytes(int64_t value);

  static const char kLoading_NetworkBytesName[];
  static constexpr uint64_t kLoading_NetworkBytesNameHash = UINT64_C(2909577699402783051);
  AdFrameLoad& SetLoading_NetworkBytes(int64_t value);

  static const char kLoading_NumResourcesName[];
  static constexpr uint64_t kLoading_NumResourcesNameHash = UINT64_C(13450060208467074309);
  AdFrameLoad& SetLoading_NumResources(int64_t value);

  static const char kLoading_VideoBytesName[];
  static constexpr uint64_t kLoading_VideoBytesNameHash = UINT64_C(15011407665794377843);
  AdFrameLoad& SetLoading_VideoBytes(int64_t value);

  static const char kStatus_CrossOriginName[];
  static constexpr uint64_t kStatus_CrossOriginNameHash = UINT64_C(4568069380683941241);
  AdFrameLoad& SetStatus_CrossOrigin(int64_t value);

  static const char kStatus_MediaName[];
  static constexpr uint64_t kStatus_MediaNameHash = UINT64_C(4546060596826334451);
  AdFrameLoad& SetStatus_Media(int64_t value);

  static const char kStatus_UserActivationName[];
  static constexpr uint64_t kStatus_UserActivationNameHash = UINT64_C(5097180316580530092);
  AdFrameLoad& SetStatus_UserActivation(int64_t value);

  static const char kTiming_FirstContentfulPaintName[];
  static constexpr uint64_t kTiming_FirstContentfulPaintNameHash = UINT64_C(17943578481506543757);
  AdFrameLoad& SetTiming_FirstContentfulPaint(int64_t value);

  static const char kTiming_InteractiveName[];
  static constexpr uint64_t kTiming_InteractiveNameHash = UINT64_C(15125362531657075325);
  AdFrameLoad& SetTiming_Interactive(int64_t value);

  static const char kTiming_PreActivationForegroundDurationName[];
  static constexpr uint64_t kTiming_PreActivationForegroundDurationNameHash = UINT64_C(2408123120387630908);
  AdFrameLoad& SetTiming_PreActivationForegroundDuration(int64_t value);

  static const char kVisibility_FrameHeightName[];
  static constexpr uint64_t kVisibility_FrameHeightNameHash = UINT64_C(7279397677831738677);
  AdFrameLoad& SetVisibility_FrameHeight(int64_t value);

  static const char kVisibility_FrameWidthName[];
  static constexpr uint64_t kVisibility_FrameWidthNameHash = UINT64_C(3041121436852256629);
  AdFrameLoad& SetVisibility_FrameWidth(int64_t value);

  static const char kVisibility_HiddenName[];
  static constexpr uint64_t kVisibility_HiddenNameHash = UINT64_C(10742343504399641560);
  AdFrameLoad& SetVisibility_Hidden(int64_t value);

};

class AdPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AdPageLoad(ukm::SourceId source_id);
  explicit AdPageLoad(base::UkmSourceId source_id);
  ~AdPageLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(897698866892786861);


  static const char kAdBytesName[];
  static constexpr uint64_t kAdBytesNameHash = UINT64_C(6659033870686188869);
  AdPageLoad& SetAdBytes(int64_t value);

  static const char kAdCpuTimeName[];
  static constexpr uint64_t kAdCpuTimeNameHash = UINT64_C(4851683766975122096);
  AdPageLoad& SetAdCpuTime(int64_t value);

  static const char kAdJavascriptBytesName[];
  static constexpr uint64_t kAdJavascriptBytesNameHash = UINT64_C(13996584362851862436);
  AdPageLoad& SetAdJavascriptBytes(int64_t value);

  static const char kAdVideoBytesName[];
  static constexpr uint64_t kAdVideoBytesNameHash = UINT64_C(4207294672781050458);
  AdPageLoad& SetAdVideoBytes(int64_t value);

  static const char kMainframeAdBytesName[];
  static constexpr uint64_t kMainframeAdBytesNameHash = UINT64_C(10142968506033351129);
  AdPageLoad& SetMainframeAdBytes(int64_t value);

  static const char kTotalBytesName[];
  static constexpr uint64_t kTotalBytesNameHash = UINT64_C(8087173487984213000);
  AdPageLoad& SetTotalBytes(int64_t value);

};

class AmpPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AmpPageLoad(ukm::SourceId source_id);
  explicit AmpPageLoad(base::UkmSourceId source_id);
  ~AmpPageLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15288827799554694614);


  static const char kMainFrameAmpPageLoadName[];
  static constexpr uint64_t kMainFrameAmpPageLoadNameHash = UINT64_C(5461195790241701747);
  AmpPageLoad& SetMainFrameAmpPageLoad(int64_t value);

  static const char kSubFrame_InteractiveTiming_FirstInputDelay4Name[];
  static constexpr uint64_t kSubFrame_InteractiveTiming_FirstInputDelay4NameHash = UINT64_C(4724951111204316736);
  AmpPageLoad& SetSubFrame_InteractiveTiming_FirstInputDelay4(int64_t value);

  static const char kSubFrame_LayoutInstability_CumulativeShiftScoreName[];
  static constexpr uint64_t kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash = UINT64_C(16418444555505335830);
  AmpPageLoad& SetSubFrame_LayoutInstability_CumulativeShiftScore(int64_t value);

  static const char kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[];
  static constexpr uint64_t kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash = UINT64_C(14270238291922659727);
  AmpPageLoad& SetSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value);

  static const char kSubFrame_MainFrameToSubFrameNavigationDeltaName[];
  static constexpr uint64_t kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash = UINT64_C(8980472913360711190);
  AmpPageLoad& SetSubFrame_MainFrameToSubFrameNavigationDelta(int64_t value);

  static const char kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName[];
  static constexpr uint64_t kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash = UINT64_C(638842222187756601);
  AmpPageLoad& SetSubFrame_PaintTiming_NavigationToFirstContentfulPaint(int64_t value);

  static const char kSubFrame_PaintTiming_NavigationToLargestContentfulPaintName[];
  static constexpr uint64_t kSubFrame_PaintTiming_NavigationToLargestContentfulPaintNameHash = UINT64_C(7926371826234720799);
  AmpPageLoad& SetSubFrame_PaintTiming_NavigationToLargestContentfulPaint(int64_t value);

  static const char kSubFrameAmpPageLoadName[];
  static constexpr uint64_t kSubFrameAmpPageLoadNameHash = UINT64_C(6483268505712723387);
  AmpPageLoad& SetSubFrameAmpPageLoad(int64_t value);

};

class AppListAppClickData final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AppListAppClickData(ukm::SourceId source_id);
  explicit AppListAppClickData(base::UkmSourceId source_id);
  ~AppListAppClickData() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4589718692267131532);


  static const char kAppLaunchIdName[];
  static constexpr uint64_t kAppLaunchIdNameHash = UINT64_C(18141239051505688203);
  AppListAppClickData& SetAppLaunchId(int64_t value);

  static const char kAppTypeName[];
  static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
  AppListAppClickData& SetAppType(int64_t value);

  static const char kClickRankName[];
  static constexpr uint64_t kClickRankNameHash = UINT64_C(2055104011801596037);
  AppListAppClickData& SetClickRank(int64_t value);

  static const char kClicksEachHour00Name[];
  static constexpr uint64_t kClicksEachHour00NameHash = UINT64_C(9852218943589438537);
  AppListAppClickData& SetClicksEachHour00(int64_t value);

  static const char kClicksEachHour01Name[];
  static constexpr uint64_t kClicksEachHour01NameHash = UINT64_C(4594220155145935772);
  AppListAppClickData& SetClicksEachHour01(int64_t value);

  static const char kClicksEachHour02Name[];
  static constexpr uint64_t kClicksEachHour02NameHash = UINT64_C(2979946241209199190);
  AppListAppClickData& SetClicksEachHour02(int64_t value);

  static const char kClicksEachHour03Name[];
  static constexpr uint64_t kClicksEachHour03NameHash = UINT64_C(2807870101964151999);
  AppListAppClickData& SetClicksEachHour03(int64_t value);

  static const char kClicksEachHour04Name[];
  static constexpr uint64_t kClicksEachHour04NameHash = UINT64_C(714499009068860843);
  AppListAppClickData& SetClicksEachHour04(int64_t value);

  static const char kClicksEachHour05Name[];
  static constexpr uint64_t kClicksEachHour05NameHash = UINT64_C(17713188968632146147);
  AppListAppClickData& SetClicksEachHour05(int64_t value);

  static const char kClicksEachHour06Name[];
  static constexpr uint64_t kClicksEachHour06NameHash = UINT64_C(1175107707626973313);
  AppListAppClickData& SetClicksEachHour06(int64_t value);

  static const char kClicksEachHour07Name[];
  static constexpr uint64_t kClicksEachHour07NameHash = UINT64_C(2271012638508829384);
  AppListAppClickData& SetClicksEachHour07(int64_t value);

  static const char kClicksEachHour08Name[];
  static constexpr uint64_t kClicksEachHour08NameHash = UINT64_C(1772457901586832457);
  AppListAppClickData& SetClicksEachHour08(int64_t value);

  static const char kClicksEachHour09Name[];
  static constexpr uint64_t kClicksEachHour09NameHash = UINT64_C(2851247351851385842);
  AppListAppClickData& SetClicksEachHour09(int64_t value);

  static const char kClicksEachHour10Name[];
  static constexpr uint64_t kClicksEachHour10NameHash = UINT64_C(1806588398743155997);
  AppListAppClickData& SetClicksEachHour10(int64_t value);

  static const char kClicksEachHour11Name[];
  static constexpr uint64_t kClicksEachHour11NameHash = UINT64_C(3131444643108020140);
  AppListAppClickData& SetClicksEachHour11(int64_t value);

  static const char kClicksEachHour12Name[];
  static constexpr uint64_t kClicksEachHour12NameHash = UINT64_C(2448014348189133351);
  AppListAppClickData& SetClicksEachHour12(int64_t value);

  static const char kClicksEachHour13Name[];
  static constexpr uint64_t kClicksEachHour13NameHash = UINT64_C(18250438715855980346);
  AppListAppClickData& SetClicksEachHour13(int64_t value);

  static const char kClicksEachHour14Name[];
  static constexpr uint64_t kClicksEachHour14NameHash = UINT64_C(17694991336934069562);
  AppListAppClickData& SetClicksEachHour14(int64_t value);

  static const char kClicksEachHour15Name[];
  static constexpr uint64_t kClicksEachHour15NameHash = UINT64_C(841563503357754805);
  AppListAppClickData& SetClicksEachHour15(int64_t value);

  static const char kClicksEachHour16Name[];
  static constexpr uint64_t kClicksEachHour16NameHash = UINT64_C(2083341464824283347);
  AppListAppClickData& SetClicksEachHour16(int64_t value);

  static const char kClicksEachHour17Name[];
  static constexpr uint64_t kClicksEachHour17NameHash = UINT64_C(16117389064877716783);
  AppListAppClickData& SetClicksEachHour17(int64_t value);

  static const char kClicksEachHour18Name[];
  static constexpr uint64_t kClicksEachHour18NameHash = UINT64_C(8357842770757548892);
  AppListAppClickData& SetClicksEachHour18(int64_t value);

  static const char kClicksEachHour19Name[];
  static constexpr uint64_t kClicksEachHour19NameHash = UINT64_C(9017652834579276383);
  AppListAppClickData& SetClicksEachHour19(int64_t value);

  static const char kClicksEachHour20Name[];
  static constexpr uint64_t kClicksEachHour20NameHash = UINT64_C(16309270750830060266);
  AppListAppClickData& SetClicksEachHour20(int64_t value);

  static const char kClicksEachHour21Name[];
  static constexpr uint64_t kClicksEachHour21NameHash = UINT64_C(8993148668647496674);
  AppListAppClickData& SetClicksEachHour21(int64_t value);

  static const char kClicksEachHour22Name[];
  static constexpr uint64_t kClicksEachHour22NameHash = UINT64_C(6608700521453268064);
  AppListAppClickData& SetClicksEachHour22(int64_t value);

  static const char kClicksEachHour23Name[];
  static constexpr uint64_t kClicksEachHour23NameHash = UINT64_C(10184622070282293203);
  AppListAppClickData& SetClicksEachHour23(int64_t value);

  static const char kClicksLast24HoursName[];
  static constexpr uint64_t kClicksLast24HoursNameHash = UINT64_C(8208362521514978200);
  AppListAppClickData& SetClicksLast24Hours(int64_t value);

  static const char kClicksLastHourName[];
  static constexpr uint64_t kClicksLastHourNameHash = UINT64_C(11587637074403422994);
  AppListAppClickData& SetClicksLastHour(int64_t value);

  static const char kLastLaunchedFromName[];
  static constexpr uint64_t kLastLaunchedFromNameHash = UINT64_C(17950909090926741200);
  AppListAppClickData& SetLastLaunchedFrom(int64_t value);

  static const char kMostRecentlyUsedIndexName[];
  static constexpr uint64_t kMostRecentlyUsedIndexNameHash = UINT64_C(4904327804870856216);
  AppListAppClickData& SetMostRecentlyUsedIndex(int64_t value);

  static const char kSequenceNumberName[];
  static constexpr uint64_t kSequenceNumberNameHash = UINT64_C(3161886034278201905);
  AppListAppClickData& SetSequenceNumber(int64_t value);

  static const char kTimeSinceLastClickName[];
  static constexpr uint64_t kTimeSinceLastClickNameHash = UINT64_C(6482216598721160744);
  AppListAppClickData& SetTimeSinceLastClick(int64_t value);

  static const char kTotalClicksName[];
  static constexpr uint64_t kTotalClicksNameHash = UINT64_C(14899889891285787674);
  AppListAppClickData& SetTotalClicks(int64_t value);

};

class AppListAppLaunch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AppListAppLaunch(ukm::SourceId source_id);
  explicit AppListAppLaunch(base::UkmSourceId source_id);
  ~AppListAppLaunch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16635456347627451827);


  static const char kAllClicksLast24HoursName[];
  static constexpr uint64_t kAllClicksLast24HoursNameHash = UINT64_C(4575029519393656215);
  AppListAppLaunch& SetAllClicksLast24Hours(int64_t value);

  static const char kAllClicksLastHourName[];
  static constexpr uint64_t kAllClicksLastHourNameHash = UINT64_C(14694624669615609981);
  AppListAppLaunch& SetAllClicksLastHour(int64_t value);

  static const char kAppTypeName[];
  static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
  AppListAppLaunch& SetAppType(int64_t value);

  static const char kClickMethodName[];
  static constexpr uint64_t kClickMethodNameHash = UINT64_C(6788393749258903020);
  AppListAppLaunch& SetClickMethod(int64_t value);

  static const char kDayOfWeekName[];
  static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
  AppListAppLaunch& SetDayOfWeek(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  AppListAppLaunch& SetDeviceMode(int64_t value);

  static const char kDeviceTypeName[];
  static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
  AppListAppLaunch& SetDeviceType(int64_t value);

  static const char kHourOfDayName[];
  static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
  AppListAppLaunch& SetHourOfDay(int64_t value);

  static const char kLaunchedFromName[];
  static constexpr uint64_t kLaunchedFromNameHash = UINT64_C(6515313514467325646);
  AppListAppLaunch& SetLaunchedFrom(int64_t value);

  static const char kPositionIndexName[];
  static constexpr uint64_t kPositionIndexNameHash = UINT64_C(11513691020323067369);
  AppListAppLaunch& SetPositionIndex(int64_t value);

  static const char kTotalHoursName[];
  static constexpr uint64_t kTotalHoursNameHash = UINT64_C(14771740324071435168);
  AppListAppLaunch& SetTotalHours(int64_t value);

};

class AppListNonAppImpression final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit AppListNonAppImpression(ukm::SourceId source_id);
  explicit AppListNonAppImpression(base::UkmSourceId source_id);
  ~AppListNonAppImpression() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9743727136758947685);


  static const char kCategoryName[];
  static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
  AppListNonAppImpression& SetCategory(int64_t value);

  static const char kDayOfWeekName[];
  static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
  AppListNonAppImpression& SetDayOfWeek(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  AppListNonAppImpression& SetDeviceMode(int64_t value);

  static const char kEventIdName[];
  static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
  AppListNonAppImpression& SetEventId(int64_t value);

  static const char kFileExtensionName[];
  static constexpr uint64_t kFileExtensionNameHash = UINT64_C(4237373813144714625);
  AppListNonAppImpression& SetFileExtension(int64_t value);

  static const char kHourOfDayName[];
  static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
  AppListNonAppImpression& SetHourOfDay(int64_t value);

  static const char kIsLaunchedName[];
  static constexpr uint64_t kIsLaunchedNameHash = UINT64_C(11373196583043827840);
  AppListNonAppImpression& SetIsLaunched(int64_t value);

  static const char kLaunchesAtHour00Name[];
  static constexpr uint64_t kLaunchesAtHour00NameHash = UINT64_C(9994582707780149401);
  AppListNonAppImpression& SetLaunchesAtHour00(int64_t value);

  static const char kLaunchesAtHour01Name[];
  static constexpr uint64_t kLaunchesAtHour01NameHash = UINT64_C(15581676297665955751);
  AppListNonAppImpression& SetLaunchesAtHour01(int64_t value);

  static const char kLaunchesAtHour02Name[];
  static constexpr uint64_t kLaunchesAtHour02NameHash = UINT64_C(3490931745208659263);
  AppListNonAppImpression& SetLaunchesAtHour02(int64_t value);

  static const char kLaunchesAtHour03Name[];
  static constexpr uint64_t kLaunchesAtHour03NameHash = UINT64_C(6699433121366187438);
  AppListNonAppImpression& SetLaunchesAtHour03(int64_t value);

  static const char kLaunchesAtHour04Name[];
  static constexpr uint64_t kLaunchesAtHour04NameHash = UINT64_C(6196426709480210296);
  AppListNonAppImpression& SetLaunchesAtHour04(int64_t value);

  static const char kLaunchesAtHour05Name[];
  static constexpr uint64_t kLaunchesAtHour05NameHash = UINT64_C(2830185526157851333);
  AppListNonAppImpression& SetLaunchesAtHour05(int64_t value);

  static const char kLaunchesAtHour06Name[];
  static constexpr uint64_t kLaunchesAtHour06NameHash = UINT64_C(14049502631921211171);
  AppListNonAppImpression& SetLaunchesAtHour06(int64_t value);

  static const char kLaunchesAtHour07Name[];
  static constexpr uint64_t kLaunchesAtHour07NameHash = UINT64_C(875047434489613290);
  AppListNonAppImpression& SetLaunchesAtHour07(int64_t value);

  static const char kLaunchesAtHour08Name[];
  static constexpr uint64_t kLaunchesAtHour08NameHash = UINT64_C(10240916556316942564);
  AppListNonAppImpression& SetLaunchesAtHour08(int64_t value);

  static const char kLaunchesAtHour09Name[];
  static constexpr uint64_t kLaunchesAtHour09NameHash = UINT64_C(13783684429099029759);
  AppListNonAppImpression& SetLaunchesAtHour09(int64_t value);

  static const char kLaunchesAtHour10Name[];
  static constexpr uint64_t kLaunchesAtHour10NameHash = UINT64_C(15867810781858314625);
  AppListNonAppImpression& SetLaunchesAtHour10(int64_t value);

  static const char kLaunchesAtHour11Name[];
  static constexpr uint64_t kLaunchesAtHour11NameHash = UINT64_C(11243311795376025564);
  AppListNonAppImpression& SetLaunchesAtHour11(int64_t value);

  static const char kLaunchesAtHour12Name[];
  static constexpr uint64_t kLaunchesAtHour12NameHash = UINT64_C(12436405938045371161);
  AppListNonAppImpression& SetLaunchesAtHour12(int64_t value);

  static const char kLaunchesAtHour13Name[];
  static constexpr uint64_t kLaunchesAtHour13NameHash = UINT64_C(5283536503016304216);
  AppListNonAppImpression& SetLaunchesAtHour13(int64_t value);

  static const char kLaunchesAtHour14Name[];
  static constexpr uint64_t kLaunchesAtHour14NameHash = UINT64_C(14644009661152931662);
  AppListNonAppImpression& SetLaunchesAtHour14(int64_t value);

  static const char kLaunchesAtHour15Name[];
  static constexpr uint64_t kLaunchesAtHour15NameHash = UINT64_C(6247933159874418974);
  AppListNonAppImpression& SetLaunchesAtHour15(int64_t value);

  static const char kLaunchesAtHour16Name[];
  static constexpr uint64_t kLaunchesAtHour16NameHash = UINT64_C(8056817024961911720);
  AppListNonAppImpression& SetLaunchesAtHour16(int64_t value);

  static const char kLaunchesAtHour17Name[];
  static constexpr uint64_t kLaunchesAtHour17NameHash = UINT64_C(5853027825260103916);
  AppListNonAppImpression& SetLaunchesAtHour17(int64_t value);

  static const char kLaunchesAtHour18Name[];
  static constexpr uint64_t kLaunchesAtHour18NameHash = UINT64_C(7933783632498859686);
  AppListNonAppImpression& SetLaunchesAtHour18(int64_t value);

  static const char kLaunchesAtHour19Name[];
  static constexpr uint64_t kLaunchesAtHour19NameHash = UINT64_C(8074489491104251777);
  AppListNonAppImpression& SetLaunchesAtHour19(int64_t value);

  static const char kLaunchesAtHour20Name[];
  static constexpr uint64_t kLaunchesAtHour20NameHash = UINT64_C(3013399864116845181);
  AppListNonAppImpression& SetLaunchesAtHour20(int64_t value);

  static const char kLaunchesAtHour21Name[];
  static constexpr uint64_t kLaunchesAtHour21NameHash = UINT64_C(2781987889633216719);
  AppListNonAppImpression& SetLaunchesAtHour21(int64_t value);

  static const char kLaunchesAtHour22Name[];
  static constexpr uint64_t kLaunchesAtHour22NameHash = UINT64_C(10933629332725470808);
  AppListNonAppImpression& SetLaunchesAtHour22(int64_t value);

  static const char kLaunchesAtHour23Name[];
  static constexpr uint64_t kLaunchesAtHour23NameHash = UINT64_C(3461810265400542843);
  AppListNonAppImpression& SetLaunchesAtHour23(int64_t value);

  static const char kLaunchesThisSessionName[];
  static constexpr uint64_t kLaunchesThisSessionNameHash = UINT64_C(11701974752902462481);
  AppListNonAppImpression& SetLaunchesThisSession(int64_t value);

  static const char kPositionName[];
  static constexpr uint64_t kPositionNameHash = UINT64_C(5977931179408079967);
  AppListNonAppImpression& SetPosition(int64_t value);

  static const char kQueryLengthName[];
  static constexpr uint64_t kQueryLengthNameHash = UINT64_C(10982924610849676673);
  AppListNonAppImpression& SetQueryLength(int64_t value);

  static const char kRelevanceScoreName[];
  static constexpr uint64_t kRelevanceScoreNameHash = UINT64_C(14800889372098299506);
  AppListNonAppImpression& SetRelevanceScore(int64_t value);

  static const char kTimeOfLastLaunchName[];
  static constexpr uint64_t kTimeOfLastLaunchNameHash = UINT64_C(10891086330304605904);
  AppListNonAppImpression& SetTimeOfLastLaunch(int64_t value);

  static const char kTimeSinceLastLaunchName[];
  static constexpr uint64_t kTimeSinceLastLaunchNameHash = UINT64_C(7857562444138501968);
  AppListNonAppImpression& SetTimeSinceLastLaunch(int64_t value);

};

class Autofill_CardUploadDecision final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_CardUploadDecision(ukm::SourceId source_id);
  explicit Autofill_CardUploadDecision(base::UkmSourceId source_id);
  ~Autofill_CardUploadDecision() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3597047501124112026);


  static const char kUploadDecisionName[];
  static constexpr uint64_t kUploadDecisionNameHash = UINT64_C(1530202151366371243);
  Autofill_CardUploadDecision& SetUploadDecision(int64_t value);

};

class Autofill_DeveloperEngagement final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_DeveloperEngagement(ukm::SourceId source_id);
  explicit Autofill_DeveloperEngagement(base::UkmSourceId source_id);
  ~Autofill_DeveloperEngagement() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14550063303370974566);


  static const char kDeveloperEngagementName[];
  static constexpr uint64_t kDeveloperEngagementNameHash = UINT64_C(15538334115650657597);
  Autofill_DeveloperEngagement& SetDeveloperEngagement(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_DeveloperEngagement& SetFormSignature(int64_t value);

  static const char kFormTypesName[];
  static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
  Autofill_DeveloperEngagement& SetFormTypes(int64_t value);

  static const char kIsForCreditCardName[];
  static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
  Autofill_DeveloperEngagement& SetIsForCreditCard(int64_t value);

};

class Autofill_FieldFillStatus final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_FieldFillStatus(ukm::SourceId source_id);
  explicit Autofill_FieldFillStatus(base::UkmSourceId source_id);
  ~Autofill_FieldFillStatus() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11456448948041474991);


  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_FieldFillStatus& SetFieldSignature(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_FieldFillStatus& SetFormSignature(int64_t value);

  static const char kIsAutofilledName[];
  static constexpr uint64_t kIsAutofilledNameHash = UINT64_C(17551275327964504767);
  Autofill_FieldFillStatus& SetIsAutofilled(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_FieldFillStatus& SetMillisecondsSinceFormParsed(int64_t value);

  static const char kPredictionSourceName[];
  static constexpr uint64_t kPredictionSourceNameHash = UINT64_C(5017294346205954242);
  Autofill_FieldFillStatus& SetPredictionSource(int64_t value);

  static const char kValidationEventName[];
  static constexpr uint64_t kValidationEventNameHash = UINT64_C(17361557898566789372);
  Autofill_FieldFillStatus& SetValidationEvent(int64_t value);

  static const char kWasPreviouslyAutofilledName[];
  static constexpr uint64_t kWasPreviouslyAutofilledNameHash = UINT64_C(1646712375187153208);
  Autofill_FieldFillStatus& SetWasPreviouslyAutofilled(int64_t value);

};

class Autofill_FieldTypeValidation final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_FieldTypeValidation(ukm::SourceId source_id);
  explicit Autofill_FieldTypeValidation(base::UkmSourceId source_id);
  ~Autofill_FieldTypeValidation() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(1290380890049589579);


  static const char kActualTypeName[];
  static constexpr uint64_t kActualTypeNameHash = UINT64_C(4245305632546756744);
  Autofill_FieldTypeValidation& SetActualType(int64_t value);

  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_FieldTypeValidation& SetFieldSignature(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_FieldTypeValidation& SetFormSignature(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_FieldTypeValidation& SetMillisecondsSinceFormParsed(int64_t value);

  static const char kPredictedTypeName[];
  static constexpr uint64_t kPredictedTypeNameHash = UINT64_C(13118965333595910063);
  Autofill_FieldTypeValidation& SetPredictedType(int64_t value);

  static const char kPredictionSourceName[];
  static constexpr uint64_t kPredictionSourceNameHash = UINT64_C(5017294346205954242);
  Autofill_FieldTypeValidation& SetPredictionSource(int64_t value);

  static const char kValidationEventName[];
  static constexpr uint64_t kValidationEventNameHash = UINT64_C(17361557898566789372);
  Autofill_FieldTypeValidation& SetValidationEvent(int64_t value);

};

class Autofill_FormEvent final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_FormEvent(ukm::SourceId source_id);
  explicit Autofill_FormEvent(base::UkmSourceId source_id);
  ~Autofill_FormEvent() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16631655786524489525);


  static const char kAutofillFormEventName[];
  static constexpr uint64_t kAutofillFormEventNameHash = UINT64_C(101161368576121811);
  Autofill_FormEvent& SetAutofillFormEvent(int64_t value);

  static const char kFormTypesName[];
  static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
  Autofill_FormEvent& SetFormTypes(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_FormEvent& SetMillisecondsSinceFormParsed(int64_t value);

};

class Autofill_FormSubmitted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_FormSubmitted(ukm::SourceId source_id);
  explicit Autofill_FormSubmitted(base::UkmSourceId source_id);
  ~Autofill_FormSubmitted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12791011001011085363);


  static const char kAutofillFormSubmittedStateName[];
  static constexpr uint64_t kAutofillFormSubmittedStateNameHash = UINT64_C(4964829566871574464);
  Autofill_FormSubmitted& SetAutofillFormSubmittedState(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_FormSubmitted& SetFormSignature(int64_t value);

  static const char kFormTypesName[];
  static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
  Autofill_FormSubmitted& SetFormTypes(int64_t value);

  static const char kHasUpiVpaFieldName[];
  static constexpr uint64_t kHasUpiVpaFieldNameHash = UINT64_C(3630243921977557291);
  Autofill_FormSubmitted& SetHasUpiVpaField(int64_t value);

  static const char kIsForCreditCardName[];
  static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
  Autofill_FormSubmitted& SetIsForCreditCard(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_FormSubmitted& SetMillisecondsSinceFormParsed(int64_t value);

};

class Autofill_HiddenRepresentationalFieldSkipDecision final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceId source_id);
  explicit Autofill_HiddenRepresentationalFieldSkipDecision(base::UkmSourceId source_id);
  ~Autofill_HiddenRepresentationalFieldSkipDecision() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14481214823422924028);


  static const char kFieldOverallTypeName[];
  static constexpr uint64_t kFieldOverallTypeNameHash = UINT64_C(5024560379185631865);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldOverallType(int64_t value);

  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldSignature(int64_t value);

  static const char kFieldTypeGroupName[];
  static constexpr uint64_t kFieldTypeGroupNameHash = UINT64_C(4771816394504495494);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldTypeGroup(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetFormSignature(int64_t value);

  static const char kHeuristicTypeName[];
  static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetHeuristicType(int64_t value);

  static const char kHtmlFieldModeName[];
  static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetHtmlFieldMode(int64_t value);

  static const char kHtmlFieldTypeName[];
  static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetHtmlFieldType(int64_t value);

  static const char kIsSkippedName[];
  static constexpr uint64_t kIsSkippedNameHash = UINT64_C(13869837774034534594);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetIsSkipped(int64_t value);

  static const char kServerTypeName[];
  static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
  Autofill_HiddenRepresentationalFieldSkipDecision& SetServerType(int64_t value);

};

class Autofill_InteractedWithForm final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_InteractedWithForm(ukm::SourceId source_id);
  explicit Autofill_InteractedWithForm(base::UkmSourceId source_id);
  ~Autofill_InteractedWithForm() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12943113565528625214);


  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_InteractedWithForm& SetFormSignature(int64_t value);

  static const char kFormTypesName[];
  static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
  Autofill_InteractedWithForm& SetFormTypes(int64_t value);

  static const char kIsForCreditCardName[];
  static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
  Autofill_InteractedWithForm& SetIsForCreditCard(int64_t value);

  static const char kLocalRecordTypeCountName[];
  static constexpr uint64_t kLocalRecordTypeCountNameHash = UINT64_C(4967504613046448052);
  Autofill_InteractedWithForm& SetLocalRecordTypeCount(int64_t value);

  static const char kServerRecordTypeCountName[];
  static constexpr uint64_t kServerRecordTypeCountNameHash = UINT64_C(7268279397149312763);
  Autofill_InteractedWithForm& SetServerRecordTypeCount(int64_t value);

};

class Autofill_RepeatedServerTypePredictionRationalized final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_RepeatedServerTypePredictionRationalized(ukm::SourceId source_id);
  explicit Autofill_RepeatedServerTypePredictionRationalized(base::UkmSourceId source_id);
  ~Autofill_RepeatedServerTypePredictionRationalized() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10421158139944624501);


  static const char kFieldNewOverallTypeName[];
  static constexpr uint64_t kFieldNewOverallTypeNameHash = UINT64_C(17662835963219696641);
  Autofill_RepeatedServerTypePredictionRationalized& SetFieldNewOverallType(int64_t value);

  static const char kFieldOldOverallTypeName[];
  static constexpr uint64_t kFieldOldOverallTypeNameHash = UINT64_C(16429141926058996845);
  Autofill_RepeatedServerTypePredictionRationalized& SetFieldOldOverallType(int64_t value);

  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_RepeatedServerTypePredictionRationalized& SetFieldSignature(int64_t value);

  static const char kFieldTypeGroupName[];
  static constexpr uint64_t kFieldTypeGroupNameHash = UINT64_C(4771816394504495494);
  Autofill_RepeatedServerTypePredictionRationalized& SetFieldTypeGroup(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_RepeatedServerTypePredictionRationalized& SetFormSignature(int64_t value);

  static const char kHeuristicTypeName[];
  static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
  Autofill_RepeatedServerTypePredictionRationalized& SetHeuristicType(int64_t value);

  static const char kHtmlFieldModeName[];
  static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
  Autofill_RepeatedServerTypePredictionRationalized& SetHtmlFieldMode(int64_t value);

  static const char kHtmlFieldTypeName[];
  static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
  Autofill_RepeatedServerTypePredictionRationalized& SetHtmlFieldType(int64_t value);

  static const char kServerTypeName[];
  static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
  Autofill_RepeatedServerTypePredictionRationalized& SetServerType(int64_t value);

};

class Autofill_SuggestionFilled final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_SuggestionFilled(ukm::SourceId source_id);
  explicit Autofill_SuggestionFilled(base::UkmSourceId source_id);
  ~Autofill_SuggestionFilled() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17703268464688884622);


  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_SuggestionFilled& SetFieldSignature(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_SuggestionFilled& SetFormSignature(int64_t value);

  static const char kIsForCreditCardName[];
  static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
  Autofill_SuggestionFilled& SetIsForCreditCard(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_SuggestionFilled& SetMillisecondsSinceFormParsed(int64_t value);

  static const char kRecordTypeName[];
  static constexpr uint64_t kRecordTypeNameHash = UINT64_C(2556852903161176255);
  Autofill_SuggestionFilled& SetRecordType(int64_t value);

};

class Autofill_SuggestionsShown final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_SuggestionsShown(ukm::SourceId source_id);
  explicit Autofill_SuggestionsShown(base::UkmSourceId source_id);
  ~Autofill_SuggestionsShown() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7579660929739851736);


  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_SuggestionsShown& SetFieldSignature(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_SuggestionsShown& SetFormSignature(int64_t value);

  static const char kHeuristicTypeName[];
  static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
  Autofill_SuggestionsShown& SetHeuristicType(int64_t value);

  static const char kHtmlFieldTypeName[];
  static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
  Autofill_SuggestionsShown& SetHtmlFieldType(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_SuggestionsShown& SetMillisecondsSinceFormParsed(int64_t value);

  static const char kServerTypeName[];
  static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
  Autofill_SuggestionsShown& SetServerType(int64_t value);

};

class Autofill_TextFieldDidChange final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Autofill_TextFieldDidChange(ukm::SourceId source_id);
  explicit Autofill_TextFieldDidChange(base::UkmSourceId source_id);
  ~Autofill_TextFieldDidChange() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8376184896509210883);


  static const char kFieldSignatureName[];
  static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
  Autofill_TextFieldDidChange& SetFieldSignature(int64_t value);

  static const char kFieldTypeGroupName[];
  static constexpr uint64_t kFieldTypeGroupNameHash = UINT64_C(4771816394504495494);
  Autofill_TextFieldDidChange& SetFieldTypeGroup(int64_t value);

  static const char kFormSignatureName[];
  static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
  Autofill_TextFieldDidChange& SetFormSignature(int64_t value);

  static const char kHeuristicTypeName[];
  static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
  Autofill_TextFieldDidChange& SetHeuristicType(int64_t value);

  static const char kHtmlFieldModeName[];
  static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
  Autofill_TextFieldDidChange& SetHtmlFieldMode(int64_t value);

  static const char kHtmlFieldTypeName[];
  static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
  Autofill_TextFieldDidChange& SetHtmlFieldType(int64_t value);

  static const char kIsAutofilledName[];
  static constexpr uint64_t kIsAutofilledNameHash = UINT64_C(17551275327964504767);
  Autofill_TextFieldDidChange& SetIsAutofilled(int64_t value);

  static const char kIsEmptyName[];
  static constexpr uint64_t kIsEmptyNameHash = UINT64_C(13334288173870607265);
  Autofill_TextFieldDidChange& SetIsEmpty(int64_t value);

  static const char kMillisecondsSinceFormParsedName[];
  static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
  Autofill_TextFieldDidChange& SetMillisecondsSinceFormParsed(int64_t value);

  static const char kServerTypeName[];
  static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
  Autofill_TextFieldDidChange& SetServerType(int64_t value);

};

class BackgroundFetch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit BackgroundFetch(ukm::SourceId source_id);
  explicit BackgroundFetch(base::UkmSourceId source_id);
  ~BackgroundFetch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15260645490069405494);


  static const char kDeniedDueToPermissionsName[];
  static constexpr uint64_t kDeniedDueToPermissionsNameHash = UINT64_C(2758060228952433941);
  BackgroundFetch& SetDeniedDueToPermissions(int64_t value);

  static const char kDownloadTotalName[];
  static constexpr uint64_t kDownloadTotalNameHash = UINT64_C(8410270676684853040);
  BackgroundFetch& SetDownloadTotal(int64_t value);

  static const char kHasTitleName[];
  static constexpr uint64_t kHasTitleNameHash = UINT64_C(16464620929402588538);
  BackgroundFetch& SetHasTitle(int64_t value);

  static const char kNumIconsName[];
  static constexpr uint64_t kNumIconsNameHash = UINT64_C(12708022996225087379);
  BackgroundFetch& SetNumIcons(int64_t value);

  static const char kNumRequestsInFetchName[];
  static constexpr uint64_t kNumRequestsInFetchNameHash = UINT64_C(15496480607003620043);
  BackgroundFetch& SetNumRequestsInFetch(int64_t value);

  static const char kRatioOfIdealToChosenIconSizeName[];
  static constexpr uint64_t kRatioOfIdealToChosenIconSizeNameHash = UINT64_C(18158828977194098243);
  BackgroundFetch& SetRatioOfIdealToChosenIconSize(int64_t value);

};

class BackgroundFetchDeletingRegistration final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit BackgroundFetchDeletingRegistration(ukm::SourceId source_id);
  explicit BackgroundFetchDeletingRegistration(base::UkmSourceId source_id);
  ~BackgroundFetchDeletingRegistration() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2765600174500981245);


  static const char kUserInitiatedAbortName[];
  static constexpr uint64_t kUserInitiatedAbortNameHash = UINT64_C(2365076081250918859);
  BackgroundFetchDeletingRegistration& SetUserInitiatedAbort(int64_t value);

};

class BackgroundSyncCompleted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit BackgroundSyncCompleted(ukm::SourceId source_id);
  explicit BackgroundSyncCompleted(base::UkmSourceId source_id);
  ~BackgroundSyncCompleted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7109245137155486527);


  static const char kMaxAttemptsName[];
  static constexpr uint64_t kMaxAttemptsNameHash = UINT64_C(13811216186026220346);
  BackgroundSyncCompleted& SetMaxAttempts(int64_t value);

  static const char kNumAttemptsName[];
  static constexpr uint64_t kNumAttemptsNameHash = UINT64_C(537979731801272247);
  BackgroundSyncCompleted& SetNumAttempts(int64_t value);

  static const char kStatusName[];
  static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
  BackgroundSyncCompleted& SetStatus(int64_t value);

};

class BackgroundSyncRegistered final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit BackgroundSyncRegistered(ukm::SourceId source_id);
  explicit BackgroundSyncRegistered(base::UkmSourceId source_id);
  ~BackgroundSyncRegistered() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3511425855963568724);


  static const char kCanFireName[];
  static constexpr uint64_t kCanFireNameHash = UINT64_C(14458670990807174531);
  BackgroundSyncRegistered& SetCanFire(int64_t value);

  static const char kIsReregisteredName[];
  static constexpr uint64_t kIsReregisteredNameHash = UINT64_C(10082741689941820461);
  BackgroundSyncRegistered& SetIsReregistered(int64_t value);

};

class Badging final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Badging(ukm::SourceId source_id);
  explicit Badging(base::UkmSourceId source_id);
  ~Badging() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12678664205992465342);


  static const char kUpdateAppBadgeName[];
  static constexpr uint64_t kUpdateAppBadgeNameHash = UINT64_C(5657178876164813495);
  Badging& SetUpdateAppBadge(int64_t value);

};

class Blink_FindInPage final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_FindInPage(ukm::SourceId source_id);
  explicit Blink_FindInPage(base::UkmSourceId source_id);
  ~Blink_FindInPage() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14503116569381719800);


  static const char kDidHaveRenderSubtreeMatchName[];
  static constexpr uint64_t kDidHaveRenderSubtreeMatchNameHash = UINT64_C(10437331684651176215);
  Blink_FindInPage& SetDidHaveRenderSubtreeMatch(int64_t value);

  static const char kDidSearchName[];
  static constexpr uint64_t kDidSearchNameHash = UINT64_C(11237017958028068734);
  Blink_FindInPage& SetDidSearch(int64_t value);

};

class Blink_HTMLParsing final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_HTMLParsing(ukm::SourceId source_id);
  explicit Blink_HTMLParsing(base::UkmSourceId source_id);
  ~Blink_HTMLParsing() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11969773594143228030);


  static const char kChunkCountName[];
  static constexpr uint64_t kChunkCountNameHash = UINT64_C(12117884680134555924);
  Blink_HTMLParsing& SetChunkCount(int64_t value);

  static const char kParsingTimeMaxName[];
  static constexpr uint64_t kParsingTimeMaxNameHash = UINT64_C(17100612038745900895);
  Blink_HTMLParsing& SetParsingTimeMax(int64_t value);

  static const char kParsingTimeMinName[];
  static constexpr uint64_t kParsingTimeMinNameHash = UINT64_C(1069166688745848743);
  Blink_HTMLParsing& SetParsingTimeMin(int64_t value);

  static const char kParsingTimeTotalName[];
  static constexpr uint64_t kParsingTimeTotalNameHash = UINT64_C(4428025718068016638);
  Blink_HTMLParsing& SetParsingTimeTotal(int64_t value);

  static const char kTokensParsedAverageName[];
  static constexpr uint64_t kTokensParsedAverageNameHash = UINT64_C(9991938757455203086);
  Blink_HTMLParsing& SetTokensParsedAverage(int64_t value);

  static const char kTokensParsedMaxName[];
  static constexpr uint64_t kTokensParsedMaxNameHash = UINT64_C(5038652062281821354);
  Blink_HTMLParsing& SetTokensParsedMax(int64_t value);

  static const char kTokensParsedMinName[];
  static constexpr uint64_t kTokensParsedMinNameHash = UINT64_C(17792655194760260705);
  Blink_HTMLParsing& SetTokensParsedMin(int64_t value);

  static const char kYieldedTimeAverageName[];
  static constexpr uint64_t kYieldedTimeAverageNameHash = UINT64_C(13724762123779077336);
  Blink_HTMLParsing& SetYieldedTimeAverage(int64_t value);

  static const char kYieldedTimeMaxName[];
  static constexpr uint64_t kYieldedTimeMaxNameHash = UINT64_C(10007745934025216351);
  Blink_HTMLParsing& SetYieldedTimeMax(int64_t value);

  static const char kYieldedTimeMinName[];
  static constexpr uint64_t kYieldedTimeMinNameHash = UINT64_C(14554832440690350773);
  Blink_HTMLParsing& SetYieldedTimeMin(int64_t value);

};

class Blink_PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_PageLoad(ukm::SourceId source_id);
  explicit Blink_PageLoad(base::UkmSourceId source_id);
  ~Blink_PageLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11315426756825559974);


  static const char kAnimateName[];
  static constexpr uint64_t kAnimateNameHash = UINT64_C(404752839576342973);
  Blink_PageLoad& SetAnimate(int64_t value);

  static const char kCompositingName[];
  static constexpr uint64_t kCompositingNameHash = UINT64_C(11996896506970689590);
  Blink_PageLoad& SetCompositing(int64_t value);

  static const char kCompositingCommitName[];
  static constexpr uint64_t kCompositingCommitNameHash = UINT64_C(15809321536415505310);
  Blink_PageLoad& SetCompositingCommit(int64_t value);

  static const char kForcedStyleAndLayoutName[];
  static constexpr uint64_t kForcedStyleAndLayoutNameHash = UINT64_C(15609086396948909960);
  Blink_PageLoad& SetForcedStyleAndLayout(int64_t value);

  static const char kHandleInputEventsName[];
  static constexpr uint64_t kHandleInputEventsNameHash = UINT64_C(8113352720551083585);
  Blink_PageLoad& SetHandleInputEvents(int64_t value);

  static const char kHitTestDocumentUpdateName[];
  static constexpr uint64_t kHitTestDocumentUpdateNameHash = UINT64_C(11724920415365121476);
  Blink_PageLoad& SetHitTestDocumentUpdate(int64_t value);

  static const char kImplCompositorCommitName[];
  static constexpr uint64_t kImplCompositorCommitNameHash = UINT64_C(13634114799754628945);
  Blink_PageLoad& SetImplCompositorCommit(int64_t value);

  static const char kIntersectionObservationName[];
  static constexpr uint64_t kIntersectionObservationNameHash = UINT64_C(15458618821019023377);
  Blink_PageLoad& SetIntersectionObservation(int64_t value);

  static const char kLayoutName[];
  static constexpr uint64_t kLayoutNameHash = UINT64_C(16994824421489949816);
  Blink_PageLoad& SetLayout(int64_t value);

  static const char kMainFrameName[];
  static constexpr uint64_t kMainFrameNameHash = UINT64_C(4089985743552002450);
  Blink_PageLoad& SetMainFrame(int64_t value);

  static const char kPaintName[];
  static constexpr uint64_t kPaintNameHash = UINT64_C(5188891880448173739);
  Blink_PageLoad& SetPaint(int64_t value);

  static const char kPrePaintName[];
  static constexpr uint64_t kPrePaintNameHash = UINT64_C(4880392982914161630);
  Blink_PageLoad& SetPrePaint(int64_t value);

  static const char kScrollingCoordinatorName[];
  static constexpr uint64_t kScrollingCoordinatorNameHash = UINT64_C(2535431477567642583);
  Blink_PageLoad& SetScrollingCoordinator(int64_t value);

  static const char kStyleName[];
  static constexpr uint64_t kStyleNameHash = UINT64_C(12549367841823747617);
  Blink_PageLoad& SetStyle(int64_t value);

  static const char kUpdateLayersName[];
  static constexpr uint64_t kUpdateLayersNameHash = UINT64_C(1916294310099025691);
  Blink_PageLoad& SetUpdateLayers(int64_t value);

  static const char kWaitForCommitName[];
  static constexpr uint64_t kWaitForCommitNameHash = UINT64_C(16193385044298516974);
  Blink_PageLoad& SetWaitForCommit(int64_t value);

};

class Blink_Script_AsyncScripts final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_Script_AsyncScripts(ukm::SourceId source_id);
  explicit Blink_Script_AsyncScripts(base::UkmSourceId source_id);
  ~Blink_Script_AsyncScripts() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16907734789798036504);


  static const char kAsyncScriptCountName[];
  static constexpr uint64_t kAsyncScriptCountNameHash = UINT64_C(4930820782463131368);
  Blink_Script_AsyncScripts& SetAsyncScriptCount(int64_t value);

};

class Blink_UpdateTime final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_UpdateTime(ukm::SourceId source_id);
  explicit Blink_UpdateTime(base::UkmSourceId source_id);
  ~Blink_UpdateTime() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(397568092790313676);


  static const char kAnimateName[];
  static constexpr uint64_t kAnimateNameHash = UINT64_C(404752839576342973);
  Blink_UpdateTime& SetAnimate(int64_t value);

  static const char kAnimatePercentageName[];
  static constexpr uint64_t kAnimatePercentageNameHash = UINT64_C(16788666601668574229);
  Blink_UpdateTime& SetAnimatePercentage(int64_t value);

  static const char kCompositingName[];
  static constexpr uint64_t kCompositingNameHash = UINT64_C(11996896506970689590);
  Blink_UpdateTime& SetCompositing(int64_t value);

  static const char kCompositingCommitName[];
  static constexpr uint64_t kCompositingCommitNameHash = UINT64_C(15809321536415505310);
  Blink_UpdateTime& SetCompositingCommit(int64_t value);

  static const char kCompositingCommitPercentageName[];
  static constexpr uint64_t kCompositingCommitPercentageNameHash = UINT64_C(9683773163727269592);
  Blink_UpdateTime& SetCompositingCommitPercentage(int64_t value);

  static const char kCompositingPercentageName[];
  static constexpr uint64_t kCompositingPercentageNameHash = UINT64_C(4729730591730941243);
  Blink_UpdateTime& SetCompositingPercentage(int64_t value);

  static const char kForcedStyleAndLayoutName[];
  static constexpr uint64_t kForcedStyleAndLayoutNameHash = UINT64_C(15609086396948909960);
  Blink_UpdateTime& SetForcedStyleAndLayout(int64_t value);

  static const char kForcedStyleAndLayoutPercentageName[];
  static constexpr uint64_t kForcedStyleAndLayoutPercentageNameHash = UINT64_C(1282780671378158255);
  Blink_UpdateTime& SetForcedStyleAndLayoutPercentage(int64_t value);

  static const char kHandleInputEventsName[];
  static constexpr uint64_t kHandleInputEventsNameHash = UINT64_C(8113352720551083585);
  Blink_UpdateTime& SetHandleInputEvents(int64_t value);

  static const char kHandleInputEventsPercentageName[];
  static constexpr uint64_t kHandleInputEventsPercentageNameHash = UINT64_C(10373930885691098873);
  Blink_UpdateTime& SetHandleInputEventsPercentage(int64_t value);

  static const char kHitTestDocumentUpdateName[];
  static constexpr uint64_t kHitTestDocumentUpdateNameHash = UINT64_C(11724920415365121476);
  Blink_UpdateTime& SetHitTestDocumentUpdate(int64_t value);

  static const char kHitTestDocumentUpdatePercentageName[];
  static constexpr uint64_t kHitTestDocumentUpdatePercentageNameHash = UINT64_C(12950199462606213991);
  Blink_UpdateTime& SetHitTestDocumentUpdatePercentage(int64_t value);

  static const char kImplCompositorCommitName[];
  static constexpr uint64_t kImplCompositorCommitNameHash = UINT64_C(13634114799754628945);
  Blink_UpdateTime& SetImplCompositorCommit(int64_t value);

  static const char kImplCompositorCommitPercentageName[];
  static constexpr uint64_t kImplCompositorCommitPercentageNameHash = UINT64_C(10256352499980463891);
  Blink_UpdateTime& SetImplCompositorCommitPercentage(int64_t value);

  static const char kIntersectionObservationName[];
  static constexpr uint64_t kIntersectionObservationNameHash = UINT64_C(15458618821019023377);
  Blink_UpdateTime& SetIntersectionObservation(int64_t value);

  static const char kIntersectionObservationPercentageName[];
  static constexpr uint64_t kIntersectionObservationPercentageNameHash = UINT64_C(12733621349771067408);
  Blink_UpdateTime& SetIntersectionObservationPercentage(int64_t value);

  static const char kLayoutName[];
  static constexpr uint64_t kLayoutNameHash = UINT64_C(16994824421489949816);
  Blink_UpdateTime& SetLayout(int64_t value);

  static const char kLayoutPercentageName[];
  static constexpr uint64_t kLayoutPercentageNameHash = UINT64_C(881888359978198226);
  Blink_UpdateTime& SetLayoutPercentage(int64_t value);

  static const char kMainFrameName[];
  static constexpr uint64_t kMainFrameNameHash = UINT64_C(4089985743552002450);
  Blink_UpdateTime& SetMainFrame(int64_t value);

  static const char kMainFrameIsBeforeFCPName[];
  static constexpr uint64_t kMainFrameIsBeforeFCPNameHash = UINT64_C(9885769400282831772);
  Blink_UpdateTime& SetMainFrameIsBeforeFCP(int64_t value);

  static const char kMainFrameReasonsName[];
  static constexpr uint64_t kMainFrameReasonsNameHash = UINT64_C(8828908854731562228);
  Blink_UpdateTime& SetMainFrameReasons(int64_t value);

  static const char kPaintName[];
  static constexpr uint64_t kPaintNameHash = UINT64_C(5188891880448173739);
  Blink_UpdateTime& SetPaint(int64_t value);

  static const char kPaintPercentageName[];
  static constexpr uint64_t kPaintPercentageNameHash = UINT64_C(17699399351855093740);
  Blink_UpdateTime& SetPaintPercentage(int64_t value);

  static const char kPrePaintName[];
  static constexpr uint64_t kPrePaintNameHash = UINT64_C(4880392982914161630);
  Blink_UpdateTime& SetPrePaint(int64_t value);

  static const char kPrePaintPercentageName[];
  static constexpr uint64_t kPrePaintPercentageNameHash = UINT64_C(13030807739298355232);
  Blink_UpdateTime& SetPrePaintPercentage(int64_t value);

  static const char kScrollingCoordinatorName[];
  static constexpr uint64_t kScrollingCoordinatorNameHash = UINT64_C(2535431477567642583);
  Blink_UpdateTime& SetScrollingCoordinator(int64_t value);

  static const char kScrollingCoordinatorPercentageName[];
  static constexpr uint64_t kScrollingCoordinatorPercentageNameHash = UINT64_C(4147299427106315440);
  Blink_UpdateTime& SetScrollingCoordinatorPercentage(int64_t value);

  static const char kStyleName[];
  static constexpr uint64_t kStyleNameHash = UINT64_C(12549367841823747617);
  Blink_UpdateTime& SetStyle(int64_t value);

  static const char kStylePercentageName[];
  static constexpr uint64_t kStylePercentageNameHash = UINT64_C(9410633853884879876);
  Blink_UpdateTime& SetStylePercentage(int64_t value);

  static const char kUpdateLayersName[];
  static constexpr uint64_t kUpdateLayersNameHash = UINT64_C(1916294310099025691);
  Blink_UpdateTime& SetUpdateLayers(int64_t value);

  static const char kUpdateLayersPercentageName[];
  static constexpr uint64_t kUpdateLayersPercentageNameHash = UINT64_C(3948952039575933770);
  Blink_UpdateTime& SetUpdateLayersPercentage(int64_t value);

  static const char kWaitForCommitName[];
  static constexpr uint64_t kWaitForCommitNameHash = UINT64_C(16193385044298516974);
  Blink_UpdateTime& SetWaitForCommit(int64_t value);

  static const char kWaitForCommitPercentageName[];
  static constexpr uint64_t kWaitForCommitPercentageNameHash = UINT64_C(7399994841548954271);
  Blink_UpdateTime& SetWaitForCommitPercentage(int64_t value);

};

class Blink_UseCounter final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Blink_UseCounter(ukm::SourceId source_id);
  explicit Blink_UseCounter(base::UkmSourceId source_id);
  ~Blink_UseCounter() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16486120572686381376);


  static const char kFeatureName[];
  static constexpr uint64_t kFeatureNameHash = UINT64_C(2378497229593503977);
  Blink_UseCounter& SetFeature(int64_t value);

  static const char kIsMainFrameFeatureName[];
  static constexpr uint64_t kIsMainFrameFeatureNameHash = UINT64_C(8112503265735119902);
  Blink_UseCounter& SetIsMainFrameFeature(int64_t value);

};

class ClickInput final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ClickInput(ukm::SourceId source_id);
  explicit ClickInput(base::UkmSourceId source_id);
  ~ClickInput() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18270520290100355082);


  static const char kExperimental_ClickInputBurstName[];
  static constexpr uint64_t kExperimental_ClickInputBurstNameHash = UINT64_C(15140487667339141216);
  ClickInput& SetExperimental_ClickInputBurst(int64_t value);

};

class Compositor_Rendering final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Compositor_Rendering(ukm::SourceId source_id);
  explicit Compositor_Rendering(base::UkmSourceId source_id);
  ~Compositor_Rendering() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18003859069234917647);


  static const char kCheckerboardedImagesCountName[];
  static constexpr uint64_t kCheckerboardedImagesCountNameHash = UINT64_C(1155611193130623091);
  Compositor_Rendering& SetCheckerboardedImagesCount(int64_t value);

};

class Compositor_UserInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Compositor_UserInteraction(ukm::SourceId source_id);
  explicit Compositor_UserInteraction(base::UkmSourceId source_id);
  ~Compositor_UserInteraction() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3378172330402895005);


  static const char kCheckerboardedContentAreaName[];
  static constexpr uint64_t kCheckerboardedContentAreaNameHash = UINT64_C(18364704041698110260);
  Compositor_UserInteraction& SetCheckerboardedContentArea(int64_t value);

  static const char kCheckerboardedContentAreaRatioName[];
  static constexpr uint64_t kCheckerboardedContentAreaRatioNameHash = UINT64_C(6812281970879011502);
  Compositor_UserInteraction& SetCheckerboardedContentAreaRatio(int64_t value);

  static const char kCheckerboardedImagesCountName[];
  static constexpr uint64_t kCheckerboardedImagesCountNameHash = UINT64_C(1155611193130623091);
  Compositor_UserInteraction& SetCheckerboardedImagesCount(int64_t value);

  static const char kNumMissingTilesName[];
  static constexpr uint64_t kNumMissingTilesNameHash = UINT64_C(14477360290938608899);
  Compositor_UserInteraction& SetNumMissingTiles(int64_t value);

};

class ContactsPicker_ShareStatistics final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContactsPicker_ShareStatistics(ukm::SourceId source_id);
  explicit ContactsPicker_ShareStatistics(base::UkmSourceId source_id);
  ~ContactsPicker_ShareStatistics() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11375675958515902207);


  static const char kPropertiesRequestedName[];
  static constexpr uint64_t kPropertiesRequestedNameHash = UINT64_C(18375281953152993238);
  ContactsPicker_ShareStatistics& SetPropertiesRequested(int64_t value);

  static const char kSelectCountName[];
  static constexpr uint64_t kSelectCountNameHash = UINT64_C(5527119260645369915);
  ContactsPicker_ShareStatistics& SetSelectCount(int64_t value);

  static const char kSelectPercentageName[];
  static constexpr uint64_t kSelectPercentageNameHash = UINT64_C(9795301071653640943);
  ContactsPicker_ShareStatistics& SetSelectPercentage(int64_t value);

};

class ContentIndex_Added final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContentIndex_Added(ukm::SourceId source_id);
  explicit ContentIndex_Added(base::UkmSourceId source_id);
  ~ContentIndex_Added() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7195670717417274603);


  static const char kCategoryName[];
  static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
  ContentIndex_Added& SetCategory(int64_t value);

};

class ContentIndex_DeletedByUser final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContentIndex_DeletedByUser(ukm::SourceId source_id);
  explicit ContentIndex_DeletedByUser(base::UkmSourceId source_id);
  ~ContentIndex_DeletedByUser() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8302809238691294596);


  static const char kDeletedName[];
  static constexpr uint64_t kDeletedNameHash = UINT64_C(6910211073230771657);
  ContentIndex_DeletedByUser& SetDeleted(int64_t value);

};

class ContentIndex_Opened final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContentIndex_Opened(ukm::SourceId source_id);
  explicit ContentIndex_Opened(base::UkmSourceId source_id);
  ~ContentIndex_Opened() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4039427715416584382);


  static const char kIsOfflineName[];
  static constexpr uint64_t kIsOfflineNameHash = UINT64_C(17298814962699281457);
  ContentIndex_Opened& SetIsOffline(int64_t value);

};

class ContextMenuAndroid_Selected final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContextMenuAndroid_Selected(ukm::SourceId source_id);
  explicit ContextMenuAndroid_Selected(base::UkmSourceId source_id);
  ~ContextMenuAndroid_Selected() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(1205887675013444985);


  static const char kActionName[];
  static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
  ContextMenuAndroid_Selected& SetAction(int64_t value);

};

class ContextMenuAndroid_Shown final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContextMenuAndroid_Shown(ukm::SourceId source_id);
  explicit ContextMenuAndroid_Shown(base::UkmSourceId source_id);
  ~ContextMenuAndroid_Shown() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12646817710005836743);


  static const char kSearchByImageName[];
  static constexpr uint64_t kSearchByImageNameHash = UINT64_C(6108028259674083300);
  ContextMenuAndroid_Shown& SetSearchByImage(int64_t value);

  static const char kSearchWithGoogleLensName[];
  static constexpr uint64_t kSearchWithGoogleLensNameHash = UINT64_C(13660833589691996740);
  ContextMenuAndroid_Shown& SetSearchWithGoogleLens(int64_t value);

  static const char kShopWithGoogleLensName[];
  static constexpr uint64_t kShopWithGoogleLensNameHash = UINT64_C(8394054406851481398);
  ContextMenuAndroid_Shown& SetShopWithGoogleLens(int64_t value);

};

class ContextualSearch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ContextualSearch(ukm::SourceId source_id);
  explicit ContextualSearch(base::UkmSourceId source_id);
  ~ContextualSearch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14879419826968794335);


  static const char kDidOptInName[];
  static constexpr uint64_t kDidOptInNameHash = UINT64_C(12640784127050914995);
  ContextualSearch& SetDidOptIn(int64_t value);

  static const char kDurationAfterScrollMsName[];
  static constexpr uint64_t kDurationAfterScrollMsNameHash = UINT64_C(9693963647701472728);
  ContextualSearch& SetDurationAfterScrollMs(int64_t value);

  static const char kEntityImpressionsCountName[];
  static constexpr uint64_t kEntityImpressionsCountNameHash = UINT64_C(15952781754006645855);
  ContextualSearch& SetEntityImpressionsCount(int64_t value);

  static const char kEntityOpensCountName[];
  static constexpr uint64_t kEntityOpensCountNameHash = UINT64_C(641585822242808710);
  ContextualSearch& SetEntityOpensCount(int64_t value);

  static const char kFontSizeName[];
  static constexpr uint64_t kFontSizeNameHash = UINT64_C(2643658496925572245);
  ContextualSearch& SetFontSize(int64_t value);

  static const char kIsEntityName[];
  static constexpr uint64_t kIsEntityNameHash = UINT64_C(7662372954863476590);
  ContextualSearch& SetIsEntity(int64_t value);

  static const char kIsEntityEligibleName[];
  static constexpr uint64_t kIsEntityEligibleNameHash = UINT64_C(14648358556369473398);
  ContextualSearch& SetIsEntityEligible(int64_t value);

  static const char kIsHttpName[];
  static constexpr uint64_t kIsHttpNameHash = UINT64_C(1002302620744868215);
  ContextualSearch& SetIsHttp(int64_t value);

  static const char kIsLanguageMismatchName[];
  static constexpr uint64_t kIsLanguageMismatchNameHash = UINT64_C(2255335648555969039);
  ContextualSearch& SetIsLanguageMismatch(int64_t value);

  static const char kIsLongWordName[];
  static constexpr uint64_t kIsLongWordNameHash = UINT64_C(18148517952477547345);
  ContextualSearch& SetIsLongWord(int64_t value);

  static const char kIsSecondTapOverrideName[];
  static constexpr uint64_t kIsSecondTapOverrideNameHash = UINT64_C(8788769137190271820);
  ContextualSearch& SetIsSecondTapOverride(int64_t value);

  static const char kIsShortWordName[];
  static constexpr uint64_t kIsShortWordNameHash = UINT64_C(7992627050111663729);
  ContextualSearch& SetIsShortWord(int64_t value);

  static const char kIsWordEdgeName[];
  static constexpr uint64_t kIsWordEdgeNameHash = UINT64_C(7068207925783210246);
  ContextualSearch& SetIsWordEdge(int64_t value);

  static const char kOpenCountName[];
  static constexpr uint64_t kOpenCountNameHash = UINT64_C(8476882816646040416);
  ContextualSearch& SetOpenCount(int64_t value);

  static const char kOutcomeRankerDidPredictName[];
  static constexpr uint64_t kOutcomeRankerDidPredictNameHash = UINT64_C(1223460898641686759);
  ContextualSearch& SetOutcomeRankerDidPredict(int64_t value);

  static const char kOutcomeRankerPredictionName[];
  static constexpr uint64_t kOutcomeRankerPredictionNameHash = UINT64_C(15532279510849044424);
  ContextualSearch& SetOutcomeRankerPrediction(int64_t value);

  static const char kOutcomeRankerPredictionScoreName[];
  static constexpr uint64_t kOutcomeRankerPredictionScoreNameHash = UINT64_C(10863066907628573927);
  ContextualSearch& SetOutcomeRankerPredictionScore(int64_t value);

  static const char kOutcomeWasCardsDataShownName[];
  static constexpr uint64_t kOutcomeWasCardsDataShownNameHash = UINT64_C(10586318365375462202);
  ContextualSearch& SetOutcomeWasCardsDataShown(int64_t value);

  static const char kOutcomeWasPanelOpenedName[];
  static constexpr uint64_t kOutcomeWasPanelOpenedNameHash = UINT64_C(1283040101353376836);
  ContextualSearch& SetOutcomeWasPanelOpened(int64_t value);

  static const char kOutcomeWasQuickActionClickedName[];
  static constexpr uint64_t kOutcomeWasQuickActionClickedNameHash = UINT64_C(4665494976417872953);
  ContextualSearch& SetOutcomeWasQuickActionClicked(int64_t value);

  static const char kOutcomeWasQuickAnswerSeenName[];
  static constexpr uint64_t kOutcomeWasQuickAnswerSeenNameHash = UINT64_C(107968630341396949);
  ContextualSearch& SetOutcomeWasQuickAnswerSeen(int64_t value);

  static const char kPortionOfElementName[];
  static constexpr uint64_t kPortionOfElementNameHash = UINT64_C(16285840641082868632);
  ContextualSearch& SetPortionOfElement(int64_t value);

  static const char kPrevious28DayCtrPercentName[];
  static constexpr uint64_t kPrevious28DayCtrPercentNameHash = UINT64_C(959880084996189379);
  ContextualSearch& SetPrevious28DayCtrPercent(int64_t value);

  static const char kPrevious28DayImpressionsCountName[];
  static constexpr uint64_t kPrevious28DayImpressionsCountNameHash = UINT64_C(15760577507068659896);
  ContextualSearch& SetPrevious28DayImpressionsCount(int64_t value);

  static const char kPreviousWeekCtrPercentName[];
  static constexpr uint64_t kPreviousWeekCtrPercentNameHash = UINT64_C(10178724284129317201);
  ContextualSearch& SetPreviousWeekCtrPercent(int64_t value);

  static const char kPreviousWeekImpressionsCountName[];
  static constexpr uint64_t kPreviousWeekImpressionsCountNameHash = UINT64_C(9621288479571652806);
  ContextualSearch& SetPreviousWeekImpressionsCount(int64_t value);

  static const char kQuickActionImpressionsCountName[];
  static constexpr uint64_t kQuickActionImpressionsCountNameHash = UINT64_C(5143533701497306060);
  ContextualSearch& SetQuickActionImpressionsCount(int64_t value);

  static const char kQuickActionsIgnoredName[];
  static constexpr uint64_t kQuickActionsIgnoredNameHash = UINT64_C(990579457210023058);
  ContextualSearch& SetQuickActionsIgnored(int64_t value);

  static const char kQuickActionsTakenName[];
  static constexpr uint64_t kQuickActionsTakenNameHash = UINT64_C(12052780143766735854);
  ContextualSearch& SetQuickActionsTaken(int64_t value);

  static const char kQuickAnswerCountName[];
  static constexpr uint64_t kQuickAnswerCountNameHash = UINT64_C(4510489829885602207);
  ContextualSearch& SetQuickAnswerCount(int64_t value);

  static const char kScreenTopDpsName[];
  static constexpr uint64_t kScreenTopDpsNameHash = UINT64_C(12683906349255072392);
  ContextualSearch& SetScreenTopDps(int64_t value);

  static const char kTapCountName[];
  static constexpr uint64_t kTapCountNameHash = UINT64_C(271089889000519387);
  ContextualSearch& SetTapCount(int64_t value);

  static const char kTapDurationMsName[];
  static constexpr uint64_t kTapDurationMsNameHash = UINT64_C(9435816688821705322);
  ContextualSearch& SetTapDurationMs(int64_t value);

  static const char kWasScreenBottomName[];
  static constexpr uint64_t kWasScreenBottomNameHash = UINT64_C(8966660250732563679);
  ContextualSearch& SetWasScreenBottom(int64_t value);

};

class CPUUsageMeasurement final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit CPUUsageMeasurement(ukm::SourceId source_id);
  explicit CPUUsageMeasurement(base::UkmSourceId source_id);
  ~CPUUsageMeasurement() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(988984496812825435);


  static const char kCPUUsageName[];
  static constexpr uint64_t kCPUUsageNameHash = UINT64_C(4766204289640456177);
  CPUUsageMeasurement& SetCPUUsage(int64_t value);

  static const char kEventTypeName[];
  static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
  CPUUsageMeasurement& SetEventType(int64_t value);

  static const char kIsVisibleName[];
  static constexpr uint64_t kIsVisibleNameHash = UINT64_C(1485165748725517792);
  CPUUsageMeasurement& SetIsVisible(int64_t value);

  static const char kNumberOfCoresidentTabsName[];
  static constexpr uint64_t kNumberOfCoresidentTabsNameHash = UINT64_C(9703380981804271394);
  CPUUsageMeasurement& SetNumberOfCoresidentTabs(int64_t value);

  static const char kObservationWindowSizeMsName[];
  static constexpr uint64_t kObservationWindowSizeMsNameHash = UINT64_C(73587915121421831);
  CPUUsageMeasurement& SetObservationWindowSizeMs(int64_t value);

  static const char kProcessUptimeMsName[];
  static constexpr uint64_t kProcessUptimeMsNameHash = UINT64_C(12996007208370462538);
  CPUUsageMeasurement& SetProcessUptimeMs(int64_t value);

};

class DataReductionProxy final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit DataReductionProxy(ukm::SourceId source_id);
  explicit DataReductionProxy(base::UkmSourceId source_id);
  ~DataReductionProxy() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(26394013458683718);


  static const char kDataSaverPageUUIDName[];
  static constexpr uint64_t kDataSaverPageUUIDNameHash = UINT64_C(12817183208027107985);
  DataReductionProxy& SetDataSaverPageUUID(int64_t value);

  static const char kEstimatedOriginalNetworkBytesName[];
  static constexpr uint64_t kEstimatedOriginalNetworkBytesNameHash = UINT64_C(16999189648527820582);
  DataReductionProxy& SetEstimatedOriginalNetworkBytes(int64_t value);

};

class Document_OutliveTimeAfterShutdown final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Document_OutliveTimeAfterShutdown(ukm::SourceId source_id);
  explicit Document_OutliveTimeAfterShutdown(base::UkmSourceId source_id);
  ~Document_OutliveTimeAfterShutdown() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17687503538123373506);


  static const char kGCCountName[];
  static constexpr uint64_t kGCCountNameHash = UINT64_C(9191439764286334343);
  Document_OutliveTimeAfterShutdown& SetGCCount(int64_t value);

};

class DocumentCreated final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit DocumentCreated(ukm::SourceId source_id);
  explicit DocumentCreated(base::UkmSourceId source_id);
  ~DocumentCreated() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2704655726834470033);


  static const char kIsCrossOriginFrameName[];
  static constexpr uint64_t kIsCrossOriginFrameNameHash = UINT64_C(15054512686433939687);
  DocumentCreated& SetIsCrossOriginFrame(int64_t value);

  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  DocumentCreated& SetIsMainFrame(int64_t value);

  static const char kNavigationSourceIdName[];
  static constexpr uint64_t kNavigationSourceIdNameHash = UINT64_C(16809659592214455005);
  DocumentCreated& SetNavigationSourceId(int64_t value);

};

class Download_Completed final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Download_Completed(ukm::SourceId source_id);
  explicit Download_Completed(base::UkmSourceId source_id);
  ~Download_Completed() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9818692869640581957);


  static const char kBytesWastedName[];
  static constexpr uint64_t kBytesWastedNameHash = UINT64_C(13076198488342677109);
  Download_Completed& SetBytesWasted(int64_t value);

  static const char kDownloadIdName[];
  static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
  Download_Completed& SetDownloadId(int64_t value);

  static const char kResultingFileSizeName[];
  static constexpr uint64_t kResultingFileSizeNameHash = UINT64_C(9870186940406075265);
  Download_Completed& SetResultingFileSize(int64_t value);

  static const char kTimeSinceStartName[];
  static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
  Download_Completed& SetTimeSinceStart(int64_t value);

};

class Download_Interrupted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Download_Interrupted(ukm::SourceId source_id);
  explicit Download_Interrupted(base::UkmSourceId source_id);
  ~Download_Interrupted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9706055097174303);


  static const char kBytesWastedName[];
  static constexpr uint64_t kBytesWastedNameHash = UINT64_C(13076198488342677109);
  Download_Interrupted& SetBytesWasted(int64_t value);

  static const char kChangeInFileSizeName[];
  static constexpr uint64_t kChangeInFileSizeNameHash = UINT64_C(16943406704139999114);
  Download_Interrupted& SetChangeInFileSize(int64_t value);

  static const char kDownloadIdName[];
  static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
  Download_Interrupted& SetDownloadId(int64_t value);

  static const char kReasonName[];
  static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
  Download_Interrupted& SetReason(int64_t value);

  static const char kResultingFileSizeName[];
  static constexpr uint64_t kResultingFileSizeNameHash = UINT64_C(9870186940406075265);
  Download_Interrupted& SetResultingFileSize(int64_t value);

  static const char kTimeSinceStartName[];
  static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
  Download_Interrupted& SetTimeSinceStart(int64_t value);

};

class Download_Resumed final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Download_Resumed(ukm::SourceId source_id);
  explicit Download_Resumed(base::UkmSourceId source_id);
  ~Download_Resumed() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9188207819461355990);


  static const char kDownloadIdName[];
  static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
  Download_Resumed& SetDownloadId(int64_t value);

  static const char kModeName[];
  static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
  Download_Resumed& SetMode(int64_t value);

  static const char kTimeSinceStartName[];
  static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
  Download_Resumed& SetTimeSinceStart(int64_t value);

};

class Download_Started final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Download_Started(ukm::SourceId source_id);
  explicit Download_Started(base::UkmSourceId source_id);
  ~Download_Started() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2153997617158303225);


  static const char kDownloadConnectionSecurityName[];
  static constexpr uint64_t kDownloadConnectionSecurityNameHash = UINT64_C(1575516418771310819);
  Download_Started& SetDownloadConnectionSecurity(int64_t value);

  static const char kDownloadIdName[];
  static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
  Download_Started& SetDownloadId(int64_t value);

  static const char kDownloadSourceName[];
  static constexpr uint64_t kDownloadSourceNameHash = UINT64_C(11957806128610167400);
  Download_Started& SetDownloadSource(int64_t value);

  static const char kFileTypeName[];
  static constexpr uint64_t kFileTypeNameHash = UINT64_C(1646892813222506878);
  Download_Started& SetFileType(int64_t value);

  static const char kIsSameHostDownloadName[];
  static constexpr uint64_t kIsSameHostDownloadNameHash = UINT64_C(11844668225816315716);
  Download_Started& SetIsSameHostDownload(int64_t value);

};

class Event_ScrollBegin_Touch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Event_ScrollBegin_Touch(ukm::SourceId source_id);
  explicit Event_ScrollBegin_Touch(base::UkmSourceId source_id);
  ~Event_ScrollBegin_Touch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12255255036748617486);


  static const char kIsMainThreadName[];
  static constexpr uint64_t kIsMainThreadNameHash = UINT64_C(1011657010800388108);
  Event_ScrollBegin_Touch& SetIsMainThread(int64_t value);

  static const char kTimeToHandledName[];
  static constexpr uint64_t kTimeToHandledNameHash = UINT64_C(10647249754326480869);
  Event_ScrollBegin_Touch& SetTimeToHandled(int64_t value);

  static const char kTimeToScrollUpdateSwapBeginName[];
  static constexpr uint64_t kTimeToScrollUpdateSwapBeginNameHash = UINT64_C(1631660777277694939);
  Event_ScrollBegin_Touch& SetTimeToScrollUpdateSwapBegin(int64_t value);

};

class Event_ScrollBegin_Wheel final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Event_ScrollBegin_Wheel(ukm::SourceId source_id);
  explicit Event_ScrollBegin_Wheel(base::UkmSourceId source_id);
  ~Event_ScrollBegin_Wheel() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15188233126885586509);


  static const char kIsMainThreadName[];
  static constexpr uint64_t kIsMainThreadNameHash = UINT64_C(1011657010800388108);
  Event_ScrollBegin_Wheel& SetIsMainThread(int64_t value);

  static const char kTimeToHandledName[];
  static constexpr uint64_t kTimeToHandledNameHash = UINT64_C(10647249754326480869);
  Event_ScrollBegin_Wheel& SetTimeToHandled(int64_t value);

  static const char kTimeToScrollUpdateSwapBeginName[];
  static constexpr uint64_t kTimeToScrollUpdateSwapBeginNameHash = UINT64_C(1631660777277694939);
  Event_ScrollBegin_Wheel& SetTimeToScrollUpdateSwapBegin(int64_t value);

};

class Event_ScrollUpdate_Touch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Event_ScrollUpdate_Touch(ukm::SourceId source_id);
  explicit Event_ScrollUpdate_Touch(base::UkmSourceId source_id);
  ~Event_ScrollUpdate_Touch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7257623327097011244);


  static const char kIsMainThreadName[];
  static constexpr uint64_t kIsMainThreadNameHash = UINT64_C(1011657010800388108);
  Event_ScrollUpdate_Touch& SetIsMainThread(int64_t value);

  static const char kTimeToHandledName[];
  static constexpr uint64_t kTimeToHandledNameHash = UINT64_C(10647249754326480869);
  Event_ScrollUpdate_Touch& SetTimeToHandled(int64_t value);

  static const char kTimeToScrollUpdateSwapBeginName[];
  static constexpr uint64_t kTimeToScrollUpdateSwapBeginNameHash = UINT64_C(1631660777277694939);
  Event_ScrollUpdate_Touch& SetTimeToScrollUpdateSwapBegin(int64_t value);

};

class Event_ScrollUpdate_Wheel final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Event_ScrollUpdate_Wheel(ukm::SourceId source_id);
  explicit Event_ScrollUpdate_Wheel(base::UkmSourceId source_id);
  ~Event_ScrollUpdate_Wheel() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12963707033129547010);


  static const char kIsMainThreadName[];
  static constexpr uint64_t kIsMainThreadNameHash = UINT64_C(1011657010800388108);
  Event_ScrollUpdate_Wheel& SetIsMainThread(int64_t value);

  static const char kTimeToHandledName[];
  static constexpr uint64_t kTimeToHandledNameHash = UINT64_C(10647249754326480869);
  Event_ScrollUpdate_Wheel& SetTimeToHandled(int64_t value);

  static const char kTimeToScrollUpdateSwapBeginName[];
  static constexpr uint64_t kTimeToScrollUpdateSwapBeginNameHash = UINT64_C(1631660777277694939);
  Event_ScrollUpdate_Wheel& SetTimeToScrollUpdateSwapBegin(int64_t value);

};

class Extensions_CrossOriginFetchFromContentScript3 final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Extensions_CrossOriginFetchFromContentScript3(ukm::SourceId source_id);
  explicit Extensions_CrossOriginFetchFromContentScript3(base::UkmSourceId source_id);
  ~Extensions_CrossOriginFetchFromContentScript3() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7056658383170956797);


  static const char kEventHappenedName[];
  static constexpr uint64_t kEventHappenedNameHash = UINT64_C(1529510787380563747);
  Extensions_CrossOriginFetchFromContentScript3& SetEventHappened(int64_t value);

};

class FontMatchAttempts final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit FontMatchAttempts(ukm::SourceId source_id);
  explicit FontMatchAttempts(base::UkmSourceId source_id);
  ~FontMatchAttempts() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14096131912271921055);


  static const char kLoadContextName[];
  static constexpr uint64_t kLoadContextNameHash = UINT64_C(16892252971023607146);
  FontMatchAttempts& SetLoadContext(int64_t value);

  static const char kLocalFontFailuresName[];
  static constexpr uint64_t kLocalFontFailuresNameHash = UINT64_C(11374192084528809227);
  FontMatchAttempts& SetLocalFontFailures(int64_t value);

  static const char kLocalFontSuccessesName[];
  static constexpr uint64_t kLocalFontSuccessesNameHash = UINT64_C(3770291609206623888);
  FontMatchAttempts& SetLocalFontSuccesses(int64_t value);

  static const char kSystemFontFamilyFailuresName[];
  static constexpr uint64_t kSystemFontFamilyFailuresNameHash = UINT64_C(18275145271112769240);
  FontMatchAttempts& SetSystemFontFamilyFailures(int64_t value);

  static const char kSystemFontFamilySuccessesName[];
  static constexpr uint64_t kSystemFontFamilySuccessesNameHash = UINT64_C(10843526073429268857);
  FontMatchAttempts& SetSystemFontFamilySuccesses(int64_t value);

  static const char kWebFontFamilyFailuresName[];
  static constexpr uint64_t kWebFontFamilyFailuresNameHash = UINT64_C(15817650167502602188);
  FontMatchAttempts& SetWebFontFamilyFailures(int64_t value);

  static const char kWebFontFamilySuccessesName[];
  static constexpr uint64_t kWebFontFamilySuccessesNameHash = UINT64_C(11661689107446329814);
  FontMatchAttempts& SetWebFontFamilySuccesses(int64_t value);

};

class GeneratedNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit GeneratedNavigation(ukm::SourceId source_id);
  explicit GeneratedNavigation(base::UkmSourceId source_id);
  ~GeneratedNavigation() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17713702562453741093);


  static const char kFinalURLIsDefaultSearchEngineName[];
  static constexpr uint64_t kFinalURLIsDefaultSearchEngineNameHash = UINT64_C(1036686794479530753);
  GeneratedNavigation& SetFinalURLIsDefaultSearchEngine(int64_t value);

  static const char kFinalURLIsHomePageName[];
  static constexpr uint64_t kFinalURLIsHomePageNameHash = UINT64_C(1917448393817607381);
  GeneratedNavigation& SetFinalURLIsHomePage(int64_t value);

  static const char kFirstURLIsDefaultSearchEngineName[];
  static constexpr uint64_t kFirstURLIsDefaultSearchEngineNameHash = UINT64_C(16888879793066537203);
  GeneratedNavigation& SetFirstURLIsDefaultSearchEngine(int64_t value);

  static const char kFirstURLIsHomePageName[];
  static constexpr uint64_t kFirstURLIsHomePageNameHash = UINT64_C(7866972537372757464);
  GeneratedNavigation& SetFirstURLIsHomePage(int64_t value);

};

class GoogleDocsOfflineExtension final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit GoogleDocsOfflineExtension(ukm::SourceId source_id);
  explicit GoogleDocsOfflineExtension(base::UkmSourceId source_id);
  ~GoogleDocsOfflineExtension() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3420244295988015024);


  static const char kResourceRequestedName[];
  static constexpr uint64_t kResourceRequestedNameHash = UINT64_C(121230110045336584);
  GoogleDocsOfflineExtension& SetResourceRequested(int64_t value);

};

class Graphics_Smoothness_EventLatency final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Graphics_Smoothness_EventLatency(ukm::SourceId source_id);
  explicit Graphics_Smoothness_EventLatency(base::UkmSourceId source_id);
  ~Graphics_Smoothness_EventLatency() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11577416923418681607);


  static const char kActivationName[];
  static constexpr uint64_t kActivationNameHash = UINT64_C(12224509299331452166);
  Graphics_Smoothness_EventLatency& SetActivation(int64_t value);

  static const char kBeginImplFrameToSendBeginMainFrameName[];
  static constexpr uint64_t kBeginImplFrameToSendBeginMainFrameNameHash = UINT64_C(17008172611226938782);
  Graphics_Smoothness_EventLatency& SetBeginImplFrameToSendBeginMainFrame(int64_t value);

  static const char kBrowserToRendererCompositorName[];
  static constexpr uint64_t kBrowserToRendererCompositorNameHash = UINT64_C(4393966536167787736);
  Graphics_Smoothness_EventLatency& SetBrowserToRendererCompositor(int64_t value);

  static const char kCommitName[];
  static constexpr uint64_t kCommitNameHash = UINT64_C(6473274705490247427);
  Graphics_Smoothness_EventLatency& SetCommit(int64_t value);

  static const char kEndActivateToSubmitCompositorFrameName[];
  static constexpr uint64_t kEndActivateToSubmitCompositorFrameNameHash = UINT64_C(16428909035706792583);
  Graphics_Smoothness_EventLatency& SetEndActivateToSubmitCompositorFrame(int64_t value);

  static const char kEndCommitToActivationName[];
  static constexpr uint64_t kEndCommitToActivationNameHash = UINT64_C(3830696727341877188);
  Graphics_Smoothness_EventLatency& SetEndCommitToActivation(int64_t value);

  static const char kEventTypeName[];
  static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
  Graphics_Smoothness_EventLatency& SetEventType(int64_t value);

  static const char kScrollInputTypeName[];
  static constexpr uint64_t kScrollInputTypeNameHash = UINT64_C(17008543633647094581);
  Graphics_Smoothness_EventLatency& SetScrollInputType(int64_t value);

  static const char kSendBeginMainFrameToCommitName[];
  static constexpr uint64_t kSendBeginMainFrameToCommitNameHash = UINT64_C(4533040338292079001);
  Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrameName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrameNameHash = UINT64_C(6674140523643808969);
  Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value);

  static const char kTotalLatencyName[];
  static constexpr uint64_t kTotalLatencyNameHash = UINT64_C(1484146670166706245);
  Graphics_Smoothness_EventLatency& SetTotalLatency(int64_t value);

  static const char kTotalLatencyToSwapEndName[];
  static constexpr uint64_t kTotalLatencyToSwapEndNameHash = UINT64_C(17237468931010370397);
  Graphics_Smoothness_EventLatency& SetTotalLatencyToSwapEnd(int64_t value);

};

class Graphics_Smoothness_Latency final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Graphics_Smoothness_Latency(ukm::SourceId source_id);
  explicit Graphics_Smoothness_Latency(base::UkmSourceId source_id);
  ~Graphics_Smoothness_Latency() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4259890394998283936);


  static const char kActivationName[];
  static constexpr uint64_t kActivationNameHash = UINT64_C(12224509299331452166);
  Graphics_Smoothness_Latency& SetActivation(int64_t value);

  static const char kBeginImplFrameToSendBeginMainFrameName[];
  static constexpr uint64_t kBeginImplFrameToSendBeginMainFrameNameHash = UINT64_C(17008172611226938782);
  Graphics_Smoothness_Latency& SetBeginImplFrameToSendBeginMainFrame(int64_t value);

  static const char kCommitName[];
  static constexpr uint64_t kCommitNameHash = UINT64_C(6473274705490247427);
  Graphics_Smoothness_Latency& SetCommit(int64_t value);

  static const char kCompositorAnimationName[];
  static constexpr uint64_t kCompositorAnimationNameHash = UINT64_C(11839765941398348215);
  Graphics_Smoothness_Latency& SetCompositorAnimation(int64_t value);

  static const char kEndActivateToSubmitCompositorFrameName[];
  static constexpr uint64_t kEndActivateToSubmitCompositorFrameNameHash = UINT64_C(16428909035706792583);
  Graphics_Smoothness_Latency& SetEndActivateToSubmitCompositorFrame(int64_t value);

  static const char kEndCommitToActivationName[];
  static constexpr uint64_t kEndCommitToActivationNameHash = UINT64_C(3830696727341877188);
  Graphics_Smoothness_Latency& SetEndCommitToActivation(int64_t value);

  static const char kMainThreadAnimationName[];
  static constexpr uint64_t kMainThreadAnimationNameHash = UINT64_C(17585341169403378470);
  Graphics_Smoothness_Latency& SetMainThreadAnimation(int64_t value);

  static const char kMissedFrameName[];
  static constexpr uint64_t kMissedFrameNameHash = UINT64_C(4476428804431606583);
  Graphics_Smoothness_Latency& SetMissedFrame(int64_t value);

  static const char kPinchZoomName[];
  static constexpr uint64_t kPinchZoomNameHash = UINT64_C(12064032880897582979);
  Graphics_Smoothness_Latency& SetPinchZoom(int64_t value);

  static const char kRAFName[];
  static constexpr uint64_t kRAFNameHash = UINT64_C(5697873212277685907);
  Graphics_Smoothness_Latency& SetRAF(int64_t value);

  static const char kSendBeginMainFrameToCommitName[];
  static constexpr uint64_t kSendBeginMainFrameToCommitNameHash = UINT64_C(4533040338292079001);
  Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrameName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrameNameHash = UINT64_C(6674140523643808969);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash = UINT64_C(11186016080733742173);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash = UINT64_C(7210524409551472901);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash = UINT64_C(14306474530895290443);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash = UINT64_C(838162815137783913);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value);

  static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[];
  static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash = UINT64_C(6621395714715301150);
  Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value);

  static const char kTotalLatencyName[];
  static constexpr uint64_t kTotalLatencyNameHash = UINT64_C(1484146670166706245);
  Graphics_Smoothness_Latency& SetTotalLatency(int64_t value);

  static const char kTouchScrollName[];
  static constexpr uint64_t kTouchScrollNameHash = UINT64_C(11899565240377852355);
  Graphics_Smoothness_Latency& SetTouchScroll(int64_t value);

  static const char kUnknownName[];
  static constexpr uint64_t kUnknownNameHash = UINT64_C(9806653697265365224);
  Graphics_Smoothness_Latency& SetUnknown(int64_t value);

  static const char kVideoName[];
  static constexpr uint64_t kVideoNameHash = UINT64_C(3810838688059735925);
  Graphics_Smoothness_Latency& SetVideo(int64_t value);

  static const char kWheelScrollName[];
  static constexpr uint64_t kWheelScrollNameHash = UINT64_C(82067021580369146);
  Graphics_Smoothness_Latency& SetWheelScroll(int64_t value);

};

class Graphics_Smoothness_PercentDroppedFrames final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Graphics_Smoothness_PercentDroppedFrames(ukm::SourceId source_id);
  explicit Graphics_Smoothness_PercentDroppedFrames(base::UkmSourceId source_id);
  ~Graphics_Smoothness_PercentDroppedFrames() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6831778698353217167);


  static const char kAllAnimationsName[];
  static constexpr uint64_t kAllAnimationsNameHash = UINT64_C(9418644690385035063);
  Graphics_Smoothness_PercentDroppedFrames& SetAllAnimations(int64_t value);

  static const char kAllInteractionsName[];
  static constexpr uint64_t kAllInteractionsNameHash = UINT64_C(13049191242033784332);
  Graphics_Smoothness_PercentDroppedFrames& SetAllInteractions(int64_t value);

  static const char kAllSequencesName[];
  static constexpr uint64_t kAllSequencesNameHash = UINT64_C(6028515937420265331);
  Graphics_Smoothness_PercentDroppedFrames& SetAllSequences(int64_t value);

  static const char kCompositorThread_CompositorAnimationName[];
  static constexpr uint64_t kCompositorThread_CompositorAnimationNameHash = UINT64_C(11508986088444192594);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_CompositorAnimation(int64_t value);

  static const char kCompositorThread_MainThreadAnimationName[];
  static constexpr uint64_t kCompositorThread_MainThreadAnimationNameHash = UINT64_C(3902324856980997333);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_MainThreadAnimation(int64_t value);

  static const char kCompositorThread_PinchZoomName[];
  static constexpr uint64_t kCompositorThread_PinchZoomNameHash = UINT64_C(14027074550302800518);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_PinchZoom(int64_t value);

  static const char kCompositorThread_RAFName[];
  static constexpr uint64_t kCompositorThread_RAFNameHash = UINT64_C(10190667140064471187);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_RAF(int64_t value);

  static const char kCompositorThread_TouchScrollName[];
  static constexpr uint64_t kCompositorThread_TouchScrollNameHash = UINT64_C(1734389275819109649);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_TouchScroll(int64_t value);

  static const char kCompositorThread_UniversalName[];
  static constexpr uint64_t kCompositorThread_UniversalNameHash = UINT64_C(1007281809521606678);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_Universal(int64_t value);

  static const char kCompositorThread_VideoName[];
  static constexpr uint64_t kCompositorThread_VideoNameHash = UINT64_C(2464666396187755279);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_Video(int64_t value);

  static const char kCompositorThread_WheelScrollName[];
  static constexpr uint64_t kCompositorThread_WheelScrollNameHash = UINT64_C(15112909620146868915);
  Graphics_Smoothness_PercentDroppedFrames& SetCompositorThread_WheelScroll(int64_t value);

  static const char kMainThread_CompositorAnimationName[];
  static constexpr uint64_t kMainThread_CompositorAnimationNameHash = UINT64_C(1114728914573230140);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_CompositorAnimation(int64_t value);

  static const char kMainThread_MainThreadAnimationName[];
  static constexpr uint64_t kMainThread_MainThreadAnimationNameHash = UINT64_C(9417612520398703314);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_MainThreadAnimation(int64_t value);

  static const char kMainThread_PinchZoomName[];
  static constexpr uint64_t kMainThread_PinchZoomNameHash = UINT64_C(8673404319606286985);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_PinchZoom(int64_t value);

  static const char kMainThread_RAFName[];
  static constexpr uint64_t kMainThread_RAFNameHash = UINT64_C(6083877763173548455);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_RAF(int64_t value);

  static const char kMainThread_TouchScrollName[];
  static constexpr uint64_t kMainThread_TouchScrollNameHash = UINT64_C(16953845144267820592);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_TouchScroll(int64_t value);

  static const char kMainThread_UniversalName[];
  static constexpr uint64_t kMainThread_UniversalNameHash = UINT64_C(113620670344084971);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_Universal(int64_t value);

  static const char kMainThread_VideoName[];
  static constexpr uint64_t kMainThread_VideoNameHash = UINT64_C(4791323324276332364);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_Video(int64_t value);

  static const char kMainThread_WheelScrollName[];
  static constexpr uint64_t kMainThread_WheelScrollNameHash = UINT64_C(1226328940498258039);
  Graphics_Smoothness_PercentDroppedFrames& SetMainThread_WheelScroll(int64_t value);

  static const char kSlowerThread_CompositorAnimationName[];
  static constexpr uint64_t kSlowerThread_CompositorAnimationNameHash = UINT64_C(9445543428295374577);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_CompositorAnimation(int64_t value);

  static const char kSlowerThread_MainThreadAnimationName[];
  static constexpr uint64_t kSlowerThread_MainThreadAnimationNameHash = UINT64_C(2181407727938480692);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_MainThreadAnimation(int64_t value);

  static const char kSlowerThread_PinchZoomName[];
  static constexpr uint64_t kSlowerThread_PinchZoomNameHash = UINT64_C(13704619336708057753);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_PinchZoom(int64_t value);

  static const char kSlowerThread_RAFName[];
  static constexpr uint64_t kSlowerThread_RAFNameHash = UINT64_C(10470149913463790153);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_RAF(int64_t value);

  static const char kSlowerThread_TouchScrollName[];
  static constexpr uint64_t kSlowerThread_TouchScrollNameHash = UINT64_C(16749703255167573311);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_TouchScroll(int64_t value);

  static const char kSlowerThread_UniversalName[];
  static constexpr uint64_t kSlowerThread_UniversalNameHash = UINT64_C(4529587551604131922);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_Universal(int64_t value);

  static const char kSlowerThread_VideoName[];
  static constexpr uint64_t kSlowerThread_VideoNameHash = UINT64_C(4821027141553097818);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_Video(int64_t value);

  static const char kSlowerThread_WheelScrollName[];
  static constexpr uint64_t kSlowerThread_WheelScrollNameHash = UINT64_C(10908301063591575695);
  Graphics_Smoothness_PercentDroppedFrames& SetSlowerThread_WheelScroll(int64_t value);

};

class HistoryManipulationIntervention final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit HistoryManipulationIntervention(ukm::SourceId source_id);
  explicit HistoryManipulationIntervention(base::UkmSourceId source_id);
  ~HistoryManipulationIntervention() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17985071802125984440);


};

class HistoryNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit HistoryNavigation(ukm::SourceId source_id);
  explicit HistoryNavigation(base::UkmSourceId source_id);
  ~HistoryNavigation() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6390056345493314213);


  static const char kBackForwardCache_IsServedFromBackForwardCacheName[];
  static constexpr uint64_t kBackForwardCache_IsServedFromBackForwardCacheNameHash = UINT64_C(4696927693770382140);
  HistoryNavigation& SetBackForwardCache_IsServedFromBackForwardCache(int64_t value);

  static const char kBackForwardCache_NotRestoredReasonsName[];
  static constexpr uint64_t kBackForwardCache_NotRestoredReasonsNameHash = UINT64_C(1788460300115305264);
  HistoryNavigation& SetBackForwardCache_NotRestoredReasons(int64_t value);

  static const char kCrossOriginSubframesFeaturesName[];
  static constexpr uint64_t kCrossOriginSubframesFeaturesNameHash = UINT64_C(15837216398858754148);
  HistoryNavigation& SetCrossOriginSubframesFeatures(int64_t value);

  static const char kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName[];
  static constexpr uint64_t kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash = UINT64_C(10950301779928294410);
  HistoryNavigation& SetLastCommittedCrossDocumentNavigationSourceIdForTheSameDocument(int64_t value);

  static const char kLastCommittedSourceIdForTheSameDocumentName[];
  static constexpr uint64_t kLastCommittedSourceIdForTheSameDocumentNameHash = UINT64_C(1687479106038719889);
  HistoryNavigation& SetLastCommittedSourceIdForTheSameDocument(int64_t value);

  static const char kMainFrameFeaturesName[];
  static constexpr uint64_t kMainFrameFeaturesNameHash = UINT64_C(277837253456542220);
  HistoryNavigation& SetMainFrameFeatures(int64_t value);

  static const char kNavigatedToTheMostRecentEntryForDocumentName[];
  static constexpr uint64_t kNavigatedToTheMostRecentEntryForDocumentNameHash = UINT64_C(16985983351931289345);
  HistoryNavigation& SetNavigatedToTheMostRecentEntryForDocument(int64_t value);

  static const char kSameOriginSubframesFeaturesName[];
  static constexpr uint64_t kSameOriginSubframesFeaturesNameHash = UINT64_C(3171771254759560933);
  HistoryNavigation& SetSameOriginSubframesFeatures(int64_t value);

  static const char kTimeSinceNavigatedAwayFromDocumentName[];
  static constexpr uint64_t kTimeSinceNavigatedAwayFromDocumentNameHash = UINT64_C(17394368525671091150);
  HistoryNavigation& SetTimeSinceNavigatedAwayFromDocument(int64_t value);

};

class Identifiability final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Identifiability(ukm::SourceId source_id);
  explicit Identifiability(base::UkmSourceId source_id);
  ~Identifiability() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(287024497009309687);


  static const char kStudyGeneration_626Name[];
  static constexpr uint64_t kStudyGeneration_626NameHash = UINT64_C(11181185366848792576);
  Identifiability& SetStudyGeneration_626(int64_t value);

};

class InputEvent final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit InputEvent(ukm::SourceId source_id);
  explicit InputEvent(base::UkmSourceId source_id);
  ~InputEvent() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2784102704372436909);


  static const char kInteractiveTiming_InputDelayName[];
  static constexpr uint64_t kInteractiveTiming_InputDelayNameHash = UINT64_C(4816242175536355714);
  InputEvent& SetInteractiveTiming_InputDelay(int64_t value);

  static const char kInteractiveTiming_ProcessingTimeName[];
  static constexpr uint64_t kInteractiveTiming_ProcessingTimeNameHash = UINT64_C(7806768776702689257);
  InputEvent& SetInteractiveTiming_ProcessingTime(int64_t value);

};

class Intervention_DocumentWrite_ScriptBlock final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Intervention_DocumentWrite_ScriptBlock(ukm::SourceId source_id);
  explicit Intervention_DocumentWrite_ScriptBlock(base::UkmSourceId source_id);
  ~Intervention_DocumentWrite_ScriptBlock() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10386387717857957103);


  static const char kDisabled_ReloadName[];
  static constexpr uint64_t kDisabled_ReloadNameHash = UINT64_C(3949106941696904177);
  Intervention_DocumentWrite_ScriptBlock& SetDisabled_Reload(int64_t value);

  static const char kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteName[];
  static constexpr uint64_t kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteNameHash = UINT64_C(16007399633238692131);
  Intervention_DocumentWrite_ScriptBlock& SetParseTiming_ParseBlockedOnScriptExecutionFromDocumentWrite(int64_t value);

  static const char kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteName[];
  static constexpr uint64_t kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteNameHash = UINT64_C(310867285454477562);
  Intervention_DocumentWrite_ScriptBlock& SetParseTiming_ParseBlockedOnScriptLoadFromDocumentWrite(int64_t value);

};

class IOS_FindInPageSearchMatches final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit IOS_FindInPageSearchMatches(ukm::SourceId source_id);
  explicit IOS_FindInPageSearchMatches(base::UkmSourceId source_id);
  ~IOS_FindInPageSearchMatches() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3999691266874322037);


  static const char kHasMatchesName[];
  static constexpr uint64_t kHasMatchesNameHash = UINT64_C(7077976188191291377);
  IOS_FindInPageSearchMatches& SetHasMatches(int64_t value);

};

class IOS_PageZoomChanged final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit IOS_PageZoomChanged(ukm::SourceId source_id);
  explicit IOS_PageZoomChanged(base::UkmSourceId source_id);
  ~IOS_PageZoomChanged() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4631281682778806273);


  static const char kContentSizeCategoryName[];
  static constexpr uint64_t kContentSizeCategoryNameHash = UINT64_C(17224924781030716348);
  IOS_PageZoomChanged& SetContentSizeCategory(int64_t value);

  static const char kOverallZoomLevelName[];
  static constexpr uint64_t kOverallZoomLevelNameHash = UINT64_C(2817337295596296593);
  IOS_PageZoomChanged& SetOverallZoomLevel(int64_t value);

  static const char kUserZoomLevelName[];
  static constexpr uint64_t kUserZoomLevelNameHash = UINT64_C(13800606689589064956);
  IOS_PageZoomChanged& SetUserZoomLevel(int64_t value);

};

class IOS_RendererGone final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit IOS_RendererGone(ukm::SourceId source_id);
  explicit IOS_RendererGone(base::UkmSourceId source_id);
  ~IOS_RendererGone() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10713578431670288986);


  static const char kAliveRecentlyRendererCountName[];
  static constexpr uint64_t kAliveRecentlyRendererCountNameHash = UINT64_C(14933446705995907612);
  IOS_RendererGone& SetAliveRecentlyRendererCount(int64_t value);

  static const char kAliveRendererCountName[];
  static constexpr uint64_t kAliveRendererCountNameHash = UINT64_C(4517554268483005232);
  IOS_RendererGone& SetAliveRendererCount(int64_t value);

  static const char kInForegroundName[];
  static constexpr uint64_t kInForegroundNameHash = UINT64_C(16087321402939566058);
  IOS_RendererGone& SetInForeground(int64_t value);

  static const char kSawMemoryWarningName[];
  static constexpr uint64_t kSawMemoryWarningNameHash = UINT64_C(449336318584050538);
  IOS_RendererGone& SetSawMemoryWarning(int64_t value);

};

class IOS_URLMismatchInLegacyAndSlimNavigationManager final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit IOS_URLMismatchInLegacyAndSlimNavigationManager(ukm::SourceId source_id);
  explicit IOS_URLMismatchInLegacyAndSlimNavigationManager(base::UkmSourceId source_id);
  ~IOS_URLMismatchInLegacyAndSlimNavigationManager() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18173210514398479989);


  static const char kHasMismatchName[];
  static constexpr uint64_t kHasMismatchNameHash = UINT64_C(14369944748312834021);
  IOS_URLMismatchInLegacyAndSlimNavigationManager& SetHasMismatch(int64_t value);

};

class Layout_DisplayCutout_StateChanged final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Layout_DisplayCutout_StateChanged(ukm::SourceId source_id);
  explicit Layout_DisplayCutout_StateChanged(base::UkmSourceId source_id);
  ~Layout_DisplayCutout_StateChanged() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(1389206047285929549);


  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  Layout_DisplayCutout_StateChanged& SetIsMainFrame(int64_t value);

  static const char kSafeAreasPresentName[];
  static constexpr uint64_t kSafeAreasPresentNameHash = UINT64_C(14782585480306329863);
  Layout_DisplayCutout_StateChanged& SetSafeAreasPresent(int64_t value);

  static const char kViewportFit_AppliedName[];
  static constexpr uint64_t kViewportFit_AppliedNameHash = UINT64_C(3174683684013141815);
  Layout_DisplayCutout_StateChanged& SetViewportFit_Applied(int64_t value);

  static const char kViewportFit_IgnoredReasonName[];
  static constexpr uint64_t kViewportFit_IgnoredReasonNameHash = UINT64_C(10638530736604015937);
  Layout_DisplayCutout_StateChanged& SetViewportFit_IgnoredReason(int64_t value);

  static const char kViewportFit_SuppliedName[];
  static constexpr uint64_t kViewportFit_SuppliedNameHash = UINT64_C(3782339936139345310);
  Layout_DisplayCutout_StateChanged& SetViewportFit_Supplied(int64_t value);

};

class LoadingPredictor final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit LoadingPredictor(ukm::SourceId source_id);
  explicit LoadingPredictor(base::UkmSourceId source_id);
  ~LoadingPredictor() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17180165945688341623);


  static const char kLocalPredictionCorrectlyPredictedOriginsName[];
  static constexpr uint64_t kLocalPredictionCorrectlyPredictedOriginsNameHash = UINT64_C(11890392650600702934);
  LoadingPredictor& SetLocalPredictionCorrectlyPredictedOrigins(int64_t value);

  static const char kLocalPredictionOriginsName[];
  static constexpr uint64_t kLocalPredictionOriginsNameHash = UINT64_C(4632708717020315528);
  LoadingPredictor& SetLocalPredictionOrigins(int64_t value);

  static const char kOptimizationGuidePredictionCorrectlyPredictedOriginsName[];
  static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash = UINT64_C(13684299638232047171);
  LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedOrigins(int64_t value);

  static const char kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName[];
  static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash = UINT64_C(10378504874380127147);
  LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedSubresources(int64_t value);

  static const char kOptimizationGuidePredictionDecisionName[];
  static constexpr uint64_t kOptimizationGuidePredictionDecisionNameHash = UINT64_C(15337213847512842846);
  LoadingPredictor& SetOptimizationGuidePredictionDecision(int64_t value);

  static const char kOptimizationGuidePredictionOriginsName[];
  static constexpr uint64_t kOptimizationGuidePredictionOriginsNameHash = UINT64_C(15824464772807852023);
  LoadingPredictor& SetOptimizationGuidePredictionOrigins(int64_t value);

  static const char kOptimizationGuidePredictionSubresourcesName[];
  static constexpr uint64_t kOptimizationGuidePredictionSubresourcesNameHash = UINT64_C(16369424947811357892);
  LoadingPredictor& SetOptimizationGuidePredictionSubresources(int64_t value);

};

class LocalNetworkRequests final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit LocalNetworkRequests(ukm::SourceId source_id);
  explicit LocalNetworkRequests(base::UkmSourceId source_id);
  ~LocalNetworkRequests() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5563841616204153427);


  static const char kCount_FailedName[];
  static constexpr uint64_t kCount_FailedNameHash = UINT64_C(4332170555344799116);
  LocalNetworkRequests& SetCount_Failed(int64_t value);

  static const char kCount_SuccessfulName[];
  static constexpr uint64_t kCount_SuccessfulNameHash = UINT64_C(7366317784072625071);
  LocalNetworkRequests& SetCount_Successful(int64_t value);

  static const char kPortTypeName[];
  static constexpr uint64_t kPortTypeNameHash = UINT64_C(8660532902729963646);
  LocalNetworkRequests& SetPortType(int64_t value);

  static const char kResourceTypeName[];
  static constexpr uint64_t kResourceTypeNameHash = UINT64_C(13449604986098457094);
  LocalNetworkRequests& SetResourceType(int64_t value);

};

class LookalikeUrl_NavigationSuggestion final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit LookalikeUrl_NavigationSuggestion(ukm::SourceId source_id);
  explicit LookalikeUrl_NavigationSuggestion(base::UkmSourceId source_id);
  ~LookalikeUrl_NavigationSuggestion() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6455694443766360259);


  static const char kMatchTypeName[];
  static constexpr uint64_t kMatchTypeNameHash = UINT64_C(11181695565646487911);
  LookalikeUrl_NavigationSuggestion& SetMatchType(int64_t value);

  static const char kUserActionName[];
  static constexpr uint64_t kUserActionNameHash = UINT64_C(11431707273815549887);
  LookalikeUrl_NavigationSuggestion& SetUserAction(int64_t value);

};

class MainFrameNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MainFrameNavigation(ukm::SourceId source_id);
  explicit MainFrameNavigation(base::UkmSourceId source_id);
  ~MainFrameNavigation() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17528121675680665933);


  static const char kDidCommitName[];
  static constexpr uint64_t kDidCommitNameHash = UINT64_C(15090303392628531230);
  MainFrameNavigation& SetDidCommit(int64_t value);

};

class Media_Autoplay_Attempt final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Autoplay_Attempt(ukm::SourceId source_id);
  explicit Media_Autoplay_Attempt(base::UkmSourceId source_id);
  ~Media_Autoplay_Attempt() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15357501003006382777);


  static const char kAudioTrackName[];
  static constexpr uint64_t kAudioTrackNameHash = UINT64_C(11741394230508611626);
  Media_Autoplay_Attempt& SetAudioTrack(int64_t value);

  static const char kHighMediaEngagementName[];
  static constexpr uint64_t kHighMediaEngagementNameHash = UINT64_C(7387526769811817505);
  Media_Autoplay_Attempt& SetHighMediaEngagement(int64_t value);

  static const char kMutedName[];
  static constexpr uint64_t kMutedNameHash = UINT64_C(8116925261070264013);
  Media_Autoplay_Attempt& SetMuted(int64_t value);

  static const char kSourceName[];
  static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
  Media_Autoplay_Attempt& SetSource(int64_t value);

  static const char kUserGestureRequiredName[];
  static constexpr uint64_t kUserGestureRequiredNameHash = UINT64_C(18423189923073954832);
  Media_Autoplay_Attempt& SetUserGestureRequired(int64_t value);

  static const char kUserGestureStatusName[];
  static constexpr uint64_t kUserGestureStatusNameHash = UINT64_C(17118719080195994394);
  Media_Autoplay_Attempt& SetUserGestureStatus(int64_t value);

  static const char kVideoTrackName[];
  static constexpr uint64_t kVideoTrackNameHash = UINT64_C(4366426770158320744);
  Media_Autoplay_Attempt& SetVideoTrack(int64_t value);

};

class Media_Autoplay_AudioContext final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Autoplay_AudioContext(ukm::SourceId source_id);
  explicit Media_Autoplay_AudioContext(base::UkmSourceId source_id);
  ~Media_Autoplay_AudioContext() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2039378813737092278);


  static const char kSourceNodeStartedName[];
  static constexpr uint64_t kSourceNodeStartedNameHash = UINT64_C(10503181443482708212);
  Media_Autoplay_AudioContext& SetSourceNodeStarted(int64_t value);

  static const char kStatusName[];
  static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
  Media_Autoplay_AudioContext& SetStatus(int64_t value);

  static const char kUnlockTypeName[];
  static constexpr uint64_t kUnlockTypeNameHash = UINT64_C(11517746341786708229);
  Media_Autoplay_AudioContext& SetUnlockType(int64_t value);

};

class Media_Autoplay_Muted_UnmuteAction final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Autoplay_Muted_UnmuteAction(ukm::SourceId source_id);
  explicit Media_Autoplay_Muted_UnmuteAction(base::UkmSourceId source_id);
  ~Media_Autoplay_Muted_UnmuteAction() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3015822386723746523);


  static const char kResultName[];
  static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
  Media_Autoplay_Muted_UnmuteAction& SetResult(int64_t value);

  static const char kSourceName[];
  static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
  Media_Autoplay_Muted_UnmuteAction& SetSource(int64_t value);

};

class Media_BasicPlayback final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_BasicPlayback(ukm::SourceId source_id);
  explicit Media_BasicPlayback(base::UkmSourceId source_id);
  ~Media_BasicPlayback() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8416658001170131658);


  static const char kAudioCodecName[];
  static constexpr uint64_t kAudioCodecNameHash = UINT64_C(1465592132233517979);
  Media_BasicPlayback& SetAudioCodec(int64_t value);

  static const char kAudioCodecProfileName[];
  static constexpr uint64_t kAudioCodecProfileNameHash = UINT64_C(15517112798891852308);
  Media_BasicPlayback& SetAudioCodecProfile(int64_t value);

  static const char kAudioDecoderNameName[];
  static constexpr uint64_t kAudioDecoderNameNameHash = UINT64_C(7400968670179001125);
  Media_BasicPlayback& SetAudioDecoderName(int64_t value);

  static const char kAudioEncryptionSchemeName[];
  static constexpr uint64_t kAudioEncryptionSchemeNameHash = UINT64_C(9279392719755629215);
  Media_BasicPlayback& SetAudioEncryptionScheme(int64_t value);

  static const char kAutoplayInitiatedName[];
  static constexpr uint64_t kAutoplayInitiatedNameHash = UINT64_C(5475295434443958193);
  Media_BasicPlayback& SetAutoplayInitiated(int64_t value);

  static const char kCompletedRebuffersCountName[];
  static constexpr uint64_t kCompletedRebuffersCountNameHash = UINT64_C(11401868138030856851);
  Media_BasicPlayback& SetCompletedRebuffersCount(int64_t value);

  static const char kCompletedRebuffersDurationName[];
  static constexpr uint64_t kCompletedRebuffersDurationNameHash = UINT64_C(7260457768772866332);
  Media_BasicPlayback& SetCompletedRebuffersDuration(int64_t value);

  static const char kDurationName[];
  static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
  Media_BasicPlayback& SetDuration(int64_t value);

  static const char kHasAudioName[];
  static constexpr uint64_t kHasAudioNameHash = UINT64_C(11107996916041070680);
  Media_BasicPlayback& SetHasAudio(int64_t value);

  static const char kHasVideoName[];
  static constexpr uint64_t kHasVideoNameHash = UINT64_C(14168404852977906041);
  Media_BasicPlayback& SetHasVideo(int64_t value);

  static const char kIsBackgroundName[];
  static constexpr uint64_t kIsBackgroundNameHash = UINT64_C(5213574143647769765);
  Media_BasicPlayback& SetIsBackground(int64_t value);

  static const char kIsEMEName[];
  static constexpr uint64_t kIsEMENameHash = UINT64_C(9603548586615616861);
  Media_BasicPlayback& SetIsEME(int64_t value);

  static const char kIsMSEName[];
  static constexpr uint64_t kIsMSENameHash = UINT64_C(1649159027333078910);
  Media_BasicPlayback& SetIsMSE(int64_t value);

  static const char kIsMutedName[];
  static constexpr uint64_t kIsMutedNameHash = UINT64_C(16310095796065347619);
  Media_BasicPlayback& SetIsMuted(int64_t value);

  static const char kIsTopFrameName[];
  static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
  Media_BasicPlayback& SetIsTopFrame(int64_t value);

  static const char kLastPipelineStatusName[];
  static constexpr uint64_t kLastPipelineStatusNameHash = UINT64_C(7379597174511267180);
  Media_BasicPlayback& SetLastPipelineStatus(int64_t value);

  static const char kMeanTimeBetweenRebuffersName[];
  static constexpr uint64_t kMeanTimeBetweenRebuffersNameHash = UINT64_C(4184550771348788496);
  Media_BasicPlayback& SetMeanTimeBetweenRebuffers(int64_t value);

  static const char kPlayerIDName[];
  static constexpr uint64_t kPlayerIDNameHash = UINT64_C(14726224399452516920);
  Media_BasicPlayback& SetPlayerID(int64_t value);

  static const char kRebuffersCountName[];
  static constexpr uint64_t kRebuffersCountNameHash = UINT64_C(13807071113907897713);
  Media_BasicPlayback& SetRebuffersCount(int64_t value);

  static const char kVideoCodecName[];
  static constexpr uint64_t kVideoCodecNameHash = UINT64_C(4277283989099800257);
  Media_BasicPlayback& SetVideoCodec(int64_t value);

  static const char kVideoCodecProfileName[];
  static constexpr uint64_t kVideoCodecProfileNameHash = UINT64_C(13549923910363567539);
  Media_BasicPlayback& SetVideoCodecProfile(int64_t value);

  static const char kVideoDecoderNameName[];
  static constexpr uint64_t kVideoDecoderNameNameHash = UINT64_C(2955371204855076682);
  Media_BasicPlayback& SetVideoDecoderName(int64_t value);

  static const char kVideoEncryptionSchemeName[];
  static constexpr uint64_t kVideoEncryptionSchemeNameHash = UINT64_C(8020364149971333246);
  Media_BasicPlayback& SetVideoEncryptionScheme(int64_t value);

  static const char kVideoFramesDecodedName[];
  static constexpr uint64_t kVideoFramesDecodedNameHash = UINT64_C(5249207403669740374);
  Media_BasicPlayback& SetVideoFramesDecoded(int64_t value);

  static const char kVideoFramesDroppedName[];
  static constexpr uint64_t kVideoFramesDroppedNameHash = UINT64_C(16832572534571948703);
  Media_BasicPlayback& SetVideoFramesDropped(int64_t value);

  static const char kVideoNaturalHeightName[];
  static constexpr uint64_t kVideoNaturalHeightNameHash = UINT64_C(1900038218584603521);
  Media_BasicPlayback& SetVideoNaturalHeight(int64_t value);

  static const char kVideoNaturalWidthName[];
  static constexpr uint64_t kVideoNaturalWidthNameHash = UINT64_C(7910695112651016017);
  Media_BasicPlayback& SetVideoNaturalWidth(int64_t value);

  static const char kWatchTimeName[];
  static constexpr uint64_t kWatchTimeNameHash = UINT64_C(4238353176698564424);
  Media_BasicPlayback& SetWatchTime(int64_t value);

  static const char kWatchTime_ACName[];
  static constexpr uint64_t kWatchTime_ACNameHash = UINT64_C(12245748949786056651);
  Media_BasicPlayback& SetWatchTime_AC(int64_t value);

  static const char kWatchTime_BatteryName[];
  static constexpr uint64_t kWatchTime_BatteryNameHash = UINT64_C(4816984999048658540);
  Media_BasicPlayback& SetWatchTime_Battery(int64_t value);

  static const char kWatchTime_DisplayFullscreenName[];
  static constexpr uint64_t kWatchTime_DisplayFullscreenNameHash = UINT64_C(17627238861389141605);
  Media_BasicPlayback& SetWatchTime_DisplayFullscreen(int64_t value);

  static const char kWatchTime_DisplayInlineName[];
  static constexpr uint64_t kWatchTime_DisplayInlineNameHash = UINT64_C(6904900890184958698);
  Media_BasicPlayback& SetWatchTime_DisplayInline(int64_t value);

  static const char kWatchTime_DisplayPictureInPictureName[];
  static constexpr uint64_t kWatchTime_DisplayPictureInPictureNameHash = UINT64_C(16046220114157168716);
  Media_BasicPlayback& SetWatchTime_DisplayPictureInPicture(int64_t value);

  static const char kWatchTime_NativeControlsOffName[];
  static constexpr uint64_t kWatchTime_NativeControlsOffNameHash = UINT64_C(10500999714956221012);
  Media_BasicPlayback& SetWatchTime_NativeControlsOff(int64_t value);

  static const char kWatchTime_NativeControlsOnName[];
  static constexpr uint64_t kWatchTime_NativeControlsOnNameHash = UINT64_C(7643229976440928650);
  Media_BasicPlayback& SetWatchTime_NativeControlsOn(int64_t value);

};

class Media_EME_ApiPromiseRejection final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_EME_ApiPromiseRejection(ukm::SourceId source_id);
  explicit Media_EME_ApiPromiseRejection(base::UkmSourceId source_id);
  ~Media_EME_ApiPromiseRejection() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7968428823878627316);


  static const char kApiName[];
  static constexpr uint64_t kApiNameHash = UINT64_C(8243361657487571724);
  Media_EME_ApiPromiseRejection& SetApi(int64_t value);

  static const char kSystemCodeName[];
  static constexpr uint64_t kSystemCodeNameHash = UINT64_C(2228946995368470143);
  Media_EME_ApiPromiseRejection& SetSystemCode(int64_t value);

};

class Media_EME_CreateMediaKeys final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_EME_CreateMediaKeys(ukm::SourceId source_id);
  explicit Media_EME_CreateMediaKeys(base::UkmSourceId source_id);
  ~Media_EME_CreateMediaKeys() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16664479587726188526);


  static const char kIsAdFrameName[];
  static constexpr uint64_t kIsAdFrameNameHash = UINT64_C(4919021348770235533);
  Media_EME_CreateMediaKeys& SetIsAdFrame(int64_t value);

  static const char kIsCrossOriginName[];
  static constexpr uint64_t kIsCrossOriginNameHash = UINT64_C(9876972617887417766);
  Media_EME_CreateMediaKeys& SetIsCrossOrigin(int64_t value);

  static const char kIsTopFrameName[];
  static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
  Media_EME_CreateMediaKeys& SetIsTopFrame(int64_t value);

  static const char kKeySystemName[];
  static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
  Media_EME_CreateMediaKeys& SetKeySystem(int64_t value);

};

class Media_EME_RequestMediaKeySystemAccess final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_EME_RequestMediaKeySystemAccess(ukm::SourceId source_id);
  explicit Media_EME_RequestMediaKeySystemAccess(base::UkmSourceId source_id);
  ~Media_EME_RequestMediaKeySystemAccess() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14018069268047764723);


  static const char kIsAdFrameName[];
  static constexpr uint64_t kIsAdFrameNameHash = UINT64_C(4919021348770235533);
  Media_EME_RequestMediaKeySystemAccess& SetIsAdFrame(int64_t value);

  static const char kIsCrossOriginName[];
  static constexpr uint64_t kIsCrossOriginNameHash = UINT64_C(9876972617887417766);
  Media_EME_RequestMediaKeySystemAccess& SetIsCrossOrigin(int64_t value);

  static const char kIsTopFrameName[];
  static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
  Media_EME_RequestMediaKeySystemAccess& SetIsTopFrame(int64_t value);

  static const char kKeySystemName[];
  static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
  Media_EME_RequestMediaKeySystemAccess& SetKeySystem(int64_t value);

  static const char kVideoCapabilitiesName[];
  static constexpr uint64_t kVideoCapabilitiesNameHash = UINT64_C(16227477551914694738);
  Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities(int64_t value);

  static const char kVideoCapabilities_HasEmptyRobustnessName[];
  static constexpr uint64_t kVideoCapabilities_HasEmptyRobustnessNameHash = UINT64_C(6254942854308824331);
  Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities_HasEmptyRobustness(int64_t value);

  static const char kVideoCapabilities_HasHwSecureAllRobustnessName[];
  static constexpr uint64_t kVideoCapabilities_HasHwSecureAllRobustnessNameHash = UINT64_C(10921133155864908334);
  Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities_HasHwSecureAllRobustness(int64_t value);

};

class Media_Engagement_SessionFinished final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Engagement_SessionFinished(ukm::SourceId source_id);
  explicit Media_Engagement_SessionFinished(base::UkmSourceId source_id);
  ~Media_Engagement_SessionFinished() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(886585293387977076);


  static const char kEngagement_IsHighName[];
  static constexpr uint64_t kEngagement_IsHighNameHash = UINT64_C(3559175725154865187);
  Media_Engagement_SessionFinished& SetEngagement_IsHigh(int64_t value);

  static const char kEngagement_ScoreName[];
  static constexpr uint64_t kEngagement_ScoreNameHash = UINT64_C(6115011579945185747);
  Media_Engagement_SessionFinished& SetEngagement_Score(int64_t value);

  static const char kPlaybacks_TotalName[];
  static constexpr uint64_t kPlaybacks_TotalNameHash = UINT64_C(17419025647826460429);
  Media_Engagement_SessionFinished& SetPlaybacks_Total(int64_t value);

  static const char kPlayer_Audible_DeltaName[];
  static constexpr uint64_t kPlayer_Audible_DeltaNameHash = UINT64_C(17580650989425633909);
  Media_Engagement_SessionFinished& SetPlayer_Audible_Delta(int64_t value);

  static const char kPlayer_Significant_DeltaName[];
  static constexpr uint64_t kPlayer_Significant_DeltaNameHash = UINT64_C(1233203601745147659);
  Media_Engagement_SessionFinished& SetPlayer_Significant_Delta(int64_t value);

  static const char kVisits_TotalName[];
  static constexpr uint64_t kVisits_TotalNameHash = UINT64_C(8621457172620586317);
  Media_Engagement_SessionFinished& SetVisits_Total(int64_t value);

};

class Media_Engagement_ShortPlaybackIgnored final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Engagement_ShortPlaybackIgnored(ukm::SourceId source_id);
  explicit Media_Engagement_ShortPlaybackIgnored(base::UkmSourceId source_id);
  ~Media_Engagement_ShortPlaybackIgnored() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(13016590436839167921);


  static const char kLengthName[];
  static constexpr uint64_t kLengthNameHash = UINT64_C(13414706430103511103);
  Media_Engagement_ShortPlaybackIgnored& SetLength(int64_t value);

};

class Media_Feed_Discover final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Feed_Discover(ukm::SourceId source_id);
  explicit Media_Feed_Discover(base::UkmSourceId source_id);
  ~Media_Feed_Discover() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9905764244590677619);


  static const char kHasMediaFeedName[];
  static constexpr uint64_t kHasMediaFeedNameHash = UINT64_C(8108709776245181348);
  Media_Feed_Discover& SetHasMediaFeed(int64_t value);

};

class Media_GlobalMediaControls_ActionButtonPressed final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceId source_id);
  explicit Media_GlobalMediaControls_ActionButtonPressed(base::UkmSourceId source_id);
  ~Media_GlobalMediaControls_ActionButtonPressed() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14701475071317937048);


  static const char kMediaSessionActionName[];
  static constexpr uint64_t kMediaSessionActionNameHash = UINT64_C(12367086545883832195);
  Media_GlobalMediaControls_ActionButtonPressed& SetMediaSessionAction(int64_t value);

};

class Media_Learning_PredictionRecord final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_Learning_PredictionRecord(ukm::SourceId source_id);
  explicit Media_Learning_PredictionRecord(base::UkmSourceId source_id);
  ~Media_Learning_PredictionRecord() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5140299263436558885);


  static const char kLearningTaskName[];
  static constexpr uint64_t kLearningTaskNameHash = UINT64_C(3255462620316368086);
  Media_Learning_PredictionRecord& SetLearningTask(int64_t value);

  static const char kObservedValueName[];
  static constexpr uint64_t kObservedValueNameHash = UINT64_C(9335108307962014649);
  Media_Learning_PredictionRecord& SetObservedValue(int64_t value);

  static const char kPredictedValueName[];
  static constexpr uint64_t kPredictedValueNameHash = UINT64_C(14522200333545318594);
  Media_Learning_PredictionRecord& SetPredictedValue(int64_t value);

  static const char kTrainingDataSizeName[];
  static constexpr uint64_t kTrainingDataSizeNameHash = UINT64_C(17064345110121741748);
  Media_Learning_PredictionRecord& SetTrainingDataSize(int64_t value);

  static const char kTrainingDataTotalWeightName[];
  static constexpr uint64_t kTrainingDataTotalWeightNameHash = UINT64_C(7855079783080918129);
  Media_Learning_PredictionRecord& SetTrainingDataTotalWeight(int64_t value);

};

class Media_SiteMuted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_SiteMuted(ukm::SourceId source_id);
  explicit Media_SiteMuted(base::UkmSourceId source_id);
  ~Media_SiteMuted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9485702385711484844);


  static const char kMuteReasonName[];
  static constexpr uint64_t kMuteReasonNameHash = UINT64_C(11711049693295628292);
  Media_SiteMuted& SetMuteReason(int64_t value);

};

class Media_VideoDecodePerfRecord final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_VideoDecodePerfRecord(ukm::SourceId source_id);
  explicit Media_VideoDecodePerfRecord(base::UkmSourceId source_id);
  ~Media_VideoDecodePerfRecord() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4207699002180294249);


  static const char kPerf_ApiWouldClaimIsPowerEfficientName[];
  static constexpr uint64_t kPerf_ApiWouldClaimIsPowerEfficientNameHash = UINT64_C(5735887776585123091);
  Media_VideoDecodePerfRecord& SetPerf_ApiWouldClaimIsPowerEfficient(int64_t value);

  static const char kPerf_ApiWouldClaimIsSmoothName[];
  static constexpr uint64_t kPerf_ApiWouldClaimIsSmoothNameHash = UINT64_C(12671368491971530709);
  Media_VideoDecodePerfRecord& SetPerf_ApiWouldClaimIsSmooth(int64_t value);

  static const char kPerf_PastVideoFramesDecodedName[];
  static constexpr uint64_t kPerf_PastVideoFramesDecodedNameHash = UINT64_C(8441960325832700449);
  Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesDecoded(int64_t value);

  static const char kPerf_PastVideoFramesDroppedName[];
  static constexpr uint64_t kPerf_PastVideoFramesDroppedNameHash = UINT64_C(18418972936520347850);
  Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesDropped(int64_t value);

  static const char kPerf_PastVideoFramesPowerEfficientName[];
  static constexpr uint64_t kPerf_PastVideoFramesPowerEfficientNameHash = UINT64_C(7446723482648341353);
  Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesPowerEfficient(int64_t value);

  static const char kPerf_RecordIsPowerEfficientName[];
  static constexpr uint64_t kPerf_RecordIsPowerEfficientNameHash = UINT64_C(8067819045200543647);
  Media_VideoDecodePerfRecord& SetPerf_RecordIsPowerEfficient(int64_t value);

  static const char kPerf_RecordIsSmoothName[];
  static constexpr uint64_t kPerf_RecordIsSmoothNameHash = UINT64_C(12667944347029598270);
  Media_VideoDecodePerfRecord& SetPerf_RecordIsSmooth(int64_t value);

  static const char kPerf_VideoFramesDecodedName[];
  static constexpr uint64_t kPerf_VideoFramesDecodedNameHash = UINT64_C(13148455826076313336);
  Media_VideoDecodePerfRecord& SetPerf_VideoFramesDecoded(int64_t value);

  static const char kPerf_VideoFramesDroppedName[];
  static constexpr uint64_t kPerf_VideoFramesDroppedNameHash = UINT64_C(9694095505089398065);
  Media_VideoDecodePerfRecord& SetPerf_VideoFramesDropped(int64_t value);

  static const char kPerf_VideoFramesPowerEfficientName[];
  static constexpr uint64_t kPerf_VideoFramesPowerEfficientNameHash = UINT64_C(977668949207851975);
  Media_VideoDecodePerfRecord& SetPerf_VideoFramesPowerEfficient(int64_t value);

  static const char kVideo_CodecProfileName[];
  static constexpr uint64_t kVideo_CodecProfileNameHash = UINT64_C(12697741592931889256);
  Media_VideoDecodePerfRecord& SetVideo_CodecProfile(int64_t value);

  static const char kVideo_EME_KeySystemName[];
  static constexpr uint64_t kVideo_EME_KeySystemNameHash = UINT64_C(15796328125282619455);
  Media_VideoDecodePerfRecord& SetVideo_EME_KeySystem(int64_t value);

  static const char kVideo_EME_UseHwSecureCodecsName[];
  static constexpr uint64_t kVideo_EME_UseHwSecureCodecsNameHash = UINT64_C(6542307800731144643);
  Media_VideoDecodePerfRecord& SetVideo_EME_UseHwSecureCodecs(int64_t value);

  static const char kVideo_FramesPerSecondName[];
  static constexpr uint64_t kVideo_FramesPerSecondNameHash = UINT64_C(9284015185136411749);
  Media_VideoDecodePerfRecord& SetVideo_FramesPerSecond(int64_t value);

  static const char kVideo_InTopFrameName[];
  static constexpr uint64_t kVideo_InTopFrameNameHash = UINT64_C(2486969173492159481);
  Media_VideoDecodePerfRecord& SetVideo_InTopFrame(int64_t value);

  static const char kVideo_NaturalHeightName[];
  static constexpr uint64_t kVideo_NaturalHeightNameHash = UINT64_C(6424389758392557464);
  Media_VideoDecodePerfRecord& SetVideo_NaturalHeight(int64_t value);

  static const char kVideo_NaturalWidthName[];
  static constexpr uint64_t kVideo_NaturalWidthNameHash = UINT64_C(12684813081500050839);
  Media_VideoDecodePerfRecord& SetVideo_NaturalWidth(int64_t value);

  static const char kVideo_PlayerIDName[];
  static constexpr uint64_t kVideo_PlayerIDNameHash = UINT64_C(11303151379432599370);
  Media_VideoDecodePerfRecord& SetVideo_PlayerID(int64_t value);

};

class Media_WebAudio_AudioContext_AudibleTime final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_WebAudio_AudioContext_AudibleTime(ukm::SourceId source_id);
  explicit Media_WebAudio_AudioContext_AudibleTime(base::UkmSourceId source_id);
  ~Media_WebAudio_AudioContext_AudibleTime() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17314038096102597390);


  static const char kAudibleTimeName[];
  static constexpr uint64_t kAudibleTimeNameHash = UINT64_C(12873745361743450640);
  Media_WebAudio_AudioContext_AudibleTime& SetAudibleTime(int64_t value);

  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  Media_WebAudio_AudioContext_AudibleTime& SetIsMainFrame(int64_t value);

};

class Media_WebMediaPlayerState final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Media_WebMediaPlayerState(ukm::SourceId source_id);
  explicit Media_WebMediaPlayerState(base::UkmSourceId source_id);
  ~Media_WebMediaPlayerState() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14428460888229388079);


  static const char kContainerNameName[];
  static constexpr uint64_t kContainerNameNameHash = UINT64_C(4418601378549410313);
  Media_WebMediaPlayerState& SetContainerName(int64_t value);

  static const char kFinalPipelineStatusName[];
  static constexpr uint64_t kFinalPipelineStatusNameHash = UINT64_C(10539654806699313254);
  Media_WebMediaPlayerState& SetFinalPipelineStatus(int64_t value);

  static const char kIsEMEName[];
  static constexpr uint64_t kIsEMENameHash = UINT64_C(9603548586615616861);
  Media_WebMediaPlayerState& SetIsEME(int64_t value);

  static const char kIsMSEName[];
  static constexpr uint64_t kIsMSENameHash = UINT64_C(1649159027333078910);
  Media_WebMediaPlayerState& SetIsMSE(int64_t value);

  static const char kIsTopFrameName[];
  static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
  Media_WebMediaPlayerState& SetIsTopFrame(int64_t value);

  static const char kPlayerIDName[];
  static constexpr uint64_t kPlayerIDNameHash = UINT64_C(14726224399452516920);
  Media_WebMediaPlayerState& SetPlayerID(int64_t value);

  static const char kTimeToFirstFrameName[];
  static constexpr uint64_t kTimeToFirstFrameNameHash = UINT64_C(4692112185366530109);
  Media_WebMediaPlayerState& SetTimeToFirstFrame(int64_t value);

  static const char kTimeToMetadataName[];
  static constexpr uint64_t kTimeToMetadataNameHash = UINT64_C(4362545705166911725);
  Media_WebMediaPlayerState& SetTimeToMetadata(int64_t value);

  static const char kTimeToPlayReadyName[];
  static constexpr uint64_t kTimeToPlayReadyNameHash = UINT64_C(3934160282665258072);
  Media_WebMediaPlayerState& SetTimeToPlayReady(int64_t value);

  static const char kURLSchemeName[];
  static constexpr uint64_t kURLSchemeNameHash = UINT64_C(2127881778750603395);
  Media_WebMediaPlayerState& SetURLScheme(int64_t value);

};

class MediaRouter_TabMirroringStarted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MediaRouter_TabMirroringStarted(ukm::SourceId source_id);
  explicit MediaRouter_TabMirroringStarted(base::UkmSourceId source_id);
  ~MediaRouter_TabMirroringStarted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2088599620296425553);


  static const char kAudioStateName[];
  static constexpr uint64_t kAudioStateNameHash = UINT64_C(17285533685146397729);
  MediaRouter_TabMirroringStarted& SetAudioState(int64_t value);

};

class Memory_Experimental final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Memory_Experimental(ukm::SourceId source_id);
  explicit Memory_Experimental(base::UkmSourceId source_id);
  ~Memory_Experimental() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2958711939369432145);


  static const char kArrayBufferName[];
  static constexpr uint64_t kArrayBufferNameHash = UINT64_C(11725738762011925469);
  Memory_Experimental& SetArrayBuffer(int64_t value);

  static const char kBlinkGCName[];
  static constexpr uint64_t kBlinkGCNameHash = UINT64_C(7968550169431094519);
  Memory_Experimental& SetBlinkGC(int64_t value);

  static const char kBlinkGC_AllocatedObjectsName[];
  static constexpr uint64_t kBlinkGC_AllocatedObjectsNameHash = UINT64_C(2308711769835636489);
  Memory_Experimental& SetBlinkGC_AllocatedObjects(int64_t value);

  static const char kCanvasResourceProvider_SkSurfaceName[];
  static constexpr uint64_t kCanvasResourceProvider_SkSurfaceNameHash = UINT64_C(6464412163022849223);
  Memory_Experimental& SetCanvasResourceProvider_SkSurface(int64_t value);

  static const char kCommandBufferName[];
  static constexpr uint64_t kCommandBufferNameHash = UINT64_C(11751001059183415549);
  Memory_Experimental& SetCommandBuffer(int64_t value);

  static const char kDiscardableName[];
  static constexpr uint64_t kDiscardableNameHash = UINT64_C(200561209145538443);
  Memory_Experimental& SetDiscardable(int64_t value);

  static const char kDownloadServiceName[];
  static constexpr uint64_t kDownloadServiceNameHash = UINT64_C(7359304541321789172);
  Memory_Experimental& SetDownloadService(int64_t value);

  static const char kExtensions_ValueStoreName[];
  static constexpr uint64_t kExtensions_ValueStoreNameHash = UINT64_C(29559029929544692);
  Memory_Experimental& SetExtensions_ValueStore(int64_t value);

  static const char kFontCachesName[];
  static constexpr uint64_t kFontCachesNameHash = UINT64_C(16529061004933942300);
  Memory_Experimental& SetFontCaches(int64_t value);

  static const char kGpuMemoryName[];
  static constexpr uint64_t kGpuMemoryNameHash = UINT64_C(490077485390910541);
  Memory_Experimental& SetGpuMemory(int64_t value);

  static const char kHistoryName[];
  static constexpr uint64_t kHistoryNameHash = UINT64_C(1644574205037202324);
  Memory_Experimental& SetHistory(int64_t value);

  static const char kIsVisibleName[];
  static constexpr uint64_t kIsVisibleNameHash = UINT64_C(1485165748725517792);
  Memory_Experimental& SetIsVisible(int64_t value);

  static const char kJavaHeapName[];
  static constexpr uint64_t kJavaHeapNameHash = UINT64_C(8862862044285854091);
  Memory_Experimental& SetJavaHeap(int64_t value);

  static const char kLevelDatabaseName[];
  static constexpr uint64_t kLevelDatabaseNameHash = UINT64_C(11348850218298612975);
  Memory_Experimental& SetLevelDatabase(int64_t value);

  static const char kMallocName[];
  static constexpr uint64_t kMallocNameHash = UINT64_C(1238957276816977011);
  Memory_Experimental& SetMalloc(int64_t value);

  static const char kMalloc_AllocatedObjectsName[];
  static constexpr uint64_t kMalloc_AllocatedObjectsNameHash = UINT64_C(1925721785185208243);
  Memory_Experimental& SetMalloc_AllocatedObjects(int64_t value);

  static const char kNetName[];
  static constexpr uint64_t kNetNameHash = UINT64_C(5769866783646202089);
  Memory_Experimental& SetNet(int64_t value);

  static const char kNet_UrlRequestContextName[];
  static constexpr uint64_t kNet_UrlRequestContextNameHash = UINT64_C(4591518805853525343);
  Memory_Experimental& SetNet_UrlRequestContext(int64_t value);

  static const char kNumberOfAdSubframesName[];
  static constexpr uint64_t kNumberOfAdSubframesNameHash = UINT64_C(10743182343548519998);
  Memory_Experimental& SetNumberOfAdSubframes(int64_t value);

  static const char kNumberOfArrayBufferContentsName[];
  static constexpr uint64_t kNumberOfArrayBufferContentsNameHash = UINT64_C(13264497785936960149);
  Memory_Experimental& SetNumberOfArrayBufferContents(int64_t value);

  static const char kNumberOfDetachedScriptStatesName[];
  static constexpr uint64_t kNumberOfDetachedScriptStatesNameHash = UINT64_C(18265098399102889270);
  Memory_Experimental& SetNumberOfDetachedScriptStates(int64_t value);

  static const char kNumberOfDocumentsName[];
  static constexpr uint64_t kNumberOfDocumentsNameHash = UINT64_C(5733109213322944724);
  Memory_Experimental& SetNumberOfDocuments(int64_t value);

  static const char kNumberOfExtensionsName[];
  static constexpr uint64_t kNumberOfExtensionsNameHash = UINT64_C(3403202119543761618);
  Memory_Experimental& SetNumberOfExtensions(int64_t value);

  static const char kNumberOfFramesName[];
  static constexpr uint64_t kNumberOfFramesNameHash = UINT64_C(6940065104966512226);
  Memory_Experimental& SetNumberOfFrames(int64_t value);

  static const char kNumberOfLayoutObjectsName[];
  static constexpr uint64_t kNumberOfLayoutObjectsNameHash = UINT64_C(3649880882460262866);
  Memory_Experimental& SetNumberOfLayoutObjects(int64_t value);

  static const char kNumberOfMojoHandlesName[];
  static constexpr uint64_t kNumberOfMojoHandlesNameHash = UINT64_C(16814172961108727736);
  Memory_Experimental& SetNumberOfMojoHandles(int64_t value);

  static const char kNumberOfNodesName[];
  static constexpr uint64_t kNumberOfNodesNameHash = UINT64_C(15643987746411267564);
  Memory_Experimental& SetNumberOfNodes(int64_t value);

  static const char kNumberOfWebMediaPlayersName[];
  static constexpr uint64_t kNumberOfWebMediaPlayersNameHash = UINT64_C(12804910322462330532);
  Memory_Experimental& SetNumberOfWebMediaPlayers(int64_t value);

  static const char kOmniboxSuggestionsName[];
  static constexpr uint64_t kOmniboxSuggestionsNameHash = UINT64_C(17355891050851009725);
  Memory_Experimental& SetOmniboxSuggestions(int64_t value);

  static const char kPartitionAllocName[];
  static constexpr uint64_t kPartitionAllocNameHash = UINT64_C(9610482673592445024);
  Memory_Experimental& SetPartitionAlloc(int64_t value);

  static const char kPartitionAlloc_AllocatedObjectsName[];
  static constexpr uint64_t kPartitionAlloc_AllocatedObjectsNameHash = UINT64_C(15224183457205092815);
  Memory_Experimental& SetPartitionAlloc_AllocatedObjects(int64_t value);

  static const char kPartitionAlloc_Partitions_ArrayBufferName[];
  static constexpr uint64_t kPartitionAlloc_Partitions_ArrayBufferNameHash = UINT64_C(806433197023658949);
  Memory_Experimental& SetPartitionAlloc_Partitions_ArrayBuffer(int64_t value);

  static const char kPartitionAlloc_Partitions_BufferName[];
  static constexpr uint64_t kPartitionAlloc_Partitions_BufferNameHash = UINT64_C(12341882596033563250);
  Memory_Experimental& SetPartitionAlloc_Partitions_Buffer(int64_t value);

  static const char kPartitionAlloc_Partitions_FastMallocName[];
  static constexpr uint64_t kPartitionAlloc_Partitions_FastMallocNameHash = UINT64_C(13878052578744598290);
  Memory_Experimental& SetPartitionAlloc_Partitions_FastMalloc(int64_t value);

  static const char kPartitionAlloc_Partitions_LayoutName[];
  static constexpr uint64_t kPartitionAlloc_Partitions_LayoutNameHash = UINT64_C(6655809818244318026);
  Memory_Experimental& SetPartitionAlloc_Partitions_Layout(int64_t value);

  static const char kPrivateMemoryFootprintName[];
  static constexpr uint64_t kPrivateMemoryFootprintNameHash = UINT64_C(10052513537419821189);
  Memory_Experimental& SetPrivateMemoryFootprint(int64_t value);

  static const char kPrivateSwapFootprintName[];
  static constexpr uint64_t kPrivateSwapFootprintNameHash = UINT64_C(13571406198520885449);
  Memory_Experimental& SetPrivateSwapFootprint(int64_t value);

  static const char kProcessTypeName[];
  static constexpr uint64_t kProcessTypeNameHash = UINT64_C(7486237172651555104);
  Memory_Experimental& SetProcessType(int64_t value);

  static const char kResidentName[];
  static constexpr uint64_t kResidentNameHash = UINT64_C(13461411595380681438);
  Memory_Experimental& SetResident(int64_t value);

  static const char kSharedMemoryFootprintName[];
  static constexpr uint64_t kSharedMemoryFootprintNameHash = UINT64_C(17500641147677751075);
  Memory_Experimental& SetSharedMemoryFootprint(int64_t value);

  static const char kSiteStorageName[];
  static constexpr uint64_t kSiteStorageNameHash = UINT64_C(9072081726198684739);
  Memory_Experimental& SetSiteStorage(int64_t value);

  static const char kSiteStorage_BlobStorageName[];
  static constexpr uint64_t kSiteStorage_BlobStorageNameHash = UINT64_C(7198093127485286680);
  Memory_Experimental& SetSiteStorage_BlobStorage(int64_t value);

  static const char kSiteStorage_IndexDBName[];
  static constexpr uint64_t kSiteStorage_IndexDBNameHash = UINT64_C(6402762799502043507);
  Memory_Experimental& SetSiteStorage_IndexDB(int64_t value);

  static const char kSiteStorage_LocalStorageName[];
  static constexpr uint64_t kSiteStorage_LocalStorageNameHash = UINT64_C(14933128457130084075);
  Memory_Experimental& SetSiteStorage_LocalStorage(int64_t value);

  static const char kSiteStorage_SessionStorageName[];
  static constexpr uint64_t kSiteStorage_SessionStorageNameHash = UINT64_C(14209441575119482215);
  Memory_Experimental& SetSiteStorage_SessionStorage(int64_t value);

  static const char kSkiaName[];
  static constexpr uint64_t kSkiaNameHash = UINT64_C(9991921243016949116);
  Memory_Experimental& SetSkia(int64_t value);

  static const char kSkia_SkGlyphCacheName[];
  static constexpr uint64_t kSkia_SkGlyphCacheNameHash = UINT64_C(8035476658629055040);
  Memory_Experimental& SetSkia_SkGlyphCache(int64_t value);

  static const char kSkia_SkResourceCacheName[];
  static constexpr uint64_t kSkia_SkResourceCacheNameHash = UINT64_C(6214163245680517898);
  Memory_Experimental& SetSkia_SkResourceCache(int64_t value);

  static const char kSqliteName[];
  static constexpr uint64_t kSqliteNameHash = UINT64_C(2900118879024321274);
  Memory_Experimental& SetSqlite(int64_t value);

  static const char kSyncName[];
  static constexpr uint64_t kSyncNameHash = UINT64_C(15629878885545645682);
  Memory_Experimental& SetSync(int64_t value);

  static const char kTabRestoreName[];
  static constexpr uint64_t kTabRestoreNameHash = UINT64_C(4112632899105915167);
  Memory_Experimental& SetTabRestore(int64_t value);

  static const char kTimeSinceLastNavigationName[];
  static constexpr uint64_t kTimeSinceLastNavigationNameHash = UINT64_C(13938385952041404158);
  Memory_Experimental& SetTimeSinceLastNavigation(int64_t value);

  static const char kTimeSinceLastVisibilityChangeName[];
  static constexpr uint64_t kTimeSinceLastVisibilityChangeNameHash = UINT64_C(6720756525548063269);
  Memory_Experimental& SetTimeSinceLastVisibilityChange(int64_t value);

  static const char kTotal2_PrivateMemoryFootprintName[];
  static constexpr uint64_t kTotal2_PrivateMemoryFootprintNameHash = UINT64_C(3202306657284943476);
  Memory_Experimental& SetTotal2_PrivateMemoryFootprint(int64_t value);

  static const char kTotal2_SharedMemoryFootprintName[];
  static constexpr uint64_t kTotal2_SharedMemoryFootprintNameHash = UINT64_C(12351660231667012712);
  Memory_Experimental& SetTotal2_SharedMemoryFootprint(int64_t value);

  static const char kUIName[];
  static constexpr uint64_t kUINameHash = UINT64_C(8214408844178480006);
  Memory_Experimental& SetUI(int64_t value);

  static const char kUptimeName[];
  static constexpr uint64_t kUptimeNameHash = UINT64_C(15054621371739184368);
  Memory_Experimental& SetUptime(int64_t value);

  static const char kV8Name[];
  static constexpr uint64_t kV8NameHash = UINT64_C(16896410219304879775);
  Memory_Experimental& SetV8(int64_t value);

  static const char kV8_AllocatedObjectsName[];
  static constexpr uint64_t kV8_AllocatedObjectsNameHash = UINT64_C(12768063626211715955);
  Memory_Experimental& SetV8_AllocatedObjects(int64_t value);

  static const char kV8_MainName[];
  static constexpr uint64_t kV8_MainNameHash = UINT64_C(15822769446047631319);
  Memory_Experimental& SetV8_Main(int64_t value);

  static const char kV8_Main_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_AllocatedObjectsNameHash = UINT64_C(6415930962248516020);
  Memory_Experimental& SetV8_Main_AllocatedObjects(int64_t value);

  static const char kV8_Main_GlobalHandlesName[];
  static constexpr uint64_t kV8_Main_GlobalHandlesNameHash = UINT64_C(15581823109972252891);
  Memory_Experimental& SetV8_Main_GlobalHandles(int64_t value);

  static const char kV8_Main_HeapName[];
  static constexpr uint64_t kV8_Main_HeapNameHash = UINT64_C(1921939464854386930);
  Memory_Experimental& SetV8_Main_Heap(int64_t value);

  static const char kV8_Main_Heap_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_AllocatedObjectsNameHash = UINT64_C(18399663685000936309);
  Memory_Experimental& SetV8_Main_Heap_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_CodeLargeObjectSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_CodeLargeObjectSpaceNameHash = UINT64_C(16494123902430388069);
  Memory_Experimental& SetV8_Main_Heap_CodeLargeObjectSpace(int64_t value);

  static const char kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(2364189807997549859);
  Memory_Experimental& SetV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_CodeSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_CodeSpaceNameHash = UINT64_C(17931395497534883149);
  Memory_Experimental& SetV8_Main_Heap_CodeSpace(int64_t value);

  static const char kV8_Main_Heap_CodeSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash = UINT64_C(8854776756506961912);
  Memory_Experimental& SetV8_Main_Heap_CodeSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_LargeObjectSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_LargeObjectSpaceNameHash = UINT64_C(11750966123435126059);
  Memory_Experimental& SetV8_Main_Heap_LargeObjectSpace(int64_t value);

  static const char kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(11564384343176289185);
  Memory_Experimental& SetV8_Main_Heap_LargeObjectSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_MapSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_MapSpaceNameHash = UINT64_C(11978611635426298319);
  Memory_Experimental& SetV8_Main_Heap_MapSpace(int64_t value);

  static const char kV8_Main_Heap_MapSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash = UINT64_C(16674407876969307804);
  Memory_Experimental& SetV8_Main_Heap_MapSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_NewLargeObjectSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_NewLargeObjectSpaceNameHash = UINT64_C(834392200182619412);
  Memory_Experimental& SetV8_Main_Heap_NewLargeObjectSpace(int64_t value);

  static const char kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(17778294341716883234);
  Memory_Experimental& SetV8_Main_Heap_NewLargeObjectSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_NewSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_NewSpaceNameHash = UINT64_C(10321246481429414455);
  Memory_Experimental& SetV8_Main_Heap_NewSpace(int64_t value);

  static const char kV8_Main_Heap_NewSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash = UINT64_C(14817743657656407284);
  Memory_Experimental& SetV8_Main_Heap_NewSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_OldSpaceName[];
  static constexpr uint64_t kV8_Main_Heap_OldSpaceNameHash = UINT64_C(11173434268017894307);
  Memory_Experimental& SetV8_Main_Heap_OldSpace(int64_t value);

  static const char kV8_Main_Heap_OldSpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash = UINT64_C(15835060948495197507);
  Memory_Experimental& SetV8_Main_Heap_OldSpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_Heap_ReadOnlySpaceName[];
  static constexpr uint64_t kV8_Main_Heap_ReadOnlySpaceNameHash = UINT64_C(4433186457491512075);
  Memory_Experimental& SetV8_Main_Heap_ReadOnlySpace(int64_t value);

  static const char kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash = UINT64_C(9665716489791848232);
  Memory_Experimental& SetV8_Main_Heap_ReadOnlySpace_AllocatedObjects(int64_t value);

  static const char kV8_Main_MallocName[];
  static constexpr uint64_t kV8_Main_MallocNameHash = UINT64_C(5158976984073464014);
  Memory_Experimental& SetV8_Main_Malloc(int64_t value);

  static const char kV8_WorkersName[];
  static constexpr uint64_t kV8_WorkersNameHash = UINT64_C(8553202260117802914);
  Memory_Experimental& SetV8_Workers(int64_t value);

  static const char kV8_Workers_AllocatedObjectsName[];
  static constexpr uint64_t kV8_Workers_AllocatedObjectsNameHash = UINT64_C(12177354597900444603);
  Memory_Experimental& SetV8_Workers_AllocatedObjects(int64_t value);

  static const char kWebCacheName[];
  static constexpr uint64_t kWebCacheNameHash = UINT64_C(13488018231190606421);
  Memory_Experimental& SetWebCache(int64_t value);

  static const char kWebCache_CSSStylesheetResourcesName[];
  static constexpr uint64_t kWebCache_CSSStylesheetResourcesNameHash = UINT64_C(9097814082721146272);
  Memory_Experimental& SetWebCache_CSSStylesheetResources(int64_t value);

  static const char kWebCache_EncodedSizeDuplicatedInDataUrlsName[];
  static constexpr uint64_t kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash = UINT64_C(14143651647860570899);
  Memory_Experimental& SetWebCache_EncodedSizeDuplicatedInDataUrls(int64_t value);

  static const char kWebCache_FontResourcesName[];
  static constexpr uint64_t kWebCache_FontResourcesNameHash = UINT64_C(9628146792345614317);
  Memory_Experimental& SetWebCache_FontResources(int64_t value);

  static const char kWebCache_ImageResourcesName[];
  static constexpr uint64_t kWebCache_ImageResourcesNameHash = UINT64_C(9515010466852810683);
  Memory_Experimental& SetWebCache_ImageResources(int64_t value);

  static const char kWebCache_OtherResourcesName[];
  static constexpr uint64_t kWebCache_OtherResourcesNameHash = UINT64_C(17732136591162526580);
  Memory_Experimental& SetWebCache_OtherResources(int64_t value);

  static const char kWebCache_ScriptResourcesName[];
  static constexpr uint64_t kWebCache_ScriptResourcesNameHash = UINT64_C(3925250771305782664);
  Memory_Experimental& SetWebCache_ScriptResources(int64_t value);

  static const char kWebCache_V8CodeCacheName[];
  static constexpr uint64_t kWebCache_V8CodeCacheNameHash = UINT64_C(12782736109709927035);
  Memory_Experimental& SetWebCache_V8CodeCache(int64_t value);

  static const char kWebCache_XSLStylesheetResourcesName[];
  static constexpr uint64_t kWebCache_XSLStylesheetResourcesNameHash = UINT64_C(12721691713197854566);
  Memory_Experimental& SetWebCache_XSLStylesheetResources(int64_t value);

  static const char kWebMediaPlayer_AudioName[];
  static constexpr uint64_t kWebMediaPlayer_AudioNameHash = UINT64_C(9811078190138863992);
  Memory_Experimental& SetWebMediaPlayer_Audio(int64_t value);

  static const char kWebMediaPlayer_DataSourceName[];
  static constexpr uint64_t kWebMediaPlayer_DataSourceNameHash = UINT64_C(7384723713952795180);
  Memory_Experimental& SetWebMediaPlayer_DataSource(int64_t value);

  static const char kWebMediaPlayer_DemuxerName[];
  static constexpr uint64_t kWebMediaPlayer_DemuxerNameHash = UINT64_C(15908638698549151493);
  Memory_Experimental& SetWebMediaPlayer_Demuxer(int64_t value);

  static const char kWebMediaPlayer_VideoName[];
  static constexpr uint64_t kWebMediaPlayer_VideoNameHash = UINT64_C(16129684864004564062);
  Memory_Experimental& SetWebMediaPlayer_Video(int64_t value);

};

class Memory_TabFootprint final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Memory_TabFootprint(ukm::SourceId source_id);
  explicit Memory_TabFootprint(base::UkmSourceId source_id);
  ~Memory_TabFootprint() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12430751894188593646);


  static const char kMainFrameProcessPMFName[];
  static constexpr uint64_t kMainFrameProcessPMFNameHash = UINT64_C(12781944348586693197);
  Memory_TabFootprint& SetMainFrameProcessPMF(int64_t value);

  static const char kSubFrameProcessPMF_ExcludedName[];
  static constexpr uint64_t kSubFrameProcessPMF_ExcludedNameHash = UINT64_C(4544803109589615267);
  Memory_TabFootprint& SetSubFrameProcessPMF_Excluded(int64_t value);

  static const char kSubFrameProcessPMF_IncludedName[];
  static constexpr uint64_t kSubFrameProcessPMF_IncludedNameHash = UINT64_C(10498004541020155793);
  Memory_TabFootprint& SetSubFrameProcessPMF_Included(int64_t value);

  static const char kSubFrameProcessPMF_TotalName[];
  static constexpr uint64_t kSubFrameProcessPMF_TotalNameHash = UINT64_C(11258618895083361601);
  Memory_TabFootprint& SetSubFrameProcessPMF_Total(int64_t value);

  static const char kTabPMFName[];
  static constexpr uint64_t kTabPMFNameHash = UINT64_C(5878461021664314052);
  Memory_TabFootprint& SetTabPMF(int64_t value);

};

class MixedContentAutoupgrade_ResourceRequest final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MixedContentAutoupgrade_ResourceRequest(ukm::SourceId source_id);
  explicit MixedContentAutoupgrade_ResourceRequest(base::UkmSourceId source_id);
  ~MixedContentAutoupgrade_ResourceRequest() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9946364510678884885);


  static const char kCodeName[];
  static constexpr uint64_t kCodeNameHash = UINT64_C(14559498612242860847);
  MixedContentAutoupgrade_ResourceRequest& SetCode(int64_t value);

  static const char kStatusName[];
  static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
  MixedContentAutoupgrade_ResourceRequest& SetStatus(int64_t value);

};

class MobileMenu_DirectShare final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MobileMenu_DirectShare(ukm::SourceId source_id);
  explicit MobileMenu_DirectShare(base::UkmSourceId source_id);
  ~MobileMenu_DirectShare() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10323656781780570903);


  static const char kHasOccurredName[];
  static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
  MobileMenu_DirectShare& SetHasOccurred(int64_t value);

};

class MobileMenu_FindInPage final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MobileMenu_FindInPage(ukm::SourceId source_id);
  explicit MobileMenu_FindInPage(base::UkmSourceId source_id);
  ~MobileMenu_FindInPage() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(317096594738729330);


  static const char kHasOccurredName[];
  static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
  MobileMenu_FindInPage& SetHasOccurred(int64_t value);

};

class MobileMenu_Share final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit MobileMenu_Share(ukm::SourceId source_id);
  explicit MobileMenu_Share(base::UkmSourceId source_id);
  ~MobileMenu_Share() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16632756802456473210);


  static const char kHasOccurredName[];
  static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
  MobileMenu_Share& SetHasOccurred(int64_t value);

};

class NavigationPredictorAnchorElementMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit NavigationPredictorAnchorElementMetrics(ukm::SourceId source_id);
  explicit NavigationPredictorAnchorElementMetrics(base::UkmSourceId source_id);
  ~NavigationPredictorAnchorElementMetrics() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4064735116116070675);


  static const char kAnchorIndexName[];
  static constexpr uint64_t kAnchorIndexNameHash = UINT64_C(9397884037038305849);
  NavigationPredictorAnchorElementMetrics& SetAnchorIndex(int64_t value);

  static const char kContainsImageName[];
  static constexpr uint64_t kContainsImageNameHash = UINT64_C(16441638965853255360);
  NavigationPredictorAnchorElementMetrics& SetContainsImage(int64_t value);

  static const char kIsInIframeName[];
  static constexpr uint64_t kIsInIframeNameHash = UINT64_C(2879927029285282397);
  NavigationPredictorAnchorElementMetrics& SetIsInIframe(int64_t value);

  static const char kIsURLIncrementedByOneName[];
  static constexpr uint64_t kIsURLIncrementedByOneNameHash = UINT64_C(3472078046519927012);
  NavigationPredictorAnchorElementMetrics& SetIsURLIncrementedByOne(int64_t value);

  static const char kPercentClickableAreaName[];
  static constexpr uint64_t kPercentClickableAreaNameHash = UINT64_C(12162500925069527559);
  NavigationPredictorAnchorElementMetrics& SetPercentClickableArea(int64_t value);

  static const char kPercentVerticalDistanceName[];
  static constexpr uint64_t kPercentVerticalDistanceNameHash = UINT64_C(14979657413195163456);
  NavigationPredictorAnchorElementMetrics& SetPercentVerticalDistance(int64_t value);

  static const char kSameOriginName[];
  static constexpr uint64_t kSameOriginNameHash = UINT64_C(3198866256218607801);
  NavigationPredictorAnchorElementMetrics& SetSameOrigin(int64_t value);

};

class NavigationPredictorPageLinkClick final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit NavigationPredictorPageLinkClick(ukm::SourceId source_id);
  explicit NavigationPredictorPageLinkClick(base::UkmSourceId source_id);
  ~NavigationPredictorPageLinkClick() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10775915644707889889);


  static const char kAnchorElementIndexName[];
  static constexpr uint64_t kAnchorElementIndexNameHash = UINT64_C(10478607568863071276);
  NavigationPredictorPageLinkClick& SetAnchorElementIndex(int64_t value);

};

class NavigationPredictorPageLinkMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit NavigationPredictorPageLinkMetrics(ukm::SourceId source_id);
  explicit NavigationPredictorPageLinkMetrics(base::UkmSourceId source_id);
  ~NavigationPredictorPageLinkMetrics() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(367468233168747720);


  static const char kMedianLinkLocationName[];
  static constexpr uint64_t kMedianLinkLocationNameHash = UINT64_C(10492116656714417766);
  NavigationPredictorPageLinkMetrics& SetMedianLinkLocation(int64_t value);

  static const char kNumberOfAnchors_ContainsImageName[];
  static constexpr uint64_t kNumberOfAnchors_ContainsImageNameHash = UINT64_C(924687343626407188);
  NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_ContainsImage(int64_t value);

  static const char kNumberOfAnchors_InIframeName[];
  static constexpr uint64_t kNumberOfAnchors_InIframeNameHash = UINT64_C(6586263068289067744);
  NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_InIframe(int64_t value);

  static const char kNumberOfAnchors_SameHostName[];
  static constexpr uint64_t kNumberOfAnchors_SameHostNameHash = UINT64_C(6024206236807188452);
  NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_SameHost(int64_t value);

  static const char kNumberOfAnchors_TotalName[];
  static constexpr uint64_t kNumberOfAnchors_TotalNameHash = UINT64_C(2837656844888606476);
  NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_Total(int64_t value);

  static const char kNumberOfAnchors_URLIncrementedName[];
  static constexpr uint64_t kNumberOfAnchors_URLIncrementedNameHash = UINT64_C(4900312954566928460);
  NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_URLIncremented(int64_t value);

  static const char kTotalClickableSpaceName[];
  static constexpr uint64_t kTotalClickableSpaceNameHash = UINT64_C(1923089912871098586);
  NavigationPredictorPageLinkMetrics& SetTotalClickableSpace(int64_t value);

  static const char kViewport_HeightName[];
  static constexpr uint64_t kViewport_HeightNameHash = UINT64_C(6402799756853104710);
  NavigationPredictorPageLinkMetrics& SetViewport_Height(int64_t value);

  static const char kViewport_WidthName[];
  static constexpr uint64_t kViewport_WidthNameHash = UINT64_C(2201646688798995121);
  NavigationPredictorPageLinkMetrics& SetViewport_Width(int64_t value);

};

class Net_LegacyTLSVersion final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Net_LegacyTLSVersion(ukm::SourceId source_id);
  explicit Net_LegacyTLSVersion(base::UkmSourceId source_id);
  ~Net_LegacyTLSVersion() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(83722319975286136);


  static const char kIsAdResourceName[];
  static constexpr uint64_t kIsAdResourceNameHash = UINT64_C(9449576853867193455);
  Net_LegacyTLSVersion& SetIsAdResource(int64_t value);

  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  Net_LegacyTLSVersion& SetIsMainFrame(int64_t value);

  static const char kIsSubresourceName[];
  static constexpr uint64_t kIsSubresourceNameHash = UINT64_C(9684313629212333971);
  Net_LegacyTLSVersion& SetIsSubresource(int64_t value);

};

class NoStatePrefetch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit NoStatePrefetch(ukm::SourceId source_id);
  explicit NoStatePrefetch(base::UkmSourceId source_id);
  ~NoStatePrefetch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5007192410804132260);


  static const char kPrefetchedRecently_FinalStatusName[];
  static constexpr uint64_t kPrefetchedRecently_FinalStatusNameHash = UINT64_C(9796471847649268750);
  NoStatePrefetch& SetPrefetchedRecently_FinalStatus(int64_t value);

  static const char kPrefetchedRecently_OriginName[];
  static constexpr uint64_t kPrefetchedRecently_OriginNameHash = UINT64_C(2530841639179133763);
  NoStatePrefetch& SetPrefetchedRecently_Origin(int64_t value);

  static const char kPrefetchedRecently_PrefetchAgeName[];
  static constexpr uint64_t kPrefetchedRecently_PrefetchAgeNameHash = UINT64_C(10422971425397899407);
  NoStatePrefetch& SetPrefetchedRecently_PrefetchAge(int64_t value);

};

class Notification final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Notification(ukm::SourceId source_id);
  explicit Notification(base::UkmSourceId source_id);
  ~Notification() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10867195639280438101);


  static const char kClosedReasonName[];
  static constexpr uint64_t kClosedReasonNameHash = UINT64_C(17020731291041401384);
  Notification& SetClosedReason(int64_t value);

  static const char kDidReplaceAnotherNotificationName[];
  static constexpr uint64_t kDidReplaceAnotherNotificationNameHash = UINT64_C(14697312060434823404);
  Notification& SetDidReplaceAnotherNotification(int64_t value);

  static const char kDidUserOpenSettingsName[];
  static constexpr uint64_t kDidUserOpenSettingsNameHash = UINT64_C(12457694958612229736);
  Notification& SetDidUserOpenSettings(int64_t value);

  static const char kHasBadgeName[];
  static constexpr uint64_t kHasBadgeNameHash = UINT64_C(1404314928722833713);
  Notification& SetHasBadge(int64_t value);

  static const char kHasIconName[];
  static constexpr uint64_t kHasIconNameHash = UINT64_C(4132654540182426756);
  Notification& SetHasIcon(int64_t value);

  static const char kHasImageName[];
  static constexpr uint64_t kHasImageNameHash = UINT64_C(15666573512201018736);
  Notification& SetHasImage(int64_t value);

  static const char kHasRenotifyName[];
  static constexpr uint64_t kHasRenotifyNameHash = UINT64_C(1255778828920234902);
  Notification& SetHasRenotify(int64_t value);

  static const char kHasTagName[];
  static constexpr uint64_t kHasTagNameHash = UINT64_C(10403421344797099586);
  Notification& SetHasTag(int64_t value);

  static const char kIsSilentName[];
  static constexpr uint64_t kIsSilentNameHash = UINT64_C(12611294049427120665);
  Notification& SetIsSilent(int64_t value);

  static const char kNumActionButtonClicksName[];
  static constexpr uint64_t kNumActionButtonClicksNameHash = UINT64_C(15400118752953521622);
  Notification& SetNumActionButtonClicks(int64_t value);

  static const char kNumActionsName[];
  static constexpr uint64_t kNumActionsNameHash = UINT64_C(1524089126526666739);
  Notification& SetNumActions(int64_t value);

  static const char kNumClicksName[];
  static constexpr uint64_t kNumClicksNameHash = UINT64_C(7685741146111146271);
  Notification& SetNumClicks(int64_t value);

  static const char kRequireInteractionName[];
  static constexpr uint64_t kRequireInteractionNameHash = UINT64_C(1417488390737291945);
  Notification& SetRequireInteraction(int64_t value);

  static const char kTimeUntilCloseName[];
  static constexpr uint64_t kTimeUntilCloseNameHash = UINT64_C(11999907426896258327);
  Notification& SetTimeUntilClose(int64_t value);

  static const char kTimeUntilFirstClickName[];
  static constexpr uint64_t kTimeUntilFirstClickNameHash = UINT64_C(5643047780569843127);
  Notification& SetTimeUntilFirstClick(int64_t value);

  static const char kTimeUntilLastClickName[];
  static constexpr uint64_t kTimeUntilLastClickNameHash = UINT64_C(11175801317414480864);
  Notification& SetTimeUntilLastClick(int64_t value);

};

class OptimizationGuide final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit OptimizationGuide(ukm::SourceId source_id);
  explicit OptimizationGuide(base::UkmSourceId source_id);
  ~OptimizationGuide() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2087579403365801585);


  static const char kNavigationHintsFetchAttemptStatusName[];
  static constexpr uint64_t kNavigationHintsFetchAttemptStatusNameHash = UINT64_C(1464000691203191735);
  OptimizationGuide& SetNavigationHintsFetchAttemptStatus(int64_t value);

  static const char kNavigationHintsFetchRequestLatencyName[];
  static constexpr uint64_t kNavigationHintsFetchRequestLatencyNameHash = UINT64_C(6533440160746002973);
  OptimizationGuide& SetNavigationHintsFetchRequestLatency(int64_t value);

  static const char kPainfulPageLoadModelPredictionScoreName[];
  static constexpr uint64_t kPainfulPageLoadModelPredictionScoreNameHash = UINT64_C(10010186179769926802);
  OptimizationGuide& SetPainfulPageLoadModelPredictionScore(int64_t value);

  static const char kPainfulPageLoadModelVersionName[];
  static constexpr uint64_t kPainfulPageLoadModelVersionNameHash = UINT64_C(17720450364474031631);
  OptimizationGuide& SetPainfulPageLoadModelVersion(int64_t value);

  static const char kPredictionModelFeatureEffectiveConnectionTypeName[];
  static constexpr uint64_t kPredictionModelFeatureEffectiveConnectionTypeNameHash = UINT64_C(7241953335484025720);
  OptimizationGuide& SetPredictionModelFeatureEffectiveConnectionType(int64_t value);

  static const char kPredictionModelFeatureIsSameOriginNavigationName[];
  static constexpr uint64_t kPredictionModelFeatureIsSameOriginNavigationNameHash = UINT64_C(910442687354881456);
  OptimizationGuide& SetPredictionModelFeatureIsSameOriginNavigation(int64_t value);

  static const char kPredictionModelFeatureNavigationToFCPSessionMeanName[];
  static constexpr uint64_t kPredictionModelFeatureNavigationToFCPSessionMeanNameHash = UINT64_C(4466439852803304290);
  OptimizationGuide& SetPredictionModelFeatureNavigationToFCPSessionMean(int64_t value);

  static const char kPredictionModelFeatureNavigationToFCPSessionStdDevName[];
  static constexpr uint64_t kPredictionModelFeatureNavigationToFCPSessionStdDevNameHash = UINT64_C(5240912445644558686);
  OptimizationGuide& SetPredictionModelFeatureNavigationToFCPSessionStdDev(int64_t value);

  static const char kPredictionModelFeaturePageTransitionName[];
  static constexpr uint64_t kPredictionModelFeaturePageTransitionNameHash = UINT64_C(2716652744885400005);
  OptimizationGuide& SetPredictionModelFeaturePageTransition(int64_t value);

  static const char kPredictionModelFeaturePreviousPageLoadNavigationToFCPName[];
  static constexpr uint64_t kPredictionModelFeaturePreviousPageLoadNavigationToFCPNameHash = UINT64_C(17531127691348138457);
  OptimizationGuide& SetPredictionModelFeaturePreviousPageLoadNavigationToFCP(int64_t value);

  static const char kPredictionModelFeatureSiteEngagementScoreName[];
  static constexpr uint64_t kPredictionModelFeatureSiteEngagementScoreNameHash = UINT64_C(554792981370193163);
  OptimizationGuide& SetPredictionModelFeatureSiteEngagementScore(int64_t value);

  static const char kRegisteredOptimizationTargetsName[];
  static constexpr uint64_t kRegisteredOptimizationTargetsNameHash = UINT64_C(16583518481415531705);
  OptimizationGuide& SetRegisteredOptimizationTargets(int64_t value);

  static const char kRegisteredOptimizationTypesName[];
  static constexpr uint64_t kRegisteredOptimizationTypesNameHash = UINT64_C(16255593039456486105);
  OptimizationGuide& SetRegisteredOptimizationTypes(int64_t value);

};

class PageDomainInfo final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageDomainInfo(ukm::SourceId source_id);
  explicit PageDomainInfo(base::UkmSourceId source_id);
  ~PageDomainInfo() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12853622770478513093);


  static const char kDomainTypeName[];
  static constexpr uint64_t kDomainTypeNameHash = UINT64_C(7797620970950375408);
  PageDomainInfo& SetDomainType(int64_t value);

};

class PageForegroundSession final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageForegroundSession(ukm::SourceId source_id);
  explicit PageForegroundSession(base::UkmSourceId source_id);
  ~PageForegroundSession() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14423022965050986312);


  static const char kForegroundDurationName[];
  static constexpr uint64_t kForegroundDurationNameHash = UINT64_C(14040493619853098912);
  PageForegroundSession& SetForegroundDuration(int64_t value);

  static const char kForegroundNumInputEventsName[];
  static constexpr uint64_t kForegroundNumInputEventsNameHash = UINT64_C(8312183371249827438);
  PageForegroundSession& SetForegroundNumInputEvents(int64_t value);

  static const char kForegroundTotalAdjustedInputDelayName[];
  static constexpr uint64_t kForegroundTotalAdjustedInputDelayNameHash = UINT64_C(4081792426231663378);
  PageForegroundSession& SetForegroundTotalAdjustedInputDelay(int64_t value);

  static const char kForegroundTotalInputDelayName[];
  static constexpr uint64_t kForegroundTotalInputDelayNameHash = UINT64_C(8008711279838603073);
  PageForegroundSession& SetForegroundTotalInputDelay(int64_t value);

};

class PageInfoBubble final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageInfoBubble(ukm::SourceId source_id);
  explicit PageInfoBubble(base::UkmSourceId source_id);
  ~PageInfoBubble() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10171644723325805171);


  static const char kActionTakenName[];
  static constexpr uint64_t kActionTakenNameHash = UINT64_C(9500803244906435515);
  PageInfoBubble& SetActionTaken(int64_t value);

};

class PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageLoad(ukm::SourceId source_id);
  explicit PageLoad(base::UkmSourceId source_id);
  ~PageLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12426032810838168341);


  static const char kCpuTimeName[];
  static constexpr uint64_t kCpuTimeNameHash = UINT64_C(6353397511912813717);
  PageLoad& SetCpuTime(int64_t value);

  static const char kDocumentTiming_NavigationToDOMContentLoadedEventFiredName[];
  static constexpr uint64_t kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash = UINT64_C(6867802542830008226);
  PageLoad& SetDocumentTiming_NavigationToDOMContentLoadedEventFired(int64_t value);

  static const char kDocumentTiming_NavigationToLoadEventFiredName[];
  static constexpr uint64_t kDocumentTiming_NavigationToLoadEventFiredNameHash = UINT64_C(9492260367886123818);
  PageLoad& SetDocumentTiming_NavigationToLoadEventFired(int64_t value);

  static const char kExperimental_InputToNavigationStartName[];
  static constexpr uint64_t kExperimental_InputToNavigationStartNameHash = UINT64_C(16463295207942209746);
  PageLoad& SetExperimental_InputToNavigationStart(int64_t value);

  static const char kExperimental_Navigation_UserInitiatedName[];
  static constexpr uint64_t kExperimental_Navigation_UserInitiatedNameHash = UINT64_C(16650208715214610274);
  PageLoad& SetExperimental_Navigation_UserInitiated(int64_t value);

  static const char kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintName[];
  static constexpr uint64_t kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash = UINT64_C(7669206824977834951);
  PageLoad& SetExperimental_PaintTiming_NavigationToFirstMeaningfulPaint(int64_t value);

  static const char kInteractiveTiming_FirstInputDelay4Name[];
  static constexpr uint64_t kInteractiveTiming_FirstInputDelay4NameHash = UINT64_C(6127468907094730300);
  PageLoad& SetInteractiveTiming_FirstInputDelay4(int64_t value);

  static const char kInteractiveTiming_FirstInputProcessingTimesName[];
  static constexpr uint64_t kInteractiveTiming_FirstInputProcessingTimesNameHash = UINT64_C(1593757276256967582);
  PageLoad& SetInteractiveTiming_FirstInputProcessingTimes(int64_t value);

  static const char kInteractiveTiming_FirstInputTimestamp4Name[];
  static constexpr uint64_t kInteractiveTiming_FirstInputTimestamp4NameHash = UINT64_C(16268762437310799839);
  PageLoad& SetInteractiveTiming_FirstInputTimestamp4(int64_t value);

  static const char kInteractiveTiming_FirstScrollDelayName[];
  static constexpr uint64_t kInteractiveTiming_FirstScrollDelayNameHash = UINT64_C(12767345461070005318);
  PageLoad& SetInteractiveTiming_FirstScrollDelay(int64_t value);

  static const char kInteractiveTiming_LongestInputDelay4Name[];
  static constexpr uint64_t kInteractiveTiming_LongestInputDelay4NameHash = UINT64_C(9023942308232641926);
  PageLoad& SetInteractiveTiming_LongestInputDelay4(int64_t value);

  static const char kInteractiveTiming_LongestInputTimestamp4Name[];
  static constexpr uint64_t kInteractiveTiming_LongestInputTimestamp4NameHash = UINT64_C(4114176268949136412);
  PageLoad& SetInteractiveTiming_LongestInputTimestamp4(int64_t value);

  static const char kInteractiveTiming_NumInputEventsName[];
  static constexpr uint64_t kInteractiveTiming_NumInputEventsNameHash = UINT64_C(396062217706944461);
  PageLoad& SetInteractiveTiming_NumInputEvents(int64_t value);

  static const char kInteractiveTiming_TotalAdjustedInputDelayName[];
  static constexpr uint64_t kInteractiveTiming_TotalAdjustedInputDelayNameHash = UINT64_C(6954135380531273761);
  PageLoad& SetInteractiveTiming_TotalAdjustedInputDelay(int64_t value);

  static const char kInteractiveTiming_TotalInputDelayName[];
  static constexpr uint64_t kInteractiveTiming_TotalInputDelayNameHash = UINT64_C(11141808103060574535);
  PageLoad& SetInteractiveTiming_TotalInputDelay(int64_t value);

  static const char kIsCrossProcessNavigationName[];
  static constexpr uint64_t kIsCrossProcessNavigationNameHash = UINT64_C(14766000458248570201);
  PageLoad& SetIsCrossProcessNavigation(int64_t value);

  static const char kLayoutInstability_CumulativeShiftScoreName[];
  static constexpr uint64_t kLayoutInstability_CumulativeShiftScoreNameHash = UINT64_C(6355895514150060407);
  PageLoad& SetLayoutInstability_CumulativeShiftScore(int64_t value);

  static const char kLayoutInstability_CumulativeShiftScore_MainFrameName[];
  static constexpr uint64_t kLayoutInstability_CumulativeShiftScore_MainFrameNameHash = UINT64_C(11706444123851508509);
  PageLoad& SetLayoutInstability_CumulativeShiftScore_MainFrame(int64_t value);

  static const char kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName[];
  static constexpr uint64_t kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash = UINT64_C(15733786266747591446);
  PageLoad& SetLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScroll(int64_t value);

  static const char kMainDocumentSequenceNumberName[];
  static constexpr uint64_t kMainDocumentSequenceNumberNameHash = UINT64_C(5968137368190340881);
  PageLoad& SetMainDocumentSequenceNumber(int64_t value);

  static const char kMainFrameResource_ConnectDelayName[];
  static constexpr uint64_t kMainFrameResource_ConnectDelayNameHash = UINT64_C(4568735770730238095);
  PageLoad& SetMainFrameResource_ConnectDelay(int64_t value);

  static const char kMainFrameResource_DNSDelayName[];
  static constexpr uint64_t kMainFrameResource_DNSDelayNameHash = UINT64_C(7307227729996236826);
  PageLoad& SetMainFrameResource_DNSDelay(int64_t value);

  static const char kMainFrameResource_HttpProtocolSchemeName[];
  static constexpr uint64_t kMainFrameResource_HttpProtocolSchemeNameHash = UINT64_C(3007836930622015766);
  PageLoad& SetMainFrameResource_HttpProtocolScheme(int64_t value);

  static const char kMainFrameResource_NavigationStartToReceiveHeadersStartName[];
  static constexpr uint64_t kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash = UINT64_C(1663480531586966499);
  PageLoad& SetMainFrameResource_NavigationStartToReceiveHeadersStart(int64_t value);

  static const char kMainFrameResource_NavigationStartToRequestStartName[];
  static constexpr uint64_t kMainFrameResource_NavigationStartToRequestStartNameHash = UINT64_C(2378326484600041608);
  PageLoad& SetMainFrameResource_NavigationStartToRequestStart(int64_t value);

  static const char kMainFrameResource_RedirectCountName[];
  static constexpr uint64_t kMainFrameResource_RedirectCountNameHash = UINT64_C(12945767909598519836);
  PageLoad& SetMainFrameResource_RedirectCount(int64_t value);

  static const char kMainFrameResource_RequestStartToReceiveHeadersEndName[];
  static constexpr uint64_t kMainFrameResource_RequestStartToReceiveHeadersEndNameHash = UINT64_C(15735870039030289373);
  PageLoad& SetMainFrameResource_RequestStartToReceiveHeadersEnd(int64_t value);

  static const char kMainFrameResource_RequestStartToSendStartName[];
  static constexpr uint64_t kMainFrameResource_RequestStartToSendStartNameHash = UINT64_C(13976230857219088742);
  PageLoad& SetMainFrameResource_RequestStartToSendStart(int64_t value);

  static const char kMainFrameResource_SendStartToReceiveHeadersEndName[];
  static constexpr uint64_t kMainFrameResource_SendStartToReceiveHeadersEndNameHash = UINT64_C(14929342406575835437);
  PageLoad& SetMainFrameResource_SendStartToReceiveHeadersEnd(int64_t value);

  static const char kMainFrameResource_SocketReusedName[];
  static constexpr uint64_t kMainFrameResource_SocketReusedNameHash = UINT64_C(6515553691927856961);
  PageLoad& SetMainFrameResource_SocketReused(int64_t value);

  static const char kNavigation_PageEndReason2Name[];
  static constexpr uint64_t kNavigation_PageEndReason2NameHash = UINT64_C(14267529952722108465);
  PageLoad& SetNavigation_PageEndReason2(int64_t value);

  static const char kNavigation_PageTransitionName[];
  static constexpr uint64_t kNavigation_PageTransitionNameHash = UINT64_C(6618380684727568744);
  PageLoad& SetNavigation_PageTransition(int64_t value);

  static const char kNavigationEntryOffsetName[];
  static constexpr uint64_t kNavigationEntryOffsetNameHash = UINT64_C(17340864924359066998);
  PageLoad& SetNavigationEntryOffset(int64_t value);

  static const char kNet_CacheBytes2Name[];
  static constexpr uint64_t kNet_CacheBytes2NameHash = UINT64_C(6646370524195624485);
  PageLoad& SetNet_CacheBytes2(int64_t value);

  static const char kNet_DownstreamKbpsEstimate_OnNavigationStartName[];
  static constexpr uint64_t kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash = UINT64_C(9428473883870683459);
  PageLoad& SetNet_DownstreamKbpsEstimate_OnNavigationStart(int64_t value);

  static const char kNet_EffectiveConnectionType2_OnNavigationStartName[];
  static constexpr uint64_t kNet_EffectiveConnectionType2_OnNavigationStartNameHash = UINT64_C(12505429480755299532);
  PageLoad& SetNet_EffectiveConnectionType2_OnNavigationStart(int64_t value);

  static const char kNet_ErrorCode_OnFailedProvisionalLoadName[];
  static constexpr uint64_t kNet_ErrorCode_OnFailedProvisionalLoadNameHash = UINT64_C(10394413376607560477);
  PageLoad& SetNet_ErrorCode_OnFailedProvisionalLoad(int64_t value);

  static const char kNet_HttpResponseCodeName[];
  static constexpr uint64_t kNet_HttpResponseCodeNameHash = UINT64_C(578349876587866241);
  PageLoad& SetNet_HttpResponseCode(int64_t value);

  static const char kNet_HttpRttEstimate_OnNavigationStartName[];
  static constexpr uint64_t kNet_HttpRttEstimate_OnNavigationStartNameHash = UINT64_C(5774646068519167414);
  PageLoad& SetNet_HttpRttEstimate_OnNavigationStart(int64_t value);

  static const char kNet_ImageBytesName[];
  static constexpr uint64_t kNet_ImageBytesNameHash = UINT64_C(5183779451881510109);
  PageLoad& SetNet_ImageBytes(int64_t value);

  static const char kNet_ImageSubframeBytesName[];
  static constexpr uint64_t kNet_ImageSubframeBytesNameHash = UINT64_C(14934783117622224799);
  PageLoad& SetNet_ImageSubframeBytes(int64_t value);

  static const char kNet_JavaScriptBytesName[];
  static constexpr uint64_t kNet_JavaScriptBytesNameHash = UINT64_C(16506405133843665312);
  PageLoad& SetNet_JavaScriptBytes(int64_t value);

  static const char kNet_JavaScriptMaxBytesName[];
  static constexpr uint64_t kNet_JavaScriptMaxBytesNameHash = UINT64_C(5476124973335865020);
  PageLoad& SetNet_JavaScriptMaxBytes(int64_t value);

  static const char kNet_MediaBytesName[];
  static constexpr uint64_t kNet_MediaBytesNameHash = UINT64_C(11876875363388558280);
  PageLoad& SetNet_MediaBytes(int64_t value);

  static const char kNet_NetworkBytes2Name[];
  static constexpr uint64_t kNet_NetworkBytes2NameHash = UINT64_C(17997790111755306706);
  PageLoad& SetNet_NetworkBytes2(int64_t value);

  static const char kNet_TransportRttEstimate_OnNavigationStartName[];
  static constexpr uint64_t kNet_TransportRttEstimate_OnNavigationStartNameHash = UINT64_C(1015883933811308473);
  PageLoad& SetNet_TransportRttEstimate_OnNavigationStart(int64_t value);

  static const char kPageTiming_ForegroundDurationName[];
  static constexpr uint64_t kPageTiming_ForegroundDurationNameHash = UINT64_C(2843257204381097865);
  PageLoad& SetPageTiming_ForegroundDuration(int64_t value);

  static const char kPageTiming_NavigationToFailedProvisionalLoadName[];
  static constexpr uint64_t kPageTiming_NavigationToFailedProvisionalLoadNameHash = UINT64_C(11986312636689853254);
  PageLoad& SetPageTiming_NavigationToFailedProvisionalLoad(int64_t value);

  static const char kPaintTiming_NavigationToExperimentalLargestContentfulPaintName[];
  static constexpr uint64_t kPaintTiming_NavigationToExperimentalLargestContentfulPaintNameHash = UINT64_C(11962117189652864404);
  PageLoad& SetPaintTiming_NavigationToExperimentalLargestContentfulPaint(int64_t value);

  static const char kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameName[];
  static constexpr uint64_t kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameNameHash = UINT64_C(7103264932008649048);
  PageLoad& SetPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrame(int64_t value);

  static const char kPaintTiming_NavigationToFirstContentfulPaintName[];
  static constexpr uint64_t kPaintTiming_NavigationToFirstContentfulPaintNameHash = UINT64_C(8518716400092239089);
  PageLoad& SetPaintTiming_NavigationToFirstContentfulPaint(int64_t value);

  static const char kPaintTiming_NavigationToFirstPaintName[];
  static constexpr uint64_t kPaintTiming_NavigationToFirstPaintNameHash = UINT64_C(7259095400115977984);
  PageLoad& SetPaintTiming_NavigationToFirstPaint(int64_t value);

  static const char kPaintTiming_NavigationToLargestContentfulPaintName[];
  static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaintNameHash = UINT64_C(2541572237502750312);
  PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint(int64_t value);

  static const char kPaintTiming_NavigationToLargestContentfulPaint_MainFrameName[];
  static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaint_MainFrameNameHash = UINT64_C(110015268269975783);
  PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint_MainFrame(int64_t value);

  static const char kParseTiming_NavigationToParseStartName[];
  static constexpr uint64_t kParseTiming_NavigationToParseStartNameHash = UINT64_C(13847075934787644884);
  PageLoad& SetParseTiming_NavigationToParseStart(int64_t value);

  static const char kSiteEngagementScoreName[];
  static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
  PageLoad& SetSiteEngagementScore(int64_t value);

  static const char kThirdPartyCookieBlockingEnabledForSiteName[];
  static constexpr uint64_t kThirdPartyCookieBlockingEnabledForSiteNameHash = UINT64_C(440600315450942530);
  PageLoad& SetThirdPartyCookieBlockingEnabledForSite(int64_t value);

  static const char kWasCachedName[];
  static constexpr uint64_t kWasCachedNameHash = UINT64_C(8288453355921177151);
  PageLoad& SetWasCached(int64_t value);

};

class PageLoad_FromGoogleSearch final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageLoad_FromGoogleSearch(ukm::SourceId source_id);
  explicit PageLoad_FromGoogleSearch(base::UkmSourceId source_id);
  ~PageLoad_FromGoogleSearch() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8384138607730558665);


};

class PageLoad_Internal final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageLoad_Internal(ukm::SourceId source_id);
  explicit PageLoad_Internal(base::UkmSourceId source_id);
  ~PageLoad_Internal() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5441732143890651748);


  static const char kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeName[];
  static constexpr uint64_t kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeNameHash = UINT64_C(2569577768105358307);
  PageLoad_Internal& SetPaintTiming_ExperimentalLargestContentfulPaint_ContentType(int64_t value);

  static const char kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateName[];
  static constexpr uint64_t kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateNameHash = UINT64_C(12558832176402100504);
  PageLoad_Internal& SetPaintTiming_ExperimentalLargestContentfulPaint_TerminationState(int64_t value);

  static const char kPaintTiming_LargestContentfulPaint_ContentTypeName[];
  static constexpr uint64_t kPaintTiming_LargestContentfulPaint_ContentTypeNameHash = UINT64_C(16724376080307984909);
  PageLoad_Internal& SetPaintTiming_LargestContentfulPaint_ContentType(int64_t value);

  static const char kPaintTiming_LargestContentfulPaint_TerminationStateName[];
  static constexpr uint64_t kPaintTiming_LargestContentfulPaint_TerminationStateNameHash = UINT64_C(5926365039165737690);
  PageLoad_Internal& SetPaintTiming_LargestContentfulPaint_TerminationState(int64_t value);

};

class PageLoad_ServiceWorkerControlled final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageLoad_ServiceWorkerControlled(ukm::SourceId source_id);
  explicit PageLoad_ServiceWorkerControlled(base::UkmSourceId source_id);
  ~PageLoad_ServiceWorkerControlled() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18067304287773255026);


};

class PageLoad_SignedExchange final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageLoad_SignedExchange(ukm::SourceId source_id);
  explicit PageLoad_SignedExchange(base::UkmSourceId source_id);
  ~PageLoad_SignedExchange() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14566014450078110818);


  static const char kServedFromGoogleCacheName[];
  static constexpr uint64_t kServedFromGoogleCacheNameHash = UINT64_C(17732685549292242683);
  PageLoad_SignedExchange& SetServedFromGoogleCache(int64_t value);

};

class PageWithPassword final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PageWithPassword(ukm::SourceId source_id);
  explicit PageWithPassword(base::UkmSourceId source_id);
  ~PageWithPassword() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2493630448790526384);


  static const char kFormManagerAvailableName[];
  static constexpr uint64_t kFormManagerAvailableNameHash = UINT64_C(16068659807803166350);
  PageWithPassword& SetFormManagerAvailable(int64_t value);

  static const char kPageLevelUserActionName[];
  static constexpr uint64_t kPageLevelUserActionNameHash = UINT64_C(10977249896159391035);
  PageWithPassword& SetPageLevelUserAction(int64_t value);

  static const char kProvisionalSaveFailureName[];
  static constexpr uint64_t kProvisionalSaveFailureNameHash = UINT64_C(7470710753863609401);
  PageWithPassword& SetProvisionalSaveFailure(int64_t value);

  static const char kUserModifiedPasswordFieldName[];
  static constexpr uint64_t kUserModifiedPasswordFieldNameHash = UINT64_C(2714307025842210332);
  PageWithPassword& SetUserModifiedPasswordField(int64_t value);

};

class PaintPreviewCapture final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PaintPreviewCapture(ukm::SourceId source_id);
  explicit PaintPreviewCapture(base::UkmSourceId source_id);
  ~PaintPreviewCapture() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(1595630084981618121);


  static const char kBlinkCaptureTimeName[];
  static constexpr uint64_t kBlinkCaptureTimeNameHash = UINT64_C(6510140679687069140);
  PaintPreviewCapture& SetBlinkCaptureTime(int64_t value);

  static const char kCompressedOnDiskSizeName[];
  static constexpr uint64_t kCompressedOnDiskSizeNameHash = UINT64_C(12971499806185141047);
  PaintPreviewCapture& SetCompressedOnDiskSize(int64_t value);

};

class PasswordForm final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PasswordForm(ukm::SourceId source_id);
  explicit PasswordForm(base::UkmSourceId source_id);
  ~PasswordForm() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8060270586115376858);


  static const char kContext_FormSignatureName[];
  static constexpr uint64_t kContext_FormSignatureNameHash = UINT64_C(7963393494324030143);
  PasswordForm& SetContext_FormSignature(int64_t value);

  static const char kDynamicFormChangesName[];
  static constexpr uint64_t kDynamicFormChangesNameHash = UINT64_C(2597861915893901769);
  PasswordForm& SetDynamicFormChanges(int64_t value);

  static const char kFill_FirstFillingResultInRendererName[];
  static constexpr uint64_t kFill_FirstFillingResultInRendererNameHash = UINT64_C(2520810486634620725);
  PasswordForm& SetFill_FirstFillingResultInRenderer(int64_t value);

  static const char kFill_FirstWaitForUsernameReasonName[];
  static constexpr uint64_t kFill_FirstWaitForUsernameReasonNameHash = UINT64_C(7438807842425949182);
  PasswordForm& SetFill_FirstWaitForUsernameReason(int64_t value);

  static const char kFillOnLoadName[];
  static constexpr uint64_t kFillOnLoadNameHash = UINT64_C(11910685083216950873);
  PasswordForm& SetFillOnLoad(int64_t value);

  static const char kGeneration_GeneratedPasswordName[];
  static constexpr uint64_t kGeneration_GeneratedPasswordNameHash = UINT64_C(63581670180275077);
  PasswordForm& SetGeneration_GeneratedPassword(int64_t value);

  static const char kGeneration_GeneratedPasswordModifiedName[];
  static constexpr uint64_t kGeneration_GeneratedPasswordModifiedNameHash = UINT64_C(2019134969922041879);
  PasswordForm& SetGeneration_GeneratedPasswordModified(int64_t value);

  static const char kGeneration_PopupShownName[];
  static constexpr uint64_t kGeneration_PopupShownNameHash = UINT64_C(3779268428021661864);
  PasswordForm& SetGeneration_PopupShown(int64_t value);

  static const char kManagerFill_ActionName[];
  static constexpr uint64_t kManagerFill_ActionNameHash = UINT64_C(10479452804440058134);
  PasswordForm& SetManagerFill_Action(int64_t value);

  static const char kManagerFill_AssistanceName[];
  static constexpr uint64_t kManagerFill_AssistanceNameHash = UINT64_C(8134193492903112186);
  PasswordForm& SetManagerFill_Assistance(int64_t value);

  static const char kReadonlyWhenFillingName[];
  static constexpr uint64_t kReadonlyWhenFillingNameHash = UINT64_C(4514761882709205318);
  PasswordForm& SetReadonlyWhenFilling(int64_t value);

  static const char kReadonlyWhenSavingName[];
  static constexpr uint64_t kReadonlyWhenSavingNameHash = UINT64_C(3695413570360800308);
  PasswordForm& SetReadonlyWhenSaving(int64_t value);

  static const char kSaving_Prompt_InteractionName[];
  static constexpr uint64_t kSaving_Prompt_InteractionNameHash = UINT64_C(11260027812017306962);
  PasswordForm& SetSaving_Prompt_Interaction(int64_t value);

  static const char kSaving_Prompt_ShownName[];
  static constexpr uint64_t kSaving_Prompt_ShownNameHash = UINT64_C(17150803645879521558);
  PasswordForm& SetSaving_Prompt_Shown(int64_t value);

  static const char kSaving_Prompt_TriggerName[];
  static constexpr uint64_t kSaving_Prompt_TriggerNameHash = UINT64_C(14370044635698072654);
  PasswordForm& SetSaving_Prompt_Trigger(int64_t value);

  static const char kSaving_ShowedManualFallbackForSavingName[];
  static constexpr uint64_t kSaving_ShowedManualFallbackForSavingNameHash = UINT64_C(1380853887219072743);
  PasswordForm& SetSaving_ShowedManualFallbackForSaving(int64_t value);

  static const char kSubmission_IndicatorName[];
  static constexpr uint64_t kSubmission_IndicatorNameHash = UINT64_C(2585760809099691441);
  PasswordForm& SetSubmission_Indicator(int64_t value);

  static const char kSubmission_ObservedName[];
  static constexpr uint64_t kSubmission_ObservedNameHash = UINT64_C(4515933539223991436);
  PasswordForm& SetSubmission_Observed(int64_t value);

  static const char kSubmission_SubmissionResultName[];
  static constexpr uint64_t kSubmission_SubmissionResultNameHash = UINT64_C(15247671546925217641);
  PasswordForm& SetSubmission_SubmissionResult(int64_t value);

  static const char kSubmission_SubmittedFormTypeName[];
  static constexpr uint64_t kSubmission_SubmittedFormTypeNameHash = UINT64_C(9111877994358158676);
  PasswordForm& SetSubmission_SubmittedFormType(int64_t value);

  static const char kUpdating_Prompt_InteractionName[];
  static constexpr uint64_t kUpdating_Prompt_InteractionNameHash = UINT64_C(14320711380061622942);
  PasswordForm& SetUpdating_Prompt_Interaction(int64_t value);

  static const char kUpdating_Prompt_ShownName[];
  static constexpr uint64_t kUpdating_Prompt_ShownNameHash = UINT64_C(17781634715365209800);
  PasswordForm& SetUpdating_Prompt_Shown(int64_t value);

  static const char kUpdating_Prompt_TriggerName[];
  static constexpr uint64_t kUpdating_Prompt_TriggerNameHash = UINT64_C(15209183178715629827);
  PasswordForm& SetUpdating_Prompt_Trigger(int64_t value);

  static const char kUser_Action_CorrectedUsernameInFormName[];
  static constexpr uint64_t kUser_Action_CorrectedUsernameInFormNameHash = UINT64_C(7751416161539292552);
  PasswordForm& SetUser_Action_CorrectedUsernameInForm(int64_t value);

  static const char kUser_Action_EditedUsernameInBubbleName[];
  static constexpr uint64_t kUser_Action_EditedUsernameInBubbleNameHash = UINT64_C(10966659704643359477);
  PasswordForm& SetUser_Action_EditedUsernameInBubble(int64_t value);

  static const char kUser_Action_SelectedDifferentPasswordInBubbleName[];
  static constexpr uint64_t kUser_Action_SelectedDifferentPasswordInBubbleNameHash = UINT64_C(6311303221302518030);
  PasswordForm& SetUser_Action_SelectedDifferentPasswordInBubble(int64_t value);

  static const char kUser_Action_TriggeredManualFallbackForSavingName[];
  static constexpr uint64_t kUser_Action_TriggeredManualFallbackForSavingNameHash = UINT64_C(2587019996419876036);
  PasswordForm& SetUser_Action_TriggeredManualFallbackForSaving(int64_t value);

};

class PaymentApp_CheckoutEvents final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PaymentApp_CheckoutEvents(ukm::SourceId source_id);
  explicit PaymentApp_CheckoutEvents(base::UkmSourceId source_id);
  ~PaymentApp_CheckoutEvents() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(702207440764833882);


  static const char kCompletionStatusName[];
  static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
  PaymentApp_CheckoutEvents& SetCompletionStatus(int64_t value);

  static const char kEventsName[];
  static constexpr uint64_t kEventsNameHash = UINT64_C(9798134274041538451);
  PaymentApp_CheckoutEvents& SetEvents(int64_t value);

};

class PaymentRequest_CheckoutEvents final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PaymentRequest_CheckoutEvents(ukm::SourceId source_id);
  explicit PaymentRequest_CheckoutEvents(base::UkmSourceId source_id);
  ~PaymentRequest_CheckoutEvents() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9066413457122162526);


  static const char kCompletionStatusName[];
  static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
  PaymentRequest_CheckoutEvents& SetCompletionStatus(int64_t value);

  static const char kEventsName[];
  static constexpr uint64_t kEventsNameHash = UINT64_C(9798134274041538451);
  PaymentRequest_CheckoutEvents& SetEvents(int64_t value);

};

class PaymentRequest_TransactionAmount final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PaymentRequest_TransactionAmount(ukm::SourceId source_id);
  explicit PaymentRequest_TransactionAmount(base::UkmSourceId source_id);
  ~PaymentRequest_TransactionAmount() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4090736682116197688);


  static const char kCategoryName[];
  static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
  PaymentRequest_TransactionAmount& SetCategory(int64_t value);

  static const char kCompletionStatusName[];
  static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
  PaymentRequest_TransactionAmount& SetCompletionStatus(int64_t value);

};

class Pepper_Broker final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Pepper_Broker(ukm::SourceId source_id);
  explicit Pepper_Broker(base::UkmSourceId source_id);
  ~Pepper_Broker() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4863880088883807024);


};

class PeriodicBackgroundSyncEventCompleted final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PeriodicBackgroundSyncEventCompleted(ukm::SourceId source_id);
  explicit PeriodicBackgroundSyncEventCompleted(base::UkmSourceId source_id);
  ~PeriodicBackgroundSyncEventCompleted() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10863131082725230381);


  static const char kMaxAttemptsName[];
  static constexpr uint64_t kMaxAttemptsNameHash = UINT64_C(13811216186026220346);
  PeriodicBackgroundSyncEventCompleted& SetMaxAttempts(int64_t value);

  static const char kNumAttemptsName[];
  static constexpr uint64_t kNumAttemptsNameHash = UINT64_C(537979731801272247);
  PeriodicBackgroundSyncEventCompleted& SetNumAttempts(int64_t value);

  static const char kStatusName[];
  static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
  PeriodicBackgroundSyncEventCompleted& SetStatus(int64_t value);

};

class PeriodicBackgroundSyncRegistered final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PeriodicBackgroundSyncRegistered(ukm::SourceId source_id);
  explicit PeriodicBackgroundSyncRegistered(base::UkmSourceId source_id);
  ~PeriodicBackgroundSyncRegistered() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8211654418406942912);


  static const char kIsReregisteredName[];
  static constexpr uint64_t kIsReregisteredNameHash = UINT64_C(10082741689941820461);
  PeriodicBackgroundSyncRegistered& SetIsReregistered(int64_t value);

  static const char kMinIntervalMsName[];
  static constexpr uint64_t kMinIntervalMsNameHash = UINT64_C(11330617392665034633);
  PeriodicBackgroundSyncRegistered& SetMinIntervalMs(int64_t value);

};

class Permission final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Permission(ukm::SourceId source_id);
  explicit Permission(base::UkmSourceId source_id);
  ~Permission() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17104084284355864347);


  static const char kActionName[];
  static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
  Permission& SetAction(int64_t value);

  static const char kGestureName[];
  static constexpr uint64_t kGestureNameHash = UINT64_C(1976985484619472355);
  Permission& SetGesture(int64_t value);

  static const char kPermissionTypeName[];
  static constexpr uint64_t kPermissionTypeNameHash = UINT64_C(12838086084889581840);
  Permission& SetPermissionType(int64_t value);

  static const char kPriorDismissalsName[];
  static constexpr uint64_t kPriorDismissalsNameHash = UINT64_C(9632910442238752479);
  Permission& SetPriorDismissals(int64_t value);

  static const char kPriorIgnoresName[];
  static constexpr uint64_t kPriorIgnoresNameHash = UINT64_C(1762046784113667081);
  Permission& SetPriorIgnores(int64_t value);

  static const char kPromptDispositionName[];
  static constexpr uint64_t kPromptDispositionNameHash = UINT64_C(1320746900446203052);
  Permission& SetPromptDisposition(int64_t value);

  static const char kSourceName[];
  static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
  Permission& SetSource(int64_t value);

};

class Plugins_FlashInstance final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Plugins_FlashInstance(ukm::SourceId source_id);
  explicit Plugins_FlashInstance(base::UkmSourceId source_id);
  ~Plugins_FlashInstance() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2851782918499658607);


};

class Popup_Closed final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Popup_Closed(ukm::SourceId source_id);
  explicit Popup_Closed(base::UkmSourceId source_id);
  ~Popup_Closed() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5373577291340314501);


  static const char kEngagementTimeName[];
  static constexpr uint64_t kEngagementTimeNameHash = UINT64_C(5757927903187539607);
  Popup_Closed& SetEngagementTime(int64_t value);

  static const char kNumActivationInteractionsName[];
  static constexpr uint64_t kNumActivationInteractionsNameHash = UINT64_C(1968290450355139412);
  Popup_Closed& SetNumActivationInteractions(int64_t value);

  static const char kNumGestureScrollBeginInteractionsName[];
  static constexpr uint64_t kNumGestureScrollBeginInteractionsNameHash = UINT64_C(16455411608912728271);
  Popup_Closed& SetNumGestureScrollBeginInteractions(int64_t value);

  static const char kNumInteractionsName[];
  static constexpr uint64_t kNumInteractionsNameHash = UINT64_C(5654420946245687695);
  Popup_Closed& SetNumInteractions(int64_t value);

  static const char kSafeBrowsingStatusName[];
  static constexpr uint64_t kSafeBrowsingStatusNameHash = UINT64_C(9647052102537443981);
  Popup_Closed& SetSafeBrowsingStatus(int64_t value);

  static const char kTrustedName[];
  static constexpr uint64_t kTrustedNameHash = UINT64_C(13853175197766416028);
  Popup_Closed& SetTrusted(int64_t value);

  static const char kUserInitiatedCloseName[];
  static constexpr uint64_t kUserInitiatedCloseNameHash = UINT64_C(16452490512765540245);
  Popup_Closed& SetUserInitiatedClose(int64_t value);

  static const char kWindowOpenDispositionName[];
  static constexpr uint64_t kWindowOpenDispositionNameHash = UINT64_C(17804395139469765033);
  Popup_Closed& SetWindowOpenDisposition(int64_t value);

};

class Popup_Page final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Popup_Page(ukm::SourceId source_id);
  explicit Popup_Page(base::UkmSourceId source_id);
  ~Popup_Page() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(9277003375443527515);


  static const char kAllowedName[];
  static constexpr uint64_t kAllowedNameHash = UINT64_C(13501762879137544078);
  Popup_Page& SetAllowed(int64_t value);

};

class Portal_Activate final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Portal_Activate(ukm::SourceId source_id);
  explicit Portal_Activate(base::UkmSourceId source_id);
  ~Portal_Activate() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(570650911258459707);


  static const char kPaintTiming_PortalActivationToFirstPaintName[];
  static constexpr uint64_t kPaintTiming_PortalActivationToFirstPaintNameHash = UINT64_C(10350998418336997145);
  Portal_Activate& SetPaintTiming_PortalActivationToFirstPaint(int64_t value);

  static const char kPortalActivationName[];
  static constexpr uint64_t kPortalActivationNameHash = UINT64_C(4430962806322008522);
  Portal_Activate& SetPortalActivation(int64_t value);

  static const char kPortalActivationBeforeLCPName[];
  static constexpr uint64_t kPortalActivationBeforeLCPNameHash = UINT64_C(16175379994101710778);
  Portal_Activate& SetPortalActivationBeforeLCP(int64_t value);

};

class PrefetchProxy final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PrefetchProxy(ukm::SourceId source_id);
  explicit PrefetchProxy(base::UkmSourceId source_id);
  ~PrefetchProxy() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11352241752715206016);


  static const char kcount_css_js_loaded_cache_before_fcpName[];
  static constexpr uint64_t kcount_css_js_loaded_cache_before_fcpNameHash = UINT64_C(9275202528456063142);
  PrefetchProxy& Setcount_css_js_loaded_cache_before_fcp(int64_t value);

  static const char kcount_css_js_loaded_network_before_fcpName[];
  static constexpr uint64_t kcount_css_js_loaded_network_before_fcpNameHash = UINT64_C(15794213686734490645);
  PrefetchProxy& Setcount_css_js_loaded_network_before_fcp(int64_t value);

  static const char kdays_since_last_visit_to_originName[];
  static constexpr uint64_t kdays_since_last_visit_to_originNameHash = UINT64_C(210860424475155511);
  PrefetchProxy& Setdays_since_last_visit_to_origin(int64_t value);

  static const char kmainpage_request_had_cookiesName[];
  static constexpr uint64_t kmainpage_request_had_cookiesNameHash = UINT64_C(17839494076012608904);
  PrefetchProxy& Setmainpage_request_had_cookies(int64_t value);

  static const char kordered_eligible_pages_bitmaskName[];
  static constexpr uint64_t kordered_eligible_pages_bitmaskNameHash = UINT64_C(14872200826846551039);
  PrefetchProxy& Setordered_eligible_pages_bitmask(int64_t value);

  static const char kprefetch_attempted_countName[];
  static constexpr uint64_t kprefetch_attempted_countNameHash = UINT64_C(14009054735640351019);
  PrefetchProxy& Setprefetch_attempted_count(int64_t value);

  static const char kprefetch_eligible_countName[];
  static constexpr uint64_t kprefetch_eligible_countNameHash = UINT64_C(2248218164746653975);
  PrefetchProxy& Setprefetch_eligible_count(int64_t value);

  static const char kprefetch_successful_countName[];
  static constexpr uint64_t kprefetch_successful_countNameHash = UINT64_C(13378708688148375022);
  PrefetchProxy& Setprefetch_successful_count(int64_t value);

};

class PrefetchProxy_AfterSRPClick final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PrefetchProxy_AfterSRPClick(ukm::SourceId source_id);
  explicit PrefetchProxy_AfterSRPClick(base::UkmSourceId source_id);
  ~PrefetchProxy_AfterSRPClick() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6674705951757661648);


  static const char kClickedLinkSRPPositionName[];
  static constexpr uint64_t kClickedLinkSRPPositionNameHash = UINT64_C(6517804828846600668);
  PrefetchProxy_AfterSRPClick& SetClickedLinkSRPPosition(int64_t value);

  static const char kProbeLatencyMsName[];
  static constexpr uint64_t kProbeLatencyMsNameHash = UINT64_C(8004524944946139403);
  PrefetchProxy_AfterSRPClick& SetProbeLatencyMs(int64_t value);

  static const char kSRPClickPrefetchStatusName[];
  static constexpr uint64_t kSRPClickPrefetchStatusNameHash = UINT64_C(7878335820719982043);
  PrefetchProxy_AfterSRPClick& SetSRPClickPrefetchStatus(int64_t value);

  static const char kSRPPrefetchEligibleCountName[];
  static constexpr uint64_t kSRPPrefetchEligibleCountNameHash = UINT64_C(12605281584920932061);
  PrefetchProxy_AfterSRPClick& SetSRPPrefetchEligibleCount(int64_t value);

};

class Previews final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Previews(ukm::SourceId source_id);
  explicit Previews(base::UkmSourceId source_id);
  ~Previews() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16176000469846917671);


  static const char kdefer_all_scriptName[];
  static constexpr uint64_t kdefer_all_scriptNameHash = UINT64_C(6358776468279324838);
  Previews& Setdefer_all_script(int64_t value);

  static const char kdefer_all_script_eligibility_reasonName[];
  static constexpr uint64_t kdefer_all_script_eligibility_reasonNameHash = UINT64_C(9159831810423580601);
  Previews& Setdefer_all_script_eligibility_reason(int64_t value);

  static const char klite_pageName[];
  static constexpr uint64_t klite_pageNameHash = UINT64_C(3925409904844646530);
  Previews& Setlite_page(int64_t value);

  static const char knoscriptName[];
  static constexpr uint64_t knoscriptNameHash = UINT64_C(1356908301518096793);
  Previews& Setnoscript(int64_t value);

  static const char knoscript_eligibility_reasonName[];
  static constexpr uint64_t knoscript_eligibility_reasonNameHash = UINT64_C(1885840407684820961);
  Previews& Setnoscript_eligibility_reason(int64_t value);

  static const char koffline_eligibility_reasonName[];
  static constexpr uint64_t koffline_eligibility_reasonNameHash = UINT64_C(704080074362319387);
  Previews& Setoffline_eligibility_reason(int64_t value);

  static const char koffline_previewName[];
  static constexpr uint64_t koffline_previewNameHash = UINT64_C(9862310335779980599);
  Previews& Setoffline_preview(int64_t value);

  static const char kopt_outName[];
  static constexpr uint64_t kopt_outNameHash = UINT64_C(7653551929040476);
  Previews& Setopt_out(int64_t value);

  static const char korigin_opt_outName[];
  static constexpr uint64_t korigin_opt_outNameHash = UINT64_C(17747894928105999622);
  Previews& Setorigin_opt_out(int64_t value);

  static const char kpreviews_likelyName[];
  static constexpr uint64_t kpreviews_likelyNameHash = UINT64_C(449278115406924978);
  Previews& Setpreviews_likely(int64_t value);

  static const char kproxy_lite_page_eligibility_reasonName[];
  static constexpr uint64_t kproxy_lite_page_eligibility_reasonNameHash = UINT64_C(16994112623800223750);
  Previews& Setproxy_lite_page_eligibility_reason(int64_t value);

  static const char kresource_loading_hintsName[];
  static constexpr uint64_t kresource_loading_hintsNameHash = UINT64_C(16619360579310371651);
  Previews& Setresource_loading_hints(int64_t value);

  static const char kresource_loading_hints_eligibility_reasonName[];
  static constexpr uint64_t kresource_loading_hints_eligibility_reasonNameHash = UINT64_C(17156186789450221785);
  Previews& Setresource_loading_hints_eligibility_reason(int64_t value);

  static const char ksave_data_enabledName[];
  static constexpr uint64_t ksave_data_enabledNameHash = UINT64_C(1653640859566235189);
  Previews& Setsave_data_enabled(int64_t value);

};

class PreviewsCoinFlip final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PreviewsCoinFlip(ukm::SourceId source_id);
  explicit PreviewsCoinFlip(base::UkmSourceId source_id);
  ~PreviewsCoinFlip() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6691626505896909380);


  static const char kcoin_flip_resultName[];
  static constexpr uint64_t kcoin_flip_resultNameHash = UINT64_C(11028333896747524705);
  PreviewsCoinFlip& Setcoin_flip_result(int64_t value);

};

class PreviewsDeferAllScript final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PreviewsDeferAllScript(ukm::SourceId source_id);
  explicit PreviewsDeferAllScript(base::UkmSourceId source_id);
  ~PreviewsDeferAllScript() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2545987494366395841);


  static const char kforce_deferred_scripts_mainframeName[];
  static constexpr uint64_t kforce_deferred_scripts_mainframeNameHash = UINT64_C(6563017857442431099);
  PreviewsDeferAllScript& Setforce_deferred_scripts_mainframe(int64_t value);

  static const char kforce_deferred_scripts_mainframe_externalName[];
  static constexpr uint64_t kforce_deferred_scripts_mainframe_externalNameHash = UINT64_C(4623436866560601617);
  PreviewsDeferAllScript& Setforce_deferred_scripts_mainframe_external(int64_t value);

};

class PreviewsResourceLoadingHints final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PreviewsResourceLoadingHints(ukm::SourceId source_id);
  explicit PreviewsResourceLoadingHints(base::UkmSourceId source_id);
  ~PreviewsResourceLoadingHints() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2128752535034967467);


  static const char kblocked_high_priorityName[];
  static constexpr uint64_t kblocked_high_priorityNameHash = UINT64_C(2055742149003029351);
  PreviewsResourceLoadingHints& Setblocked_high_priority(int64_t value);

  static const char kblocked_low_priorityName[];
  static constexpr uint64_t kblocked_low_priorityNameHash = UINT64_C(12006040971230508101);
  PreviewsResourceLoadingHints& Setblocked_low_priority(int64_t value);

  static const char kblocked_medium_priorityName[];
  static constexpr uint64_t kblocked_medium_priorityNameHash = UINT64_C(4407860666517220456);
  PreviewsResourceLoadingHints& Setblocked_medium_priority(int64_t value);

  static const char kblocked_very_high_priorityName[];
  static constexpr uint64_t kblocked_very_high_priorityNameHash = UINT64_C(17444171317262115905);
  PreviewsResourceLoadingHints& Setblocked_very_high_priority(int64_t value);

  static const char kblocked_very_low_priorityName[];
  static constexpr uint64_t kblocked_very_low_priorityNameHash = UINT64_C(7421720114509582048);
  PreviewsResourceLoadingHints& Setblocked_very_low_priority(int64_t value);

  static const char kpatterns_to_block_totalName[];
  static constexpr uint64_t kpatterns_to_block_totalNameHash = UINT64_C(7008272372423664292);
  PreviewsResourceLoadingHints& Setpatterns_to_block_total(int64_t value);

  static const char kpatterns_to_block_usedName[];
  static constexpr uint64_t kpatterns_to_block_usedNameHash = UINT64_C(15063357435345229670);
  PreviewsResourceLoadingHints& Setpatterns_to_block_used(int64_t value);

};

class PublicImageCompressionDataUse final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PublicImageCompressionDataUse(ukm::SourceId source_id);
  explicit PublicImageCompressionDataUse(base::UkmSourceId source_id);
  ~PublicImageCompressionDataUse() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10398495362201261089);


  static const char kCompressibleImageBytesName[];
  static constexpr uint64_t kCompressibleImageBytesNameHash = UINT64_C(8749575241013944733);
  PublicImageCompressionDataUse& SetCompressibleImageBytes(int64_t value);

  static const char kIneligibleImageHintsUnavailableAndMissingInHintsBytesName[];
  static constexpr uint64_t kIneligibleImageHintsUnavailableAndMissingInHintsBytesNameHash = UINT64_C(9298495923812634018);
  PublicImageCompressionDataUse& SetIneligibleImageHintsUnavailableAndMissingInHintsBytes(int64_t value);

  static const char kIneligibleImageHintsUnavailableButCompressibleBytesName[];
  static constexpr uint64_t kIneligibleImageHintsUnavailableButCompressibleBytesNameHash = UINT64_C(8173649068346122036);
  PublicImageCompressionDataUse& SetIneligibleImageHintsUnavailableButCompressibleBytes(int64_t value);

  static const char kIneligibleImageHintsUnavailableBytesName[];
  static constexpr uint64_t kIneligibleImageHintsUnavailableBytesNameHash = UINT64_C(13746534244307313929);
  PublicImageCompressionDataUse& SetIneligibleImageHintsUnavailableBytes(int64_t value);

  static const char kIneligibleMissingInImageHintsBytesName[];
  static constexpr uint64_t kIneligibleMissingInImageHintsBytesNameHash = UINT64_C(18222194984947673811);
  PublicImageCompressionDataUse& SetIneligibleMissingInImageHintsBytes(int64_t value);

  static const char kIneligibleOtherImageBytesName[];
  static constexpr uint64_t kIneligibleOtherImageBytesNameHash = UINT64_C(15301668612610554423);
  PublicImageCompressionDataUse& SetIneligibleOtherImageBytes(int64_t value);

};

class PWA_Visit final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit PWA_Visit(ukm::SourceId source_id);
  explicit PWA_Visit(base::UkmSourceId source_id);
  ~PWA_Visit() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4791378639615025150);


  static const char kLaunchSourceName[];
  static constexpr uint64_t kLaunchSourceNameHash = UINT64_C(5360095524695749322);
  PWA_Visit& SetLaunchSource(int64_t value);

  static const char kWebAPKableSiteVisitName[];
  static constexpr uint64_t kWebAPKableSiteVisitNameHash = UINT64_C(4362561697839438819);
  PWA_Visit& SetWebAPKableSiteVisit(int64_t value);

};

class ReaderModeActivated final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ReaderModeActivated(ukm::SourceId source_id);
  explicit ReaderModeActivated(base::UkmSourceId source_id);
  ~ReaderModeActivated() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15014052365473894052);


  static const char kActivatedViaOmniboxName[];
  static constexpr uint64_t kActivatedViaOmniboxNameHash = UINT64_C(2176968808273118322);
  ReaderModeActivated& SetActivatedViaOmnibox(int64_t value);

};

class ReaderModeReceivedDistillability final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ReaderModeReceivedDistillability(ukm::SourceId source_id);
  explicit ReaderModeReceivedDistillability(base::UkmSourceId source_id);
  ~ReaderModeReceivedDistillability() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3308537368968335608);


  static const char kIsPageDistillableName[];
  static constexpr uint64_t kIsPageDistillableNameHash = UINT64_C(6232477014927662300);
  ReaderModeReceivedDistillability& SetIsPageDistillable(int64_t value);

};

class RendererSchedulerTask final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit RendererSchedulerTask(ukm::SourceId source_id);
  explicit RendererSchedulerTask(base::UkmSourceId source_id);
  ~RendererSchedulerTask() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18249372845339521807);


  static const char kFrameStatusName[];
  static constexpr uint64_t kFrameStatusNameHash = UINT64_C(8127006928817986898);
  RendererSchedulerTask& SetFrameStatus(int64_t value);

  static const char kIsOOPIFName[];
  static constexpr uint64_t kIsOOPIFNameHash = UINT64_C(4026879053974581447);
  RendererSchedulerTask& SetIsOOPIF(int64_t value);

  static const char kPageSchedulersName[];
  static constexpr uint64_t kPageSchedulersNameHash = UINT64_C(11770126887694907943);
  RendererSchedulerTask& SetPageSchedulers(int64_t value);

  static const char kQueueTypeName[];
  static constexpr uint64_t kQueueTypeNameHash = UINT64_C(11208877159905152236);
  RendererSchedulerTask& SetQueueType(int64_t value);

  static const char kRendererAudibleName[];
  static constexpr uint64_t kRendererAudibleNameHash = UINT64_C(4748648681023634603);
  RendererSchedulerTask& SetRendererAudible(int64_t value);

  static const char kRendererBackgroundedName[];
  static constexpr uint64_t kRendererBackgroundedNameHash = UINT64_C(7540850391372337744);
  RendererSchedulerTask& SetRendererBackgrounded(int64_t value);

  static const char kRendererHiddenName[];
  static constexpr uint64_t kRendererHiddenNameHash = UINT64_C(4143722852895683235);
  RendererSchedulerTask& SetRendererHidden(int64_t value);

  static const char kSecondsSinceBackgroundedName[];
  static constexpr uint64_t kSecondsSinceBackgroundedNameHash = UINT64_C(11822329391758215615);
  RendererSchedulerTask& SetSecondsSinceBackgrounded(int64_t value);

  static const char kTaskCPUDurationName[];
  static constexpr uint64_t kTaskCPUDurationNameHash = UINT64_C(16455678090173301579);
  RendererSchedulerTask& SetTaskCPUDuration(int64_t value);

  static const char kTaskDurationName[];
  static constexpr uint64_t kTaskDurationNameHash = UINT64_C(3339793303415972546);
  RendererSchedulerTask& SetTaskDuration(int64_t value);

  static const char kTaskTypeName[];
  static constexpr uint64_t kTaskTypeNameHash = UINT64_C(12639142331433684509);
  RendererSchedulerTask& SetTaskType(int64_t value);

  static const char kThreadTypeName[];
  static constexpr uint64_t kThreadTypeNameHash = UINT64_C(16336169703352190142);
  RendererSchedulerTask& SetThreadType(int64_t value);

  static const char kUseCaseName[];
  static constexpr uint64_t kUseCaseNameHash = UINT64_C(10388051568539810908);
  RendererSchedulerTask& SetUseCase(int64_t value);

  static const char kVersionName[];
  static constexpr uint64_t kVersionNameHash = UINT64_C(3798449238516105146);
  RendererSchedulerTask& SetVersion(int64_t value);

};

class ResponsivenessMeasurement final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ResponsivenessMeasurement(ukm::SourceId source_id);
  explicit ResponsivenessMeasurement(base::UkmSourceId source_id);
  ~ResponsivenessMeasurement() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6628044799783508745);


  static const char kExpectedTaskQueueingDurationName[];
  static constexpr uint64_t kExpectedTaskQueueingDurationNameHash = UINT64_C(17505273149654010352);
  ResponsivenessMeasurement& SetExpectedTaskQueueingDuration(int64_t value);

};

class SameSiteDifferentSchemeRequest final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SameSiteDifferentSchemeRequest(ukm::SourceId source_id);
  explicit SameSiteDifferentSchemeRequest(base::UkmSourceId source_id);
  ~SameSiteDifferentSchemeRequest() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(14016795862258924641);


};

class SameSiteDifferentSchemeResponse final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SameSiteDifferentSchemeResponse(ukm::SourceId source_id);
  explicit SameSiteDifferentSchemeResponse(base::UkmSourceId source_id);
  ~SameSiteDifferentSchemeResponse() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6057282574508536454);


};

class SchemefulSameSiteContextDowngrade final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SchemefulSameSiteContextDowngrade(ukm::SourceId source_id);
  explicit SchemefulSameSiteContextDowngrade(base::UkmSourceId source_id);
  ~SchemefulSameSiteContextDowngrade() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16392896102401488447);


  static const char kRequestPerCookieName[];
  static constexpr uint64_t kRequestPerCookieNameHash = UINT64_C(2434445133551336228);
  SchemefulSameSiteContextDowngrade& SetRequestPerCookie(int64_t value);

  static const char kResponsePerCookieName[];
  static constexpr uint64_t kResponsePerCookieNameHash = UINT64_C(5214101366751624340);
  SchemefulSameSiteContextDowngrade& SetResponsePerCookie(int64_t value);

};

class ScreenBrightness final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit ScreenBrightness(ukm::SourceId source_id);
  explicit ScreenBrightness(base::UkmSourceId source_id);
  ~ScreenBrightness() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(17111718181803892778);


  static const char kBatteryPercentName[];
  static constexpr uint64_t kBatteryPercentNameHash = UINT64_C(3434325767059222004);
  ScreenBrightness& SetBatteryPercent(int64_t value);

  static const char kBrightnessName[];
  static constexpr uint64_t kBrightnessNameHash = UINT64_C(12849653716714311268);
  ScreenBrightness& SetBrightness(int64_t value);

  static const char kDayOfWeekName[];
  static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
  ScreenBrightness& SetDayOfWeek(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  ScreenBrightness& SetDeviceMode(int64_t value);

  static const char kHourOfDayName[];
  static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
  ScreenBrightness& SetHourOfDay(int64_t value);

  static const char kIsAutoclickEnabledName[];
  static constexpr uint64_t kIsAutoclickEnabledNameHash = UINT64_C(12085477661763404958);
  ScreenBrightness& SetIsAutoclickEnabled(int64_t value);

  static const char kIsBrailleDisplayConnectedName[];
  static constexpr uint64_t kIsBrailleDisplayConnectedNameHash = UINT64_C(17405292260030448849);
  ScreenBrightness& SetIsBrailleDisplayConnected(int64_t value);

  static const char kIsCaretHighlightEnabledName[];
  static constexpr uint64_t kIsCaretHighlightEnabledNameHash = UINT64_C(10482296846968056654);
  ScreenBrightness& SetIsCaretHighlightEnabled(int64_t value);

  static const char kIsCursorHighlightEnabledName[];
  static constexpr uint64_t kIsCursorHighlightEnabledNameHash = UINT64_C(2111688606646287289);
  ScreenBrightness& SetIsCursorHighlightEnabled(int64_t value);

  static const char kIsFocusHighlightEnabledName[];
  static constexpr uint64_t kIsFocusHighlightEnabledNameHash = UINT64_C(4772586800047270064);
  ScreenBrightness& SetIsFocusHighlightEnabled(int64_t value);

  static const char kIsHighContrastEnabledName[];
  static constexpr uint64_t kIsHighContrastEnabledNameHash = UINT64_C(374822690988321958);
  ScreenBrightness& SetIsHighContrastEnabled(int64_t value);

  static const char kIsLargeCursorEnabledName[];
  static constexpr uint64_t kIsLargeCursorEnabledNameHash = UINT64_C(1440663063306295171);
  ScreenBrightness& SetIsLargeCursorEnabled(int64_t value);

  static const char kIsMagnifierEnabledName[];
  static constexpr uint64_t kIsMagnifierEnabledNameHash = UINT64_C(6711936056248658535);
  ScreenBrightness& SetIsMagnifierEnabled(int64_t value);

  static const char kIsMonoAudioEnabledName[];
  static constexpr uint64_t kIsMonoAudioEnabledNameHash = UINT64_C(11595411019290590600);
  ScreenBrightness& SetIsMonoAudioEnabled(int64_t value);

  static const char kIsSelectToSpeakEnabledName[];
  static constexpr uint64_t kIsSelectToSpeakEnabledNameHash = UINT64_C(4363348572679012907);
  ScreenBrightness& SetIsSelectToSpeakEnabled(int64_t value);

  static const char kIsSpokenFeedbackEnabledName[];
  static constexpr uint64_t kIsSpokenFeedbackEnabledNameHash = UINT64_C(6400938228896171943);
  ScreenBrightness& SetIsSpokenFeedbackEnabled(int64_t value);

  static const char kIsSwitchAccessEnabledName[];
  static constexpr uint64_t kIsSwitchAccessEnabledNameHash = UINT64_C(1769366891414824383);
  ScreenBrightness& SetIsSwitchAccessEnabled(int64_t value);

  static const char kIsVideoPlayingName[];
  static constexpr uint64_t kIsVideoPlayingNameHash = UINT64_C(1871421023467865761);
  ScreenBrightness& SetIsVideoPlaying(int64_t value);

  static const char kIsVirtualKeyboardEnabledName[];
  static constexpr uint64_t kIsVirtualKeyboardEnabledNameHash = UINT64_C(16129358140694558991);
  ScreenBrightness& SetIsVirtualKeyboardEnabled(int64_t value);

  static const char kLastActivityTimeSecName[];
  static constexpr uint64_t kLastActivityTimeSecNameHash = UINT64_C(2653130242002900914);
  ScreenBrightness& SetLastActivityTimeSec(int64_t value);

  static const char kNightLightTemperaturePercentName[];
  static constexpr uint64_t kNightLightTemperaturePercentNameHash = UINT64_C(10702391938559175141);
  ScreenBrightness& SetNightLightTemperaturePercent(int64_t value);

  static const char kNumRecentKeyEventsName[];
  static constexpr uint64_t kNumRecentKeyEventsNameHash = UINT64_C(17517294973322255376);
  ScreenBrightness& SetNumRecentKeyEvents(int64_t value);

  static const char kNumRecentMouseEventsName[];
  static constexpr uint64_t kNumRecentMouseEventsNameHash = UINT64_C(6164169136009494499);
  ScreenBrightness& SetNumRecentMouseEvents(int64_t value);

  static const char kNumRecentStylusEventsName[];
  static constexpr uint64_t kNumRecentStylusEventsNameHash = UINT64_C(13185006921548112034);
  ScreenBrightness& SetNumRecentStylusEvents(int64_t value);

  static const char kNumRecentTouchEventsName[];
  static constexpr uint64_t kNumRecentTouchEventsNameHash = UINT64_C(14067961327568630776);
  ScreenBrightness& SetNumRecentTouchEvents(int64_t value);

  static const char kOnBatteryName[];
  static constexpr uint64_t kOnBatteryNameHash = UINT64_C(9497943841916154435);
  ScreenBrightness& SetOnBattery(int64_t value);

  static const char kPreviousBrightnessName[];
  static constexpr uint64_t kPreviousBrightnessNameHash = UINT64_C(28161076988593854);
  ScreenBrightness& SetPreviousBrightness(int64_t value);

  static const char kReasonName[];
  static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
  ScreenBrightness& SetReason(int64_t value);

  static const char kRecentTimeActiveSecName[];
  static constexpr uint64_t kRecentTimeActiveSecNameHash = UINT64_C(8488182886786891867);
  ScreenBrightness& SetRecentTimeActiveSec(int64_t value);

  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  ScreenBrightness& SetSequenceId(int64_t value);

  static const char kTimeSinceLastEventSecName[];
  static constexpr uint64_t kTimeSinceLastEventSecNameHash = UINT64_C(8786008257637497412);
  ScreenBrightness& SetTimeSinceLastEventSec(int64_t value);

};

class Security_SafetyTip final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Security_SafetyTip(ukm::SourceId source_id);
  explicit Security_SafetyTip(base::UkmSourceId source_id);
  ~Security_SafetyTip() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(345243929458665883);


  static const char kSafetyTipInteractionName[];
  static constexpr uint64_t kSafetyTipInteractionNameHash = UINT64_C(568933257952179197);
  Security_SafetyTip& SetSafetyTipInteraction(int64_t value);

  static const char kSafetyTipStatusName[];
  static constexpr uint64_t kSafetyTipStatusNameHash = UINT64_C(4178545148842217888);
  Security_SafetyTip& SetSafetyTipStatus(int64_t value);

  static const char kTriggeredKeywordsHeuristicsName[];
  static constexpr uint64_t kTriggeredKeywordsHeuristicsNameHash = UINT64_C(18218625137990774330);
  Security_SafetyTip& SetTriggeredKeywordsHeuristics(int64_t value);

  static const char kTriggeredLookalikeHeuristicsName[];
  static constexpr uint64_t kTriggeredLookalikeHeuristicsNameHash = UINT64_C(17597744927637524893);
  Security_SafetyTip& SetTriggeredLookalikeHeuristics(int64_t value);

  static const char kTriggeredServerSideBlocklistName[];
  static constexpr uint64_t kTriggeredServerSideBlocklistNameHash = UINT64_C(17953907279342391241);
  Security_SafetyTip& SetTriggeredServerSideBlocklist(int64_t value);

  static const char kUserPreviouslyIgnoredName[];
  static constexpr uint64_t kUserPreviouslyIgnoredNameHash = UINT64_C(7110437703924452447);
  Security_SafetyTip& SetUserPreviouslyIgnored(int64_t value);

};

class Security_SiteEngagement final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Security_SiteEngagement(ukm::SourceId source_id);
  explicit Security_SiteEngagement(base::UkmSourceId source_id);
  ~Security_SiteEngagement() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10614135803401894002);


  static const char kFinalSecurityLevelName[];
  static constexpr uint64_t kFinalSecurityLevelNameHash = UINT64_C(8095555624405238595);
  Security_SiteEngagement& SetFinalSecurityLevel(int64_t value);

  static const char kInitialSecurityLevelName[];
  static constexpr uint64_t kInitialSecurityLevelNameHash = UINT64_C(7293396472423676335);
  Security_SiteEngagement& SetInitialSecurityLevel(int64_t value);

  static const char kSafetyTipStatusName[];
  static constexpr uint64_t kSafetyTipStatusNameHash = UINT64_C(4178545148842217888);
  Security_SiteEngagement& SetSafetyTipStatus(int64_t value);

  static const char kScoreDeltaName[];
  static constexpr uint64_t kScoreDeltaNameHash = UINT64_C(9558031948839307480);
  Security_SiteEngagement& SetScoreDelta(int64_t value);

  static const char kScoreFinalName[];
  static constexpr uint64_t kScoreFinalNameHash = UINT64_C(16975692316282427253);
  Security_SiteEngagement& SetScoreFinal(int64_t value);

};

class Sharing_ClickToCall final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Sharing_ClickToCall(ukm::SourceId source_id);
  explicit Sharing_ClickToCall(base::UkmSourceId source_id);
  ~Sharing_ClickToCall() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(13674128907128689363);


  static const char kEntryPointName[];
  static constexpr uint64_t kEntryPointNameHash = UINT64_C(14367068064969258826);
  Sharing_ClickToCall& SetEntryPoint(int64_t value);

  static const char kHasAppsName[];
  static constexpr uint64_t kHasAppsNameHash = UINT64_C(8572169351575878732);
  Sharing_ClickToCall& SetHasApps(int64_t value);

  static const char kHasDevicesName[];
  static constexpr uint64_t kHasDevicesNameHash = UINT64_C(2199982532385446345);
  Sharing_ClickToCall& SetHasDevices(int64_t value);

  static const char kSelectionName[];
  static constexpr uint64_t kSelectionNameHash = UINT64_C(8068723256203825537);
  Sharing_ClickToCall& SetSelection(int64_t value);

};

class SmartCharging final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SmartCharging(ukm::SourceId source_id);
  explicit SmartCharging(base::UkmSourceId source_id);
  ~SmartCharging() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18163040957371490481);


  static const char kBatteryPercentageName[];
  static constexpr uint64_t kBatteryPercentageNameHash = UINT64_C(14519123228304078098);
  SmartCharging& SetBatteryPercentage(int64_t value);

  static const char kBatteryPercentageBeforeLastChargeName[];
  static constexpr uint64_t kBatteryPercentageBeforeLastChargeNameHash = UINT64_C(18006859437126683457);
  SmartCharging& SetBatteryPercentageBeforeLastCharge(int64_t value);

  static const char kBatteryPercentageOfLastChargeName[];
  static constexpr uint64_t kBatteryPercentageOfLastChargeNameHash = UINT64_C(11152599426817198152);
  SmartCharging& SetBatteryPercentageOfLastCharge(int64_t value);

  static const char kDayOfMonthName[];
  static constexpr uint64_t kDayOfMonthNameHash = UINT64_C(6240377267495591558);
  SmartCharging& SetDayOfMonth(int64_t value);

  static const char kDayOfWeekName[];
  static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
  SmartCharging& SetDayOfWeek(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  SmartCharging& SetDeviceMode(int64_t value);

  static const char kDeviceTypeName[];
  static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
  SmartCharging& SetDeviceType(int64_t value);

  static const char kDurationOfLastChargeName[];
  static constexpr uint64_t kDurationOfLastChargeNameHash = UINT64_C(2917539631700490805);
  SmartCharging& SetDurationOfLastCharge(int64_t value);

  static const char kDurationRecentAudioPlayingName[];
  static constexpr uint64_t kDurationRecentAudioPlayingNameHash = UINT64_C(13229015898265878531);
  SmartCharging& SetDurationRecentAudioPlaying(int64_t value);

  static const char kDurationRecentVideoPlayingName[];
  static constexpr uint64_t kDurationRecentVideoPlayingNameHash = UINT64_C(7949042912449780813);
  SmartCharging& SetDurationRecentVideoPlaying(int64_t value);

  static const char kEventIdName[];
  static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
  SmartCharging& SetEventId(int64_t value);

  static const char kHaltFromLastChargeName[];
  static constexpr uint64_t kHaltFromLastChargeNameHash = UINT64_C(4462991214889947556);
  SmartCharging& SetHaltFromLastCharge(int64_t value);

  static const char kIsChargingName[];
  static constexpr uint64_t kIsChargingNameHash = UINT64_C(7785451285210820804);
  SmartCharging& SetIsCharging(int64_t value);

  static const char kMonthName[];
  static constexpr uint64_t kMonthNameHash = UINT64_C(8987927404178983737);
  SmartCharging& SetMonth(int64_t value);

  static const char kNumRecentKeyEventsName[];
  static constexpr uint64_t kNumRecentKeyEventsNameHash = UINT64_C(17517294973322255376);
  SmartCharging& SetNumRecentKeyEvents(int64_t value);

  static const char kNumRecentMouseEventsName[];
  static constexpr uint64_t kNumRecentMouseEventsNameHash = UINT64_C(6164169136009494499);
  SmartCharging& SetNumRecentMouseEvents(int64_t value);

  static const char kNumRecentStylusEventsName[];
  static constexpr uint64_t kNumRecentStylusEventsNameHash = UINT64_C(13185006921548112034);
  SmartCharging& SetNumRecentStylusEvents(int64_t value);

  static const char kNumRecentTouchEventsName[];
  static constexpr uint64_t kNumRecentTouchEventsNameHash = UINT64_C(14067961327568630776);
  SmartCharging& SetNumRecentTouchEvents(int64_t value);

  static const char kReasonName[];
  static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
  SmartCharging& SetReason(int64_t value);

  static const char kScreenBrightnessPercentName[];
  static constexpr uint64_t kScreenBrightnessPercentNameHash = UINT64_C(17633439285161136902);
  SmartCharging& SetScreenBrightnessPercent(int64_t value);

  static const char kTimeOfTheDayName[];
  static constexpr uint64_t kTimeOfTheDayNameHash = UINT64_C(12210633505613690203);
  SmartCharging& SetTimeOfTheDay(int64_t value);

  static const char kTimeSinceLastChargeName[];
  static constexpr uint64_t kTimeSinceLastChargeNameHash = UINT64_C(7810039360408170089);
  SmartCharging& SetTimeSinceLastCharge(int64_t value);

  static const char kTimezoneDifferenceFromLastChargeName[];
  static constexpr uint64_t kTimezoneDifferenceFromLastChargeNameHash = UINT64_C(9773033992964804237);
  SmartCharging& SetTimezoneDifferenceFromLastCharge(int64_t value);

  static const char kVoltageName[];
  static constexpr uint64_t kVoltageNameHash = UINT64_C(5373634262604211033);
  SmartCharging& SetVoltage(int64_t value);

};

class SMSReceiver final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SMSReceiver(ukm::SourceId source_id);
  explicit SMSReceiver(base::UkmSourceId source_id);
  ~SMSReceiver() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16019904587509461311);


  static const char kOutcomeName[];
  static constexpr uint64_t kOutcomeNameHash = UINT64_C(14948499774890759507);
  SMSReceiver& SetOutcome(int64_t value);

};

class SSL_MixedContentShown final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SSL_MixedContentShown(ukm::SourceId source_id);
  explicit SSL_MixedContentShown(base::UkmSourceId source_id);
  ~SSL_MixedContentShown() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(1198169845674357824);


  static const char kTypeName[];
  static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
  SSL_MixedContentShown& SetType(int64_t value);

};

class SubresourceFilter final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit SubresourceFilter(ukm::SourceId source_id);
  explicit SubresourceFilter(base::UkmSourceId source_id);
  ~SubresourceFilter() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16234573202714536926);


  static const char kActivationDecisionName[];
  static constexpr uint64_t kActivationDecisionNameHash = UINT64_C(8340568698825149996);
  SubresourceFilter& SetActivationDecision(int64_t value);

  static const char kDryRunName[];
  static constexpr uint64_t kDryRunNameHash = UINT64_C(15305931645510130195);
  SubresourceFilter& SetDryRun(int64_t value);

  static const char kEnforcementRedirectPositionName[];
  static constexpr uint64_t kEnforcementRedirectPositionNameHash = UINT64_C(17469729262836585913);
  SubresourceFilter& SetEnforcementRedirectPosition(int64_t value);

};

class Tab_RendererOOM final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Tab_RendererOOM(ukm::SourceId source_id);
  explicit Tab_RendererOOM(base::UkmSourceId source_id);
  ~Tab_RendererOOM() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(18395820288494961196);


  static const char kTimeSinceLastNavigationName[];
  static constexpr uint64_t kTimeSinceLastNavigationNameHash = UINT64_C(13938385952041404158);
  Tab_RendererOOM& SetTimeSinceLastNavigation(int64_t value);

};

class Tab_Screenshot final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Tab_Screenshot(ukm::SourceId source_id);
  explicit Tab_Screenshot(base::UkmSourceId source_id);
  ~Tab_Screenshot() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4107587426159302168);


  static const char kHasOccurredName[];
  static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
  Tab_Screenshot& SetHasOccurred(int64_t value);

};

class TabManager_Background_FirstAlertFired final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_FirstAlertFired(ukm::SourceId source_id);
  explicit TabManager_Background_FirstAlertFired(base::UkmSourceId source_id);
  ~TabManager_Background_FirstAlertFired() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6962158576008124011);


  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  TabManager_Background_FirstAlertFired& SetIsMainFrame(int64_t value);

  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_FirstAlertFired& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_Background_FirstAudioStarts final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_FirstAudioStarts(ukm::SourceId source_id);
  explicit TabManager_Background_FirstAudioStarts(base::UkmSourceId source_id);
  ~TabManager_Background_FirstAudioStarts() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6253115585121265178);


  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  TabManager_Background_FirstAudioStarts& SetIsMainFrame(int64_t value);

  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_FirstAudioStarts& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_Background_FirstFaviconUpdated final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_FirstFaviconUpdated(ukm::SourceId source_id);
  explicit TabManager_Background_FirstFaviconUpdated(base::UkmSourceId source_id);
  ~TabManager_Background_FirstFaviconUpdated() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7684352713481018374);


  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_FirstFaviconUpdated& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_Background_FirstNonPersistentNotificationCreated final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceId source_id);
  explicit TabManager_Background_FirstNonPersistentNotificationCreated(base::UkmSourceId source_id);
  ~TabManager_Background_FirstNonPersistentNotificationCreated() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5800172692978642430);


  static const char kIsMainFrameName[];
  static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
  TabManager_Background_FirstNonPersistentNotificationCreated& SetIsMainFrame(int64_t value);

  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_FirstNonPersistentNotificationCreated& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_Background_FirstTitleUpdated final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_FirstTitleUpdated(ukm::SourceId source_id);
  explicit TabManager_Background_FirstTitleUpdated(base::UkmSourceId source_id);
  ~TabManager_Background_FirstTitleUpdated() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(13224923626166210718);


  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_FirstTitleUpdated& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_Background_ForegroundedOrClosed final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Background_ForegroundedOrClosed(ukm::SourceId source_id);
  explicit TabManager_Background_ForegroundedOrClosed(base::UkmSourceId source_id);
  ~TabManager_Background_ForegroundedOrClosed() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(11823633373787678555);


  static const char kIsDiscardedName[];
  static constexpr uint64_t kIsDiscardedNameHash = UINT64_C(4545578590056105756);
  TabManager_Background_ForegroundedOrClosed& SetIsDiscarded(int64_t value);

  static const char kIsForegroundedName[];
  static constexpr uint64_t kIsForegroundedNameHash = UINT64_C(18321524612313682043);
  TabManager_Background_ForegroundedOrClosed& SetIsForegrounded(int64_t value);

  static const char kLabelIdName[];
  static constexpr uint64_t kLabelIdNameHash = UINT64_C(14578023310397047120);
  TabManager_Background_ForegroundedOrClosed& SetLabelId(int64_t value);

  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_Background_ForegroundedOrClosed& SetTimeFromBackgrounded(int64_t value);

};

class TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id);
  explicit TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo(base::UkmSourceId source_id);
  ~TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2947416194925354680);


  static const char kBackgroundTabLoadingCountName[];
  static constexpr uint64_t kBackgroundTabLoadingCountNameHash = UINT64_C(8108652028127565967);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetBackgroundTabLoadingCount(int64_t value);

  static const char kBackgroundTabOpeningSessionIdName[];
  static constexpr uint64_t kBackgroundTabOpeningSessionIdNameHash = UINT64_C(18258324678902146719);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetBackgroundTabOpeningSessionId(int64_t value);

  static const char kBackgroundTabPendingCountName[];
  static constexpr uint64_t kBackgroundTabPendingCountNameHash = UINT64_C(16383019845237238944);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetBackgroundTabPendingCount(int64_t value);

  static const char kExpectedTaskQueueingDurationName[];
  static constexpr uint64_t kExpectedTaskQueueingDurationNameHash = UINT64_C(17505273149654010352);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetExpectedTaskQueueingDuration(int64_t value);

  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSequenceId(int64_t value);

  static const char kSystemTabCountName[];
  static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
  TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSystemTabCount(int64_t value);

};

class TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(ukm::SourceId source_id);
  explicit TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(base::UkmSourceId source_id);
  ~TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5089020187687107285);


  static const char kBackgroundTabLoadingCountName[];
  static constexpr uint64_t kBackgroundTabLoadingCountNameHash = UINT64_C(8108652028127565967);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetBackgroundTabLoadingCount(int64_t value);

  static const char kBackgroundTabOpeningSessionIdName[];
  static constexpr uint64_t kBackgroundTabOpeningSessionIdNameHash = UINT64_C(18258324678902146719);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetBackgroundTabOpeningSessionId(int64_t value);

  static const char kBackgroundTabPendingCountName[];
  static constexpr uint64_t kBackgroundTabPendingCountNameHash = UINT64_C(16383019845237238944);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetBackgroundTabPendingCount(int64_t value);

  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetSequenceId(int64_t value);

  static const char kSystemTabCountName[];
  static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetSystemTabCount(int64_t value);

  static const char kTabSwitchLoadTimeName[];
  static constexpr uint64_t kTabSwitchLoadTimeNameHash = UINT64_C(10500091388990852613);
  TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& SetTabSwitchLoadTime(int64_t value);

};

class TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(ukm::SourceId source_id);
  explicit TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(base::UkmSourceId source_id);
  ~TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(5185149670019600507);


  static const char kSessionRestoreTabCountName[];
  static constexpr uint64_t kSessionRestoreTabCountNameHash = UINT64_C(17950866683835588578);
  TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& SetSessionRestoreTabCount(int64_t value);

  static const char kSystemTabCountName[];
  static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
  TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& SetSystemTabCount(int64_t value);

};

class TabManager_Experimental_SessionRestore_TabSwitchLoadStopped final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceId source_id);
  explicit TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(base::UkmSourceId source_id);
  ~TabManager_Experimental_SessionRestore_TabSwitchLoadStopped() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10989149245696867796);


  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSequenceId(int64_t value);

  static const char kSessionRestoreSessionIdName[];
  static constexpr uint64_t kSessionRestoreSessionIdNameHash = UINT64_C(15125204540231964086);
  TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSessionRestoreSessionId(int64_t value);

  static const char kSessionRestoreTabCountName[];
  static constexpr uint64_t kSessionRestoreTabCountNameHash = UINT64_C(17950866683835588578);
  TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSessionRestoreTabCount(int64_t value);

  static const char kSystemTabCountName[];
  static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
  TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSystemTabCount(int64_t value);

  static const char kTabSwitchLoadTimeName[];
  static constexpr uint64_t kTabSwitchLoadTimeNameHash = UINT64_C(10500091388990852613);
  TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetTabSwitchLoadTime(int64_t value);

};

class TabManager_LifecycleStateChange final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_LifecycleStateChange(ukm::SourceId source_id);
  explicit TabManager_LifecycleStateChange(base::UkmSourceId source_id);
  ~TabManager_LifecycleStateChange() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15361214325300303131);


  static const char kFailureGlobalBlacklistName[];
  static constexpr uint64_t kFailureGlobalBlacklistNameHash = UINT64_C(14476327180189802143);
  TabManager_LifecycleStateChange& SetFailureGlobalBlacklist(int64_t value);

  static const char kFailureHeuristicAudioName[];
  static constexpr uint64_t kFailureHeuristicAudioNameHash = UINT64_C(12990459205506514618);
  TabManager_LifecycleStateChange& SetFailureHeuristicAudio(int64_t value);

  static const char kFailureHeuristicFaviconName[];
  static constexpr uint64_t kFailureHeuristicFaviconNameHash = UINT64_C(6690922114157445648);
  TabManager_LifecycleStateChange& SetFailureHeuristicFavicon(int64_t value);

  static const char kFailureHeuristicInsufficientObservationName[];
  static constexpr uint64_t kFailureHeuristicInsufficientObservationNameHash = UINT64_C(9049974075249313421);
  TabManager_LifecycleStateChange& SetFailureHeuristicInsufficientObservation(int64_t value);

  static const char kFailureHeuristicNotificationsName[];
  static constexpr uint64_t kFailureHeuristicNotificationsNameHash = UINT64_C(17387734332470541652);
  TabManager_LifecycleStateChange& SetFailureHeuristicNotifications(int64_t value);

  static const char kFailureHeuristicTitleName[];
  static constexpr uint64_t kFailureHeuristicTitleNameHash = UINT64_C(233030549471232823);
  TabManager_LifecycleStateChange& SetFailureHeuristicTitle(int64_t value);

  static const char kFailureLifecyclesEnterprisePolicyOptOutName[];
  static constexpr uint64_t kFailureLifecyclesEnterprisePolicyOptOutNameHash = UINT64_C(1568209932272358843);
  TabManager_LifecycleStateChange& SetFailureLifecyclesEnterprisePolicyOptOut(int64_t value);

  static const char kFailureLiveStateCapturingName[];
  static constexpr uint64_t kFailureLiveStateCapturingNameHash = UINT64_C(1746761367355389825);
  TabManager_LifecycleStateChange& SetFailureLiveStateCapturing(int64_t value);

  static const char kFailureLiveStateDesktopCaptureName[];
  static constexpr uint64_t kFailureLiveStateDesktopCaptureNameHash = UINT64_C(11836939473639691991);
  TabManager_LifecycleStateChange& SetFailureLiveStateDesktopCapture(int64_t value);

  static const char kFailureLiveStateDevToolsOpenName[];
  static constexpr uint64_t kFailureLiveStateDevToolsOpenNameHash = UINT64_C(12821716976590806522);
  TabManager_LifecycleStateChange& SetFailureLiveStateDevToolsOpen(int64_t value);

  static const char kFailureLiveStateExtensionDisallowedName[];
  static constexpr uint64_t kFailureLiveStateExtensionDisallowedNameHash = UINT64_C(14913603322702848559);
  TabManager_LifecycleStateChange& SetFailureLiveStateExtensionDisallowed(int64_t value);

  static const char kFailureLiveStateFormEntryName[];
  static constexpr uint64_t kFailureLiveStateFormEntryNameHash = UINT64_C(2603883520869794602);
  TabManager_LifecycleStateChange& SetFailureLiveStateFormEntry(int64_t value);

  static const char kFailureLiveStateHasNotificationsPermissionName[];
  static constexpr uint64_t kFailureLiveStateHasNotificationsPermissionNameHash = UINT64_C(702525710594214990);
  TabManager_LifecycleStateChange& SetFailureLiveStateHasNotificationsPermission(int64_t value);

  static const char kFailureLiveStateIsPDFName[];
  static constexpr uint64_t kFailureLiveStateIsPDFNameHash = UINT64_C(13057031957762159216);
  TabManager_LifecycleStateChange& SetFailureLiveStateIsPDF(int64_t value);

  static const char kFailureLiveStateMirroringName[];
  static constexpr uint64_t kFailureLiveStateMirroringNameHash = UINT64_C(12092063214704219593);
  TabManager_LifecycleStateChange& SetFailureLiveStateMirroring(int64_t value);

  static const char kFailureLiveStatePlayingAudioName[];
  static constexpr uint64_t kFailureLiveStatePlayingAudioNameHash = UINT64_C(10433273516404381618);
  TabManager_LifecycleStateChange& SetFailureLiveStatePlayingAudio(int64_t value);

  static const char kFailureLiveStateSharingBrowsingInstanceName[];
  static constexpr uint64_t kFailureLiveStateSharingBrowsingInstanceNameHash = UINT64_C(13716775964206616000);
  TabManager_LifecycleStateChange& SetFailureLiveStateSharingBrowsingInstance(int64_t value);

  static const char kFailureLiveStateUsingBluetoothName[];
  static constexpr uint64_t kFailureLiveStateUsingBluetoothNameHash = UINT64_C(16735747532167439663);
  TabManager_LifecycleStateChange& SetFailureLiveStateUsingBluetooth(int64_t value);

  static const char kFailureLiveStateUsingIndexedDBLockName[];
  static constexpr uint64_t kFailureLiveStateUsingIndexedDBLockNameHash = UINT64_C(4740449931443625670);
  TabManager_LifecycleStateChange& SetFailureLiveStateUsingIndexedDBLock(int64_t value);

  static const char kFailureLiveStateUsingWebLockName[];
  static constexpr uint64_t kFailureLiveStateUsingWebLockNameHash = UINT64_C(11583253983001039995);
  TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebLock(int64_t value);

  static const char kFailureLiveStateUsingWebSocketsName[];
  static constexpr uint64_t kFailureLiveStateUsingWebSocketsNameHash = UINT64_C(9779613440513908570);
  TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebSockets(int64_t value);

  static const char kFailureLiveStateUsingWebUSBName[];
  static constexpr uint64_t kFailureLiveStateUsingWebUSBNameHash = UINT64_C(1264204074714928849);
  TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebUSB(int64_t value);

  static const char kFailureLiveStateVisibleName[];
  static constexpr uint64_t kFailureLiveStateVisibleNameHash = UINT64_C(17796621035327630907);
  TabManager_LifecycleStateChange& SetFailureLiveStateVisible(int64_t value);

  static const char kFailureLiveWebAppName[];
  static constexpr uint64_t kFailureLiveWebAppNameHash = UINT64_C(17972142833607591150);
  TabManager_LifecycleStateChange& SetFailureLiveWebApp(int64_t value);

  static const char kFailureOriginTrialOptOutName[];
  static constexpr uint64_t kFailureOriginTrialOptOutNameHash = UINT64_C(3117221559354080435);
  TabManager_LifecycleStateChange& SetFailureOriginTrialOptOut(int64_t value);

  static const char kFailureOriginTrialUnknownName[];
  static constexpr uint64_t kFailureOriginTrialUnknownNameHash = UINT64_C(7785929326711993984);
  TabManager_LifecycleStateChange& SetFailureOriginTrialUnknown(int64_t value);

  static const char kLifecycleStateChangeReasonName[];
  static constexpr uint64_t kLifecycleStateChangeReasonNameHash = UINT64_C(6890089423438918274);
  TabManager_LifecycleStateChange& SetLifecycleStateChangeReason(int64_t value);

  static const char kNewLifecycleStateName[];
  static constexpr uint64_t kNewLifecycleStateNameHash = UINT64_C(12484427846537283830);
  TabManager_LifecycleStateChange& SetNewLifecycleState(int64_t value);

  static const char kOldLifecycleStateName[];
  static constexpr uint64_t kOldLifecycleStateNameHash = UINT64_C(981152026490365644);
  TabManager_LifecycleStateChange& SetOldLifecycleState(int64_t value);

  static const char kOutcomeName[];
  static constexpr uint64_t kOutcomeNameHash = UINT64_C(14948499774890759507);
  TabManager_LifecycleStateChange& SetOutcome(int64_t value);

  static const char kSuccessGlobalWhitelistName[];
  static constexpr uint64_t kSuccessGlobalWhitelistNameHash = UINT64_C(7684829310602972911);
  TabManager_LifecycleStateChange& SetSuccessGlobalWhitelist(int64_t value);

  static const char kSuccessHeuristicName[];
  static constexpr uint64_t kSuccessHeuristicNameHash = UINT64_C(7282383856026303779);
  TabManager_LifecycleStateChange& SetSuccessHeuristic(int64_t value);

  static const char kSuccessOriginTrialOptInName[];
  static constexpr uint64_t kSuccessOriginTrialOptInNameHash = UINT64_C(16495340119938645034);
  TabManager_LifecycleStateChange& SetSuccessOriginTrialOptIn(int64_t value);

  static const char kTimeSinceNavigationMsName[];
  static constexpr uint64_t kTimeSinceNavigationMsNameHash = UINT64_C(3766804751933420871);
  TabManager_LifecycleStateChange& SetTimeSinceNavigationMs(int64_t value);

  static const char kTimeSinceVisibilityStateChangeMsName[];
  static constexpr uint64_t kTimeSinceVisibilityStateChangeMsNameHash = UINT64_C(18111893678766007520);
  TabManager_LifecycleStateChange& SetTimeSinceVisibilityStateChangeMs(int64_t value);

  static const char kTransitionForcedName[];
  static constexpr uint64_t kTransitionForcedNameHash = UINT64_C(18125642282066928712);
  TabManager_LifecycleStateChange& SetTransitionForced(int64_t value);

  static const char kVisibilityStateName[];
  static constexpr uint64_t kVisibilityStateNameHash = UINT64_C(14490984458414165309);
  TabManager_LifecycleStateChange& SetVisibilityState(int64_t value);

};

class TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id);
  explicit TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(base::UkmSourceId source_id);
  ~TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(8999972273877232390);


  static const char kExpectedTaskQueueingDurationName[];
  static constexpr uint64_t kExpectedTaskQueueingDurationNameHash = UINT64_C(17505273149654010352);
  TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetExpectedTaskQueueingDuration(int64_t value);

  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSequenceId(int64_t value);

  static const char kSessionRestoreSessionIdName[];
  static constexpr uint64_t kSessionRestoreSessionIdNameHash = UINT64_C(15125204540231964086);
  TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSessionRestoreSessionId(int64_t value);

  static const char kSessionRestoreTabCountName[];
  static constexpr uint64_t kSessionRestoreTabCountNameHash = UINT64_C(17950866683835588578);
  TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSessionRestoreTabCount(int64_t value);

  static const char kSystemTabCountName[];
  static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
  TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSystemTabCount(int64_t value);

};

class TabManager_TabLifetime final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_TabLifetime(ukm::SourceId source_id);
  explicit TabManager_TabLifetime(base::UkmSourceId source_id);
  ~TabManager_TabLifetime() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16307465990132225428);


  static const char kTimeSinceNavigationName[];
  static constexpr uint64_t kTimeSinceNavigationNameHash = UINT64_C(18199427499238622919);
  TabManager_TabLifetime& SetTimeSinceNavigation(int64_t value);

};

class TabManager_TabMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_TabMetrics(ukm::SourceId source_id);
  explicit TabManager_TabMetrics(base::UkmSourceId source_id);
  ~TabManager_TabMetrics() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16400979786435208530);


  static const char kContentTypeName[];
  static constexpr uint64_t kContentTypeNameHash = UINT64_C(13265227184175150385);
  TabManager_TabMetrics& SetContentType(int64_t value);

  static const char kDefaultProtocolHandlerName[];
  static constexpr uint64_t kDefaultProtocolHandlerNameHash = UINT64_C(9621417131485279191);
  TabManager_TabMetrics& SetDefaultProtocolHandler(int64_t value);

  static const char kHasBeforeUnloadHandlerName[];
  static constexpr uint64_t kHasBeforeUnloadHandlerNameHash = UINT64_C(8451320907412850621);
  TabManager_TabMetrics& SetHasBeforeUnloadHandler(int64_t value);

  static const char kHasFormEntryName[];
  static constexpr uint64_t kHasFormEntryNameHash = UINT64_C(5531671421920391819);
  TabManager_TabMetrics& SetHasFormEntry(int64_t value);

  static const char kIsExtensionProtectedName[];
  static constexpr uint64_t kIsExtensionProtectedNameHash = UINT64_C(672646190625971503);
  TabManager_TabMetrics& SetIsExtensionProtected(int64_t value);

  static const char kIsPinnedName[];
  static constexpr uint64_t kIsPinnedNameHash = UINT64_C(18335894855165892645);
  TabManager_TabMetrics& SetIsPinned(int64_t value);

  static const char kKeyEventCountName[];
  static constexpr uint64_t kKeyEventCountNameHash = UINT64_C(4163051610151272998);
  TabManager_TabMetrics& SetKeyEventCount(int64_t value);

  static const char kLabelIdName[];
  static constexpr uint64_t kLabelIdNameHash = UINT64_C(14578023310397047120);
  TabManager_TabMetrics& SetLabelId(int64_t value);

  static const char kMouseEventCountName[];
  static constexpr uint64_t kMouseEventCountNameHash = UINT64_C(309543994040533082);
  TabManager_TabMetrics& SetMouseEventCount(int64_t value);

  static const char kMRUIndexName[];
  static constexpr uint64_t kMRUIndexNameHash = UINT64_C(383823483369014150);
  TabManager_TabMetrics& SetMRUIndex(int64_t value);

  static const char kNavigationEntryCountName[];
  static constexpr uint64_t kNavigationEntryCountNameHash = UINT64_C(551192753498951443);
  TabManager_TabMetrics& SetNavigationEntryCount(int64_t value);

  static const char kNumReactivationBeforeName[];
  static constexpr uint64_t kNumReactivationBeforeNameHash = UINT64_C(12506028779813329233);
  TabManager_TabMetrics& SetNumReactivationBefore(int64_t value);

  static const char kPageTransitionCoreTypeName[];
  static constexpr uint64_t kPageTransitionCoreTypeNameHash = UINT64_C(8252723677936572940);
  TabManager_TabMetrics& SetPageTransitionCoreType(int64_t value);

  static const char kPageTransitionFromAddressBarName[];
  static constexpr uint64_t kPageTransitionFromAddressBarNameHash = UINT64_C(622306465519288550);
  TabManager_TabMetrics& SetPageTransitionFromAddressBar(int64_t value);

  static const char kPageTransitionIsRedirectName[];
  static constexpr uint64_t kPageTransitionIsRedirectNameHash = UINT64_C(385608697209044372);
  TabManager_TabMetrics& SetPageTransitionIsRedirect(int64_t value);

  static const char kQueryIdName[];
  static constexpr uint64_t kQueryIdNameHash = UINT64_C(3424853290585620796);
  TabManager_TabMetrics& SetQueryId(int64_t value);

  static const char kSiteEngagementScoreName[];
  static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
  TabManager_TabMetrics& SetSiteEngagementScore(int64_t value);

  static const char kTimeFromBackgroundedName[];
  static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
  TabManager_TabMetrics& SetTimeFromBackgrounded(int64_t value);

  static const char kTotalTabCountName[];
  static constexpr uint64_t kTotalTabCountNameHash = UINT64_C(13301182033056356455);
  TabManager_TabMetrics& SetTotalTabCount(int64_t value);

  static const char kTouchEventCountName[];
  static constexpr uint64_t kTouchEventCountNameHash = UINT64_C(15943190177665830246);
  TabManager_TabMetrics& SetTouchEventCount(int64_t value);

  static const char kWasRecentlyAudibleName[];
  static constexpr uint64_t kWasRecentlyAudibleNameHash = UINT64_C(8155633754967058330);
  TabManager_TabMetrics& SetWasRecentlyAudible(int64_t value);

  static const char kWindowIsActiveName[];
  static constexpr uint64_t kWindowIsActiveNameHash = UINT64_C(2416652406969853074);
  TabManager_TabMetrics& SetWindowIsActive(int64_t value);

  static const char kWindowShowStateName[];
  static constexpr uint64_t kWindowShowStateNameHash = UINT64_C(13531960550708215988);
  TabManager_TabMetrics& SetWindowShowState(int64_t value);

  static const char kWindowTabCountName[];
  static constexpr uint64_t kWindowTabCountNameHash = UINT64_C(18037545539906018035);
  TabManager_TabMetrics& SetWindowTabCount(int64_t value);

  static const char kWindowTypeName[];
  static constexpr uint64_t kWindowTypeNameHash = UINT64_C(78651398005697984);
  TabManager_TabMetrics& SetWindowType(int64_t value);

};

class TabManager_WindowMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TabManager_WindowMetrics(ukm::SourceId source_id);
  explicit TabManager_WindowMetrics(base::UkmSourceId source_id);
  ~TabManager_WindowMetrics() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12562637272871338124);


  static const char kIsActiveName[];
  static constexpr uint64_t kIsActiveNameHash = UINT64_C(145730663672890399);
  TabManager_WindowMetrics& SetIsActive(int64_t value);

  static const char kShowStateName[];
  static constexpr uint64_t kShowStateNameHash = UINT64_C(6352664330247173052);
  TabManager_WindowMetrics& SetShowState(int64_t value);

  static const char kTabCountName[];
  static constexpr uint64_t kTabCountNameHash = UINT64_C(1513537862956601777);
  TabManager_WindowMetrics& SetTabCount(int64_t value);

  static const char kTypeName[];
  static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
  TabManager_WindowMetrics& SetType(int64_t value);

  static const char kWindowIdName[];
  static constexpr uint64_t kWindowIdNameHash = UINT64_C(2294382318193398891);
  TabManager_WindowMetrics& SetWindowId(int64_t value);

};

class TouchToFill_Shown final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TouchToFill_Shown(ukm::SourceId source_id);
  explicit TouchToFill_Shown(base::UkmSourceId source_id);
  ~TouchToFill_Shown() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(833305494688204602);


  static const char kUserActionName[];
  static constexpr uint64_t kUserActionNameHash = UINT64_C(11431707273815549887);
  TouchToFill_Shown& SetUserAction(int64_t value);

};

class Translate final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit Translate(ukm::SourceId source_id);
  explicit Translate(base::UkmSourceId source_id);
  ~Translate() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(16054416016310256565);


  static const char kAcceptCountName[];
  static constexpr uint64_t kAcceptCountNameHash = UINT64_C(8502235306677298033);
  Translate& SetAcceptCount(int64_t value);

  static const char kCountryName[];
  static constexpr uint64_t kCountryNameHash = UINT64_C(6445051938772793705);
  Translate& SetCountry(int64_t value);

  static const char kDeclineCountName[];
  static constexpr uint64_t kDeclineCountNameHash = UINT64_C(3180238090454488835);
  Translate& SetDeclineCount(int64_t value);

  static const char kEventTypeName[];
  static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
  Translate& SetEventType(int64_t value);

  static const char kIgnoreCountName[];
  static constexpr uint64_t kIgnoreCountNameHash = UINT64_C(14896378584437100759);
  Translate& SetIgnoreCount(int64_t value);

  static const char kRankerResponseName[];
  static constexpr uint64_t kRankerResponseNameHash = UINT64_C(6404631249487430957);
  Translate& SetRankerResponse(int64_t value);

  static const char kRankerVersionName[];
  static constexpr uint64_t kRankerVersionNameHash = UINT64_C(10214100949042673155);
  Translate& SetRankerVersion(int64_t value);

  static const char kSourceLanguageName[];
  static constexpr uint64_t kSourceLanguageNameHash = UINT64_C(15558163265405593795);
  Translate& SetSourceLanguage(int64_t value);

  static const char kTargetLanguageName[];
  static constexpr uint64_t kTargetLanguageNameHash = UINT64_C(8387451134401416124);
  Translate& SetTargetLanguage(int64_t value);

};

class TrustedWebActivity_Open final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit TrustedWebActivity_Open(ukm::SourceId source_id);
  explicit TrustedWebActivity_Open(base::UkmSourceId source_id);
  ~TrustedWebActivity_Open() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15381255782093849665);


  static const char kHasOccurredName[];
  static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
  TrustedWebActivity_Open& SetHasOccurred(int64_t value);

};

class UserActivity final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit UserActivity(ukm::SourceId source_id);
  explicit UserActivity(base::UkmSourceId source_id);
  ~UserActivity() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2395897864454822590);


  static const char kBatteryPercentName[];
  static constexpr uint64_t kBatteryPercentNameHash = UINT64_C(3434325767059222004);
  UserActivity& SetBatteryPercent(int64_t value);

  static const char kDeviceManagementName[];
  static constexpr uint64_t kDeviceManagementNameHash = UINT64_C(3879735998068387644);
  UserActivity& SetDeviceManagement(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  UserActivity& SetDeviceMode(int64_t value);

  static const char kDeviceTypeName[];
  static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
  UserActivity& SetDeviceType(int64_t value);

  static const char kEventLogDurationName[];
  static constexpr uint64_t kEventLogDurationNameHash = UINT64_C(9294112700816090959);
  UserActivity& SetEventLogDuration(int64_t value);

  static const char kEventReasonName[];
  static constexpr uint64_t kEventReasonNameHash = UINT64_C(16835794410928463032);
  UserActivity& SetEventReason(int64_t value);

  static const char kEventTypeName[];
  static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
  UserActivity& SetEventType(int64_t value);

  static const char kKeyEventsInLastHourName[];
  static constexpr uint64_t kKeyEventsInLastHourNameHash = UINT64_C(11299844146219290596);
  UserActivity& SetKeyEventsInLastHour(int64_t value);

  static const char kLastActivityDayName[];
  static constexpr uint64_t kLastActivityDayNameHash = UINT64_C(14339230944188901365);
  UserActivity& SetLastActivityDay(int64_t value);

  static const char kLastActivityTimeName[];
  static constexpr uint64_t kLastActivityTimeNameHash = UINT64_C(14831110523312780762);
  UserActivity& SetLastActivityTime(int64_t value);

  static const char kLastUserActivityTimeName[];
  static constexpr uint64_t kLastUserActivityTimeNameHash = UINT64_C(8788245832941149939);
  UserActivity& SetLastUserActivityTime(int64_t value);

  static const char kModelAppliedName[];
  static constexpr uint64_t kModelAppliedNameHash = UINT64_C(6801141381231795082);
  UserActivity& SetModelApplied(int64_t value);

  static const char kModelDecisionThresholdName[];
  static constexpr uint64_t kModelDecisionThresholdNameHash = UINT64_C(16615553209600420827);
  UserActivity& SetModelDecisionThreshold(int64_t value);

  static const char kModelInactivityScoreName[];
  static constexpr uint64_t kModelInactivityScoreNameHash = UINT64_C(1730033542070367675);
  UserActivity& SetModelInactivityScore(int64_t value);

  static const char kModelResponseName[];
  static constexpr uint64_t kModelResponseNameHash = UINT64_C(972970836639660541);
  UserActivity& SetModelResponse(int64_t value);

  static const char kMouseEventsInLastHourName[];
  static constexpr uint64_t kMouseEventsInLastHourNameHash = UINT64_C(11835042666579861839);
  UserActivity& SetMouseEventsInLastHour(int64_t value);

  static const char kOnBatteryName[];
  static constexpr uint64_t kOnBatteryNameHash = UINT64_C(9497943841916154435);
  UserActivity& SetOnBattery(int64_t value);

  static const char kPreviousNegativeActionsCountName[];
  static constexpr uint64_t kPreviousNegativeActionsCountNameHash = UINT64_C(17834864132047931181);
  UserActivity& SetPreviousNegativeActionsCount(int64_t value);

  static const char kPreviousPositiveActionsCountName[];
  static constexpr uint64_t kPreviousPositiveActionsCountNameHash = UINT64_C(6191193929978136769);
  UserActivity& SetPreviousPositiveActionsCount(int64_t value);

  static const char kRecentTimeActiveName[];
  static constexpr uint64_t kRecentTimeActiveNameHash = UINT64_C(14147624997432742521);
  UserActivity& SetRecentTimeActive(int64_t value);

  static const char kRecentVideoPlayingTimeName[];
  static constexpr uint64_t kRecentVideoPlayingTimeNameHash = UINT64_C(13380566763432764429);
  UserActivity& SetRecentVideoPlayingTime(int64_t value);

  static const char kScreenDimDelayName[];
  static constexpr uint64_t kScreenDimDelayNameHash = UINT64_C(16833327722358108459);
  UserActivity& SetScreenDimDelay(int64_t value);

  static const char kScreenDimmedInitiallyName[];
  static constexpr uint64_t kScreenDimmedInitiallyNameHash = UINT64_C(10179091906473872128);
  UserActivity& SetScreenDimmedInitially(int64_t value);

  static const char kScreenDimOccurredName[];
  static constexpr uint64_t kScreenDimOccurredNameHash = UINT64_C(9781953209119865440);
  UserActivity& SetScreenDimOccurred(int64_t value);

  static const char kScreenDimToOffDelayName[];
  static constexpr uint64_t kScreenDimToOffDelayNameHash = UINT64_C(6534684685018748413);
  UserActivity& SetScreenDimToOffDelay(int64_t value);

  static const char kScreenLockedInitiallyName[];
  static constexpr uint64_t kScreenLockedInitiallyNameHash = UINT64_C(17101958306385581732);
  UserActivity& SetScreenLockedInitially(int64_t value);

  static const char kScreenLockOccurredName[];
  static constexpr uint64_t kScreenLockOccurredNameHash = UINT64_C(15627670727691026054);
  UserActivity& SetScreenLockOccurred(int64_t value);

  static const char kScreenOffInitiallyName[];
  static constexpr uint64_t kScreenOffInitiallyNameHash = UINT64_C(7660996110440871532);
  UserActivity& SetScreenOffInitially(int64_t value);

  static const char kScreenOffOccurredName[];
  static constexpr uint64_t kScreenOffOccurredNameHash = UINT64_C(2742307602633466727);
  UserActivity& SetScreenOffOccurred(int64_t value);

  static const char kSequenceIdName[];
  static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
  UserActivity& SetSequenceId(int64_t value);

  static const char kTimeSinceLastKeyName[];
  static constexpr uint64_t kTimeSinceLastKeyNameHash = UINT64_C(13324245886378099422);
  UserActivity& SetTimeSinceLastKey(int64_t value);

  static const char kTimeSinceLastMouseName[];
  static constexpr uint64_t kTimeSinceLastMouseNameHash = UINT64_C(17332744557102175004);
  UserActivity& SetTimeSinceLastMouse(int64_t value);

  static const char kTimeSinceLastTouchName[];
  static constexpr uint64_t kTimeSinceLastTouchNameHash = UINT64_C(14082842047789348566);
  UserActivity& SetTimeSinceLastTouch(int64_t value);

  static const char kTimeSinceLastVideoEndedName[];
  static constexpr uint64_t kTimeSinceLastVideoEndedNameHash = UINT64_C(10757682901092788351);
  UserActivity& SetTimeSinceLastVideoEnded(int64_t value);

  static const char kTouchEventsInLastHourName[];
  static constexpr uint64_t kTouchEventsInLastHourNameHash = UINT64_C(10049871984955982925);
  UserActivity& SetTouchEventsInLastHour(int64_t value);

};

class UserActivityId final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit UserActivityId(ukm::SourceId source_id);
  explicit UserActivityId(base::UkmSourceId source_id);
  ~UserActivityId() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(13821826834442202003);


  static const char kActivityIdName[];
  static constexpr uint64_t kActivityIdNameHash = UINT64_C(11740600895634714945);
  UserActivityId& SetActivityId(int64_t value);

  static const char kContentTypeName[];
  static constexpr uint64_t kContentTypeNameHash = UINT64_C(13265227184175150385);
  UserActivityId& SetContentType(int64_t value);

  static const char kHasFormEntryName[];
  static constexpr uint64_t kHasFormEntryNameHash = UINT64_C(5531671421920391819);
  UserActivityId& SetHasFormEntry(int64_t value);

  static const char kIsActiveName[];
  static constexpr uint64_t kIsActiveNameHash = UINT64_C(145730663672890399);
  UserActivityId& SetIsActive(int64_t value);

  static const char kIsBrowserFocusedName[];
  static constexpr uint64_t kIsBrowserFocusedNameHash = UINT64_C(10440852628796553876);
  UserActivityId& SetIsBrowserFocused(int64_t value);

  static const char kIsBrowserVisibleName[];
  static constexpr uint64_t kIsBrowserVisibleNameHash = UINT64_C(3688875443071437947);
  UserActivityId& SetIsBrowserVisible(int64_t value);

  static const char kIsTopmostBrowserName[];
  static constexpr uint64_t kIsTopmostBrowserNameHash = UINT64_C(1520583382931955160);
  UserActivityId& SetIsTopmostBrowser(int64_t value);

  static const char kSiteEngagementScoreName[];
  static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
  UserActivityId& SetSiteEngagementScore(int64_t value);

};

class UserSettingsEvent final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit UserSettingsEvent(ukm::SourceId source_id);
  explicit UserSettingsEvent(base::UkmSourceId source_id);
  ~UserSettingsEvent() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12666214553193795663);


  static const char kAccessibilityIdName[];
  static constexpr uint64_t kAccessibilityIdNameHash = UINT64_C(6951746995541001113);
  UserSettingsEvent& SetAccessibilityId(int64_t value);

  static const char kBatteryPercentageName[];
  static constexpr uint64_t kBatteryPercentageNameHash = UINT64_C(14519123228304078098);
  UserSettingsEvent& SetBatteryPercentage(int64_t value);

  static const char kCountryName[];
  static constexpr uint64_t kCountryNameHash = UINT64_C(6445051938772793705);
  UserSettingsEvent& SetCountry(int64_t value);

  static const char kCurrentValueName[];
  static constexpr uint64_t kCurrentValueNameHash = UINT64_C(4480604349707933716);
  UserSettingsEvent& SetCurrentValue(int64_t value);

  static const char kDayOfWeekName[];
  static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
  UserSettingsEvent& SetDayOfWeek(int64_t value);

  static const char kDeviceModeName[];
  static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
  UserSettingsEvent& SetDeviceMode(int64_t value);

  static const char kDeviceOrientationName[];
  static constexpr uint64_t kDeviceOrientationNameHash = UINT64_C(8736270914758222171);
  UserSettingsEvent& SetDeviceOrientation(int64_t value);

  static const char kEventIdName[];
  static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
  UserSettingsEvent& SetEventId(int64_t value);

  static const char kHasNightLightScheduleName[];
  static constexpr uint64_t kHasNightLightScheduleNameHash = UINT64_C(14585315686070998458);
  UserSettingsEvent& SetHasNightLightSchedule(int64_t value);

  static const char kHasWifiSecurityName[];
  static constexpr uint64_t kHasWifiSecurityNameHash = UINT64_C(5721107002478202463);
  UserSettingsEvent& SetHasWifiSecurity(int64_t value);

  static const char kHourOfDayName[];
  static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
  UserSettingsEvent& SetHourOfDay(int64_t value);

  static const char kIsAfterSunsetName[];
  static constexpr uint64_t kIsAfterSunsetNameHash = UINT64_C(11608548832571895888);
  UserSettingsEvent& SetIsAfterSunset(int64_t value);

  static const char kIsChargingName[];
  static constexpr uint64_t kIsChargingNameHash = UINT64_C(7785451285210820804);
  UserSettingsEvent& SetIsCharging(int64_t value);

  static const char kIsFromSearchName[];
  static constexpr uint64_t kIsFromSearchNameHash = UINT64_C(15204105501663144020);
  UserSettingsEvent& SetIsFromSearch(int64_t value);

  static const char kIsPairedBluetoothDeviceName[];
  static constexpr uint64_t kIsPairedBluetoothDeviceNameHash = UINT64_C(5002254055864357224);
  UserSettingsEvent& SetIsPairedBluetoothDevice(int64_t value);

  static const char kIsPlayingAudioName[];
  static constexpr uint64_t kIsPlayingAudioNameHash = UINT64_C(14717530477958097309);
  UserSettingsEvent& SetIsPlayingAudio(int64_t value);

  static const char kIsPlayingVideoName[];
  static constexpr uint64_t kIsPlayingVideoNameHash = UINT64_C(11099955762179070975);
  UserSettingsEvent& SetIsPlayingVideo(int64_t value);

  static const char kIsRecentlyFullscreenName[];
  static constexpr uint64_t kIsRecentlyFullscreenNameHash = UINT64_C(1799217089626394865);
  UserSettingsEvent& SetIsRecentlyFullscreen(int64_t value);

  static const char kIsRecentlyPresentingName[];
  static constexpr uint64_t kIsRecentlyPresentingNameHash = UINT64_C(14538544070627056819);
  UserSettingsEvent& SetIsRecentlyPresenting(int64_t value);

  static const char kNetworkStatusName[];
  static constexpr uint64_t kNetworkStatusNameHash = UINT64_C(1438764637082620773);
  UserSettingsEvent& SetNetworkStatus(int64_t value);

  static const char kPreviousValueName[];
  static constexpr uint64_t kPreviousValueNameHash = UINT64_C(12685882687934574180);
  UserSettingsEvent& SetPreviousValue(int64_t value);

  static const char kSettingIdName[];
  static constexpr uint64_t kSettingIdNameHash = UINT64_C(8375811908993639483);
  UserSettingsEvent& SetSettingId(int64_t value);

  static const char kSettingTypeName[];
  static constexpr uint64_t kSettingTypeNameHash = UINT64_C(211450250705861929);
  UserSettingsEvent& SetSettingType(int64_t value);

  static const char kSignalStrengthName[];
  static constexpr uint64_t kSignalStrengthNameHash = UINT64_C(15379794641566604348);
  UserSettingsEvent& SetSignalStrength(int64_t value);

  static const char kTimeSinceLastSettingsChangeName[];
  static constexpr uint64_t kTimeSinceLastSettingsChangeNameHash = UINT64_C(3738478733604276330);
  UserSettingsEvent& SetTimeSinceLastSettingsChange(int64_t value);

  static const char kUsedCellularInSessionName[];
  static constexpr uint64_t kUsedCellularInSessionNameHash = UINT64_C(18328455473606685366);
  UserSettingsEvent& SetUsedCellularInSession(int64_t value);

};

class VirtualKeyboard_Open final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit VirtualKeyboard_Open(ukm::SourceId source_id);
  explicit VirtualKeyboard_Open(base::UkmSourceId source_id);
  ~VirtualKeyboard_Open() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(3904325154478962694);


  static const char kTextInputTypeName[];
  static constexpr uint64_t kTextInputTypeNameHash = UINT64_C(6049523454185107552);
  VirtualKeyboard_Open& SetTextInputType(int64_t value);

};

class WebAPK_Install final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebAPK_Install(ukm::SourceId source_id);
  explicit WebAPK_Install(base::UkmSourceId source_id);
  ~WebAPK_Install() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(12193435703081602033);


  static const char kAppVersionName[];
  static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
  WebAPK_Install& SetAppVersion(int64_t value);

  static const char kDistributorName[];
  static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
  WebAPK_Install& SetDistributor(int64_t value);

  static const char kInstallName[];
  static constexpr uint64_t kInstallNameHash = UINT64_C(3789841737615482174);
  WebAPK_Install& SetInstall(int64_t value);

};

class WebAPK_SessionEnd final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebAPK_SessionEnd(ukm::SourceId source_id);
  explicit WebAPK_SessionEnd(base::UkmSourceId source_id);
  ~WebAPK_SessionEnd() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(304278077624055651);


  static const char kAppVersionName[];
  static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
  WebAPK_SessionEnd& SetAppVersion(int64_t value);

  static const char kDistributorName[];
  static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
  WebAPK_SessionEnd& SetDistributor(int64_t value);

  static const char kSessionDurationName[];
  static constexpr uint64_t kSessionDurationNameHash = UINT64_C(2701974374748336509);
  WebAPK_SessionEnd& SetSessionDuration(int64_t value);

};

class WebAPK_Uninstall final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebAPK_Uninstall(ukm::SourceId source_id);
  explicit WebAPK_Uninstall(base::UkmSourceId source_id);
  ~WebAPK_Uninstall() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15147671640732652143);


  static const char kAppVersionName[];
  static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
  WebAPK_Uninstall& SetAppVersion(int64_t value);

  static const char kDistributorName[];
  static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
  WebAPK_Uninstall& SetDistributor(int64_t value);

  static const char kInstalledDurationName[];
  static constexpr uint64_t kInstalledDurationNameHash = UINT64_C(8139225208300052851);
  WebAPK_Uninstall& SetInstalledDuration(int64_t value);

  static const char kLifetimeLaunchesName[];
  static constexpr uint64_t kLifetimeLaunchesNameHash = UINT64_C(14300233011189208559);
  WebAPK_Uninstall& SetLifetimeLaunches(int64_t value);

  static const char kUninstallName[];
  static constexpr uint64_t kUninstallNameHash = UINT64_C(11708794393683665055);
  WebAPK_Uninstall& SetUninstall(int64_t value);

};

class WebAPK_Visit final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebAPK_Visit(ukm::SourceId source_id);
  explicit WebAPK_Visit(base::UkmSourceId source_id);
  ~WebAPK_Visit() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7419239618516179300);


  static const char kAppVersionName[];
  static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
  WebAPK_Visit& SetAppVersion(int64_t value);

  static const char kDistributorName[];
  static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
  WebAPK_Visit& SetDistributor(int64_t value);

  static const char kLaunchName[];
  static constexpr uint64_t kLaunchNameHash = UINT64_C(10738535331188906759);
  WebAPK_Visit& SetLaunch(int64_t value);

  static const char kLaunchSourceName[];
  static constexpr uint64_t kLaunchSourceNameHash = UINT64_C(5360095524695749322);
  WebAPK_Visit& SetLaunchSource(int64_t value);

};

class WebApp_DailyInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebApp_DailyInteraction(ukm::SourceId source_id);
  explicit WebApp_DailyInteraction(base::UkmSourceId source_id);
  ~WebApp_DailyInteraction() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(10823086981545979708);


  static const char kBackgroundDurationName[];
  static constexpr uint64_t kBackgroundDurationNameHash = UINT64_C(11993638961121254288);
  WebApp_DailyInteraction& SetBackgroundDuration(int64_t value);

  static const char kDisplayModeName[];
  static constexpr uint64_t kDisplayModeNameHash = UINT64_C(12581275766339648725);
  WebApp_DailyInteraction& SetDisplayMode(int64_t value);

  static const char kForegroundDurationName[];
  static constexpr uint64_t kForegroundDurationNameHash = UINT64_C(14040493619853098912);
  WebApp_DailyInteraction& SetForegroundDuration(int64_t value);

  static const char kInstalledName[];
  static constexpr uint64_t kInstalledNameHash = UINT64_C(11015034891594477851);
  WebApp_DailyInteraction& SetInstalled(int64_t value);

  static const char kInstallSourceName[];
  static constexpr uint64_t kInstallSourceNameHash = UINT64_C(7897354207534621578);
  WebApp_DailyInteraction& SetInstallSource(int64_t value);

  static const char kNumSessionsName[];
  static constexpr uint64_t kNumSessionsNameHash = UINT64_C(6349061493514857092);
  WebApp_DailyInteraction& SetNumSessions(int64_t value);

  static const char kPromotableName[];
  static constexpr uint64_t kPromotableNameHash = UINT64_C(16843428730026040799);
  WebApp_DailyInteraction& SetPromotable(int64_t value);

  static const char kUsedName[];
  static constexpr uint64_t kUsedNameHash = UINT64_C(116280672541001035);
  WebApp_DailyInteraction& SetUsed(int64_t value);

};

class WebRTC_AddressHarvesting final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebRTC_AddressHarvesting(ukm::SourceId source_id);
  explicit WebRTC_AddressHarvesting(base::UkmSourceId source_id);
  ~WebRTC_AddressHarvesting() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(6759459948386423184);


  static const char kUsagePatternName[];
  static constexpr uint64_t kUsagePatternNameHash = UINT64_C(2048621503660355193);
  WebRTC_AddressHarvesting& SetUsagePattern(int64_t value);

};

class WebRTC_ComplexSdp final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit WebRTC_ComplexSdp(ukm::SourceId source_id);
  explicit WebRTC_ComplexSdp(base::UkmSourceId source_id);
  ~WebRTC_ComplexSdp() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(7456919696038345904);


  static const char kCategoryName[];
  static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
  WebRTC_ComplexSdp& SetCategory(int64_t value);

};

class XR_WebXR final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit XR_WebXR(ukm::SourceId source_id);
  explicit XR_WebXR(base::UkmSourceId source_id);
  ~XR_WebXR() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(2966287978545946180);


  static const char kDidGetXRInputSourcesName[];
  static constexpr uint64_t kDidGetXRInputSourcesNameHash = UINT64_C(14351844110769922173);
  XR_WebXR& SetDidGetXRInputSources(int64_t value);

  static const char kDidRequestAvailableDevicesName[];
  static constexpr uint64_t kDidRequestAvailableDevicesNameHash = UINT64_C(5107681164098988581);
  XR_WebXR& SetDidRequestAvailableDevices(int64_t value);

  static const char kDidRequestPoseName[];
  static constexpr uint64_t kDidRequestPoseNameHash = UINT64_C(1918328077075117272);
  XR_WebXR& SetDidRequestPose(int64_t value);

  static const char kDidRequestPresentationName[];
  static constexpr uint64_t kDidRequestPresentationNameHash = UINT64_C(15657914383994855428);
  XR_WebXR& SetDidRequestPresentation(int64_t value);

  static const char kDidUseNavigatorXRName[];
  static constexpr uint64_t kDidUseNavigatorXRNameHash = UINT64_C(10361228866366512051);
  XR_WebXR& SetDidUseNavigatorXR(int64_t value);

  static const char kReturnedDeviceName[];
  static constexpr uint64_t kReturnedDeviceNameHash = UINT64_C(1409100318625382915);
  XR_WebXR& SetReturnedDevice(int64_t value);

  static const char kReturnedPresentationCapableDeviceName[];
  static constexpr uint64_t kReturnedPresentationCapableDeviceNameHash = UINT64_C(6868640628705115096);
  XR_WebXR& SetReturnedPresentationCapableDevice(int64_t value);

};

class XR_WebXR_Session final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit XR_WebXR_Session(ukm::SourceId source_id);
  explicit XR_WebXR_Session(base::UkmSourceId source_id);
  ~XR_WebXR_Session() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(4113953897099533496);


  static const char kDurationName[];
  static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
  XR_WebXR_Session& SetDuration(int64_t value);

  static const char kFeatureRequest_BoundedFloorName[];
  static constexpr uint64_t kFeatureRequest_BoundedFloorNameHash = UINT64_C(16901359366456654591);
  XR_WebXR_Session& SetFeatureRequest_BoundedFloor(int64_t value);

  static const char kFeatureRequest_LocalName[];
  static constexpr uint64_t kFeatureRequest_LocalNameHash = UINT64_C(13815453126277382446);
  XR_WebXR_Session& SetFeatureRequest_Local(int64_t value);

  static const char kFeatureRequest_LocalFloorName[];
  static constexpr uint64_t kFeatureRequest_LocalFloorNameHash = UINT64_C(10252183817747774542);
  XR_WebXR_Session& SetFeatureRequest_LocalFloor(int64_t value);

  static const char kFeatureRequest_UnboundedName[];
  static constexpr uint64_t kFeatureRequest_UnboundedNameHash = UINT64_C(136983454872075535);
  XR_WebXR_Session& SetFeatureRequest_Unbounded(int64_t value);

  static const char kFeatureRequest_ViewerName[];
  static constexpr uint64_t kFeatureRequest_ViewerNameHash = UINT64_C(15521080164987816802);
  XR_WebXR_Session& SetFeatureRequest_Viewer(int64_t value);

  static const char kFeatureUse_BoundedFloorName[];
  static constexpr uint64_t kFeatureUse_BoundedFloorNameHash = UINT64_C(17918695119767135356);
  XR_WebXR_Session& SetFeatureUse_BoundedFloor(int64_t value);

  static const char kFeatureUse_LocalName[];
  static constexpr uint64_t kFeatureUse_LocalNameHash = UINT64_C(863830676396637536);
  XR_WebXR_Session& SetFeatureUse_Local(int64_t value);

  static const char kFeatureUse_LocalFloorName[];
  static constexpr uint64_t kFeatureUse_LocalFloorNameHash = UINT64_C(1848942618885117456);
  XR_WebXR_Session& SetFeatureUse_LocalFloor(int64_t value);

  static const char kFeatureUse_UnboundedName[];
  static constexpr uint64_t kFeatureUse_UnboundedNameHash = UINT64_C(892938442719335112);
  XR_WebXR_Session& SetFeatureUse_Unbounded(int64_t value);

  static const char kFeatureUse_ViewerName[];
  static constexpr uint64_t kFeatureUse_ViewerNameHash = UINT64_C(10409675248815280630);
  XR_WebXR_Session& SetFeatureUse_Viewer(int64_t value);

  static const char kModeName[];
  static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
  XR_WebXR_Session& SetMode(int64_t value);

};

class XR_WebXR_SessionRequest final : public ::ukm::internal::UkmEntryBuilderBase {
 public:
  explicit XR_WebXR_SessionRequest(ukm::SourceId source_id);
  explicit XR_WebXR_SessionRequest(base::UkmSourceId source_id);
  ~XR_WebXR_SessionRequest() override;

  static const char kEntryName[];
  static constexpr uint64_t kEntryNameHash = UINT64_C(15349576264204541813);


  static const char kFeature_BoundedFloorName[];
  static constexpr uint64_t kFeature_BoundedFloorNameHash = UINT64_C(9616676461285313482);
  XR_WebXR_SessionRequest& SetFeature_BoundedFloor(int64_t value);

  static const char kFeature_LocalName[];
  static constexpr uint64_t kFeature_LocalNameHash = UINT64_C(6494346351619867017);
  XR_WebXR_SessionRequest& SetFeature_Local(int64_t value);

  static const char kFeature_LocalFloorName[];
  static constexpr uint64_t kFeature_LocalFloorNameHash = UINT64_C(1462584064413291363);
  XR_WebXR_SessionRequest& SetFeature_LocalFloor(int64_t value);

  static const char kFeature_UnboundedName[];
  static constexpr uint64_t kFeature_UnboundedNameHash = UINT64_C(6682040134498450962);
  XR_WebXR_SessionRequest& SetFeature_Unbounded(int64_t value);

  static const char kFeature_ViewerName[];
  static constexpr uint64_t kFeature_ViewerNameHash = UINT64_C(6038436711203453177);
  XR_WebXR_SessionRequest& SetFeature_Viewer(int64_t value);

  static const char kModeName[];
  static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
  XR_WebXR_SessionRequest& SetMode(int64_t value);

  static const char kStatusName[];
  static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
  XR_WebXR_SessionRequest& SetStatus(int64_t value);

};


}  // namespace builders
}  // namespace ukm

#endif  // SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H
