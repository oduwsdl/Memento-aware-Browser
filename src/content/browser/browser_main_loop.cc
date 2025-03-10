// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/browser_main_loop.h"

#include <stddef.h>

#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "base/base_switches.h"
#include "base/bind.h"
#include "base/command_line.h"
#include "base/deferred_sequenced_task_runner.h"
#include "base/feature_list.h"
#include "base/location.h"
#include "base/logging.h"
#include "base/memory/memory_pressure_monitor.h"
#include "base/memory/ptr_util.h"
#include "base/message_loop/message_loop_current.h"
#include "base/metrics/field_trial.h"
#include "base/metrics/histogram_macros.h"
#include "base/metrics/user_metrics.h"
#include "base/no_destructor.h"
#include "base/path_service.h"
#include "base/pending_task.h"
#include "base/power_monitor/power_monitor.h"
#include "base/power_monitor/power_monitor_device_source.h"
#include "base/process/process_metrics.h"
#include "base/run_loop.h"
#include "base/scoped_observer.h"
#include "base/single_thread_task_runner.h"
#include "base/stl_util.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_split.h"
#include "base/synchronization/waitable_event.h"
#include "base/system/system_monitor.h"
#include "base/task/thread_pool/initialization_util.h"
#include "base/threading/thread.h"
#include "base/threading/thread_restrictions.h"
#include "base/threading/thread_task_runner_handle.h"
#include "base/time/time.h"
#include "base/timer/hi_res_timer_manager.h"
#include "base/trace_event/memory_dump_manager.h"
#include "base/trace_event/trace_event.h"
#include "base/util/memory_pressure/multi_source_memory_pressure_monitor.h"
#include "build/branding_buildflags.h"
#include "build/build_config.h"
#include "cc/base/histograms.h"
#include "components/discardable_memory/service/discardable_shared_memory_manager.h"
#include "components/services/storage/dom_storage/storage_area_impl.h"
#include "components/tracing/common/trace_startup_config.h"
#include "components/tracing/common/trace_to_console.h"
#include "components/tracing/common/tracing_switches.h"
#include "components/viz/host/compositing_mode_reporter_impl.h"
#include "components/viz/host/gpu_host_impl.h"
#include "components/viz/host/host_frame_sink_manager.h"
#include "content/browser/browser_thread_impl.h"
#include "content/browser/child_process_security_policy_impl.h"
#include "content/browser/compositor/viz_process_transport_factory.h"
#include "content/browser/download/save_file_manager.h"
#include "content/browser/field_trial_synchronizer.h"
#include "content/browser/gpu/browser_gpu_channel_host_factory.h"
#include "content/browser/gpu/browser_gpu_client_delegate.h"
#include "content/browser/gpu/compositor_util.h"
#include "content/browser/gpu/gpu_data_manager_impl.h"
#include "content/browser/gpu/gpu_process_host.h"
#include "content/browser/gpu/shader_cache_factory.h"
#include "content/browser/histogram_synchronizer.h"
#include "content/browser/media/capture/audio_mirroring_manager.h"
#include "content/browser/media/media_internals.h"
#include "content/browser/media/media_keys_listener_manager_impl.h"
#include "content/browser/net/browser_online_state_observer.h"
#include "content/browser/network_service_instance_impl.h"
#include "content/browser/renderer_host/media/media_stream_manager.h"
#include "content/browser/renderer_host/render_process_host_impl.h"
#include "content/browser/scheduler/browser_task_executor.h"
#include "content/browser/scheduler/responsiveness/watcher.h"
#include "content/browser/screenlock_monitor/screenlock_monitor.h"
#include "content/browser/screenlock_monitor/screenlock_monitor_device_source.h"
#include "content/browser/sms/sms_provider.h"
#include "content/browser/speech/speech_recognition_manager_impl.h"
#include "content/browser/startup_data_impl.h"
#include "content/browser/startup_task_runner.h"
#include "content/browser/tracing/background_tracing_manager_impl.h"
#include "content/browser/tracing/tracing_controller_impl.h"
#include "content/browser/utility_process_host.h"
#include "content/browser/webrtc/webrtc_internals.h"
#include "content/browser/webui/content_web_ui_controller_factory.h"
#include "content/browser/webui/url_data_manager.h"
#include "content/common/content_switches_internal.h"
#include "content/common/thread_pool_util.h"
#include "content/public/browser/audio_service.h"
#include "content/public/browser/browser_main_parts.h"
#include "content/public/browser/browser_task_traits.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/content_browser_client.h"
#include "content/public/browser/device_service.h"
#include "content/public/browser/gpu_data_manager_observer.h"
#include "content/public/browser/network_service_instance.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/browser/service_process_host.h"
#include "content/public/browser/site_isolation_policy.h"
#include "content/public/common/content_client.h"
#include "content/public/common/content_features.h"
#include "content/public/common/content_switches.h"
#include "content/public/common/main_function_params.h"
#include "content/public/common/result_codes.h"
#include "content/public/common/service_names.mojom.h"
#include "device/fido/hid/fido_hid_discovery.h"
#include "device/gamepad/gamepad_service.h"
#include "media/audio/audio_manager.h"
#include "media/audio/audio_system.h"
#include "media/audio/audio_thread_impl.h"
#include "media/base/media.h"
#include "media/base/user_input_monitor.h"
#include "media/media_buildflags.h"
#include "media/midi/midi_service.h"
#include "media/mojo/buildflags.h"
#include "mojo/core/embedder/embedder.h"
#include "mojo/core/embedder/scoped_ipc_support.h"
#include "mojo/public/cpp/bindings/mojo_buildflags.h"
#include "mojo/public/cpp/bindings/sync_call_restrictions.h"
#include "net/base/network_change_notifier.h"
#include "net/socket/client_socket_factory.h"
#include "net/ssl/ssl_config_service.h"
#include "ppapi/buildflags/buildflags.h"
#include "services/audio/service.h"
#include "services/content/public/cpp/navigable_contents_view.h"
#include "services/data_decoder/public/cpp/service_provider.h"
#include "services/network/transitional_url_loader_factory_owner.h"
#include "services/service_manager/zygote/common/zygote_buildflags.h"
#include "skia/ext/event_tracer_impl.h"
#include "skia/ext/skia_memory_dump_provider.h"
#include "sql/sql_memory_dump_provider.h"
#include "ui/base/clipboard/clipboard.h"
#include "ui/display/display_features.h"
#include "ui/gfx/font_render_params.h"
#include "ui/gfx/switches.h"

#if defined(USE_AURA) || defined(OS_MACOSX)
#include "content/browser/compositor/image_transport_factory.h"
#endif

#if defined(USE_AURA)
#include "content/public/browser/context_factory.h"
#include "ui/aura/env.h"
#endif

#if defined(OS_ANDROID)
#include "base/android/jni_android.h"
#include "base/trace_event/cpufreq_monitor_android.h"
#include "components/tracing/common/graphics_memory_dump_provider_android.h"
#include "content/browser/android/browser_startup_controller.h"
#include "content/browser/android/launcher_thread.h"
#include "content/browser/android/scoped_surface_request_manager.h"
#include "content/browser/android/tracing_controller_android.h"
#include "content/browser/font_unique_name_lookup/font_unique_name_lookup.h"
#include "content/browser/screen_orientation/screen_orientation_delegate_android.h"
#include "media/base/android/media_drm_bridge_client.h"
#include "ui/android/screen_android.h"
#include "ui/display/screen.h"
#include "ui/gl/gl_surface.h"
#endif

