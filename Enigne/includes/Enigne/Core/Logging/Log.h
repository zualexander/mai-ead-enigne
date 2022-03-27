#include "Core.h"
#include "pch.h"

namespace Enigne {
	class ENIGNE_API Log {
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}


// core log macros
#define EN_CORE_TRACE(...) ::Enigne::Log::getCoreLogger()->trace(__VA_ARGS__)
#define EN_CORE_INFO(...) ::Enigne::Log::getCoreLogger()->info(__VA_ARGS__)
#define EN_CORE_WARN(...) ::Enigne::Log::getCoreLogger()->warn(__VA_ARGS__)
#define EN_CORE_ERROR(...) ::Enigne::Log::getCoreLogger()->error(__VA_ARGS__)

// client log macros
#define EN_CLIENT_TRACE(...) ::Enigne::Log::getClientLogger()->trace(__VA_ARGS__)
#define EN_CLIENT_INFO(...) ::Enigne::Log::getClientLogger()->info(__VA_ARGS__)
#define EN_CLIENT_WARN(...) ::Enigne::Log::getClientLogger()->warn(__VA_ARGS__)
#define EN_CLIENT_ERROR(...) ::Enigne::Log::getClientLogger()->error(__VA_ARGS__)