
#ifdef EN_PLATFORM_WINDOWS
extern Enigne::Application* Enigne::CreateApplication();

int main(int argc, char **argv) {
	Enigne::Log::Init();
	Enigne::Log::GetCoreLogger()->warn("InitializedLog");
	Enigne::Log::GetClientLogger()->warn("InitializedLog");

	auto app = Enigne::CreateApplication(); 
	app->Run();
	delete app;
}

#endif