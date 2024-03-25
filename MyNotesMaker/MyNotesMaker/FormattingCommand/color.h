#ifndef COLOR_H
#define COLOR_H

#include "../mainwindow.h"
#include "command.h"

class Color : public Command {

private:
    MainWindow& mainWindow;

public:
    Color(MainWindow& Color);
    void execute();
};

#endif // COLOR_H
