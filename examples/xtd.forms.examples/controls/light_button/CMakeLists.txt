cmake_minimum_required(VERSION 3.3)

project(light_button)
find_package(xtd REQUIRED)
add_sources(src/light_button.cpp)
target_type(GUI_APPLICATION)
