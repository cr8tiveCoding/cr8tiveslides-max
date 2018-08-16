cmake_minimum_required(VERSION 3.5)
project(CreativeSlides)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(CreativeSlides main.cpp)
target_link_libraries(CreativeSlides sfml-graphics)