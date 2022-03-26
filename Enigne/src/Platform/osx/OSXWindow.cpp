//
// Created by zualexander on 26.03.22.
//

#include "Platform/osx/OSXWindow.h"
#include "pch.h"
#include "Log.h"

namespace Enigne {

    static bool isGLFWInitialized = false;

    OSXWindow::OSXWindow(const WindowProperties &props) {
        init(props);
    }

    OSXWindow::~OSXWindow() {
        shutdown();
    }

    bool OSXWindow::isVSync() const {
        return data.isVSync;
    }

    Window *Window::create(const WindowProperties &props) {
        return new OSXWindow(props);
    }

    void OSXWindow::init(const WindowProperties &props) {
        data.title = props.title;
        data.width = props.width;
        data.height = props.height;

        EN_CORE_INFO("osx window {0} created ({1} X {2})", data.title, data.width, data.height);

        if (!isGLFWInitialized) {
            // @todo: glfwTerminate on system shutdown
            int success = glfwInit();
            if (!success) {
                throw std::runtime_error("Window could not be initialized with GLFW.");
            }
            isGLFWInitialized = true;
        }

        window = glfwCreateWindow((int) data.width, (int) data.height, data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        setVSync(true);
    }

    void OSXWindow::shutdown() {
        glfwDestroyWindow(window);
    }

    void OSXWindow::onUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void OSXWindow::setVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        data.isVSync = enabled;
    }


}
