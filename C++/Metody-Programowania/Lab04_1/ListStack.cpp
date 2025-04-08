#include "ListStack.h"
#include <stdexcept>
#include <iostream>
using namespace std;

ListNode::ListNode(int val) : value(val), next(nullptr) {}

ListStack::ListStack() : head(nullptr), stackSize(0) {}

ListStack::~ListStack() {
    while (!isEmpty()) {
        pop();
    }
}

bool ListStack::isEmpty() const {
    return head == nullptr;
}

int ListStack::size() const {
    return stackSize;
}

int ListStack::top() const {
    if (isEmpty()) {
        throw out_of_range("Stos jest pusty");
    }
    return head->value;
}

void ListStack::push(int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
    stackSize++;
}

void ListStack::pop() {
    if (isEmpty()) {
        throw out_of_range("Stos jest pusty");
    }
    ListNode* temp = head;
    head = head->next;
    delete temp;
    stackSize--;
}

void ListStack::display() const {
    cout << "Elementy stosu (od gory): ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}