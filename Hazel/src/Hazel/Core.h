#pragma once

#define LOG_REF std::shared_ptr<spdlog::logger>
#define CORE_LOG ::Hazel::Log::GetCoreLogger()
#define CLIENT_LOG ::Hazel::Log::GetClientLogger()

#ifdef HZ_PLATFORM_WINDOWS
  #ifdef HZ_BUILD_DLL
    #define HAZEL_API __declspec(dllexport)
  #else
    #define HAZEL_API __declspec(dllimport)
  #endif // DEBUG
#else 
  #error Hazel only support Windows!
#endif