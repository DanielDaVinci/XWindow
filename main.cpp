#include <iostream>

#include "lib/Extensions/Basic/XWindow.h"
#include "example/MainWindow.h"
#include "lib/Extensions/Common/Brush.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Arguments must be more" << endl;
        exit(1);
    }
    MainWindow window(argv[1], 0, 0, 1000, 600);
    window.Open();

    return 0;
}
