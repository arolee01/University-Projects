/*
Zadanie 1:

Dla n losowo wygenerowanych liczb naturalnych, przechowywanych w tablicy S, proszę zaimplementować proste algorytmy sortowania. Algorytmy należy zaimplementować w postaci oddzielnych funkcji. Proszę przetestować poprawność ich działania według podanego w szablonie schematu.

Szablon rozwiązania:

//Zadanie 1

void print(int* S, int n){               //wyświetla dane
}
void init(int* S, int n){               //generuje losowe dane
}
void insertionSort(int* S, int n){
}
void selectionSort(int* S, int n){
}
void bubbleSort(int* S, int n){
}

//Zadanie 1 - test
cout<<"Zadanie 1 - test - sortowanie ..."<<endl;
{
int n = 20;                //przykładowy rozmiar
int *S = new int[n];
// generacja i wyświetlenie danych
//sortowanie i wyświetlenie danych
}

Zadanie 2:

Do programu z zdania 1 proszę dodać kod implementujący eksperymentalne porównanie algorytmów z zadania 1, uwzględniając czas ich działania.

Wykonanie eksperymentu wymaga:

wybrania odpowiednio dużego rozmiaru tablicy
generację losowych danych (oraz utworzenia ich kopii)
sortowanie danych przy użyciu algorytmów z zadania 1 i zmierzenia i wyświetlenia czasu trwania sortowania dla każdego z nich
Pomiar czasu:

    clock_t start = clock();
    //wywołanie funkcji
    clock_t end = clock();
    double result_time = (double) (end - start) /CLOCKS_PER_SEC;

Wymaga bibliotek: <ctime>, <cstdlib>.

Zadanie 3:

Do programu z zadania 2 proszę dodać i zaimplementować algorytm sortowania szybkiego, przetestować go według schematu dla zadania 1 oraz dodać do porównania z zadania 2.

Szablon rozwiązania:

//Zadanie 3
void quickSort(int* S, int left, int right){
}
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void print(int* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

// Inicjalizacja tablicy losowymi liczbami
void init(int* S, int n) {
    for (int i = 0; i < n; i++) {
        S[i] = rand();
    } 
}

// Inicjalizacja tablicy w kolejności rosnącej
void initAsc(int* S, int n) {
    for (int i = 0; i < n; i++) {
        S[i] = i;
    }
}

// Inicjalizacja tablicy w kolejności malejącej
void initDesc(int* S, int n) {
    for (int i = 0; i < n; i++) {
        S[i] = n - i;
    }
}

void copyData(const int* zrodlo, int* cel, int n) {
    for (int i = 0; i < n; i++) {
        cel[i] = zrodlo[i];
    }
}

void insertionSort(int* S, int n) {
    for (int i = 1; i < n; i++) {
        int key = S[i];
        int j = i - 1;
        while (j >= 0 && S[j] > key) {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = key;
    }
}

void selectionSort(int* S, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (S[j] < S[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = S[i];
            S[i] = S[min];
            S[min] = temp;
        }
    }
}

void bubbleSort(int* S, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (S[j] > S[j + 1]) {
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

void quickSort(int* S, int left, int right) {
    if (left < right) {
        int pivot = S[right - 1];
        int i = left - 1;
        for (int j = left; j < right - 1; j++) {
            if (S[j] <= pivot) {
                i++;
                int temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
        int temp = S[i + 1];
        S[i + 1] = S[right - 1];
        S[right - 1] = temp;
        int partitionIndex = i + 1;
        quickSort(S, left, partitionIndex);
        quickSort(S, partitionIndex + 1, right);
	}
}


void runTestForN(int n) {
    cout << "-------------------------------" << endl;
    cout << "Testowanie dla n = " << n << endl;
    cout << "-------------------------------" << endl;

    int* base = new int[n];
    int* base1 = new int[n];
    int* base2 = new int[n];

    init(base, n);
	initAsc(base1, n);
	initDesc(base2, n);

	//print(base, n);

    int* a = new int[n]; // dla insertionSort
    int* b = new int[n]; // dla selectionSort
    int* c = new int[n]; // dla bubbleSort

    int* d = new int[n]; // dla insertionSort
    int* e = new int[n]; // dla selectionSort
    int* f = new int[n]; // dla bubbleSort

    int* g = new int[n]; // dla insertionSort
    int* h = new int[n]; // dla selectionSort
    int* i = new int[n]; // dla bubbleSort

	int* j = new int[n]; // dla quickSort
	int* k = new int[n]; // dla selectionSort
	int* l = new int[n]; // dla bubbleSort


    // Skopiowanie danych z 'base' do tablic roboczych
    // (aby każdy algorytm startował z tym samym układem danych)
    copyData(base, a, n);
    copyData(base, b, n);
    copyData(base, c, n);
	copyData(base, j, n);

    copyData(base1, a, n);
    copyData(base1, b, n);
    copyData(base1, c, n);
	copyData(base1, k, n);

    copyData(base2, a, n);
    copyData(base2, b, n);
    copyData(base2, c, n);
	copyData(base2, l, n);

    clock_t start, end;
    double result_time;

    cout << "-------------------------------" << endl;
	cout << "TESTOWANIE DLA DANYCH LOSOWYCH" << endl;
    cout << "-------------------------------" << endl;
    //  insertionSort 
    cout << "Testowanie insertionSort..." << endl;
    start = clock();
    insertionSort(a, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (insertionSort): " << result_time << " sekund" << endl;

    //  selectionSort 
    cout << "Testowanie selectionSort..." << endl;
    start = clock();
    selectionSort(b, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (selectionSort): " << result_time << " sekund" << endl;

    //  bubbleSort 
    cout << "Testowanie bubbleSort..." << endl;
    start = clock();
    bubbleSort(c, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (bubbleSort): " << result_time << " sekund" << endl;

	//  quickSort 
    cout << "Testowanie quickSort..." << endl;
    start = clock();
	quickSort(j, 0, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (quickSort): " << result_time << " sekund" << endl;

    cout << "-------------------------------" << endl;
	cout << "TESTOWANIE DLA DANYCH POSORTOWANYCH ROSNĄCO" << endl;
    cout << "-------------------------------" << endl;
    //  insertionSort 
    cout << "Testowanie insertionSort..." << endl;
    start = clock();
    insertionSort(d, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (insertionSort): " << result_time << " sekund" << endl;

    //  selectionSort 
    cout << "Testowanie selectionSort..." << endl;
    start = clock();
    selectionSort(e, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (selectionSort): " << result_time << " sekund" << endl;

    //  bubbleSort 
    cout << "Testowanie bubbleSort..." << endl;
    start = clock();
    bubbleSort(f, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (bubbleSort): " << result_time << " sekund" << endl;

    //  quickSort 
    cout << "Testowanie quickSort..." << endl;
    start = clock();
    quickSort(k, 0, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (quickSort): " << result_time << " sekund" << endl;

	cout << "-------------------------------" << endl;
	cout << "TESTOWANIE DLA DANYCH POSORTOWANYCH MALEJĄCO" << endl;
    cout << "-------------------------------" << endl;
    //  insertionSort 
    cout << "Testowanie insertionSort..." << endl;
    start = clock();
    insertionSort(g, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (insertionSort): " << result_time << " sekund" << endl;

    //  selectionSort 
    cout << "Testowanie selectionSort..." << endl;
    start = clock();
    selectionSort(h, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (selectionSort): " << result_time << " sekund" << endl;

    //  bubbleSort 
    cout << "Testowanie bubbleSort..." << endl;
    start = clock();
    bubbleSort(i, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (bubbleSort): " << result_time << " sekund" << endl;

    //  quickSort 
    cout << "Testowanie quickSort..." << endl;
    start = clock();
    quickSort(l, 0, n);
    end = clock();
    result_time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Czas sortowania (quickSort): " << result_time << " sekund" << endl;

    delete[] base;
    delete[] a;
    delete[] b;
    delete[] c;
	delete[] d;
	delete[] e;
	delete[] f;
	delete[] g;
	delete[] h;
	delete[] i;
	delete[] j;
	delete[] k;
	delete[] l;

}

int main() {

    runTestForN(1000);
    runTestForN(10000);
    runTestForN(100000);

    return 0;
}

/*
DODATKOWE FUNKCJE SORTUJĄCE

void cntSort(int* S, int n) {
    if (n <= 0) return;

    int maxVal = S[0];
    for (int i = 1; i < n; i++) if (S[i] > maxVal) maxVal = S[i];

    int* count = new int[maxVal + 1]{0};

    for (int i = 0; i < n; i++) count[S[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            S[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}


void radixBinSort(int* S, int n) {
    int* zeroBucket = new int[n];
    int* oneBucket = new int[n];

    for (int bit = 0; bit < 31; bit++) {
        int zCount = 0;
        int oCount = 0;
        int mask = (1 << bit);

        for (int i = 0; i < n; i++) {
            if ((S[i] & mask) == 0) zeroBucket[zCount++] = S[i];
            else oneBucket[oCount++] = S[i];
        }

        for (int i = 0; i < zCount; i++) S[i] = zeroBucket[i];
        for (int i = 0; i < oCount; i++) S[zCount + i] = oneBucket[i];
    }

    delete[] zeroBucket;
    delete[] oneBucket;
}
*/