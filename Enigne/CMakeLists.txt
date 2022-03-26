add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Core/Log.cpp
        src/platform/osx/OSXWindow.cpp)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)
target_link_libraries(Enigne PUBLIC glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(Enigne PUBLIC OpenGL::GL)


target_include_directories(Enigne PUBLIC
        includes
        includes/Enigne
        includes/Enigne/Core
        includes/Enigne/Core/Logging
        includes/Enigne/Core/Events
        includes/Platform/osx/
        )

# precompiled headers
target_precompile_headers(Enigne
        PRIVATE
        includes/Enigne/Core/pch.h
        )


# logging library spdlog
add_subdirectory(vendor/spdlog)
target_link_libraries(Enigne PUBLIC spdlog)

