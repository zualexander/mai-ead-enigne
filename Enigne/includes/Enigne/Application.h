#include "Core.h"
#include "Window.h"
#include "ApplicationEvent.h"

namespace Enigne {

    class ENIGNE_API Application {
    private:
        std::unique_ptr<Window> window;
        bool isRunning = true;
        bool onWindowClose(WindowCloseEvent& e);
    public:
        Application();
        virtual ~Application();

        void Run();

        void onEvent(Event& e);
    };

    // to be defined in client
    Application *CreateApplication();
}