cmake_minimum_required(VERSION 3.26)
project(untitled)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled CppFiles/GameExec/main.cpp
        HeaderFiles/Game.hpp
        CppFiles/GameExec/Game.cpp
        HeaderFiles/Player.hpp
        CppFiles/GameObjects/Player.cpp
        HeaderFiles/Collider.hpp
        CppFiles/Physics/Collider.cpp
        CppFiles/Physics/Collider.cpp)

target_link_libraries(untitled sfml-graphics)
