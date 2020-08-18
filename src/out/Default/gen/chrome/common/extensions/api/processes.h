// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   chrome/common/extensions/api/processes.idl
// DO NOT EDIT.

#ifndef CHROME_COMMON_EXTENSIONS_API_PROCESSES_H__
#define CHROME_COMMON_EXTENSIONS_API_PROCESSES_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace processes {

//
// Types
//

// The types of the browser processes.
enum ProcessType {
  PROCESS_TYPE_NONE,
  PROCESS_TYPE_BROWSER,
  PROCESS_TYPE_RENDERER,
  PROCESS_TYPE_EXTENSION,
  PROCESS_TYPE_NOTIFICATION,
  PROCESS_TYPE_PLUGIN,
  PROCESS_TYPE_WORKER,
  PROCESS_TYPE_NACL,
  PROCESS_TYPE_SERVICE_WORKER,
  PROCESS_TYPE_UTILITY,
  PROCESS_TYPE_GPU,
  PROCESS_TYPE_OTHER,
  PROCESS_TYPE_LAST = PROCESS_TYPE_OTHER,
};


const char* ToString(ProcessType as_enum);
ProcessType ParseProcessType(const std::string& as_string);

struct TaskInfo {
  TaskInfo();
  ~TaskInfo();
  TaskInfo(TaskInfo&& rhs);
  TaskInfo& operator=(TaskInfo&& rhs);

  // Populates a TaskInfo object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, TaskInfo* out);

  // Creates a TaskInfo object from a base::Value, or NULL on failure.
  static std::unique_ptr<TaskInfo> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this TaskInfo object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The title of the task.
  std::string title;

  // Optional tab ID, if this task represents a tab running on a renderer process.
  std::unique_ptr<int> tab_id;


 private:
  DISALLOW_COPY_AND_ASSIGN(TaskInfo);
};

struct Cache {
  Cache();
  ~Cache();
  Cache(Cache&& rhs);
  Cache& operator=(Cache&& rhs);

  // Populates a Cache object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Cache* out);

  // Creates a Cache object from a base::Value, or NULL on failure.
  static std::unique_ptr<Cache> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Cache object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // The size of the cache, in bytes.
  double size;

  // The part of the cache that is utilized, in bytes.
  double live_size;


 private:
  DISALLOW_COPY_AND_ASSIGN(Cache);
};

struct Process {
  Process();
  ~Process();
  Process(Process&& rhs);
  Process& operator=(Process&& rhs);

  // Populates a Process object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Process* out);

  // Creates a Process object from a base::Value, or NULL on failure.
  static std::unique_ptr<Process> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Process object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Unique ID of the process provided by the browser.
  int id;

  // The ID of the process, as provided by the OS.
  int os_process_id;

  // The type of process.
  ProcessType type;

  // The profile which the process is associated with.
  std::string profile;

  // The debugging port for Native Client processes. Zero for other process types
  // and for NaCl processes that do not have debugging enabled.
  int nacl_debug_port;

  // Array of TaskInfos representing the tasks running on this process.
  std::vector<TaskInfo> tasks;

  // The most recent measurement of the process’s CPU usage, expressed as the
  // percentage of a single CPU core used in total, by all of the process’s
  // threads. This gives a value from zero to CpuInfo.numOfProcessors*100, which
  // can exceed 100% in multi-threaded processes. Only available when receiving
  // the object as part of a callback from onUpdated or onUpdatedWithMemory.
  std::unique_ptr<double> cpu;

  // The most recent measurement of the process network usage, in bytes per
  // second. Only available when receiving the object as part of a callback from
  // onUpdated or onUpdatedWithMemory.
  std::unique_ptr<double> network;

  // The most recent measurement of the process private memory usage, in bytes.
  // Only available when receiving the object as part of a callback from
  // onUpdatedWithMemory or getProcessInfo with the includeMemory flag.
  std::unique_ptr<double> private_memory;

  // The most recent measurement of the process JavaScript allocated memory, in
  // bytes. Only available when receiving the object as part of a callback from
  // onUpdated or onUpdatedWithMemory.
  std::unique_ptr<double> js_memory_allocated;

  // The most recent measurement of the process JavaScript memory used, in bytes.
  // Only available when receiving the object as part of a callback from onUpdated
  // or onUpdatedWithMemory.
  std::unique_ptr<double> js_memory_used;

  // The most recent measurement of the process’s SQLite memory usage, in bytes.
  // Only available when receiving the object as part of a callback from onUpdated
  // or onUpdatedWithMemory.
  std::unique_ptr<double> sqlite_memory;

  // The most recent information about the image cache for the process. Only
  // available when receiving the object as part of a callback from onUpdated or
  // onUpdatedWithMemory.
  std::unique_ptr<Cache> image_cache;

  // The most recent information about the script cache for the process. Only
  // available when receiving the object as part of a callback from onUpdated or
  // onUpdatedWithMemory.
  std::unique_ptr<Cache> script_cache;