#if defined(OS_MACOSX)
#include "content/browser/renderer_host/browser_compositor_view_mac.h"
#include "content/browser/theme_helper_mac.h"
#include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
#endif

#if defined(OS_WIN)
#include <commctrl.h>
#include <shellapi.h>
#include <windows.h>

#include "content/browser/renderer_host/dwrite_font_lookup_table_builder_win.h"
#include "net/base/winsock_init.h"
#include "services/service_manager/sandbox/win/sandbox_win.h"
#endif

#if defined(OS_CHROMEOS)
#include "chromeos/constants/chromeos_switches.h"
#include "device/bluetooth/bluetooth_adapter_factory.h"
#include "services/data_decoder/public/cpp/data_decoder.h"
#endif

#if defined(USE_GLIB)
#include <glib-object.h>
#endif

#if defined(OS_WIN)
#include "media/device_monitors/system_message_window_win.h"
#include "sandbox/win/src/process_mitigations.h"
#elif defined(OS_LINUX) && defined(USE_UDEV)
#include "media/device_monitors/device_monitor_udev.h"
#elif defined(OS_MACOSX)
#include "media/device_monitors/device_monitor_mac.h"
#endif

#if defined(OS_FUCHSIA)
#include <lib/zx/job.h>

#include "base/fuchsia/default_job.h"
#include "base/fuchsia/fuchsia_logging.h"
#endif  // defined(OS_FUCHSIA)

#if defined(OS_POSIX) && !defined(OS_MACOSX)
#include "content/browser/sandbox_host_linux.h"
#endif

#if BUILDFLAG(ENABLE_PLUGINS)
#include "content/browser/plugin_service_impl.h"
#endif

#if BUILDFLAG(ENABLE_LIBRARY_CDMS)
#include "content/browser/media/cdm_registry_impl.h"
#endif

#if defined(USE_X11)
#include "gpu/config/gpu_driver_bug_workaround_type.h"
#include "ui/base/x/x11_util_internal.h"  // nogncheck
#include "ui/gfx/x/x11_types.h"           // nogncheck
#endif

#if defined(USE_NSS_CERTS)
#include "crypto/nss_util.h"
#endif

#if defined(ENABLE_IPC_FUZZER) && defined(OS_MACOSX)
#include "base/mac/foundation_util.h"
#endif

#if BUILDFLAG(MOJO_RANDOM_DELAYS_ENABLED)
#include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
#endif

// One of the linux specific headers defines this as a macro.
#ifdef DestroyAll
#undef DestroyAll
#endif

namespace content {
namespace {

#if defined(USE_GLIB)
static void GLibLogHandler(const gchar* log_domain,
                           GLogLevelFlags log_level,
                           const gchar* message,
                           gpointer userdata) {
  if (!log_domain)
    log_domain = "<unknown>";
  if (!message)
    message = "<no message>";

  GLogLevelFlags always_fatal_flags = g_log_set_always_fatal(G_LOG_LEVEL_MASK);
  g_log_set_always_fatal(always_fatal_flags);
  GLogLevelFlags fatal_flags =
      g_log_set_fatal_mask(log_domain, G_LOG_LEVEL_MASK);
  g_log_set_fatal_mask(log_domain, fatal_flags);
  if ((always_fatal_flags | fatal_flags) & log_level) {
    LOG(DFATAL) << log_domain << ": " << message;
  } else if (log_level & (G_LOG_LEVEL_ERROR | G_LOG_LEVEL_CRITICAL)) {
    LOG(ERROR) << log_domain << ": " << message;
  } else if (log_level & (G_LOG_LEVEL_WARNING)) {
    LOG(WARNING) << log_domain << ": " << message;
  } else if (log_level &
             (G_LOG_LEVEL_MESSAGE | G_LOG_LEVEL_INFO | G_LOG_LEVEL_DEBUG)) {
    LOG(INFO) << log_domain << ": " << message;
  } else {
    NOTREACHED();
    LOG(DFATAL) << log_domain << ": " << message;
  }
}

static void SetUpGLibLogHandler() {
  // Register GLib-handled assertions to go through our logging system.
  const char* const kLogDomains[] = {nullptr, "Gtk", "Gdk", "GLib",
                                     "GLib-GObject"};
  for (size_t i = 0; i < base::size(kLogDomains); i++) {
    g_log_set_handler(
        kLogDomains[i],
        static_cast<GLogLevelFlags>(G_LOG_FLAG_RECURSION | G_LOG_FLAG_FATAL |
                                    G_LOG_LEVEL_ERROR | G_LOG_LEVEL_CRITICAL |
                                    G_LOG_LEVEL_WARNING),
        GLibLogHandler, nullptr);
  }
}
#endif  // defined(USE_GLIB)

// NOINLINE so it's possible to tell what thread was unresponsive by inspecting
// the callstack.
NOINLINE void ResetThread_IO(
    std::unique_ptr<BrowserProcessSubThread> io_thread) {
  io_thread.reset();
}

enum WorkerPoolType : size_t {
  BACKGROUND = 0,
  BACKGROUND_BLOCKING,
  FOREGROUND,
  FOREGROUND_BLOCKING,
  WORKER_POOL_COUNT  // Always last.
};

#if defined(OS_FUCHSIA)
// Create and register the job which will contain all child processes
// of the browser process as well as their descendents.
void InitDefaultJob() {
  zx::job job;
  zx_status_t result = zx::job::create(*zx::job::default_job(), 0, &job);
  ZX_CHECK(ZX_OK == result, result) << "zx_job_create";
  base::SetDefaultJob(std::move(job));
}
#endif  // defined(OS_FUCHSIA)

#if defined(ENABLE_IPC_FUZZER)
bool GetBuildDirectory(base::FilePath* result) {
  if (!base::PathService::Get(base::DIR_EXE, result))
    return false;

#if defined(OS_MACOSX)
  if (base::mac::AmIBundled()) {
    // The bundled app executables (Chromium, TestShell, etc) live three
    // levels down from the build directory, eg:
    // Chromium.app/Contents/MacOS/Chromium
    *result = result->DirName().DirName().DirName();
  }
#endif
  return true;
}

void SetFileUrlPathAliasForIpcFuzzer() {
  if (base::CommandLine::ForCurrentProcess()->HasSwitch(
          switches::kFileUrlPathAlias))
    return;

  base::FilePath build_directory;
  if (!GetBuildDirectory(&build_directory)) {
    LOG(ERROR) << "Failed to get build directory for /gen path alias.";
    return;
  }

  const base::CommandLine::StringType alias_switch =
      FILE_PATH_LITERAL("/gen=") + build_directory.AppendASCII("gen").value();
  base::CommandLine::ForCurrentProcess()->AppendSwitchNative(
      switches::kFileUrlPathAlias, alias_switch);
}
#endif

std::unique_ptr<base::MemoryPressureMonitor> CreateMemoryPressureMonitor(
    const base::CommandLine& command_line) {
  // Behavior of browser tests should not depend on things outside of their
  // control (like the amount of memory on the system running the tests).
  if (command_line.HasSwitch(switches::kBrowserTest))
    return nullptr;

  std::unique_ptr<util::MultiSourceMemoryPressureMonitor> monitor;

#if defined(OS_CHROMEOS)
  if (chromeos::switches::MemoryPressureHandlingEnabled())
    monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_FUCHSIA)
  monitor = std::make_unique<util::MultiSourceMemoryPressureMonitor>();
#endif
  // No memory monitor on other platforms...

  if (monitor)
    monitor->Start();

