cmake_minimum_required(VERSION 3.3)

project(month_calendar)
find_package(xtd REQUIRED)
add_sources(src/month_calendar.cpp)
target_type(GUI_APPLICATION)
