
cmake_minimum_required(VERSION 3.21)

project(rocketcad
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include_directories(src)
include(Content.cmake)

add_definitions(
    -DROCKETCAD_VERSION="${CMAKE_PROJECT_VERSION}"
    -DROCKETCAD_VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR}
    -DROCKETCAD_VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR}
    -DROCKETCAD_VERSION_PATCH=${CMAKE_PROJECT_VERSION_PATCH}
)

add_subdirectory(src/data)
add_subdirectory(src/view)


