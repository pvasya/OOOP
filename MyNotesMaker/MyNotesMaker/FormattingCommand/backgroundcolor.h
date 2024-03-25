#ifndef BACKGROUNDCOLOR_H
#define BACKGROUNDCOLOR_H

#include "../mainwindow.h"
#include "command.h"

class BackgroundColor : public Command {

private:
    MainWindow& mainWindow;

public:
    BackgroundColor(MainWindow& BackgroundColor);
    void execute();
};

#endif // BACKGROUNDCOLOR_H
