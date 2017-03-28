cmake_minimum_required(VERSION 3.6)
project(SFML-Father)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations")

#include_directories(Info Input RingMenu Images Fonts DialogueBox)

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Info/Info.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Info/Info.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Input/Input.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Input/Input.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Input/InputListener.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Input/InputStruct.hpp
        main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RingMenu/RingMenu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RingMenu/RingMenu.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DialogueBox/DialogueBox.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DialogueBox/DialogueBox.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ScreenManager/ScreenManager.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ScreenManager/ScreenManager.cpp)

add_executable(SFML-Father ${SOURCE_FILES})

target_link_libraries(SFML-Father -lsfml-graphics -lsfml-window -lsfml-system)