  return monitor;
}

#if defined(OS_CHROMEOS)
mojo::PendingRemote<data_decoder::mojom::BleScanParser> GetBleScanParser() {
  static base::NoDestructor<data_decoder::DataDecoder> decoder;
  mojo::PendingRemote<data_decoder::mojom::BleScanParser> ble_scan_parser;
  decoder->GetService()->BindBleScanParser(
      ble_scan_parser.InitWithNewPipeAndPassReceiver());
  return ble_scan_parser;
}
#endif  // defined(OS_CHROMEOS)

#if defined(OS_WIN)
// Disable dynamic code using ACG. Prevents the browser process from generating
// dynamic code or modifying executable code. See comments in
// sandbox/win/src/security_level.h. Only available on Windows 10 RS1 (1607,
// Build 14393) onwards.
const base::Feature kBrowserDynamicCodeDisabled{
    "BrowserDynamicCodeDisabled", base::FEATURE_DISABLED_BY_DEFAULT};
#endif  // defined(OS_WIN)

class OopDataDecoder : public data_decoder::ServiceProvider {
 public:
  OopDataDecoder() { data_decoder::ServiceProvider::Set(this); }
  ~OopDataDecoder() override { data_decoder::ServiceProvider::Set(nullptr); }

  // data_decoder::ServiceProvider implementation:
  void BindDataDecoderService(
      mojo::PendingReceiver<data_decoder::mojom::DataDecoderService> receiver)
      override {
    ServiceProcessHost::Launch(
        std::move(receiver),
        ServiceProcessHost::Options()
            .WithDisplayName("Data Decoder Service")
            .Pass());
  }

 private:
  DISALLOW_COPY_AND_ASSIGN(OopDataDecoder);
};

void BindHidManager(mojo::PendingReceiver<device::mojom::HidManager> receiver) {
#if !defined(OS_ANDROID)
  if (!BrowserThread::CurrentlyOn(BrowserThread::UI)) {
    GetUIThreadTaskRunner({})->PostTask(
        FROM_HERE, base::BindOnce(&BindHidManager, std::move(receiver)));
    return;
  }

  GetDeviceService().BindHidManager(std::move(receiver));
#endif
}

}  // namespace

#if defined(USE_X11)
namespace internal {

// Forwards GPUInfo updates to ui::XVisualManager
class GpuDataManagerVisualProxy : public GpuDataManagerObserver {
 public:
  explicit GpuDataManagerVisualProxy(GpuDataManagerImpl* gpu_data_manager)
      : gpu_data_manager_(gpu_data_manager) {
    if (!base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kHeadless))
      scoped_observer_.Add(gpu_data_manager_);
  }

  ~GpuDataManagerVisualProxy() override = default;

  void OnGpuInfoUpdate() override { OnUpdate(); }
  void OnGpuExtraInfoUpdate() override { OnUpdate(); }

 private:
  void OnUpdate() {
    gpu::GPUInfo gpu_info = gpu_data_manager_->GetGPUInfo();
    gpu::GpuExtraInfo gpu_extra_info = gpu_data_manager_->GetGpuExtraInfo();
    if (!ui::XVisualManager::GetInstance()->OnGPUInfoChanged(
            gpu_info.software_rendering ||
                !gpu_data_manager_->GpuAccessAllowed(nullptr),
            gpu_extra_info.system_visual, gpu_extra_info.rgba_visual)) {
      // The GPU process sent back bad visuals, which should never happen.
      auto* gpu_process_host =
          GpuProcessHost::Get(GPU_PROCESS_KIND_SANDBOXED, false);
      if (gpu_process_host)
        gpu_process_host->ForceShutdown();
    }
  }

  GpuDataManagerImpl* gpu_data_manager_;

  ScopedObserver<GpuDataManagerImpl, GpuDataManagerObserver> scoped_observer_{
      this};

  DISALLOW_COPY_AND_ASSIGN(GpuDataManagerVisualProxy);
};

}  // namespace internal
#endif

// The currently-running BrowserMainLoop.  There can be one or zero.
BrowserMainLoop* g_current_browser_main_loop = nullptr;

#if defined(OS_ANDROID)

namespace {
// Whether or not BrowserMainLoop::CreateStartupTasks() posts any tasks.
bool g_post_startup_tasks = true;
}  // namespace

// static
void BrowserMainLoop::EnableStartupTasks(bool enabled) {
  g_post_startup_tasks = enabled;
}

#endif

// BrowserMainLoop construction / destruction =============================

BrowserMainLoop* BrowserMainLoop::GetInstance() {
  DCHECK_CURRENTLY_ON(BrowserThread::UI);
  return g_current_browser_main_loop;
}

// static
media::AudioManager* BrowserMainLoop::GetAudioManager() {
  return g_current_browser_main_loop->audio_manager();
}

BrowserMainLoop::BrowserMainLoop(
    const MainFunctionParams& parameters,
    std::unique_ptr<base::ThreadPoolInstance::ScopedExecutionFence>
        scoped_execution_fence)
    : parameters_(parameters),
      parsed_command_line_(parameters.command_line),
      result_code_(service_manager::RESULT_CODE_NORMAL_EXIT),
      created_threads_(false),
      scoped_execution_fence_(std::move(scoped_execution_fence))
#if !defined(OS_ANDROID)
      ,
      // TODO(fdoray): Create the fence on Android too. Not enabled yet because
      // tests timeout. https://crbug.com/887407
      scoped_best_effort_execution_fence_(base::in_place_t())
#endif
{
  DCHECK(!g_current_browser_main_loop);
  DCHECK(scoped_execution_fence_)
      << "ThreadPool must be halted before kicking off content.";
  g_current_browser_main_loop = this;

  if (GetContentClient()->browser()->ShouldCreateThreadPool()) {
    DCHECK(base::ThreadPoolInstance::Get());
  }
}

BrowserMainLoop::~BrowserMainLoop() {
  DCHECK_EQ(this, g_current_browser_main_loop);
  ui::Clipboard::DestroyClipboardForCurrentThread();
  g_current_browser_main_loop = nullptr;
}

void BrowserMainLoop::Init() {
  TRACE_EVENT0("startup", "BrowserMainLoop::Init");

  // |startup_data| is optional. If set, the thread owned by the data
  // will be registered as BrowserThread::IO in CreateThreads() instead of
  // creating a brand new thread.
  if (parameters_.startup_data) {
    StartupDataImpl* startup_data =
        static_cast<StartupDataImpl*>(parameters_.startup_data);
    // This is always invoked before |io_thread_| is initialized (i.e. never
    // resets it).
    io_thread_ = std::move(startup_data->io_thread);
    mojo_ipc_support_ = std::move(startup_data->mojo_ipc_support);
    service_manager_shutdown_closure_ =
        std::move(startup_data->service_manager_shutdown_closure);
  }

  parts_ = GetContentClient()->browser()->CreateBrowserMainParts(parameters_);
}

// BrowserMainLoop stages ==================================================

