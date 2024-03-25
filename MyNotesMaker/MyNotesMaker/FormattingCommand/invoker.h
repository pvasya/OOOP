#ifndef INVOKER_H
#define INVOKER_H

#include "command.h"
#include <QVector>

class Invoker
{
private:
    QVector<Command*> commands;
    static Invoker* instance;

    Invoker() = default;
    ~Invoker() = default;

public:
    static Invoker& getInstance();

    void addCommand(Command* cmd);
    void startCommand(int slot);
};

#endif // INVOKER_H
