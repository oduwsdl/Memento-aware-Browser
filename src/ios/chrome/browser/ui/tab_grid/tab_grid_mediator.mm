// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/chrome/browser/ui/tab_grid/tab_grid_mediator.h"

#import <MobileCoreServices/UTCoreTypes.h>
#import <UIKit/UIKit.h>
#include <memory>

#include "base/bind.h"
#include "base/metrics/histogram_macros.h"
#include "base/scoped_observer.h"
#include "components/favicon/ios/web_favicon_driver.h"
#include "components/sessions/core/tab_restore_service.h"
#include "ios/chrome/browser/browser_state/chrome_browser_state.h"
#include "ios/chrome/browser/chrome_url_constants.h"
#import "ios/chrome/browser/chrome_url_util.h"
#import "ios/chrome/browser/drag_and_drop/drag_item_util.h"
#include "ios/chrome/browser/main/browser.h"
#import "ios/chrome/browser/main/browser_util.h"
#import "ios/chrome/browser/sessions/session_restoration_browser_agent.h"
#import "ios/chrome/browser/snapshots/snapshot_cache.h"
#import "ios/chrome/browser/snapshots/snapshot_cache_factory.h"
#import "ios/chrome/browser/snapshots/snapshot_cache_observer.h"
#import "ios/chrome/browser/snapshots/snapshot_tab_helper.h"
#include "ios/chrome/browser/system_flags.h"
#import "ios/chrome/browser/tabs/tab_title_util.h"
#import "ios/chrome/browser/ui/tab_grid/grid/grid_consumer.h"
#import "ios/chrome/browser/ui/tab_grid/grid/grid_item.h"
#import "ios/chrome/browser/web/tab_id_tab_helper.h"
#include "ios/chrome/browser/web_state_list/web_state_list.h"
#import "ios/chrome/browser/web_state_list/web_state_list_observer_bridge.h"
#import "ios/chrome/browser/web_state_list/web_state_list_serialization.h"
#include "ios/chrome/browser/web_state_list/web_state_opener.h"
#import "ios/web/public/navigation/navigation_manager.h"
#import "ios/web/public/web_state.h"
#import "ios/web/public/web_state_observer_bridge.h"
#import "net/base/mac/url_conversions.h"
#include "ui/gfx/image/image.h"

#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

namespace {
// Constructs a GridItem from a |web_state|.
GridItem* CreateItem(web::WebState* web_state) {
  TabIdTabHelper* tab_helper = TabIdTabHelper::FromWebState(web_state);
  GridItem* item = [[GridItem alloc] initWithIdentifier:tab_helper->tab_id()];
  // chrome://newtab (NTP) tabs have no title.
  if (IsURLNtp(web_state->GetVisibleURL())) {
    item.hidesTitle = YES;
  }
  item.title = tab_util::GetTabTitle(web_state);
  return item;
}

// Constructs an array of GridItems from a |web_state_list|.
NSArray* CreateItems(WebStateList* web_state_list) {
  NSMutableArray* items = [[NSMutableArray alloc] init];
  for (int i = 0; i < web_state_list->count(); i++) {
    web::WebState* web_state = web_state_list->GetWebStateAt(i);
    [items addObject:CreateItem(web_state)];
  }
  return [items copy];
}

// Returns the ID of the active tab in |web_state_list|.
NSString* GetActiveTabId(WebStateList* web_state_list) {
  if (!web_state_list)
    return nil;

  web::WebState* web_state = web_state_list->GetActiveWebState();
  if (!web_state)
    return nil;
  TabIdTabHelper* tab_helper = TabIdTabHelper::FromWebState(web_state);
  return tab_helper->tab_id();
}

// Returns the index of the tab with |identifier| in |web_state_list|. Returns
// -1 if not found.
int GetIndexOfTabWithId(WebStateList* web_state_list, NSString* identifier) {
  for (int i = 0; i < web_state_list->count(); i++) {
    web::WebState* web_state = web_state_list->GetWebStateAt(i);
    TabIdTabHelper* tab_helper = TabIdTabHelper::FromWebState(web_state);
    if ([identifier isEqualToString:tab_helper->tab_id()])
      return i;
  }
  return -1;
}

// Returns the WebState with |identifier| in |web_state_list|. Returns |nullptr|
// if not found.
web::WebState* GetWebStateWithId(WebStateList* web_state_list,
                                 NSString* identifier) {
  for (int i = 0; i < web_state_list->count(); i++) {
    web::WebState* web_state = web_state_list->GetWebStateAt(i);
    TabIdTabHelper* tab_helper = TabIdTabHelper::FromWebState(web_state);
    if ([identifier isEqualToString:tab_helper->tab_id()])
      return web_state;
  }
  return nullptr;
}

}  // namespace

