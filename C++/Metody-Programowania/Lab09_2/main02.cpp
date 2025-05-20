#include <iostream>
#include <vector>
#include <string>
#include "KnapsackSolver.h"
#include "LibFiles.h"

using namespace std;

int main() {
    // Liszka Arkadiusz

    try {
        vector<vector<int>> dataSets = readInputData("input.txt");
        vector<string> results;

        for (vector<int> dataSet : dataSets) {
            int capacity = dataSet[0];
            vector<int> weights(dataSet.begin() + 1, dataSet.end());

            vector<int> solution = solveKnapsack(capacity, weights);

            string result;
            if (solution.empty()) {
                result = " BRAK";
            }
            else {
                result = to_string(capacity) + " >";
                for (int weight : solution) {
                    result += " " + to_string(weight);
                }
            }
            results.push_back(result);
        }

        writeOutputData("output.txt", results);

        cout << "Program wykonany pomyslnie. Wyniki zapisane w output.txt" << endl;
    }
    catch (const exception& e) {
        cerr << "Blad: " << e.what() << endl;
        return 1;
    }

    return 0;
}