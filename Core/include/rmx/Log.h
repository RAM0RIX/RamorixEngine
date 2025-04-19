#pragma once
#include <rmx/Core.h>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace rmx
{
class RMX_API Log
{
  public:
    static void CreateDebugConsole();
    static void DestroyDebugConsole();

    static void Init();

  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

  public:
    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
    {
        return s_CoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger> &GetClientLogger()
    {
        return s_ClientLogger;
    }
};
} // namespace rmx

#if defined(RMX_DEBUG) or defined(RMX_RELEASE)

// Core defs
#define RMX_CORE_FATAL(...) ::rmx::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RMX_CORE_ERROR(...) ::rmx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RMX_CORE_WARNING(...) ::rmx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RMX_CORE_INFO(...) ::rmx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RMX_CORE_TRACE(...) ::rmx::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client defs
#define RMX_CLIENT_FATAL(...) ::rmx::Log::GetClientLogger()->critical(__VA_ARGS__)
#define RMX_CLIENT_ERROR(...) ::rmx::Log::GetClientLogger()->error(__VA_ARGS__)
#define RMX_CLIENT_WARNING(...) ::rmx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RMX_CLIENT_INFO(...) ::rmx::Log::GetClientLogger()->info(__VA_ARGS__)
#define RMX_CLIENT_TRACE(...) ::rmx::Log::GetClientLogger()->trace(__VA_ARGS__)

#else

// Core defs
#define RMX_CORE_FATAL(...)
#define RMX_CORE_ERROR(...)
#define RMX_CORE_WARNING(...)
#define RMX_CORE_INFO(...)
#define RMX_CORE_TRACE(...)

// Client defs
#define RMX_CLIENT_FATAL(...)
#define RMX_CLIENT_ERROR(...)
#define RMX_CLIENT_WARNING(...)
#define RMX_CLIENT_INFO(...)
#define RMX_CLIENT_TRACE(...)

#endif
