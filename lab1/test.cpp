#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Date.h"
#include "PriorityQueue.h"

Date d1(1,2,3,4,5,6);
Date d2(2023, 9, 29, 15, 5, 8);
Date d3(2023, 2, 29, 4, 5, 6);
Date d4(2023, 2, 28, 4, 5, 6);
Date d5(1900, 0, 0, 0, 0, 0);
Date d6(231, 232, 33223, 412, 60, 60);
Date d7(1871, 21, 3, 4, 5, 6);
Date d8(1871, 12, 13, 14, 15, 16);
Date d9(2020, 2, 3, 4, 5, 6);
Date d10(2020, 2, 29, 40, 56, 7);
Date d11(2023, 6, 9, 15, 5, 8);
Date d12(2020, 2, 29, 40, 56, 7);
Date d13(2020, 2, 29, 40, 56, 7);
Date d14(2020, 2, 29, 40, 56, 7);

TEST_CASE("testing the bool check();") {
    CHECK(d1.check() == 1);
    CHECK(d2.check() == 1);
    CHECK(d3.check() == 0);
    CHECK(d4.check() == 1);
    CHECK(d5.check() == 0);
    CHECK(d6.check() == 0);
    CHECK(d7.check() == 0);
    CHECK(d8.check() == 1);
    CHECK(d9.check() == 1);
    CHECK(d10.check() == 1);
}

TEST_CASE("testing the int calculateDayOfWeek()") {
    CHECK(d2.calculateDayOfWeek() == 5);
    CHECK(d4.calculateDayOfWeek() == 2);
    CHECK(d8.calculateDayOfWeek() == 3);
    CHECK(d10.calculateDayOfWeek() == 6);
}

TEST_CASE("testing the int weekNumberMonth()") {
    CHECK(d2.weekNumberMonth() == 5);
    CHECK(d4.weekNumberMonth() == 4);
    CHECK(d8.weekNumberMonth() == 2);
    CHECK(d10.weekNumberMonth() == 5);
}

TEST_CASE("testing the int weekNumberYear()") {
    CHECK(d2.weekNumberYear() == 39);
    CHECK(d4.weekNumberYear() == 9);
    CHECK(d8.weekNumberYear() == 50);
    CHECK(d10.weekNumberYear() == 9);
}

TEST_CASE("testing the int weekNumberMonth2()") {
    CHECK(d2.weekNumberMonth2() == 5);
    CHECK(d4.weekNumberMonth2() == 5);
    CHECK(d8.weekNumberMonth2() == 3);
    CHECK(d10.weekNumberMonth2() == 5);
}

TEST_CASE("testing the int weekNumberYear2()") {
    CHECK(d2.weekNumberYear2() == 40);
    CHECK(d4.weekNumberYear2() == 10);
    CHECK(d8.weekNumberYear2() == 51);
    CHECK(d10.weekNumberYear2() == 9);
}

TEST_CASE("testing the LinkedListPriorityQueue") {
    LinkedListPriorityQueue<int> i;
    SUBCASE("testing the int enqueue()") {
        i.enqueue(1);
        CHECK(i.peek() == 1);
        i.enqueue(5);
        CHECK(i.peek() == 1);
        i.enqueue(0);
        CHECK(i.peek() == 0);
        i.enqueue(1000);
        CHECK(i.peek() == 0);
    }
    SUBCASE("testing the int dequeue()") {
        i.enqueue(1);
        i.enqueue(5);
        i.enqueue(0);
        i.enqueue(1000);
        i.dequeue();
        CHECK(i.peek() == 1);
        i.dequeue();
        CHECK(i.peek() == 5);
        i.dequeue();
        CHECK(i.peek() == 1000);
    }
    LinkedListPriorityQueue<string> s;
    SUBCASE("testing the string enqueue()") {
        s.enqueue("c");
        CHECK(s.peek() == "c");
        s.enqueue("ewe");
        CHECK(s.peek() == "c");
        s.enqueue("a");
        CHECK(s.peek() == "a");
        s.enqueue("jjjj");
        CHECK(s.peek() == "a");
    }
    SUBCASE("testing the string dequeue()") {
        s.enqueue("c");
        s.enqueue("ewe");
        s.enqueue("a");
        s.enqueue("jjjj");
        s.dequeue();
        CHECK(s.peek() == "c");
        s.dequeue();
        CHECK(s.peek() == "ewe");
        s.dequeue();
        CHECK(s.peek() == "jjjj");
    }
    LinkedListPriorityQueue<vector<int>> v;
    SUBCASE("testing the vector<int> enqueue()") {
        vector<int> vec = { 10, 8, 6, 4, 2, 1 };
        v.enqueue(vec);
        vec.push_back(454);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
        vec.push_back(0);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
    }
    SUBCASE("testing the int dequeue()") {
        v.enqueue(vector<int>{1,2,3,4,5,6,7});
        v.enqueue(vector<int>{1, 2, 3});
        v.enqueue(vector<int>{0, 0});
        v.enqueue(vector<int>{1, 2, 3, 4, 5, 6, 7,23});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7,23});
    }
    LinkedListPriorityQueue<Date> d;
    SUBCASE("testing the int enqueue()") {
        d.enqueue(d1);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d2);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d5);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d7);
        CHECK(d.peek().getYear() == d1.getYear());
    }
    SUBCASE("testing the int dequeue()") {
        d.enqueue(d1);
        d.enqueue(d2);
        d.enqueue(d5);
        d.enqueue(d7);
        d.dequeue();
        CHECK(d.peek().getYear() == d7.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d5.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d2.getYear());
    }
}

