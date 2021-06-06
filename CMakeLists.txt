cmake_minimum_required(VERSION 3.11.3)

project(cpp_raytracer)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

include_directories(include)
find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIRS})

# Find all executables
file(GLOB project_SRCS src/*.cpp)

# Add project executable
add_executable(raytracer ${project_SRCS})
target_link_libraries(raytracer ${X11_LIBRARIES})
target_compile_options(raytracer PRIVATE -Wall -Wextra -pedantic)
