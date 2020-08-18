// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/extensions_manifest_types.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_EXTENSIONS_MANIFEST_TYPES_H__
#define EXTENSIONS_COMMON_API_EXTENSIONS_MANIFEST_TYPES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace extensions_manifest_types {

//
// Types
//

// This API provides programmatic access to the user interface elements of
// Chrome. This includes everything in the web view, and optionally Chrome's
// full user interface.
struct Automation {
  Automation();
  ~Automation();
  Automation(Automation&& rhs);
  Automation& operator=(Automation&& rhs);

  // Populates a Automation object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Automation* out, base::string16* error);

  // Creates a Automation object from a base::Value, or NULL on failure.
  static std::unique_ptr<Automation> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::Value representing the serialized form of this
  // Automation object.
  std::unique_ptr<base::Value> ToValue() const;
  struct Object {
    Object();
    ~Object();
    Object(Object&& rhs);
    Object& operator=(Object&& rhs);

    // Populates a Object object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Object* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Object object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // Whether to request permission to the whole ChromeOS desktop. If granted, this
    // gives the extension access to every aspect of the desktop, and every site and
    // app. If this permission is requested, all other permissions are implicitly
    // included and do not need to be requested separately.
    std::unique_ptr<bool> desktop;

    // A list of URL patterns for which this extension may request an automation
    // tree. If not specified, automation permission will be granted for the sites
    // for which the extension has a <a
    // href='https://developer.chrome.com/extensions/declare_permissions#host-permissions'>host permission</a> or <a href='https://developer.chrome.com/extensions/declare_permissions#activeTab'>activeTab permission</a>).
    std::unique_ptr<std::vector<std::string>> matches;

    // Whether the extension is allowed interactive access (true) or read-only
    // access (false; default) to the automation tree.
    std::unique_ptr<bool> interact;


   private:
    DISALLOW_COPY_AND_ASSIGN(Object);
  };


  // Choices:
  std::unique_ptr<bool> as_boolean;
  std::unique_ptr<Object> as_object;

 private:
  DISALLOW_COPY_AND_ASSIGN(Automation);
};

// The <code>content_capabilities</code> manifest entry allows an extension to
// grant certain additional capabilities to web contents whose locations match a
// given set of URL patterns.
struct ContentCapabilities {
  ContentCapabilities();
  ~ContentCapabilities();
  ContentCapabilities(ContentCapabilities&& rhs);
  ContentCapabilities& operator=(ContentCapabilities&& rhs);

  // Populates a ContentCapabilities object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, ContentCapabilities* out, base::string16* error);

  // Creates a ContentCapabilities object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ContentCapabilities> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ContentCapabilities object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The set of URL patterns to match against. If any of the given patterns match
  // a URL, its contents will be granted the specified capabilities.
  std::vector<std::string> matches;

  // The set of capabilities to grant matched contents. This is currently limited
  // to <code>clipboardRead</code>, <code>clipboardWrite</code>, and
  // <code>unlimitedStorage</code>.
  std::vector<std::string> permissions;


 private:
  DISALLOW_COPY_AND_ASSIGN(ContentCapabilities);
};

struct ExternallyConnectable {
  ExternallyConnectable();
  ~ExternallyConnectable();
  ExternallyConnectable(ExternallyConnectable&& rhs);
  ExternallyConnectable& operator=(ExternallyConnectable&& rhs);

  // Populates a ExternallyConnectable object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, ExternallyConnectable* out, base::string16* error);

  // Creates a ExternallyConnectable object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<ExternallyConnectable> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this ExternallyConnectable object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // <p>The IDs of extensions or apps that are allowed to connect. If left empty
  // or unspecified, no extensions or apps can connect.</p><p>The wildcard
  // <code>"*"</code> will allow all extensions and apps to connect.</p>
  std::unique_ptr<std::vector<std::string>> ids;

  // <p>The URL patterns for <em>web pages</em> that are allowed to connect.
  // <em>This does not affect content scripts.</em> If left empty or unspecified,
  // no web pages can connect.</p><p>Patterns cannot include wildcard domains nor
  // subdomains of <a href="http://publicsuffix.org/list/">(effective) top level
  // domains</a>; <code>*://google.com/*</code> and
  // <code>http://*.chromium.org/*</code> are valid, while
  // <code>&lt;all_urls&gt;</code>, <code>http://*/*</code>,
  // <code>*://*.com/*</code>, and even <code>http://*.appspot.com/*</code> are
  // not.</p>
  std::unique_ptr<std::vector<std::string>> matches;

  // If <code>true</code>, messages sent via $(ref:runtime.connect) or
  // $(ref:runtime.sendMessage) will set $(ref:runtime.MessageSender.tlsChannelId)
  // if those methods request it to be. If <code>false</code>,
  // $(ref:runtime.MessageSender.tlsChannelId) will never be set under any
  // circumstance.
  std::unique_ptr<bool> accepts_tls_channel_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(ExternallyConnectable);
};