@interface TabGridMediator ()<CRWWebStateObserver,
                              SnapshotCacheObserver,
                              WebStateListObserving>
// The list from the browser.
@property(nonatomic, assign) WebStateList* webStateList;
// The browser state from the browser.
@property(nonatomic, readonly) ChromeBrowserState* browserState;
// The UI consumer to which updates are made.
@property(nonatomic, weak) id<GridConsumer> consumer;
// The saved session window just before close all tabs is called.
@property(nonatomic, strong) SessionWindowIOS* closedSessionWindow;
// The number of tabs in |closedSessionWindow| that are synced by
// TabRestoreService.
@property(nonatomic, assign) int syncedClosedTabsCount;
// Short-term cache for grid thumbnails.
@property(nonatomic, strong)
    NSMutableDictionary<NSString*, UIImage*>* appearanceCache;
@end

@implementation TabGridMediator {
  // Observers for WebStateList.
  std::unique_ptr<WebStateListObserverBridge> _webStateListObserverBridge;
  std::unique_ptr<ScopedObserver<WebStateList, WebStateListObserver>>
      _scopedWebStateListObserver;
  // Observer for WebStates.
  std::unique_ptr<web::WebStateObserverBridge> _webStateObserverBridge;
  std::unique_ptr<ScopedObserver<web::WebState, web::WebStateObserver>>
      _scopedWebStateObserver;
}

// Public properties.
@synthesize browser = _browser;
@synthesize tabRestoreService = _tabRestoreService;
// Private properties.
@synthesize webStateList = _webStateList;
@synthesize browserState = _browserState;
@synthesize consumer = _consumer;
@synthesize closedSessionWindow = _closedSessionWindow;
@synthesize syncedClosedTabsCount = _syncedClosedTabsCount;
@synthesize appearanceCache = _appearanceCache;

- (instancetype)initWithConsumer:(id<GridConsumer>)consumer {
  if (self = [super init]) {
    _consumer = consumer;
    _webStateListObserverBridge =
        std::make_unique<WebStateListObserverBridge>(self);
    _scopedWebStateListObserver =
        std::make_unique<ScopedObserver<WebStateList, WebStateListObserver>>(
            _webStateListObserverBridge.get());
    _webStateObserverBridge =
        std::make_unique<web::WebStateObserverBridge>(self);
    _scopedWebStateObserver =
        std::make_unique<ScopedObserver<web::WebState, web::WebStateObserver>>(
            _webStateObserverBridge.get());
    _appearanceCache = [[NSMutableDictionary alloc] init];
  }
  return self;
}

#pragma mark - Public properties

- (void)setBrowser:(Browser*)browser {
  [self.snapshotCache removeObserver:self];
  _scopedWebStateListObserver->RemoveAll();
  _scopedWebStateObserver->RemoveAll();
  _browser = browser;
  _webStateList = browser ? browser->GetWebStateList() : nullptr;
  _browserState = browser ? browser->GetBrowserState() : nullptr;
  [self.snapshotCache addObserver:self];

  if (_webStateList) {
    _scopedWebStateListObserver->Add(_webStateList);
    for (int i = 0; i < self.webStateList->count(); i++) {
      web::WebState* webState = self.webStateList->GetWebStateAt(i);
      _scopedWebStateObserver->Add(webState);
    }
    [self populateConsumerItems];
  }
}

#pragma mark - WebStateListObserving

- (void)webStateList:(WebStateList*)webStateList
    didInsertWebState:(web::WebState*)webState
              atIndex:(int)index
           activating:(BOOL)activating {
  [self.consumer insertItem:CreateItem(webState)
                    atIndex:index
             selectedItemID:GetActiveTabId(webStateList)];
  _scopedWebStateObserver->Add(webState);
}

- (void)webStateList:(WebStateList*)webStateList
     didMoveWebState:(web::WebState*)webState
           fromIndex:(int)fromIndex
             toIndex:(int)toIndex {
  TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(webState);
  [self.consumer moveItemWithID:tabHelper->tab_id() toIndex:toIndex];
}

- (void)webStateList:(WebStateList*)webStateList
    didReplaceWebState:(web::WebState*)oldWebState
          withWebState:(web::WebState*)newWebState
               atIndex:(int)index {
  TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(oldWebState);
  [self.consumer replaceItemID:tabHelper->tab_id()
                      withItem:CreateItem(newWebState)];
  _scopedWebStateObserver->Remove(oldWebState);
  _scopedWebStateObserver->Add(newWebState);
}

