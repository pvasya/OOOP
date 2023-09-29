#include"Date.h"
#include"PriorityQueue.h"
#include <iostream>

using namespace std;

int main(){
    Date d1(2023, 9, 29, 11, 10, 14);
    d1.print();
    d1.printAlternative();
    cout << d1.check() << endl;
    d1.add(1,1,1,1,1,1);
    d1.subtract(1, 2, 3, 4, 5, 6);
    d1.print();
    d1.printAlternative();
    cout<< d1.calculateDayOfWeek() << endl;
    cout << d1.weekNumberMonth() << endl;
    cout << d1.weekNumberYear() << endl;
    cout << d1.weekNumberMonth2() << endl;
    cout << d1.weekNumberYear2() << endl;
    d1.GregorianToJulian();
    d1.print();
    d1.JulianToGregorian();
    d1.print();
    cout << endl;

    Date d2;
    d2.print();
    d2.printAlternative();
    cout << d2.check() << endl;
    d2.add(1, 1, 1, 1, 1, 1000000000);
    d2.subtract(10, 2, 3, 4, 5, 6);
    d2.print();
    d1.printAlternative();
    cout << d2.calculateDayOfWeek() << endl;
    cout << d2.weekNumberMonth() << endl;
    cout << d2.weekNumberYear() << endl;
    cout << d2.weekNumberMonth2() << endl;
    cout << d2.weekNumberYear2() << endl;
    d2.GregorianToJulian();
    d2.print();
    d2.JulianToGregorian();
    d2.print();
    cout << endl;

    Date d3;
    d3.print();
    d3.printAlternative();
    cout << d3.check() << endl;
    d3.add(1, 1, 1, 1, 1, 1000000000);
    d3.subtract(10, 2, 3, 4, 5, 6);
    d3.print();
    d3.printAlternative();
    cout << d3.calculateDayOfWeek() << endl;
    cout << d3.weekNumberMonth() << endl;
    cout << d3.weekNumberYear() << endl;
    cout << d3.weekNumberMonth2() << endl;
    cout << d3.weekNumberYear2() << endl;
    d3.GregorianToJulian();
    d3.print();
    d3.JulianToGregorian();
    d3.print();
    cout << endl;

    LinkedListPriorityQueue<int> l1;
    l1.generate(10);
    l1.print();
    l1.enqueue(100000);
    l1.dequeue();
    cout << endl;
    l1.print();
    l1.writeToFile("l1");
    cout << endl;
    LinkedListPriorityQueue<int> l2;
    l2.readFromFile("l1");
    l2.print();
    cout << endl << endl << endl;

    LinkedListPriorityQueue<Date> l3;
    l3.generate(10);
    l3.print();
    l3.enqueue(d1);
    l3.enqueue(d2);
    l3.enqueue(d3);
    l3.dequeue();
    cout << endl;
    l3.print();
    l3.writeToFile("l3");
    cout << endl;
    LinkedListPriorityQueue<Date> l4;
    l4.readFromFile("l3");
    l4.print();
    cout << endl << endl << endl << endl << endl;

    DynamicArrayPriorityQueue<int> a1;
    a1.generate(10);
    a1.print();
    a1.enqueue(100000);
    a1.dequeue();
    cout << endl;
    a1.print();
    a1.writeToFile("a1");
    cout << endl;
    DynamicArrayPriorityQueue<int> a2;
    a2.readFromFile("a1");
    a2.print();
    cout << endl;
    cout << endl;
    cout << endl;

    DynamicArrayPriorityQueue<Date> a3;
    a3.generate(10);
    a3.print();
    a3.enqueue(d1);
    a3.enqueue(d2);
    a3.enqueue(d3);
    a3.dequeue();
    cout << endl;
    a3.print();
    a3.writeToFile("a3");
    cout << endl;
    DynamicArrayPriorityQueue<Date> a4;
    a4.readFromFile("a3");
    a4.print();
    cout << endl << endl << endl << endl << endl;

    BinarySearchTreePriorityQueue<int> b1;
    b1.generate(10);
    b1.print();
    b1.enqueue(100000);
    b1.dequeue();
    cout << endl;
    b1.print();
    b1.writeToFile("b1");
    cout << endl;
    BinarySearchTreePriorityQueue<int> b2;
    b2.readFromFile("b1");
    b2.print();
    cout << endl;
    cout << endl;
    cout << endl;

    BinarySearchTreePriorityQueue<Date> b3;
    b3.generate(10);
    b3.print();
    b3.enqueue(d1);
    b3.enqueue(d2);
    b3.enqueue(d3);
    b3.dequeue();
    cout << endl;
    b3.print();
    b3.writeToFile("b3");
    cout << endl;
    BinarySearchTreePriorityQueue<Date> b4;
    b4.readFromFile("b3");
    b4.print();
    return 0;
}
