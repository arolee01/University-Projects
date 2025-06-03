#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H


/*
 * Struktura reprezentuj¹ca ga³¹Ÿ drzewa Huffmana
 * @param symbol Znak przechowywany w ga³êzi
 * @param value Czêstotliwoœæ lub prawdopodobieñstwo wyst¹pienia symbolu
 * @param left WskaŸnik do lewego dziecka
 * @param right WskaŸnik do prawego dziecka
 */
struct HuffmanNode {
    char symbol;
    double value;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char s, double v)
        : symbol(s), value(v), left(nullptr), right(nullptr) {
    }
};

#endif
