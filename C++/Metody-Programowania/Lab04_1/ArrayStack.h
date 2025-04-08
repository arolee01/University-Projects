#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

using namespace std;

/*
 * Implementacja stosu przy u¿yciu tablicy dynamicznej
 */
class ArrayStack {
private:
    int* array;
    int capacity;
    int topIndex;

public:
    ArrayStack();
    ~ArrayStack();

    /*
     * Sprawdza czy stos jest pusty
     * @return true jeœli stos jest pusty, false w przeciwnym przypadku
     */
    bool isEmpty() const;

    /*
     * Zwraca liczbê elementów na stosie
     * @return liczba elementów na stosie
     */
    int size() const;

    /*
     * Zwraca wartoœæ elementu na szczycie stosu
     * @return wartoœæ szczytowego elementu
     * @throw out_of_range jeœli stos jest pusty
     */
    int top() const;

    /*
     * Dodaje element na szczyt stosu
     * @param value wartoœæ do dodania
     */
    void push(int value);

    /*
     * Usuwa element ze szczytu stosu
     * @throw out_of_range jeœli stos jest pusty
     */
    void pop();

    /*
     * Wyœwietla zawartoœæ stosu od góry do do³u
     */
    void display() const;
};

#endif