#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "HuffmanNode.h"
#include <vector>

/*
* Klasa kolejki priorytetowej
*/
class PriorityQueue {
private:
    std::vector<HuffmanNode*> nodes;  // Przechowuje ga³êzie w wektorze

    void heapifyUp();    // Do góry
    void heapifyDown();  // W dó³

public:
    // Dodaje now¹ ga³¹Ÿ
    void push(HuffmanNode* node);

    // Wyjmuje ga³¹Ÿ z najmniejsz¹ wartoœci¹
    HuffmanNode* pop();

    // Sprawdza czy kolejka jest pusta
    bool empty() const;

    // Zwraca rozmiar kolejki
    size_t size() const;

};

#endif