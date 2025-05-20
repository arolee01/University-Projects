#include "LibFiles.h"
#include <fstream>
#include <stdexcept>

int readData(const string& filename, vector<Item>& items) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Nie mo¿na otworzyæ pliku: " + filename);
    }

    int capacity;
    file >> capacity;

    string name;
    int value, weight;
    while (file >> name >> value >> weight) {
        items.emplace_back(name, value, weight);
    }

    if (items.empty()) {
        throw runtime_error("Nieprawid³owe dane.");
    }

    return capacity;
}
