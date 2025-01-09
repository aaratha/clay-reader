cmake_minimum_required(VERSION 3.27)
project(clay)

# Add the cmake modules path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configure raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# Include directories
include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Main executable
add_executable(clay_main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_include_directories(clay_main PUBLIC .)
target_link_libraries(clay_main PUBLIC raylib)

# Set compiler flags
set(CMAKE_C_FLAGS_DEBUG "-Wall -Werror -Wno-error=missing-braces -DCLAY_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# If you have resources to copy, uncomment and modify this:
# add_custom_command(
#     TARGET clay_main POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_CURRENT_SOURCE_DIR}/resources
#     ${CMAKE_CURRENT_BINARY_DIR}/resources
# )
