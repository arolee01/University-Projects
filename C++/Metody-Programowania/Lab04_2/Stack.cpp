#include "Stack.h"

using namespace std;

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::push(const string& val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

string Stack::pop() {
    if (isEmpty()) {
        throw ("Nie mo¿na usun¹æ elementu z pustego stosu");
    }

    Node* temp = top;
    string value = temp->value;
    top = top->next;
    delete temp;

    return value;
}

string Stack::peek() const {
    if (isEmpty()) {
        throw ("Nie mo¿na odczytaæ elementu z pustego stosu");
    }
    return top->value;
}