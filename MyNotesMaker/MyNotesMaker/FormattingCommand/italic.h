#ifndef ITALIC_H
#define ITALIC_H

#include "../mainwindow.h"
#include "command.h"

class Italic : public Command {

private:
    MainWindow& mainWindow;

public:
    Italic(MainWindow& mainWindow);
    void execute();
};
#endif // ITALIC_H
