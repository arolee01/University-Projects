#include <iostream>
#include <vector>
#include <stdexcept>
#include "HuffmanTree.h"

using namespace std;

int main() {
    //Liszka Arkadiusz

    vector<pair<char, double>> freq = {
        {'a', 16},
        {'b', 5,},
        {'c', 12},
        {'d', 17},
        {'e', 10},
        {'f', 25}
    };

    vector<pair<char, double>> prob = {
        {'A', 0.39},
        {'B', 0.21},
        {'C', 0.19},
        {'D', 0.12},
        {'E', 0.09}
    };

    try {
        cout << "Kody Huffmana dla tabeli z czestotliwosciami:\n" << endl;
        processVector(freq);
        cout << "Kody Huffmana dla tabeli z prawdopodobienstwami:\n" << endl;
        processVector(prob);
    }
    catch (const exception& e) {
        cerr << "B³¹d: " << e.what() << endl;
        return 1;
    }
    return 0;
}