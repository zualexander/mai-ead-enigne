#include <Enigne.h>


class Sandbox : public Enigne::Application {

};

Enigne::Application* Enigne::CreateApplication() {
	return new Sandbox();
}
