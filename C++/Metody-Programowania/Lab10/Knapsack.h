#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <fstream>

using namespace std;

struct Item {
    int profit;
    int weight;
};

/*
 * Oblicza rekurencyjnie najlepszy zysk mo¿liwy do uzyskania metod¹ z powrotami
 * @param i Numer aktualnego przedmiotu
 * @param profit Zysk aktualny
 * @param weight Waga aktualna
 * @param maxWeight Maksymalna dozwolona waga
 * @param items Wektor dostêpnych przedmiotów
 * @param currentSet Wektor oznaczaj¹cy aktualnie wybrany zestaw
 * @param bestSet Wektor oznaczaj¹cy najlepszy dot¹d znaleziony zestaw
 * @param bestProfit Najlepszy dot¹d znaleziony zysk
 * @param out Strumieñ wyjœciowy do zapisu kroków
 */
void knapsack(int i, int profit, int weight, int maxWeight, const vector<Item>& items,
    vector<int>& currentSet, vector<int>& bestSet, int& bestProfit, ofstream& out);

#endif
