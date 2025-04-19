#include <rmxpch.h>

#include <rmx/Application.h>
#include <rmx/Events/ApplicationEvent.h>
#include <rmx/Log.h>

namespace rmx
{
    Application::Application() {}
    Application::~Application() {}
    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        RMX_CLIENT_TRACE(e.ToString());
        while (true);
    }
} // namespace rmx
