#include <Enigne.h>

class Sandbox : public Enigne::Application {};

Enigne::Application* Enigne::CreateApplication() {
	EN_CLIENT_INFO("Application Creation");
	return new Sandbox();
}
