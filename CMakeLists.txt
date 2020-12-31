cmake_minimum_required(VERSION 3.17)
project(OOPGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOPGame main.cpp Headers/Player.h CPPs/Player.cpp Headers/Weapons.h CPPs/Weapons.cpp Headers/Opponent.h CPPs/Opponent.cpp Headers/Fight.h Headers/Status.h CPPs/Status.cpp CPPs/Fight.cpp Headers/Choice.h CPPs/Choice.cpp Headers/Stick.h CPPs/Stick.cpp Headers/Sword.h CPPs/Sword.cpp)