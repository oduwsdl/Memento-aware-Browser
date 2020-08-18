// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_lookup_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5


#include "third_party/blink/renderer/core/html_element_lookup_trie.h"

#include "third_party/blink/renderer/core/html_names.h"

namespace blink {

const AtomicString& lookupHTMLTag(const UChar* data, unsigned length) {
  DCHECK(data);
  DCHECK(length);
  switch (length) {
    case 1:
        switch (data[0]) {
        case 'a':
            return html_names::kATag.LocalName();

        case 'b':
            return html_names::kBTag.LocalName();

        case 'i':
            return html_names::kITag.LocalName();

        case 'p':
            return html_names::kPTag.LocalName();

        case 'q':
            return html_names::kQTag.LocalName();

        case 's':
            return html_names::kSTag.LocalName();

        case 'u':
            return html_names::kUTag.LocalName();

        }
        break;

    case 2:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'r')
                return html_names::kBrTag.LocalName();
            break;

        case 'd':
            switch (data[1]) {
            case 'd':
                return html_names::kDdTag.LocalName();

            case 'l':
                return html_names::kDlTag.LocalName();

            case 't':
                return html_names::kDtTag.LocalName();

            }
            break;

        case 'e':
            if (data[1] == 'm')
                return html_names::kEmTag.LocalName();
            break;

        case 'h':
            switch (data[1]) {
            case '1':
                return html_names::kH1Tag.LocalName();

            case '2':
                return html_names::kH2Tag.LocalName();

            case '3':
                return html_names::kH3Tag.LocalName();

            case '4':
                return html_names::kH4Tag.LocalName();

            case '5':
                return html_names::kH5Tag.LocalName();

            case '6':
                return html_names::kH6Tag.LocalName();

            case 'r':
                return html_names::kHrTag.LocalName();

            }
            break;

        case 'l':
            if (data[1] == 'i')
                return html_names::kLiTag.LocalName();
            break;

        case 'o':
            if (data[1] == 'l')
                return html_names::kOlTag.LocalName();
            break;

        case 'r':
            switch (data[1]) {
            case 'b':
                return html_names::kRbTag.LocalName();

            case 'p':
                return html_names::kRpTag.LocalName();

            case 't':
                return html_names::kRtTag.LocalName();

            }
            break;

        case 't':
            switch (data[1]) {
            case 'd':
                return html_names::kTdTag.LocalName();

            case 'h':
                return html_names::kThTag.LocalName();

            case 'r':
                return html_names::kTrTag.LocalName();

            case 't':
                return html_names::kTtTag.LocalName();

            }
            break;

        case 'u':
            if (data[1] == 'l')
                return html_names::kUlTag.LocalName();
            break;

        }
        break;

    case 3:
        switch (data[0]) {
        case 'b':
            switch (data[1]) {
            case 'd':
                switch (data[2]) {
                case 'i':
                    return html_names::kBdiTag.LocalName();

                case 'o':
                    return html_names::kBdoTag.LocalName();

                }
                break;

            case 'i':
                if (data[2] == 'g')
                    return html_names::kBigTag.LocalName();
                break;

            }
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'l')
                return html_names::kColTag.LocalName();
            break;

