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

#define BIT(x) (1 << x)