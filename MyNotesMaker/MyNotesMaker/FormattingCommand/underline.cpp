#include "underline.h"

Underline::Underline(Formatter& formatter) : formatter(formatter)
{

}

void Underline::execute()
{
    formatter.underline();
}
