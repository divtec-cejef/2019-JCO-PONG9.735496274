cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT C:/libraries/SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(sfml main.cpp Planets/Planets.cpp Planets/Planets.h src/GameObject.cpp src/GameObject.h src/SpaceObject.cpp src/SpaceObject.h src/Planet.cpp src/Planet.h src/Owner.cpp src/Owner.h Bat.cpp Bat.h Ball.cpp Ball.h)
target_link_libraries(sfml sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

add_executable(src main.cpp)