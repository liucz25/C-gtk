cmake_minimum_required(VERSION 3.28)
project(exp4)

find_package(PkgConfig REQUIRED)
pkg_search_module(GTK REQUIRED gtk4)

include_directories(${GTK_INCLUDE_DIRS})

add_executable(exp4 main.cc)
target_link_libraries(exp4 ${GTK_LIBRARIES})