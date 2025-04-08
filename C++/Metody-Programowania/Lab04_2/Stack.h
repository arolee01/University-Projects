#ifndef STACK_H
#define STACK_H

#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Klasa implementuj¹ca stos na potrzeby konwersji wyra¿eñ
 * @details Prosta implementacja stosu oparta na liœcie jednokierunkowej
 */
class Stack {
private:
    struct Node {
        string value;
        Node* next;
        
        Node(const string& val) : value(val), next(nullptr) {}
    };
    
    Node* top;

public:
    /**
     * @brief Konstruktor - inicjalizuje pusty stos
     */
    Stack();
    
    /**
     * @brief Destruktor - zwalnia ca³¹ zaalokowan¹ pamiêæ
     */
    ~Stack();
    
    /**
     * @brief Sprawdza czy stos jest pusty
     * @return true jeœli stos jest pusty, false w przeciwnym przypadku
     */
    bool isEmpty() const;
    
    /**
     * @brief Dodaje element na szczyt stosu
     * @param val Wartoœæ do dodania
     */
    void push(const string& val);
    
    /**
     * @brief Zdejmuje i zwraca element ze szczytu stosu
     * @return Wartoœæ elementu ze szczytu
     * @throws runtime_error jeœli stos jest pusty
     */
    string pop();
    
    /**
     * @brief Zwraca element ze szczytu stosu bez jego usuwania
     * @return Wartoœæ elementu ze szczytu
     * @throws runtime_error jeœli stos jest pusty
     */
    string peek() const;
};

#endif // STACK_H