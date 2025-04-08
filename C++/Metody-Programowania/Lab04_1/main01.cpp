#include <iostream>
#include <stack>
#include "ArrayStack.h"
#include "ListStack.h"

using namespace std;

void displayStdStack(const stack<int>& s) {
    stack<int> temp = s;
    cout << "Elementy stosu (od gory): ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main() {
    
    cout << "ArrayStack: \n" << endl;
    ArrayStack arrayStack;
    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.push(3);
    arrayStack.display();
    cout << "Rozmiar: " << arrayStack.size() << endl;
    arrayStack.pop();
    cout << "Po usunieciu elementu z gory stosu:" << endl;
    arrayStack.display();
    cout << "Element ze szczytu stosu: " << arrayStack.top() << endl;
    cout << "Rozmiar: " << arrayStack.size() << endl << endl;

    cout << "ListStack: \n" << endl;
    ListStack listStack;
    listStack.push(123);
    listStack.push(456);
    listStack.push(789);
    listStack.display();
    cout << "Rozmiar: " << listStack.size() << endl;
    listStack.pop();
    cout << "Po usunieciu elementu z gory stosu:" << endl;
    listStack.display();
    cout << "Element ze szczytu stosu: " << listStack.top() << endl;
    cout << "Rozmiar: " << listStack.size() << endl << endl;

    cout << "std::stack: \n" << endl;
    stack<int> stdStack;
    stdStack.push(10);
    stdStack.push(20);
    stdStack.push(30);
    displayStdStack(stdStack);
    cout << "Rozmiar: " << stdStack.size() << endl;
    stdStack.pop();
    cout << "Po usunieciu elementu z gory stosu:" << endl;
    displayStdStack(stdStack);
    cout << "Element ze szczytu stosu: " << stdStack.top() << endl;
    cout << "Rozmiar: " << stdStack.size() << endl;

    return 0;
}