cmake_minimum_required(VERSION 3.26)
project(untitled)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled CppFiles/Engine/main.cpp
        CppFiles/Engine/Game.hpp
        CppFiles/Engine/Game.cpp
        CppFiles/Engine/Physics/Player.hpp
        CppFiles/GameObjects/Player.cpp
        CppFiles/Engine/Physics/Collider.hpp
        CppFiles/Engine/Physics/Collider.cpp
        CppFiles/Engine/Physics/Collider.cpp
        CppFiles/Engine/State.hpp
        CppFiles/Engine/State.cpp)

target_link_libraries(untitled sfml-graphics)
