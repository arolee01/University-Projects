#include <iostream>
#include <vector>
#include <stdexcept>
#include "Item.h"
#include "Knapsack.h"
#include "LibFiles.h"

using namespace std;

int main() {
    // Liszka Arkadiusz
    try {
        vector<Item> items;
        int capacity = readData("input.txt", items);

        vector<vector<int>> dp;
        vector<vector<bool>> selected;

        solveKnapsackProblem(items, capacity, dp, selected);
        vector<Item> result = getSelectedItems(items, selected, capacity);

        cout << "Najlepsze mozliwe zapakowanie (maksymalna wartosc) dla masy: " << capacity << ", to: " << dp[items.size()][capacity] << " zl" << endl;
        cout << "Wybrane przedmioty:" << endl;
        for (Item item : result) {
            cout << item.name << " " << item.value << " zl, masa: " << item.weight << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Blad: " << e.what() << endl;
    }

    return 0;
}
