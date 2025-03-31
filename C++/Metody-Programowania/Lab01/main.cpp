#include <iostream>
#include "LibArray.h"
#include "LibKadane.h"

using namespace std;

int main() {
    int z;
    cin >> z;

    while (z--) {
        int n, m;
        cin >> n >> m;

        int** arr = f_createArray(n, m);

        bool validData = false;
        int attempt = 0;

        while (attempt < 3 && !validData) {
            cout << "Remaining attempts: " << 3 - attempt << endl;
            validData = f_fillArray(arr, n, m);
            if (!validData) {
                attempt++;
            }
        }

        if (!validData) {
            cout << "Exceeded the attempt limit. Moving on to the next set." << endl;
            f_deleteArray(arr, n);
            continue;
        }

        int result = f_maxSubarraySum(arr, n, m);

        f_showResult(result);

        f_deleteArray(arr, n);
    }

    return 0;
}