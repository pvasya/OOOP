#include "italic.h"

Italic::Italic(Formatter& formatter) :
    formatter(formatter) {}

void Italic::execute() {
    formatter.italic();
}
