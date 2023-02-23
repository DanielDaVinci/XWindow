cmake_minimum_required(VERSION 3.23)
project(XWindow)

set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_CXX_FLAGS_DEBUG "-lX11")

add_executable(XWindow main.cpp lib/Extensions/XWindow/XWindow.cpp lib/Extensions/XWindow/XWindow.h)
