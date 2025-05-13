#include <iostream>
#include "LibGraph.h"

using namespace std;

int main() {
    const int MAX_VERTICES = 100;

    Node* adjacencyList[MAX_VERTICES] = { nullptr };
    int vertexCount = 0;

    readEdges(adjacencyList, vertexCount);
    printAdjacencyList(adjacencyList, vertexCount);
    printDegrees(adjacencyList, vertexCount);

    freeMemory(adjacencyList, vertexCount);

    return 0;
}
