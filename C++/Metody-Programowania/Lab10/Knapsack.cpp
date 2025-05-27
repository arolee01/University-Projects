#include "Knapsack.h"

void knapsack(int i, int profit, int weight, int maxWeight, const vector<Item>& items, vector<int>& currentSet, vector<int>& bestSet, int& bestProfit, ofstream& out) {
    out << "Poziom: " << i << ", Zysk: " << profit << ", Waga: " << weight << ", Wybrane: ";
    for (int v : currentSet) out << v << " ";
    out << endl;

    if (weight <= maxWeight && profit > bestProfit) {
        bestProfit = profit;
        bestSet = currentSet;
        out << "--- ZNALEZIONO LEPSZY ZYSK: " << bestProfit << " ---" << endl;
    }

    if (i < items.size()) {
        // Wybieramy przedmiot i
        currentSet[i] = 1;
        knapsack(i + 1, profit + items[i].profit, weight + items[i].weight, maxWeight, items, currentSet, bestSet, bestProfit, out);

        // Nie wybieramy przedmiotu i
        currentSet[i] = 0;
        knapsack(i + 1, profit, weight, maxWeight, items, currentSet, bestSet, bestProfit, out);
    }
}
