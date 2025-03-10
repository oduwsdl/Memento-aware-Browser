// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_DRAG_AND_DROP_DRAG_ITEM_UTIL_H_
#define IOS_CHROME_BROWSER_DRAG_AND_DROP_DRAG_ITEM_UTIL_H_

#import <UIKit/UIKit.h>

#import "ios/chrome/browser/window_activities/window_activity_helpers.h"

class GURL;

namespace web {
class WebState;
}

// Information that allows the receiver to locate a tab and also to decide
// whether to allow a drop.
@interface TabInfo : NSObject
// The unique identifier of the tab.
@property(nonatomic, strong, readonly) NSString* tabID;
// If YES, the tab is currently in an incognito profile.
@property(nonatomic, assign, readonly) BOOL incognito;
// Default initializer.
- (instancetype)initWithTabID:(NSString*)tabID incognito:(BOOL)incognito;
- (instancetype)init NS_UNAVAILABLE;
@end

// Creates a drag item that encapsulates a tab and a user activity to move the
// tab to a new window.
UIDragItem* CreateTabDragItem(web::WebState* web_state);

// Creates a drag item that encapsulates an URL and a user activity to open the
// URL in a new Chrome window.
UIDragItem* CreateURLDragItem(const GURL& url, WindowActivityOrigin origin);

#endif  // IOS_CHROME_BROWSER_DRAG_AND_DROP_DRAG_ITEM_UTIL_H_
