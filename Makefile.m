all: main.cpp XWindow.o
	c++ main.cpp XWindow.o -lX11

XWindow.o: lib/Extensions/XWindow/XWindow.h lib/Extensions/XWindow/XWindow.cpp
	c++ -c lib/Extensions/XWindow/XWindow.h lib/Extensions/XWindow/XWindow.cpp

clean:
	rm *.o a.out