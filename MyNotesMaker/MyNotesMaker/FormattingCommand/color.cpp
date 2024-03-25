#include "color.h"

Color::Color(MainWindow &mainWindow) : mainWindow(mainWindow)
{

}

void Color::execute()
{
    mainWindow.Color();
}
