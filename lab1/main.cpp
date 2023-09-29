#include"date.h"
#include"priority_queue.h"
#include <iostream>

using namespace std;

int main(){
    Date d1(2023,9,28,12,21,5);
    d1.print();
    d1.GregorianToJulian();
    d1.print();
    d1.JulianToGregorian();
    d1.print();
    d1.printAlternative();
}
