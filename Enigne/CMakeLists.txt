add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Log.cpp
        )

add_subdirectory(vendor/spdlog)
target_include_directories(Enigne PUBLIC includes/Enigne includes/)

target_link_libraries(Enigne PUBLIC spdlog)