  // The most recent information about the CSS cache for the process. Only
  // available when receiving the object as part of a callback from onUpdated or
  // onUpdatedWithMemory.
  std::unique_ptr<Cache> css_cache;


 private:
  DISALLOW_COPY_AND_ASSIGN(Process);
};


//
// Functions
//

namespace GetProcessIdForTab {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the tab for which the renderer process ID is to be returned.
  int tab_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// Process ID of the tab's renderer process.
std::unique_ptr<base::ListValue> Create(int process_id);
}  // namespace Results

}  // namespace GetProcessIdForTab

namespace Terminate {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The ID of the process to be terminated.
  int process_id;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// True if terminating the process was successful, and false otherwise.
std::unique_ptr<base::ListValue> Create(bool did_terminate);
}  // namespace Results

}  // namespace Terminate

namespace GetProcessInfo {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // The list of process IDs or single process ID for which to return the process
  // information. An empty list indicates all processes are requested.
  struct ProcessIds {
    ProcessIds();
    ~ProcessIds();
    ProcessIds(ProcessIds&& rhs);
    ProcessIds& operator=(ProcessIds&& rhs);

    // Populates a ProcessIds object from a base::Value. Returns whether |out| was
    // successfully populated.
    static bool Populate(const base::Value& value, ProcessIds* out);
    // Choices:
    std::unique_ptr<int> as_integer;
    std::unique_ptr<std::vector<int>> as_integers;

   private:
    DISALLOW_COPY_AND_ASSIGN(ProcessIds);
  };


  // The list of process IDs or single process ID for which to return the process
  // information. An empty list indicates all processes are requested.
  ProcessIds process_ids;

  // True if detailed memory usage is required. Note, collecting memory usage
  // information incurs extra CPU usage and should only be queried for when
  // needed.
  bool include_memory;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

// A dictionary of $(ref:Process) objects for each requested process that is a
// live child process of the current browser process, indexed by process ID.
// Metrics requiring aggregation over time will not be populated in each Process
// object.
struct Processes {
  Processes();
  ~Processes();
  Processes(Processes&& rhs);
  Processes& operator=(Processes&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Processes object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Processes);
};


// A dictionary of $(ref:Process) objects for each requested process that is a
// live child process of the current browser process, indexed by process ID.
// Metrics requiring aggregation over time will not be populated in each Process
// object.
std::unique_ptr<base::ListValue> Create(const Processes& processes);
}  // namespace Results

}  // namespace GetProcessInfo

//
// Events
//

namespace OnUpdated {

extern const char kEventName[];  // "processes.onUpdated"

// A dictionary of updated $(ref:Process) objects for each live process in the
// browser, indexed by process ID.  Metrics requiring aggregation over time will
// be populated in each Process object.
struct Processes {
  Processes();
  ~Processes();
  Processes(Processes&& rhs);
  Processes& operator=(Processes&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Processes object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Processes);
};


// A dictionary of updated $(ref:Process) objects for each live process in the
// browser, indexed by process ID.  Metrics requiring aggregation over time will
// be populated in each Process object.
std::unique_ptr<base::ListValue> Create(const Processes& processes);
}  // namespace OnUpdated

namespace OnUpdatedWithMemory {

extern const char kEventName[];  // "processes.onUpdatedWithMemory"

// A dictionary of updated $(ref:Process) objects for each live process in the
// browser, indexed by process ID.  Memory usage details will be included in
// each Process object.
struct Processes {
  Processes();
  ~Processes();
  Processes(Processes&& rhs);
  Processes& operator=(Processes&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Processes object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  base::DictionaryValue additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Processes);
};


// A dictionary of updated $(ref:Process) objects for each live process in the
// browser, indexed by process ID.  Memory usage details will be included in
// each Process object.
std::unique_ptr<base::ListValue> Create(const Processes& processes);
}  // namespace OnUpdatedWithMemory

namespace OnCreated {

extern const char kEventName[];  // "processes.onCreated"

// Details of the process that was created. Metrics requiring aggregation over
// time will not be populated in the object.
std::unique_ptr<base::ListValue> Create(const Process& process);
}  // namespace OnCreated

namespace OnUnresponsive {

extern const char kEventName[];  // "processes.onUnresponsive"

// Details of the unresponsive process. Metrics requiring aggregation over time
// will not be populated in the object. Only available for renderer processes.
std::unique_ptr<base::ListValue> Create(const Process& process);
}  // namespace OnUnresponsive

namespace OnExited {

extern const char kEventName[];  // "processes.onExited"

// The ID of the process that exited.
// The type of exit that occurred for the process - normal, abnormal, killed,
// crashed. Only available for renderer processes.
// The exit code if the process exited abnormally. Only available for renderer
// processes.
std::unique_ptr<base::ListValue> Create(int process_id, int exit_type, int exit_code);
}  // namespace OnExited

}  // namespace processes
}  // namespace api
}  // namespace extensions
#endif  // CHROME_COMMON_EXTENSIONS_API_PROCESSES_H__
