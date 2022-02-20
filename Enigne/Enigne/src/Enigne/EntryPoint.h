#pragma once

#ifdef EN_PLATFORM_WINDOWS
extern Enigne::Application* Enigne::CreateApplication();

int main(int argc, char **argv) {
	auto app = Enigne::CreateApplication(); 
	app->Run();
	delete app;
}

#endif