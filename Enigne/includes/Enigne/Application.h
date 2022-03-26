#include "Core.h"
#include "Window.h"

namespace Enigne {

    class ENIGNE_API Application {
    private:
        std::unique_ptr<Window> window;
        bool isRunning = true;
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // to be defined in client
    Application *CreateApplication();
}