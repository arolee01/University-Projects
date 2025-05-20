#ifndef KNAPSACKSOLVER_H
#define KNAPSACKSOLVER_H

#include <vector>
#include <string>

/*
 * Sprawdza, czy istnieje kombinacja elementów, które sumuj¹ siê do podanej wagi
 * @param weights Wektor dostêpnych wag elementów
 * @param target Waga docelowa do osi¹gniêcia
 * @param index Aktualny indeks w wektorze wag
 * @param current_sum Aktualna suma wag wybranych elementów
 * @param solution Wektor przechowuj¹cy aktualne rozwi¹zanie
 * @return true jeœli znaleziono rozwi¹zanie, false w przeciwnym przypadku
 */
bool findKnapsackSolution(const std::vector<int>& weights, int target,
    size_t index, int current_sum,
    std::vector<int>& solution);

/*
 * Znajduje rozwi¹zanie problemu plecakowego dla podanych parametrów
 * @param capacity Pojemnoœæ plecaka
 * @param weights Wektor dostêpnych wag elementów
 * @return Wektor z wagami elementów tworz¹cych rozwi¹zanie lub pusty wektor jeœli brak rozwi¹zania
 */
std::vector<int> solveKnapsack(int capacity, const std::vector<int>& weights);

#endif