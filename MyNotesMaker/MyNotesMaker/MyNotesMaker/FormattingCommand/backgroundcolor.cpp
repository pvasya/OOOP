#include "backgroundcolor.h"

BackgroundColor::BackgroundColor(Formatter &formatter) : formatter(formatter)
{

}

void BackgroundColor::execute()
{
    formatter.backgroundColor();
}