- (void)webStateList:(WebStateList*)webStateList
    didDetachWebState:(web::WebState*)webState
              atIndex:(int)index {
  if (!webStateList)
    return;
  TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(webState);
  NSString* itemID = tabHelper->tab_id();
  [self.consumer removeItemWithID:itemID
                   selectedItemID:GetActiveTabId(webStateList)];
  _scopedWebStateObserver->Remove(webState);
}

- (void)webStateList:(WebStateList*)webStateList
    didChangeActiveWebState:(web::WebState*)newWebState
                oldWebState:(web::WebState*)oldWebState
                    atIndex:(int)atIndex
                     reason:(ActiveWebStateChangeReason)reason {
  // If the selected index changes as a result of the last webstate being
  // detached, atIndex will be -1.
  if (atIndex == -1) {
    [self.consumer selectItemWithID:nil];
    return;
  }

  TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(newWebState);
  [self.consumer selectItemWithID:tabHelper->tab_id()];
}

#pragma mark - CRWWebStateObserver

- (void)webStateDidChangeTitle:(web::WebState*)webState {
  // Assumption: the ID of the webState didn't change as a result of this load.
  TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(webState);
  NSString* itemID = tabHelper->tab_id();
  [self.consumer replaceItemID:itemID withItem:CreateItem(webState)];
}

#pragma mark - SnapshotCacheObserver

- (void)snapshotCache:(SnapshotCache*)snapshotCache
    didUpdateSnapshotForIdentifier:(NSString*)identifier {
  [self.appearanceCache removeObjectForKey:identifier];
  web::WebState* webState = GetWebStateWithId(self.webStateList, identifier);
  if (webState) {
    // It is possible to observe an updated snapshot for a WebState before
    // observing that the WebState has been added to the WebStateList. It is the
    // consumer's responsibility to ignore any updates before inserts.
    [self.consumer replaceItemID:identifier withItem:CreateItem(webState)];
  }
}

#pragma mark - GridCommands

- (void)addNewItem {
  [self insertNewItemAtIndex:self.webStateList->count()];
}

- (void)insertNewItemAtIndex:(NSUInteger)index {
  [self insertNewItemAtIndex:index withURL:GURL(kChromeUINewTabURL)];
}

- (void)moveItemWithID:(NSString*)itemID toIndex:(NSUInteger)destinationIndex {
  int sourceIndex = GetIndexOfTabWithId(self.webStateList, itemID);
  if (sourceIndex >= 0)
    self.webStateList->MoveWebStateAt(sourceIndex, destinationIndex);
}

- (void)selectItemWithID:(NSString*)itemID {
  int index = GetIndexOfTabWithId(self.webStateList, itemID);
  if (index >= 0)
    self.webStateList->ActivateWebStateAt(index);
}

- (void)closeItemWithID:(NSString*)itemID {
  int index = GetIndexOfTabWithId(self.webStateList, itemID);
  if (index >= 0)
    self.webStateList->CloseWebStateAt(index, WebStateList::CLOSE_USER_ACTION);
}

- (void)closeAllItems {
  // This is a no-op if |webStateList| is already empty.
  self.webStateList->CloseAllWebStates(WebStateList::CLOSE_USER_ACTION);
}

- (void)saveAndCloseAllItems {
  if (self.webStateList->empty())
    return;
  // Tell the cache to mark these images for deletion, rather than immediately
  // deleting them.
  DCHECK(self.browser->GetBrowserState());
  SnapshotCache* cache =
      SnapshotCacheFactory::GetForBrowserState(self.browser->GetBrowserState());
  for (int i = 0; i < self.webStateList->count(); i++) {
    web::WebState* webState = self.webStateList->GetWebStateAt(i);
    TabIdTabHelper* tabHelper = TabIdTabHelper::FromWebState(webState);
    [cache markImageWithSessionID:tabHelper->tab_id()];
  }
  self.closedSessionWindow = SerializeWebStateList(self.webStateList);
  int old_size =
      self.tabRestoreService ? self.tabRestoreService->entries().size() : 0;
  self.webStateList->CloseAllWebStates(WebStateList::CLOSE_USER_ACTION);
  self.syncedClosedTabsCount =
      self.tabRestoreService
          ? self.tabRestoreService->entries().size() - old_size
          : 0;
}

