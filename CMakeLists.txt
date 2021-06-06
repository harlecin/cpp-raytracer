s (13 sloc) 520 Bytes
cmake_minimum_required(VERSION 3.11.3)

project(cpp_raytracer)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

include_directories(include)

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(raytracer ${project_SRCS})
target_compile_options(raytracer PRIVATE -Wall -Wextra -pedantic)