#include <rmx/Log.h>

#include <Windows.h>
#include <iostream>
#include <fstream>

namespace rmx
{
    void Log::CreateDebugConsole()
    {
        AllocConsole(); // Creates a new console for the calling process
        FILE* fp;

        // Redirect stdout
        freopen_s(&fp, "CONOUT$", "w", stdout);
        // Redirect stderr
        freopen_s(&fp, "CONOUT$", "w", stderr);
        // Redirect stdin
        freopen_s(&fp, "CONIN$", "r", stdin);

        std::ios::sync_with_stdio(); // Sync C++ streams with C stdio
    }

    void Log::DestroyDebugConsole()
    {
        FreeConsole();
    }

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("Ramorix");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("App");
        s_CoreLogger->set_level(spdlog::level::trace);
    }

}

