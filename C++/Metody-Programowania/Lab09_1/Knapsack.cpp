#include "Knapsack.h"
#include <stdexcept>

void solveKnapsackProblem(const vector<Item>& availableItems, int maxCapacity,
    vector<vector<int>>& valueTable,
    vector<vector<bool>>& choiceTable) {
    int itemCount = availableItems.size();

    // Inicjalizacja tabeli Pij (wartoœci optymalne)
    valueTable = vector<vector<int>>(itemCount + 1, vector<int>(maxCapacity + 1, 0));

    // Inicjalizacja tabeli Qij (wybory przedmiotów)
    choiceTable = vector<vector<bool>>(itemCount + 1, vector<bool>(maxCapacity + 1, false));

    // Wype³nianie tabeli
    for (int i = 1; i <= itemCount; i++) {
        const Item& currentItem = availableItems[i - 1];

        for (int j = 0; j <= maxCapacity; j++) {
            if (currentItem.weight <= j) {
                int valueWithItem = valueTable[i - 1][j - currentItem.weight] + currentItem.value;
                int valueWithoutItem = valueTable[i - 1][j];

                if (valueWithItem > valueWithoutItem) {
                    valueTable[i][j] = valueWithItem;
                    choiceTable[i][j] = true;  // Zaznaczenie wyboru w Qij
                }
                else {
                    valueTable[i][j] = valueWithoutItem;
                }
            }
            else {
                valueTable[i][j] = valueTable[i - 1][j];
            }
        }
    }
}

vector<Item> getSelectedItems(const vector<Item>& availableItems,
    const vector<vector<bool>>& choiceTable,
    int maxCapacity) {
    vector<Item> packedItems;
    int currentItemIndex = availableItems.size();
    int remainingCapacity = maxCapacity;

    while (currentItemIndex > 0 && remainingCapacity >= 0) {
        if (choiceTable[currentItemIndex][remainingCapacity]) {
            packedItems.push_back(availableItems[currentItemIndex - 1]);
            remainingCapacity -= availableItems[currentItemIndex - 1].weight;
        }
        currentItemIndex--;
    }

    return packedItems;
}