#include "LibGraph.h"
#include <fstream>

void readFile(vector<int>& edgeStart, vector<int>& edgeEnd, int& edgeCount) {
    ifstream file("test.txt");
    if (!file) {
        cerr << "Nie mozna otworzyc pliku test.txt" << endl;
        exit(1);
    }

    file >> edgeCount;
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        file >> a >> b;
        edgeStart.push_back(a);
        edgeEnd.push_back(b);
    }

    file.close();
}

int findVertexCount(const vector<int>& start, const vector<int>& end) {
    int maxVertex = 0;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] > maxVertex) maxVertex = start[i];
        if (end[i] > maxVertex) maxVertex = end[i];
    }
    return maxVertex;
}

void createIncidenceMatrix(vector<vector<int>>& matrix, const vector<int>& start, const vector<int>& end, int vertexCount, int edgeCount) {
    matrix.resize(vertexCount + 1, vector<int>(edgeCount, 0));
    for (int i = 0; i < edgeCount; i++) {
        matrix[start[i]][i] = 1;
        matrix[end[i]][i] = -1;
    }
}

void printIncidenceMatrix(const vector<vector<int>>& matrix) {
    cout << "\nMacierz incydencji:\n";
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printNeighbors(const vector<int>& start, const vector<int>& end, int vertexCount) {
    cout << "\nSasiedzi kazdego wierzcholka:\n";
    for (int i = 1; i <= vertexCount; i++) {
        cout << "Wierzcholek " << i << ": ";
        for (int j = 0; j < start.size(); j++) {
            if (start[j] == i) {
                cout << end[j] << " ";
            }
        }
        cout << endl;
    }
}
