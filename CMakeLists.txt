cmake_minimum_required(VERSION 3.5)
project(demo)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(logger)

set(SOURCES 
main.cpp
)
add_executable(demo ${SOURCES})

target_link_libraries(demo PRIVATE logger)

# Use this to compile 3rd party libraries placed in a folder called "include/"
target_include_directories(demo PRIVATE include)