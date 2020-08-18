// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_STORAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_STORAGE_H_

#include "base/callback.h"
#include "base/observer_list.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/domains/types_dom_storage.h"
#include "headless/public/headless_export.h"
#include "headless/public/internal/message_dispatcher.h"


namespace headless {
namespace dom_storage {
class HEADLESS_EXPORT ExperimentalDomain;
class HEADLESS_EXPORT ExperimentalObserver;

class HEADLESS_EXPORT ExperimentalObserver {
 public:
  virtual ~ExperimentalObserver() {}
  virtual void OnDomStorageItemAdded(const DomStorageItemAddedParams& params) {}
  virtual void OnDomStorageItemRemoved(const DomStorageItemRemovedParams& params) {}
  virtual void OnDomStorageItemUpdated(const DomStorageItemUpdatedParams& params) {}
  virtual void OnDomStorageItemsCleared(const DomStorageItemsClearedParams& params) {}
};

class HEADLESS_EXPORT Observer : public ExperimentalObserver {
 public:
  virtual ~Observer() {}
  virtual void OnDomStorageItemAdded(const DomStorageItemAddedParams& params) final {}
  virtual void OnDomStorageItemRemoved(const DomStorageItemRemovedParams& params) final {}
  virtual void OnDomStorageItemUpdated(const DomStorageItemUpdatedParams& params) final {}
  virtual void OnDomStorageItemsCleared(const DomStorageItemsClearedParams& params) final {}
};

// Query and modify DOM storage.
class HEADLESS_EXPORT Domain {
 public:
  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(Observer* observer);
  void RemoveObserver(Observer* observer);

  // Return the experimental interface for this domain. Note that experimental
  // commands may be changed or removed at any time.
  ExperimentalDomain* GetExperimental();

 protected:
  Domain(internal::MessageDispatcher* dispatcher);
  ~Domain();

  static void HandleClearResponse(base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback, const base::Value& response);
  static void HandleDisableResponse(base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback, const base::Value& response);
  static void HandleEnableResponse(base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback, const base::Value& response);
  static void HandleGetDOMStorageItemsResponse(base::OnceCallback<void(std::unique_ptr<GetDOMStorageItemsResult>)> callback, const base::Value& response);
  static void HandleRemoveDOMStorageItemResponse(base::OnceCallback<void(std::unique_ptr<RemoveDOMStorageItemResult>)> callback, const base::Value& response);
  static void HandleSetDOMStorageItemResponse(base::OnceCallback<void(std::unique_ptr<SetDOMStorageItemResult>)> callback, const base::Value& response);

  void DispatchDomStorageItemAddedEvent(const base::Value& params);
  void DispatchDomStorageItemRemovedEvent(const base::Value& params);
  void DispatchDomStorageItemUpdatedEvent(const base::Value& params);
  void DispatchDomStorageItemsClearedEvent(const base::Value& params);

  internal::MessageDispatcher* dispatcher_;  // Not owned.
  base::ObserverList<ExperimentalObserver>::Unchecked observers_;

 protected:
  void RegisterEventHandlersIfNeeded();

 private:
  bool event_handlers_registered_ = false;

  DISALLOW_COPY_AND_ASSIGN(Domain);
};

class ExperimentalDomain : public Domain {
 public:
  ExperimentalDomain(internal::MessageDispatcher* dispatcher);
  ~ExperimentalDomain();

  // Add or remove an observer. |observer| must be removed before being
  // destroyed.
  void AddObserver(ExperimentalObserver* observer);
  void RemoveObserver(ExperimentalObserver* observer);

  void Clear(std::unique_ptr<ClearParams> params, base::OnceCallback<void(std::unique_ptr<ClearResult>)> callback = base::OnceCallback<void(std::unique_ptr<ClearResult>)>());

  // Disables storage tracking, prevents storage events from being sent to the client.
  void Disable(std::unique_ptr<DisableParams> params, base::OnceCallback<void(std::unique_ptr<DisableResult>)> callback = base::OnceCallback<void(std::unique_ptr<DisableResult>)>());

  // Enables storage tracking, storage events will now be delivered to the client.
  void Enable(std::unique_ptr<EnableParams> params, base::OnceCallback<void(std::unique_ptr<EnableResult>)> callback = base::OnceCallback<void(std::unique_ptr<EnableResult>)>());

  void GetDOMStorageItems(std::unique_ptr<GetDOMStorageItemsParams> params, base::OnceCallback<void(std::unique_ptr<GetDOMStorageItemsResult>)> callback = base::OnceCallback<void(std::unique_ptr<GetDOMStorageItemsResult>)>());

  void RemoveDOMStorageItem(std::unique_ptr<RemoveDOMStorageItemParams> params, base::OnceCallback<void(std::unique_ptr<RemoveDOMStorageItemResult>)> callback = base::OnceCallback<void(std::unique_ptr<RemoveDOMStorageItemResult>)>());

  void SetDOMStorageItem(std::unique_ptr<SetDOMStorageItemParams> params, base::OnceCallback<void(std::unique_ptr<SetDOMStorageItemResult>)> callback = base::OnceCallback<void(std::unique_ptr<SetDOMStorageItemResult>)>());


 private:
  DISALLOW_COPY_AND_ASSIGN(ExperimentalDomain);
};

}  // namespace dom_storage
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_DOM_STORAGE_H_
