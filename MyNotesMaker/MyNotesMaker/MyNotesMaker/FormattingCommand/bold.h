#ifndef BOLD_H
#define BOLD_H

#include <QtWidgets/QTextEdit>
#include "command.h"
#include "formatter.h"

class Bold : public Command {

private:
    Formatter& formatter;

public:
    Bold(Formatter& formatter);
    void execute() override;
};

#endif // BOLD_H