int BrowserMainLoop::EarlyInitialization() {
  TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");

#if BUILDFLAG(USE_ZYGOTE_HANDLE)
  // The initialization of the sandbox host ends up with forking the Zygote
  // process and requires no thread been forked. The initialization has happened
  // by now since a thread to start the ServiceManager has been created
  // before the browser main loop starts.
  DCHECK(SandboxHostLinux::GetInstance()->IsInitialized());
#endif

#if defined(USE_X11)
  if (UsingInProcessGpu()) {
    if (!gfx::GetXDisplay()) {
      LOG(ERROR) << "Failed to open an X11 connection.";
    }
  }
#endif

  // GLib's spawning of new processes is buggy, so it's important that at this
  // point GLib does not need to start DBUS. Chrome should always start with
  // DBUS_SESSION_BUS_ADDRESS properly set. See crbug.com/309093.
#if defined(USE_GLIB)
  // g_type_init will be deprecated in 2.36. 2.35 is the development
  // version for 2.36, hence do not call g_type_init starting 2.35.
  // http://developer.gnome.org/gobject/unstable/gobject-Type-Information.html#g-type-init
#if !GLIB_CHECK_VERSION(2, 35, 0)
  // GLib type system initialization. It's unclear if it's still required for
  // any remaining code. Most likely this is superfluous as gtk_init() ought
  // to do this. It's definitely harmless, so it's retained here.
  g_type_init();
#endif  // !GLIB_CHECK_VERSION(2, 35, 0)

  SetUpGLibLogHandler();
#endif  // defined(USE_GLIB)

  if (parts_) {
    const int pre_early_init_error_code = parts_->PreEarlyInitialization();
    if (pre_early_init_error_code != service_manager::RESULT_CODE_NORMAL_EXIT)
      return pre_early_init_error_code;
  }

  // Up the priority of the UI thread unless it was already high (since Mac
  // and recent versions of Android (O+) do this automatically).
#if !defined(OS_MACOSX)
  if (base::FeatureList::IsEnabled(
          features::kBrowserUseDisplayThreadPriority) &&
      base::PlatformThread::GetCurrentThreadPriority() <
          base::ThreadPriority::DISPLAY) {
    base::PlatformThread::SetCurrentThreadPriority(
        base::ThreadPriority::DISPLAY);
  }
#endif  // !defined(OS_MACOSX)

#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
    defined(OS_ANDROID)
  // We use quite a few file descriptors for our IPC as well as disk the disk
  // cache,and the default limit on the Mac is low (256), so bump it up.

  // Same for Linux. The default various per distro, but it is 1024 on Fedora.
  // Low soft limits combined with liberal use of file descriptors means power
  // users can easily hit this limit with many open tabs. Bump up the limit to
  // an arbitrarily high number. See https://crbug.com/539567
  base::IncreaseFdLimitTo(8192);
#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
        // defined(OS_ANDROID)

#if defined(OS_WIN)
  net::EnsureWinsockInit();
#endif

#if defined(USE_NSS_CERTS)
  // We want to be sure to init NSPR on the main thread.
  crypto::EnsureNSPRInit();
#endif

#if defined(OS_FUCHSIA)
  InitDefaultJob();
#endif

#if defined(OS_WIN)
  if (!parsed_command_line_.HasSwitch(switches::kSingleProcess)) {
    if (base::FeatureList::IsEnabled(kBrowserDynamicCodeDisabled)) {
      sandbox::ApplyProcessMitigationsToCurrentProcess(
          sandbox::MITIGATION_DYNAMIC_CODE_DISABLE_WITH_OPT_OUT);
    }
  }
#endif

  if (parsed_command_line_.HasSwitch(switches::kRendererProcessLimit)) {
    std::string limit_string = parsed_command_line_.GetSwitchValueASCII(
        switches::kRendererProcessLimit);
    size_t process_limit;
    if (base::StringToSizeT(limit_string, &process_limit)) {
      RenderProcessHost::SetMaxRendererProcessCount(process_limit);
    }
  }

  if (parts_)
    parts_->PostEarlyInitialization();

  return service_manager::RESULT_CODE_NORMAL_EXIT;
}

void BrowserMainLoop::PreMainMessageLoopStart() {
  TRACE_EVENT0("startup",
               "BrowserMainLoop::MainMessageLoopStart:PreMainMessageLoopStart");
  if (parts_) {
    parts_->PreMainMessageLoopStart();
  }
}

void BrowserMainLoop::MainMessageLoopStart() {
  // DO NOT add more code here. Use PreMainMessageLoopStart() above or
  // PostMainMessageLoopStart() below.

  TRACE_EVENT0("startup", "BrowserMainLoop::MainMessageLoopStart");
  DCHECK(base::MessageLoopCurrentForUI::IsSet());
  InitializeMainThread();
}

void BrowserMainLoop::PostMainMessageLoopStart() {
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:SystemMonitor");
    system_monitor_.reset(new base::SystemMonitor);
  }
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:PowerMonitor");
    if (!base::PowerMonitor::IsInitialized()) {
      base::PowerMonitor::Initialize(
          std::make_unique<base::PowerMonitorDeviceSource>());
    }
  }
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:HighResTimerManager");
    hi_res_timer_manager_.reset(new base::HighResolutionTimerManager);
  }
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:NetworkChangeNotifier");
    // On Android if reduced mode started network service this would already be
    //  created.
    network_change_notifier_ = net::NetworkChangeNotifier::CreateIfNeeded();
  }
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:ScreenlockMonitor");
    std::unique_ptr<ScreenlockMonitorSource> screenlock_monitor_source =
        std::make_unique<ScreenlockMonitorDeviceSource>();
    screenlock_monitor_ = std::make_unique<ScreenlockMonitor>(
        std::move(screenlock_monitor_source));
  }
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:MediaFeatures");
    media::InitializeMediaLibrary();
  }
  {
    TRACE_EVENT0("startup",
                 "BrowserMainLoop::Subsystem:ContentWebUIController");
    WebUIControllerFactory::RegisterFactory(
        ContentWebUIControllerFactory::GetInstance());
  }

  {
    TRACE_EVENT0("startup", "BrowserMainLoop::Subsystem:OnlineStateObserver");
    online_state_observer_.reset(new BrowserOnlineStateObserver);
  }

  { base::SetRecordActionTaskRunner(GetUIThreadTaskRunner({})); }

  // TODO(boliu): kSingleProcess check is a temporary workaround for
  // in-process Android WebView. crbug.com/503724 tracks proper fix.
  if (!parsed_command_line_.HasSwitch(switches::kSingleProcess)) {
    base::DiscardableMemoryAllocator::SetInstance(
        discardable_memory::DiscardableSharedMemoryManager::Get());
  }

  if (parts_)
    parts_->PostMainMessageLoopStart();

#if defined(OS_ANDROID)
  {
    TRACE_EVENT0("startup",
                 "BrowserMainLoop::Subsystem:ScopedSurfaceRequestManager");
    if (UsingInProcessGpu()) {
      gpu::ScopedSurfaceRequestConduit::SetInstance(
          ScopedSurfaceRequestManager::GetInstance());
    }
  }

  if (!parsed_command_line_.HasSwitch(
          switches::kDisableScreenOrientationLock)) {
    TRACE_EVENT0("startup",
                 "BrowserMainLoop::Subsystem:ScreenOrientationProvider");
    screen_orientation_delegate_.reset(new ScreenOrientationDelegateAndroid());
  }

  base::trace_event::TraceLog::GetInstance()->AddEnabledStateObserver(
      base::trace_event::CPUFreqMonitor::GetInstance());
#endif

  // Enable memory-infra dump providers.
  InitSkiaEventTracer();
  base::trace_event::MemoryDumpManager::GetInstance()->RegisterDumpProvider(
      skia::SkiaMemoryDumpProvider::GetInstance(), "Skia", nullptr);
  base::trace_event::MemoryDumpManager::GetInstance()->RegisterDumpProvider(
      sql::SqlMemoryDumpProvider::GetInstance(), "Sql", nullptr);
#if defined(OS_CHROMEOS)
  device::BluetoothAdapterFactory::SetBleScanParserCallback(
      base::BindRepeating(&GetBleScanParser));
#else
  // Chrome Remote Desktop needs TransitionalURLLoaderFactoryOwner on ChromeOS.
  network::TransitionalURLLoaderFactoryOwner::DisallowUsageInProcess();
