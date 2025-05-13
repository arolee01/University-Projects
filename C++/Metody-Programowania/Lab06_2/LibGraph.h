#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#include <iostream>

using namespace std;

/*
 * Struktura reprezentuj¹ca wêze³ listy jednokierunkowej
 */
struct Node {
    int vertex;
    Node* next;
};

/*
 * Wczytuje dane z pliku "test.txt" i tworzy listê incydencji grafu nieskierowanego.
 * @param adjacencyList Tablica wskaŸników na listy s¹siedztwa
 * @param vertexCount Zmienna, do której zapisywana jest liczba wierzcho³ków
 */
void readEdges(Node* adjacencyList[], int& vertexCount);

/*
 * Dodaje krawêdŸ do listy s¹siedztwa (dla grafu nieskierowanego dodaje w obu kierunkach).
 * @param adjacencyList Tablica list s¹siedztwa
 * @param from Wierzcho³ek pocz¹tkowy
 * @param to Wierzcho³ek koñcowy
 */
void addEdge(Node* adjacencyList[], int from, int to);

/*
 * Wypisuje listê incydencji dla ka¿dego wierzcho³ka.
 * @param adjacencyList Tablica list s¹siedztwa
 * @param vertexCount Liczba wierzcho³ków
 */
void printAdjacencyList(Node* adjacencyList[], int vertexCount);

/*
 * Oblicza i wypisuje stopnie wszystkich wierzcho³ków.
 * @param adjacencyList Tablica list s¹siedztwa
 * @param vertexCount Liczba wierzcho³ków
 */
void printDegrees(Node* adjacencyList[], int vertexCount);

/*
 * Zwalnia dynamicznie alokowan¹ pamiêæ.
 * @param adjacencyList Tablica list s¹siedztwa
 * @param vertexCount Liczba wierzcho³ków
 */
void freeMemory(Node* adjacencyList[], int vertexCount);

#endif
