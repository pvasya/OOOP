#include"Date.h"
#include"PriorityQueue.h"
#include <iostream>

using namespace std;

int main(){
    Date d1(2023,3,19,12,21,5);
    //cout << d1.GregorianToJulian() << endl;
    d1.GregorianToJulian();
    d1.print();
    d1.JulianToGregorian();
    d1.print();
}
