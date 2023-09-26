
cmake_minimum_required(VERSION 3.21)

project(rocketcad
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include_directories(src)

add_subdirectory(src/data)
add_subdirectory(src/view)


