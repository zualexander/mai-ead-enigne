//
// Created by zualexander on 26.03.22.
//


#ifndef ENIGNE_WINDOW_H
#define ENIGNE_WINDOW_H

#include <utility>

#include "Core.h"
#include "pch.h"
#include "Event.h"

namespace Enigne {
    struct WindowProperties {
        unsigned int width;
        unsigned int height;
        std::string title;


        WindowProperties(std::string title = "Enigne",
                         unsigned int height = 720,
                         unsigned int width = 1280)
                : title(std::move(title)), height(height), width(width) {}
    };


    // abstract interface for desktop system
    class ENIGNE_API Window {
    public:
        // typedefinition for shorthand abbrev.
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() {}

        virtual void onUpdate() = 0;

        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;

        // window attributes
        virtual void setEventCallback(const EventCallbackFn &cb) = 0;
        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSync() const = 0;

        static Window *create(const WindowProperties &props = WindowProperties());
    };
}

#endif //ENIGNE_WINDOW_H
