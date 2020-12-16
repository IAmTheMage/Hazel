#pragma once
#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel {
  class __declspec(dllexport) Log {
    public:
      static void Init();
      inline static LOG_REF& GetCoreLogger() { return s_CoreLogger; };
      inline static LOG_REF& GetClientLogger() { return s_ClientLogger; };
    private:
      static LOG_REF s_CoreLogger;
      static LOG_REF s_ClientLogger;
  };
}

//Core Log Macros
#define HZ_CORE_LOG_ERROR(...)  CORE_LOG->error(__VA_ARGS__)
#define HZ_CORE_LOG_INFO(...)   CORE_LOG->info(__VA_ARGS__)
#define HZ_CORE_LOG_WARN(...)   CORE_LOG->warn(__VA_ARGS__)
#define HZ_CORE_LOG_TRACE(...)  CORE_LOG->trace(__VA_ARGS__)
#define HZ_CORE_LOG_FATAL(...)  CORE_LOG->fatal(__VA_ARGS__)

//Client Logs Macros

#define HZ_CLIENT_LOG_ERROR(...)  CLIENT_LOG->error(__VA_ARGS__)
#define HZ_CLIENT_LOG_INFO(...)   CLIENT_LOG->info(__VA_ARGS__)
#define HZ_CLIENT_LOG_WARN(...)   CLIENT_LOG->warn(__VA_ARGS__)
#define HZ_CLIENT_LOG_TRACE(...)  CLIENT_LOG->trace(__VA_ARGS__)
#define HZ_CLIENT_LOG_FATAL(...)  CLIENT_LOG->fatal(__VA_ARGS__)