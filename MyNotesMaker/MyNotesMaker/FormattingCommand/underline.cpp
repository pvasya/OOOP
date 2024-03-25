#include "underline.h"

Underline::Underline(MainWindow &mainWindow) : mainWindow(mainWindow)
{

}

void Underline::execute()
{
    mainWindow.Underline();
}
