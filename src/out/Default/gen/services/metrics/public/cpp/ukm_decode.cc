
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#include "services/metrics/public/cpp//ukm_decode.h"
#include "services/metrics/public/cpp//ukm_builders.h"

namespace ukm {
namespace builders {

std::map<uint64_t, EntryDecoder> CreateDecodeMap() {
  return {
    
    {
      UINT64_C(4325886147604803651),
      {
        AbusiveExperienceHeuristic::kEntryName,
        {
          
    {AbusiveExperienceHeuristic::kDidTabUnderNameHash, AbusiveExperienceHeuristic::kDidTabUnderName},

    {AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptNameHash, AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptName},

    {AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeNameHash, AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeName},

        }
      }
    },

    {
      UINT64_C(2140536877907621174),
      {
        AbusiveExperienceHeuristic_JavaScriptDialog::kEntryName,
        {
          
    {AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseNameHash, AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseName},

        }
      }
    },

    {
      UINT64_C(14027824048938333848),
      {
        AbusiveExperienceHeuristic_TabUnder::kEntryName,
        {
          
    {AbusiveExperienceHeuristic_TabUnder::kDidTabUnderNameHash, AbusiveExperienceHeuristic_TabUnder::kDidTabUnderName},

        }
      }
    },

    {
      UINT64_C(9914911288513336680),
      {
        AbusiveExperienceHeuristic_WindowOpen::kEntryName,
        {
          
    {AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptName},

    {AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeName},

        }
      }
    },

    {
      UINT64_C(11928696798041860883),
      {
        Accessibility_Renderer::kEntryName,
        {
          
    {Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsNameHash, Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsName},

        }
      }
    },

    {
      UINT64_C(9171478480016060997),
      {
        AdFrameLoad::kEntryName,
        {
          
    {AdFrameLoad::kCpuTime_PeakWindowedPercentNameHash, AdFrameLoad::kCpuTime_PeakWindowedPercentName},

    {AdFrameLoad::kCpuTime_PreActivationNameHash, AdFrameLoad::kCpuTime_PreActivationName},

    {AdFrameLoad::kCpuTime_TotalNameHash, AdFrameLoad::kCpuTime_TotalName},

    {AdFrameLoad::kFrameDepthNameHash, AdFrameLoad::kFrameDepthName},

    {AdFrameLoad::kLoading_CacheBytes2NameHash, AdFrameLoad::kLoading_CacheBytes2Name},

    {AdFrameLoad::kLoading_ImageBytesNameHash, AdFrameLoad::kLoading_ImageBytesName},

    {AdFrameLoad::kLoading_JavascriptBytesNameHash, AdFrameLoad::kLoading_JavascriptBytesName},

    {AdFrameLoad::kLoading_NetworkBytesNameHash, AdFrameLoad::kLoading_NetworkBytesName},

    {AdFrameLoad::kLoading_NumResourcesNameHash, AdFrameLoad::kLoading_NumResourcesName},

    {AdFrameLoad::kLoading_VideoBytesNameHash, AdFrameLoad::kLoading_VideoBytesName},

    {AdFrameLoad::kStatus_CrossOriginNameHash, AdFrameLoad::kStatus_CrossOriginName},

    {AdFrameLoad::kStatus_MediaNameHash, AdFrameLoad::kStatus_MediaName},

    {AdFrameLoad::kStatus_UserActivationNameHash, AdFrameLoad::kStatus_UserActivationName},

    {AdFrameLoad::kTiming_FirstContentfulPaintNameHash, AdFrameLoad::kTiming_FirstContentfulPaintName},

    {AdFrameLoad::kTiming_InteractiveNameHash, AdFrameLoad::kTiming_InteractiveName},

    {AdFrameLoad::kTiming_PreActivationForegroundDurationNameHash, AdFrameLoad::kTiming_PreActivationForegroundDurationName},

    {AdFrameLoad::kVisibility_FrameHeightNameHash, AdFrameLoad::kVisibility_FrameHeightName},

    {AdFrameLoad::kVisibility_FrameWidthNameHash, AdFrameLoad::kVisibility_FrameWidthName},

    {AdFrameLoad::kVisibility_HiddenNameHash, AdFrameLoad::kVisibility_HiddenName},

        }
      }
    },

    {
      UINT64_C(897698866892786861),
      {
        AdPageLoad::kEntryName,
        {
          
    {AdPageLoad::kAdBytesNameHash, AdPageLoad::kAdBytesName},

    {AdPageLoad::kAdCpuTimeNameHash, AdPageLoad::kAdCpuTimeName},

    {AdPageLoad::kAdJavascriptBytesNameHash, AdPageLoad::kAdJavascriptBytesName},

    {AdPageLoad::kAdVideoBytesNameHash, AdPageLoad::kAdVideoBytesName},

    {AdPageLoad::kMainframeAdBytesNameHash, AdPageLoad::kMainframeAdBytesName},

    {AdPageLoad::kTotalBytesNameHash, AdPageLoad::kTotalBytesName},

        }
      }
    },

    {
      UINT64_C(15288827799554694614),
      {
        AmpPageLoad::kEntryName,
        {
          
    {AmpPageLoad::kMainFrameAmpPageLoadNameHash, AmpPageLoad::kMainFrameAmpPageLoadName},

    {AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4NameHash, AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4Name},

    {AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash, AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreName},

    {AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash, AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName},

    {AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash, AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaName},

    {AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName},

    {AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaintNameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaintName},

    {AmpPageLoad::kSubFrameAmpPageLoadNameHash, AmpPageLoad::kSubFrameAmpPageLoadName},

        }
      }
    },

    {
      UINT64_C(4589718692267131532),
      {
        AppListAppClickData::kEntryName,
        {
          
    {AppListAppClickData::kAppLaunchIdNameHash, AppListAppClickData::kAppLaunchIdName},

    {AppListAppClickData::kAppTypeNameHash, AppListAppClickData::kAppTypeName},

    {AppListAppClickData::kClickRankNameHash, AppListAppClickData::kClickRankName},

    {AppListAppClickData::kClicksEachHour00NameHash, AppListAppClickData::kClicksEachHour00Name},

    {AppListAppClickData::kClicksEachHour01NameHash, AppListAppClickData::kClicksEachHour01Name},

    {AppListAppClickData::kClicksEachHour02NameHash, AppListAppClickData::kClicksEachHour02Name},

    {AppListAppClickData::kClicksEachHour03NameHash, AppListAppClickData::kClicksEachHour03Name},

    {AppListAppClickData::kClicksEachHour04NameHash, AppListAppClickData::kClicksEachHour04Name},

    {AppListAppClickData::kClicksEachHour05NameHash, AppListAppClickData::kClicksEachHour05Name},

    {AppListAppClickData::kClicksEachHour06NameHash, AppListAppClickData::kClicksEachHour06Name},

    {AppListAppClickData::kClicksEachHour07NameHash, AppListAppClickData::kClicksEachHour07Name},

    {AppListAppClickData::kClicksEachHour08NameHash, AppListAppClickData::kClicksEachHour08Name},

    {AppListAppClickData::kClicksEachHour09NameHash, AppListAppClickData::kClicksEachHour09Name},

    {AppListAppClickData::kClicksEachHour10NameHash, AppListAppClickData::kClicksEachHour10Name},

    {AppListAppClickData::kClicksEachHour11NameHash, AppListAppClickData::kClicksEachHour11Name},

    {AppListAppClickData::kClicksEachHour12NameHash, AppListAppClickData::kClicksEachHour12Name},

    {AppListAppClickData::kClicksEachHour13NameHash, AppListAppClickData::kClicksEachHour13Name},

    {AppListAppClickData::kClicksEachHour14NameHash, AppListAppClickData::kClicksEachHour14Name},

    {AppListAppClickData::kClicksEachHour15NameHash, AppListAppClickData::kClicksEachHour15Name},

    {AppListAppClickData::kClicksEachHour16NameHash, AppListAppClickData::kClicksEachHour16Name},

    {AppListAppClickData::kClicksEachHour17NameHash, AppListAppClickData::kClicksEachHour17Name},

    {AppListAppClickData::kClicksEachHour18NameHash, AppListAppClickData::kClicksEachHour18Name},

    {AppListAppClickData::kClicksEachHour19NameHash, AppListAppClickData::kClicksEachHour19Name},

    {AppListAppClickData::kClicksEachHour20NameHash, AppListAppClickData::kClicksEachHour20Name},

    {AppListAppClickData::kClicksEachHour21NameHash, AppListAppClickData::kClicksEachHour21Name},

    {AppListAppClickData::kClicksEachHour22NameHash, AppListAppClickData::kClicksEachHour22Name},

    {AppListAppClickData::kClicksEachHour23NameHash, AppListAppClickData::kClicksEachHour23Name},

    {AppListAppClickData::kClicksLast24HoursNameHash, AppListAppClickData::kClicksLast24HoursName},

    {AppListAppClickData::kClicksLastHourNameHash, AppListAppClickData::kClicksLastHourName},

    {AppListAppClickData::kLastLaunchedFromNameHash, AppListAppClickData::kLastLaunchedFromName},

    {AppListAppClickData::kMostRecentlyUsedIndexNameHash, AppListAppClickData::kMostRecentlyUsedIndexName},

    {AppListAppClickData::kSequenceNumberNameHash, AppListAppClickData::kSequenceNumberName},

    {AppListAppClickData::kTimeSinceLastClickNameHash, AppListAppClickData::kTimeSinceLastClickName},

    {AppListAppClickData::kTotalClicksNameHash, AppListAppClickData::kTotalClicksName},

        }
      }
    },

    {
      UINT64_C(16635456347627451827),
      {
        AppListAppLaunch::kEntryName,
        {
          
    {AppListAppLaunch::kAllClicksLast24HoursNameHash, AppListAppLaunch::kAllClicksLast24HoursName},

    {AppListAppLaunch::kAllClicksLastHourNameHash, AppListAppLaunch::kAllClicksLastHourName},

    {AppListAppLaunch::kAppTypeNameHash, AppListAppLaunch::kAppTypeName},

    {AppListAppLaunch::kClickMethodNameHash, AppListAppLaunch::kClickMethodName},

    {AppListAppLaunch::kDayOfWeekNameHash, AppListAppLaunch::kDayOfWeekName},

    {AppListAppLaunch::kDeviceModeNameHash, AppListAppLaunch::kDeviceModeName},

    {AppListAppLaunch::kDeviceTypeNameHash, AppListAppLaunch::kDeviceTypeName},

    {AppListAppLaunch::kHourOfDayNameHash, AppListAppLaunch::kHourOfDayName},

    {AppListAppLaunch::kLaunchedFromNameHash, AppListAppLaunch::kLaunchedFromName},

    {AppListAppLaunch::kPositionIndexNameHash, AppListAppLaunch::kPositionIndexName},

    {AppListAppLaunch::kTotalHoursNameHash, AppListAppLaunch::kTotalHoursName},

        }
      }
    },

    {
      UINT64_C(9743727136758947685),
      {
        AppListNonAppImpression::kEntryName,
        {
          
    {AppListNonAppImpression::kCategoryNameHash, AppListNonAppImpression::kCategoryName},

    {AppListNonAppImpression::kDayOfWeekNameHash, AppListNonAppImpression::kDayOfWeekName},

    {AppListNonAppImpression::kDeviceModeNameHash, AppListNonAppImpression::kDeviceModeName},

    {AppListNonAppImpression::kEventIdNameHash, AppListNonAppImpression::kEventIdName},

    {AppListNonAppImpression::kFileExtensionNameHash, AppListNonAppImpression::kFileExtensionName},

    {AppListNonAppImpression::kHourOfDayNameHash, AppListNonAppImpression::kHourOfDayName},

    {AppListNonAppImpression::kIsLaunchedNameHash, AppListNonAppImpression::kIsLaunchedName},

    {AppListNonAppImpression::kLaunchesAtHour00NameHash, AppListNonAppImpression::kLaunchesAtHour00Name},

    {AppListNonAppImpression::kLaunchesAtHour01NameHash, AppListNonAppImpression::kLaunchesAtHour01Name},

    {AppListNonAppImpression::kLaunchesAtHour02NameHash, AppListNonAppImpression::kLaunchesAtHour02Name},

    {AppListNonAppImpression::kLaunchesAtHour03NameHash, AppListNonAppImpression::kLaunchesAtHour03Name},

    {AppListNonAppImpression::kLaunchesAtHour04NameHash, AppListNonAppImpression::kLaunchesAtHour04Name},

    {AppListNonAppImpression::kLaunchesAtHour05NameHash, AppListNonAppImpression::kLaunchesAtHour05Name},

    {AppListNonAppImpression::kLaunchesAtHour06NameHash, AppListNonAppImpression::kLaunchesAtHour06Name},

    {AppListNonAppImpression::kLaunchesAtHour07NameHash, AppListNonAppImpression::kLaunchesAtHour07Name},

    {AppListNonAppImpression::kLaunchesAtHour08NameHash, AppListNonAppImpression::kLaunchesAtHour08Name},

    {AppListNonAppImpression::kLaunchesAtHour09NameHash, AppListNonAppImpression::kLaunchesAtHour09Name},

    {AppListNonAppImpression::kLaunchesAtHour10NameHash, AppListNonAppImpression::kLaunchesAtHour10Name},

    {AppListNonAppImpression::kLaunchesAtHour11NameHash, AppListNonAppImpression::kLaunchesAtHour11Name},

    {AppListNonAppImpression::kLaunchesAtHour12NameHash, AppListNonAppImpression::kLaunchesAtHour12Name},

    {AppListNonAppImpression::kLaunchesAtHour13NameHash, AppListNonAppImpression::kLaunchesAtHour13Name},

    {AppListNonAppImpression::kLaunchesAtHour14NameHash, AppListNonAppImpression::kLaunchesAtHour14Name},

    {AppListNonAppImpression::kLaunchesAtHour15NameHash, AppListNonAppImpression::kLaunchesAtHour15Name},

    {AppListNonAppImpression::kLaunchesAtHour16NameHash, AppListNonAppImpression::kLaunchesAtHour16Name},

    {AppListNonAppImpression::kLaunchesAtHour17NameHash, AppListNonAppImpression::kLaunchesAtHour17Name},

    {AppListNonAppImpression::kLaunchesAtHour18NameHash, AppListNonAppImpression::kLaunchesAtHour18Name},

    {AppListNonAppImpression::kLaunchesAtHour19NameHash, AppListNonAppImpression::kLaunchesAtHour19Name},

    {AppListNonAppImpression::kLaunchesAtHour20NameHash, AppListNonAppImpression::kLaunchesAtHour20Name},

    {AppListNonAppImpression::kLaunchesAtHour21NameHash, AppListNonAppImpression::kLaunchesAtHour21Name},

    {AppListNonAppImpression::kLaunchesAtHour22NameHash, AppListNonAppImpression::kLaunchesAtHour22Name},

    {AppListNonAppImpression::kLaunchesAtHour23NameHash, AppListNonAppImpression::kLaunchesAtHour23Name},

    {AppListNonAppImpression::kLaunchesThisSessionNameHash, AppListNonAppImpression::kLaunchesThisSessionName},

    {AppListNonAppImpression::kPositionNameHash, AppListNonAppImpression::kPositionName},

    {AppListNonAppImpression::kQueryLengthNameHash, AppListNonAppImpression::kQueryLengthName},

    {AppListNonAppImpression::kRelevanceScoreNameHash, AppListNonAppImpression::kRelevanceScoreName},

    {AppListNonAppImpression::kTimeOfLastLaunchNameHash, AppListNonAppImpression::kTimeOfLastLaunchName},

    {AppListNonAppImpression::kTimeSinceLastLaunchNameHash, AppListNonAppImpression::kTimeSinceLastLaunchName},

        }
      }
    },

    {
      UINT64_C(3597047501124112026),
      {
        Autofill_CardUploadDecision::kEntryName,
        {
          
    {Autofill_CardUploadDecision::kUploadDecisionNameHash, Autofill_CardUploadDecision::kUploadDecisionName},

        }
      }
    },

    {
      UINT64_C(14550063303370974566),
      {
        Autofill_DeveloperEngagement::kEntryName,
        {
          
    {Autofill_DeveloperEngagement::kDeveloperEngagementNameHash, Autofill_DeveloperEngagement::kDeveloperEngagementName},

    {Autofill_DeveloperEngagement::kFormSignatureNameHash, Autofill_DeveloperEngagement::kFormSignatureName},

    {Autofill_DeveloperEngagement::kFormTypesNameHash, Autofill_DeveloperEngagement::kFormTypesName},

    {Autofill_DeveloperEngagement::kIsForCreditCardNameHash, Autofill_DeveloperEngagement::kIsForCreditCardName},

        }
      }
    },

    {
      UINT64_C(11456448948041474991),
      {
        Autofill_FieldFillStatus::kEntryName,
        {
          
    {Autofill_FieldFillStatus::kFieldSignatureNameHash, Autofill_FieldFillStatus::kFieldSignatureName},

    {Autofill_FieldFillStatus::kFormSignatureNameHash, Autofill_FieldFillStatus::kFormSignatureName},

    {Autofill_FieldFillStatus::kIsAutofilledNameHash, Autofill_FieldFillStatus::kIsAutofilledName},

    {Autofill_FieldFillStatus::kMillisecondsSinceFormParsedNameHash, Autofill_FieldFillStatus::kMillisecondsSinceFormParsedName},

    {Autofill_FieldFillStatus::kPredictionSourceNameHash, Autofill_FieldFillStatus::kPredictionSourceName},

    {Autofill_FieldFillStatus::kValidationEventNameHash, Autofill_FieldFillStatus::kValidationEventName},

    {Autofill_FieldFillStatus::kWasPreviouslyAutofilledNameHash, Autofill_FieldFillStatus::kWasPreviouslyAutofilledName},

        }
      }
    },

    {
      UINT64_C(1290380890049589579),
      {
        Autofill_FieldTypeValidation::kEntryName,
        {
          
    {Autofill_FieldTypeValidation::kActualTypeNameHash, Autofill_FieldTypeValidation::kActualTypeName},

    {Autofill_FieldTypeValidation::kFieldSignatureNameHash, Autofill_FieldTypeValidation::kFieldSignatureName},

    {Autofill_FieldTypeValidation::kFormSignatureNameHash, Autofill_FieldTypeValidation::kFormSignatureName},

    {Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedNameHash, Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedName},

    {Autofill_FieldTypeValidation::kPredictedTypeNameHash, Autofill_FieldTypeValidation::kPredictedTypeName},

    {Autofill_FieldTypeValidation::kPredictionSourceNameHash, Autofill_FieldTypeValidation::kPredictionSourceName},

    {Autofill_FieldTypeValidation::kValidationEventNameHash, Autofill_FieldTypeValidation::kValidationEventName},

        }
      }
    },

    {
      UINT64_C(16631655786524489525),
      {
        Autofill_FormEvent::kEntryName,
        {
          
    {Autofill_FormEvent::kAutofillFormEventNameHash, Autofill_FormEvent::kAutofillFormEventName},

    {Autofill_FormEvent::kFormTypesNameHash, Autofill_FormEvent::kFormTypesName},

    {Autofill_FormEvent::kMillisecondsSinceFormParsedNameHash, Autofill_FormEvent::kMillisecondsSinceFormParsedName},

        }
      }
    },

    {
      UINT64_C(12791011001011085363),
      {
        Autofill_FormSubmitted::kEntryName,
        {
          
    {Autofill_FormSubmitted::kAutofillFormSubmittedStateNameHash, Autofill_FormSubmitted::kAutofillFormSubmittedStateName},

    {Autofill_FormSubmitted::kFormSignatureNameHash, Autofill_FormSubmitted::kFormSignatureName},

    {Autofill_FormSubmitted::kFormTypesNameHash, Autofill_FormSubmitted::kFormTypesName},

    {Autofill_FormSubmitted::kHasUpiVpaFieldNameHash, Autofill_FormSubmitted::kHasUpiVpaFieldName},

    {Autofill_FormSubmitted::kIsForCreditCardNameHash, Autofill_FormSubmitted::kIsForCreditCardName},

    {Autofill_FormSubmitted::kMillisecondsSinceFormParsedNameHash, Autofill_FormSubmitted::kMillisecondsSinceFormParsedName},

        }
      }
    },

    {
      UINT64_C(14481214823422924028),
      {
        Autofill_HiddenRepresentationalFieldSkipDecision::kEntryName,
        {
          
    {Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedName},

    {Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeName},

        }
      }
    },

    {
      UINT64_C(12943113565528625214),
      {
        Autofill_InteractedWithForm::kEntryName,
        {
          
    {Autofill_InteractedWithForm::kFormSignatureNameHash, Autofill_InteractedWithForm::kFormSignatureName},

    {Autofill_InteractedWithForm::kFormTypesNameHash, Autofill_InteractedWithForm::kFormTypesName},

    {Autofill_InteractedWithForm::kIsForCreditCardNameHash, Autofill_InteractedWithForm::kIsForCreditCardName},

    {Autofill_InteractedWithForm::kLocalRecordTypeCountNameHash, Autofill_InteractedWithForm::kLocalRecordTypeCountName},

    {Autofill_InteractedWithForm::kServerRecordTypeCountNameHash, Autofill_InteractedWithForm::kServerRecordTypeCountName},

        }
      }
    },

    {
      UINT64_C(10421158139944624501),
      {
        Autofill_RepeatedServerTypePredictionRationalized::kEntryName,
        {
          
    {Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeName},

    {Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeName},

    {Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureName},

    {Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupName},

    {Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureName},

    {Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeName},

    {Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeName},

    {Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeName},

    {Autofill_RepeatedServerTypePredictionRationalized::kServerTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kServerTypeName},

        }
      }
    },

    {
      UINT64_C(17703268464688884622),
      {
        Autofill_SuggestionFilled::kEntryName,
        {
          
    {Autofill_SuggestionFilled::kFieldSignatureNameHash, Autofill_SuggestionFilled::kFieldSignatureName},

    {Autofill_SuggestionFilled::kFormSignatureNameHash, Autofill_SuggestionFilled::kFormSignatureName},

    {Autofill_SuggestionFilled::kIsForCreditCardNameHash, Autofill_SuggestionFilled::kIsForCreditCardName},

    {Autofill_SuggestionFilled::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionFilled::kMillisecondsSinceFormParsedName},

    {Autofill_SuggestionFilled::kRecordTypeNameHash, Autofill_SuggestionFilled::kRecordTypeName},

        }
      }
    },

    {
      UINT64_C(7579660929739851736),
      {
        Autofill_SuggestionsShown::kEntryName,
        {
          
    {Autofill_SuggestionsShown::kFieldSignatureNameHash, Autofill_SuggestionsShown::kFieldSignatureName},

    {Autofill_SuggestionsShown::kFormSignatureNameHash, Autofill_SuggestionsShown::kFormSignatureName},

    {Autofill_SuggestionsShown::kHeuristicTypeNameHash, Autofill_SuggestionsShown::kHeuristicTypeName},

    {Autofill_SuggestionsShown::kHtmlFieldTypeNameHash, Autofill_SuggestionsShown::kHtmlFieldTypeName},

    {Autofill_SuggestionsShown::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionsShown::kMillisecondsSinceFormParsedName},

    {Autofill_SuggestionsShown::kServerTypeNameHash, Autofill_SuggestionsShown::kServerTypeName},

        }
      }
    },

    {
      UINT64_C(8376184896509210883),
      {
        Autofill_TextFieldDidChange::kEntryName,
        {
          
    {Autofill_TextFieldDidChange::kFieldSignatureNameHash, Autofill_TextFieldDidChange::kFieldSignatureName},

    {Autofill_TextFieldDidChange::kFieldTypeGroupNameHash, Autofill_TextFieldDidChange::kFieldTypeGroupName},

    {Autofill_TextFieldDidChange::kFormSignatureNameHash, Autofill_TextFieldDidChange::kFormSignatureName},

    {Autofill_TextFieldDidChange::kHeuristicTypeNameHash, Autofill_TextFieldDidChange::kHeuristicTypeName},

    {Autofill_TextFieldDidChange::kHtmlFieldModeNameHash, Autofill_TextFieldDidChange::kHtmlFieldModeName},

    {Autofill_TextFieldDidChange::kHtmlFieldTypeNameHash, Autofill_TextFieldDidChange::kHtmlFieldTypeName},

    {Autofill_TextFieldDidChange::kIsAutofilledNameHash, Autofill_TextFieldDidChange::kIsAutofilledName},

    {Autofill_TextFieldDidChange::kIsEmptyNameHash, Autofill_TextFieldDidChange::kIsEmptyName},

    {Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedNameHash, Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedName},

    {Autofill_TextFieldDidChange::kServerTypeNameHash, Autofill_TextFieldDidChange::kServerTypeName},

        }
      }
    },

    {
      UINT64_C(15260645490069405494),
      {
        BackgroundFetch::kEntryName,
        {
          
    {BackgroundFetch::kDeniedDueToPermissionsNameHash, BackgroundFetch::kDeniedDueToPermissionsName},

    {BackgroundFetch::kDownloadTotalNameHash, BackgroundFetch::kDownloadTotalName},

    {BackgroundFetch::kHasTitleNameHash, BackgroundFetch::kHasTitleName},

    {BackgroundFetch::kNumIconsNameHash, BackgroundFetch::kNumIconsName},

    {BackgroundFetch::kNumRequestsInFetchNameHash, BackgroundFetch::kNumRequestsInFetchName},

    {BackgroundFetch::kRatioOfIdealToChosenIconSizeNameHash, BackgroundFetch::kRatioOfIdealToChosenIconSizeName},

        }
      }
    },

    {
      UINT64_C(2765600174500981245),
      {
        BackgroundFetchDeletingRegistration::kEntryName,
        {
          
    {BackgroundFetchDeletingRegistration::kUserInitiatedAbortNameHash, BackgroundFetchDeletingRegistration::kUserInitiatedAbortName},

        }
      }
    },

    {
      UINT64_C(7109245137155486527),
      {
        BackgroundSyncCompleted::kEntryName,
        {
          
    {BackgroundSyncCompleted::kMaxAttemptsNameHash, BackgroundSyncCompleted::kMaxAttemptsName},

    {BackgroundSyncCompleted::kNumAttemptsNameHash, BackgroundSyncCompleted::kNumAttemptsName},

    {BackgroundSyncCompleted::kStatusNameHash, BackgroundSyncCompleted::kStatusName},

        }
      }
    },

    {
      UINT64_C(3511425855963568724),
      {
        BackgroundSyncRegistered::kEntryName,
        {
          
    {BackgroundSyncRegistered::kCanFireNameHash, BackgroundSyncRegistered::kCanFireName},

    {BackgroundSyncRegistered::kIsReregisteredNameHash, BackgroundSyncRegistered::kIsReregisteredName},

        }
      }
    },

    {
      UINT64_C(12678664205992465342),
      {
        Badging::kEntryName,
        {
          
    {Badging::kUpdateAppBadgeNameHash, Badging::kUpdateAppBadgeName},

        }
      }
    },

    {
      UINT64_C(14503116569381719800),
      {
        Blink_FindInPage::kEntryName,
        {
          
    {Blink_FindInPage::kDidHaveRenderSubtreeMatchNameHash, Blink_FindInPage::kDidHaveRenderSubtreeMatchName},

    {Blink_FindInPage::kDidSearchNameHash, Blink_FindInPage::kDidSearchName},

        }
      }
    },

    {
      UINT64_C(11969773594143228030),
      {
        Blink_HTMLParsing::kEntryName,
        {
          
    {Blink_HTMLParsing::kChunkCountNameHash, Blink_HTMLParsing::kChunkCountName},

    {Blink_HTMLParsing::kParsingTimeMaxNameHash, Blink_HTMLParsing::kParsingTimeMaxName},

    {Blink_HTMLParsing::kParsingTimeMinNameHash, Blink_HTMLParsing::kParsingTimeMinName},

    {Blink_HTMLParsing::kParsingTimeTotalNameHash, Blink_HTMLParsing::kParsingTimeTotalName},

    {Blink_HTMLParsing::kTokensParsedAverageNameHash, Blink_HTMLParsing::kTokensParsedAverageName},

    {Blink_HTMLParsing::kTokensParsedMaxNameHash, Blink_HTMLParsing::kTokensParsedMaxName},

    {Blink_HTMLParsing::kTokensParsedMinNameHash, Blink_HTMLParsing::kTokensParsedMinName},

    {Blink_HTMLParsing::kYieldedTimeAverageNameHash, Blink_HTMLParsing::kYieldedTimeAverageName},

    {Blink_HTMLParsing::kYieldedTimeMaxNameHash, Blink_HTMLParsing::kYieldedTimeMaxName},

    {Blink_HTMLParsing::kYieldedTimeMinNameHash, Blink_HTMLParsing::kYieldedTimeMinName},

        }
      }
    },

    {
      UINT64_C(11315426756825559974),
      {
        Blink_PageLoad::kEntryName,
        {
          
    {Blink_PageLoad::kAnimateNameHash, Blink_PageLoad::kAnimateName},

    {Blink_PageLoad::kCompositingNameHash, Blink_PageLoad::kCompositingName},

    {Blink_PageLoad::kCompositingCommitNameHash, Blink_PageLoad::kCompositingCommitName},

    {Blink_PageLoad::kForcedStyleAndLayoutNameHash, Blink_PageLoad::kForcedStyleAndLayoutName},

    {Blink_PageLoad::kHandleInputEventsNameHash, Blink_PageLoad::kHandleInputEventsName},

    {Blink_PageLoad::kHitTestDocumentUpdateNameHash, Blink_PageLoad::kHitTestDocumentUpdateName},

    {Blink_PageLoad::kImplCompositorCommitNameHash, Blink_PageLoad::kImplCompositorCommitName},

    {Blink_PageLoad::kIntersectionObservationNameHash, Blink_PageLoad::kIntersectionObservationName},

    {Blink_PageLoad::kLayoutNameHash, Blink_PageLoad::kLayoutName},

    {Blink_PageLoad::kMainFrameNameHash, Blink_PageLoad::kMainFrameName},

    {Blink_PageLoad::kPaintNameHash, Blink_PageLoad::kPaintName},

    {Blink_PageLoad::kPrePaintNameHash, Blink_PageLoad::kPrePaintName},

    {Blink_PageLoad::kScrollingCoordinatorNameHash, Blink_PageLoad::kScrollingCoordinatorName},

    {Blink_PageLoad::kStyleNameHash, Blink_PageLoad::kStyleName},

    {Blink_PageLoad::kUpdateLayersNameHash, Blink_PageLoad::kUpdateLayersName},

    {Blink_PageLoad::kWaitForCommitNameHash, Blink_PageLoad::kWaitForCommitName},

        }
      }
    },

    {
      UINT64_C(16907734789798036504),
      {
        Blink_Script_AsyncScripts::kEntryName,
        {
          
    {Blink_Script_AsyncScripts::kAsyncScriptCountNameHash, Blink_Script_AsyncScripts::kAsyncScriptCountName},

        }
      }
    },

    {
      UINT64_C(397568092790313676),
      {
        Blink_UpdateTime::kEntryName,
        {
          
    {Blink_UpdateTime::kAnimateNameHash, Blink_UpdateTime::kAnimateName},

    {Blink_UpdateTime::kAnimatePercentageNameHash, Blink_UpdateTime::kAnimatePercentageName},

    {Blink_UpdateTime::kCompositingNameHash, Blink_UpdateTime::kCompositingName},

    {Blink_UpdateTime::kCompositingCommitNameHash, Blink_UpdateTime::kCompositingCommitName},

    {Blink_UpdateTime::kCompositingCommitPercentageNameHash, Blink_UpdateTime::kCompositingCommitPercentageName},

    {Blink_UpdateTime::kCompositingPercentageNameHash, Blink_UpdateTime::kCompositingPercentageName},

    {Blink_UpdateTime::kForcedStyleAndLayoutNameHash, Blink_UpdateTime::kForcedStyleAndLayoutName},

    {Blink_UpdateTime::kForcedStyleAndLayoutPercentageNameHash, Blink_UpdateTime::kForcedStyleAndLayoutPercentageName},

    {Blink_UpdateTime::kHandleInputEventsNameHash, Blink_UpdateTime::kHandleInputEventsName},

    {Blink_UpdateTime::kHandleInputEventsPercentageNameHash, Blink_UpdateTime::kHandleInputEventsPercentageName},

    {Blink_UpdateTime::kHitTestDocumentUpdateNameHash, Blink_UpdateTime::kHitTestDocumentUpdateName},

    {Blink_UpdateTime::kHitTestDocumentUpdatePercentageNameHash, Blink_UpdateTime::kHitTestDocumentUpdatePercentageName},

    {Blink_UpdateTime::kImplCompositorCommitNameHash, Blink_UpdateTime::kImplCompositorCommitName},

    {Blink_UpdateTime::kImplCompositorCommitPercentageNameHash, Blink_UpdateTime::kImplCompositorCommitPercentageName},

    {Blink_UpdateTime::kIntersectionObservationNameHash, Blink_UpdateTime::kIntersectionObservationName},

    {Blink_UpdateTime::kIntersectionObservationPercentageNameHash, Blink_UpdateTime::kIntersectionObservationPercentageName},

    {Blink_UpdateTime::kLayoutNameHash, Blink_UpdateTime::kLayoutName},

    {Blink_UpdateTime::kLayoutPercentageNameHash, Blink_UpdateTime::kLayoutPercentageName},

    {Blink_UpdateTime::kMainFrameNameHash, Blink_UpdateTime::kMainFrameName},

    {Blink_UpdateTime::kMainFrameIsBeforeFCPNameHash, Blink_UpdateTime::kMainFrameIsBeforeFCPName},

    {Blink_UpdateTime::kMainFrameReasonsNameHash, Blink_UpdateTime::kMainFrameReasonsName},

    {Blink_UpdateTime::kPaintNameHash, Blink_UpdateTime::kPaintName},

    {Blink_UpdateTime::kPaintPercentageNameHash, Blink_UpdateTime::kPaintPercentageName},

    {Blink_UpdateTime::kPrePaintNameHash, Blink_UpdateTime::kPrePaintName},

    {Blink_UpdateTime::kPrePaintPercentageNameHash, Blink_UpdateTime::kPrePaintPercentageName},

    {Blink_UpdateTime::kScrollingCoordinatorNameHash, Blink_UpdateTime::kScrollingCoordinatorName},

    {Blink_UpdateTime::kScrollingCoordinatorPercentageNameHash, Blink_UpdateTime::kScrollingCoordinatorPercentageName},

    {Blink_UpdateTime::kStyleNameHash, Blink_UpdateTime::kStyleName},

    {Blink_UpdateTime::kStylePercentageNameHash, Blink_UpdateTime::kStylePercentageName},

    {Blink_UpdateTime::kUpdateLayersNameHash, Blink_UpdateTime::kUpdateLayersName},

    {Blink_UpdateTime::kUpdateLayersPercentageNameHash, Blink_UpdateTime::kUpdateLayersPercentageName},

    {Blink_UpdateTime::kWaitForCommitNameHash, Blink_UpdateTime::kWaitForCommitName},

    {Blink_UpdateTime::kWaitForCommitPercentageNameHash, Blink_UpdateTime::kWaitForCommitPercentageName},

        }
      }
    },

    {
      UINT64_C(16486120572686381376),
      {
        Blink_UseCounter::kEntryName,
        {
          
    {Blink_UseCounter::kFeatureNameHash, Blink_UseCounter::kFeatureName},

    {Blink_UseCounter::kIsMainFrameFeatureNameHash, Blink_UseCounter::kIsMainFrameFeatureName},

        }
      }
    },

    {
      UINT64_C(18270520290100355082),
      {
        ClickInput::kEntryName,
        {
          
    {ClickInput::kExperimental_ClickInputBurstNameHash, ClickInput::kExperimental_ClickInputBurstName},

        }
      }
    },

    {
      UINT64_C(18003859069234917647),
      {
        Compositor_Rendering::kEntryName,
        {
          
    {Compositor_Rendering::kCheckerboardedImagesCountNameHash, Compositor_Rendering::kCheckerboardedImagesCountName},

        }
      }
    },

    {
      UINT64_C(3378172330402895005),
      {
        Compositor_UserInteraction::kEntryName,
        {
          
    {Compositor_UserInteraction::kCheckerboardedContentAreaNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaName},

    {Compositor_UserInteraction::kCheckerboardedContentAreaRatioNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaRatioName},

    {Compositor_UserInteraction::kCheckerboardedImagesCountNameHash, Compositor_UserInteraction::kCheckerboardedImagesCountName},

    {Compositor_UserInteraction::kNumMissingTilesNameHash, Compositor_UserInteraction::kNumMissingTilesName},

        }
      }
    },

    {
      UINT64_C(11375675958515902207),
      {
        ContactsPicker_ShareStatistics::kEntryName,
        {
          
    {ContactsPicker_ShareStatistics::kPropertiesRequestedNameHash, ContactsPicker_ShareStatistics::kPropertiesRequestedName},

    {ContactsPicker_ShareStatistics::kSelectCountNameHash, ContactsPicker_ShareStatistics::kSelectCountName},

    {ContactsPicker_ShareStatistics::kSelectPercentageNameHash, ContactsPicker_ShareStatistics::kSelectPercentageName},

        }
      }
    },

    {
      UINT64_C(7195670717417274603),
      {
        ContentIndex_Added::kEntryName,
        {
          
    {ContentIndex_Added::kCategoryNameHash, ContentIndex_Added::kCategoryName},

        }
      }
    },

    {
      UINT64_C(8302809238691294596),
      {
        ContentIndex_DeletedByUser::kEntryName,
        {
          
    {ContentIndex_DeletedByUser::kDeletedNameHash, ContentIndex_DeletedByUser::kDeletedName},

        }
      }
    },

    {
      UINT64_C(4039427715416584382),
      {
        ContentIndex_Opened::kEntryName,
        {
          
    {ContentIndex_Opened::kIsOfflineNameHash, ContentIndex_Opened::kIsOfflineName},

        }
      }
    },

    {
      UINT64_C(1205887675013444985),
      {
        ContextMenuAndroid_Selected::kEntryName,
        {
          
    {ContextMenuAndroid_Selected::kActionNameHash, ContextMenuAndroid_Selected::kActionName},

        }
      }
    },

    {
      UINT64_C(12646817710005836743),
      {
        ContextMenuAndroid_Shown::kEntryName,
        {
          
    {ContextMenuAndroid_Shown::kSearchByImageNameHash, ContextMenuAndroid_Shown::kSearchByImageName},

    {ContextMenuAndroid_Shown::kSearchWithGoogleLensNameHash, ContextMenuAndroid_Shown::kSearchWithGoogleLensName},

    {ContextMenuAndroid_Shown::kShopWithGoogleLensNameHash, ContextMenuAndroid_Shown::kShopWithGoogleLensName},

        }
      }
    },

    {
      UINT64_C(14879419826968794335),
      {
        ContextualSearch::kEntryName,
        {
          
    {ContextualSearch::kDidOptInNameHash, ContextualSearch::kDidOptInName},

    {ContextualSearch::kDurationAfterScrollMsNameHash, ContextualSearch::kDurationAfterScrollMsName},

    {ContextualSearch::kEntityImpressionsCountNameHash, ContextualSearch::kEntityImpressionsCountName},

    {ContextualSearch::kEntityOpensCountNameHash, ContextualSearch::kEntityOpensCountName},

    {ContextualSearch::kFontSizeNameHash, ContextualSearch::kFontSizeName},

    {ContextualSearch::kIsEntityNameHash, ContextualSearch::kIsEntityName},

    {ContextualSearch::kIsEntityEligibleNameHash, ContextualSearch::kIsEntityEligibleName},

    {ContextualSearch::kIsHttpNameHash, ContextualSearch::kIsHttpName},

    {ContextualSearch::kIsLanguageMismatchNameHash, ContextualSearch::kIsLanguageMismatchName},

    {ContextualSearch::kIsLongWordNameHash, ContextualSearch::kIsLongWordName},

    {ContextualSearch::kIsSecondTapOverrideNameHash, ContextualSearch::kIsSecondTapOverrideName},

    {ContextualSearch::kIsShortWordNameHash, ContextualSearch::kIsShortWordName},

    {ContextualSearch::kIsWordEdgeNameHash, ContextualSearch::kIsWordEdgeName},

    {ContextualSearch::kOpenCountNameHash, ContextualSearch::kOpenCountName},

    {ContextualSearch::kOutcomeRankerDidPredictNameHash, ContextualSearch::kOutcomeRankerDidPredictName},

    {ContextualSearch::kOutcomeRankerPredictionNameHash, ContextualSearch::kOutcomeRankerPredictionName},

    {ContextualSearch::kOutcomeRankerPredictionScoreNameHash, ContextualSearch::kOutcomeRankerPredictionScoreName},

    {ContextualSearch::kOutcomeWasCardsDataShownNameHash, ContextualSearch::kOutcomeWasCardsDataShownName},

    {ContextualSearch::kOutcomeWasPanelOpenedNameHash, ContextualSearch::kOutcomeWasPanelOpenedName},

    {ContextualSearch::kOutcomeWasQuickActionClickedNameHash, ContextualSearch::kOutcomeWasQuickActionClickedName},

    {ContextualSearch::kOutcomeWasQuickAnswerSeenNameHash, ContextualSearch::kOutcomeWasQuickAnswerSeenName},

    {ContextualSearch::kPortionOfElementNameHash, ContextualSearch::kPortionOfElementName},

    {ContextualSearch::kPrevious28DayCtrPercentNameHash, ContextualSearch::kPrevious28DayCtrPercentName},

    {ContextualSearch::kPrevious28DayImpressionsCountNameHash, ContextualSearch::kPrevious28DayImpressionsCountName},

    {ContextualSearch::kPreviousWeekCtrPercentNameHash, ContextualSearch::kPreviousWeekCtrPercentName},

    {ContextualSearch::kPreviousWeekImpressionsCountNameHash, ContextualSearch::kPreviousWeekImpressionsCountName},

    {ContextualSearch::kQuickActionImpressionsCountNameHash, ContextualSearch::kQuickActionImpressionsCountName},

    {ContextualSearch::kQuickActionsIgnoredNameHash, ContextualSearch::kQuickActionsIgnoredName},

    {ContextualSearch::kQuickActionsTakenNameHash, ContextualSearch::kQuickActionsTakenName},

    {ContextualSearch::kQuickAnswerCountNameHash, ContextualSearch::kQuickAnswerCountName},

    {ContextualSearch::kScreenTopDpsNameHash, ContextualSearch::kScreenTopDpsName},

    {ContextualSearch::kTapCountNameHash, ContextualSearch::kTapCountName},

    {ContextualSearch::kTapDurationMsNameHash, ContextualSearch::kTapDurationMsName},

    {ContextualSearch::kWasScreenBottomNameHash, ContextualSearch::kWasScreenBottomName},

        }
      }
    },

    {
      UINT64_C(988984496812825435),
      {
        CPUUsageMeasurement::kEntryName,
        {
          
    {CPUUsageMeasurement::kCPUUsageNameHash, CPUUsageMeasurement::kCPUUsageName},

    {CPUUsageMeasurement::kEventTypeNameHash, CPUUsageMeasurement::kEventTypeName},

    {CPUUsageMeasurement::kIsVisibleNameHash, CPUUsageMeasurement::kIsVisibleName},

    {CPUUsageMeasurement::kNumberOfCoresidentTabsNameHash, CPUUsageMeasurement::kNumberOfCoresidentTabsName},

    {CPUUsageMeasurement::kObservationWindowSizeMsNameHash, CPUUsageMeasurement::kObservationWindowSizeMsName},

    {CPUUsageMeasurement::kProcessUptimeMsNameHash, CPUUsageMeasurement::kProcessUptimeMsName},

        }
      }
    },

    {
      UINT64_C(26394013458683718),
      {
        DataReductionProxy::kEntryName,
        {
          
    {DataReductionProxy::kDataSaverPageUUIDNameHash, DataReductionProxy::kDataSaverPageUUIDName},

    {DataReductionProxy::kEstimatedOriginalNetworkBytesNameHash, DataReductionProxy::kEstimatedOriginalNetworkBytesName},

        }
      }
    },

    {
      UINT64_C(17687503538123373506),
      {
        Document_OutliveTimeAfterShutdown::kEntryName,
        {
          
    {Document_OutliveTimeAfterShutdown::kGCCountNameHash, Document_OutliveTimeAfterShutdown::kGCCountName},

        }
      }
    },

    {
      UINT64_C(2704655726834470033),
      {
        DocumentCreated::kEntryName,
        {
          
    {DocumentCreated::kIsCrossOriginFrameNameHash, DocumentCreated::kIsCrossOriginFrameName},

    {DocumentCreated::kIsMainFrameNameHash, DocumentCreated::kIsMainFrameName},

    {DocumentCreated::kNavigationSourceIdNameHash, DocumentCreated::kNavigationSourceIdName},

        }
      }
    },

    {
      UINT64_C(9818692869640581957),
      {
        Download_Completed::kEntryName,
        {
          
    {Download_Completed::kBytesWastedNameHash, Download_Completed::kBytesWastedName},

    {Download_Completed::kDownloadIdNameHash, Download_Completed::kDownloadIdName},

    {Download_Completed::kResultingFileSizeNameHash, Download_Completed::kResultingFileSizeName},

    {Download_Completed::kTimeSinceStartNameHash, Download_Completed::kTimeSinceStartName},

        }
      }
    },

    {
      UINT64_C(9706055097174303),
      {
        Download_Interrupted::kEntryName,
        {
          
    {Download_Interrupted::kBytesWastedNameHash, Download_Interrupted::kBytesWastedName},

    {Download_Interrupted::kChangeInFileSizeNameHash, Download_Interrupted::kChangeInFileSizeName},

    {Download_Interrupted::kDownloadIdNameHash, Download_Interrupted::kDownloadIdName},

    {Download_Interrupted::kReasonNameHash, Download_Interrupted::kReasonName},

    {Download_Interrupted::kResultingFileSizeNameHash, Download_Interrupted::kResultingFileSizeName},

    {Download_Interrupted::kTimeSinceStartNameHash, Download_Interrupted::kTimeSinceStartName},

        }
      }
    },

    {
      UINT64_C(9188207819461355990),
      {
        Download_Resumed::kEntryName,
        {
          
    {Download_Resumed::kDownloadIdNameHash, Download_Resumed::kDownloadIdName},

    {Download_Resumed::kModeNameHash, Download_Resumed::kModeName},

    {Download_Resumed::kTimeSinceStartNameHash, Download_Resumed::kTimeSinceStartName},

        }
      }
    },

    {
      UINT64_C(2153997617158303225),
      {
        Download_Started::kEntryName,
        {
          
    {Download_Started::kDownloadConnectionSecurityNameHash, Download_Started::kDownloadConnectionSecurityName},

    {Download_Started::kDownloadIdNameHash, Download_Started::kDownloadIdName},

    {Download_Started::kDownloadSourceNameHash, Download_Started::kDownloadSourceName},

    {Download_Started::kFileTypeNameHash, Download_Started::kFileTypeName},

    {Download_Started::kIsSameHostDownloadNameHash, Download_Started::kIsSameHostDownloadName},

        }
      }
    },

    {
      UINT64_C(12255255036748617486),
      {
        Event_ScrollBegin_Touch::kEntryName,
        {
          
    {Event_ScrollBegin_Touch::kIsMainThreadNameHash, Event_ScrollBegin_Touch::kIsMainThreadName},

    {Event_ScrollBegin_Touch::kTimeToHandledNameHash, Event_ScrollBegin_Touch::kTimeToHandledName},

    {Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginName},

        }
      }
    },

    {
      UINT64_C(15188233126885586509),
      {
        Event_ScrollBegin_Wheel::kEntryName,
        {
          
    {Event_ScrollBegin_Wheel::kIsMainThreadNameHash, Event_ScrollBegin_Wheel::kIsMainThreadName},

    {Event_ScrollBegin_Wheel::kTimeToHandledNameHash, Event_ScrollBegin_Wheel::kTimeToHandledName},

    {Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginName},

        }
      }
    },

    {
      UINT64_C(7257623327097011244),
      {
        Event_ScrollUpdate_Touch::kEntryName,
        {
          
    {Event_ScrollUpdate_Touch::kIsMainThreadNameHash, Event_ScrollUpdate_Touch::kIsMainThreadName},

    {Event_ScrollUpdate_Touch::kTimeToHandledNameHash, Event_ScrollUpdate_Touch::kTimeToHandledName},

    {Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginName},

        }
      }
    },

    {
      UINT64_C(12963707033129547010),
      {
        Event_ScrollUpdate_Wheel::kEntryName,
        {
          
    {Event_ScrollUpdate_Wheel::kIsMainThreadNameHash, Event_ScrollUpdate_Wheel::kIsMainThreadName},

    {Event_ScrollUpdate_Wheel::kTimeToHandledNameHash, Event_ScrollUpdate_Wheel::kTimeToHandledName},

    {Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginName},

        }
      }
    },

    {
      UINT64_C(7056658383170956797),
      {
        Extensions_CrossOriginFetchFromContentScript3::kEntryName,
        {
          
    {Extensions_CrossOriginFetchFromContentScript3::kEventHappenedNameHash, Extensions_CrossOriginFetchFromContentScript3::kEventHappenedName},

        }
      }
    },

    {
      UINT64_C(14096131912271921055),
      {
        FontMatchAttempts::kEntryName,
        {
          
    {FontMatchAttempts::kLoadContextNameHash, FontMatchAttempts::kLoadContextName},

    {FontMatchAttempts::kLocalFontFailuresNameHash, FontMatchAttempts::kLocalFontFailuresName},

    {FontMatchAttempts::kLocalFontSuccessesNameHash, FontMatchAttempts::kLocalFontSuccessesName},

    {FontMatchAttempts::kSystemFontFamilyFailuresNameHash, FontMatchAttempts::kSystemFontFamilyFailuresName},

    {FontMatchAttempts::kSystemFontFamilySuccessesNameHash, FontMatchAttempts::kSystemFontFamilySuccessesName},

    {FontMatchAttempts::kWebFontFamilyFailuresNameHash, FontMatchAttempts::kWebFontFamilyFailuresName},

    {FontMatchAttempts::kWebFontFamilySuccessesNameHash, FontMatchAttempts::kWebFontFamilySuccessesName},

        }
      }
    },

    {
      UINT64_C(17713702562453741093),
      {
        GeneratedNavigation::kEntryName,
        {
          
    {GeneratedNavigation::kFinalURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFinalURLIsDefaultSearchEngineName},

    {GeneratedNavigation::kFinalURLIsHomePageNameHash, GeneratedNavigation::kFinalURLIsHomePageName},

    {GeneratedNavigation::kFirstURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFirstURLIsDefaultSearchEngineName},

    {GeneratedNavigation::kFirstURLIsHomePageNameHash, GeneratedNavigation::kFirstURLIsHomePageName},

        }
      }
    },

    {
      UINT64_C(3420244295988015024),
      {
        GoogleDocsOfflineExtension::kEntryName,
        {
          
    {GoogleDocsOfflineExtension::kResourceRequestedNameHash, GoogleDocsOfflineExtension::kResourceRequestedName},

        }
      }
    },

    {
      UINT64_C(11577416923418681607),
      {
        Graphics_Smoothness_EventLatency::kEntryName,
        {
          
    {Graphics_Smoothness_EventLatency::kActivationNameHash, Graphics_Smoothness_EventLatency::kActivationName},

    {Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameNameHash, Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameName},

    {Graphics_Smoothness_EventLatency::kBrowserToRendererCompositorNameHash, Graphics_Smoothness_EventLatency::kBrowserToRendererCompositorName},

    {Graphics_Smoothness_EventLatency::kCommitNameHash, Graphics_Smoothness_EventLatency::kCommitName},

    {Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameNameHash, Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameName},

    {Graphics_Smoothness_EventLatency::kEndCommitToActivationNameHash, Graphics_Smoothness_EventLatency::kEndCommitToActivationName},

    {Graphics_Smoothness_EventLatency::kEventTypeNameHash, Graphics_Smoothness_EventLatency::kEventTypeName},

    {Graphics_Smoothness_EventLatency::kScrollInputTypeNameHash, Graphics_Smoothness_EventLatency::kScrollInputTypeName},

    {Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitNameHash, Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitName},

    {Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash, Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameName},

    {Graphics_Smoothness_EventLatency::kTotalLatencyNameHash, Graphics_Smoothness_EventLatency::kTotalLatencyName},

    {Graphics_Smoothness_EventLatency::kTotalLatencyToSwapEndNameHash, Graphics_Smoothness_EventLatency::kTotalLatencyToSwapEndName},

        }
      }
    },

    {
      UINT64_C(4259890394998283936),
      {
        Graphics_Smoothness_Latency::kEntryName,
        {
          
    {Graphics_Smoothness_Latency::kActivationNameHash, Graphics_Smoothness_Latency::kActivationName},

    {Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameNameHash, Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameName},

    {Graphics_Smoothness_Latency::kCommitNameHash, Graphics_Smoothness_Latency::kCommitName},

    {Graphics_Smoothness_Latency::kCompositorAnimationNameHash, Graphics_Smoothness_Latency::kCompositorAnimationName},

    {Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameNameHash, Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameName},

    {Graphics_Smoothness_Latency::kEndCommitToActivationNameHash, Graphics_Smoothness_Latency::kEndCommitToActivationName},

    {Graphics_Smoothness_Latency::kMainThreadAnimationNameHash, Graphics_Smoothness_Latency::kMainThreadAnimationName},

    {Graphics_Smoothness_Latency::kMissedFrameNameHash, Graphics_Smoothness_Latency::kMissedFrameName},

    {Graphics_Smoothness_Latency::kPinchZoomNameHash, Graphics_Smoothness_Latency::kPinchZoomName},

    {Graphics_Smoothness_Latency::kRAFNameHash, Graphics_Smoothness_Latency::kRAFName},

    {Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName},

    {Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash, Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName},

    {Graphics_Smoothness_Latency::kTotalLatencyNameHash, Graphics_Smoothness_Latency::kTotalLatencyName},

    {Graphics_Smoothness_Latency::kTouchScrollNameHash, Graphics_Smoothness_Latency::kTouchScrollName},

    {Graphics_Smoothness_Latency::kUnknownNameHash, Graphics_Smoothness_Latency::kUnknownName},

    {Graphics_Smoothness_Latency::kVideoNameHash, Graphics_Smoothness_Latency::kVideoName},

    {Graphics_Smoothness_Latency::kWheelScrollNameHash, Graphics_Smoothness_Latency::kWheelScrollName},

        }
      }
    },

    {
      UINT64_C(6831778698353217167),
      {
        Graphics_Smoothness_PercentDroppedFrames::kEntryName,
        {
          
    {Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsName},

    {Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsName},

    {Graphics_Smoothness_PercentDroppedFrames::kAllSequencesNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllSequencesName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_UniversalNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_UniversalName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoName},

    {Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_UniversalNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_UniversalName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoName},

    {Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_CompositorAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_CompositorAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_MainThreadAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_MainThreadAnimationName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_RAFNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_RAFName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_TouchScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_TouchScrollName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_UniversalNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_UniversalName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_VideoNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_VideoName},

    {Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_WheelScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_WheelScrollName},

        }
      }
    },

    {
      UINT64_C(17985071802125984440),
      {
        HistoryManipulationIntervention::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(6390056345493314213),
      {
        HistoryNavigation::kEntryName,
        {
          
    {HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheNameHash, HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheName},

    {HistoryNavigation::kBackForwardCache_NotRestoredReasonsNameHash, HistoryNavigation::kBackForwardCache_NotRestoredReasonsName},

    {HistoryNavigation::kCrossOriginSubframesFeaturesNameHash, HistoryNavigation::kCrossOriginSubframesFeaturesName},

    {HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash, HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName},

    {HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentNameHash, HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentName},

    {HistoryNavigation::kMainFrameFeaturesNameHash, HistoryNavigation::kMainFrameFeaturesName},

    {HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentNameHash, HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentName},

    {HistoryNavigation::kSameOriginSubframesFeaturesNameHash, HistoryNavigation::kSameOriginSubframesFeaturesName},

    {HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentNameHash, HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentName},

        }
      }
    },

    {
      UINT64_C(287024497009309687),
      {
        Identifiability::kEntryName,
        {
          
    {Identifiability::kStudyGeneration_626NameHash, Identifiability::kStudyGeneration_626Name},

        }
      }
    },

    {
      UINT64_C(2784102704372436909),
      {
        InputEvent::kEntryName,
        {
          
    {InputEvent::kInteractiveTiming_InputDelayNameHash, InputEvent::kInteractiveTiming_InputDelayName},

    {InputEvent::kInteractiveTiming_ProcessingTimeNameHash, InputEvent::kInteractiveTiming_ProcessingTimeName},

        }
      }
    },

    {
      UINT64_C(10386387717857957103),
      {
        Intervention_DocumentWrite_ScriptBlock::kEntryName,
        {
          
    {Intervention_DocumentWrite_ScriptBlock::kDisabled_ReloadNameHash, Intervention_DocumentWrite_ScriptBlock::kDisabled_ReloadName},

    {Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteNameHash, Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptExecutionFromDocumentWriteName},

    {Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteNameHash, Intervention_DocumentWrite_ScriptBlock::kParseTiming_ParseBlockedOnScriptLoadFromDocumentWriteName},

        }
      }
    },

    {
      UINT64_C(3999691266874322037),
      {
        IOS_FindInPageSearchMatches::kEntryName,
        {
          
    {IOS_FindInPageSearchMatches::kHasMatchesNameHash, IOS_FindInPageSearchMatches::kHasMatchesName},

        }
      }
    },

    {
      UINT64_C(4631281682778806273),
      {
        IOS_PageZoomChanged::kEntryName,
        {
          
    {IOS_PageZoomChanged::kContentSizeCategoryNameHash, IOS_PageZoomChanged::kContentSizeCategoryName},

    {IOS_PageZoomChanged::kOverallZoomLevelNameHash, IOS_PageZoomChanged::kOverallZoomLevelName},

    {IOS_PageZoomChanged::kUserZoomLevelNameHash, IOS_PageZoomChanged::kUserZoomLevelName},

        }
      }
    },

    {
      UINT64_C(10713578431670288986),
      {
        IOS_RendererGone::kEntryName,
        {
          
    {IOS_RendererGone::kAliveRecentlyRendererCountNameHash, IOS_RendererGone::kAliveRecentlyRendererCountName},

    {IOS_RendererGone::kAliveRendererCountNameHash, IOS_RendererGone::kAliveRendererCountName},

    {IOS_RendererGone::kInForegroundNameHash, IOS_RendererGone::kInForegroundName},

    {IOS_RendererGone::kSawMemoryWarningNameHash, IOS_RendererGone::kSawMemoryWarningName},

        }
      }
    },

    {
      UINT64_C(18173210514398479989),
      {
        IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryName,
        {
          
    {IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchNameHash, IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchName},

        }
      }
    },

    {
      UINT64_C(1389206047285929549),
      {
        Layout_DisplayCutout_StateChanged::kEntryName,
        {
          
    {Layout_DisplayCutout_StateChanged::kIsMainFrameNameHash, Layout_DisplayCutout_StateChanged::kIsMainFrameName},

    {Layout_DisplayCutout_StateChanged::kSafeAreasPresentNameHash, Layout_DisplayCutout_StateChanged::kSafeAreasPresentName},

    {Layout_DisplayCutout_StateChanged::kViewportFit_AppliedNameHash, Layout_DisplayCutout_StateChanged::kViewportFit_AppliedName},

    {Layout_DisplayCutout_StateChanged::kViewportFit_IgnoredReasonNameHash, Layout_DisplayCutout_StateChanged::kViewportFit_IgnoredReasonName},

    {Layout_DisplayCutout_StateChanged::kViewportFit_SuppliedNameHash, Layout_DisplayCutout_StateChanged::kViewportFit_SuppliedName},

        }
      }
    },

    {
      UINT64_C(17180165945688341623),
      {
        LoadingPredictor::kEntryName,
        {
          
    {LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsNameHash, LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsName},

    {LoadingPredictor::kLocalPredictionOriginsNameHash, LoadingPredictor::kLocalPredictionOriginsName},

    {LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash, LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsName},

    {LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash, LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName},

    {LoadingPredictor::kOptimizationGuidePredictionDecisionNameHash, LoadingPredictor::kOptimizationGuidePredictionDecisionName},

    {LoadingPredictor::kOptimizationGuidePredictionOriginsNameHash, LoadingPredictor::kOptimizationGuidePredictionOriginsName},

    {LoadingPredictor::kOptimizationGuidePredictionSubresourcesNameHash, LoadingPredictor::kOptimizationGuidePredictionSubresourcesName},

        }
      }
    },

    {
      UINT64_C(5563841616204153427),
      {
        LocalNetworkRequests::kEntryName,
        {
          
    {LocalNetworkRequests::kCount_FailedNameHash, LocalNetworkRequests::kCount_FailedName},

    {LocalNetworkRequests::kCount_SuccessfulNameHash, LocalNetworkRequests::kCount_SuccessfulName},

    {LocalNetworkRequests::kPortTypeNameHash, LocalNetworkRequests::kPortTypeName},

    {LocalNetworkRequests::kResourceTypeNameHash, LocalNetworkRequests::kResourceTypeName},

        }
      }
    },

    {
      UINT64_C(6455694443766360259),
      {
        LookalikeUrl_NavigationSuggestion::kEntryName,
        {
          
    {LookalikeUrl_NavigationSuggestion::kMatchTypeNameHash, LookalikeUrl_NavigationSuggestion::kMatchTypeName},

    {LookalikeUrl_NavigationSuggestion::kUserActionNameHash, LookalikeUrl_NavigationSuggestion::kUserActionName},

        }
      }
    },

    {
      UINT64_C(17528121675680665933),
      {
        MainFrameNavigation::kEntryName,
        {
          
    {MainFrameNavigation::kDidCommitNameHash, MainFrameNavigation::kDidCommitName},

        }
      }
    },

    {
      UINT64_C(15357501003006382777),
      {
        Media_Autoplay_Attempt::kEntryName,
        {
          
    {Media_Autoplay_Attempt::kAudioTrackNameHash, Media_Autoplay_Attempt::kAudioTrackName},

    {Media_Autoplay_Attempt::kHighMediaEngagementNameHash, Media_Autoplay_Attempt::kHighMediaEngagementName},

    {Media_Autoplay_Attempt::kMutedNameHash, Media_Autoplay_Attempt::kMutedName},

    {Media_Autoplay_Attempt::kSourceNameHash, Media_Autoplay_Attempt::kSourceName},

    {Media_Autoplay_Attempt::kUserGestureRequiredNameHash, Media_Autoplay_Attempt::kUserGestureRequiredName},

    {Media_Autoplay_Attempt::kUserGestureStatusNameHash, Media_Autoplay_Attempt::kUserGestureStatusName},

    {Media_Autoplay_Attempt::kVideoTrackNameHash, Media_Autoplay_Attempt::kVideoTrackName},

        }
      }
    },

    {
      UINT64_C(2039378813737092278),
      {
        Media_Autoplay_AudioContext::kEntryName,
        {
          
    {Media_Autoplay_AudioContext::kSourceNodeStartedNameHash, Media_Autoplay_AudioContext::kSourceNodeStartedName},

    {Media_Autoplay_AudioContext::kStatusNameHash, Media_Autoplay_AudioContext::kStatusName},

    {Media_Autoplay_AudioContext::kUnlockTypeNameHash, Media_Autoplay_AudioContext::kUnlockTypeName},

        }
      }
    },

    {
      UINT64_C(3015822386723746523),
      {
        Media_Autoplay_Muted_UnmuteAction::kEntryName,
        {
          
    {Media_Autoplay_Muted_UnmuteAction::kResultNameHash, Media_Autoplay_Muted_UnmuteAction::kResultName},

    {Media_Autoplay_Muted_UnmuteAction::kSourceNameHash, Media_Autoplay_Muted_UnmuteAction::kSourceName},

        }
      }
    },

    {
      UINT64_C(8416658001170131658),
      {
        Media_BasicPlayback::kEntryName,
        {
          
    {Media_BasicPlayback::kAudioCodecNameHash, Media_BasicPlayback::kAudioCodecName},

    {Media_BasicPlayback::kAudioCodecProfileNameHash, Media_BasicPlayback::kAudioCodecProfileName},

    {Media_BasicPlayback::kAudioDecoderNameNameHash, Media_BasicPlayback::kAudioDecoderNameName},

    {Media_BasicPlayback::kAudioEncryptionSchemeNameHash, Media_BasicPlayback::kAudioEncryptionSchemeName},

    {Media_BasicPlayback::kAutoplayInitiatedNameHash, Media_BasicPlayback::kAutoplayInitiatedName},

    {Media_BasicPlayback::kCompletedRebuffersCountNameHash, Media_BasicPlayback::kCompletedRebuffersCountName},

    {Media_BasicPlayback::kCompletedRebuffersDurationNameHash, Media_BasicPlayback::kCompletedRebuffersDurationName},

    {Media_BasicPlayback::kDurationNameHash, Media_BasicPlayback::kDurationName},

    {Media_BasicPlayback::kHasAudioNameHash, Media_BasicPlayback::kHasAudioName},

    {Media_BasicPlayback::kHasVideoNameHash, Media_BasicPlayback::kHasVideoName},

    {Media_BasicPlayback::kIsBackgroundNameHash, Media_BasicPlayback::kIsBackgroundName},

    {Media_BasicPlayback::kIsEMENameHash, Media_BasicPlayback::kIsEMEName},

    {Media_BasicPlayback::kIsMSENameHash, Media_BasicPlayback::kIsMSEName},

    {Media_BasicPlayback::kIsMutedNameHash, Media_BasicPlayback::kIsMutedName},

    {Media_BasicPlayback::kIsTopFrameNameHash, Media_BasicPlayback::kIsTopFrameName},

    {Media_BasicPlayback::kLastPipelineStatusNameHash, Media_BasicPlayback::kLastPipelineStatusName},

    {Media_BasicPlayback::kMeanTimeBetweenRebuffersNameHash, Media_BasicPlayback::kMeanTimeBetweenRebuffersName},

    {Media_BasicPlayback::kPlayerIDNameHash, Media_BasicPlayback::kPlayerIDName},

    {Media_BasicPlayback::kRebuffersCountNameHash, Media_BasicPlayback::kRebuffersCountName},

    {Media_BasicPlayback::kVideoCodecNameHash, Media_BasicPlayback::kVideoCodecName},

    {Media_BasicPlayback::kVideoCodecProfileNameHash, Media_BasicPlayback::kVideoCodecProfileName},

    {Media_BasicPlayback::kVideoDecoderNameNameHash, Media_BasicPlayback::kVideoDecoderNameName},

    {Media_BasicPlayback::kVideoEncryptionSchemeNameHash, Media_BasicPlayback::kVideoEncryptionSchemeName},

    {Media_BasicPlayback::kVideoFramesDecodedNameHash, Media_BasicPlayback::kVideoFramesDecodedName},

    {Media_BasicPlayback::kVideoFramesDroppedNameHash, Media_BasicPlayback::kVideoFramesDroppedName},

    {Media_BasicPlayback::kVideoNaturalHeightNameHash, Media_BasicPlayback::kVideoNaturalHeightName},

    {Media_BasicPlayback::kVideoNaturalWidthNameHash, Media_BasicPlayback::kVideoNaturalWidthName},

    {Media_BasicPlayback::kWatchTimeNameHash, Media_BasicPlayback::kWatchTimeName},

    {Media_BasicPlayback::kWatchTime_ACNameHash, Media_BasicPlayback::kWatchTime_ACName},

    {Media_BasicPlayback::kWatchTime_BatteryNameHash, Media_BasicPlayback::kWatchTime_BatteryName},

    {Media_BasicPlayback::kWatchTime_DisplayFullscreenNameHash, Media_BasicPlayback::kWatchTime_DisplayFullscreenName},

    {Media_BasicPlayback::kWatchTime_DisplayInlineNameHash, Media_BasicPlayback::kWatchTime_DisplayInlineName},

    {Media_BasicPlayback::kWatchTime_DisplayPictureInPictureNameHash, Media_BasicPlayback::kWatchTime_DisplayPictureInPictureName},

    {Media_BasicPlayback::kWatchTime_NativeControlsOffNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOffName},

    {Media_BasicPlayback::kWatchTime_NativeControlsOnNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOnName},

        }
      }
    },

    {
      UINT64_C(7968428823878627316),
      {
        Media_EME_ApiPromiseRejection::kEntryName,
        {
          
    {Media_EME_ApiPromiseRejection::kApiNameHash, Media_EME_ApiPromiseRejection::kApiName},

    {Media_EME_ApiPromiseRejection::kSystemCodeNameHash, Media_EME_ApiPromiseRejection::kSystemCodeName},

        }
      }
    },

    {
      UINT64_C(16664479587726188526),
      {
        Media_EME_CreateMediaKeys::kEntryName,
        {
          
    {Media_EME_CreateMediaKeys::kIsAdFrameNameHash, Media_EME_CreateMediaKeys::kIsAdFrameName},

    {Media_EME_CreateMediaKeys::kIsCrossOriginNameHash, Media_EME_CreateMediaKeys::kIsCrossOriginName},

    {Media_EME_CreateMediaKeys::kIsTopFrameNameHash, Media_EME_CreateMediaKeys::kIsTopFrameName},

    {Media_EME_CreateMediaKeys::kKeySystemNameHash, Media_EME_CreateMediaKeys::kKeySystemName},

        }
      }
    },

    {
      UINT64_C(14018069268047764723),
      {
        Media_EME_RequestMediaKeySystemAccess::kEntryName,
        {
          
    {Media_EME_RequestMediaKeySystemAccess::kIsAdFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsAdFrameName},

    {Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginNameHash, Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginName},

    {Media_EME_RequestMediaKeySystemAccess::kIsTopFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsTopFrameName},

    {Media_EME_RequestMediaKeySystemAccess::kKeySystemNameHash, Media_EME_RequestMediaKeySystemAccess::kKeySystemName},

    {Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesNameHash, Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesName},

    {Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessNameHash, Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessName},

    {Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessNameHash, Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessName},

        }
      }
    },

    {
      UINT64_C(886585293387977076),
      {
        Media_Engagement_SessionFinished::kEntryName,
        {
          
    {Media_Engagement_SessionFinished::kEngagement_IsHighNameHash, Media_Engagement_SessionFinished::kEngagement_IsHighName},

    {Media_Engagement_SessionFinished::kEngagement_ScoreNameHash, Media_Engagement_SessionFinished::kEngagement_ScoreName},

    {Media_Engagement_SessionFinished::kPlaybacks_TotalNameHash, Media_Engagement_SessionFinished::kPlaybacks_TotalName},

    {Media_Engagement_SessionFinished::kPlayer_Audible_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Audible_DeltaName},

    {Media_Engagement_SessionFinished::kPlayer_Significant_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Significant_DeltaName},

    {Media_Engagement_SessionFinished::kVisits_TotalNameHash, Media_Engagement_SessionFinished::kVisits_TotalName},

        }
      }
    },

    {
      UINT64_C(13016590436839167921),
      {
        Media_Engagement_ShortPlaybackIgnored::kEntryName,
        {
          
    {Media_Engagement_ShortPlaybackIgnored::kLengthNameHash, Media_Engagement_ShortPlaybackIgnored::kLengthName},

        }
      }
    },

    {
      UINT64_C(9905764244590677619),
      {
        Media_Feed_Discover::kEntryName,
        {
          
    {Media_Feed_Discover::kHasMediaFeedNameHash, Media_Feed_Discover::kHasMediaFeedName},

        }
      }
    },

    {
      UINT64_C(14701475071317937048),
      {
        Media_GlobalMediaControls_ActionButtonPressed::kEntryName,
        {
          
    {Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionNameHash, Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionName},

        }
      }
    },

    {
      UINT64_C(5140299263436558885),
      {
        Media_Learning_PredictionRecord::kEntryName,
        {
          
    {Media_Learning_PredictionRecord::kLearningTaskNameHash, Media_Learning_PredictionRecord::kLearningTaskName},

    {Media_Learning_PredictionRecord::kObservedValueNameHash, Media_Learning_PredictionRecord::kObservedValueName},

    {Media_Learning_PredictionRecord::kPredictedValueNameHash, Media_Learning_PredictionRecord::kPredictedValueName},

    {Media_Learning_PredictionRecord::kTrainingDataSizeNameHash, Media_Learning_PredictionRecord::kTrainingDataSizeName},

    {Media_Learning_PredictionRecord::kTrainingDataTotalWeightNameHash, Media_Learning_PredictionRecord::kTrainingDataTotalWeightName},

        }
      }
    },

    {
      UINT64_C(9485702385711484844),
      {
        Media_SiteMuted::kEntryName,
        {
          
    {Media_SiteMuted::kMuteReasonNameHash, Media_SiteMuted::kMuteReasonName},

        }
      }
    },

    {
      UINT64_C(4207699002180294249),
      {
        Media_VideoDecodePerfRecord::kEntryName,
        {
          
    {Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientName},

    {Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothName},

    {Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedName},

    {Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedName},

    {Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientName},

    {Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientName},

    {Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothName},

    {Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedName},

    {Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedName},

    {Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientName},

    {Media_VideoDecodePerfRecord::kVideo_CodecProfileNameHash, Media_VideoDecodePerfRecord::kVideo_CodecProfileName},

    {Media_VideoDecodePerfRecord::kVideo_EME_KeySystemNameHash, Media_VideoDecodePerfRecord::kVideo_EME_KeySystemName},

    {Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsNameHash, Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsName},

    {Media_VideoDecodePerfRecord::kVideo_FramesPerSecondNameHash, Media_VideoDecodePerfRecord::kVideo_FramesPerSecondName},

    {Media_VideoDecodePerfRecord::kVideo_InTopFrameNameHash, Media_VideoDecodePerfRecord::kVideo_InTopFrameName},

    {Media_VideoDecodePerfRecord::kVideo_NaturalHeightNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalHeightName},

    {Media_VideoDecodePerfRecord::kVideo_NaturalWidthNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalWidthName},

    {Media_VideoDecodePerfRecord::kVideo_PlayerIDNameHash, Media_VideoDecodePerfRecord::kVideo_PlayerIDName},

        }
      }
    },

    {
      UINT64_C(17314038096102597390),
      {
        Media_WebAudio_AudioContext_AudibleTime::kEntryName,
        {
          
    {Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeNameHash, Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeName},

    {Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameNameHash, Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameName},

        }
      }
    },

    {
      UINT64_C(14428460888229388079),
      {
        Media_WebMediaPlayerState::kEntryName,
        {
          
    {Media_WebMediaPlayerState::kContainerNameNameHash, Media_WebMediaPlayerState::kContainerNameName},

    {Media_WebMediaPlayerState::kFinalPipelineStatusNameHash, Media_WebMediaPlayerState::kFinalPipelineStatusName},

    {Media_WebMediaPlayerState::kIsEMENameHash, Media_WebMediaPlayerState::kIsEMEName},

    {Media_WebMediaPlayerState::kIsMSENameHash, Media_WebMediaPlayerState::kIsMSEName},

    {Media_WebMediaPlayerState::kIsTopFrameNameHash, Media_WebMediaPlayerState::kIsTopFrameName},

    {Media_WebMediaPlayerState::kPlayerIDNameHash, Media_WebMediaPlayerState::kPlayerIDName},

    {Media_WebMediaPlayerState::kTimeToFirstFrameNameHash, Media_WebMediaPlayerState::kTimeToFirstFrameName},

    {Media_WebMediaPlayerState::kTimeToMetadataNameHash, Media_WebMediaPlayerState::kTimeToMetadataName},

    {Media_WebMediaPlayerState::kTimeToPlayReadyNameHash, Media_WebMediaPlayerState::kTimeToPlayReadyName},

    {Media_WebMediaPlayerState::kURLSchemeNameHash, Media_WebMediaPlayerState::kURLSchemeName},

        }
      }
    },

    {
      UINT64_C(2088599620296425553),
      {
        MediaRouter_TabMirroringStarted::kEntryName,
        {
          
    {MediaRouter_TabMirroringStarted::kAudioStateNameHash, MediaRouter_TabMirroringStarted::kAudioStateName},

        }
      }
    },

    {
      UINT64_C(2958711939369432145),
      {
        Memory_Experimental::kEntryName,
        {
          
    {Memory_Experimental::kArrayBufferNameHash, Memory_Experimental::kArrayBufferName},

    {Memory_Experimental::kBlinkGCNameHash, Memory_Experimental::kBlinkGCName},

    {Memory_Experimental::kBlinkGC_AllocatedObjectsNameHash, Memory_Experimental::kBlinkGC_AllocatedObjectsName},

    {Memory_Experimental::kCanvasResourceProvider_SkSurfaceNameHash, Memory_Experimental::kCanvasResourceProvider_SkSurfaceName},

    {Memory_Experimental::kCommandBufferNameHash, Memory_Experimental::kCommandBufferName},

    {Memory_Experimental::kDiscardableNameHash, Memory_Experimental::kDiscardableName},

    {Memory_Experimental::kDownloadServiceNameHash, Memory_Experimental::kDownloadServiceName},

    {Memory_Experimental::kExtensions_ValueStoreNameHash, Memory_Experimental::kExtensions_ValueStoreName},

    {Memory_Experimental::kFontCachesNameHash, Memory_Experimental::kFontCachesName},

    {Memory_Experimental::kGpuMemoryNameHash, Memory_Experimental::kGpuMemoryName},

    {Memory_Experimental::kHistoryNameHash, Memory_Experimental::kHistoryName},

    {Memory_Experimental::kIsVisibleNameHash, Memory_Experimental::kIsVisibleName},

    {Memory_Experimental::kJavaHeapNameHash, Memory_Experimental::kJavaHeapName},

    {Memory_Experimental::kLevelDatabaseNameHash, Memory_Experimental::kLevelDatabaseName},

    {Memory_Experimental::kMallocNameHash, Memory_Experimental::kMallocName},

    {Memory_Experimental::kMalloc_AllocatedObjectsNameHash, Memory_Experimental::kMalloc_AllocatedObjectsName},

    {Memory_Experimental::kNetNameHash, Memory_Experimental::kNetName},

    {Memory_Experimental::kNet_UrlRequestContextNameHash, Memory_Experimental::kNet_UrlRequestContextName},

    {Memory_Experimental::kNumberOfAdSubframesNameHash, Memory_Experimental::kNumberOfAdSubframesName},

    {Memory_Experimental::kNumberOfArrayBufferContentsNameHash, Memory_Experimental::kNumberOfArrayBufferContentsName},

    {Memory_Experimental::kNumberOfDetachedScriptStatesNameHash, Memory_Experimental::kNumberOfDetachedScriptStatesName},

    {Memory_Experimental::kNumberOfDocumentsNameHash, Memory_Experimental::kNumberOfDocumentsName},

    {Memory_Experimental::kNumberOfExtensionsNameHash, Memory_Experimental::kNumberOfExtensionsName},

    {Memory_Experimental::kNumberOfFramesNameHash, Memory_Experimental::kNumberOfFramesName},

    {Memory_Experimental::kNumberOfLayoutObjectsNameHash, Memory_Experimental::kNumberOfLayoutObjectsName},

    {Memory_Experimental::kNumberOfMojoHandlesNameHash, Memory_Experimental::kNumberOfMojoHandlesName},

    {Memory_Experimental::kNumberOfNodesNameHash, Memory_Experimental::kNumberOfNodesName},

    {Memory_Experimental::kNumberOfWebMediaPlayersNameHash, Memory_Experimental::kNumberOfWebMediaPlayersName},

    {Memory_Experimental::kOmniboxSuggestionsNameHash, Memory_Experimental::kOmniboxSuggestionsName},

    {Memory_Experimental::kPartitionAllocNameHash, Memory_Experimental::kPartitionAllocName},

    {Memory_Experimental::kPartitionAlloc_AllocatedObjectsNameHash, Memory_Experimental::kPartitionAlloc_AllocatedObjectsName},

    {Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferName},

    {Memory_Experimental::kPartitionAlloc_Partitions_BufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_BufferName},

    {Memory_Experimental::kPartitionAlloc_Partitions_FastMallocNameHash, Memory_Experimental::kPartitionAlloc_Partitions_FastMallocName},

    {Memory_Experimental::kPartitionAlloc_Partitions_LayoutNameHash, Memory_Experimental::kPartitionAlloc_Partitions_LayoutName},

    {Memory_Experimental::kPrivateMemoryFootprintNameHash, Memory_Experimental::kPrivateMemoryFootprintName},

    {Memory_Experimental::kPrivateSwapFootprintNameHash, Memory_Experimental::kPrivateSwapFootprintName},

    {Memory_Experimental::kProcessTypeNameHash, Memory_Experimental::kProcessTypeName},

    {Memory_Experimental::kResidentNameHash, Memory_Experimental::kResidentName},

    {Memory_Experimental::kSharedMemoryFootprintNameHash, Memory_Experimental::kSharedMemoryFootprintName},

    {Memory_Experimental::kSiteStorageNameHash, Memory_Experimental::kSiteStorageName},

    {Memory_Experimental::kSiteStorage_BlobStorageNameHash, Memory_Experimental::kSiteStorage_BlobStorageName},

    {Memory_Experimental::kSiteStorage_IndexDBNameHash, Memory_Experimental::kSiteStorage_IndexDBName},

    {Memory_Experimental::kSiteStorage_LocalStorageNameHash, Memory_Experimental::kSiteStorage_LocalStorageName},

    {Memory_Experimental::kSiteStorage_SessionStorageNameHash, Memory_Experimental::kSiteStorage_SessionStorageName},

    {Memory_Experimental::kSkiaNameHash, Memory_Experimental::kSkiaName},

    {Memory_Experimental::kSkia_SkGlyphCacheNameHash, Memory_Experimental::kSkia_SkGlyphCacheName},

    {Memory_Experimental::kSkia_SkResourceCacheNameHash, Memory_Experimental::kSkia_SkResourceCacheName},

    {Memory_Experimental::kSqliteNameHash, Memory_Experimental::kSqliteName},

    {Memory_Experimental::kSyncNameHash, Memory_Experimental::kSyncName},

    {Memory_Experimental::kTabRestoreNameHash, Memory_Experimental::kTabRestoreName},

    {Memory_Experimental::kTimeSinceLastNavigationNameHash, Memory_Experimental::kTimeSinceLastNavigationName},

    {Memory_Experimental::kTimeSinceLastVisibilityChangeNameHash, Memory_Experimental::kTimeSinceLastVisibilityChangeName},

    {Memory_Experimental::kTotal2_PrivateMemoryFootprintNameHash, Memory_Experimental::kTotal2_PrivateMemoryFootprintName},

    {Memory_Experimental::kTotal2_SharedMemoryFootprintNameHash, Memory_Experimental::kTotal2_SharedMemoryFootprintName},

    {Memory_Experimental::kUINameHash, Memory_Experimental::kUIName},

    {Memory_Experimental::kUptimeNameHash, Memory_Experimental::kUptimeName},

    {Memory_Experimental::kV8NameHash, Memory_Experimental::kV8Name},

    {Memory_Experimental::kV8_AllocatedObjectsNameHash, Memory_Experimental::kV8_AllocatedObjectsName},

    {Memory_Experimental::kV8_MainNameHash, Memory_Experimental::kV8_MainName},

    {Memory_Experimental::kV8_Main_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_GlobalHandlesNameHash, Memory_Experimental::kV8_Main_GlobalHandlesName},

    {Memory_Experimental::kV8_Main_HeapNameHash, Memory_Experimental::kV8_Main_HeapName},

    {Memory_Experimental::kV8_Main_Heap_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceName},

    {Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_CodeSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeSpaceName},

    {Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceName},

    {Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_MapSpaceNameHash, Memory_Experimental::kV8_Main_Heap_MapSpaceName},

    {Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceName},

    {Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_NewSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewSpaceName},

    {Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_OldSpaceNameHash, Memory_Experimental::kV8_Main_Heap_OldSpaceName},

    {Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceNameHash, Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceName},

    {Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName},

    {Memory_Experimental::kV8_Main_MallocNameHash, Memory_Experimental::kV8_Main_MallocName},

    {Memory_Experimental::kV8_WorkersNameHash, Memory_Experimental::kV8_WorkersName},

    {Memory_Experimental::kV8_Workers_AllocatedObjectsNameHash, Memory_Experimental::kV8_Workers_AllocatedObjectsName},

    {Memory_Experimental::kWebCacheNameHash, Memory_Experimental::kWebCacheName},

    {Memory_Experimental::kWebCache_CSSStylesheetResourcesNameHash, Memory_Experimental::kWebCache_CSSStylesheetResourcesName},

    {Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash, Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsName},

    {Memory_Experimental::kWebCache_FontResourcesNameHash, Memory_Experimental::kWebCache_FontResourcesName},

    {Memory_Experimental::kWebCache_ImageResourcesNameHash, Memory_Experimental::kWebCache_ImageResourcesName},

    {Memory_Experimental::kWebCache_OtherResourcesNameHash, Memory_Experimental::kWebCache_OtherResourcesName},

    {Memory_Experimental::kWebCache_ScriptResourcesNameHash, Memory_Experimental::kWebCache_ScriptResourcesName},

    {Memory_Experimental::kWebCache_V8CodeCacheNameHash, Memory_Experimental::kWebCache_V8CodeCacheName},

    {Memory_Experimental::kWebCache_XSLStylesheetResourcesNameHash, Memory_Experimental::kWebCache_XSLStylesheetResourcesName},

    {Memory_Experimental::kWebMediaPlayer_AudioNameHash, Memory_Experimental::kWebMediaPlayer_AudioName},

    {Memory_Experimental::kWebMediaPlayer_DataSourceNameHash, Memory_Experimental::kWebMediaPlayer_DataSourceName},

    {Memory_Experimental::kWebMediaPlayer_DemuxerNameHash, Memory_Experimental::kWebMediaPlayer_DemuxerName},

    {Memory_Experimental::kWebMediaPlayer_VideoNameHash, Memory_Experimental::kWebMediaPlayer_VideoName},

        }
      }
    },

    {
      UINT64_C(12430751894188593646),
      {
        Memory_TabFootprint::kEntryName,
        {
          
    {Memory_TabFootprint::kMainFrameProcessPMFNameHash, Memory_TabFootprint::kMainFrameProcessPMFName},

    {Memory_TabFootprint::kSubFrameProcessPMF_ExcludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_ExcludedName},

    {Memory_TabFootprint::kSubFrameProcessPMF_IncludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_IncludedName},

    {Memory_TabFootprint::kSubFrameProcessPMF_TotalNameHash, Memory_TabFootprint::kSubFrameProcessPMF_TotalName},

    {Memory_TabFootprint::kTabPMFNameHash, Memory_TabFootprint::kTabPMFName},

        }
      }
    },

    {
      UINT64_C(9946364510678884885),
      {
        MixedContentAutoupgrade_ResourceRequest::kEntryName,
        {
          
    {MixedContentAutoupgrade_ResourceRequest::kCodeNameHash, MixedContentAutoupgrade_ResourceRequest::kCodeName},

    {MixedContentAutoupgrade_ResourceRequest::kStatusNameHash, MixedContentAutoupgrade_ResourceRequest::kStatusName},

        }
      }
    },

    {
      UINT64_C(10323656781780570903),
      {
        MobileMenu_DirectShare::kEntryName,
        {
          
    {MobileMenu_DirectShare::kHasOccurredNameHash, MobileMenu_DirectShare::kHasOccurredName},

        }
      }
    },

    {
      UINT64_C(317096594738729330),
      {
        MobileMenu_FindInPage::kEntryName,
        {
          
    {MobileMenu_FindInPage::kHasOccurredNameHash, MobileMenu_FindInPage::kHasOccurredName},

        }
      }
    },

    {
      UINT64_C(16632756802456473210),
      {
        MobileMenu_Share::kEntryName,
        {
          
    {MobileMenu_Share::kHasOccurredNameHash, MobileMenu_Share::kHasOccurredName},

        }
      }
    },

    {
      UINT64_C(4064735116116070675),
      {
        NavigationPredictorAnchorElementMetrics::kEntryName,
        {
          
    {NavigationPredictorAnchorElementMetrics::kAnchorIndexNameHash, NavigationPredictorAnchorElementMetrics::kAnchorIndexName},

    {NavigationPredictorAnchorElementMetrics::kContainsImageNameHash, NavigationPredictorAnchorElementMetrics::kContainsImageName},

    {NavigationPredictorAnchorElementMetrics::kIsInIframeNameHash, NavigationPredictorAnchorElementMetrics::kIsInIframeName},

    {NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneNameHash, NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneName},

    {NavigationPredictorAnchorElementMetrics::kPercentClickableAreaNameHash, NavigationPredictorAnchorElementMetrics::kPercentClickableAreaName},

    {NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceNameHash, NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceName},

    {NavigationPredictorAnchorElementMetrics::kSameOriginNameHash, NavigationPredictorAnchorElementMetrics::kSameOriginName},

        }
      }
    },

    {
      UINT64_C(10775915644707889889),
      {
        NavigationPredictorPageLinkClick::kEntryName,
        {
          
    {NavigationPredictorPageLinkClick::kAnchorElementIndexNameHash, NavigationPredictorPageLinkClick::kAnchorElementIndexName},

        }
      }
    },

    {
      UINT64_C(367468233168747720),
      {
        NavigationPredictorPageLinkMetrics::kEntryName,
        {
          
    {NavigationPredictorPageLinkMetrics::kMedianLinkLocationNameHash, NavigationPredictorPageLinkMetrics::kMedianLinkLocationName},

    {NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageName},

    {NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeName},

    {NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostName},

    {NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalName},

    {NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedName},

    {NavigationPredictorPageLinkMetrics::kTotalClickableSpaceNameHash, NavigationPredictorPageLinkMetrics::kTotalClickableSpaceName},

    {NavigationPredictorPageLinkMetrics::kViewport_HeightNameHash, NavigationPredictorPageLinkMetrics::kViewport_HeightName},

    {NavigationPredictorPageLinkMetrics::kViewport_WidthNameHash, NavigationPredictorPageLinkMetrics::kViewport_WidthName},

        }
      }
    },

    {
      UINT64_C(83722319975286136),
      {
        Net_LegacyTLSVersion::kEntryName,
        {
          
    {Net_LegacyTLSVersion::kIsAdResourceNameHash, Net_LegacyTLSVersion::kIsAdResourceName},

    {Net_LegacyTLSVersion::kIsMainFrameNameHash, Net_LegacyTLSVersion::kIsMainFrameName},

    {Net_LegacyTLSVersion::kIsSubresourceNameHash, Net_LegacyTLSVersion::kIsSubresourceName},

        }
      }
    },

    {
      UINT64_C(5007192410804132260),
      {
        NoStatePrefetch::kEntryName,
        {
          
    {NoStatePrefetch::kPrefetchedRecently_FinalStatusNameHash, NoStatePrefetch::kPrefetchedRecently_FinalStatusName},

    {NoStatePrefetch::kPrefetchedRecently_OriginNameHash, NoStatePrefetch::kPrefetchedRecently_OriginName},

    {NoStatePrefetch::kPrefetchedRecently_PrefetchAgeNameHash, NoStatePrefetch::kPrefetchedRecently_PrefetchAgeName},

        }
      }
    },

    {
      UINT64_C(10867195639280438101),
      {
        Notification::kEntryName,
        {
          
    {Notification::kClosedReasonNameHash, Notification::kClosedReasonName},

    {Notification::kDidReplaceAnotherNotificationNameHash, Notification::kDidReplaceAnotherNotificationName},

    {Notification::kDidUserOpenSettingsNameHash, Notification::kDidUserOpenSettingsName},

    {Notification::kHasBadgeNameHash, Notification::kHasBadgeName},

    {Notification::kHasIconNameHash, Notification::kHasIconName},

    {Notification::kHasImageNameHash, Notification::kHasImageName},

    {Notification::kHasRenotifyNameHash, Notification::kHasRenotifyName},

    {Notification::kHasTagNameHash, Notification::kHasTagName},

    {Notification::kIsSilentNameHash, Notification::kIsSilentName},

    {Notification::kNumActionButtonClicksNameHash, Notification::kNumActionButtonClicksName},

    {Notification::kNumActionsNameHash, Notification::kNumActionsName},

    {Notification::kNumClicksNameHash, Notification::kNumClicksName},

    {Notification::kRequireInteractionNameHash, Notification::kRequireInteractionName},

    {Notification::kTimeUntilCloseNameHash, Notification::kTimeUntilCloseName},

    {Notification::kTimeUntilFirstClickNameHash, Notification::kTimeUntilFirstClickName},

    {Notification::kTimeUntilLastClickNameHash, Notification::kTimeUntilLastClickName},

        }
      }
    },

    {
      UINT64_C(2087579403365801585),
      {
        OptimizationGuide::kEntryName,
        {
          
    {OptimizationGuide::kNavigationHintsFetchAttemptStatusNameHash, OptimizationGuide::kNavigationHintsFetchAttemptStatusName},

    {OptimizationGuide::kNavigationHintsFetchRequestLatencyNameHash, OptimizationGuide::kNavigationHintsFetchRequestLatencyName},

    {OptimizationGuide::kPainfulPageLoadModelPredictionScoreNameHash, OptimizationGuide::kPainfulPageLoadModelPredictionScoreName},

    {OptimizationGuide::kPainfulPageLoadModelVersionNameHash, OptimizationGuide::kPainfulPageLoadModelVersionName},

    {OptimizationGuide::kPredictionModelFeatureEffectiveConnectionTypeNameHash, OptimizationGuide::kPredictionModelFeatureEffectiveConnectionTypeName},

    {OptimizationGuide::kPredictionModelFeatureIsSameOriginNavigationNameHash, OptimizationGuide::kPredictionModelFeatureIsSameOriginNavigationName},

    {OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionMeanNameHash, OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionMeanName},

    {OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionStdDevNameHash, OptimizationGuide::kPredictionModelFeatureNavigationToFCPSessionStdDevName},

    {OptimizationGuide::kPredictionModelFeaturePageTransitionNameHash, OptimizationGuide::kPredictionModelFeaturePageTransitionName},

    {OptimizationGuide::kPredictionModelFeaturePreviousPageLoadNavigationToFCPNameHash, OptimizationGuide::kPredictionModelFeaturePreviousPageLoadNavigationToFCPName},

    {OptimizationGuide::kPredictionModelFeatureSiteEngagementScoreNameHash, OptimizationGuide::kPredictionModelFeatureSiteEngagementScoreName},

    {OptimizationGuide::kRegisteredOptimizationTargetsNameHash, OptimizationGuide::kRegisteredOptimizationTargetsName},

    {OptimizationGuide::kRegisteredOptimizationTypesNameHash, OptimizationGuide::kRegisteredOptimizationTypesName},

        }
      }
    },

    {
      UINT64_C(12853622770478513093),
      {
        PageDomainInfo::kEntryName,
        {
          
    {PageDomainInfo::kDomainTypeNameHash, PageDomainInfo::kDomainTypeName},

        }
      }
    },

    {
      UINT64_C(14423022965050986312),
      {
        PageForegroundSession::kEntryName,
        {
          
    {PageForegroundSession::kForegroundDurationNameHash, PageForegroundSession::kForegroundDurationName},

    {PageForegroundSession::kForegroundNumInputEventsNameHash, PageForegroundSession::kForegroundNumInputEventsName},

    {PageForegroundSession::kForegroundTotalAdjustedInputDelayNameHash, PageForegroundSession::kForegroundTotalAdjustedInputDelayName},

    {PageForegroundSession::kForegroundTotalInputDelayNameHash, PageForegroundSession::kForegroundTotalInputDelayName},

        }
      }
    },

    {
      UINT64_C(10171644723325805171),
      {
        PageInfoBubble::kEntryName,
        {
          
    {PageInfoBubble::kActionTakenNameHash, PageInfoBubble::kActionTakenName},

        }
      }
    },

    {
      UINT64_C(12426032810838168341),
      {
        PageLoad::kEntryName,
        {
          
    {PageLoad::kCpuTimeNameHash, PageLoad::kCpuTimeName},

    {PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash, PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredName},

    {PageLoad::kDocumentTiming_NavigationToLoadEventFiredNameHash, PageLoad::kDocumentTiming_NavigationToLoadEventFiredName},

    {PageLoad::kExperimental_InputToNavigationStartNameHash, PageLoad::kExperimental_InputToNavigationStartName},

    {PageLoad::kExperimental_Navigation_UserInitiatedNameHash, PageLoad::kExperimental_Navigation_UserInitiatedName},

    {PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash, PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintName},

    {PageLoad::kInteractiveTiming_FirstInputDelay4NameHash, PageLoad::kInteractiveTiming_FirstInputDelay4Name},

    {PageLoad::kInteractiveTiming_FirstInputProcessingTimesNameHash, PageLoad::kInteractiveTiming_FirstInputProcessingTimesName},

    {PageLoad::kInteractiveTiming_FirstInputTimestamp4NameHash, PageLoad::kInteractiveTiming_FirstInputTimestamp4Name},

    {PageLoad::kInteractiveTiming_FirstScrollDelayNameHash, PageLoad::kInteractiveTiming_FirstScrollDelayName},

    {PageLoad::kInteractiveTiming_LongestInputDelay4NameHash, PageLoad::kInteractiveTiming_LongestInputDelay4Name},

    {PageLoad::kInteractiveTiming_LongestInputTimestamp4NameHash, PageLoad::kInteractiveTiming_LongestInputTimestamp4Name},

    {PageLoad::kInteractiveTiming_NumInputEventsNameHash, PageLoad::kInteractiveTiming_NumInputEventsName},

    {PageLoad::kInteractiveTiming_TotalAdjustedInputDelayNameHash, PageLoad::kInteractiveTiming_TotalAdjustedInputDelayName},

    {PageLoad::kInteractiveTiming_TotalInputDelayNameHash, PageLoad::kInteractiveTiming_TotalInputDelayName},

    {PageLoad::kIsCrossProcessNavigationNameHash, PageLoad::kIsCrossProcessNavigationName},

    {PageLoad::kLayoutInstability_CumulativeShiftScoreNameHash, PageLoad::kLayoutInstability_CumulativeShiftScoreName},

    {PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameNameHash, PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameName},

    {PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash, PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName},

    {PageLoad::kMainDocumentSequenceNumberNameHash, PageLoad::kMainDocumentSequenceNumberName},

    {PageLoad::kMainFrameResource_ConnectDelayNameHash, PageLoad::kMainFrameResource_ConnectDelayName},

    {PageLoad::kMainFrameResource_DNSDelayNameHash, PageLoad::kMainFrameResource_DNSDelayName},

    {PageLoad::kMainFrameResource_HttpProtocolSchemeNameHash, PageLoad::kMainFrameResource_HttpProtocolSchemeName},

    {PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash, PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartName},

    {PageLoad::kMainFrameResource_NavigationStartToRequestStartNameHash, PageLoad::kMainFrameResource_NavigationStartToRequestStartName},

    {PageLoad::kMainFrameResource_RedirectCountNameHash, PageLoad::kMainFrameResource_RedirectCountName},

    {PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndName},

    {PageLoad::kMainFrameResource_RequestStartToSendStartNameHash, PageLoad::kMainFrameResource_RequestStartToSendStartName},

    {PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndName},

    {PageLoad::kMainFrameResource_SocketReusedNameHash, PageLoad::kMainFrameResource_SocketReusedName},

    {PageLoad::kNavigation_PageEndReason2NameHash, PageLoad::kNavigation_PageEndReason2Name},

    {PageLoad::kNavigation_PageTransitionNameHash, PageLoad::kNavigation_PageTransitionName},

    {PageLoad::kNavigationEntryOffsetNameHash, PageLoad::kNavigationEntryOffsetName},

    {PageLoad::kNet_CacheBytes2NameHash, PageLoad::kNet_CacheBytes2Name},

    {PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash, PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartName},

    {PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartNameHash, PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartName},

    {PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadNameHash, PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadName},

    {PageLoad::kNet_HttpResponseCodeNameHash, PageLoad::kNet_HttpResponseCodeName},

    {PageLoad::kNet_HttpRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_HttpRttEstimate_OnNavigationStartName},

    {PageLoad::kNet_ImageBytesNameHash, PageLoad::kNet_ImageBytesName},

    {PageLoad::kNet_ImageSubframeBytesNameHash, PageLoad::kNet_ImageSubframeBytesName},

    {PageLoad::kNet_JavaScriptBytesNameHash, PageLoad::kNet_JavaScriptBytesName},

    {PageLoad::kNet_JavaScriptMaxBytesNameHash, PageLoad::kNet_JavaScriptMaxBytesName},

    {PageLoad::kNet_MediaBytesNameHash, PageLoad::kNet_MediaBytesName},

    {PageLoad::kNet_NetworkBytes2NameHash, PageLoad::kNet_NetworkBytes2Name},

    {PageLoad::kNet_TransportRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_TransportRttEstimate_OnNavigationStartName},

    {PageLoad::kPageTiming_ForegroundDurationNameHash, PageLoad::kPageTiming_ForegroundDurationName},

    {PageLoad::kPageTiming_NavigationToFailedProvisionalLoadNameHash, PageLoad::kPageTiming_NavigationToFailedProvisionalLoadName},

    {PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaintNameHash, PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaintName},

    {PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameNameHash, PageLoad::kPaintTiming_NavigationToExperimentalLargestContentfulPaint_MainFrameName},

    {PageLoad::kPaintTiming_NavigationToFirstContentfulPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstContentfulPaintName},

    {PageLoad::kPaintTiming_NavigationToFirstPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstPaintName},

    {PageLoad::kPaintTiming_NavigationToLargestContentfulPaintNameHash, PageLoad::kPaintTiming_NavigationToLargestContentfulPaintName},

    {PageLoad::kPaintTiming_NavigationToLargestContentfulPaint_MainFrameNameHash, PageLoad::kPaintTiming_NavigationToLargestContentfulPaint_MainFrameName},

    {PageLoad::kParseTiming_NavigationToParseStartNameHash, PageLoad::kParseTiming_NavigationToParseStartName},

    {PageLoad::kSiteEngagementScoreNameHash, PageLoad::kSiteEngagementScoreName},

    {PageLoad::kThirdPartyCookieBlockingEnabledForSiteNameHash, PageLoad::kThirdPartyCookieBlockingEnabledForSiteName},

    {PageLoad::kWasCachedNameHash, PageLoad::kWasCachedName},

        }
      }
    },

    {
      UINT64_C(8384138607730558665),
      {
        PageLoad_FromGoogleSearch::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(5441732143890651748),
      {
        PageLoad_Internal::kEntryName,
        {
          
    {PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeNameHash, PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_ContentTypeName},

    {PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateNameHash, PageLoad_Internal::kPaintTiming_ExperimentalLargestContentfulPaint_TerminationStateName},

    {PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeNameHash, PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeName},

    {PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateNameHash, PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateName},

        }
      }
    },

    {
      UINT64_C(18067304287773255026),
      {
        PageLoad_ServiceWorkerControlled::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(14566014450078110818),
      {
        PageLoad_SignedExchange::kEntryName,
        {
          
    {PageLoad_SignedExchange::kServedFromGoogleCacheNameHash, PageLoad_SignedExchange::kServedFromGoogleCacheName},

        }
      }
    },

    {
      UINT64_C(2493630448790526384),
      {
        PageWithPassword::kEntryName,
        {
          
    {PageWithPassword::kFormManagerAvailableNameHash, PageWithPassword::kFormManagerAvailableName},

    {PageWithPassword::kPageLevelUserActionNameHash, PageWithPassword::kPageLevelUserActionName},

    {PageWithPassword::kProvisionalSaveFailureNameHash, PageWithPassword::kProvisionalSaveFailureName},

    {PageWithPassword::kUserModifiedPasswordFieldNameHash, PageWithPassword::kUserModifiedPasswordFieldName},

        }
      }
    },

    {
      UINT64_C(1595630084981618121),
      {
        PaintPreviewCapture::kEntryName,
        {
          
    {PaintPreviewCapture::kBlinkCaptureTimeNameHash, PaintPreviewCapture::kBlinkCaptureTimeName},

    {PaintPreviewCapture::kCompressedOnDiskSizeNameHash, PaintPreviewCapture::kCompressedOnDiskSizeName},

        }
      }
    },

    {
      UINT64_C(8060270586115376858),
      {
        PasswordForm::kEntryName,
        {
          
    {PasswordForm::kContext_FormSignatureNameHash, PasswordForm::kContext_FormSignatureName},

    {PasswordForm::kDynamicFormChangesNameHash, PasswordForm::kDynamicFormChangesName},

    {PasswordForm::kFill_FirstFillingResultInRendererNameHash, PasswordForm::kFill_FirstFillingResultInRendererName},

    {PasswordForm::kFill_FirstWaitForUsernameReasonNameHash, PasswordForm::kFill_FirstWaitForUsernameReasonName},

    {PasswordForm::kFillOnLoadNameHash, PasswordForm::kFillOnLoadName},

    {PasswordForm::kGeneration_GeneratedPasswordNameHash, PasswordForm::kGeneration_GeneratedPasswordName},

    {PasswordForm::kGeneration_GeneratedPasswordModifiedNameHash, PasswordForm::kGeneration_GeneratedPasswordModifiedName},

    {PasswordForm::kGeneration_PopupShownNameHash, PasswordForm::kGeneration_PopupShownName},

    {PasswordForm::kManagerFill_ActionNameHash, PasswordForm::kManagerFill_ActionName},

    {PasswordForm::kManagerFill_AssistanceNameHash, PasswordForm::kManagerFill_AssistanceName},

    {PasswordForm::kReadonlyWhenFillingNameHash, PasswordForm::kReadonlyWhenFillingName},

    {PasswordForm::kReadonlyWhenSavingNameHash, PasswordForm::kReadonlyWhenSavingName},

    {PasswordForm::kSaving_Prompt_InteractionNameHash, PasswordForm::kSaving_Prompt_InteractionName},

    {PasswordForm::kSaving_Prompt_ShownNameHash, PasswordForm::kSaving_Prompt_ShownName},

    {PasswordForm::kSaving_Prompt_TriggerNameHash, PasswordForm::kSaving_Prompt_TriggerName},

    {PasswordForm::kSaving_ShowedManualFallbackForSavingNameHash, PasswordForm::kSaving_ShowedManualFallbackForSavingName},

    {PasswordForm::kSubmission_IndicatorNameHash, PasswordForm::kSubmission_IndicatorName},

    {PasswordForm::kSubmission_ObservedNameHash, PasswordForm::kSubmission_ObservedName},

    {PasswordForm::kSubmission_SubmissionResultNameHash, PasswordForm::kSubmission_SubmissionResultName},

    {PasswordForm::kSubmission_SubmittedFormTypeNameHash, PasswordForm::kSubmission_SubmittedFormTypeName},

    {PasswordForm::kUpdating_Prompt_InteractionNameHash, PasswordForm::kUpdating_Prompt_InteractionName},

    {PasswordForm::kUpdating_Prompt_ShownNameHash, PasswordForm::kUpdating_Prompt_ShownName},

    {PasswordForm::kUpdating_Prompt_TriggerNameHash, PasswordForm::kUpdating_Prompt_TriggerName},

    {PasswordForm::kUser_Action_CorrectedUsernameInFormNameHash, PasswordForm::kUser_Action_CorrectedUsernameInFormName},

    {PasswordForm::kUser_Action_EditedUsernameInBubbleNameHash, PasswordForm::kUser_Action_EditedUsernameInBubbleName},

    {PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleNameHash, PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleName},

    {PasswordForm::kUser_Action_TriggeredManualFallbackForSavingNameHash, PasswordForm::kUser_Action_TriggeredManualFallbackForSavingName},

        }
      }
    },

    {
      UINT64_C(702207440764833882),
      {
        PaymentApp_CheckoutEvents::kEntryName,
        {
          
    {PaymentApp_CheckoutEvents::kCompletionStatusNameHash, PaymentApp_CheckoutEvents::kCompletionStatusName},

    {PaymentApp_CheckoutEvents::kEventsNameHash, PaymentApp_CheckoutEvents::kEventsName},

        }
      }
    },

    {
      UINT64_C(9066413457122162526),
      {
        PaymentRequest_CheckoutEvents::kEntryName,
        {
          
    {PaymentRequest_CheckoutEvents::kCompletionStatusNameHash, PaymentRequest_CheckoutEvents::kCompletionStatusName},

    {PaymentRequest_CheckoutEvents::kEventsNameHash, PaymentRequest_CheckoutEvents::kEventsName},

        }
      }
    },

    {
      UINT64_C(4090736682116197688),
      {
        PaymentRequest_TransactionAmount::kEntryName,
        {
          
    {PaymentRequest_TransactionAmount::kCategoryNameHash, PaymentRequest_TransactionAmount::kCategoryName},

    {PaymentRequest_TransactionAmount::kCompletionStatusNameHash, PaymentRequest_TransactionAmount::kCompletionStatusName},

        }
      }
    },

    {
      UINT64_C(4863880088883807024),
      {
        Pepper_Broker::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(10863131082725230381),
      {
        PeriodicBackgroundSyncEventCompleted::kEntryName,
        {
          
    {PeriodicBackgroundSyncEventCompleted::kMaxAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kMaxAttemptsName},

    {PeriodicBackgroundSyncEventCompleted::kNumAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kNumAttemptsName},

    {PeriodicBackgroundSyncEventCompleted::kStatusNameHash, PeriodicBackgroundSyncEventCompleted::kStatusName},

        }
      }
    },

    {
      UINT64_C(8211654418406942912),
      {
        PeriodicBackgroundSyncRegistered::kEntryName,
        {
          
    {PeriodicBackgroundSyncRegistered::kIsReregisteredNameHash, PeriodicBackgroundSyncRegistered::kIsReregisteredName},

    {PeriodicBackgroundSyncRegistered::kMinIntervalMsNameHash, PeriodicBackgroundSyncRegistered::kMinIntervalMsName},

        }
      }
    },

    {
      UINT64_C(17104084284355864347),
      {
        Permission::kEntryName,
        {
          
    {Permission::kActionNameHash, Permission::kActionName},

    {Permission::kGestureNameHash, Permission::kGestureName},

    {Permission::kPermissionTypeNameHash, Permission::kPermissionTypeName},

    {Permission::kPriorDismissalsNameHash, Permission::kPriorDismissalsName},

    {Permission::kPriorIgnoresNameHash, Permission::kPriorIgnoresName},

    {Permission::kPromptDispositionNameHash, Permission::kPromptDispositionName},

    {Permission::kSourceNameHash, Permission::kSourceName},

        }
      }
    },

    {
      UINT64_C(2851782918499658607),
      {
        Plugins_FlashInstance::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(5373577291340314501),
      {
        Popup_Closed::kEntryName,
        {
          
    {Popup_Closed::kEngagementTimeNameHash, Popup_Closed::kEngagementTimeName},

    {Popup_Closed::kNumActivationInteractionsNameHash, Popup_Closed::kNumActivationInteractionsName},

    {Popup_Closed::kNumGestureScrollBeginInteractionsNameHash, Popup_Closed::kNumGestureScrollBeginInteractionsName},

    {Popup_Closed::kNumInteractionsNameHash, Popup_Closed::kNumInteractionsName},

    {Popup_Closed::kSafeBrowsingStatusNameHash, Popup_Closed::kSafeBrowsingStatusName},

    {Popup_Closed::kTrustedNameHash, Popup_Closed::kTrustedName},

    {Popup_Closed::kUserInitiatedCloseNameHash, Popup_Closed::kUserInitiatedCloseName},

    {Popup_Closed::kWindowOpenDispositionNameHash, Popup_Closed::kWindowOpenDispositionName},

        }
      }
    },

    {
      UINT64_C(9277003375443527515),
      {
        Popup_Page::kEntryName,
        {
          
    {Popup_Page::kAllowedNameHash, Popup_Page::kAllowedName},

        }
      }
    },

    {
      UINT64_C(570650911258459707),
      {
        Portal_Activate::kEntryName,
        {
          
    {Portal_Activate::kPaintTiming_PortalActivationToFirstPaintNameHash, Portal_Activate::kPaintTiming_PortalActivationToFirstPaintName},

    {Portal_Activate::kPortalActivationNameHash, Portal_Activate::kPortalActivationName},

    {Portal_Activate::kPortalActivationBeforeLCPNameHash, Portal_Activate::kPortalActivationBeforeLCPName},

        }
      }
    },

    {
      UINT64_C(11352241752715206016),
      {
        PrefetchProxy::kEntryName,
        {
          
    {PrefetchProxy::kcount_css_js_loaded_cache_before_fcpNameHash, PrefetchProxy::kcount_css_js_loaded_cache_before_fcpName},

    {PrefetchProxy::kcount_css_js_loaded_network_before_fcpNameHash, PrefetchProxy::kcount_css_js_loaded_network_before_fcpName},

    {PrefetchProxy::kdays_since_last_visit_to_originNameHash, PrefetchProxy::kdays_since_last_visit_to_originName},

    {PrefetchProxy::kmainpage_request_had_cookiesNameHash, PrefetchProxy::kmainpage_request_had_cookiesName},

    {PrefetchProxy::kordered_eligible_pages_bitmaskNameHash, PrefetchProxy::kordered_eligible_pages_bitmaskName},

    {PrefetchProxy::kprefetch_attempted_countNameHash, PrefetchProxy::kprefetch_attempted_countName},

    {PrefetchProxy::kprefetch_eligible_countNameHash, PrefetchProxy::kprefetch_eligible_countName},

    {PrefetchProxy::kprefetch_successful_countNameHash, PrefetchProxy::kprefetch_successful_countName},

        }
      }
    },

    {
      UINT64_C(6674705951757661648),
      {
        PrefetchProxy_AfterSRPClick::kEntryName,
        {
          
    {PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionNameHash, PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionName},

    {PrefetchProxy_AfterSRPClick::kProbeLatencyMsNameHash, PrefetchProxy_AfterSRPClick::kProbeLatencyMsName},

    {PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusNameHash, PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusName},

    {PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountNameHash, PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountName},

        }
      }
    },

    {
      UINT64_C(16176000469846917671),
      {
        Previews::kEntryName,
        {
          
    {Previews::kdefer_all_scriptNameHash, Previews::kdefer_all_scriptName},

    {Previews::kdefer_all_script_eligibility_reasonNameHash, Previews::kdefer_all_script_eligibility_reasonName},

    {Previews::klite_pageNameHash, Previews::klite_pageName},

    {Previews::knoscriptNameHash, Previews::knoscriptName},

    {Previews::knoscript_eligibility_reasonNameHash, Previews::knoscript_eligibility_reasonName},

    {Previews::koffline_eligibility_reasonNameHash, Previews::koffline_eligibility_reasonName},

    {Previews::koffline_previewNameHash, Previews::koffline_previewName},

    {Previews::kopt_outNameHash, Previews::kopt_outName},

    {Previews::korigin_opt_outNameHash, Previews::korigin_opt_outName},

    {Previews::kpreviews_likelyNameHash, Previews::kpreviews_likelyName},

    {Previews::kproxy_lite_page_eligibility_reasonNameHash, Previews::kproxy_lite_page_eligibility_reasonName},

    {Previews::kresource_loading_hintsNameHash, Previews::kresource_loading_hintsName},

    {Previews::kresource_loading_hints_eligibility_reasonNameHash, Previews::kresource_loading_hints_eligibility_reasonName},

    {Previews::ksave_data_enabledNameHash, Previews::ksave_data_enabledName},

        }
      }
    },

    {
      UINT64_C(6691626505896909380),
      {
        PreviewsCoinFlip::kEntryName,
        {
          
    {PreviewsCoinFlip::kcoin_flip_resultNameHash, PreviewsCoinFlip::kcoin_flip_resultName},

        }
      }
    },

    {
      UINT64_C(2545987494366395841),
      {
        PreviewsDeferAllScript::kEntryName,
        {
          
    {PreviewsDeferAllScript::kforce_deferred_scripts_mainframeNameHash, PreviewsDeferAllScript::kforce_deferred_scripts_mainframeName},

    {PreviewsDeferAllScript::kforce_deferred_scripts_mainframe_externalNameHash, PreviewsDeferAllScript::kforce_deferred_scripts_mainframe_externalName},

        }
      }
    },

    {
      UINT64_C(2128752535034967467),
      {
        PreviewsResourceLoadingHints::kEntryName,
        {
          
    {PreviewsResourceLoadingHints::kblocked_high_priorityNameHash, PreviewsResourceLoadingHints::kblocked_high_priorityName},

    {PreviewsResourceLoadingHints::kblocked_low_priorityNameHash, PreviewsResourceLoadingHints::kblocked_low_priorityName},

    {PreviewsResourceLoadingHints::kblocked_medium_priorityNameHash, PreviewsResourceLoadingHints::kblocked_medium_priorityName},

    {PreviewsResourceLoadingHints::kblocked_very_high_priorityNameHash, PreviewsResourceLoadingHints::kblocked_very_high_priorityName},

    {PreviewsResourceLoadingHints::kblocked_very_low_priorityNameHash, PreviewsResourceLoadingHints::kblocked_very_low_priorityName},

    {PreviewsResourceLoadingHints::kpatterns_to_block_totalNameHash, PreviewsResourceLoadingHints::kpatterns_to_block_totalName},

    {PreviewsResourceLoadingHints::kpatterns_to_block_usedNameHash, PreviewsResourceLoadingHints::kpatterns_to_block_usedName},

        }
      }
    },

    {
      UINT64_C(10398495362201261089),
      {
        PublicImageCompressionDataUse::kEntryName,
        {
          
    {PublicImageCompressionDataUse::kCompressibleImageBytesNameHash, PublicImageCompressionDataUse::kCompressibleImageBytesName},

    {PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableAndMissingInHintsBytesNameHash, PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableAndMissingInHintsBytesName},

    {PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableButCompressibleBytesNameHash, PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableButCompressibleBytesName},

    {PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableBytesNameHash, PublicImageCompressionDataUse::kIneligibleImageHintsUnavailableBytesName},

    {PublicImageCompressionDataUse::kIneligibleMissingInImageHintsBytesNameHash, PublicImageCompressionDataUse::kIneligibleMissingInImageHintsBytesName},

    {PublicImageCompressionDataUse::kIneligibleOtherImageBytesNameHash, PublicImageCompressionDataUse::kIneligibleOtherImageBytesName},

        }
      }
    },

    {
      UINT64_C(4791378639615025150),
      {
        PWA_Visit::kEntryName,
        {
          
    {PWA_Visit::kLaunchSourceNameHash, PWA_Visit::kLaunchSourceName},

    {PWA_Visit::kWebAPKableSiteVisitNameHash, PWA_Visit::kWebAPKableSiteVisitName},

        }
      }
    },

    {
      UINT64_C(15014052365473894052),
      {
        ReaderModeActivated::kEntryName,
        {
          
    {ReaderModeActivated::kActivatedViaOmniboxNameHash, ReaderModeActivated::kActivatedViaOmniboxName},

        }
      }
    },

    {
      UINT64_C(3308537368968335608),
      {
        ReaderModeReceivedDistillability::kEntryName,
        {
          
    {ReaderModeReceivedDistillability::kIsPageDistillableNameHash, ReaderModeReceivedDistillability::kIsPageDistillableName},

        }
      }
    },

    {
      UINT64_C(18249372845339521807),
      {
        RendererSchedulerTask::kEntryName,
        {
          
    {RendererSchedulerTask::kFrameStatusNameHash, RendererSchedulerTask::kFrameStatusName},

    {RendererSchedulerTask::kIsOOPIFNameHash, RendererSchedulerTask::kIsOOPIFName},

    {RendererSchedulerTask::kPageSchedulersNameHash, RendererSchedulerTask::kPageSchedulersName},

    {RendererSchedulerTask::kQueueTypeNameHash, RendererSchedulerTask::kQueueTypeName},

    {RendererSchedulerTask::kRendererAudibleNameHash, RendererSchedulerTask::kRendererAudibleName},

    {RendererSchedulerTask::kRendererBackgroundedNameHash, RendererSchedulerTask::kRendererBackgroundedName},

    {RendererSchedulerTask::kRendererHiddenNameHash, RendererSchedulerTask::kRendererHiddenName},

    {RendererSchedulerTask::kSecondsSinceBackgroundedNameHash, RendererSchedulerTask::kSecondsSinceBackgroundedName},

    {RendererSchedulerTask::kTaskCPUDurationNameHash, RendererSchedulerTask::kTaskCPUDurationName},

    {RendererSchedulerTask::kTaskDurationNameHash, RendererSchedulerTask::kTaskDurationName},

    {RendererSchedulerTask::kTaskTypeNameHash, RendererSchedulerTask::kTaskTypeName},

    {RendererSchedulerTask::kThreadTypeNameHash, RendererSchedulerTask::kThreadTypeName},

    {RendererSchedulerTask::kUseCaseNameHash, RendererSchedulerTask::kUseCaseName},

    {RendererSchedulerTask::kVersionNameHash, RendererSchedulerTask::kVersionName},

        }
      }
    },

    {
      UINT64_C(6628044799783508745),
      {
        ResponsivenessMeasurement::kEntryName,
        {
          
    {ResponsivenessMeasurement::kExpectedTaskQueueingDurationNameHash, ResponsivenessMeasurement::kExpectedTaskQueueingDurationName},

        }
      }
    },

    {
      UINT64_C(14016795862258924641),
      {
        SameSiteDifferentSchemeRequest::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(6057282574508536454),
      {
        SameSiteDifferentSchemeResponse::kEntryName,
        {
          
        }
      }
    },

    {
      UINT64_C(16392896102401488447),
      {
        SchemefulSameSiteContextDowngrade::kEntryName,
        {
          
    {SchemefulSameSiteContextDowngrade::kRequestPerCookieNameHash, SchemefulSameSiteContextDowngrade::kRequestPerCookieName},

    {SchemefulSameSiteContextDowngrade::kResponsePerCookieNameHash, SchemefulSameSiteContextDowngrade::kResponsePerCookieName},

        }
      }
    },

    {
      UINT64_C(17111718181803892778),
      {
        ScreenBrightness::kEntryName,
        {
          
    {ScreenBrightness::kBatteryPercentNameHash, ScreenBrightness::kBatteryPercentName},

    {ScreenBrightness::kBrightnessNameHash, ScreenBrightness::kBrightnessName},

    {ScreenBrightness::kDayOfWeekNameHash, ScreenBrightness::kDayOfWeekName},

    {ScreenBrightness::kDeviceModeNameHash, ScreenBrightness::kDeviceModeName},

    {ScreenBrightness::kHourOfDayNameHash, ScreenBrightness::kHourOfDayName},

    {ScreenBrightness::kIsAutoclickEnabledNameHash, ScreenBrightness::kIsAutoclickEnabledName},

    {ScreenBrightness::kIsBrailleDisplayConnectedNameHash, ScreenBrightness::kIsBrailleDisplayConnectedName},

    {ScreenBrightness::kIsCaretHighlightEnabledNameHash, ScreenBrightness::kIsCaretHighlightEnabledName},

    {ScreenBrightness::kIsCursorHighlightEnabledNameHash, ScreenBrightness::kIsCursorHighlightEnabledName},

    {ScreenBrightness::kIsFocusHighlightEnabledNameHash, ScreenBrightness::kIsFocusHighlightEnabledName},

    {ScreenBrightness::kIsHighContrastEnabledNameHash, ScreenBrightness::kIsHighContrastEnabledName},

    {ScreenBrightness::kIsLargeCursorEnabledNameHash, ScreenBrightness::kIsLargeCursorEnabledName},

    {ScreenBrightness::kIsMagnifierEnabledNameHash, ScreenBrightness::kIsMagnifierEnabledName},

    {ScreenBrightness::kIsMonoAudioEnabledNameHash, ScreenBrightness::kIsMonoAudioEnabledName},

    {ScreenBrightness::kIsSelectToSpeakEnabledNameHash, ScreenBrightness::kIsSelectToSpeakEnabledName},

    {ScreenBrightness::kIsSpokenFeedbackEnabledNameHash, ScreenBrightness::kIsSpokenFeedbackEnabledName},

    {ScreenBrightness::kIsSwitchAccessEnabledNameHash, ScreenBrightness::kIsSwitchAccessEnabledName},

    {ScreenBrightness::kIsVideoPlayingNameHash, ScreenBrightness::kIsVideoPlayingName},

    {ScreenBrightness::kIsVirtualKeyboardEnabledNameHash, ScreenBrightness::kIsVirtualKeyboardEnabledName},

    {ScreenBrightness::kLastActivityTimeSecNameHash, ScreenBrightness::kLastActivityTimeSecName},

    {ScreenBrightness::kNightLightTemperaturePercentNameHash, ScreenBrightness::kNightLightTemperaturePercentName},

    {ScreenBrightness::kNumRecentKeyEventsNameHash, ScreenBrightness::kNumRecentKeyEventsName},

    {ScreenBrightness::kNumRecentMouseEventsNameHash, ScreenBrightness::kNumRecentMouseEventsName},

    {ScreenBrightness::kNumRecentStylusEventsNameHash, ScreenBrightness::kNumRecentStylusEventsName},

    {ScreenBrightness::kNumRecentTouchEventsNameHash, ScreenBrightness::kNumRecentTouchEventsName},

    {ScreenBrightness::kOnBatteryNameHash, ScreenBrightness::kOnBatteryName},

    {ScreenBrightness::kPreviousBrightnessNameHash, ScreenBrightness::kPreviousBrightnessName},

    {ScreenBrightness::kReasonNameHash, ScreenBrightness::kReasonName},

    {ScreenBrightness::kRecentTimeActiveSecNameHash, ScreenBrightness::kRecentTimeActiveSecName},

    {ScreenBrightness::kSequenceIdNameHash, ScreenBrightness::kSequenceIdName},

    {ScreenBrightness::kTimeSinceLastEventSecNameHash, ScreenBrightness::kTimeSinceLastEventSecName},

        }
      }
    },

    {
      UINT64_C(345243929458665883),
      {
        Security_SafetyTip::kEntryName,
        {
          
    {Security_SafetyTip::kSafetyTipInteractionNameHash, Security_SafetyTip::kSafetyTipInteractionName},

    {Security_SafetyTip::kSafetyTipStatusNameHash, Security_SafetyTip::kSafetyTipStatusName},

    {Security_SafetyTip::kTriggeredKeywordsHeuristicsNameHash, Security_SafetyTip::kTriggeredKeywordsHeuristicsName},

    {Security_SafetyTip::kTriggeredLookalikeHeuristicsNameHash, Security_SafetyTip::kTriggeredLookalikeHeuristicsName},

    {Security_SafetyTip::kTriggeredServerSideBlocklistNameHash, Security_SafetyTip::kTriggeredServerSideBlocklistName},

    {Security_SafetyTip::kUserPreviouslyIgnoredNameHash, Security_SafetyTip::kUserPreviouslyIgnoredName},

        }
      }
    },

    {
      UINT64_C(10614135803401894002),
      {
        Security_SiteEngagement::kEntryName,
        {
          
    {Security_SiteEngagement::kFinalSecurityLevelNameHash, Security_SiteEngagement::kFinalSecurityLevelName},

    {Security_SiteEngagement::kInitialSecurityLevelNameHash, Security_SiteEngagement::kInitialSecurityLevelName},

    {Security_SiteEngagement::kSafetyTipStatusNameHash, Security_SiteEngagement::kSafetyTipStatusName},

    {Security_SiteEngagement::kScoreDeltaNameHash, Security_SiteEngagement::kScoreDeltaName},

    {Security_SiteEngagement::kScoreFinalNameHash, Security_SiteEngagement::kScoreFinalName},

        }
      }
    },

    {
      UINT64_C(13674128907128689363),
      {
        Sharing_ClickToCall::kEntryName,
        {
          
    {Sharing_ClickToCall::kEntryPointNameHash, Sharing_ClickToCall::kEntryPointName},

    {Sharing_ClickToCall::kHasAppsNameHash, Sharing_ClickToCall::kHasAppsName},

    {Sharing_ClickToCall::kHasDevicesNameHash, Sharing_ClickToCall::kHasDevicesName},

    {Sharing_ClickToCall::kSelectionNameHash, Sharing_ClickToCall::kSelectionName},

        }
      }
    },

    {
      UINT64_C(18163040957371490481),
      {
        SmartCharging::kEntryName,
        {
          
    {SmartCharging::kBatteryPercentageNameHash, SmartCharging::kBatteryPercentageName},

    {SmartCharging::kBatteryPercentageBeforeLastChargeNameHash, SmartCharging::kBatteryPercentageBeforeLastChargeName},

    {SmartCharging::kBatteryPercentageOfLastChargeNameHash, SmartCharging::kBatteryPercentageOfLastChargeName},

    {SmartCharging::kDayOfMonthNameHash, SmartCharging::kDayOfMonthName},

    {SmartCharging::kDayOfWeekNameHash, SmartCharging::kDayOfWeekName},

    {SmartCharging::kDeviceModeNameHash, SmartCharging::kDeviceModeName},

    {SmartCharging::kDeviceTypeNameHash, SmartCharging::kDeviceTypeName},

    {SmartCharging::kDurationOfLastChargeNameHash, SmartCharging::kDurationOfLastChargeName},

    {SmartCharging::kDurationRecentAudioPlayingNameHash, SmartCharging::kDurationRecentAudioPlayingName},

    {SmartCharging::kDurationRecentVideoPlayingNameHash, SmartCharging::kDurationRecentVideoPlayingName},

    {SmartCharging::kEventIdNameHash, SmartCharging::kEventIdName},

    {SmartCharging::kHaltFromLastChargeNameHash, SmartCharging::kHaltFromLastChargeName},

    {SmartCharging::kIsChargingNameHash, SmartCharging::kIsChargingName},

    {SmartCharging::kMonthNameHash, SmartCharging::kMonthName},

    {SmartCharging::kNumRecentKeyEventsNameHash, SmartCharging::kNumRecentKeyEventsName},

    {SmartCharging::kNumRecentMouseEventsNameHash, SmartCharging::kNumRecentMouseEventsName},

    {SmartCharging::kNumRecentStylusEventsNameHash, SmartCharging::kNumRecentStylusEventsName},

    {SmartCharging::kNumRecentTouchEventsNameHash, SmartCharging::kNumRecentTouchEventsName},

    {SmartCharging::kReasonNameHash, SmartCharging::kReasonName},

    {SmartCharging::kScreenBrightnessPercentNameHash, SmartCharging::kScreenBrightnessPercentName},

    {SmartCharging::kTimeOfTheDayNameHash, SmartCharging::kTimeOfTheDayName},

    {SmartCharging::kTimeSinceLastChargeNameHash, SmartCharging::kTimeSinceLastChargeName},

    {SmartCharging::kTimezoneDifferenceFromLastChargeNameHash, SmartCharging::kTimezoneDifferenceFromLastChargeName},

    {SmartCharging::kVoltageNameHash, SmartCharging::kVoltageName},

        }
      }
    },

    {
      UINT64_C(16019904587509461311),
      {
        SMSReceiver::kEntryName,
        {
          
    {SMSReceiver::kOutcomeNameHash, SMSReceiver::kOutcomeName},

        }
      }
    },

    {
      UINT64_C(1198169845674357824),
      {
        SSL_MixedContentShown::kEntryName,
        {
          
    {SSL_MixedContentShown::kTypeNameHash, SSL_MixedContentShown::kTypeName},

        }
      }
    },

    {
      UINT64_C(16234573202714536926),
      {
        SubresourceFilter::kEntryName,
        {
          
    {SubresourceFilter::kActivationDecisionNameHash, SubresourceFilter::kActivationDecisionName},

    {SubresourceFilter::kDryRunNameHash, SubresourceFilter::kDryRunName},

    {SubresourceFilter::kEnforcementRedirectPositionNameHash, SubresourceFilter::kEnforcementRedirectPositionName},

        }
      }
    },

    {
      UINT64_C(18395820288494961196),
      {
        Tab_RendererOOM::kEntryName,
        {
          
    {Tab_RendererOOM::kTimeSinceLastNavigationNameHash, Tab_RendererOOM::kTimeSinceLastNavigationName},

        }
      }
    },

    {
      UINT64_C(4107587426159302168),
      {
        Tab_Screenshot::kEntryName,
        {
          
    {Tab_Screenshot::kHasOccurredNameHash, Tab_Screenshot::kHasOccurredName},

        }
      }
    },

    {
      UINT64_C(6962158576008124011),
      {
        TabManager_Background_FirstAlertFired::kEntryName,
        {
          
    {TabManager_Background_FirstAlertFired::kIsMainFrameNameHash, TabManager_Background_FirstAlertFired::kIsMainFrameName},

    {TabManager_Background_FirstAlertFired::kTimeFromBackgroundedNameHash, TabManager_Background_FirstAlertFired::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(6253115585121265178),
      {
        TabManager_Background_FirstAudioStarts::kEntryName,
        {
          
    {TabManager_Background_FirstAudioStarts::kIsMainFrameNameHash, TabManager_Background_FirstAudioStarts::kIsMainFrameName},

    {TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedNameHash, TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(7684352713481018374),
      {
        TabManager_Background_FirstFaviconUpdated::kEntryName,
        {
          
    {TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedNameHash, TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(5800172692978642430),
      {
        TabManager_Background_FirstNonPersistentNotificationCreated::kEntryName,
        {
          
    {TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameNameHash, TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameName},

    {TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedNameHash, TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(13224923626166210718),
      {
        TabManager_Background_FirstTitleUpdated::kEntryName,
        {
          
    {TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedNameHash, TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(11823633373787678555),
      {
        TabManager_Background_ForegroundedOrClosed::kEntryName,
        {
          
    {TabManager_Background_ForegroundedOrClosed::kIsDiscardedNameHash, TabManager_Background_ForegroundedOrClosed::kIsDiscardedName},

    {TabManager_Background_ForegroundedOrClosed::kIsForegroundedNameHash, TabManager_Background_ForegroundedOrClosed::kIsForegroundedName},

    {TabManager_Background_ForegroundedOrClosed::kLabelIdNameHash, TabManager_Background_ForegroundedOrClosed::kLabelIdName},

    {TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedNameHash, TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedName},

        }
      }
    },

    {
      UINT64_C(2947416194925354680),
      {
        TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName,
        {
          
    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabLoadingCountNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabLoadingCountName},

    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabOpeningSessionIdNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabOpeningSessionIdName},

    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabPendingCountNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kBackgroundTabPendingCountName},

    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName},

    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName},

    {TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash, TabManager_BackgroundTabOpening_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName},

        }
      }
    },

    {
      UINT64_C(5089020187687107285),
      {
        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryName,
        {
          
    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountName},

    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdName},

    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountName},

    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdName},

    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountName},

    {TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash, TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeName},

        }
      }
    },

    {
      UINT64_C(5185149670019600507),
      {
        TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryName,
        {
          
    {TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountNameHash, TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountName},

    {TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountNameHash, TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountName},

        }
      }
    },

    {
      UINT64_C(10989149245696867796),
      {
        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryName,
        {
          
    {TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdNameHash, TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdName},

    {TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdNameHash, TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdName},

    {TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountNameHash, TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountName},

    {TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountNameHash, TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountName},

    {TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash, TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeName},

        }
      }
    },

    {
      UINT64_C(15361214325300303131),
      {
        TabManager_LifecycleStateChange::kEntryName,
        {
          
    {TabManager_LifecycleStateChange::kFailureGlobalBlacklistNameHash, TabManager_LifecycleStateChange::kFailureGlobalBlacklistName},

    {TabManager_LifecycleStateChange::kFailureHeuristicAudioNameHash, TabManager_LifecycleStateChange::kFailureHeuristicAudioName},

    {TabManager_LifecycleStateChange::kFailureHeuristicFaviconNameHash, TabManager_LifecycleStateChange::kFailureHeuristicFaviconName},

    {TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationNameHash, TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationName},

    {TabManager_LifecycleStateChange::kFailureHeuristicNotificationsNameHash, TabManager_LifecycleStateChange::kFailureHeuristicNotificationsName},

    {TabManager_LifecycleStateChange::kFailureHeuristicTitleNameHash, TabManager_LifecycleStateChange::kFailureHeuristicTitleName},

    {TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutNameHash, TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutName},

    {TabManager_LifecycleStateChange::kFailureLiveStateCapturingNameHash, TabManager_LifecycleStateChange::kFailureLiveStateCapturingName},

    {TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureNameHash, TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureName},

    {TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenNameHash, TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenName},

    {TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedNameHash, TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedName},

    {TabManager_LifecycleStateChange::kFailureLiveStateFormEntryNameHash, TabManager_LifecycleStateChange::kFailureLiveStateFormEntryName},

    {TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionNameHash, TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionName},

    {TabManager_LifecycleStateChange::kFailureLiveStateIsPDFNameHash, TabManager_LifecycleStateChange::kFailureLiveStateIsPDFName},

    {TabManager_LifecycleStateChange::kFailureLiveStateMirroringNameHash, TabManager_LifecycleStateChange::kFailureLiveStateMirroringName},

    {TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioNameHash, TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioName},

    {TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceNameHash, TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceName},

    {TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothName},

    {TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockName},

    {TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockName},

    {TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsName},

    {TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBName},

    {TabManager_LifecycleStateChange::kFailureLiveStateVisibleNameHash, TabManager_LifecycleStateChange::kFailureLiveStateVisibleName},

    {TabManager_LifecycleStateChange::kFailureLiveWebAppNameHash, TabManager_LifecycleStateChange::kFailureLiveWebAppName},

    {TabManager_LifecycleStateChange::kFailureOriginTrialOptOutNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialOptOutName},

    {TabManager_LifecycleStateChange::kFailureOriginTrialUnknownNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialUnknownName},

    {TabManager_LifecycleStateChange::kLifecycleStateChangeReasonNameHash, TabManager_LifecycleStateChange::kLifecycleStateChangeReasonName},

    {TabManager_LifecycleStateChange::kNewLifecycleStateNameHash, TabManager_LifecycleStateChange::kNewLifecycleStateName},

    {TabManager_LifecycleStateChange::kOldLifecycleStateNameHash, TabManager_LifecycleStateChange::kOldLifecycleStateName},

    {TabManager_LifecycleStateChange::kOutcomeNameHash, TabManager_LifecycleStateChange::kOutcomeName},

    {TabManager_LifecycleStateChange::kSuccessGlobalWhitelistNameHash, TabManager_LifecycleStateChange::kSuccessGlobalWhitelistName},

    {TabManager_LifecycleStateChange::kSuccessHeuristicNameHash, TabManager_LifecycleStateChange::kSuccessHeuristicName},

    {TabManager_LifecycleStateChange::kSuccessOriginTrialOptInNameHash, TabManager_LifecycleStateChange::kSuccessOriginTrialOptInName},

    {TabManager_LifecycleStateChange::kTimeSinceNavigationMsNameHash, TabManager_LifecycleStateChange::kTimeSinceNavigationMsName},

    {TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsNameHash, TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsName},

    {TabManager_LifecycleStateChange::kTransitionForcedNameHash, TabManager_LifecycleStateChange::kTransitionForcedName},

    {TabManager_LifecycleStateChange::kVisibilityStateNameHash, TabManager_LifecycleStateChange::kVisibilityStateName},

        }
      }
    },

    {
      UINT64_C(8999972273877232390),
      {
        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName,
        {
          
    {TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash, TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName},

    {TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash, TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName},

    {TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdNameHash, TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdName},

    {TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountNameHash, TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountName},

    {TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash, TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName},

        }
      }
    },

    {
      UINT64_C(16307465990132225428),
      {
        TabManager_TabLifetime::kEntryName,
        {
          
    {TabManager_TabLifetime::kTimeSinceNavigationNameHash, TabManager_TabLifetime::kTimeSinceNavigationName},

        }
      }
    },

    {
      UINT64_C(16400979786435208530),
      {
        TabManager_TabMetrics::kEntryName,
        {
          
    {TabManager_TabMetrics::kContentTypeNameHash, TabManager_TabMetrics::kContentTypeName},

    {TabManager_TabMetrics::kDefaultProtocolHandlerNameHash, TabManager_TabMetrics::kDefaultProtocolHandlerName},

    {TabManager_TabMetrics::kHasBeforeUnloadHandlerNameHash, TabManager_TabMetrics::kHasBeforeUnloadHandlerName},

    {TabManager_TabMetrics::kHasFormEntryNameHash, TabManager_TabMetrics::kHasFormEntryName},

    {TabManager_TabMetrics::kIsExtensionProtectedNameHash, TabManager_TabMetrics::kIsExtensionProtectedName},

    {TabManager_TabMetrics::kIsPinnedNameHash, TabManager_TabMetrics::kIsPinnedName},

    {TabManager_TabMetrics::kKeyEventCountNameHash, TabManager_TabMetrics::kKeyEventCountName},

    {TabManager_TabMetrics::kLabelIdNameHash, TabManager_TabMetrics::kLabelIdName},

    {TabManager_TabMetrics::kMouseEventCountNameHash, TabManager_TabMetrics::kMouseEventCountName},

    {TabManager_TabMetrics::kMRUIndexNameHash, TabManager_TabMetrics::kMRUIndexName},

    {TabManager_TabMetrics::kNavigationEntryCountNameHash, TabManager_TabMetrics::kNavigationEntryCountName},

    {TabManager_TabMetrics::kNumReactivationBeforeNameHash, TabManager_TabMetrics::kNumReactivationBeforeName},

    {TabManager_TabMetrics::kPageTransitionCoreTypeNameHash, TabManager_TabMetrics::kPageTransitionCoreTypeName},

    {TabManager_TabMetrics::kPageTransitionFromAddressBarNameHash, TabManager_TabMetrics::kPageTransitionFromAddressBarName},

    {TabManager_TabMetrics::kPageTransitionIsRedirectNameHash, TabManager_TabMetrics::kPageTransitionIsRedirectName},

    {TabManager_TabMetrics::kQueryIdNameHash, TabManager_TabMetrics::kQueryIdName},

    {TabManager_TabMetrics::kSiteEngagementScoreNameHash, TabManager_TabMetrics::kSiteEngagementScoreName},

    {TabManager_TabMetrics::kTimeFromBackgroundedNameHash, TabManager_TabMetrics::kTimeFromBackgroundedName},

    {TabManager_TabMetrics::kTotalTabCountNameHash, TabManager_TabMetrics::kTotalTabCountName},

    {TabManager_TabMetrics::kTouchEventCountNameHash, TabManager_TabMetrics::kTouchEventCountName},

    {TabManager_TabMetrics::kWasRecentlyAudibleNameHash, TabManager_TabMetrics::kWasRecentlyAudibleName},

    {TabManager_TabMetrics::kWindowIsActiveNameHash, TabManager_TabMetrics::kWindowIsActiveName},

    {TabManager_TabMetrics::kWindowShowStateNameHash, TabManager_TabMetrics::kWindowShowStateName},

    {TabManager_TabMetrics::kWindowTabCountNameHash, TabManager_TabMetrics::kWindowTabCountName},

    {TabManager_TabMetrics::kWindowTypeNameHash, TabManager_TabMetrics::kWindowTypeName},

        }
      }
    },

    {
      UINT64_C(12562637272871338124),
      {
        TabManager_WindowMetrics::kEntryName,
        {
          
    {TabManager_WindowMetrics::kIsActiveNameHash, TabManager_WindowMetrics::kIsActiveName},

    {TabManager_WindowMetrics::kShowStateNameHash, TabManager_WindowMetrics::kShowStateName},

    {TabManager_WindowMetrics::kTabCountNameHash, TabManager_WindowMetrics::kTabCountName},

    {TabManager_WindowMetrics::kTypeNameHash, TabManager_WindowMetrics::kTypeName},

    {TabManager_WindowMetrics::kWindowIdNameHash, TabManager_WindowMetrics::kWindowIdName},

        }
      }
    },

    {
      UINT64_C(833305494688204602),
      {
        TouchToFill_Shown::kEntryName,
        {
          
    {TouchToFill_Shown::kUserActionNameHash, TouchToFill_Shown::kUserActionName},

        }
      }
    },

    {
      UINT64_C(16054416016310256565),
      {
        Translate::kEntryName,
        {
          
    {Translate::kAcceptCountNameHash, Translate::kAcceptCountName},

    {Translate::kCountryNameHash, Translate::kCountryName},

    {Translate::kDeclineCountNameHash, Translate::kDeclineCountName},

    {Translate::kEventTypeNameHash, Translate::kEventTypeName},

    {Translate::kIgnoreCountNameHash, Translate::kIgnoreCountName},

    {Translate::kRankerResponseNameHash, Translate::kRankerResponseName},

    {Translate::kRankerVersionNameHash, Translate::kRankerVersionName},

    {Translate::kSourceLanguageNameHash, Translate::kSourceLanguageName},

    {Translate::kTargetLanguageNameHash, Translate::kTargetLanguageName},

        }
      }
    },

    {
      UINT64_C(15381255782093849665),
      {
        TrustedWebActivity_Open::kEntryName,
        {
          
    {TrustedWebActivity_Open::kHasOccurredNameHash, TrustedWebActivity_Open::kHasOccurredName},

        }
      }
    },

    {
      UINT64_C(2395897864454822590),
      {
        UserActivity::kEntryName,
        {
          
    {UserActivity::kBatteryPercentNameHash, UserActivity::kBatteryPercentName},

    {UserActivity::kDeviceManagementNameHash, UserActivity::kDeviceManagementName},

    {UserActivity::kDeviceModeNameHash, UserActivity::kDeviceModeName},

    {UserActivity::kDeviceTypeNameHash, UserActivity::kDeviceTypeName},

    {UserActivity::kEventLogDurationNameHash, UserActivity::kEventLogDurationName},

    {UserActivity::kEventReasonNameHash, UserActivity::kEventReasonName},

    {UserActivity::kEventTypeNameHash, UserActivity::kEventTypeName},

    {UserActivity::kKeyEventsInLastHourNameHash, UserActivity::kKeyEventsInLastHourName},

    {UserActivity::kLastActivityDayNameHash, UserActivity::kLastActivityDayName},

    {UserActivity::kLastActivityTimeNameHash, UserActivity::kLastActivityTimeName},

    {UserActivity::kLastUserActivityTimeNameHash, UserActivity::kLastUserActivityTimeName},

    {UserActivity::kModelAppliedNameHash, UserActivity::kModelAppliedName},

    {UserActivity::kModelDecisionThresholdNameHash, UserActivity::kModelDecisionThresholdName},

    {UserActivity::kModelInactivityScoreNameHash, UserActivity::kModelInactivityScoreName},

    {UserActivity::kModelResponseNameHash, UserActivity::kModelResponseName},

    {UserActivity::kMouseEventsInLastHourNameHash, UserActivity::kMouseEventsInLastHourName},

    {UserActivity::kOnBatteryNameHash, UserActivity::kOnBatteryName},

    {UserActivity::kPreviousNegativeActionsCountNameHash, UserActivity::kPreviousNegativeActionsCountName},

    {UserActivity::kPreviousPositiveActionsCountNameHash, UserActivity::kPreviousPositiveActionsCountName},

    {UserActivity::kRecentTimeActiveNameHash, UserActivity::kRecentTimeActiveName},

    {UserActivity::kRecentVideoPlayingTimeNameHash, UserActivity::kRecentVideoPlayingTimeName},

    {UserActivity::kScreenDimDelayNameHash, UserActivity::kScreenDimDelayName},

    {UserActivity::kScreenDimmedInitiallyNameHash, UserActivity::kScreenDimmedInitiallyName},

    {UserActivity::kScreenDimOccurredNameHash, UserActivity::kScreenDimOccurredName},

    {UserActivity::kScreenDimToOffDelayNameHash, UserActivity::kScreenDimToOffDelayName},

    {UserActivity::kScreenLockedInitiallyNameHash, UserActivity::kScreenLockedInitiallyName},

    {UserActivity::kScreenLockOccurredNameHash, UserActivity::kScreenLockOccurredName},

    {UserActivity::kScreenOffInitiallyNameHash, UserActivity::kScreenOffInitiallyName},

    {UserActivity::kScreenOffOccurredNameHash, UserActivity::kScreenOffOccurredName},

    {UserActivity::kSequenceIdNameHash, UserActivity::kSequenceIdName},

    {UserActivity::kTimeSinceLastKeyNameHash, UserActivity::kTimeSinceLastKeyName},

    {UserActivity::kTimeSinceLastMouseNameHash, UserActivity::kTimeSinceLastMouseName},

    {UserActivity::kTimeSinceLastTouchNameHash, UserActivity::kTimeSinceLastTouchName},

    {UserActivity::kTimeSinceLastVideoEndedNameHash, UserActivity::kTimeSinceLastVideoEndedName},

    {UserActivity::kTouchEventsInLastHourNameHash, UserActivity::kTouchEventsInLastHourName},

        }
      }
    },

    {
      UINT64_C(13821826834442202003),
      {
        UserActivityId::kEntryName,
        {
          
    {UserActivityId::kActivityIdNameHash, UserActivityId::kActivityIdName},

    {UserActivityId::kContentTypeNameHash, UserActivityId::kContentTypeName},

    {UserActivityId::kHasFormEntryNameHash, UserActivityId::kHasFormEntryName},

    {UserActivityId::kIsActiveNameHash, UserActivityId::kIsActiveName},

    {UserActivityId::kIsBrowserFocusedNameHash, UserActivityId::kIsBrowserFocusedName},

    {UserActivityId::kIsBrowserVisibleNameHash, UserActivityId::kIsBrowserVisibleName},

    {UserActivityId::kIsTopmostBrowserNameHash, UserActivityId::kIsTopmostBrowserName},

    {UserActivityId::kSiteEngagementScoreNameHash, UserActivityId::kSiteEngagementScoreName},

        }
      }
    },

    {
      UINT64_C(12666214553193795663),
      {
        UserSettingsEvent::kEntryName,
        {
          
    {UserSettingsEvent::kAccessibilityIdNameHash, UserSettingsEvent::kAccessibilityIdName},

    {UserSettingsEvent::kBatteryPercentageNameHash, UserSettingsEvent::kBatteryPercentageName},

    {UserSettingsEvent::kCountryNameHash, UserSettingsEvent::kCountryName},

    {UserSettingsEvent::kCurrentValueNameHash, UserSettingsEvent::kCurrentValueName},

    {UserSettingsEvent::kDayOfWeekNameHash, UserSettingsEvent::kDayOfWeekName},

    {UserSettingsEvent::kDeviceModeNameHash, UserSettingsEvent::kDeviceModeName},

    {UserSettingsEvent::kDeviceOrientationNameHash, UserSettingsEvent::kDeviceOrientationName},

    {UserSettingsEvent::kEventIdNameHash, UserSettingsEvent::kEventIdName},

    {UserSettingsEvent::kHasNightLightScheduleNameHash, UserSettingsEvent::kHasNightLightScheduleName},

    {UserSettingsEvent::kHasWifiSecurityNameHash, UserSettingsEvent::kHasWifiSecurityName},

    {UserSettingsEvent::kHourOfDayNameHash, UserSettingsEvent::kHourOfDayName},

    {UserSettingsEvent::kIsAfterSunsetNameHash, UserSettingsEvent::kIsAfterSunsetName},

    {UserSettingsEvent::kIsChargingNameHash, UserSettingsEvent::kIsChargingName},

    {UserSettingsEvent::kIsFromSearchNameHash, UserSettingsEvent::kIsFromSearchName},

    {UserSettingsEvent::kIsPairedBluetoothDeviceNameHash, UserSettingsEvent::kIsPairedBluetoothDeviceName},

    {UserSettingsEvent::kIsPlayingAudioNameHash, UserSettingsEvent::kIsPlayingAudioName},

    {UserSettingsEvent::kIsPlayingVideoNameHash, UserSettingsEvent::kIsPlayingVideoName},

    {UserSettingsEvent::kIsRecentlyFullscreenNameHash, UserSettingsEvent::kIsRecentlyFullscreenName},

    {UserSettingsEvent::kIsRecentlyPresentingNameHash, UserSettingsEvent::kIsRecentlyPresentingName},

    {UserSettingsEvent::kNetworkStatusNameHash, UserSettingsEvent::kNetworkStatusName},

    {UserSettingsEvent::kPreviousValueNameHash, UserSettingsEvent::kPreviousValueName},

    {UserSettingsEvent::kSettingIdNameHash, UserSettingsEvent::kSettingIdName},

    {UserSettingsEvent::kSettingTypeNameHash, UserSettingsEvent::kSettingTypeName},

    {UserSettingsEvent::kSignalStrengthNameHash, UserSettingsEvent::kSignalStrengthName},

    {UserSettingsEvent::kTimeSinceLastSettingsChangeNameHash, UserSettingsEvent::kTimeSinceLastSettingsChangeName},

    {UserSettingsEvent::kUsedCellularInSessionNameHash, UserSettingsEvent::kUsedCellularInSessionName},

        }
      }
    },

    {
      UINT64_C(3904325154478962694),
      {
        VirtualKeyboard_Open::kEntryName,
        {
          
    {VirtualKeyboard_Open::kTextInputTypeNameHash, VirtualKeyboard_Open::kTextInputTypeName},

        }
      }
    },

    {
      UINT64_C(12193435703081602033),
      {
        WebAPK_Install::kEntryName,
        {
          
    {WebAPK_Install::kAppVersionNameHash, WebAPK_Install::kAppVersionName},

    {WebAPK_Install::kDistributorNameHash, WebAPK_Install::kDistributorName},

    {WebAPK_Install::kInstallNameHash, WebAPK_Install::kInstallName},

        }
      }
    },

    {
      UINT64_C(304278077624055651),
      {
        WebAPK_SessionEnd::kEntryName,
        {
          
    {WebAPK_SessionEnd::kAppVersionNameHash, WebAPK_SessionEnd::kAppVersionName},

    {WebAPK_SessionEnd::kDistributorNameHash, WebAPK_SessionEnd::kDistributorName},

    {WebAPK_SessionEnd::kSessionDurationNameHash, WebAPK_SessionEnd::kSessionDurationName},

        }
      }
    },

    {
      UINT64_C(15147671640732652143),
      {
        WebAPK_Uninstall::kEntryName,
        {
          
    {WebAPK_Uninstall::kAppVersionNameHash, WebAPK_Uninstall::kAppVersionName},

    {WebAPK_Uninstall::kDistributorNameHash, WebAPK_Uninstall::kDistributorName},

    {WebAPK_Uninstall::kInstalledDurationNameHash, WebAPK_Uninstall::kInstalledDurationName},

    {WebAPK_Uninstall::kLifetimeLaunchesNameHash, WebAPK_Uninstall::kLifetimeLaunchesName},

    {WebAPK_Uninstall::kUninstallNameHash, WebAPK_Uninstall::kUninstallName},

        }
      }
    },

    {
      UINT64_C(7419239618516179300),
      {
        WebAPK_Visit::kEntryName,
        {
          
    {WebAPK_Visit::kAppVersionNameHash, WebAPK_Visit::kAppVersionName},

    {WebAPK_Visit::kDistributorNameHash, WebAPK_Visit::kDistributorName},

    {WebAPK_Visit::kLaunchNameHash, WebAPK_Visit::kLaunchName},

    {WebAPK_Visit::kLaunchSourceNameHash, WebAPK_Visit::kLaunchSourceName},

        }
      }
    },

    {
      UINT64_C(10823086981545979708),
      {
        WebApp_DailyInteraction::kEntryName,
        {
          
    {WebApp_DailyInteraction::kBackgroundDurationNameHash, WebApp_DailyInteraction::kBackgroundDurationName},

    {WebApp_DailyInteraction::kDisplayModeNameHash, WebApp_DailyInteraction::kDisplayModeName},

    {WebApp_DailyInteraction::kForegroundDurationNameHash, WebApp_DailyInteraction::kForegroundDurationName},

    {WebApp_DailyInteraction::kInstalledNameHash, WebApp_DailyInteraction::kInstalledName},

    {WebApp_DailyInteraction::kInstallSourceNameHash, WebApp_DailyInteraction::kInstallSourceName},

    {WebApp_DailyInteraction::kNumSessionsNameHash, WebApp_DailyInteraction::kNumSessionsName},

    {WebApp_DailyInteraction::kPromotableNameHash, WebApp_DailyInteraction::kPromotableName},

    {WebApp_DailyInteraction::kUsedNameHash, WebApp_DailyInteraction::kUsedName},

        }
      }
    },

    {
      UINT64_C(6759459948386423184),
      {
        WebRTC_AddressHarvesting::kEntryName,
        {
          
    {WebRTC_AddressHarvesting::kUsagePatternNameHash, WebRTC_AddressHarvesting::kUsagePatternName},

        }
      }
    },

    {
      UINT64_C(7456919696038345904),
      {
        WebRTC_ComplexSdp::kEntryName,
        {
          
    {WebRTC_ComplexSdp::kCategoryNameHash, WebRTC_ComplexSdp::kCategoryName},

        }
      }
    },

    {
      UINT64_C(2966287978545946180),
      {
        XR_WebXR::kEntryName,
        {
          
    {XR_WebXR::kDidGetXRInputSourcesNameHash, XR_WebXR::kDidGetXRInputSourcesName},

    {XR_WebXR::kDidRequestAvailableDevicesNameHash, XR_WebXR::kDidRequestAvailableDevicesName},

    {XR_WebXR::kDidRequestPoseNameHash, XR_WebXR::kDidRequestPoseName},

    {XR_WebXR::kDidRequestPresentationNameHash, XR_WebXR::kDidRequestPresentationName},

    {XR_WebXR::kDidUseNavigatorXRNameHash, XR_WebXR::kDidUseNavigatorXRName},

    {XR_WebXR::kReturnedDeviceNameHash, XR_WebXR::kReturnedDeviceName},

    {XR_WebXR::kReturnedPresentationCapableDeviceNameHash, XR_WebXR::kReturnedPresentationCapableDeviceName},

        }
      }
    },

    {
      UINT64_C(4113953897099533496),
      {
        XR_WebXR_Session::kEntryName,
        {
          
    {XR_WebXR_Session::kDurationNameHash, XR_WebXR_Session::kDurationName},

    {XR_WebXR_Session::kFeatureRequest_BoundedFloorNameHash, XR_WebXR_Session::kFeatureRequest_BoundedFloorName},

    {XR_WebXR_Session::kFeatureRequest_LocalNameHash, XR_WebXR_Session::kFeatureRequest_LocalName},

    {XR_WebXR_Session::kFeatureRequest_LocalFloorNameHash, XR_WebXR_Session::kFeatureRequest_LocalFloorName},

    {XR_WebXR_Session::kFeatureRequest_UnboundedNameHash, XR_WebXR_Session::kFeatureRequest_UnboundedName},

    {XR_WebXR_Session::kFeatureRequest_ViewerNameHash, XR_WebXR_Session::kFeatureRequest_ViewerName},

    {XR_WebXR_Session::kFeatureUse_BoundedFloorNameHash, XR_WebXR_Session::kFeatureUse_BoundedFloorName},

    {XR_WebXR_Session::kFeatureUse_LocalNameHash, XR_WebXR_Session::kFeatureUse_LocalName},

    {XR_WebXR_Session::kFeatureUse_LocalFloorNameHash, XR_WebXR_Session::kFeatureUse_LocalFloorName},

    {XR_WebXR_Session::kFeatureUse_UnboundedNameHash, XR_WebXR_Session::kFeatureUse_UnboundedName},

    {XR_WebXR_Session::kFeatureUse_ViewerNameHash, XR_WebXR_Session::kFeatureUse_ViewerName},

    {XR_WebXR_Session::kModeNameHash, XR_WebXR_Session::kModeName},

        }
      }
    },

    {
      UINT64_C(15349576264204541813),
      {
        XR_WebXR_SessionRequest::kEntryName,
        {
          
    {XR_WebXR_SessionRequest::kFeature_BoundedFloorNameHash, XR_WebXR_SessionRequest::kFeature_BoundedFloorName},

    {XR_WebXR_SessionRequest::kFeature_LocalNameHash, XR_WebXR_SessionRequest::kFeature_LocalName},

    {XR_WebXR_SessionRequest::kFeature_LocalFloorNameHash, XR_WebXR_SessionRequest::kFeature_LocalFloorName},

    {XR_WebXR_SessionRequest::kFeature_UnboundedNameHash, XR_WebXR_SessionRequest::kFeature_UnboundedName},

    {XR_WebXR_SessionRequest::kFeature_ViewerNameHash, XR_WebXR_SessionRequest::kFeature_ViewerName},

    {XR_WebXR_SessionRequest::kModeNameHash, XR_WebXR_SessionRequest::kModeName},

    {XR_WebXR_SessionRequest::kStatusNameHash, XR_WebXR_SessionRequest::kStatusName},

        }
      }
    },

  };
}

}  // namespace builders
}  // namespace ukm
