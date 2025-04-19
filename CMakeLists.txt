cmake_minimum_required(VERSION 3.10.2)

project("Ramorix Engine")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(PLATFORM_WINDOWS "Will set the defines for Windows" OFF)
option(PLATFORM_LINUX "Will set the defines for Linux" OFF)

if (PLATFORM_WINDOWS)
    message("Generating Windows defines")
    add_compile_definitions(RMX_PLATFORM_WINDOWS)
elseif(PLATFORM_LINUX)
    message("Generating Linux defines")
    add_compile_definitions(RMX_PLATFORM_LINUX)
else()
    message(FATAL_ERROR "No platform provided ! Please specify PLATFORM_WINDOWS or PLATFORM_LINUX.")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()



list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(SourceGroups)

add_subdirectory("libs/spdlog")
add_subdirectory("libs/glfw")

add_subdirectory("Core")
add_subdirectory("Client")


