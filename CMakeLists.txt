cmake_minimum_required(VERSION 3.6)
project(SFML-Father)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations")

set(SOURCE_FILES
    Info/Info.cpp
    Info/Info.hpp
    Input/Input.cpp
    Input/Input.hpp
    Input/InputListener.hpp
    Input/InputStruct.hpp
    main.cpp
    RingMenu/RingMenu.cpp
    RingMenu/RingMenu.hpp
    RingMenu/RingMenuItem.cpp
    RingMenu/RingMenuItem.hpp
    DialogueBox/DialogueBox.cpp
    DialogueBox/DialogueBox.hpp
    TextureManager/TextureManager.cpp
    TextureManager/TextureManager.hpp
    Alarm/Alarm.cpp
    Alarm/Alarm.hpp
    Alarm/AlarmListener.hpp
    Alarm/AlarmManager.cpp
    Alarm/AlarmManager.hpp)

add_executable(SFML-Father ${SOURCE_FILES})

target_link_libraries(SFML-Father -lsfml-graphics -lsfml-window -lsfml-system)