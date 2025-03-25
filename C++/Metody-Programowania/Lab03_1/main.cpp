#include <iostream>
#include <string>
#include "LibFiles.h"
#include "LibTables.h"

using namespace std;

int main() {
    string inputFile, outputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    DataSet* dataSets = nullptr;
    int numOfSets;

    if (!f_readData(inputFile, numOfSets, dataSets)) {
        cout << "Error loading data from file." << endl;
        return 1;
    }

    if (!f_processAndSaveData(outputFile, numOfSets, dataSets)) {
        cout << "Error processing data or saving results." << endl;
        return 1;
    }

    f_freeMemory(numOfSets, dataSets);

    return 0;
}