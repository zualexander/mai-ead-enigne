#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

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