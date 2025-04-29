#ifndef LIBGRAPH_H
#define LIBGRAPH_H

#include <iostream>
#include <vector>

using namespace std;

/*
 * Wczytuje dane grafu z pliku "test.txt": liczbê krawêdzi i ich definicje.
 * @param edgeStart Wektor przechowuj¹cy wierzcho³ki pocz¹tkowe krawêdzi
 * @param edgeEnd Wektor przechowuj¹cy wierzcho³ki koñcowe krawêdzi
 * @param edgeCount Zmienna przechowuj¹ca liczbê krawêdzi
 */
void readFile(vector<int>& edgeStart, vector<int>& edgeEnd, int& edgeCount);

/*
 * Zwraca najwiêkszy numer wierzcho³ka wystêpuj¹cy w grafie.
 * @param start Lista wierzcho³ków pocz¹tkowych
 * @param end Lista wierzcho³ków koñcowych
 * @return Liczba wierzcho³ków w grafie
 */
int findVertexCount(const vector<int>& start, const vector<int>& end);

/*
 * Tworzy macierz incydencji grafu skierowanego.
 * @param matrix Referencja do macierzy do wype³nienia
 * @param start Wektor wierzcho³ków pocz¹tkowych krawêdzi
 * @param end Wektor wierzcho³ków koñcowych krawêdzi
 * @param vertexCount Liczba wierzcho³ków
 * @param edgeCount Liczba krawêdzi
 */
void createIncidenceMatrix(vector<vector<int>>& matrix, const vector<int>& start, const vector<int>& end, int vertexCount, int edgeCount);

/*
 * Wypisuje macierz incydencji.
 * @param matrix Macierz incydencji
 */
void printIncidenceMatrix(const vector<vector<int>>& matrix);

/*
 * Wypisuje listê s¹siadów ka¿dego wierzcho³ka (wierzcho³ki docelowe krawêdzi wychodz¹cych).
 * @param start Wektor wierzcho³ków pocz¹tkowych krawêdzi
 * @param end Wektor wierzcho³ków koñcowych krawêdzi
 * @param vertexCount Liczba wierzcho³ków w grafie
 */
void printNeighbors(const vector<int>& start, const vector<int>& end, int vertexCount);

#endif
