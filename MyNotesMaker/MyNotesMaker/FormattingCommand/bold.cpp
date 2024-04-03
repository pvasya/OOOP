#include "bold.h"

Bold::Bold(Formatter& formatter) :
    formatter(formatter) {}

void Bold::execute() {
    formatter.bold();
}
