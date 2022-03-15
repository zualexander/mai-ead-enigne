
#ifdef EN_PLATFORM_WINDOWS
extern Enigne::Application* Enigne::CreateApplication();

int main(int argc, char **argv) {
	Enigne::Log::Init();
	EN_CLIENT_TRACE("Initialized TRACE");
	EN_USER_TRACE("User TRace");

	auto app = Enigne::CreateApplication(); 
	app->Run();
	delete app;
}

#endif