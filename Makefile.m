all: main.cpp XSystem.o XVisual.o Color.o Brush.o IColorable.o IDrawable.o XVisualObject.o ILifecycle.o IEventHandler.o XWindow.o MainWindow.o
	g++ main.cpp XSystem.o XVisual.o Color.o Brush.o IColorable.o IDrawable.o XVisualObject.o ILifecycle.o IEventHandler.o XWindow.o MainWindow.o -lX11

XSystem.o: lib/Extensions/Basic/XSystem.h lib/Extensions/Basic/XSystem.cpp
	c++ -c lib/Extensions/Basic/XSystem.h lib/Extensions/Basic/XSystem.cpp 

XVisual.o: XSystem.o lib/Extensions/Basic/XVisual.h lib/Extensions/Basic/XVisual.cpp
	c++ -c lib/Extensions/Basic/XVisual.h lib/Extensions/Basic/XVisual.cpp

Color.o: XVisual.o lib/Extensions/Common/Color.h lib/Extensions/Common/Color.cpp
	c++ -c lib/Extensions/Common/Color.h lib/Extensions/Common/Color.cpp

Brush.o: Color.o  lib/Extensions/Common/Brush.h lib/Extensions/Common/Brush.cpp
	c++ -c lib/Extensions/Common/Brush.h lib/Extensions/Common/Brush.cpp

IColorable.o: Brush.o lib/Extensions/Basic/Interfaces/IColorable.h lib/Extensions/Basic/Interfaces/IColorable.cpp
	c++ -c lib/Extensions/Basic/Interfaces/IColorable.h lib/Extensions/Basic/Interfaces/IColorable.cpp

IDrawable.o: IColorable.o lib/Extensions/Basic/Interfaces/IDrawable.h lib/Extensions/Basic/Interfaces/IDrawable.cpp
	c++ -c lib/Extensions/Basic/Interfaces/IDrawable.h lib/Extensions/Basic/Interfaces/IDrawable.cpp

XVisualObject.o: IColorable.o IDrawable.o lib/Extensions/Basic/XVisualObject.h lib/Extensions/Basic/XVisualObject.cpp
	c++ -c lib/Extensions/Basic/XVisualObject.h lib/Extensions/Basic/XVisualObject.cpp

ILifecycle.o: lib/Extensions/Basic/Interfaces/ILifecycle.h lib/Extensions/Basic/Interfaces/ILifecycle.cpp
	c++ -c lib/Extensions/Basic/Interfaces/ILifecycle.h lib/Extensions/Basic/Interfaces/ILifecycle.cpp

IEventHandler.o: lib/Extensions/Basic/Interfaces/IEventHandler.h lib/Extensions/Basic/Interfaces/IEventHandler.cpp
	c++ -c lib/Extensions/Basic/Interfaces/IEventHandler.h lib/Extensions/Basic/Interfaces/IEventHandler.cpp

XWindow.o: XVisualObject.o ILifecycle.o IEventHandler.o lib/Extensions/Basic/XWindow.h lib/Extensions/Basic/XWindow.cpp
	c++ -c lib/Extensions/Basic/XWindow.h lib/Extensions/Basic/XWindow.cpp

MainWindow.o: XWindow.o example/MainWindow.h example/MainWindow.cpp
	c++ -c example/MainWindow.h example/MainWindow.cpp

clean:
	rm *.o a.out