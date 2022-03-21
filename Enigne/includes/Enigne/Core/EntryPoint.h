extern Enigne::Application* Enigne::CreateApplication();

int main(int argc, char **argv) {
	Enigne::Log::Init();
	EN_CORE_INFO("Engine Started");

	auto app = Enigne::CreateApplication(); 
	app->Run();
	delete app;
}