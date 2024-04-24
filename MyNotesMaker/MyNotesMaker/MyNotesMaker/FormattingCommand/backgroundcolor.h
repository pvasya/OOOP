#ifndef BACKGROUNDCOLOR_H
#define BACKGROUNDCOLOR_H

#include "command.h"
#include "formatter.h"

class BackgroundColor : public Command {

private:
    Formatter& formatter;

public:
    BackgroundColor(Formatter& formatter);
    void execute() override;
};

#endif // BACKGROUNDCOLOR_H
