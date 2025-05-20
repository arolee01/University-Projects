#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

/*
 * Reprezentuje pojedynczy przedmiot
 * @param name Nazwa przedmiotu
 * @param value Wartoœæ (cena) przedmiotu
 * @param weight Waga (rozmiar) przedmiotu
 */
class Item {
public:
    string name;
    int value;
    int weight;

    Item(string n, int v, int w);
};

#endif
