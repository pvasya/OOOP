#ifndef BOLD_H
#define BOLD_H

#include "../mainwindow.h"
#include "command.h"

class Bold : public Command {

private:
    MainWindow& mainWindow;

public:
    Bold(MainWindow& mainWindow);
    void execute();
};

#endif // BOLD_H