- (void)undoCloseAllItems {
  if (!self.closedSessionWindow)
    return;
  DCHECK(self.browser->GetBrowserState());
  SessionRestorationBrowserAgent::FromBrowser(self.browser)
      ->RestoreSessionWindow(self.closedSessionWindow);
  self.closedSessionWindow = nil;
  [self removeEntriesFromTabRestoreService];
  self.syncedClosedTabsCount = 0;
  // Unmark all images for deletion since they are now active tabs again.
  ChromeBrowserState* browserState = self.browser->GetBrowserState();
  [SnapshotCacheFactory::GetForBrowserState(browserState) unmarkAllImages];
}

- (void)discardSavedClosedItems {
  if (!self.closedSessionWindow)
    return;
  self.syncedClosedTabsCount = 0;
  self.closedSessionWindow = nil;
  // Delete all marked images from the cache.
  DCHECK(self.browserState);
  [SnapshotCacheFactory::GetForBrowserState(self.browserState)
      removeMarkedImages];
}

#pragma mark GridCommands helpers

- (void)insertNewItemAtIndex:(NSUInteger)index withURL:(const GURL&)newTabURL {
  // The incognito mediator's Browser is briefly set to nil after the last
  // incognito tab is closed.  This occurs because the incognito BrowserState
  // needs to be destroyed to correctly clear incognito browsing data.  Don't
  // attempt to create a new WebState with a nil BrowserState.
  if (!self.browser)
    return;

  DCHECK(self.browserState);
  web::WebState::CreateParams params(self.browserState);
  std::unique_ptr<web::WebState> webState = web::WebState::Create(params);

  web::NavigationManager::WebLoadParams loadParams(newTabURL);
  loadParams.transition_type = ui::PAGE_TRANSITION_TYPED;
  webState->GetNavigationManager()->LoadURLWithParams(loadParams);

  self.webStateList->InsertWebState(
      base::checked_cast<int>(index), std::move(webState),
      (WebStateList::INSERT_FORCE_INDEX | WebStateList::INSERT_ACTIVATE),
      WebStateOpener());
}

#pragma mark - GridDragDropHandler

- (UIDragItem*)dragItemForItemWithID:(NSString*)itemID {
  web::WebState* webState = GetWebStateWithId(self.webStateList, itemID);
  return CreateTabDragItem(webState);
}

- (UIDropOperation)dropOperationForDropSession:(id<UIDropSession>)session {
  UIDragItem* dragItem = session.localDragSession.items.firstObject;

  // Tab move operations only originate from Chrome so a local object is used.
  // Local objects allow synchronous drops, whereas NSItemProvider only allows
  // asynchronous drops.
  if ([dragItem.localObject isKindOfClass:[TabInfo class]]) {
    TabInfo* tabInfo = static_cast<TabInfo*>(dragItem.localObject);
    if (self.browserState->IsOffTheRecord() && tabInfo.incognito) {
      return UIDropOperationMove;
    }
    if (!self.browserState->IsOffTheRecord() && !tabInfo.incognito) {
      return UIDropOperationMove;
    }
    // Tabs of different profiles (regular/incognito) cannot be dropped.
    return UIDropOperationForbidden;
  }

  // All URLs originating from Chrome create a new tab (as opposed to moving a
  // tab).
  if ([dragItem.localObject isKindOfClass:[NSURL class]]) {
    return UIDropOperationCopy;
  }

  // URLs are accepted when drags originate from outside Chrome.
  NSArray<NSString*>* acceptableTypes = @[ (__bridge NSString*)kUTTypeURL ];
  if ([session hasItemsConformingToTypeIdentifiers:acceptableTypes]) {
    return UIDropOperationCopy;
  }

  // Other UTI types such as image data or file data cannot be dropped.
  return UIDropOperationForbidden;
}

