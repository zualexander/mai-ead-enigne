#include <Enigne.h>

class Sandbox : public Enigne::Application {};

Enigne::Application* Enigne::CreateApplication() {
	EN_CLIENT_INFO("Application Creation");
	EN_CLIENT_INFO("Application Creation2");
	return new Sandbox();
}
