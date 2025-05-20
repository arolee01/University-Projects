#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include "item.h"
using namespace std;

/*
 * Rozwi¹zuje problem plecakowy (0-1 Knapsack) metod¹ programowania dynamicznego
 * @param availableItems - lista przedmiotów Pi (ka¿dy z mas¹ mi i cen¹ ci)
 * @param maxCapacity - maksymalna pojemnoœæ plecaka Mmax [jm]
 * @param valueTable - tabela wartoœci Pij (wyjœciowa)
 * @param choiceTable - tabela wyborów Qij (wyjœciowa)
 */
void solveKnapsackProblem(const std::vector<Item>& availableItems,
    int maxCapacity,
    std::vector<std::vector<int>>& valueTable,
    std::vector<std::vector<bool>>& choiceTable);

/*
 * Zwraca listê przedmiotów zapakowanych do plecaka na podstawie tabeli Qij
 * @param availableItems - lista wszystkich przedmiotów Pi
 * @param choiceTable - tabela wyborów Qij
 * @param maxCapacity - maksymalna pojemnoœæ plecaka Mmax [jm]
 * @return wektor wybranych przedmiotów w kolejnoœci od ostatniego do pierwszego
 */
std::vector<Item> getSelectedItems(const std::vector<Item>& availableItems,
    const std::vector<std::vector<bool>>& choiceTable,
    int maxCapacity);

#endif
