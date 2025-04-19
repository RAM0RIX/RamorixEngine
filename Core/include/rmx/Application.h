#pragma once
#include <rmx/Core.h>

namespace rmx
{

    class RMX_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    // To be defined in client
    Application* CreateApplication();

} // namespace rmx