#endif
}

int BrowserMainLoop::PreCreateThreads() {
  TRACE_EVENT0("startup", "BrowserMainLoop::PreCreateThreads");

  // Make sure no accidental call to initialize GpuDataManager earlier.
  DCHECK(!GpuDataManagerImpl::Initialized());
  if (parts_) {

    result_code_ = parts_->PreCreateThreads();
  }

  InitializeMemoryManagementComponent();

#if BUILDFLAG(ENABLE_PLUGINS)
  // Prior to any processing happening on the IO thread, we create the
  // plugin service as it is predominantly used from the IO thread,
  // but must be created on the main thread. The service ctor is
  // inexpensive and does not invoke the io_thread() accessor.
  {
    TRACE_EVENT0("startup", "BrowserMainLoop::PluginService");
    PluginService::GetInstance()->Init();
  }
#endif

#if BUILDFLAG(ENABLE_LIBRARY_CDMS)
  // Prior to any processing happening on the IO thread, we create the
  // CDM service as it is predominantly used from the IO thread. This must
  // be called on the main thread since it involves file path checks.
  CdmRegistry::GetInstance()->Init();
#endif

#if defined(OS_MACOSX)
  // The WindowResizeHelper allows the UI thread to wait on specific renderer
  // and GPU messages from the IO thread. Initializing it before the IO thread
  // starts ensures the affected IO thread messages always have somewhere to go.
  ui::WindowResizeHelperMac::Get()->Init(base::ThreadTaskRunnerHandle::Get());
#endif

  // GpuDataManager should be initialized in parts_->PreCreateThreads through
  // ChromeBrowserMainExtraPartsGpu. However, if |parts_| is not set,
  // initialize it here.
  // Need to initialize in-process GpuDataManager before creating threads.
  // It's unsafe to append the gpu command line switches to the global
  // CommandLine::ForCurrentProcess object after threads are created.
  GpuDataManagerImpl::GetInstance();
  DCHECK(GpuDataManagerImpl::Initialized());

#if defined(USE_X11)
  gpu_data_manager_visual_proxy_.reset(new internal::GpuDataManagerVisualProxy(
      GpuDataManagerImpl::GetInstance()));
#endif

#if !BUILDFLAG(GOOGLE_CHROME_BRANDING) || defined(OS_ANDROID)
  // Single-process is an unsupported and not fully tested mode, so
  // don't enable it for official Chrome builds (except on Android).
  if (parsed_command_line_.HasSwitch(switches::kSingleProcess))
    RenderProcessHost::SetRunRendererInProcess(true);
#endif

  // Initialize origins that require process isolation.  Must be done
  // after base::FeatureList is initialized, but before any navigations can
  // happen.
  SiteIsolationPolicy::ApplyGlobalIsolatedOrigins();

  return result_code_;
}

void BrowserMainLoop::PreShutdown() {
  ui::Clipboard::OnPreShutdownForCurrentThread();
}

void BrowserMainLoop::CreateStartupTasks() {
  TRACE_EVENT0("startup", "BrowserMainLoop::CreateStartupTasks");

  DCHECK(!startup_task_runner_);
#if defined(OS_ANDROID)
  // Some java scheduler tests need to test migration to C++, but the browser
  // environment isn't set up fully and if these tasks run they may crash.
  if (!g_post_startup_tasks)
    return;

  startup_task_runner_ = std::make_unique<StartupTaskRunner>(
      base::BindOnce(&BrowserStartupComplete),
      GetUIThreadTaskRunner({BrowserTaskType::kBootstrap}));
#else
  startup_task_runner_ = std::make_unique<StartupTaskRunner>(
      base::OnceCallback<void(int)>(), base::ThreadTaskRunnerHandle::Get());
#endif
  StartupTask pre_create_threads = base::BindOnce(
      &BrowserMainLoop::PreCreateThreads, base::Unretained(this));
  startup_task_runner_->AddTask(std::move(pre_create_threads));

  StartupTask create_threads =
      base::BindOnce(&BrowserMainLoop::CreateThreads, base::Unretained(this));
  startup_task_runner_->AddTask(std::move(create_threads));

  StartupTask post_create_threads = base::BindOnce(
      &BrowserMainLoop::PostCreateThreads, base::Unretained(this));
  startup_task_runner_->AddTask(std::move(post_create_threads));

  StartupTask browser_thread_started = base::BindOnce(
      &BrowserMainLoop::BrowserThreadsStarted, base::Unretained(this));
  startup_task_runner_->AddTask(std::move(browser_thread_started));

  StartupTask pre_main_message_loop_run = base::BindOnce(
      &BrowserMainLoop::PreMainMessageLoopRun, base::Unretained(this));
  startup_task_runner_->AddTask(std::move(pre_main_message_loop_run));

#if defined(OS_ANDROID)
  startup_task_runner_->StartRunningTasksAsync();
#else
  startup_task_runner_->RunAllTasksNow();
#endif
}

scoped_refptr<base::SingleThreadTaskRunner>
BrowserMainLoop::GetResizeTaskRunner() {
#if defined(OS_MACOSX)
  scoped_refptr<base::SingleThreadTaskRunner> task_runner =
      ui::WindowResizeHelperMac::Get()->task_runner();
  // In tests, WindowResizeHelperMac task runner might not be initialized.
  return task_runner ? task_runner : base::ThreadTaskRunnerHandle::Get();
#else
  return base::ThreadTaskRunnerHandle::Get();
#endif
}

gpu::GpuChannelEstablishFactory*
BrowserMainLoop::gpu_channel_establish_factory() const {
  return BrowserGpuChannelHostFactory::instance();
}

#if defined(OS_ANDROID)
void BrowserMainLoop::SynchronouslyFlushStartupTasks() {
  startup_task_runner_->RunAllTasksNow();
}
#endif  // OS_ANDROID

int BrowserMainLoop::CreateThreads() {
  TRACE_EVENT0("startup,rail", "BrowserMainLoop::CreateThreads");

  // Release the ThreadPool's threads.
  scoped_execution_fence_.reset();

  // The |io_thread| can have optionally been injected into Init(), but if not,
  // create it here. Thre thread is only tagged as BrowserThread::IO here in
  // order to prevent any code from statically posting to it before
  // CreateThreads() (as such maintaining the invariant that PreCreateThreads()
  // et al. "happen-before" BrowserThread::IO is "brought up").
  if (!io_thread_) {
    io_thread_ = BrowserTaskExecutor::CreateIOThread();
  }
  io_thread_->RegisterAsBrowserThread();
  BrowserTaskExecutor::InitializeIOThread();

  // TODO(https://crbug.com/863341): Replace with a better API
  GetContentClient()->browser()->PostAfterStartupTask(
      FROM_HERE, base::SequencedTaskRunnerHandle::Get(),
      base::BindOnce(
          [](BrowserMainLoop* browser_main_loop) {
            // Enable main thread and thread pool best effort queues. Non-best
            // effort queues will already have been enabled. This will enable
            // all queues on all browser threads, so we need to do this after
            // the threads have been created, i.e. here.
            content::BrowserTaskExecutor::EnableAllQueues();
            browser_main_loop->scoped_best_effort_execution_fence_.reset();
          },
          // Main thread tasks can't run after BrowserMainLoop destruction.
          // Accessing an Unretained pointer to BrowserMainLoop from a main
          // thread task is therefore safe.
          base::Unretained(this)));

  created_threads_ = true;
  return result_code_;
}

