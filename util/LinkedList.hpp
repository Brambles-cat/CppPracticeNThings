#include "Node.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class LinkedList {
    Node<T> *head = nullptr, *tail = nullptr, *current = nullptr;
    int listSize = 0;

    public:
    LinkedList<T>() {}

    void add(T nodeData) {

        if (head == nullptr) {
            head = new Node<T>(nodeData);
            tail = head;
            current = head;

        } else {
            Node<T> *newTail = new Node<T>(nodeData);
            (*tail).next = newTail;
            tail = newTail;

        }
        ++listSize;
    }

    void printContents() {
        Node<T> *current = head;
        
        while (current != nullptr) {
            cout << (*current).getValue() << " ";
            current = (*current).next;
        }
    }

    T& get(int index) {
        if (head == nullptr) throw runtime_error("List is Empty");
        if (index + 1 > listSize) throw runtime_error("index out of bounds for this list");

        int curIndex = 0;
        Node<T> *currentNode = head;

        while(curIndex++ < index) {
            currentNode = (*currentNode).next;
        }
        
        return (*currentNode).getValue();
    }

    T& getFirst() {
        if (isEmpty()) throw runtime_error("List is empty");
        return (*head).getValue();
    }

    T& getLast() {
        if (isEmpty()) throw runtime_error("List is empty");
        return (*tail).getValue();
    }

    bool isEmpty() {return head == nullptr;}

    bool hasNext();
    
    int size() {return listSize;}
};