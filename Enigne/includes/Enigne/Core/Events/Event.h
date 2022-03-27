#pragma once

#include "Core.h"

namespace Enigne {
    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = 1,
        EventCategoryInput = 2,
        EventCategoryKeyboard = 4,
        EventCategoryMouse = 8,
        EventCategoryMouseButton = 16
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType getStaticType() { return EventType::type; }                \
    virtual EventType getEventType() const override { return getStaticType(); } \
    virtual const char *getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int getCategoryFlags() const override { return category; }

    class Event {
    public:
        virtual ~Event() = default;

        bool isHandled = false;

        virtual EventType getEventType() const = 0;
        virtual const char *getName() const = 0;
        virtual int getCategoryFlags() const = 0;

        virtual std::string toString() const { return getName(); }

        bool isInCategory(EventCategory category) const {
            return getCategoryFlags() & category;
        }
    };

    class EventDispatcher {
    public:
        EventDispatcher(Event &event)
                : m_Event(event) {
        }

        // F will be deduced by the compiler
        template<typename T, typename F>
        bool dispatch(const F &func) {
            if (m_Event.getEventType() == T::getStaticType()) {
                m_Event.isHandled |= func(static_cast<T &>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event &m_Event;
    };

    inline std::ostream &operator<<(std::ostream &os, const Event &e) {
        return os << e.toString();
    }

}