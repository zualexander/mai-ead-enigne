#pragma once

#include "Core.h"

namespace Enigne {

	class ENIGNE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();
}