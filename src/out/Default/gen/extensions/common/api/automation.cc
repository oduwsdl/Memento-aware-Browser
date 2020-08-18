// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/automation.idl
// DO NOT EDIT.

#include "tools/json_schema_compiler/util.h"
#include "base/logging.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "extensions/common/api/automation.h"
#include <set>
#include <utility>

using base::UTF8ToUTF16;

namespace extensions {
namespace api {
namespace automation {
//
// Types
//

const char* ToString(EventType enum_param) {
  switch (enum_param) {
    case EVENT_TYPE_ACTIVEDESCENDANTCHANGED:
      return "activedescendantchanged";
    case EVENT_TYPE_ALERT:
      return "alert";
    case EVENT_TYPE_ARIAATTRIBUTECHANGED:
      return "ariaAttributeChanged";
    case EVENT_TYPE_AUTOCORRECTIONOCCURED:
      return "autocorrectionOccured";
    case EVENT_TYPE_BLUR:
      return "blur";
    case EVENT_TYPE_CHECKEDSTATECHANGED:
      return "checkedStateChanged";
    case EVENT_TYPE_CHILDRENCHANGED:
      return "childrenChanged";
    case EVENT_TYPE_CLICKED:
      return "clicked";
    case EVENT_TYPE_CONTROLSCHANGED:
      return "controlsChanged";
    case EVENT_TYPE_DOCUMENTSELECTIONCHANGED:
      return "documentSelectionChanged";
    case EVENT_TYPE_DOCUMENTTITLECHANGED:
      return "documentTitleChanged";
    case EVENT_TYPE_ENDOFTEST:
      return "endOfTest";
    case EVENT_TYPE_EXPANDEDCHANGED:
      return "expandedChanged";
    case EVENT_TYPE_FOCUS:
      return "focus";
    case EVENT_TYPE_FOCUSAFTERMENUCLOSE:
      return "focusAfterMenuClose";
    case EVENT_TYPE_FOCUSCONTEXT:
      return "focusContext";
    case EVENT_TYPE_HIDE:
      return "hide";
    case EVENT_TYPE_HITTESTRESULT:
      return "hitTestResult";
    case EVENT_TYPE_HOVER:
      return "hover";
    case EVENT_TYPE_IMAGEFRAMEUPDATED:
      return "imageFrameUpdated";
    case EVENT_TYPE_INVALIDSTATUSCHANGED:
      return "invalidStatusChanged";
    case EVENT_TYPE_LAYOUTCOMPLETE:
      return "layoutComplete";
    case EVENT_TYPE_LIVEREGIONCHANGED:
      return "liveRegionChanged";
    case EVENT_TYPE_LIVEREGIONCREATED:
      return "liveRegionCreated";
    case EVENT_TYPE_LOADCOMPLETE:
      return "loadComplete";
    case EVENT_TYPE_LOADSTART:
      return "loadStart";
    case EVENT_TYPE_LOCATIONCHANGED:
      return "locationChanged";
    case EVENT_TYPE_MEDIASTARTEDPLAYING:
      return "mediaStartedPlaying";
    case EVENT_TYPE_MEDIASTOPPEDPLAYING:
      return "mediaStoppedPlaying";
    case EVENT_TYPE_MENUEND:
      return "menuEnd";
    case EVENT_TYPE_MENULISTITEMSELECTED:
      return "menuListItemSelected";
    case EVENT_TYPE_MENULISTVALUECHANGED:
      return "menuListValueChanged";
    case EVENT_TYPE_MENUPOPUPEND:
      return "menuPopupEnd";
    case EVENT_TYPE_MENUPOPUPSTART:
      return "menuPopupStart";
    case EVENT_TYPE_MENUSTART:
      return "menuStart";
    case EVENT_TYPE_MOUSECANCELED:
      return "mouseCanceled";
    case EVENT_TYPE_MOUSEDRAGGED:
      return "mouseDragged";
    case EVENT_TYPE_MOUSEMOVED:
      return "mouseMoved";
    case EVENT_TYPE_MOUSEPRESSED:
      return "mousePressed";
    case EVENT_TYPE_MOUSERELEASED:
      return "mouseReleased";
    case EVENT_TYPE_ROWCOLLAPSED:
      return "rowCollapsed";
    case EVENT_TYPE_ROWCOUNTCHANGED:
      return "rowCountChanged";
    case EVENT_TYPE_ROWEXPANDED:
      return "rowExpanded";
    case EVENT_TYPE_SCROLLPOSITIONCHANGED:
      return "scrollPositionChanged";
    case EVENT_TYPE_SCROLLEDTOANCHOR:
      return "scrolledToAnchor";
    case EVENT_TYPE_SELECTEDCHILDRENCHANGED:
      return "selectedChildrenChanged";
    case EVENT_TYPE_SELECTION:
      return "selection";
    case EVENT_TYPE_SELECTIONADD:
      return "selectionAdd";
    case EVENT_TYPE_SELECTIONREMOVE:
      return "selectionRemove";
    case EVENT_TYPE_SHOW:
      return "show";
    case EVENT_TYPE_STATECHANGED:
      return "stateChanged";
    case EVENT_TYPE_TEXTCHANGED:
      return "textChanged";
    case EVENT_TYPE_TEXTSELECTIONCHANGED:
      return "textSelectionChanged";
    case EVENT_TYPE_TOOLTIPCLOSED:
      return "tooltipClosed";
    case EVENT_TYPE_TOOLTIPOPENED:
      return "tooltipOpened";
    case EVENT_TYPE_WINDOWACTIVATED:
      return "windowActivated";
    case EVENT_TYPE_WINDOWDEACTIVATED:
      return "windowDeactivated";
    case EVENT_TYPE_WINDOWVISIBILITYCHANGED:
      return "windowVisibilityChanged";
    case EVENT_TYPE_TREECHANGED:
      return "treeChanged";
    case EVENT_TYPE_VALUECHANGED:
      return "valueChanged";
    case EVENT_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

EventType ParseEventType(const std::string& enum_string) {
  if (enum_string == "activedescendantchanged")
    return EVENT_TYPE_ACTIVEDESCENDANTCHANGED;
  if (enum_string == "alert")
    return EVENT_TYPE_ALERT;
  if (enum_string == "ariaAttributeChanged")
    return EVENT_TYPE_ARIAATTRIBUTECHANGED;
  if (enum_string == "autocorrectionOccured")
    return EVENT_TYPE_AUTOCORRECTIONOCCURED;
  if (enum_string == "blur")
    return EVENT_TYPE_BLUR;
  if (enum_string == "checkedStateChanged")
    return EVENT_TYPE_CHECKEDSTATECHANGED;
  if (enum_string == "childrenChanged")
    return EVENT_TYPE_CHILDRENCHANGED;
  if (enum_string == "clicked")
    return EVENT_TYPE_CLICKED;
  if (enum_string == "controlsChanged")
    return EVENT_TYPE_CONTROLSCHANGED;
  if (enum_string == "documentSelectionChanged")
    return EVENT_TYPE_DOCUMENTSELECTIONCHANGED;
  if (enum_string == "documentTitleChanged")
    return EVENT_TYPE_DOCUMENTTITLECHANGED;
  if (enum_string == "endOfTest")
    return EVENT_TYPE_ENDOFTEST;
  if (enum_string == "expandedChanged")
    return EVENT_TYPE_EXPANDEDCHANGED;
  if (enum_string == "focus")
    return EVENT_TYPE_FOCUS;
  if (enum_string == "focusAfterMenuClose")
    return EVENT_TYPE_FOCUSAFTERMENUCLOSE;
  if (enum_string == "focusContext")
    return EVENT_TYPE_FOCUSCONTEXT;
  if (enum_string == "hide")
    return EVENT_TYPE_HIDE;
  if (enum_string == "hitTestResult")
    return EVENT_TYPE_HITTESTRESULT;
  if (enum_string == "hover")
    return EVENT_TYPE_HOVER;
  if (enum_string == "imageFrameUpdated")
    return EVENT_TYPE_IMAGEFRAMEUPDATED;
  if (enum_string == "invalidStatusChanged")
    return EVENT_TYPE_INVALIDSTATUSCHANGED;
  if (enum_string == "layoutComplete")
    return EVENT_TYPE_LAYOUTCOMPLETE;
  if (enum_string == "liveRegionChanged")
    return EVENT_TYPE_LIVEREGIONCHANGED;
  if (enum_string == "liveRegionCreated")
    return EVENT_TYPE_LIVEREGIONCREATED;
  if (enum_string == "loadComplete")
    return EVENT_TYPE_LOADCOMPLETE;
  if (enum_string == "loadStart")
    return EVENT_TYPE_LOADSTART;
  if (enum_string == "locationChanged")
    return EVENT_TYPE_LOCATIONCHANGED;
  if (enum_string == "mediaStartedPlaying")
    return EVENT_TYPE_MEDIASTARTEDPLAYING;
  if (enum_string == "mediaStoppedPlaying")
    return EVENT_TYPE_MEDIASTOPPEDPLAYING;
  if (enum_string == "menuEnd")
    return EVENT_TYPE_MENUEND;
  if (enum_string == "menuListItemSelected")
    return EVENT_TYPE_MENULISTITEMSELECTED;
  if (enum_string == "menuListValueChanged")
    return EVENT_TYPE_MENULISTVALUECHANGED;
  if (enum_string == "menuPopupEnd")
    return EVENT_TYPE_MENUPOPUPEND;
  if (enum_string == "menuPopupStart")
    return EVENT_TYPE_MENUPOPUPSTART;
  if (enum_string == "menuStart")
    return EVENT_TYPE_MENUSTART;
  if (enum_string == "mouseCanceled")
    return EVENT_TYPE_MOUSECANCELED;
  if (enum_string == "mouseDragged")
    return EVENT_TYPE_MOUSEDRAGGED;
  if (enum_string == "mouseMoved")
    return EVENT_TYPE_MOUSEMOVED;
  if (enum_string == "mousePressed")
    return EVENT_TYPE_MOUSEPRESSED;
  if (enum_string == "mouseReleased")
    return EVENT_TYPE_MOUSERELEASED;
  if (enum_string == "rowCollapsed")
    return EVENT_TYPE_ROWCOLLAPSED;
  if (enum_string == "rowCountChanged")
    return EVENT_TYPE_ROWCOUNTCHANGED;
  if (enum_string == "rowExpanded")
    return EVENT_TYPE_ROWEXPANDED;
  if (enum_string == "scrollPositionChanged")
    return EVENT_TYPE_SCROLLPOSITIONCHANGED;
  if (enum_string == "scrolledToAnchor")
    return EVENT_TYPE_SCROLLEDTOANCHOR;
  if (enum_string == "selectedChildrenChanged")
    return EVENT_TYPE_SELECTEDCHILDRENCHANGED;
  if (enum_string == "selection")
    return EVENT_TYPE_SELECTION;
  if (enum_string == "selectionAdd")
    return EVENT_TYPE_SELECTIONADD;
  if (enum_string == "selectionRemove")
    return EVENT_TYPE_SELECTIONREMOVE;
  if (enum_string == "show")
    return EVENT_TYPE_SHOW;
  if (enum_string == "stateChanged")
    return EVENT_TYPE_STATECHANGED;
  if (enum_string == "textChanged")
    return EVENT_TYPE_TEXTCHANGED;
  if (enum_string == "textSelectionChanged")
    return EVENT_TYPE_TEXTSELECTIONCHANGED;
  if (enum_string == "tooltipClosed")
    return EVENT_TYPE_TOOLTIPCLOSED;
  if (enum_string == "tooltipOpened")
    return EVENT_TYPE_TOOLTIPOPENED;
  if (enum_string == "windowActivated")
    return EVENT_TYPE_WINDOWACTIVATED;
  if (enum_string == "windowDeactivated")
    return EVENT_TYPE_WINDOWDEACTIVATED;
  if (enum_string == "windowVisibilityChanged")
    return EVENT_TYPE_WINDOWVISIBILITYCHANGED;
  if (enum_string == "treeChanged")
    return EVENT_TYPE_TREECHANGED;
  if (enum_string == "valueChanged")
    return EVENT_TYPE_VALUECHANGED;
  return EVENT_TYPE_NONE;
}


const char* ToString(RoleType enum_param) {
  switch (enum_param) {
    case ROLE_TYPE_ABBR:
      return "abbr";
    case ROLE_TYPE_ALERT:
      return "alert";
    case ROLE_TYPE_ALERTDIALOG:
      return "alertDialog";
    case ROLE_TYPE_ANCHOR:
      return "anchor";
    case ROLE_TYPE_APPLICATION:
      return "application";
    case ROLE_TYPE_ARTICLE:
      return "article";
    case ROLE_TYPE_AUDIO:
      return "audio";
    case ROLE_TYPE_BANNER:
      return "banner";
    case ROLE_TYPE_BLOCKQUOTE:
      return "blockquote";
    case ROLE_TYPE_BUTTON:
      return "button";
    case ROLE_TYPE_CANVAS:
      return "canvas";
    case ROLE_TYPE_CAPTION:
      return "caption";
    case ROLE_TYPE_CARET:
      return "caret";
    case ROLE_TYPE_CELL:
      return "cell";
    case ROLE_TYPE_CHECKBOX:
      return "checkBox";
    case ROLE_TYPE_CLIENT:
      return "client";
    case ROLE_TYPE_CODE:
      return "code";
    case ROLE_TYPE_COLORWELL:
      return "colorWell";
    case ROLE_TYPE_COLUMN:
      return "column";
    case ROLE_TYPE_COLUMNHEADER:
      return "columnHeader";
    case ROLE_TYPE_COMBOBOXGROUPING:
      return "comboBoxGrouping";
    case ROLE_TYPE_COMBOBOXMENUBUTTON:
      return "comboBoxMenuButton";
    case ROLE_TYPE_COMMENT:
      return "comment";
    case ROLE_TYPE_COMPLEMENTARY:
      return "complementary";
    case ROLE_TYPE_CONTENTDELETION:
      return "contentDeletion";
    case ROLE_TYPE_CONTENTINSERTION:
      return "contentInsertion";
    case ROLE_TYPE_CONTENTINFO:
      return "contentInfo";
    case ROLE_TYPE_DATE:
      return "date";
    case ROLE_TYPE_DATETIME:
      return "dateTime";
    case ROLE_TYPE_DEFINITION:
      return "definition";
    case ROLE_TYPE_DESCRIPTIONLIST:
      return "descriptionList";
    case ROLE_TYPE_DESCRIPTIONLISTDETAIL:
      return "descriptionListDetail";
    case ROLE_TYPE_DESCRIPTIONLISTTERM:
      return "descriptionListTerm";
    case ROLE_TYPE_DESKTOP:
      return "desktop";
    case ROLE_TYPE_DETAILS:
      return "details";
    case ROLE_TYPE_DIALOG:
      return "dialog";
    case ROLE_TYPE_DIRECTORY:
      return "directory";
    case ROLE_TYPE_DISCLOSURETRIANGLE:
      return "disclosureTriangle";
    case ROLE_TYPE_DOCABSTRACT:
      return "docAbstract";
    case ROLE_TYPE_DOCACKNOWLEDGMENTS:
      return "docAcknowledgments";
    case ROLE_TYPE_DOCAFTERWORD:
      return "docAfterword";
    case ROLE_TYPE_DOCAPPENDIX:
      return "docAppendix";
    case ROLE_TYPE_DOCBACKLINK:
      return "docBackLink";
    case ROLE_TYPE_DOCBIBLIOENTRY:
      return "docBiblioEntry";
    case ROLE_TYPE_DOCBIBLIOGRAPHY:
      return "docBibliography";
    case ROLE_TYPE_DOCBIBLIOREF:
      return "docBiblioRef";
    case ROLE_TYPE_DOCCHAPTER:
      return "docChapter";
    case ROLE_TYPE_DOCCOLOPHON:
      return "docColophon";
    case ROLE_TYPE_DOCCONCLUSION:
      return "docConclusion";
    case ROLE_TYPE_DOCCOVER:
      return "docCover";
    case ROLE_TYPE_DOCCREDIT:
      return "docCredit";
    case ROLE_TYPE_DOCCREDITS:
      return "docCredits";
    case ROLE_TYPE_DOCDEDICATION:
      return "docDedication";
    case ROLE_TYPE_DOCENDNOTE:
      return "docEndnote";
    case ROLE_TYPE_DOCENDNOTES:
      return "docEndnotes";
    case ROLE_TYPE_DOCEPIGRAPH:
      return "docEpigraph";
    case ROLE_TYPE_DOCEPILOGUE:
      return "docEpilogue";
    case ROLE_TYPE_DOCERRATA:
      return "docErrata";
    case ROLE_TYPE_DOCEXAMPLE:
      return "docExample";
    case ROLE_TYPE_DOCFOOTNOTE:
      return "docFootnote";
    case ROLE_TYPE_DOCFOREWORD:
      return "docForeword";
    case ROLE_TYPE_DOCGLOSSARY:
      return "docGlossary";
    case ROLE_TYPE_DOCGLOSSREF:
      return "docGlossRef";
    case ROLE_TYPE_DOCINDEX:
      return "docIndex";
    case ROLE_TYPE_DOCINTRODUCTION:
      return "docIntroduction";
    case ROLE_TYPE_DOCNOTEREF:
      return "docNoteRef";
    case ROLE_TYPE_DOCNOTICE:
      return "docNotice";
    case ROLE_TYPE_DOCPAGEBREAK:
      return "docPageBreak";
    case ROLE_TYPE_DOCPAGELIST:
      return "docPageList";
    case ROLE_TYPE_DOCPART:
      return "docPart";
    case ROLE_TYPE_DOCPREFACE:
      return "docPreface";
    case ROLE_TYPE_DOCPROLOGUE:
      return "docPrologue";
    case ROLE_TYPE_DOCPULLQUOTE:
      return "docPullquote";
    case ROLE_TYPE_DOCQNA:
      return "docQna";
    case ROLE_TYPE_DOCSUBTITLE:
      return "docSubtitle";
    case ROLE_TYPE_DOCTIP:
      return "docTip";
    case ROLE_TYPE_DOCTOC:
      return "docToc";
    case ROLE_TYPE_DOCUMENT:
      return "document";
    case ROLE_TYPE_EMBEDDEDOBJECT:
      return "embeddedObject";
    case ROLE_TYPE_EMPHASIS:
      return "emphasis";
    case ROLE_TYPE_FEED:
      return "feed";
    case ROLE_TYPE_FIGCAPTION:
      return "figcaption";
    case ROLE_TYPE_FIGURE:
      return "figure";
    case ROLE_TYPE_FOOTER:
      return "footer";
    case ROLE_TYPE_FOOTERASNONLANDMARK:
      return "footerAsNonLandmark";
    case ROLE_TYPE_FORM:
      return "form";
    case ROLE_TYPE_GENERICCONTAINER:
      return "genericContainer";
    case ROLE_TYPE_GRAPHICSDOCUMENT:
      return "graphicsDocument";
    case ROLE_TYPE_GRAPHICSOBJECT:
      return "graphicsObject";
    case ROLE_TYPE_GRAPHICSSYMBOL:
      return "graphicsSymbol";
    case ROLE_TYPE_GRID:
      return "grid";
    case ROLE_TYPE_GROUP:
      return "group";
    case ROLE_TYPE_HEADER:
      return "header";
    case ROLE_TYPE_HEADERASNONLANDMARK:
      return "headerAsNonLandmark";
    case ROLE_TYPE_HEADING:
      return "heading";
    case ROLE_TYPE_IFRAME:
      return "iframe";
    case ROLE_TYPE_IFRAMEPRESENTATIONAL:
      return "iframePresentational";
    case ROLE_TYPE_IGNORED:
      return "ignored";
    case ROLE_TYPE_IMAGE:
      return "image";
    case ROLE_TYPE_IMAGEMAP:
      return "imageMap";
    case ROLE_TYPE_IMECANDIDATE:
      return "imeCandidate";
    case ROLE_TYPE_INLINETEXTBOX:
      return "inlineTextBox";
    case ROLE_TYPE_INPUTTIME:
      return "inputTime";
    case ROLE_TYPE_KEYBOARD:
      return "keyboard";
    case ROLE_TYPE_LABELTEXT:
      return "labelText";
    case ROLE_TYPE_LAYOUTTABLE:
      return "layoutTable";
    case ROLE_TYPE_LAYOUTTABLECELL:
      return "layoutTableCell";
    case ROLE_TYPE_LAYOUTTABLEROW:
      return "layoutTableRow";
    case ROLE_TYPE_LEGEND:
      return "legend";
    case ROLE_TYPE_LINEBREAK:
      return "lineBreak";
    case ROLE_TYPE_LINK:
      return "link";
    case ROLE_TYPE_LIST:
      return "list";
    case ROLE_TYPE_LISTBOX:
      return "listBox";
    case ROLE_TYPE_LISTBOXOPTION:
      return "listBoxOption";
    case ROLE_TYPE_LISTGRID:
      return "listGrid";
    case ROLE_TYPE_LISTITEM:
      return "listItem";
    case ROLE_TYPE_LISTMARKER:
      return "listMarker";
    case ROLE_TYPE_LOG:
      return "log";
    case ROLE_TYPE_MAIN:
      return "main";
    case ROLE_TYPE_MARK:
      return "mark";
    case ROLE_TYPE_MARQUEE:
      return "marquee";
    case ROLE_TYPE_MATH:
      return "math";
    case ROLE_TYPE_MENU:
      return "menu";
    case ROLE_TYPE_MENUBAR:
      return "menuBar";
    case ROLE_TYPE_MENUBUTTON:
      return "menuButton";
    case ROLE_TYPE_MENUITEM:
      return "menuItem";
    case ROLE_TYPE_MENUITEMCHECKBOX:
      return "menuItemCheckBox";
    case ROLE_TYPE_MENUITEMRADIO:
      return "menuItemRadio";
    case ROLE_TYPE_MENULISTOPTION:
      return "menuListOption";
    case ROLE_TYPE_MENULISTPOPUP:
      return "menuListPopup";
    case ROLE_TYPE_METER:
      return "meter";
    case ROLE_TYPE_NAVIGATION:
      return "navigation";
    case ROLE_TYPE_NOTE:
      return "note";
    case ROLE_TYPE_PANE:
      return "pane";
    case ROLE_TYPE_PARAGRAPH:
      return "paragraph";
    case ROLE_TYPE_PDFACTIONABLEHIGHLIGHT:
      return "pdfActionableHighlight";
    case ROLE_TYPE_PLUGINOBJECT:
      return "pluginObject";
    case ROLE_TYPE_POPUPBUTTON:
      return "popUpButton";
    case ROLE_TYPE_PORTAL:
      return "portal";
    case ROLE_TYPE_PRE:
      return "pre";
    case ROLE_TYPE_PRESENTATIONAL:
      return "presentational";
    case ROLE_TYPE_PROGRESSINDICATOR:
      return "progressIndicator";
    case ROLE_TYPE_RADIOBUTTON:
      return "radioButton";
    case ROLE_TYPE_RADIOGROUP:
      return "radioGroup";
    case ROLE_TYPE_REGION:
      return "region";
    case ROLE_TYPE_ROOTWEBAREA:
      return "rootWebArea";
    case ROLE_TYPE_ROW:
      return "row";
    case ROLE_TYPE_ROWGROUP:
      return "rowGroup";
    case ROLE_TYPE_ROWHEADER:
      return "rowHeader";
    case ROLE_TYPE_RUBY:
      return "ruby";
    case ROLE_TYPE_RUBYANNOTATION:
      return "rubyAnnotation";
    case ROLE_TYPE_SCROLLBAR:
      return "scrollBar";
    case ROLE_TYPE_SCROLLVIEW:
      return "scrollView";
    case ROLE_TYPE_SEARCH:
      return "search";
    case ROLE_TYPE_SEARCHBOX:
      return "searchBox";
    case ROLE_TYPE_SECTION:
      return "section";
    case ROLE_TYPE_SLIDER:
      return "slider";
    case ROLE_TYPE_SLIDERTHUMB:
      return "sliderThumb";
    case ROLE_TYPE_SPINBUTTON:
      return "spinButton";
    case ROLE_TYPE_SPLITTER:
      return "splitter";
    case ROLE_TYPE_STATICTEXT:
      return "staticText";
    case ROLE_TYPE_STATUS:
      return "status";
    case ROLE_TYPE_STRONG:
      return "strong";
    case ROLE_TYPE_SUGGESTION:
      return "suggestion";
    case ROLE_TYPE_SVGROOT:
      return "svgRoot";
    case ROLE_TYPE_SWITCH:
      return "switch";
    case ROLE_TYPE_TAB:
      return "tab";
    case ROLE_TYPE_TABLIST:
      return "tabList";
    case ROLE_TYPE_TABPANEL:
      return "tabPanel";
    case ROLE_TYPE_TABLE:
      return "table";
    case ROLE_TYPE_TABLEHEADERCONTAINER:
      return "tableHeaderContainer";
    case ROLE_TYPE_TERM:
      return "term";
    case ROLE_TYPE_TEXTFIELD:
      return "textField";
    case ROLE_TYPE_TEXTFIELDWITHCOMBOBOX:
      return "textFieldWithComboBox";
    case ROLE_TYPE_TIME:
      return "time";
    case ROLE_TYPE_TIMER:
      return "timer";
    case ROLE_TYPE_TITLEBAR:
      return "titleBar";
    case ROLE_TYPE_TOGGLEBUTTON:
      return "toggleButton";
    case ROLE_TYPE_TOOLBAR:
      return "toolbar";
    case ROLE_TYPE_TOOLTIP:
      return "tooltip";
    case ROLE_TYPE_TREE:
      return "tree";
    case ROLE_TYPE_TREEGRID:
      return "treeGrid";
    case ROLE_TYPE_TREEITEM:
      return "treeItem";
    case ROLE_TYPE_UNKNOWN:
      return "unknown";
    case ROLE_TYPE_VIDEO:
      return "video";
    case ROLE_TYPE_WEBAREA:
      return "webArea";
    case ROLE_TYPE_WEBVIEW:
      return "webView";
    case ROLE_TYPE_WINDOW:
      return "window";
    case ROLE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

RoleType ParseRoleType(const std::string& enum_string) {
  if (enum_string == "abbr")
    return ROLE_TYPE_ABBR;
  if (enum_string == "alert")
    return ROLE_TYPE_ALERT;
  if (enum_string == "alertDialog")
    return ROLE_TYPE_ALERTDIALOG;
  if (enum_string == "anchor")
    return ROLE_TYPE_ANCHOR;
  if (enum_string == "application")
    return ROLE_TYPE_APPLICATION;
  if (enum_string == "article")
    return ROLE_TYPE_ARTICLE;
  if (enum_string == "audio")
    return ROLE_TYPE_AUDIO;
  if (enum_string == "banner")
    return ROLE_TYPE_BANNER;
  if (enum_string == "blockquote")
    return ROLE_TYPE_BLOCKQUOTE;
  if (enum_string == "button")
    return ROLE_TYPE_BUTTON;
  if (enum_string == "canvas")
    return ROLE_TYPE_CANVAS;
  if (enum_string == "caption")
    return ROLE_TYPE_CAPTION;
  if (enum_string == "caret")
    return ROLE_TYPE_CARET;
  if (enum_string == "cell")
    return ROLE_TYPE_CELL;
  if (enum_string == "checkBox")
    return ROLE_TYPE_CHECKBOX;
  if (enum_string == "client")
    return ROLE_TYPE_CLIENT;
  if (enum_string == "code")
    return ROLE_TYPE_CODE;
  if (enum_string == "colorWell")
    return ROLE_TYPE_COLORWELL;
  if (enum_string == "column")
    return ROLE_TYPE_COLUMN;
  if (enum_string == "columnHeader")
    return ROLE_TYPE_COLUMNHEADER;
  if (enum_string == "comboBoxGrouping")
    return ROLE_TYPE_COMBOBOXGROUPING;
  if (enum_string == "comboBoxMenuButton")
    return ROLE_TYPE_COMBOBOXMENUBUTTON;
  if (enum_string == "comment")
    return ROLE_TYPE_COMMENT;
  if (enum_string == "complementary")
    return ROLE_TYPE_COMPLEMENTARY;
  if (enum_string == "contentDeletion")
    return ROLE_TYPE_CONTENTDELETION;
  if (enum_string == "contentInsertion")
    return ROLE_TYPE_CONTENTINSERTION;
  if (enum_string == "contentInfo")
    return ROLE_TYPE_CONTENTINFO;
  if (enum_string == "date")
    return ROLE_TYPE_DATE;
  if (enum_string == "dateTime")
    return ROLE_TYPE_DATETIME;
  if (enum_string == "definition")
    return ROLE_TYPE_DEFINITION;
  if (enum_string == "descriptionList")
    return ROLE_TYPE_DESCRIPTIONLIST;
  if (enum_string == "descriptionListDetail")
    return ROLE_TYPE_DESCRIPTIONLISTDETAIL;
  if (enum_string == "descriptionListTerm")
    return ROLE_TYPE_DESCRIPTIONLISTTERM;
  if (enum_string == "desktop")
    return ROLE_TYPE_DESKTOP;
  if (enum_string == "details")
    return ROLE_TYPE_DETAILS;
  if (enum_string == "dialog")
    return ROLE_TYPE_DIALOG;
  if (enum_string == "directory")
    return ROLE_TYPE_DIRECTORY;
  if (enum_string == "disclosureTriangle")
    return ROLE_TYPE_DISCLOSURETRIANGLE;
  if (enum_string == "docAbstract")
    return ROLE_TYPE_DOCABSTRACT;
  if (enum_string == "docAcknowledgments")
    return ROLE_TYPE_DOCACKNOWLEDGMENTS;
  if (enum_string == "docAfterword")
    return ROLE_TYPE_DOCAFTERWORD;
  if (enum_string == "docAppendix")
    return ROLE_TYPE_DOCAPPENDIX;
  if (enum_string == "docBackLink")
    return ROLE_TYPE_DOCBACKLINK;
  if (enum_string == "docBiblioEntry")
    return ROLE_TYPE_DOCBIBLIOENTRY;
  if (enum_string == "docBibliography")
    return ROLE_TYPE_DOCBIBLIOGRAPHY;
  if (enum_string == "docBiblioRef")
    return ROLE_TYPE_DOCBIBLIOREF;
  if (enum_string == "docChapter")
    return ROLE_TYPE_DOCCHAPTER;
  if (enum_string == "docColophon")
    return ROLE_TYPE_DOCCOLOPHON;
  if (enum_string == "docConclusion")
    return ROLE_TYPE_DOCCONCLUSION;
  if (enum_string == "docCover")
    return ROLE_TYPE_DOCCOVER;
  if (enum_string == "docCredit")
    return ROLE_TYPE_DOCCREDIT;
  if (enum_string == "docCredits")
    return ROLE_TYPE_DOCCREDITS;
  if (enum_string == "docDedication")
    return ROLE_TYPE_DOCDEDICATION;
  if (enum_string == "docEndnote")
    return ROLE_TYPE_DOCENDNOTE;
  if (enum_string == "docEndnotes")
    return ROLE_TYPE_DOCENDNOTES;
  if (enum_string == "docEpigraph")
    return ROLE_TYPE_DOCEPIGRAPH;
  if (enum_string == "docEpilogue")
    return ROLE_TYPE_DOCEPILOGUE;
  if (enum_string == "docErrata")
    return ROLE_TYPE_DOCERRATA;
  if (enum_string == "docExample")
    return ROLE_TYPE_DOCEXAMPLE;
  if (enum_string == "docFootnote")
    return ROLE_TYPE_DOCFOOTNOTE;
  if (enum_string == "docForeword")
    return ROLE_TYPE_DOCFOREWORD;
  if (enum_string == "docGlossary")
    return ROLE_TYPE_DOCGLOSSARY;
  if (enum_string == "docGlossRef")
    return ROLE_TYPE_DOCGLOSSREF;
  if (enum_string == "docIndex")
    return ROLE_TYPE_DOCINDEX;
  if (enum_string == "docIntroduction")
    return ROLE_TYPE_DOCINTRODUCTION;
  if (enum_string == "docNoteRef")
    return ROLE_TYPE_DOCNOTEREF;
  if (enum_string == "docNotice")
    return ROLE_TYPE_DOCNOTICE;
  if (enum_string == "docPageBreak")
    return ROLE_TYPE_DOCPAGEBREAK;
  if (enum_string == "docPageList")
    return ROLE_TYPE_DOCPAGELIST;
  if (enum_string == "docPart")
    return ROLE_TYPE_DOCPART;
  if (enum_string == "docPreface")
    return ROLE_TYPE_DOCPREFACE;
  if (enum_string == "docPrologue")
    return ROLE_TYPE_DOCPROLOGUE;
  if (enum_string == "docPullquote")
    return ROLE_TYPE_DOCPULLQUOTE;
  if (enum_string == "docQna")
    return ROLE_TYPE_DOCQNA;
  if (enum_string == "docSubtitle")
    return ROLE_TYPE_DOCSUBTITLE;
  if (enum_string == "docTip")
    return ROLE_TYPE_DOCTIP;
  if (enum_string == "docToc")
    return ROLE_TYPE_DOCTOC;
  if (enum_string == "document")
    return ROLE_TYPE_DOCUMENT;
  if (enum_string == "embeddedObject")
    return ROLE_TYPE_EMBEDDEDOBJECT;
  if (enum_string == "emphasis")
    return ROLE_TYPE_EMPHASIS;
  if (enum_string == "feed")
    return ROLE_TYPE_FEED;
  if (enum_string == "figcaption")
    return ROLE_TYPE_FIGCAPTION;
  if (enum_string == "figure")
    return ROLE_TYPE_FIGURE;
  if (enum_string == "footer")
    return ROLE_TYPE_FOOTER;
  if (enum_string == "footerAsNonLandmark")
    return ROLE_TYPE_FOOTERASNONLANDMARK;
  if (enum_string == "form")
    return ROLE_TYPE_FORM;
  if (enum_string == "genericContainer")
    return ROLE_TYPE_GENERICCONTAINER;
  if (enum_string == "graphicsDocument")
    return ROLE_TYPE_GRAPHICSDOCUMENT;
  if (enum_string == "graphicsObject")
    return ROLE_TYPE_GRAPHICSOBJECT;
  if (enum_string == "graphicsSymbol")
    return ROLE_TYPE_GRAPHICSSYMBOL;
  if (enum_string == "grid")
    return ROLE_TYPE_GRID;
  if (enum_string == "group")
    return ROLE_TYPE_GROUP;
  if (enum_string == "header")
    return ROLE_TYPE_HEADER;
  if (enum_string == "headerAsNonLandmark")
    return ROLE_TYPE_HEADERASNONLANDMARK;
  if (enum_string == "heading")
    return ROLE_TYPE_HEADING;
  if (enum_string == "iframe")
    return ROLE_TYPE_IFRAME;
  if (enum_string == "iframePresentational")
    return ROLE_TYPE_IFRAMEPRESENTATIONAL;
  if (enum_string == "ignored")
    return ROLE_TYPE_IGNORED;
  if (enum_string == "image")
    return ROLE_TYPE_IMAGE;
  if (enum_string == "imageMap")
    return ROLE_TYPE_IMAGEMAP;
  if (enum_string == "imeCandidate")
    return ROLE_TYPE_IMECANDIDATE;
  if (enum_string == "inlineTextBox")
    return ROLE_TYPE_INLINETEXTBOX;
  if (enum_string == "inputTime")
    return ROLE_TYPE_INPUTTIME;
  if (enum_string == "keyboard")
    return ROLE_TYPE_KEYBOARD;
  if (enum_string == "labelText")
    return ROLE_TYPE_LABELTEXT;
  if (enum_string == "layoutTable")
    return ROLE_TYPE_LAYOUTTABLE;
  if (enum_string == "layoutTableCell")
    return ROLE_TYPE_LAYOUTTABLECELL;
  if (enum_string == "layoutTableRow")
    return ROLE_TYPE_LAYOUTTABLEROW;
  if (enum_string == "legend")
    return ROLE_TYPE_LEGEND;
  if (enum_string == "lineBreak")
    return ROLE_TYPE_LINEBREAK;
  if (enum_string == "link")
    return ROLE_TYPE_LINK;
  if (enum_string == "list")
    return ROLE_TYPE_LIST;
  if (enum_string == "listBox")
    return ROLE_TYPE_LISTBOX;
  if (enum_string == "listBoxOption")
    return ROLE_TYPE_LISTBOXOPTION;
  if (enum_string == "listGrid")
    return ROLE_TYPE_LISTGRID;
  if (enum_string == "listItem")
    return ROLE_TYPE_LISTITEM;
  if (enum_string == "listMarker")
    return ROLE_TYPE_LISTMARKER;
  if (enum_string == "log")
    return ROLE_TYPE_LOG;
  if (enum_string == "main")
    return ROLE_TYPE_MAIN;
  if (enum_string == "mark")
    return ROLE_TYPE_MARK;
  if (enum_string == "marquee")
    return ROLE_TYPE_MARQUEE;
  if (enum_string == "math")
    return ROLE_TYPE_MATH;
  if (enum_string == "menu")
    return ROLE_TYPE_MENU;
  if (enum_string == "menuBar")
    return ROLE_TYPE_MENUBAR;
  if (enum_string == "menuButton")
    return ROLE_TYPE_MENUBUTTON;
  if (enum_string == "menuItem")
    return ROLE_TYPE_MENUITEM;
  if (enum_string == "menuItemCheckBox")
    return ROLE_TYPE_MENUITEMCHECKBOX;
  if (enum_string == "menuItemRadio")
    return ROLE_TYPE_MENUITEMRADIO;
  if (enum_string == "menuListOption")
    return ROLE_TYPE_MENULISTOPTION;
  if (enum_string == "menuListPopup")
    return ROLE_TYPE_MENULISTPOPUP;
  if (enum_string == "meter")
    return ROLE_TYPE_METER;
  if (enum_string == "navigation")
    return ROLE_TYPE_NAVIGATION;
  if (enum_string == "note")
    return ROLE_TYPE_NOTE;
  if (enum_string == "pane")
    return ROLE_TYPE_PANE;
  if (enum_string == "paragraph")
    return ROLE_TYPE_PARAGRAPH;
  if (enum_string == "pdfActionableHighlight")
    return ROLE_TYPE_PDFACTIONABLEHIGHLIGHT;
  if (enum_string == "pluginObject")
    return ROLE_TYPE_PLUGINOBJECT;
  if (enum_string == "popUpButton")
    return ROLE_TYPE_POPUPBUTTON;
  if (enum_string == "portal")
    return ROLE_TYPE_PORTAL;
  if (enum_string == "pre")
    return ROLE_TYPE_PRE;
  if (enum_string == "presentational")
    return ROLE_TYPE_PRESENTATIONAL;
  if (enum_string == "progressIndicator")
    return ROLE_TYPE_PROGRESSINDICATOR;
  if (enum_string == "radioButton")
    return ROLE_TYPE_RADIOBUTTON;
  if (enum_string == "radioGroup")
    return ROLE_TYPE_RADIOGROUP;
  if (enum_string == "region")
    return ROLE_TYPE_REGION;
  if (enum_string == "rootWebArea")
    return ROLE_TYPE_ROOTWEBAREA;
  if (enum_string == "row")
    return ROLE_TYPE_ROW;
  if (enum_string == "rowGroup")
    return ROLE_TYPE_ROWGROUP;
  if (enum_string == "rowHeader")
    return ROLE_TYPE_ROWHEADER;
  if (enum_string == "ruby")
    return ROLE_TYPE_RUBY;
  if (enum_string == "rubyAnnotation")
    return ROLE_TYPE_RUBYANNOTATION;
  if (enum_string == "scrollBar")
    return ROLE_TYPE_SCROLLBAR;
  if (enum_string == "scrollView")
    return ROLE_TYPE_SCROLLVIEW;
  if (enum_string == "search")
    return ROLE_TYPE_SEARCH;
  if (enum_string == "searchBox")
    return ROLE_TYPE_SEARCHBOX;
  if (enum_string == "section")
    return ROLE_TYPE_SECTION;
  if (enum_string == "slider")
    return ROLE_TYPE_SLIDER;
  if (enum_string == "sliderThumb")
    return ROLE_TYPE_SLIDERTHUMB;
  if (enum_string == "spinButton")
    return ROLE_TYPE_SPINBUTTON;
  if (enum_string == "splitter")
    return ROLE_TYPE_SPLITTER;
  if (enum_string == "staticText")
    return ROLE_TYPE_STATICTEXT;
  if (enum_string == "status")
    return ROLE_TYPE_STATUS;
  if (enum_string == "strong")
    return ROLE_TYPE_STRONG;
  if (enum_string == "suggestion")
    return ROLE_TYPE_SUGGESTION;
  if (enum_string == "svgRoot")
    return ROLE_TYPE_SVGROOT;
  if (enum_string == "switch")
    return ROLE_TYPE_SWITCH;
  if (enum_string == "tab")
    return ROLE_TYPE_TAB;
  if (enum_string == "tabList")
    return ROLE_TYPE_TABLIST;
  if (enum_string == "tabPanel")
    return ROLE_TYPE_TABPANEL;
  if (enum_string == "table")
    return ROLE_TYPE_TABLE;
  if (enum_string == "tableHeaderContainer")
    return ROLE_TYPE_TABLEHEADERCONTAINER;
  if (enum_string == "term")
    return ROLE_TYPE_TERM;
  if (enum_string == "textField")
    return ROLE_TYPE_TEXTFIELD;
  if (enum_string == "textFieldWithComboBox")
    return ROLE_TYPE_TEXTFIELDWITHCOMBOBOX;
  if (enum_string == "time")
    return ROLE_TYPE_TIME;
  if (enum_string == "timer")
    return ROLE_TYPE_TIMER;
  if (enum_string == "titleBar")
    return ROLE_TYPE_TITLEBAR;
  if (enum_string == "toggleButton")
    return ROLE_TYPE_TOGGLEBUTTON;
  if (enum_string == "toolbar")
    return ROLE_TYPE_TOOLBAR;
  if (enum_string == "tooltip")
    return ROLE_TYPE_TOOLTIP;
  if (enum_string == "tree")
    return ROLE_TYPE_TREE;
  if (enum_string == "treeGrid")
    return ROLE_TYPE_TREEGRID;
  if (enum_string == "treeItem")
    return ROLE_TYPE_TREEITEM;
  if (enum_string == "unknown")
    return ROLE_TYPE_UNKNOWN;
  if (enum_string == "video")
    return ROLE_TYPE_VIDEO;
  if (enum_string == "webArea")
    return ROLE_TYPE_WEBAREA;
  if (enum_string == "webView")
    return ROLE_TYPE_WEBVIEW;
  if (enum_string == "window")
    return ROLE_TYPE_WINDOW;
  return ROLE_TYPE_NONE;
}


const char* ToString(StateType enum_param) {
  switch (enum_param) {
    case STATE_TYPE_AUTOFILLAVAILABLE:
      return "autofillAvailable";
    case STATE_TYPE_COLLAPSED:
      return "collapsed";
    case STATE_TYPE_DEFAULT:
      return "default";
    case STATE_TYPE_EDITABLE:
      return "editable";
    case STATE_TYPE_EXPANDED:
      return "expanded";
    case STATE_TYPE_FOCUSABLE:
      return "focusable";
    case STATE_TYPE_FOCUSED:
      return "focused";
    case STATE_TYPE_HORIZONTAL:
      return "horizontal";
    case STATE_TYPE_HOVERED:
      return "hovered";
    case STATE_TYPE_IGNORED:
      return "ignored";
    case STATE_TYPE_INVISIBLE:
      return "invisible";
    case STATE_TYPE_LINKED:
      return "linked";
    case STATE_TYPE_MULTILINE:
      return "multiline";
    case STATE_TYPE_MULTISELECTABLE:
      return "multiselectable";
    case STATE_TYPE_OFFSCREEN:
      return "offscreen";
    case STATE_TYPE_PROTECTED:
      return "protected";
    case STATE_TYPE_REQUIRED:
      return "required";
    case STATE_TYPE_RICHLYEDITABLE:
      return "richlyEditable";
    case STATE_TYPE_VERTICAL:
      return "vertical";
    case STATE_TYPE_VISITED:
      return "visited";
    case STATE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

StateType ParseStateType(const std::string& enum_string) {
  if (enum_string == "autofillAvailable")
    return STATE_TYPE_AUTOFILLAVAILABLE;
  if (enum_string == "collapsed")
    return STATE_TYPE_COLLAPSED;
  if (enum_string == "default")
    return STATE_TYPE_DEFAULT;
  if (enum_string == "editable")
    return STATE_TYPE_EDITABLE;
  if (enum_string == "expanded")
    return STATE_TYPE_EXPANDED;
  if (enum_string == "focusable")
    return STATE_TYPE_FOCUSABLE;
  if (enum_string == "focused")
    return STATE_TYPE_FOCUSED;
  if (enum_string == "horizontal")
    return STATE_TYPE_HORIZONTAL;
  if (enum_string == "hovered")
    return STATE_TYPE_HOVERED;
  if (enum_string == "ignored")
    return STATE_TYPE_IGNORED;
  if (enum_string == "invisible")
    return STATE_TYPE_INVISIBLE;
  if (enum_string == "linked")
    return STATE_TYPE_LINKED;
  if (enum_string == "multiline")
    return STATE_TYPE_MULTILINE;
  if (enum_string == "multiselectable")
    return STATE_TYPE_MULTISELECTABLE;
  if (enum_string == "offscreen")
    return STATE_TYPE_OFFSCREEN;
  if (enum_string == "protected")
    return STATE_TYPE_PROTECTED;
  if (enum_string == "required")
    return STATE_TYPE_REQUIRED;
  if (enum_string == "richlyEditable")
    return STATE_TYPE_RICHLYEDITABLE;
  if (enum_string == "vertical")
    return STATE_TYPE_VERTICAL;
  if (enum_string == "visited")
    return STATE_TYPE_VISITED;
  return STATE_TYPE_NONE;
}


const char* ToString(ActionType enum_param) {
  switch (enum_param) {
    case ACTION_TYPE_ANNOTATEPAGEIMAGES:
      return "annotatePageImages";
    case ACTION_TYPE_BLUR:
      return "blur";
    case ACTION_TYPE_CLEARACCESSIBILITYFOCUS:
      return "clearAccessibilityFocus";
    case ACTION_TYPE_COLLAPSE:
      return "collapse";
    case ACTION_TYPE_CUSTOMACTION:
      return "customAction";
    case ACTION_TYPE_DECREMENT:
      return "decrement";
    case ACTION_TYPE_DODEFAULT:
      return "doDefault";
    case ACTION_TYPE_EXPAND:
      return "expand";
    case ACTION_TYPE_FOCUS:
      return "focus";
    case ACTION_TYPE_GETIMAGEDATA:
      return "getImageData";
    case ACTION_TYPE_GETTEXTLOCATION:
      return "getTextLocation";
    case ACTION_TYPE_HIDETOOLTIP:
      return "hideTooltip";
    case ACTION_TYPE_HITTEST:
      return "hitTest";
    case ACTION_TYPE_INCREMENT:
      return "increment";
    case ACTION_TYPE_INTERNALINVALIDATETREE:
      return "internalInvalidateTree";
    case ACTION_TYPE_LOADINLINETEXTBOXES:
      return "loadInlineTextBoxes";
    case ACTION_TYPE_REPLACESELECTEDTEXT:
      return "replaceSelectedText";
    case ACTION_TYPE_SCROLLBACKWARD:
      return "scrollBackward";
    case ACTION_TYPE_SCROLLDOWN:
      return "scrollDown";
    case ACTION_TYPE_SCROLLFORWARD:
      return "scrollForward";
    case ACTION_TYPE_SCROLLLEFT:
      return "scrollLeft";
    case ACTION_TYPE_SCROLLRIGHT:
      return "scrollRight";
    case ACTION_TYPE_SCROLLUP:
      return "scrollUp";
    case ACTION_TYPE_SCROLLTOMAKEVISIBLE:
      return "scrollToMakeVisible";
    case ACTION_TYPE_SCROLLTOPOINT:
      return "scrollToPoint";
    case ACTION_TYPE_SETACCESSIBILITYFOCUS:
      return "setAccessibilityFocus";
    case ACTION_TYPE_SETSCROLLOFFSET:
      return "setScrollOffset";
    case ACTION_TYPE_SETSELECTION:
      return "setSelection";
    case ACTION_TYPE_SETSEQUENTIALFOCUSNAVIGATIONSTARTINGPOINT:
      return "setSequentialFocusNavigationStartingPoint";
    case ACTION_TYPE_SETVALUE:
      return "setValue";
    case ACTION_TYPE_SHOWCONTEXTMENU:
      return "showContextMenu";
    case ACTION_TYPE_SIGNALENDOFTEST:
      return "signalEndOfTest";
    case ACTION_TYPE_SHOWTOOLTIP:
      return "showTooltip";
    case ACTION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

ActionType ParseActionType(const std::string& enum_string) {
  if (enum_string == "annotatePageImages")
    return ACTION_TYPE_ANNOTATEPAGEIMAGES;
  if (enum_string == "blur")
    return ACTION_TYPE_BLUR;
  if (enum_string == "clearAccessibilityFocus")
    return ACTION_TYPE_CLEARACCESSIBILITYFOCUS;
  if (enum_string == "collapse")
    return ACTION_TYPE_COLLAPSE;
  if (enum_string == "customAction")
    return ACTION_TYPE_CUSTOMACTION;
  if (enum_string == "decrement")
    return ACTION_TYPE_DECREMENT;
  if (enum_string == "doDefault")
    return ACTION_TYPE_DODEFAULT;
  if (enum_string == "expand")
    return ACTION_TYPE_EXPAND;
  if (enum_string == "focus")
    return ACTION_TYPE_FOCUS;
  if (enum_string == "getImageData")
    return ACTION_TYPE_GETIMAGEDATA;
  if (enum_string == "getTextLocation")
    return ACTION_TYPE_GETTEXTLOCATION;
  if (enum_string == "hideTooltip")
    return ACTION_TYPE_HIDETOOLTIP;
  if (enum_string == "hitTest")
    return ACTION_TYPE_HITTEST;
  if (enum_string == "increment")
    return ACTION_TYPE_INCREMENT;
  if (enum_string == "internalInvalidateTree")
    return ACTION_TYPE_INTERNALINVALIDATETREE;
  if (enum_string == "loadInlineTextBoxes")
    return ACTION_TYPE_LOADINLINETEXTBOXES;
  if (enum_string == "replaceSelectedText")
    return ACTION_TYPE_REPLACESELECTEDTEXT;
  if (enum_string == "scrollBackward")
    return ACTION_TYPE_SCROLLBACKWARD;
  if (enum_string == "scrollDown")
    return ACTION_TYPE_SCROLLDOWN;
  if (enum_string == "scrollForward")
    return ACTION_TYPE_SCROLLFORWARD;
  if (enum_string == "scrollLeft")
    return ACTION_TYPE_SCROLLLEFT;
  if (enum_string == "scrollRight")
    return ACTION_TYPE_SCROLLRIGHT;
  if (enum_string == "scrollUp")
    return ACTION_TYPE_SCROLLUP;
  if (enum_string == "scrollToMakeVisible")
    return ACTION_TYPE_SCROLLTOMAKEVISIBLE;
  if (enum_string == "scrollToPoint")
    return ACTION_TYPE_SCROLLTOPOINT;
  if (enum_string == "setAccessibilityFocus")
    return ACTION_TYPE_SETACCESSIBILITYFOCUS;
  if (enum_string == "setScrollOffset")
    return ACTION_TYPE_SETSCROLLOFFSET;
  if (enum_string == "setSelection")
    return ACTION_TYPE_SETSELECTION;
  if (enum_string == "setSequentialFocusNavigationStartingPoint")
    return ACTION_TYPE_SETSEQUENTIALFOCUSNAVIGATIONSTARTINGPOINT;
  if (enum_string == "setValue")
    return ACTION_TYPE_SETVALUE;
  if (enum_string == "showContextMenu")
    return ACTION_TYPE_SHOWCONTEXTMENU;
  if (enum_string == "signalEndOfTest")
    return ACTION_TYPE_SIGNALENDOFTEST;
  if (enum_string == "showTooltip")
    return ACTION_TYPE_SHOWTOOLTIP;
  return ACTION_TYPE_NONE;
}


const char* ToString(TreeChangeType enum_param) {
  switch (enum_param) {
    case TREE_CHANGE_TYPE_NODECREATED:
      return "nodeCreated";
    case TREE_CHANGE_TYPE_SUBTREECREATED:
      return "subtreeCreated";
    case TREE_CHANGE_TYPE_NODECHANGED:
      return "nodeChanged";
    case TREE_CHANGE_TYPE_TEXTCHANGED:
      return "textChanged";
    case TREE_CHANGE_TYPE_NODEREMOVED:
      return "nodeRemoved";
    case TREE_CHANGE_TYPE_SUBTREEUPDATEEND:
      return "subtreeUpdateEnd";
    case TREE_CHANGE_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TreeChangeType ParseTreeChangeType(const std::string& enum_string) {
  if (enum_string == "nodeCreated")
    return TREE_CHANGE_TYPE_NODECREATED;
  if (enum_string == "subtreeCreated")
    return TREE_CHANGE_TYPE_SUBTREECREATED;
  if (enum_string == "nodeChanged")
    return TREE_CHANGE_TYPE_NODECHANGED;
  if (enum_string == "textChanged")
    return TREE_CHANGE_TYPE_TEXTCHANGED;
  if (enum_string == "nodeRemoved")
    return TREE_CHANGE_TYPE_NODEREMOVED;
  if (enum_string == "subtreeUpdateEnd")
    return TREE_CHANGE_TYPE_SUBTREEUPDATEEND;
  return TREE_CHANGE_TYPE_NONE;
}


const char* ToString(NameFromType enum_param) {
  switch (enum_param) {
    case NAME_FROM_TYPE_UNINITIALIZED:
      return "uninitialized";
    case NAME_FROM_TYPE_ATTRIBUTE:
      return "attribute";
    case NAME_FROM_TYPE_ATTRIBUTEEXPLICITLYEMPTY:
      return "attributeExplicitlyEmpty";
    case NAME_FROM_TYPE_CAPTION:
      return "caption";
    case NAME_FROM_TYPE_CONTENTS:
      return "contents";
    case NAME_FROM_TYPE_PLACEHOLDER:
      return "placeholder";
    case NAME_FROM_TYPE_RELATEDELEMENT:
      return "relatedElement";
    case NAME_FROM_TYPE_TITLE:
      return "title";
    case NAME_FROM_TYPE_VALUE:
      return "value";
    case NAME_FROM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

NameFromType ParseNameFromType(const std::string& enum_string) {
  if (enum_string == "uninitialized")
    return NAME_FROM_TYPE_UNINITIALIZED;
  if (enum_string == "attribute")
    return NAME_FROM_TYPE_ATTRIBUTE;
  if (enum_string == "attributeExplicitlyEmpty")
    return NAME_FROM_TYPE_ATTRIBUTEEXPLICITLYEMPTY;
  if (enum_string == "caption")
    return NAME_FROM_TYPE_CAPTION;
  if (enum_string == "contents")
    return NAME_FROM_TYPE_CONTENTS;
  if (enum_string == "placeholder")
    return NAME_FROM_TYPE_PLACEHOLDER;
  if (enum_string == "relatedElement")
    return NAME_FROM_TYPE_RELATEDELEMENT;
  if (enum_string == "title")
    return NAME_FROM_TYPE_TITLE;
  if (enum_string == "value")
    return NAME_FROM_TYPE_VALUE;
  return NAME_FROM_TYPE_NONE;
}


const char* ToString(DescriptionFromType enum_param) {
  switch (enum_param) {
    case DESCRIPTION_FROM_TYPE_UNINITIALIZED:
      return "uninitialized";
    case DESCRIPTION_FROM_TYPE_ATTRIBUTE:
      return "attribute";
    case DESCRIPTION_FROM_TYPE_CONTENTS:
      return "contents";
    case DESCRIPTION_FROM_TYPE_RELATEDELEMENT:
      return "relatedElement";
    case DESCRIPTION_FROM_TYPE_TITLE:
      return "title";
    case DESCRIPTION_FROM_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DescriptionFromType ParseDescriptionFromType(const std::string& enum_string) {
  if (enum_string == "uninitialized")
    return DESCRIPTION_FROM_TYPE_UNINITIALIZED;
  if (enum_string == "attribute")
    return DESCRIPTION_FROM_TYPE_ATTRIBUTE;
  if (enum_string == "contents")
    return DESCRIPTION_FROM_TYPE_CONTENTS;
  if (enum_string == "relatedElement")
    return DESCRIPTION_FROM_TYPE_RELATEDELEMENT;
  if (enum_string == "title")
    return DESCRIPTION_FROM_TYPE_TITLE;
  return DESCRIPTION_FROM_TYPE_NONE;
}


const char* ToString(Restriction enum_param) {
  switch (enum_param) {
    case RESTRICTION_DISABLED:
      return "disabled";
    case RESTRICTION_READONLY:
      return "readOnly";
    case RESTRICTION_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

Restriction ParseRestriction(const std::string& enum_string) {
  if (enum_string == "disabled")
    return RESTRICTION_DISABLED;
  if (enum_string == "readOnly")
    return RESTRICTION_READONLY;
  return RESTRICTION_NONE;
}


const char* ToString(HasPopup enum_param) {
  switch (enum_param) {
    case HAS_POPUP_TRUE:
      return "true";
    case HAS_POPUP_MENU:
      return "menu";
    case HAS_POPUP_LISTBOX:
      return "listbox";
    case HAS_POPUP_TREE:
      return "tree";
    case HAS_POPUP_GRID:
      return "grid";
    case HAS_POPUP_DIALOG:
      return "dialog";
    case HAS_POPUP_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

HasPopup ParseHasPopup(const std::string& enum_string) {
  if (enum_string == "true")
    return HAS_POPUP_TRUE;
  if (enum_string == "menu")
    return HAS_POPUP_MENU;
  if (enum_string == "listbox")
    return HAS_POPUP_LISTBOX;
  if (enum_string == "tree")
    return HAS_POPUP_TREE;
  if (enum_string == "grid")
    return HAS_POPUP_GRID;
  if (enum_string == "dialog")
    return HAS_POPUP_DIALOG;
  return HAS_POPUP_NONE;
}


const char* ToString(DefaultActionVerb enum_param) {
  switch (enum_param) {
    case DEFAULT_ACTION_VERB_ACTIVATE:
      return "activate";
    case DEFAULT_ACTION_VERB_CHECK:
      return "check";
    case DEFAULT_ACTION_VERB_CLICK:
      return "click";
    case DEFAULT_ACTION_VERB_CLICKANCESTOR:
      return "clickAncestor";
    case DEFAULT_ACTION_VERB_JUMP:
      return "jump";
    case DEFAULT_ACTION_VERB_OPEN:
      return "open";
    case DEFAULT_ACTION_VERB_PRESS:
      return "press";
    case DEFAULT_ACTION_VERB_SELECT:
      return "select";
    case DEFAULT_ACTION_VERB_UNCHECK:
      return "uncheck";
    case DEFAULT_ACTION_VERB_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

DefaultActionVerb ParseDefaultActionVerb(const std::string& enum_string) {
  if (enum_string == "activate")
    return DEFAULT_ACTION_VERB_ACTIVATE;
  if (enum_string == "check")
    return DEFAULT_ACTION_VERB_CHECK;
  if (enum_string == "click")
    return DEFAULT_ACTION_VERB_CLICK;
  if (enum_string == "clickAncestor")
    return DEFAULT_ACTION_VERB_CLICKANCESTOR;
  if (enum_string == "jump")
    return DEFAULT_ACTION_VERB_JUMP;
  if (enum_string == "open")
    return DEFAULT_ACTION_VERB_OPEN;
  if (enum_string == "press")
    return DEFAULT_ACTION_VERB_PRESS;
  if (enum_string == "select")
    return DEFAULT_ACTION_VERB_SELECT;
  if (enum_string == "uncheck")
    return DEFAULT_ACTION_VERB_UNCHECK;
  return DEFAULT_ACTION_VERB_NONE;
}


const char* ToString(MarkerType enum_param) {
  switch (enum_param) {
    case MARKER_TYPE_SPELLING:
      return "spelling";
    case MARKER_TYPE_GRAMMAR:
      return "grammar";
    case MARKER_TYPE_TEXTMATCH:
      return "textMatch";
    case MARKER_TYPE_ACTIVESUGGESTION:
      return "activeSuggestion";
    case MARKER_TYPE_SUGGESTION:
      return "suggestion";
    case MARKER_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

MarkerType ParseMarkerType(const std::string& enum_string) {
  if (enum_string == "spelling")
    return MARKER_TYPE_SPELLING;
  if (enum_string == "grammar")
    return MARKER_TYPE_GRAMMAR;
  if (enum_string == "textMatch")
    return MARKER_TYPE_TEXTMATCH;
  if (enum_string == "activeSuggestion")
    return MARKER_TYPE_ACTIVESUGGESTION;
  if (enum_string == "suggestion")
    return MARKER_TYPE_SUGGESTION;
  return MARKER_TYPE_NONE;
}


const char* ToString(EventCommandType enum_param) {
  switch (enum_param) {
    case EVENT_COMMAND_TYPE_CLEARSELECTION:
      return "clearSelection";
    case EVENT_COMMAND_TYPE_CUT:
      return "cut";
    case EVENT_COMMAND_TYPE_DELETE:
      return "delete";
    case EVENT_COMMAND_TYPE_DICTATE:
      return "dictate";
    case EVENT_COMMAND_TYPE_EXTENDSELECTION:
      return "extendSelection";
    case EVENT_COMMAND_TYPE_FORMAT:
      return "format";
    case EVENT_COMMAND_TYPE_INSERT:
      return "insert";
    case EVENT_COMMAND_TYPE_MARKER:
      return "marker";
    case EVENT_COMMAND_TYPE_MOVESELECTION:
      return "moveSelection";
    case EVENT_COMMAND_TYPE_PASTE:
      return "paste";
    case EVENT_COMMAND_TYPE_REPLACE:
      return "replace";
    case EVENT_COMMAND_TYPE_SETSELECTION:
      return "setSelection";
    case EVENT_COMMAND_TYPE_TYPE:
      return "type";
    case EVENT_COMMAND_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

EventCommandType ParseEventCommandType(const std::string& enum_string) {
  if (enum_string == "clearSelection")
    return EVENT_COMMAND_TYPE_CLEARSELECTION;
  if (enum_string == "cut")
    return EVENT_COMMAND_TYPE_CUT;
  if (enum_string == "delete")
    return EVENT_COMMAND_TYPE_DELETE;
  if (enum_string == "dictate")
    return EVENT_COMMAND_TYPE_DICTATE;
  if (enum_string == "extendSelection")
    return EVENT_COMMAND_TYPE_EXTENDSELECTION;
  if (enum_string == "format")
    return EVENT_COMMAND_TYPE_FORMAT;
  if (enum_string == "insert")
    return EVENT_COMMAND_TYPE_INSERT;
  if (enum_string == "marker")
    return EVENT_COMMAND_TYPE_MARKER;
  if (enum_string == "moveSelection")
    return EVENT_COMMAND_TYPE_MOVESELECTION;
  if (enum_string == "paste")
    return EVENT_COMMAND_TYPE_PASTE;
  if (enum_string == "replace")
    return EVENT_COMMAND_TYPE_REPLACE;
  if (enum_string == "setSelection")
    return EVENT_COMMAND_TYPE_SETSELECTION;
  if (enum_string == "type")
    return EVENT_COMMAND_TYPE_TYPE;
  return EVENT_COMMAND_TYPE_NONE;
}


const char* ToString(EventTextBoundaryType enum_param) {
  switch (enum_param) {
    case EVENT_TEXT_BOUNDARY_TYPE_CHARACTER:
      return "character";
    case EVENT_TEXT_BOUNDARY_TYPE_FORMAT:
      return "format";
    case EVENT_TEXT_BOUNDARY_TYPE_LINEEND:
      return "lineEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_LINESTART:
      return "lineStart";
    case EVENT_TEXT_BOUNDARY_TYPE_LINESTARTOREND:
      return "lineStartOrEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_OBJECT:
      return "object";
    case EVENT_TEXT_BOUNDARY_TYPE_PAGEEND:
      return "pageEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_PAGESTART:
      return "pageStart";
    case EVENT_TEXT_BOUNDARY_TYPE_PAGESTARTOREND:
      return "pageStartOrEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHEND:
      return "paragraphEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTART:
      return "paragraphStart";
    case EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTARTOREND:
      return "paragraphStartOrEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_SENTENCEEND:
      return "sentenceEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTART:
      return "sentenceStart";
    case EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTARTOREND:
      return "sentenceStartOrEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_WEBPAGE:
      return "webPage";
    case EVENT_TEXT_BOUNDARY_TYPE_WORDEND:
      return "wordEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_WORDSTART:
      return "wordStart";
    case EVENT_TEXT_BOUNDARY_TYPE_WORDSTARTOREND:
      return "wordStartOrEnd";
    case EVENT_TEXT_BOUNDARY_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

EventTextBoundaryType ParseEventTextBoundaryType(const std::string& enum_string) {
  if (enum_string == "character")
    return EVENT_TEXT_BOUNDARY_TYPE_CHARACTER;
  if (enum_string == "format")
    return EVENT_TEXT_BOUNDARY_TYPE_FORMAT;
  if (enum_string == "lineEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_LINEEND;
  if (enum_string == "lineStart")
    return EVENT_TEXT_BOUNDARY_TYPE_LINESTART;
  if (enum_string == "lineStartOrEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_LINESTARTOREND;
  if (enum_string == "object")
    return EVENT_TEXT_BOUNDARY_TYPE_OBJECT;
  if (enum_string == "pageEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_PAGEEND;
  if (enum_string == "pageStart")
    return EVENT_TEXT_BOUNDARY_TYPE_PAGESTART;
  if (enum_string == "pageStartOrEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_PAGESTARTOREND;
  if (enum_string == "paragraphEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHEND;
  if (enum_string == "paragraphStart")
    return EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTART;
  if (enum_string == "paragraphStartOrEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_PARAGRAPHSTARTOREND;
  if (enum_string == "sentenceEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_SENTENCEEND;
  if (enum_string == "sentenceStart")
    return EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTART;
  if (enum_string == "sentenceStartOrEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_SENTENCESTARTOREND;
  if (enum_string == "webPage")
    return EVENT_TEXT_BOUNDARY_TYPE_WEBPAGE;
  if (enum_string == "wordEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_WORDEND;
  if (enum_string == "wordStart")
    return EVENT_TEXT_BOUNDARY_TYPE_WORDSTART;
  if (enum_string == "wordStartOrEnd")
    return EVENT_TEXT_BOUNDARY_TYPE_WORDSTARTOREND;
  return EVENT_TEXT_BOUNDARY_TYPE_NONE;
}


const char* ToString(EventMoveDirectionType enum_param) {
  switch (enum_param) {
    case EVENT_MOVE_DIRECTION_TYPE_FORWARD:
      return "forward";
    case EVENT_MOVE_DIRECTION_TYPE_BACKWARD:
      return "backward";
    case EVENT_MOVE_DIRECTION_TYPE_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

EventMoveDirectionType ParseEventMoveDirectionType(const std::string& enum_string) {
  if (enum_string == "forward")
    return EVENT_MOVE_DIRECTION_TYPE_FORWARD;
  if (enum_string == "backward")
    return EVENT_MOVE_DIRECTION_TYPE_BACKWARD;
  return EVENT_MOVE_DIRECTION_TYPE_NONE;
}


Rect::Rect()
: left(0),
top(0),
width(0),
height(0) {}

Rect::~Rect() {}
Rect::Rect(Rect&& rhs)
: left(rhs.left),
top(rhs.top),
width(rhs.width),
height(rhs.height){
}

Rect& Rect::operator=(Rect&& rhs)
{
left = rhs.left;
top = rhs.top;
width = rhs.width;
height = rhs.height;
return *this;
}

// static
bool Rect::Populate(
    const base::Value& value, Rect* out) {
  if (!value.is_dict()) {
    return false;
  }
  const base::DictionaryValue* dict = static_cast<const base::DictionaryValue*>(&value);
  const base::Value* left_value = NULL;
  if (!dict->GetWithoutPathExpansion("left", &left_value)) {
    return false;
  }
  {
    if (!left_value->GetAsInteger(&out->left)) {
      return false;
    }
  }

  const base::Value* top_value = NULL;
  if (!dict->GetWithoutPathExpansion("top", &top_value)) {
    return false;
  }
  {
    if (!top_value->GetAsInteger(&out->top)) {
      return false;
    }
  }

  const base::Value* width_value = NULL;
  if (!dict->GetWithoutPathExpansion("width", &width_value)) {
    return false;
  }
  {
    if (!width_value->GetAsInteger(&out->width)) {
      return false;
    }
  }

  const base::Value* height_value = NULL;
  if (!dict->GetWithoutPathExpansion("height", &height_value)) {
    return false;
  }
  {
    if (!height_value->GetAsInteger(&out->height)) {
      return false;
    }
  }

  return true;
}

// static
std::unique_ptr<Rect> Rect::FromValue(const base::Value& value) {
  std::unique_ptr<Rect> out(new Rect());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Rect::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());

  to_value_result->SetWithoutPathExpansion("left", std::make_unique<base::Value>(this->left));

  to_value_result->SetWithoutPathExpansion("top", std::make_unique<base::Value>(this->top));

  to_value_result->SetWithoutPathExpansion("width", std::make_unique<base::Value>(this->width));

  to_value_result->SetWithoutPathExpansion("height", std::make_unique<base::Value>(this->height));


  return to_value_result;
}


FindParams::FindParams()
 {}

FindParams::~FindParams() {}
FindParams::FindParams(FindParams&& rhs)
{
}

FindParams& FindParams::operator=(FindParams&& rhs)
{

return *this;
}

// static
bool FindParams::Populate(
    const base::Value& value, FindParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<FindParams> FindParams::FromValue(const base::Value& value) {
  std::unique_ptr<FindParams> out(new FindParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> FindParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


SetDocumentSelectionParams::SetDocumentSelectionParams()
 {}

SetDocumentSelectionParams::~SetDocumentSelectionParams() {}
SetDocumentSelectionParams::SetDocumentSelectionParams(SetDocumentSelectionParams&& rhs)
{
}

SetDocumentSelectionParams& SetDocumentSelectionParams::operator=(SetDocumentSelectionParams&& rhs)
{

return *this;
}

// static
bool SetDocumentSelectionParams::Populate(
    const base::Value& value, SetDocumentSelectionParams* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<SetDocumentSelectionParams> SetDocumentSelectionParams::FromValue(const base::Value& value) {
  std::unique_ptr<SetDocumentSelectionParams> out(new SetDocumentSelectionParams());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> SetDocumentSelectionParams::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


AutomationIntent::AutomationIntent()
 {}

AutomationIntent::~AutomationIntent() {}
AutomationIntent::AutomationIntent(AutomationIntent&& rhs)
{
}

AutomationIntent& AutomationIntent::operator=(AutomationIntent&& rhs)
{

return *this;
}

// static
bool AutomationIntent::Populate(
    const base::Value& value, AutomationIntent* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<AutomationIntent> AutomationIntent::FromValue(const base::Value& value) {
  std::unique_ptr<AutomationIntent> out(new AutomationIntent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AutomationIntent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


AutomationEvent::AutomationEvent()
 {}

AutomationEvent::~AutomationEvent() {}
AutomationEvent::AutomationEvent(AutomationEvent&& rhs)
{
}

AutomationEvent& AutomationEvent::operator=(AutomationEvent&& rhs)
{

return *this;
}

// static
bool AutomationEvent::Populate(
    const base::Value& value, AutomationEvent* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<AutomationEvent> AutomationEvent::FromValue(const base::Value& value) {
  std::unique_ptr<AutomationEvent> out(new AutomationEvent());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AutomationEvent::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


TreeChange::TreeChange()
 {}

TreeChange::~TreeChange() {}
TreeChange::TreeChange(TreeChange&& rhs)
{
}

TreeChange& TreeChange::operator=(TreeChange&& rhs)
{

return *this;
}

// static
bool TreeChange::Populate(
    const base::Value& value, TreeChange* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<TreeChange> TreeChange::FromValue(const base::Value& value) {
  std::unique_ptr<TreeChange> out(new TreeChange());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> TreeChange::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


const char* ToString(TreeChangeObserverFilter enum_param) {
  switch (enum_param) {
    case TREE_CHANGE_OBSERVER_FILTER_NOTREECHANGES:
      return "noTreeChanges";
    case TREE_CHANGE_OBSERVER_FILTER_LIVEREGIONTREECHANGES:
      return "liveRegionTreeChanges";
    case TREE_CHANGE_OBSERVER_FILTER_TEXTMARKERCHANGES:
      return "textMarkerChanges";
    case TREE_CHANGE_OBSERVER_FILTER_ALLTREECHANGES:
      return "allTreeChanges";
    case TREE_CHANGE_OBSERVER_FILTER_NONE:
      return "";
  }
  NOTREACHED();
  return "";
}

TreeChangeObserverFilter ParseTreeChangeObserverFilter(const std::string& enum_string) {
  if (enum_string == "noTreeChanges")
    return TREE_CHANGE_OBSERVER_FILTER_NOTREECHANGES;
  if (enum_string == "liveRegionTreeChanges")
    return TREE_CHANGE_OBSERVER_FILTER_LIVEREGIONTREECHANGES;
  if (enum_string == "textMarkerChanges")
    return TREE_CHANGE_OBSERVER_FILTER_TEXTMARKERCHANGES;
  if (enum_string == "allTreeChanges")
    return TREE_CHANGE_OBSERVER_FILTER_ALLTREECHANGES;
  return TREE_CHANGE_OBSERVER_FILTER_NONE;
}


CustomAction::CustomAction()
 {}

CustomAction::~CustomAction() {}
CustomAction::CustomAction(CustomAction&& rhs)
{
}

CustomAction& CustomAction::operator=(CustomAction&& rhs)
{

return *this;
}

// static
bool CustomAction::Populate(
    const base::Value& value, CustomAction* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<CustomAction> CustomAction::FromValue(const base::Value& value) {
  std::unique_ptr<CustomAction> out(new CustomAction());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> CustomAction::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


LanguageSpan::LanguageSpan()
 {}

LanguageSpan::~LanguageSpan() {}
LanguageSpan::LanguageSpan(LanguageSpan&& rhs)
{
}

LanguageSpan& LanguageSpan::operator=(LanguageSpan&& rhs)
{

return *this;
}

// static
bool LanguageSpan::Populate(
    const base::Value& value, LanguageSpan* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<LanguageSpan> LanguageSpan::FromValue(const base::Value& value) {
  std::unique_ptr<LanguageSpan> out(new LanguageSpan());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> LanguageSpan::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


Marker::Marker()
 {}

Marker::~Marker() {}
Marker::Marker(Marker&& rhs)
{
}

Marker& Marker::operator=(Marker&& rhs)
{

return *this;
}

// static
bool Marker::Populate(
    const base::Value& value, Marker* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<Marker> Marker::FromValue(const base::Value& value) {
  std::unique_ptr<Marker> out(new Marker());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> Marker::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}


AutomationNode::AutomationNode()
 {}

AutomationNode::~AutomationNode() {}
AutomationNode::AutomationNode(AutomationNode&& rhs)
{
}

AutomationNode& AutomationNode::operator=(AutomationNode&& rhs)
{

return *this;
}

// static
bool AutomationNode::Populate(
    const base::Value& value, AutomationNode* out) {
  if (!value.is_dict()) {
    return false;
  }
  return true;
}

// static
std::unique_ptr<AutomationNode> AutomationNode::FromValue(const base::Value& value) {
  std::unique_ptr<AutomationNode> out(new AutomationNode());
  if (!Populate(value, out.get()))
    return nullptr;
  return out;
}

std::unique_ptr<base::DictionaryValue> AutomationNode::ToValue() const {
  std::unique_ptr<base::DictionaryValue> to_value_result(new base::DictionaryValue());


  return to_value_result;
}



}  // namespace automation
}  // namespace api
}  // namespace extensions