int BrowserMainLoop::PostCreateThreads() {
  tracing_controller_ = std::make_unique<content::TracingControllerImpl>();
  content::BackgroundTracingManagerImpl::GetInstance()
      ->AddMetadataGeneratorFunction();

  if (parts_) {
    TRACE_EVENT0("startup", "BrowserMainLoop::PostCreateThreads");
    parts_->PostCreateThreads();
  }

  return result_code_;
}

int BrowserMainLoop::PreMainMessageLoopRun() {
#if defined(OS_ANDROID)
  bool use_display_wide_color_gamut =
      GetContentClient()->browser()->GetWideColorGamutHeuristic() ==
      ContentBrowserClient::WideColorGamutHeuristic::kUseDisplay;
  // Let screen instance be overridable by parts.
  ui::SetScreenAndroid(use_display_wide_color_gamut);
#endif

  if (parts_) {
    TRACE_EVENT0("startup", "BrowserMainLoop::PreMainMessageLoopRun");

    parts_->PreMainMessageLoopRun();
  }

#if defined(OS_WIN)
  // ShellBrowserMainParts initializes a ShellBrowserContext with a profile
  // directory only in PreMainMessageLoopRun(). DWriteFontLookupTableBuilder
  // needs to access this directory, hence triggering after this stage has run.
  if (base::FeatureList::IsEnabled(features::kFontSrcLocalMatching)) {
    content::DWriteFontLookupTableBuilder::GetInstance()
        ->SchedulePrepareFontUniqueNameTableIfNeeded();
  }
#endif

  // If the UI thread blocks, the whole UI is unresponsive. Do not allow
  // unresponsive tasks from the UI thread and instantiate a
  // responsiveness::Watcher to catch jank induced by any blocking tasks not
  // instrumented with ScopedBlockingCall's assert.
  base::DisallowUnresponsiveTasks();
  responsiveness_watcher_ = new responsiveness::Watcher;
  responsiveness_watcher_->SetUp();
  return result_code_;
}

void BrowserMainLoop::RunMainMessageLoopParts() {
  bool ran_main_loop = false;
  if (parts_)
    ran_main_loop = parts_->MainMessageLoopRun(&result_code_);

  if (!ran_main_loop)
    MainMessageLoopRun();
}

void BrowserMainLoop::ShutdownThreadsAndCleanUp() {
  if (!created_threads_) {
    // Called early, nothing to do
    return;
  }
  TRACE_EVENT0("shutdown", "BrowserMainLoop::ShutdownThreadsAndCleanUp");

  // Teardown may start in PostMainMessageLoopRun, and during teardown we
  // need to be able to perform IO.
  base::ThreadRestrictions::SetIOAllowed(true);
  GetIOThreadTaskRunner({})->PostTask(
      FROM_HERE,
      base::BindOnce(
          base::IgnoreResult(&base::ThreadRestrictions::SetIOAllowed), true));

  // Also allow waiting to join threads.
  // TODO(https://crbug.com/800808): Ideally this (and the above SetIOAllowed()
  // would be scoped allowances). That would be one of the first step to ensure
  // no persistent work is being done after ThreadPoolInstance::Shutdown() in
  // order to move towards atomic shutdown.
  base::ThreadRestrictions::SetWaitAllowed(true);
  GetIOThreadTaskRunner({})->PostTask(
      FROM_HERE,
      base::BindOnce(
          base::IgnoreResult(&base::ThreadRestrictions::SetWaitAllowed), true));

  if (RenderProcessHost::run_renderer_in_process())
    RenderProcessHostImpl::ShutDownInProcessRenderer();

  if (parts_) {
    TRACE_EVENT0("shutdown",
                 "BrowserMainLoop::Subsystem:PostMainMessageLoopRun");
    parts_->PostMainMessageLoopRun();
  }

  // Request shutdown to clean up allocated resources on the IO thread.
  if (midi_service_) {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:MidiService");
    midi_service_->Shutdown();
  }

  TRACE_EVENT0("shutdown",
               "BrowserMainLoop::Subsystem:SpeechRecognitionManager");
  io_thread_->task_runner()->DeleteSoon(FROM_HERE,
                                        speech_recognition_manager_.release());

  memory_pressure_monitor_.reset();

  ShutDownNetworkService();

#if defined(OS_MACOSX)
  BrowserCompositorMac::DisableRecyclingForShutdown();
#endif

#if defined(USE_AURA) || defined(OS_MACOSX)
  {
    TRACE_EVENT0("shutdown",
                 "BrowserMainLoop::Subsystem:ImageTransportFactory");
    ImageTransportFactory::Terminate();
  }
#endif

#if !defined(OS_ANDROID)
  host_frame_sink_manager_.reset();
  compositing_mode_reporter_impl_.reset();
#endif

// The device monitors are using |system_monitor_| as dependency, so delete
// them before |system_monitor_| goes away.
// On Mac and windows, the monitor needs to be destroyed on the same thread
// as they were created. On Linux, the monitor will be deleted when IO thread
// goes away.
#if defined(OS_WIN)
  system_message_window_.reset();
#elif defined(OS_MACOSX)
  device_monitor_mac_.reset();
#endif

  if (BrowserGpuChannelHostFactory::instance())
    BrowserGpuChannelHostFactory::instance()->CloseChannel();

  // Shutdown the Service Manager and IPC.
  if (service_manager_shutdown_closure_)
    std::move(service_manager_shutdown_closure_).Run();
  mojo_ipc_support_.reset();

  if (save_file_manager_)
    save_file_manager_->Shutdown();

  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:IOThread");
    ResetThread_IO(std::move(io_thread_));
  }

  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:ThreadPool");
    base::ThreadPoolInstance::Get()->Shutdown();
  }

  // Must happen after the IO thread is shutdown since this may be accessed from
  // it.
  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:GPUChannelFactory");
    if (BrowserGpuChannelHostFactory::instance()) {
      BrowserGpuChannelHostFactory::Terminate();
    }
  }

  // Must happen after the I/O thread is shutdown since this class lives on the
  // I/O thread and isn't threadsafe.
  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:GamepadService");
    device::GamepadService::GetInstance()->Terminate();
  }
  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:DeleteDataSources");
    URLDataManager::DeleteDataSources();
  }
  {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:AudioMan");
    if (audio_manager_ && !audio_manager_->Shutdown()) {
      // Intentionally leak AudioManager if shutdown failed.
      // We might run into various CHECK(s) in AudioManager destructor.
      ignore_result(audio_manager_.release());
      // |user_input_monitor_| may be in use by stray streams in case
      // AudioManager shutdown failed.
      ignore_result(user_input_monitor_.release());
    }

    // Leaking AudioSystem: we cannot correctly destroy it since Audio service
    // connection in there is bound to IO thread.
    ignore_result(audio_system_.release());
  }

  if (parts_) {
    TRACE_EVENT0("shutdown", "BrowserMainLoop::Subsystem:PostDestroyThreads");
    parts_->PostDestroyThreads();
  }
}

media::AudioManager* BrowserMainLoop::audio_manager() const {
  DCHECK(audio_manager_) << "AudioManager is not instantiated - running the "
                            "audio service out of process?";
  return audio_manager_.get();
}

void BrowserMainLoop::GetCompositingModeReporter(
    mojo::PendingReceiver<viz::mojom::CompositingModeReporter> receiver) {
#if defined(OS_ANDROID)
  // Android doesn't support non-gpu compositing modes, and doesn't make a
  // CompositingModeReporter.
  return;
#else
  compositing_mode_reporter_impl_->BindReceiver(std::move(receiver));
#endif
}

