#ifndef LIBFILES_H
#define LIBFILES_H

#include <vector>
#include <string>
#include "item.h"
using namespace std;

/*
 * Wczytuje dane z pliku tekstowego
 * @param filename Nazwa pliku wejœciowego
 * @param items Wektor, do którego zostan¹ za³adowane przedmioty
 * @return Ca³kowita pojemnoœæ plecaka
 * @throws runtime_error w przypadku b³êdu odczytu
 */
int readData(const string& filename, vector<Item>& items);

#endif
