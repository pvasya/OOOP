#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "date.h"

using namespace std;

template<typename T>
bool compare(T a, T b) {
    if (a < b) return true;
    return false;
}
bool compare(string a, string b) {
    if (a.compare(b) < 0) return true;
    return false;
}
template<typename T>
bool compare(vector<T> a, vector<T> b) {
    if (a < b) return true;
    return false;
}
bool compare(Date a, Date b) {
    if ((a.getYear() < b.getYear()) ||
        (a.getYear() == b.getYear() && a.getMonth() < b.getMonth())
        || (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() < b.getDay())
        || (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() == b.getDay() && a.getHour() < b.getHour()
            || (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() == b.getDay() && a.getHour() == b.getHour() && a.getMinute() < b.getMinute())
            || (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() == b.getDay() && a.getHour() == b.getHour() && a.getMinute() == b.getMinute() && a.getSecond() < b.getSecond()))) return true;
    return false;
}

template <typename T>
class PriorityQueue {
public:
    virtual void enqueue(T item) = 0;
    virtual T dequeue() = 0;
    virtual T peek() = 0;
    void generate(int count) {
        srand(time(NULL));
        if constexpr (is_same<T, int>::value || is_same<T, double>::value) {
            for (int i = 0; i < count; i++) {
                enqueue(rand() % 10000);
            }
        }
         else if constexpr (is_same<T, string>::value) {
            string letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
            string random;
            for (int i = 0; i < count; i++) {
                random = "";
                for (int j = 0; j < rand() % 100; j++) {
                    random += letters[rand() % 53];
                }
                enqueue(random);
            }
        }
        else if constexpr (is_same<T, vector<int>>::value) {
            vector<int> vec;
            for (int i = 0; i < count; i++) {
                vec.clear();
                for (int j = 0; j < rand() % 100; j++) {
                    vec.push_back(rand() % 10000);
                }
                enqueue(vec);
            }
        }
        else if constexpr (is_same<T, vector<double>>::value) {
            vector<double> vec;
            for (int i = 0; i < count; i++) {
                vec.clear();
                for (int j = 0; j < rand() % 100; j++) {
                    vec.push_back(rand() % 10000);
                }
                enqueue(vec);
            }
        }
        else if constexpr (is_same<T, vector<string>>::value) {
            string letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
            string random;
            vector<string> vec;
            for (int i = 0; i < count; i++) {
                vec.clear();
                for (int j = 0; j < rand() % 100; j++) {
                    random = "";
                    for (int k = 0; k < rand() % 100; k++) {
                        random += letters[rand() % 53];
                    }
                    vec.push_back(random);
                }
                enqueue(vec);
            }
        }
        else if constexpr (is_same<T, Date>::value) {
            for (int i = 0; i < count; i++) {
                enqueue(Date(rand() % 5000, 1 + rand() % 12, 1 + rand() % 30, rand() % 24, rand() % 60, rand() % 60));
            }
        }
    };
    virtual void print() = 0;
};

template <typename T>
class LinkedListPriorityQueue : public PriorityQueue<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T item) : data(item), next(nullptr) {}
    };

    Node* head = new Node();

public:
    LinkedListPriorityQueue() : head(nullptr) {}

    void enqueue(T item) override {
        Node* newNode = new Node(item);
        if (!head || compare(item, head->data)) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && compare(current->next->data, item)) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T dequeue() override {
        if (!head) throw "The queue is empty";
        else{
            T result = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            return result;
        }
    }

    T peek() override {
        if (!head) throw "The queue is empty";
        else return head->data;
    }

    void print() override {
        Node* current = head;
        if constexpr (is_same<T, int>::value || is_same<T, double>::value || is_same<T, string>::value) {
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
        }
        else if constexpr (is_same<T, vector<int>>::value || is_same<T, vector<double>>::value || is_same<T, vector<string>>::value) {
            while (current) {
                for (auto& i : current->data) {
                    cout << i << " ";
                }
                cout << endl;
                current = current->next;
            }
        }
        else if constexpr (is_same<T, Date>::value) {
            while (current) {
                cout << current->data.getYear() << " " << current->data.getMonth() << " " << current->data.getDay() << " " << current->data.getHour() << " " << current->data.getMinute() << " " << current->data.getSecond() << endl;
                current = current->next;
            }
        }
    }
};

