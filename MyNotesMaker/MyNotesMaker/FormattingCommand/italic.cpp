#include "italic.h"

Italic::Italic(MainWindow &mainWindow) : mainWindow(mainWindow)
{

}

void Italic::execute()
{
    mainWindow.Italic();
}
