#pragma once
#ifdef RMX_PLATFORM_WINDOWS

    #include <rmx/Application.h>
    #include <rmx/Log.h>
    #include <rmx/Events/ApplicationEvent.h>

extern rmx::Application* rmx::CreateApplication();

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    #if defined(RMX_DEBUG) or defined(RMX_RELEASE)
    rmx::Log::CreateDebugConsole();
    rmx::Log::Init();
    #endif
    RMX_CORE_TRACE("Initialized Debugging Window");
    RMX_CLIENT_INFO("Launching Ramorix Engine...");

    rmx::Application* app = rmx::CreateApplication();
    app->Run();
    delete app;

    MessageBox(NULL, TEXT("Unexpected crash !"), NULL, MB_OK);
    return ERROR_FATAL_APP_EXIT;

    #if defined(RMX_DEBUG) or defined(RMX_RELEASE)
    rmx::Log::DestroyDebugConsole();
    #endif
}

#elif defined(RMX_PLATFORM_LINUX)

int main(int argc, char** argv)
{
    return 0;
}

#endif
