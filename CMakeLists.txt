cmake_minimum_required(VERSION 3.23)
project(XWindow)

set(CMAKE_CXX_STANDARD 20)

add_executable(XWindow main.cpp lib/Extensions/Basic/XWindow.cpp lib/Extensions/Basic/XWindow.h lib/Extensions/Common/Color.cpp lib/Extensions/Common/Color.h example/MainWindow.cpp example/MainWindow.h lib/Extensions/Basic/Interfaces/IDrawable.cpp lib/Extensions/Basic/Interfaces/IDrawable.h lib/Extensions/Basic/Interfaces/IColorable.cpp lib/Extensions/Basic/Interfaces/IColorable.h lib/Extensions/Basic/XVisualObject.cpp lib/Extensions/Basic/XVisualObject.h lib/Extensions/Common/Brush.cpp lib/Extensions/Common/Brush.h lib/Extensions/Basic/XVisual.cpp lib/Extensions/Basic/XVisual.h lib/Extensions/Basic/XSystem.cpp lib/Extensions/Basic/XSystem.h lib/Extensions/Basic/Interfaces/ILifecycle.cpp lib/Extensions/Basic/Interfaces/ILifecycle.h lib/Extensions/Basic/Interfaces/IEventHandler.cpp lib/Extensions/Basic/Interfaces/IEventHandler.h)
