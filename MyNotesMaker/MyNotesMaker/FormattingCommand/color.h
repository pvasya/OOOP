#ifndef COLOR_H
#define COLOR_H

#include "command.h"
#include "formatter.h"
#include <QTextEdit>

class Color : public Command {

private:
    Formatter& formatter;

public:
    Color(Formatter& formatter);
    void execute();
};

#endif // COLOR_H