// The <code>options_ui</code> manifest property declares how the options page
// should be displayed.
struct OptionsUI {
  OptionsUI();
  ~OptionsUI();
  OptionsUI(OptionsUI&& rhs);
  OptionsUI& operator=(OptionsUI&& rhs);

  // Populates a OptionsUI object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, OptionsUI* out, base::string16* error);

  // Creates a OptionsUI object from a base::Value, or NULL on failure.
  static std::unique_ptr<OptionsUI> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this OptionsUI object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The path to your options page, relative to your extension's root.
  std::string page;

  // If <code>true</code>, a Chrome user agent stylesheet will be applied to your
  // options page. The default value is <code>false</code>, but we recommend you
  // enable it for a consistent UI with Chrome.
  std::unique_ptr<bool> chrome_style;

  // <p>If <code>true</code>, your extension's options page will be opened in a
  // new tab rather than embedded in <em>chrome://extensions</em>. The default is
  // <code>false</code>, and we recommend that you don't change
  // it.</p><p><strong>This is only useful to delay the inevitable deprecation of
  // the old options UI!</strong> It will be removed soon, so try not to use it.
  // It will break.</p>
  std::unique_ptr<bool> open_in_tab;


 private:
  DISALLOW_COPY_AND_ASSIGN(OptionsUI);
};

// <p>A single string or a list of strings representing host:port patterns.</p>
struct SocketHostPatterns {
  SocketHostPatterns();
  ~SocketHostPatterns();
  SocketHostPatterns(SocketHostPatterns&& rhs);
  SocketHostPatterns& operator=(SocketHostPatterns&& rhs);

  // Populates a SocketHostPatterns object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, SocketHostPatterns* out, base::string16* error);

  // Creates a SocketHostPatterns object from a base::Value, or NULL on failure.
  static std::unique_ptr<SocketHostPatterns> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::Value representing the serialized form of this
  // SocketHostPatterns object.
  std::unique_ptr<base::Value> ToValue() const;
  // Choices:
  std::unique_ptr<std::string> as_string;
  std::unique_ptr<std::vector<std::string>> as_strings;

 private:
  DISALLOW_COPY_AND_ASSIGN(SocketHostPatterns);
};

// The <code>sockets</code> manifest property declares which sockets operations
// an app can issue.
struct Sockets {
  Sockets();
  ~Sockets();
  Sockets(Sockets&& rhs);
  Sockets& operator=(Sockets&& rhs);

  // Populates a Sockets object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Sockets* out, base::string16* error);

  // Creates a Sockets object from a base::Value, or NULL on failure.
  static std::unique_ptr<Sockets> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Sockets object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The <code>udp</code> manifest property declares which sockets.udp operations
  // an app can issue.
  struct Udp {
    Udp();
    ~Udp();
    Udp(Udp&& rhs);
    Udp& operator=(Udp&& rhs);

    // Populates a Udp object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Udp* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Udp object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // <p>The host:port pattern for <code>bind</code> operations.</p>
    std::unique_ptr<SocketHostPatterns> bind;

    // <p>The host:port pattern for <code>send</code> operations.</p>
    std::unique_ptr<SocketHostPatterns> send;

    // <p>The host:port pattern for <code>joinGroup</code> operations.</p>
    std::unique_ptr<SocketHostPatterns> multicast_membership;


   private:
    DISALLOW_COPY_AND_ASSIGN(Udp);
  };

  // The <code>tcp</code> manifest property declares which sockets.tcp operations
  // an app can issue.
  struct Tcp {
    Tcp();
    ~Tcp();
    Tcp(Tcp&& rhs);
    Tcp& operator=(Tcp&& rhs);

    // Populates a Tcp object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, Tcp* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this Tcp object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // <p>The host:port pattern for <code>connect</code> operations.</p>
    std::unique_ptr<SocketHostPatterns> connect;


   private:
    DISALLOW_COPY_AND_ASSIGN(Tcp);
  };

  // The <code>tcpServer</code> manifest property declares which sockets.tcpServer
  // operations an app can issue.
  struct TcpServer {
    TcpServer();
    ~TcpServer();
    TcpServer(TcpServer&& rhs);
    TcpServer& operator=(TcpServer&& rhs);

    // Populates a TcpServer object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, TcpServer* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this TcpServer object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // <p>The host:port pattern for <code>listen</code> operations.</p>
    std::unique_ptr<SocketHostPatterns> listen;


   private:
    DISALLOW_COPY_AND_ASSIGN(TcpServer);
  };


  // The <code>udp</code> manifest property declares which sockets.udp operations
  // an app can issue.
  std::unique_ptr<Udp> udp;

  // The <code>tcp</code> manifest property declares which sockets.tcp operations
  // an app can issue.
  std::unique_ptr<Tcp> tcp;

  // The <code>tcpServer</code> manifest property declares which sockets.tcpServer
  // operations an app can issue.
  std::unique_ptr<TcpServer> tcp_server;


 private:
  DISALLOW_COPY_AND_ASSIGN(Sockets);
};

