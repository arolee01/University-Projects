#include "KnapsackSolver.h"
#include <stdexcept>

using namespace std;

bool findKnapsackSolution(const vector<int>& weights, int target,
    size_t index, int current_sum,
    vector<int>& solution) {
    if (current_sum == target) {
        return true;
    }

    if (index >= weights.size() || current_sum > target) {
        return false;
    }

    // Spróbuj dodaæ aktualny element
    solution.push_back(weights[index]);
    if (findKnapsackSolution(weights, target, index + 1, current_sum + weights[index], solution)) {
        return true;
    }

    // Jeœli nie dzia³a, usuñ element i spróbuj bez niego
    solution.pop_back();
    return findKnapsackSolution(weights, target, index + 1, current_sum, solution);
}

vector<int> solveKnapsack(int capacity, const vector<int>& weights) {
    vector<int> solution;

    if (findKnapsackSolution(weights, capacity, 0, 0, solution)) {
        return solution;
    }

    return vector<int>();
}