- (void)dropItem:(UIDragItem*)dragItem
               toIndex:(NSUInteger)destinationIndex
    fromSameCollection:(BOOL)fromSameCollection {
  // Tab move operations only originate from Chrome so a local object is used.
  // Local objects allow synchronous drops, whereas NSItemProvider only allows
  // asynchronous drops.
  if ([dragItem.localObject isKindOfClass:[TabInfo class]]) {
    TabInfo* tabInfo = static_cast<TabInfo*>(dragItem.localObject);
    if (!fromSameCollection) {
      // Move tab across Browsers.
      MoveTabToBrowser(tabInfo.tabID, self.browser, destinationIndex);
      return;
    }
    // Reorder tab within same grid.
    int sourceIndex = GetIndexOfTabWithId(self.webStateList, tabInfo.tabID);
    if (sourceIndex >= 0)
      self.webStateList->MoveWebStateAt(sourceIndex, destinationIndex);
    return;
  }

  // Handle URLs from within Chrome synchronously using a local object.
  if ([dragItem.localObject isKindOfClass:[NSURL class]]) {
    NSURL* droppedURL = static_cast<NSURL*>(dragItem.localObject);
    [self insertNewItemAtIndex:destinationIndex
                       withURL:net::GURLWithNSURL(droppedURL)];
    return;
  }

  // Handle URLs from other apps asynchronously, as synchronous is not possible
  // with NSItemProvider.
  NSItemProvider* itemProvider = dragItem.itemProvider;
  if ([itemProvider canLoadObjectOfClass:[NSURL class]]) {
    auto loadHandler =
        ^(id<NSItemProviderReading> providedItem, NSError* error) {
          dispatch_async(dispatch_get_main_queue(), ^{
            NSURL* droppedURL = static_cast<NSURL*>(providedItem);
            [self insertNewItemAtIndex:destinationIndex
                               withURL:net::GURLWithNSURL(droppedURL)];
          });
        };
    [itemProvider loadObjectOfClass:[NSURL class]
                  completionHandler:loadHandler];
    return;
  }
}

#pragma mark - GridImageDataSource

- (void)snapshotForIdentifier:(NSString*)identifier
                   completion:(void (^)(UIImage*))completion {
  if (self.appearanceCache[identifier]) {
    completion(self.appearanceCache[identifier]);
    return;
  }
  web::WebState* webState = GetWebStateWithId(self.webStateList, identifier);
  if (webState) {
    SnapshotTabHelper::FromWebState(webState)->RetrieveColorSnapshot(
        ^(UIImage* image) {
            completion(image);
        });
  }
}

- (void)faviconForIdentifier:(NSString*)identifier
                  completion:(void (^)(UIImage*))completion {
  web::WebState* webState = GetWebStateWithId(self.webStateList, identifier);
  if (!webState) {
    return;
  }
  // NTP tabs get no favicon.
  if (IsURLNtp(webState->GetVisibleURL())) {
    return;
  }
  UIImage* defaultFavicon =
      webState->GetBrowserState()->IsOffTheRecord()
          ? [UIImage imageNamed:@"default_world_favicon_incognito"]
          : [UIImage imageNamed:@"default_world_favicon_regular"];
  completion(defaultFavicon);

  favicon::FaviconDriver* faviconDriver =
      favicon::WebFaviconDriver::FromWebState(webState);
  if (faviconDriver) {
    gfx::Image favicon = faviconDriver->GetFavicon();
    if (!favicon.IsEmpty())
      completion(favicon.ToUIImage());
  }
}

- (void)preloadSnapshotsForVisibleGridSize:(int)gridSize {
  int startIndex = std::max(self.webStateList->active_index() - gridSize, 0);
  int endIndex = std::min(self.webStateList->active_index() + gridSize,
                          self.webStateList->count() - 1);
  for (int i = startIndex; i <= endIndex; i++) {
    web::WebState* web_state = self.webStateList->GetWebStateAt(i);
    NSString* identifier = TabIdTabHelper::FromWebState(web_state)->tab_id();
    auto cacheImage = ^(UIImage* image) {
      self.appearanceCache[identifier] = image;
    };
    [self snapshotForIdentifier:identifier completion:cacheImage];
  }
}

- (void)clearPreloadedSnapshots {
  [self.appearanceCache removeAllObjects];
}

#pragma mark - Private

// Calls |-populateItems:selectedItemID:| on the consumer.
- (void)populateConsumerItems {
  if (self.webStateList->count() > 0) {
    [self.consumer populateItems:CreateItems(self.webStateList)
                  selectedItemID:GetActiveTabId(self.webStateList)];
  }
}

// Removes |self.syncedClosedTabsCount| most recent entries from the
// TabRestoreService.
- (void)removeEntriesFromTabRestoreService {
  if (!self.tabRestoreService) {
    return;
  }
  std::vector<SessionID> identifiers;
  auto iter = self.tabRestoreService->entries().begin();
  auto end = self.tabRestoreService->entries().end();
  for (int i = 0; i < self.syncedClosedTabsCount && iter != end; i++) {
    identifiers.push_back(iter->get()->id);
    iter++;
  }
  for (const SessionID sessionID : identifiers) {
    self.tabRestoreService->RemoveTabEntryById(sessionID);
  }
}

// Returns a SnapshotCache for the current BrowserState.
- (SnapshotCache*)snapshotCache {
  if (!self.browserState)
    return nil;
  return SnapshotCacheFactory::GetForBrowserState(self.browserState);
}

@end
