#include "Application.h"
#include "pch.h"

namespace Enigne {
    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
    }

    Application::~Application() {}


    void Application::Run() {
        while (isRunning) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate();
        }
    }
}