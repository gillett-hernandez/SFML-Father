cmake_minimum_required(VERSION 3.6)
project(SFML-Father)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations")

set(SOURCE_FILES
    Info.cpp
    Info.hpp
    Input.cpp
    Input.hpp
    InputListener.hpp
    InputStruct.hpp
    main.cpp
    RingMenu.cpp
    RingMenu.hpp)

add_executable(SFML-Father ${SOURCE_FILES})

target_link_libraries(SFML-Father -lsfml-graphics -lsfml-window -lsfml-system)