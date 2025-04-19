#include <Ramorix.h>

class Sandbox : public rmx::Application
{
  public:
    Sandbox()
    {
    }
    ~Sandbox()
    {
    }
};

rmx::Application *rmx::CreateApplication()
{
    return new Application();
}
