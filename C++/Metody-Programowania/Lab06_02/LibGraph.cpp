#include "LibGraph.h"
#include <fstream>

void addEdge(Node* adjacencyList[], int from, int to) {
    Node* newNode = new Node{ to, adjacencyList[from] };
    adjacencyList[from] = newNode;

    Node* newNodeReverse = new Node{ from, adjacencyList[to] };
    adjacencyList[to] = newNodeReverse;
}

void readEdges(Node* adjacencyList[], int& vertexCount) {
    ifstream file("test.txt");
    if (!file) {
        cerr << "Nie mozna otworzyc pliku test.txt" << endl;
        exit(1);
    }

    int edgeCount;
    file >> edgeCount;

    vertexCount = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        file >> a >> b;
        addEdge(adjacencyList, a, b);

        if (a > vertexCount) vertexCount = a;
        if (b > vertexCount) vertexCount = b;
    }

    file.close();
}

void printAdjacencyList(Node* adjacencyList[], int vertexCount) {
    cout << "\nLista incydencji:" << endl;
    for (int i = 1; i <= vertexCount; i++) {
        cout << "Wierzcholek " << i << ": ";
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            cout << current->vertex << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void printDegrees(Node* adjacencyList[], int vertexCount) {
    cout << "\nStopnie wierzcholkow:" << endl;
    for (int i = 1; i <= vertexCount; i++) {
        int degree = 0;
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            degree++;
            current = current->next;
        }
        cout << "Wierzcholek " << i << ": " << degree << endl;
    }
}

void freeMemory(Node* adjacencyList[], int vertexCount) {
    for (int i = 1; i <= vertexCount; i++) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        adjacencyList[i] = nullptr;
    }
}
