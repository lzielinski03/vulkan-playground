workspace "vulkan-playground"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "vulkan-playground"
	location "vulkan-playground"
	kind "SharedLib"
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
		"vulkan-playground/src"
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