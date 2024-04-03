#ifndef UNDERLINE_H
#define UNDERLINE_H

#include "command.h"
#include "formatter.h"
#include <QTextEdit>

class Underline : public Command {

private:
    Formatter& formatter;

public:
    Underline(Formatter& formatter);
    void execute();
};

#endif // UNDERLINE_H
