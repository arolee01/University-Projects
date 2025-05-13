#include <iostream>
#include <vector>
#include "LibGraph.h"

using namespace std;

int main() {
    vector<int> edgeStart;
    vector<int> edgeEnd;
    int edgeCount;

    readFile(edgeStart, edgeEnd, edgeCount);

    int vertexCount = findVertexCount(edgeStart, edgeEnd);

    vector<vector<int>> incidenceMatrix;
    createIncidenceMatrix(incidenceMatrix, edgeStart, edgeEnd, vertexCount, edgeCount);

    printIncidenceMatrix(incidenceMatrix);
    printNeighbors(edgeStart, edgeEnd, vertexCount);

    return 0;
}
