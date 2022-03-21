add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Core/Log.cpp
        )

add_subdirectory(vendor/spdlog)
target_include_directories(Enigne PUBLIC 
includes/
includes/Enigne /
includes/Enigne/Core/
)

target_link_libraries(Enigne PUBLIC spdlog)
