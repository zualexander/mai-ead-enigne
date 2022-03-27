#include "Application.h"
#include "pch.h"
#include "Log.h"

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Enigne {
    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
        window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
    }


    Application::~Application() {}

    void Application::onEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
        EN_CORE_TRACE("{0}", e.toString());
    }

    bool Application::onWindowClose(WindowCloseEvent &e) {
        isRunning = false;
        return true;
    }

    void Application::Run() {
        while (isRunning) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            window->onUpdate();
        }
    }

}