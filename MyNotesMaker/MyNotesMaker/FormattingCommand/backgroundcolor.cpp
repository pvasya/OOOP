#include "backgroundcolor.h"

BackgroundColor::BackgroundColor(MainWindow &mainWindow) : mainWindow(mainWindow)
{

}

void BackgroundColor::execute()
{
    mainWindow.BackgroundColor();
}
