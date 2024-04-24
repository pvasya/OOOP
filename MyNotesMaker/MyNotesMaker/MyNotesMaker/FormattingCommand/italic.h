#ifndef ITALIC_H
#define ITALIC_H

#include "command.h"
#include "formatter.h"
#include <QTextEdit>

class Italic : public Command {

private:
    Formatter& formatter;

public:
    Italic(Formatter& formatter);
    void execute();
};
#endif // ITALIC_H
