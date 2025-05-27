#include <iostream>
#include <fstream>
#include "Knapsack.h"

using namespace std;

int main() {
    vector<Item> items = {
        {40, 2},
        {30, 5},
        {50, 10},
        {10, 5}
    };

    int maxWeight = 16;
    vector<int> bestSet(items.size(), 0);
    vector<int> currentSet(items.size(), 0);
    int bestProfit = 0;

    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Nie mo¿na otworzyæ pliku output.txt" << endl;
        return 1;
    }

    knapsack(0, 0, 0, maxWeight, items, currentSet, bestSet, bestProfit, outFile);

    outFile << "Najlepszy zysk: " << bestProfit << endl;
    outFile << "Wybrane przedmioty: ";
    for (int i = 0; i < bestSet.size(); i++) {
        if (bestSet[i] == 1)
            outFile << (i + 1) << " ";
    }
    outFile << endl;
    outFile.close();

    cout << "Najlepszy zysk: " << bestProfit << endl;
    cout << "Wybrane przedmioty: ";
    for (int i = 0; i < bestSet.size(); i++) {
        if (bestSet[i] == 1)
            cout << (i + 1) << " ";
    }
    cout << endl;

    return 0;
}