void BrowserMainLoop::InitializeMainThread() {
  TRACE_EVENT0("startup", "BrowserMainLoop::InitializeMainThread");
  base::PlatformThread::SetName("CrBrowserMain");

  // Register the main thread. The main thread's task runner should already have
  // been initialized in MainMessageLoopStart() (or before if
  // MessageLoopCurrent::Get() was externally provided).
  DCHECK(base::ThreadTaskRunnerHandle::IsSet());
  main_thread_.reset(new BrowserThreadImpl(
      BrowserThread::UI, base::ThreadTaskRunnerHandle::Get()));
}

int BrowserMainLoop::BrowserThreadsStarted() {
  TRACE_EVENT0("startup", "BrowserMainLoop::BrowserThreadsStarted");

  // Bring up Mojo IPC and the embedded Service Manager as early as possible.
  // Initializaing mojo requires the IO thread to have been initialized first,
  // so this cannot happen any earlier than now.
  InitializeMojo();

  data_decoder_service_provider_ = std::make_unique<OopDataDecoder>();

  HistogramSynchronizer::GetInstance();

  field_trial_synchronizer_ = base::MakeRefCounted<FieldTrialSynchronizer>();

  // cc assumes a single client name for metrics in a process, which is
  // is inconsistent with single process mode where both the renderer and
  // browser compositor run in the same process. In this case, avoid
  // initializing with a browser metric name to ensure we record metrics for the
  // renderer compositor.
  // Note that since single process mode is only used by webview in practice,
  // which doesn't have a browser compositor, this is not required anyway.
  if (!base::CommandLine::ForCurrentProcess()->HasSwitch(
          switches::kSingleProcess)) {
    cc::SetClientNameForMetrics("Browser");
  }

  // Initialize the GPU shader cache. This needs to be initialized before
  // BrowserGpuChannelHostFactory below, since that depends on an initialized
  // ShaderCacheFactory.
  InitShaderCacheFactorySingleton(GetIOThreadTaskRunner({}));

  // Initialize the FontRenderParams on IO thread. This needs to be initialized
  // before gpu process initialization below.
  GetIOThreadTaskRunner({})->PostTask(
      FROM_HERE, base::BindOnce(&viz::GpuHostImpl::InitFontRenderParams,
                                gfx::GetFontRenderParams(
                                    gfx::FontRenderParamsQuery(), nullptr)));

  bool always_uses_gpu = true;
  bool established_gpu_channel = false;
#if defined(OS_ANDROID)
  // TODO(crbug.com/439322): This should be set to |true|.
  established_gpu_channel = false;
  always_uses_gpu = ShouldStartGpuProcessOnBrowserStartup();
  BrowserGpuChannelHostFactory::Initialize(established_gpu_channel);
#else
  established_gpu_channel = true;
  if (parsed_command_line_.HasSwitch(switches::kDisableGpu) ||
      parsed_command_line_.HasSwitch(switches::kDisableGpuCompositing) ||
      parsed_command_line_.HasSwitch(switches::kDisableGpuEarlyInit)) {
    established_gpu_channel = always_uses_gpu = false;
  }

  host_frame_sink_manager_ = std::make_unique<viz::HostFrameSinkManager>();
  BrowserGpuChannelHostFactory::Initialize(established_gpu_channel);
  compositing_mode_reporter_impl_ =
      std::make_unique<viz::CompositingModeReporterImpl>();

  auto transport_factory = std::make_unique<VizProcessTransportFactory>(
      BrowserGpuChannelHostFactory::instance(), GetResizeTaskRunner(),
      compositing_mode_reporter_impl_.get());
  transport_factory->ConnectHostFrameSinkManager();
  ImageTransportFactory::SetFactory(std::move(transport_factory));

#if defined(USE_AURA)
  env_->set_context_factory(GetContextFactory());
#endif  // defined(USE_AURA)
#endif  // !defined(OS_ANDROID)

#if defined(OS_ANDROID)
  base::trace_event::MemoryDumpManager::GetInstance()->RegisterDumpProvider(
      tracing::GraphicsMemoryDumpProvider::GetInstance(), "AndroidGraphics",
      nullptr);
#endif

  {
    TRACE_EVENT0("startup", "BrowserThreadsStarted::Subsystem:AudioMan");
    InitializeAudio();
  }

  {
    TRACE_EVENT0("startup", "BrowserThreadsStarted::Subsystem:MidiService");
    midi_service_.reset(new midi::MidiService);
  }

  {
    TRACE_EVENT0("startup", "BrowserThreadsStarted::Subsystem:Devices");
    device::GamepadService::GetInstance()->StartUp(
        base::BindRepeating(&BindHidManager));
#if !defined(OS_ANDROID)
    device::FidoHidDiscovery::SetHidManagerBinder(
        base::BindRepeating(&BindHidManager));
#endif
  }

#if defined(OS_WIN)
  system_message_window_.reset(new media::SystemMessageWindowWin);
#elif defined(OS_LINUX) && defined(USE_UDEV)
  device_monitor_linux_ = std::make_unique<media::DeviceMonitorLinux>();
#elif defined(OS_MACOSX)
  // On Mac, the audio task runner must belong to the main thread.
  // See audio_thread_impl.cc and https://crbug.com/158170.
  DCHECK(!audio_manager_ ||
         audio_manager_->GetTaskRunner()->BelongsToCurrentThread());
  device_monitor_mac_.reset(
      new media::DeviceMonitorMac(base::ThreadTaskRunnerHandle::Get()));
#endif

  // Instantiated once using CreateSingletonInstance(), and accessed only using
  // GetInstance(), which is not allowed to create the object. This allows us
  // to ensure that it cannot be used before objects it relies on have been
  // created; namely, WebRtcEventLogManager.
  // Allowed to leak when the browser exits.
  WebRTCInternals::CreateSingletonInstance();

  // MediaStreamManager needs the IO thread to be created.
  {
    TRACE_EVENT0(
        "startup",
        "BrowserMainLoop::BrowserThreadsStarted:InitMediaStreamManager");

    scoped_refptr<base::SingleThreadTaskRunner> audio_task_runner =
        audio_manager_ ? audio_manager_->GetTaskRunner() : nullptr;

#if defined(OS_MACOSX)
    // On Mac, the audio task runner must belong to the main thread.
    // See audio_thread_impl.cc and https://crbug.com/158170.
    if (audio_task_runner) {
      DCHECK(audio_task_runner->BelongsToCurrentThread());
    } else {
      audio_task_runner = base::ThreadTaskRunnerHandle::Get();
    }
#endif

    media_stream_manager_ = std::make_unique<MediaStreamManager>(
        audio_system_.get(), std::move(audio_task_runner));
  }

  {
    TRACE_EVENT0(
        "startup",
        "BrowserMainLoop::BrowserThreadsStarted:InitSpeechRecognition");
    speech_recognition_manager_.reset(new SpeechRecognitionManagerImpl(
        audio_system_.get(), media_stream_manager_.get()));
  }

  {
    TRACE_EVENT0(
        "startup",
        "BrowserMainLoop::BrowserThreadsStarted::InitUserInputMonitor");
    user_input_monitor_ = media::UserInputMonitor::Create(
        io_thread_->task_runner(), base::ThreadTaskRunnerHandle::Get());
  }

  {
    TRACE_EVENT0("startup",
                 "BrowserMainLoop::BrowserThreadsStarted::SaveFileManager");
    save_file_manager_ = new SaveFileManager();
  }

  // Alert the clipboard class to which threads are allowed to access the
  // clipboard:
  std::vector<base::PlatformThreadId> allowed_clipboard_threads;
  // The current thread is the UI thread.
  allowed_clipboard_threads.push_back(base::PlatformThread::CurrentId());
#if defined(OS_WIN)
  // On Windows, clipboard is also used on the IO thread.
  allowed_clipboard_threads.push_back(io_thread_->GetThreadId());
#endif
  ui::Clipboard::SetAllowedThreads(allowed_clipboard_threads);

  if (GpuDataManagerImpl::GetInstance()->GpuProcessStartAllowed() &&
      !established_gpu_channel && always_uses_gpu) {
    TRACE_EVENT_INSTANT0("gpu", "Post task to launch GPU process",
                         TRACE_EVENT_SCOPE_THREAD);
    GetIOThreadTaskRunner({})->PostTask(
        FROM_HERE,
        base::BindOnce(base::IgnoreResult(&GpuProcessHost::Get),
                       GPU_PROCESS_KIND_SANDBOXED, true /* force_create */));
  }

#if defined(OS_WIN)
  GpuDataManagerImpl::GetInstance()->OnBrowserThreadsStarted();
#endif

  if (MediaKeysListenerManager::IsMediaKeysListenerManagerEnabled()) {
    media_keys_listener_manager_ =
        std::make_unique<MediaKeysListenerManagerImpl>();
  }

#if defined(OS_MACOSX)
  ThemeHelperMac::GetInstance();
#endif  // defined(OS_MACOSX)

#if defined(OS_ANDROID)
  media::SetMediaDrmBridgeClient(GetContentClient()->GetMediaDrmBridgeClient());
  if (base::FeatureList::IsEnabled(features::kFontSrcLocalMatching)) {
    FontUniqueNameLookup::GetInstance();
  }
#endif

#if defined(ENABLE_IPC_FUZZER)
  SetFileUrlPathAliasForIpcFuzzer();
#endif
  return result_code_;
}

