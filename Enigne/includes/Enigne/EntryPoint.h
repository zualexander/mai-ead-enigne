extern Enigne::Application* Enigne::CreateApplication();

int main(int argc, char **argv) {
	Enigne::Log::Init();
	EN_CORE_WARN("Initialized TRACE");
    EN_CLIENT_TRACE("User TRace");

	auto app = Enigne::CreateApplication(); 
	app->Run();
	delete app;
}