#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <vector>
#include <string>
#include <stdexcept>
#include "HuffmanNode.h"
#include "PriorityQueue.h"
#include "MyException.h"

using namespace std;

/*
 * Buduje drzewo Huffmana na podstawie symboli i ich wartoœci (czêstotliwoœci/prawdopodobieñstwa)
 * @param symbols Wektor par (symbol, wartoœæ)
 * @return WskaŸnik do korzenia drzewa Huffmana
 */
HuffmanNode* buildHuffmanTree(const vector<pair<char, double>>& symbols);

/*
 * Generuje kody Huffmana dla ka¿dego symbolu
 * @param root Korzeñ drzewa Huffmana
 * @param code Aktualnie budowany kod
 * @param codes Mapa przechowuj¹ca kody dla symboli
 */
void generateHuffmanCodes(HuffmanNode* root, const string& code, vector<pair<char, string>>& codes);

/*
 * Przetwarza wektor symboli: buduje drzewo, generuje i wypisuje kody Huffmana
 * @param symbols Wektor par (symbol, wartoœæ)
 */
void processVector(vector<pair<char, double>> symbols);

/*
 * Wypisuje kody Huffmana
 * @param codes Wektor par (symbol, kod Huffmana)
 */
void printCodes(const vector<pair<char, string>>& codes);

#endif