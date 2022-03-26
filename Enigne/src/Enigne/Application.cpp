#include "Application.h"
#include "pch.h"

namespace Enigne {
    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
    }

    Application::~Application() {}


    void Application::Run() {
        while (isRunning) {
            window->onUpdate();
        }
    }
}