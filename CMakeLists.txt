cmake_minimum_required(VERSION 3.26)
project(untitled)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled CppFiles/main.cpp
        CppFiles/Engine/States/Game.hpp
        CppFiles/Engine/States/Game.cpp
        CppFiles/GameObjects/Player.hpp
        CppFiles/GameObjects/Player.cpp
        CppFiles/Engine/Physics/Collider.hpp
        CppFiles/Engine/Physics/Collider.cpp
        CppFiles/Engine/Physics/Collider.cpp
        CppFiles/Engine/States/State.hpp
        CppFiles/Engine/States/State.cpp)

target_link_libraries(untitled sfml-graphics)
