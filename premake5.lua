workspace "HazelGameEngine"
  architecture "x64"
  
  configurations {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
  location "Hazel"
  kind "SharedLib"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "Hazel/src/**.h",
    "Hazel/src/**.cpp"
  }

  includedirs
  {
    "%{prj.name}/vendor/spdlog/include"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "HZ_PLATFORM_WINDOWS",
      "HZ_BUILD_DLL",
    }

    postbuildcommands{"{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox-0"}

    filter "configurations:Debug"
      defines "HZ_DEBUG"  
      symbols "On"

    filter "configurations:Release"
      defines "HZ_RELEASE"  
      optimize "On"

    filter "configurations:Dist"
      defines "HZ_DIST"  
      optimize "On"


project "Sandbox"
  location "Sanbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "Sandbox-0/src/**.h",
    "Sandbox-0/src/**.cpp"
  }

  includedirs
  {
    "Hazel/vendor/spdlog/include",
    "Hazel/src"
  }

  links 
  {
    "Hazel"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

    defines
    {
      "HZ_PLATFORM_WINDOWS",
    }

  

    filter "configurations:Debug"
      defines "HZ_DEBUG"  
      symbols "On"

    filter "configurations:Release"
      defines "HZ_RELEASE"  
      optimize "On"

    filter "configurations:Dist"
      defines "HZ_DIST"  
      optimize "On"