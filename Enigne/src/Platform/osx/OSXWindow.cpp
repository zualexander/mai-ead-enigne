//
// Created by zualexander on 26.03.22.
//

#include "Platform/osx/OSXWindow.h"
#include "pch.h"
#include "Log.h"
#include "ApplicationEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

namespace Enigne {

    static bool isGLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *desc) {
        EN_CORE_ERROR("GLFW Error ({0}: {1))", error, desc);
    }

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
            glfwSetErrorCallback(GLFWErrorCallback);
            isGLFWInitialized = true;
        }

        window = glfwCreateWindow((int) data.width, (int) data.height, data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        setVSync(true);

        // Set GLFW callbacks
        bindGLFWEvents();

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

    void OSXWindow::bindGLFWEvents() const {
        glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;

            WindowResizeEvent evt(width, height);
            data.evtCallback(evt);
        });

        glfwSetWindowCloseCallback(window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            WindowCloseEvent evt;
            data.evtCallback(evt);
        });

        glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.evtCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.evtCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.evtCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.evtCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.evtCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            MouseScrolledEvent evt((float) xOffset, (float) yOffset);
            data.evtCallback(evt);
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow *window, double xPosition, double yPosition) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);

            MouseMovedEvent evt((float) xPosition, (float) yPosition);
            data.evtCallback(evt);
        });
    }

}
