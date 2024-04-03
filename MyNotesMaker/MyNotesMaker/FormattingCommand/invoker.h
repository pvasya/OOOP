#ifndef INVOKER_H
#define INVOKER_H

#include "command.h"
#include <QVector>

class Invoker
{
private:
    QVector<Command*> commands;
    static Invoker* instance;

protected:
    Invoker() {}
public:
    static Invoker& get(){
        static Invoker invoker;
        return invoker;
    }
    Invoker(Invoker const&) = delete;
    Invoker(Invoker&&) = delete;
    Invoker& operator=(Invoker const&) = delete;
    Invoker& operator=(Invoker &&) = delete;

    void addCommand(Command* cmd);
    void startCommand(int slot);
};

#endif // INVOKER_H
