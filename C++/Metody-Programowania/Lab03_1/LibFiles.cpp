#include "LibFiles.h"
#include "LibTables.h"
#include <iostream>
#include <fstream>

using namespace std;

bool f_readData(const string& filename, int& numOfSets, DataSet*& dataSets) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file >> numOfSets;
    dataSets = new DataSet[numOfSets];

    for (int i = 0; i < numOfSets; i++) {
        file >> dataSets[i].dataSize;
        dataSets[i].data = new int[dataSets[i].dataSize];
        for (int j = 0; j < dataSets[i].dataSize; j++) {
            file >> dataSets[i].data[j];
        }

        file >> dataSets[i].numbersAmount;
        dataSets[i].searchedNumbers = new int[dataSets[i].numbersAmount];
        for (int j = 0; j < dataSets[i].numbersAmount; j++) {
            file >> dataSets[i].searchedNumbers[j];
        }
    }

    file.close();
    return true;
}

bool f_processAndSaveData(const string& filename, int numOfSets, DataSet* dataSets) {
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (int i = 0; i < numOfSets; i++) {
        for (int j = 0; j < dataSets[i].numbersAmount; j++) {
            int target = dataSets[i].searchedNumbers[j];
            int count = f_countOccurrences(dataSets[i].data, dataSets[i].dataSize, target);
            int index = f_interpolationSearch(dataSets[i].data, dataSets[i].dataSize, target);
            file << "(" << count << " " << index << ") ";
        }
        file << endl;

        int newSize;
        int* newArray = f_removeDuplicates(dataSets[i].data, dataSets[i].dataSize, newSize);
        for (int j = 0; j < newSize && j < 200; j++) {
            file << newArray[j];
            if (j < newSize - 1 && j < 199) {
                file << " ";
            }
            if ((j + 1) % 50 == 0) {
                file << endl;
            }
        }
        file << endl;

        delete[] newArray;
    }

    file.close();
    return true;
}

void f_freeMemory(int numOfSets, DataSet* dataSets) {
    for (int i = 0; i < numOfSets; i++) {
        delete[] dataSets[i].data;
        delete[] dataSets[i].searchedNumbers;
    }
    delete[] dataSets;
}