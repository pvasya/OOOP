#include "color.h"

Color::Color(Formatter& formatter) : formatter(formatter)
{

}

void Color::execute()
{
    formatter.color();
}