bool BrowserMainLoop::UsingInProcessGpu() const {
  return parsed_command_line_.HasSwitch(switches::kSingleProcess) ||
         parsed_command_line_.HasSwitch(switches::kInProcessGPU);
}

void BrowserMainLoop::InitializeMemoryManagementComponent() {
  memory_pressure_monitor_ = CreateMemoryPressureMonitor(parsed_command_line_);
}

bool BrowserMainLoop::InitializeToolkit() {
  TRACE_EVENT0("startup", "BrowserMainLoop::InitializeToolkit");

  // TODO(evan): this function is rather subtle, due to the variety
  // of intersecting ifdefs we have.  To keep it easy to follow, there
  // are no #else branches on any #ifs.
  // TODO(stevenjb): Move platform specific code into platform specific Parts
  // (Need to add InitializeToolkit stage to BrowserParts).
  // See also GTK setup in EarlyInitialization, above, and associated comments.

#if defined(OS_WIN)
  INITCOMMONCONTROLSEX config;
  config.dwSize = sizeof(config);
  config.dwICC = ICC_WIN95_CLASSES;
  if (!InitCommonControlsEx(&config))
    PLOG(FATAL);
#endif

#if defined(USE_AURA)

#if defined(USE_X11)
  if (!parsed_command_line_.HasSwitch(switches::kHeadless) &&
      !gfx::GetXDisplay()) {
    LOG(ERROR) << "Unable to open X display.";
    return false;
  }
#endif

  // Env creates the compositor. Aura widgets need the compositor to be created
  // before they can be initialized by the browser.
  env_ = aura::Env::CreateInstance();
#endif  // defined(USE_AURA)

  if (parts_)
    parts_->ToolkitInitialized();

  return true;
}

void BrowserMainLoop::MainMessageLoopRun() {
#if defined(OS_ANDROID)
  // Android's main message loop is the Java message loop.
  NOTREACHED();
#else
  base::RunLoop run_loop;
  parts_->PreDefaultMainMessageLoopRun(run_loop.QuitClosure());
  run_loop.Run();
#endif
}

void BrowserMainLoop::InitializeMojo() {
  if (!parsed_command_line_.HasSwitch(switches::kSingleProcess)) {
    // Disallow mojo sync calls in the browser process. Note that we allow sync
    // calls in single-process mode since renderer IPCs are made from a browser
    // thread.
    mojo::SyncCallRestrictions::DisallowSyncCall();
  }

  // Ensure that any NavigableContentsViews constructed in the browser process
  // know they're running in the same process as the service.
  content::NavigableContentsView::SetClientRunningInServiceProcess();

  // Start startup tracing through TracingController's interface. TraceLog has
  // been enabled in content_main_runner where threads are not available. Now We
  // need to start tracing for all other tracing agents, which require threads.
  // We can only do this after starting the main message loop to avoid calling
  // MessagePumpForUI::ScheduleWork() before MessagePumpForUI::Start().
  TracingControllerImpl::GetInstance()->StartStartupTracingIfNeeded();

#if BUILDFLAG(MOJO_RANDOM_DELAYS_ENABLED)
  mojo::BeginRandomMojoDelays();
#endif
}

void BrowserMainLoop::InitializeAudio() {
  DCHECK(!audio_manager_);

  audio_manager_ = GetContentClient()->browser()->CreateAudioManager(
      MediaInternals::GetInstance());
  DCHECK_EQ(!!audio_manager_,
            GetContentClient()->browser()->OverridesAudioManager());

  // Do not initialize |audio_manager_| if running out of process.
  if (!audio_manager_ &&
      (base::CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kSingleProcess) ||
       !base::FeatureList::IsEnabled(features::kAudioServiceOutOfProcess))) {
    audio_manager_ =
        media::AudioManager::Create(std::make_unique<media::AudioThreadImpl>(),
                                    MediaInternals::GetInstance());
    CHECK(audio_manager_);
  }

  // Iff |audio_manager_| is instantiated, the audio service will run
  // in-process. Complete the setup for that:
  if (audio_manager_) {
    AudioMirroringManager* const mirroring_manager =
        AudioMirroringManager::GetInstance();
    audio_manager_->SetDiverterCallbacks(
        mirroring_manager->GetAddDiverterCallback(),
        mirroring_manager->GetRemoveDiverterCallback());

    TRACE_EVENT_INSTANT0("startup", "Starting Audio service task runner",
                         TRACE_EVENT_SCOPE_THREAD);
    audio::Service::GetInProcessTaskRunner()->StartWithTaskRunner(
        audio_manager_->GetTaskRunner());
  }

  if (base::FeatureList::IsEnabled(features::kAudioServiceLaunchOnStartup)) {
    // Schedule the audio service startup on the main thread.
    content::GetUIThreadTaskRunner({base::TaskPriority::BEST_EFFORT})
        ->PostTask(FROM_HERE, base::BindOnce([]() {
                     TRACE_EVENT0("audio", "Starting audio service");
                     GetAudioService();
                   }));
  }

  audio_system_ = CreateAudioSystemForAudioService();
  CHECK(audio_system_);
}

bool BrowserMainLoop::AudioServiceOutOfProcess() const {
  // Returns true iff kAudioServiceOutOfProcess feature is enabled and if the
  // embedder does not provide its own in-process AudioManager.
  return base::FeatureList::IsEnabled(features::kAudioServiceOutOfProcess) &&
         !GetContentClient()->browser()->OverridesAudioManager();
}

SmsProvider* BrowserMainLoop::GetSmsProvider() {
  if (!sms_provider_) {
    sms_provider_ = SmsProvider::Create();
  }
  return sms_provider_.get();
}

void BrowserMainLoop::SetSmsProviderForTesting(
    std::unique_ptr<SmsProvider> provider) {
  sms_provider_ = std::move(provider);
}

}  // namespace content
