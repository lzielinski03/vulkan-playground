#pragma once

#ifdef VPL_PLATFORM_WINDOWS
	#ifdef VPL_BUILD_DLL
		#define VPL_API __declspec(dllexport)
	#else
		#define VPL_API __declspec(dllimport)
	#endif
#else
	#error Vulkan Playground only support Windows!
#endif

#ifdef VPL_ENABLE_ASSERTS
	#define VPL_ASSERT(x, ...) { if(!(x)) { VPL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VPL_CORE_ASSERT(x, ...) { if(!(x)) { VPL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VPL_ASSERT(x, ...)
	#define VPL_CORE_ASSERT(x, ...)
#endif



#define BIT(x) (1 << x)