cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT C:/libraries/SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
add_executable(sfml main.cpp Bat.cpp Bat.h Ball.cpp Ball.h GameObject.cpp GameObject.h Gauge.cpp Gauge.h ScoreViewer.cpp ScoreViewer.h)
target_link_libraries(sfml sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

add_executable(src main.cpp)