// The <code>bluetooth</code> manifest property give permission to an app to use
// the $(ref:bluetooth) API. A list of UUIDs can be optionally specified to
// enable communication with devices.
struct Bluetooth {
  Bluetooth();
  ~Bluetooth();
  Bluetooth(Bluetooth&& rhs);
  Bluetooth& operator=(Bluetooth&& rhs);

  // Populates a Bluetooth object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Bluetooth* out, base::string16* error);

  // Creates a Bluetooth object from a base::Value, or NULL on failure.
  static std::unique_ptr<Bluetooth> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Bluetooth object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The <code>uuids</code> manifest property declares the list of protocols,
  // profiles and services that an app can communicate using.
  std::unique_ptr<std::vector<std::string>> uuids;

  // If <code>true</code>, gives permission to an app to use the
  // $(ref:bluetoothSocket) API
  std::unique_ptr<bool> socket;

  // If <code>true</code>, gives permission to an app to use the
  // $(ref:bluetoothLowEnergy) API
  std::unique_ptr<bool> low_energy;

  // If <code>true</code>, gives permission to an app to use the advertisement
  // functions in the $(ref:bluetoothLowEnergy) API
  std::unique_ptr<bool> peripheral;


 private:
  DISALLOW_COPY_AND_ASSIGN(Bluetooth);
};

// The <code>usb_printers</code> manifest property lists the USB printers
// supported by an app implementing the $(ref:printerProvider) API.
struct UsbPrinters {
  UsbPrinters();
  ~UsbPrinters();
  UsbPrinters(UsbPrinters&& rhs);
  UsbPrinters& operator=(UsbPrinters&& rhs);

  // Populates a UsbPrinters object from a base::Value. Returns whether |out|
  // was successfully populated.
  static bool Populate(const base::Value& value, UsbPrinters* out, base::string16* error);

  // Creates a UsbPrinters object from a base::Value, or NULL on failure.
  static std::unique_ptr<UsbPrinters> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this UsbPrinters object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  struct FiltersType {
    FiltersType();
    ~FiltersType();
    FiltersType(FiltersType&& rhs);
    FiltersType& operator=(FiltersType&& rhs);

    // Populates a FiltersType object from a base::Value. Returns whether |out|
    // was successfully populated.
    static bool Populate(const base::Value& value, FiltersType* out, base::string16* error);

    // Returns a new base::DictionaryValue representing the serialized form of
    // this FiltersType object.
    std::unique_ptr<base::DictionaryValue> ToValue() const;

    // USB vendor ID of matching devices
    int vendor_id;

    // USB product ID of matching devices
    std::unique_ptr<int> product_id;

    // USB interface class implemented by any interface of a matching device.
    std::unique_ptr<int> interface_class;

    // USB interface sub-class implemented by the interface matching
    // $(ref:interfaceClass).
    std::unique_ptr<int> interface_subclass;

    // USB interface protocol implemented by the interface matching
    // $(ref:interfaceClass) and $(ref:interfaceSubclass).
    std::unique_ptr<int> interface_protocol;


   private:
    DISALLOW_COPY_AND_ASSIGN(FiltersType);
  };



  // A list of $(ref:usb.DeviceFilter USB device filters) matching supported
  // devices. A device only needs to match one of the provided filters. A
  // <code>vendorId</code> is required and only one of <code>productId</code> or
  // <code>interfaceClass</code> may be provided.
  std::vector<FiltersType> filters;


 private:
  DISALLOW_COPY_AND_ASSIGN(UsbPrinters);
};

// The <code>kiosk_secondary_apps</code> manifest property lists the secondary
// kiosk apps to be deployed by the primary kiosk app.
struct KioskSecondaryAppsType {
  KioskSecondaryAppsType();
  ~KioskSecondaryAppsType();
  KioskSecondaryAppsType(KioskSecondaryAppsType&& rhs);
  KioskSecondaryAppsType& operator=(KioskSecondaryAppsType&& rhs);

  // Populates a KioskSecondaryAppsType object from a base::Value. Returns
  // whether |out| was successfully populated.
  static bool Populate(const base::Value& value, KioskSecondaryAppsType* out, base::string16* error);

  // Creates a KioskSecondaryAppsType object from a base::Value, or NULL on
  // failure.
  static std::unique_ptr<KioskSecondaryAppsType> FromValue(const base::Value& value, base::string16* error);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this KioskSecondaryAppsType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // ID of secondary kiosk app
  std::string id;

  // Whether the secondary app should be enabled when kiosk app is launched. If
  // true, the app will be enabled before the kiosk app launch; if false the app
  // will be disabled before the kiosk app launch; if not set, the app's enabled
  // state will not be changed during the kiosk app launch. The ${ref:management}
  // API can be used to later change the secondary app state.
  std::unique_ptr<bool> enabled_on_launch;


 private:
  DISALLOW_COPY_AND_ASSIGN(KioskSecondaryAppsType);
};

typedef std::vector<KioskSecondaryAppsType > KioskSecondaryApps;


}  // namespace extensions_manifest_types
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_EXTENSIONS_MANIFEST_TYPES_H__
