#pragma once

#include <memory>
#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace VulkanPG {

	class VPL_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logs macros
#define VPL_CORE_TRACE(...) ::VulkanPG::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VPL_CORE_INFO(...) ::VulkanPG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VPL_CORE_WARN(...) ::VulkanPG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VPL_CORE_ERROR(...) ::VulkanPG::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VPL_CORE_FATAL(...) ::VulkanPG::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logs macros
#define VPL_TRACE(...) ::VulkanPG::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VPL_INFO(...) ::VulkanPG::Log::GetClientLogger()->info(__VA_ARGS__)
#define VPL_WARN(...) ::VulkanPG::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VPL_ERROR(...) ::VulkanPG::Log::GetClientLogger()->error(__VA_ARGS__)
#define VPL_FATAL(...) ::VulkanPG::Log::GetClientLogger()->fatal(__VA_ARGS__)
