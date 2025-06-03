#include "PriorityQueue.h"

using namespace std;

// Przywracanie porz¹dku gdy dodaje element
void PriorityQueue::heapifyUp() {
    int index = nodes.size() - 1;  // Zaczyna od ostatniego

    while (index > 0) {
        int parent = (index - 1) / 2;  // Pozycja rodzica
        // Sprawdza czy dziecko jest mniejsze od rodzica
        if (nodes[index]->value >= nodes[parent]->value) break;
        swap(nodes[index], nodes[parent]);  // Zamienia jeœli trzeba
        index = parent;
    }
}

// Przywracanie porz¹dku gdy usuwa element
void PriorityQueue::heapifyDown() {
    int index = 0;

    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // Szukanie najmniejsszego dziecka
        if (left < nodes.size() && nodes[left]->value < nodes[smallest]->value)
            smallest = left;
        if (right < nodes.size() && nodes[right]->value < nodes[smallest]->value)
            smallest = right;

        if (smallest == index) break;

        swap(nodes[index], nodes[smallest]);
        index = smallest;
    }
}

// Dodaje element do kolejki
void PriorityQueue::push(HuffmanNode* node) {
    if (node == nullptr) return;  // Sprawdza czy wêze³ nie jest pusty
    nodes.push_back(node);
    heapifyUp();
}

// Wyjmuje najmniejszy element
HuffmanNode* PriorityQueue::pop() {
    if (empty()) return nullptr;

    HuffmanNode* result = nodes[0];  // Zapamiêtuje pierwszy (najmniejszy)
    nodes[0] = nodes.back();         // Ostatni daje na pocz¹tek
    nodes.pop_back();                // Usuwa ostatni

    if (!empty()) {  // Jeœli pozosta³ jeszcze jakiœ element
        heapifyDown();
    }

    return result;
}

bool PriorityQueue::empty() const {
    return nodes.empty();
}

size_t PriorityQueue::size() const {
    return nodes.size();
}