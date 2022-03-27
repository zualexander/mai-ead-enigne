extern Enigne::Application *Enigne::CreateApplication();

int main(int argc, char **argv) {
    Enigne::Application *appPtr;
    try {
        Enigne::Log::init();
        EN_CORE_INFO("Engine Started");

        auto app = Enigne::CreateApplication();
        appPtr = app;
        app->Run();
        delete app;
    }
    catch (std::runtime_error &e) {
        if (appPtr != nullptr) {
            delete appPtr;
        }

        std::cerr << e.what() << std::endl;
        return -1;
    }
}