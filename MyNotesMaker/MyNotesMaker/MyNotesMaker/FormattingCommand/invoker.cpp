#include "invoker.h"

void Invoker::addCommand(Command* cmd)
{
    commands.push_back(cmd);
}

void Invoker::startCommand(int slot)
{
    if (slot >= 0 && slot < commands.size()) {
        commands[slot]->execute();
    }
}
