add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Log.cpp
        )

target_include_directories(Enigne PUBLIC includes/Enigne includes/)

find_package(spdlog REQUIRED)
target_link_libraries(Enigne PUBLIC spdlog::spdlog)
