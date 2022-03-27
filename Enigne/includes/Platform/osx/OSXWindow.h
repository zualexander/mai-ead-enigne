//
// Created by zualexander on 26.03.22.
//

#ifndef ENIGNE_OSXWINDOW_H
#define ENIGNE_OSXWINDOW_H

#include "Window.h"


namespace Enigne {

    class OSXWindow : public Window {
    private:
        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool isVSync;

            EventCallbackFn evtCallback;
        };
        GLFWwindow *window;
        WindowData data;

    private:
        virtual void init(const WindowProperties &props);
        virtual void shutdown();

    public:
        OSXWindow(const WindowProperties &props);
        virtual ~OSXWindow();

        void onUpdate() override;

        unsigned int getWidth() const override { return data.width; }

        unsigned int getHeight() const override { return data.height; }

        /* inline */ void setEventCallback(const EventCallbackFn &cb) override { data.evtCallback = cb; }

        void setVSync(bool enabled) override;
        bool isVSync() const override;

        void bindGLFWEvents() const;
    };
}


#endif //ENIGNE_OSXWINDOW_H
