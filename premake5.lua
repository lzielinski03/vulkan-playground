workspace "vulkan-playground"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "vulkan-playground/vendor/GLFW/include"
IncludeDir["glm"] = "vulkan-playground/vendor/glm"

include "vulkan-playground/vendor/GLFW"

project "GLFW"
	staticruntime "On"

project "vulkan-playground"
	location "vulkan-playground"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

	pchheader "pch.hpp"
	pchsource "vulkan-playground/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"vulkan-playground/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"C:/VulkanSDK/1.3.224.1/Include"
	}

	links 
	{ 
		"GLFW",
		"C:/VulkanSDK/1.3.224.1/Lib/vulkan-1.lib"
		--"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VPL_PLATFORM_WINDOWS",
			"VPL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "VPL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VPL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VPL_DIST"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"vulkan-playground/vendor/spdlog/include",
		"vulkan-playground/src",
		"C:/VulkanSDK/1.3.224.1/Include"
	}

	links {
		"vulkan-playground"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VPL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VPL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VPL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VPL_DIST"
		optimize "On"