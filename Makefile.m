all: main.cpp XWindow.o Color.o MainWindow.o
	c++ main.cpp XWindow.o Color.o MainWindow.o -lX11

XWindow.o: lib/Extensions/XWindow/XWindow.h lib/Extensions/XWindow/XWindow.cpp
	c++ -c lib/Extensions/XWindow/XWindow.h lib/Extensions/XWindow/XWindow.cpp

Color.o: lib/Extensions/Common/Color.h lib/Extensions/Common/Color.cpp
	c++ -c lib/Extensions/Common/Color.h lib/Extensions/Common/Color.cpp

MainWindow.o: example/MainWindow.h example/MainWindow.cpp
	c++ -c example/MainWindow.h example/MainWindow.cpp

clean:
	rm *.o a.out