        case 'd':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'l')
                    return html_names::kDelTag.LocalName();
                break;

            case 'f':
                if (data[2] == 'n')
                    return html_names::kDfnTag.LocalName();
                break;

            case 'i':
                switch (data[2]) {
                case 'r':
                    return html_names::kDirTag.LocalName();

                case 'v':
                    return html_names::kDivTag.LocalName();

                }
                break;

            }
            break;

        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'g')
                    return html_names::kImgTag.LocalName();
                break;

            case 'n':
                if (data[2] == 's')
                    return html_names::kInsTag.LocalName();
                break;

            }
            break;

        case 'k':
            if (data[1] == 'b' && data[2] == 'd')
                return html_names::kKbdTag.LocalName();
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'p')
                return html_names::kMapTag.LocalName();
            break;

        case 'n':
            if (data[1] == 'a' && data[2] == 'v')
                return html_names::kNavTag.LocalName();
            break;

        case 'p':
            if (data[1] == 'r' && data[2] == 'e')
                return html_names::kPreTag.LocalName();
            break;

        case 'r':
            if (data[1] == 't' && data[2] == 'c')
                return html_names::kRTCTag.LocalName();
            break;

        case 's':
            switch (data[1]) {
            case 'u':
                switch (data[2]) {
                case 'b':
                    return html_names::kSubTag.LocalName();

                case 'p':
                    return html_names::kSupTag.LocalName();

                }
                break;

            }
            break;

        case 'v':
            if (data[1] == 'a' && data[2] == 'r')
                return html_names::kVarTag.LocalName();
            break;

        case 'w':
            if (data[1] == 'b' && data[2] == 'r')
                return html_names::kWbrTag.LocalName();
            break;

        case 'x':
            if (data[1] == 'm' && data[2] == 'p')
                return html_names::kXmpTag.LocalName();
            break;

        }
        break;

    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'b' && data[3] == 'r')
                    return html_names::kAbbrTag.LocalName();
                break;

            case 'r':
                if (data[2] == 'e' && data[3] == 'a')
                    return html_names::kAreaTag.LocalName();
                break;

            }
            break;

        case 'b':
            switch (data[1]) {
            case 'a':
                if (data[2] == 's' && data[3] == 'e')
                    return html_names::kBaseTag.LocalName();
                break;

            case 'o':
                if (data[2] == 'd' && data[3] == 'y')
                    return html_names::kBodyTag.LocalName();
                break;

            }
            break;

        case 'c':
            switch (data[1]) {
            case 'i':
                if (data[2] == 't' && data[3] == 'e')
                    return html_names::kCiteTag.LocalName();
                break;

            case 'o':
                if (data[2] == 'd' && data[3] == 'e')
                    return html_names::kCodeTag.LocalName();
                break;

            }
            break;

        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a')
                return html_names::kDataTag.LocalName();
            break;

        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 't')
                        return html_names::kFontTag.LocalName();
                    break;

                case 'r':
                    if (data[3] == 'm')
                        return html_names::kFormTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd')
                    return html_names::kHeadTag.LocalName();
                break;

            case 't':
                if (data[2] == 'm' && data[3] == 'l')
                    return html_names::kHTMLTag.LocalName();
                break;

            }
            break;

        case 'l':
            if (data[1] == 'i' && data[2] == 'n' && data[3] == 'k')
                return html_names::kLinkTag.LocalName();
            break;

        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'i':
                    if (data[3] == 'n')
                        return html_names::kMainTag.LocalName();
                    break;

                case 'r':
                    if (data[3] == 'k')
                        return html_names::kMarkTag.LocalName();
                    break;

                }
                break;

            case 'e':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'u')
                        return html_names::kMenuTag.LocalName();
                    break;

                case 't':
                    if (data[3] == 'a')
                        return html_names::kMetaTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'n':
            if (data[1] == 'o' && data[2] == 'b' && data[3] == 'r')
                return html_names::kNobrTag.LocalName();
            break;

        case 'r':
            if (data[1] == 'u' && data[2] == 'b' && data[3] == 'y')
                return html_names::kRubyTag.LocalName();
            break;

        case 's':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'm' && data[3] == 'p')
                    return html_names::kSampTag.LocalName();
                break;

            case 'l':
                if (data[2] == 'o' && data[3] == 't')
                    return html_names::kSlotTag.LocalName();
                break;

            case 'p':
                if (data[2] == 'a' && data[3] == 'n')
                    return html_names::kSpanTag.LocalName();
                break;

            }
            break;

        case 't':
            if (data[1] == 'i' && data[2] == 'm' && data[3] == 'e')
                return html_names::kTimeTag.LocalName();
            break;

        }
        break;

    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 's':
                if (data[2] == 'i' && data[3] == 'd' && data[4] == 'e')
                    return html_names::kAsideTag.LocalName();
                break;

            case 'u':
                if (data[2] == 'd' && data[3] == 'i' && data[4] == 'o')
                    return html_names::kAudioTag.LocalName();
                break;

            }
            break;

        case 'e':
            if (data[1] == 'm' && data[2] == 'b' && data[3] == 'e' && data[4] == 'd')
                return html_names::kEmbedTag.LocalName();
            break;

        case 'f':
            if (data[1] == 'r' && data[2] == 'a' && data[3] == 'm' && data[4] == 'e')
                return html_names::kFrameTag.LocalName();
            break;

        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'g' && data[4] == 'e')
                    return html_names::kImageTag.LocalName();
                break;

            case 'n':
                if (data[2] == 'p' && data[3] == 'u' && data[4] == 't')
                    return html_names::kInputTag.LocalName();
                break;

            }
            break;

        case 'l':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'b':
                    if (data[3] == 'e' && data[4] == 'l')
                        return html_names::kLabelTag.LocalName();
                    break;

                case 'y':
                    if (data[3] == 'e' && data[4] == 'r')
                        return html_names::kLayerTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'm':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'e' && data[4] == 'r')
                return html_names::kMeterTag.LocalName();
            break;

        case 'p':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm')
                return html_names::kParamTag.LocalName();
            break;

        case 's':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'l' && data[4] == 'l')
                    return html_names::kSmallTag.LocalName();
                break;

            case 't':
                if (data[2] == 'y' && data[3] == 'l' && data[4] == 'e')
                    return html_names::kStyleTag.LocalName();
                break;

            }
            break;

        case 't':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'b' && data[3] == 'l' && data[4] == 'e')
                    return html_names::kTableTag.LocalName();
                break;

            case 'b':
                if (data[2] == 'o' && data[3] == 'd' && data[4] == 'y')
                    return html_names::kTbodyTag.LocalName();
                break;

            case 'f':
                if (data[2] == 'o' && data[3] == 'o' && data[4] == 't')
                    return html_names::kTfootTag.LocalName();
                break;

            case 'h':
                if (data[2] == 'e' && data[3] == 'a' && data[4] == 'd')
                    return html_names::kTheadTag.LocalName();
                break;

            case 'i':
                if (data[2] == 't' && data[3] == 'l' && data[4] == 'e')
                    return html_names::kTitleTag.LocalName();
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'c' && data[4] == 'k')
                    return html_names::kTrackTag.LocalName();
                break;

            }
            break;

        case 'v':
            if (data[1] == 'i' && data[2] == 'd' && data[3] == 'e' && data[4] == 'o')
                return html_names::kVideoTag.LocalName();
            break;

        }
        break;

    case 6:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'p' && data[2] == 'p' && data[3] == 'l' && data[4] == 'e' && data[5] == 't')
                return html_names::kAppletTag.LocalName();
            break;

        case 'b':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 't' && data[4] == 'o' && data[5] == 'n')
                return html_names::kButtonTag.LocalName();
            break;

        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'v' && data[4] == 'a' && data[5] == 's')
                    return html_names::kCanvasTag.LocalName();
                break;

            case 'e':
                if (data[2] == 'n' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return html_names::kCenterTag.LocalName();
                break;

            }
            break;

        case 'd':
            if (data[1] == 'i' && data[2] == 'a' && data[3] == 'l' && data[4] == 'o' && data[5] == 'g')
                return html_names::kDialogTag.LocalName();
            break;

        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'g' && data[3] == 'u' && data[4] == 'r' && data[5] == 'e')
                    return html_names::kFigureTag.LocalName();
                break;

            case 'o':
                if (data[2] == 'o' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return html_names::kFooterTag.LocalName();
                break;

            }
            break;

        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r')
                    return html_names::kHeaderTag.LocalName();
                break;

            case 'g':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'u' && data[5] == 'p')
                    return html_names::kHgroupTag.LocalName();
                break;

            }
            break;

        case 'i':
            if (data[1] == 'f' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm' && data[5] == 'e')
                return html_names::kIFrameTag.LocalName();
            break;

        case 'k':
            if (data[1] == 'e' && data[2] == 'y' && data[3] == 'g' && data[4] == 'e' && data[5] == 'n')
                return html_names::kKeygenTag.LocalName();
            break;

        case 'l':
            if (data[1] == 'e' && data[2] == 'g' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd')
                return html_names::kLegendTag.LocalName();
            break;

        case 'o':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'j' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::kObjectTag.LocalName();
                break;

            case 'p':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'o' && data[5] == 'n')
                    return html_names::kOptionTag.LocalName();
                break;

            case 'u':
                if (data[2] == 't' && data[3] == 'p' && data[4] == 'u' && data[5] == 't')
                    return html_names::kOutputTag.LocalName();
                break;

            }
            break;

        case 'p':
            if (data[1] == 'o' && data[2] == 'r' && data[3] == 't' && data[4] == 'a' && data[5] == 'l')
                return html_names::kPortalTag.LocalName();
            break;

        case 's':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'i' && data[4] == 'p' && data[5] == 't')
                    return html_names::kScriptTag.LocalName();
                break;

            case 'e':
                if (data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::kSelectTag.LocalName();
                break;

            case 'h':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'o' && data[5] == 'w')
                    return html_names::kShadowTag.LocalName();
                break;

            case 'o':
                if (data[2] == 'u' && data[3] == 'r' && data[4] == 'c' && data[5] == 'e')
                    return html_names::kSourceTag.LocalName();
                break;

            case 't':
                switch (data[2]) {
                case 'r':
                    switch (data[3]) {
                    case 'i':
                        if (data[4] == 'k' && data[5] == 'e')
                            return html_names::kStrikeTag.LocalName();
                        break;

                    case 'o':
                        if (data[4] == 'n' && data[5] == 'g')
                            return html_names::kStrongTag.LocalName();
                        break;

                    }
                    break;

                }
                break;

            }
            break;

        }
        break;

    case 7:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'n' && data[5] == 'y' && data[6] == 'm')
                    return html_names::kAcronymTag.LocalName();
                break;

            case 'd':
                if (data[2] == 'd' && data[3] == 'r' && data[4] == 'e' && data[5] == 's' && data[6] == 's')
                    return html_names::kAddressTag.LocalName();
                break;

            case 'r':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'c' && data[5] == 'l' && data[6] == 'e')
                    return html_names::kArticleTag.LocalName();
                break;

            }
            break;

        case 'b':
            if (data[1] == 'g' && data[2] == 's' && data[3] == 'o' && data[4] == 'u' && data[5] == 'n' && data[6] == 'd')
                return html_names::kBgsoundTag.LocalName();
            break;

        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'p' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return html_names::kCaptionTag.LocalName();
                break;

            case 'o':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'm' && data[4] == 'a' && data[5] == 'n' && data[6] == 'd')
                        return html_names::kCommandTag.LocalName();
                    break;

                case 'n':
                    if (data[3] == 't' && data[4] == 'e' && data[5] == 'n' && data[6] == 't')
                        return html_names::kContentTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'd':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'a' && data[4] == 'i' && data[5] == 'l' && data[6] == 's')
                return html_names::kDetailsTag.LocalName();
            break;

        case 'l':
            if (data[1] == 'i' && data[2] == 's' && data[3] == 't' && data[4] == 'i' && data[5] == 'n' && data[6] == 'g')
                return html_names::kListingTag.LocalName();
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'q' && data[4] == 'u' && data[5] == 'e' && data[6] == 'e')
                return html_names::kMarqueeTag.LocalName();
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'e':
                    if (data[3] == 'm' && data[4] == 'b' && data[5] == 'e' && data[6] == 'd')
                        return html_names::kNoembedTag.LocalName();
                    break;

                case 'l':
                    if (data[3] == 'a' && data[4] == 'y' && data[5] == 'e' && data[6] == 'r')
                        return html_names::kNolayerTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'p':
            if (data[1] == 'i' && data[2] == 'c' && data[3] == 't' && data[4] == 'u' && data[5] == 'r' && data[6] == 'e')
                return html_names::kPictureTag.LocalName();
            break;

        case 's':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'c' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return html_names::kSectionTag.LocalName();
                break;

            case 'u':
                if (data[2] == 'm' && data[3] == 'm' && data[4] == 'a' && data[5] == 'r' && data[6] == 'y')
                    return html_names::kSummaryTag.LocalName();
                break;

            }
            break;

        }
        break;

    case 8:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'a' && data[2] == 's' && data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'n' && data[7] == 't')
                return html_names::kBasefontTag.LocalName();
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'l' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return html_names::kColgroupTag.LocalName();
            break;

        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a' && data[4] == 'l' && data[5] == 'i' && data[6] == 's' && data[7] == 't')
                return html_names::kDatalistTag.LocalName();
            break;

        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'e' && data[3] == 'l' && data[4] == 'd' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return html_names::kFieldsetTag.LocalName();
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'm' && data[4] == 'e' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return html_names::kFramesetTag.LocalName();
                break;

            }
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'f':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'm' && data[6] == 'e' && data[7] == 's')
                        return html_names::kNoframesTag.LocalName();
                    break;

                case 's':
                    if (data[3] == 'c' && data[4] == 'r' && data[5] == 'i' && data[6] == 'p' && data[7] == 't')
                        return html_names::kNoscriptTag.LocalName();
                    break;

                }
                break;

            }
            break;

        case 'o':
            if (data[1] == 'p' && data[2] == 't' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return html_names::kOptgroupTag.LocalName();
            break;

        case 'p':
            if (data[1] == 'r' && data[2] == 'o' && data[3] == 'g' && data[4] == 'r' && data[5] == 'e' && data[6] == 's' && data[7] == 's')
                return html_names::kProgressTag.LocalName();
            break;

        case 't':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'p' && data[4] == 'l' && data[5] == 'a' && data[6] == 't' && data[7] == 'e')
                        return html_names::kTemplateTag.LocalName();
                    break;

                case 'x':
                    if (data[3] == 't' && data[4] == 'a' && data[5] == 'r' && data[6] == 'e' && data[7] == 'a')
                        return html_names::kTextareaTag.LocalName();
                    break;

                }
                break;

            }
            break;

        }
        break;

    case 9:
        switch (data[0]) {
        case 'p':
            if (data[1] == 'l' && data[2] == 'a' && data[3] == 'i' && data[4] == 'n' && data[5] == 't' && data[6] == 'e' && data[7] == 'x' && data[8] == 't')
                return html_names::kPlaintextTag.LocalName();
            break;

        }
        break;

    case 10:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'l' && data[2] == 'o' && data[3] == 'c' && data[4] == 'k' && data[5] == 'q' && data[6] == 'u' && data[7] == 'o' && data[8] == 't' && data[9] == 'e')
                return html_names::kBlockquoteTag.LocalName();
            break;

        case 'f':
            if (data[1] == 'i' && data[2] == 'g' && data[3] == 'c' && data[4] == 'a' && data[5] == 'p' && data[6] == 't' && data[7] == 'i' && data[8] == 'o' && data[9] == 'n')
                return html_names::kFigcaptionTag.LocalName();
            break;

        }
        break;

    }

  return g_null_atom;
}

}  // namespace blink
