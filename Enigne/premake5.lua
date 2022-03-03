workspace "Enigne"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Enigne"
	location "Enigne"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"EN_PLATFORM_WINDOWS",
			"EN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EN_DIST"
		optimize "On"

project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
			
		targetdir("bin/" .. outputdir .. "%{prj.name}")
		objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include;",
		"Enigne/src"
	}

	links
	{
		"Enigne"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"EN_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "EN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EN_DIST"
		optimize "On"