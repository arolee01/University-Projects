#include "HuffmanTree.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

HuffmanNode* buildHuffmanTree(const vector<pair<char, double>>& symbols) {
    if (symbols.empty()) {
        throw MyException("Brak symboli do zakodowania!");
    }

    PriorityQueue pq;

    cout << "Dodaje symbole do kolejki:" << endl;
    // Dodaje symbole do kolejki jako liœcie drzewa
    for (const auto& pair : symbols) {
        cout << pair.first << ": " << pair.second << endl;
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
    cout << endl;

    // L¹czenie ga³êzi a¿ do uzyskania jednego korzenia
    while (pq.size() > 1) {
        // Pobiera dwie ga³êzie o najmniejszych czêstotliwoœciach
        HuffmanNode* first = pq.pop();
        HuffmanNode* second = pq.pop();

        cout << "Lacze galezie: ";
        // Wyœwietlanie informacji o ³¹czonych ga³êziach
        if (first->symbol != '\0') {
            cout << first->symbol;
        }
        else {
            cout << "galaz";
        }
        cout << " (w:" << first->value << ") + ";
        if (second->symbol != '\0') {
            cout << second->symbol;
        }
        else {
            cout << "galaz";
        }
        cout << " (w:" << second->value << ") = " << (first->value + second->value) << endl;

        // Tworzenie nowej ga³êzi-rodzica o sumie czêstotliwoœci
        HuffmanNode* parent = new HuffmanNode('\0', first->value + second->value);

        // Podpinanie ga³êzi jako dzieci
        parent->left = first;
        parent->right = second;

        // Dodawanie nowej ga³êzi z powrotem do kolejki
        pq.push(parent);
    }
    cout << endl;

    // Zwraca korzeñ drzewa Huffmana
    return pq.pop();
}

void generateHuffmanCodes(HuffmanNode* root, const string& code,
    vector<pair<char, string>>& codes) {
    if (!root) return;

    // Jeœli trafi na liœæ (symbol), zapisuje jego kod
    if (root->symbol != '\0') {
        // W przypadku gdy jest tylko jeden symbol, ustawia kod "0"
        codes.push_back({ root->symbol, code.empty() ? "0" : code });
        return;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

void printCodes(const vector<pair<char, string>>& codes) {
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void processVector(vector<pair<char, double>> symbols) {
    try {
        HuffmanNode* root = buildHuffmanTree(symbols);
        vector<pair<char, string>> codes;
        generateHuffmanCodes(root, "", codes);
        cout << "Wygenerowane kody:" << endl;
        printCodes(codes);
        cout << endl;
    }
    catch (const MyException& e) {
        cout << "Blad: " << e.what() << endl;
    }
}