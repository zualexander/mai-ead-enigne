include_directories(
	/usr/local/lib ## update to your location where spdlog was installed
	)

add_library(Enigne
        src/Enigne/Application.cpp
        src/Enigne/Log.cpp
        )

target_include_directories(Enigne PUBLIC src/Enigne src/)

find_package(spdlog REQUIRED)
target_link_libraries(Enigne PUBLIC spdlog::spdlog)
