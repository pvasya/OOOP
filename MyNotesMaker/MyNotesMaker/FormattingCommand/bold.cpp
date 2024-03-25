#include "bold.h"
#include "../mainwindow.h"

Bold::Bold(MainWindow& mainWindow) :
    mainWindow(mainWindow) {}

void Bold::execute() {
    mainWindow.Bold();
}
