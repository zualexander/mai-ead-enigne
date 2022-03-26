add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Core/Log.cpp
        )

add_subdirectory(vendor/spdlog)
target_include_directories(Enigne PUBLIC
        includes
        includes/Enigne
        includes/Enigne/Core
        includes/Enigne/Core/Logging
        includes/Enigne/Core/Events
        includes/Enigne/Core/pch.h
        )

# precompiled headers
target_precompile_headers(Enigne
        PRIVATE
        includes/Enigne/Core/pch.h
        )


# logging library spdlog
target_link_libraries(Enigne PUBLIC spdlog)

