#include"Date.h"
#include"PriorityQueue.h"
#include <iostream>

using namespace std;

int main(){
    Date d1(2023,10,29,31,21,5);
    cout << d1.weekNumberMonth() << endl;
    d1.print();
}
