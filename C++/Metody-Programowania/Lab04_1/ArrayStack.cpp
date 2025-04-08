#include "ArrayStack.h"
#include <stdexcept>
#include <iostream>

ArrayStack::ArrayStack() : capacity(10), topIndex(-1) {
    array = new int[capacity];
}

ArrayStack::~ArrayStack() {
    delete[] array;
}

bool ArrayStack::isEmpty() const {
    return topIndex == -1;
}

int ArrayStack::size() const {
    return topIndex + 1;
}

int ArrayStack::top() const {
    if (isEmpty()) {
        throw out_of_range("Stos jest pusty");
    }
    return array[topIndex];
}

void ArrayStack::push(int value) {
    if (topIndex == capacity - 1) {
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i <= topIndex; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
    array[++topIndex] = value;
}

void ArrayStack::pop() {
    if (isEmpty()) {
        throw out_of_range("Stos jest pusty");
    }
    topIndex--;
}

void ArrayStack::display() const {
    cout << "Elementy stosu (od gory): ";
    for (int i = topIndex; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
}