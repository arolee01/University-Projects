#include "LibFiles.h"
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace std;

vector<vector<int>> readInputData(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw runtime_error("Nie mo¿na otworzyæ pliku wejœciowego: " + filename);
    }

    vector<vector<int>> dataSets;
    int numSets;
    inputFile >> numSets;

    for (int i = 0; i < numSets; i++) {
        int capacity, numElements;
        inputFile >> capacity >> numElements;

        vector<int> weights(numElements);
        for (int j = 0; j < numElements; j++) {
            inputFile >> weights[j];
        }

        dataSets.push_back({ capacity });
        dataSets.back().insert(dataSets.back().end(), weights.begin(), weights.end());
    }

    inputFile.close();
    return dataSets;
}

void writeOutputData(const string& filename, const vector<string>& results) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        throw runtime_error("Nie mo¿na otworzyæ pliku wyjœciowego: " + filename);
    }

    for (string result : results) {
        outputFile << result << endl;
    }

    outputFile.close();
}