template <typename T>
class DynamicArrayPriorityQueue : public PriorityQueue<T> {
private:
    vector<T> elements;

public:
    void enqueue(T item) override {
        auto it = elements.begin();
        while (it != elements.end() && compare(*it, item)) {
            it++;
        }
        elements.insert(it, item);
    }

    T dequeue() override {
        if (elements.empty()) throw "The queue is empty";
        else {
            T front = elements.front();
            elements.erase(elements.begin());
            return front;
        }
    }

    T peek() override {
        if (elements.empty()) throw "The queue is empty";
        else {
            return elements.front();
        }
    }

    void print() override {
        if constexpr (is_same<T, int>::value || is_same<T, double>::value || is_same<T, string>::value) {
            for (auto& ele : elements) {
                cout << ele << " ";
            }
            cout << endl;
        }
        else if constexpr (is_same<T, vector<int>>::value || is_same<T, vector<double>>::value || is_same<T, vector<string>>::value) {
            for (auto& ele : elements) {
                for (auto& i : ele) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
        else if constexpr (is_same<T, Date>::value) {
            for (auto& ele : elements) {
                cout << ele.getYear() <<" " << ele.getMonth() << " " << ele.getDay() << " " << ele.getHour() << " " << ele.getMinute() << " " << ele.getSecond() << endl;
            }
        }
    }
};

template <typename T>
class BinarySearchTreePriorityQueue : public PriorityQueue<T> {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T item) : data(item), left(nullptr), right(nullptr) {}
    };

    Node* root = new Node();

private:
    Node* remove(Node* node, T item) {
        if (!node) {
            return node;
        }
        if (compare(item, node->data)) {
            node->left = remove(node->left, item);
        }
        else if (compare(node->data, item)) {
            node->right = remove(node->right, item);
        }
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            T temp = findMin(node->right);
            node->data = temp;
            node->right = remove(node->right, temp);
        }
        return node;
    }

    Node* insert(Node* node, T item) {
        if (!node) {
            return new Node(item);
        }
        if (compare(item, node->data)) {
            node->left = insert(node->left, item);
        }
        else {
            node->right = insert(node->right, item);
        }
        return node;
    }

    T findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node->data;
    }

    void printInOrder(Node* node) {
        if (node) {
            printInOrder(node->left);
            if constexpr (is_same<T, int>::value || is_same<T, double>::value || is_same<T, string>::value) {
                cout << node->data << " ";
            }
            else if constexpr (is_same<T, vector<int>>::value || is_same<T, vector<double>>::value || is_same<T, vector<string>>::value) {
                for (auto& i : node->data) {
                    cout << i << " ";
                }
                cout << endl;
            }
            else if constexpr (is_same<T, Date>::value) {
                cout << node->data.getYear() << " " << node->data.getMonth() << " " << node->data.getDay() << " " << node->data.getHour() << " " << node->data.getMinute() << " " << node->data.getSecond() << std::endl;
            }
            printInOrder(node->right);
        }
    }

public:
    BinarySearchTreePriorityQueue() : root(nullptr) {}

    void enqueue(T item) override {
        if (!root) {
            root = new Node(item);
        }
        else {
            root = insert(root, item);
        }
    }

    T dequeue() override {
        if (!root) throw "The queue is empty";
        else {
            T result = findMin(root);
            root = remove(root, result);
            return result;
        }
    }

    T peek() override {
        if (!root) throw "The queue is empty";
        else return findMin(root);
    }

    void print() override {
        printInOrder(root);
    }
};
