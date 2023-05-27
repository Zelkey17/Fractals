cmake_minimum_required(VERSION 3.23)
project(Fractals)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(SFML 2.5 COMPONENTS graphics audio network system window REQUIRED)
add_definitions(-lsfml-graphics -lsfml-window -lsfml-system -Wall -Wextra -Wpedantic)

add_executable(Fractals
        main.cpp
        MainWindow.cpp
        MainWindow.h
        Complex.cpp Complex.h)
target_link_libraries(Fractals sfml-graphics sfml-audio sfml-network sfml-window sfml-system)