TEST_CASE("testing the DynamicArrayPriorityQueue") {
    DynamicArrayPriorityQueue<int> i;
    SUBCASE("testing the int enqueue()") {
        i.enqueue(1);
        CHECK(i.peek() == 1);
        i.enqueue(5);
        CHECK(i.peek() == 1);
        i.enqueue(0);
        CHECK(i.peek() == 0);
        i.enqueue(1000);
        CHECK(i.peek() == 0);
    }
    SUBCASE("testing the int dequeue()") {
        i.enqueue(1);
        i.enqueue(5);
        i.enqueue(0);
        i.enqueue(1000);
        i.dequeue();
        CHECK(i.peek() == 1);
        i.dequeue();
        CHECK(i.peek() == 5);
        i.dequeue();
        CHECK(i.peek() == 1000);
    }
    DynamicArrayPriorityQueue<string> s;
    SUBCASE("testing the string enqueue()") {
        s.enqueue("c");
        CHECK(s.peek() == "c");
        s.enqueue("ewe");
        CHECK(s.peek() == "c");
        s.enqueue("a");
        CHECK(s.peek() == "a");
        s.enqueue("jjjj");
        CHECK(s.peek() == "a");
    }
    SUBCASE("testing the string dequeue()") {
        s.enqueue("c");
        s.enqueue("ewe");
        s.enqueue("a");
        s.enqueue("jjjj");
        s.dequeue();
        CHECK(s.peek() == "c");
        s.dequeue();
        CHECK(s.peek() == "ewe");
        s.dequeue();
        CHECK(s.peek() == "jjjj");
    }
    DynamicArrayPriorityQueue<vector<int>> v;
    SUBCASE("testing the vector<int> enqueue()") {
        vector<int> vec = { 10, 8, 6, 4, 2, 1 };
        v.enqueue(vec);
        vec.push_back(454);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
        vec.push_back(0);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
    }
    SUBCASE("testing the int dequeue()") {
        v.enqueue(vector<int>{1, 2, 3, 4, 5, 6, 7});
        v.enqueue(vector<int>{1, 2, 3});
        v.enqueue(vector<int>{0, 0});
        v.enqueue(vector<int>{1, 2, 3, 4, 5, 6, 7, 23});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7, 23});
    }
    DynamicArrayPriorityQueue<Date> d;
    SUBCASE("testing the int enqueue()") {
        d.enqueue(d1);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d2);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d5);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d7);
        CHECK(d.peek().getYear() == d1.getYear());
    }
    SUBCASE("testing the int dequeue()") {
        d.enqueue(d1);
        d.enqueue(d2);
        d.enqueue(d5);
        d.enqueue(d7);
        d.dequeue();
        CHECK(d.peek().getYear() == d7.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d5.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d2.getYear());
    }
}

TEST_CASE("testing the BinarySearchTreePriorityQueue") {
    BinarySearchTreePriorityQueue<int> i;
    SUBCASE("testing the int enqueue()") {
        i.enqueue(1);
        CHECK(i.peek() == 1);
        i.enqueue(5);
        CHECK(i.peek() == 1);
        i.enqueue(0);
        CHECK(i.peek() == 0);
        i.enqueue(1000);
        CHECK(i.peek() == 0);
    }
    SUBCASE("testing the int dequeue()") {
        i.enqueue(1);
        i.enqueue(5);
        i.enqueue(0);
        i.enqueue(1000);
        i.dequeue();
        CHECK(i.peek() == 1);
        i.dequeue();
        CHECK(i.peek() == 5);
        i.dequeue();
        CHECK(i.peek() == 1000);
    }
    BinarySearchTreePriorityQueue<string> s;
    SUBCASE("testing the string enqueue()") {
        s.enqueue("c");
        CHECK(s.peek() == "c");
        s.enqueue("ewe");
        CHECK(s.peek() == "c");
        s.enqueue("a");
        CHECK(s.peek() == "a");
        s.enqueue("jjjj");
        CHECK(s.peek() == "a");
    }
    SUBCASE("testing the string dequeue()") {
        s.enqueue("c");
        s.enqueue("ewe");
        s.enqueue("a");
        s.enqueue("jjjj");
        s.dequeue();
        CHECK(s.peek() == "c");
        s.dequeue();
        CHECK(s.peek() == "ewe");
        s.dequeue();
        CHECK(s.peek() == "jjjj");
    }
    BinarySearchTreePriorityQueue<vector<int>> v;
    SUBCASE("testing the vector<int> enqueue()") {
        vector<int> vec = { 10, 8, 6, 4, 2, 1 };
        v.enqueue(vec);
        vec.push_back(454);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
        vec.push_back(0);
        v.enqueue(vec);
        CHECK(v.peek() == vector<int>{10, 8, 6, 4, 2, 1});
    }
    SUBCASE("testing the int dequeue()") {
        v.enqueue(vector<int>{1, 2, 3, 4, 5, 6, 7});
        v.enqueue(vector<int>{1, 2, 3});
        v.enqueue(vector<int>{0, 0});
        v.enqueue(vector<int>{1, 2, 3, 4, 5, 6, 7, 23});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7});
        v.dequeue();
        CHECK(v.peek() == vector<int>{1, 2, 3, 4, 5, 6, 7, 23});
    }
    BinarySearchTreePriorityQueue<Date> d;
    SUBCASE("testing the int enqueue()") {
        d.enqueue(d1);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d2);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d5);
        CHECK(d.peek().getYear() == d1.getYear());
        d.enqueue(d7);
        CHECK(d.peek().getYear() == d1.getYear());
    }
    SUBCASE("testing the int dequeue()") {
        d.enqueue(d1);
        d.enqueue(d2);
        d.enqueue(d5);
        d.enqueue(d7);
        d.dequeue();
        CHECK(d.peek().getYear() == d7.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d5.getYear());
        d.dequeue();
        CHECK(d.peek().getYear() == d2.getYear());
    }
}
