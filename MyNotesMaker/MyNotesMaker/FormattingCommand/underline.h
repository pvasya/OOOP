#ifndef UNDERLINE_H
#define UNDERLINE_H

#include "../mainwindow.h"
#include "command.h"

class Underline : public Command {

private:
    MainWindow& mainWindow;

public:
    Underline(MainWindow& mainWindow);
    void execute();
};

#endif // UNDERLINE_H
