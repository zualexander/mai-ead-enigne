#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Enigne {
	class ENIGNE_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}


// todo: implement more and clientlogger
// core log macros
#define EN_CORE_TRACE(...) ::Enigne::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EN_CORE_INFO(...) ::Enigne::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EN_CORE_ERROR(...) ::Enigne::Log::GetCoreLogger()->error(__VA_ARGS__)

#define EN_CLIENT_TRACE(...) ::Enigne::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EN_CLIENT_INFO(...) ::Enigne::Log::GetClientLogger()->info(__VA_ARGS__)
#define EN_CLIENT_ERROR(...) ::Enigne::Log::GetClientLogger()->error(__VA_ARGS__)