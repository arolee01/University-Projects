/*
Dla grafu (skierowanego lub nieskierowanego) reprezentowanego w postaci macierzy sąsiedztwa proszę zaimplementować wskazane algorytmy przeszukiwania grafu. Algorytmy powinien wyświetlać węzły w kolejności odwiedzenia. Proszę przetestować poprawność działania algorytmów.

//Szablon rozwiązania:
struct edge{
    int s;
    int t;
};
class Graph{
    private:
        int** adjMatrix;
        int n;                              //liczba węzłów
        bool directed;              //true - graf skierowany, false - graf nieskierowany
       void dfs(int s, int* visited);    //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
    public:
        Graph(int n, int m, edge edges[], bool directed);    //tworzy graf w oparciu o pdaną listę krawędzi
        Graph(){ //konstruktor domyślny z predefiniowanym grafem testowym

            this->n = 6;
            this->directed = true;
            adjMatrix = new int*[n];

            for(int i=0; i< n; i++)
                adjMatrix[i]=new int[n]{0};

            adjMatrix[0][4]=1;
            adjMatrix[0][5]=1;
            adjMatrix[1][0]=1;
            adjMatrix[1][2]=1;
            adjMatrix[1][4]=1;
            adjMatrix[2][1]=1;
            adjMatrix[2][3]=1;
            adjMatrix[2][4]=1;
            adjMatrix[3][2]=1;
            adjMatrix[3][5]=1;
            adjMatrix[4][0]=1;
            adjMatrix[4][1]=1;
            adjMatrix[4][3]=1;
            adjMatrix[5][3]=1;
            adjMatrix[5][4]=1;

          }
        Graph(int n, int m, bool directed);    //tworzy losowy graf o n węzłach i m krawędziach, skierowany lub nieskierowany
        void bfs(int s);                //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
        void dfs(int s);                //metoda pomocnicza dla dfs - tworzy tabelę visited i wywołuję metodę prywatną dfs
        friend ostream& operator<<(ostream& out, Graph& g);  //wyświetla graf
        ~Graph();
};


*/

#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int s;
    int t;
};
class Graph {
private:
    int** adjMatrix;
    int n;                              //liczba węzłów
    bool directed;              //true - graf skierowany, false - graf nieskierowany

    void dfs(int s, bool* visited) {
        visited[s] = true;
        cout << s << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[s][i] == 1 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }    //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
public:
    // Tworzy graf w oparciu o podaną listę krawędzi
    Graph(int n, int m, edge edges[], bool directed) {
        this->n = n;
        this->directed = directed;

        // Alokacja pamięci dla macierzy
        adjMatrix = new int* [n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n] {0}; // Inicjalizacja zerami
        }

        // Wypełnianie macierzy na podstawie listy krawędzi
        for (int i = 0; i < m; i++) {
            int u = edges[i].s;
            int v = edges[i].t;

            if (u >= 0 && u < n && v >= 0 && v < n) {
                adjMatrix[u][v] = 1;
                if (!directed) {
                    adjMatrix[v][u] = 1; // Dla nieskierowanego krawędź działa w obie strony
                }
            }
        }
    }
    Graph() { //konstruktor domyślny z predefiniowanym grafem testowym

        this->n = 6;
        this->directed = true;
        adjMatrix = new int* [n];

        for (int i = 0; i < n; i++)
            adjMatrix[i] = new int[n] {0};

        adjMatrix[0][4] = 1;
        adjMatrix[0][5] = 1;
        adjMatrix[1][0] = 1;
        adjMatrix[1][2] = 1;
        adjMatrix[1][4] = 1;
        adjMatrix[2][1] = 1;
        adjMatrix[2][3] = 1;
        adjMatrix[2][4] = 1;
        adjMatrix[3][2] = 1;
        adjMatrix[3][5] = 1;
        adjMatrix[4][0] = 1;
        adjMatrix[4][1] = 1;
        adjMatrix[4][3] = 1;
        adjMatrix[5][3] = 1;
        adjMatrix[5][4] = 1;

    }
    
    // Tworzy losowy graf
    Graph(int n, int m, bool directed) {
        this->n = n;
        this->directed = directed;
        srand(time(NULL));

        adjMatrix = new int* [n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n] {0};
        }
    }
    //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
    void bfs(int s) {
        if (s < 0 || s >= n) return;

        bool* visited = new bool[n]{false};
        queue<int> q;

        visited[s] = true;
        q.push(s);

        cout << "BFS od wezla " << s << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v = 0; v < n; v++) {
                if (adjMatrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }       
    //metoda pomocnicza dla dfs - tworzy tabelę visited i wywołuję metodę prywatną dfs
    void dfs(int s) {
        if (s < 0 || s >= n) return;

        bool* visited = new bool[n] {false};

        cout << "DFS od wezla " << s << ": ";
        dfs(s, visited); // Wywołanie rekurencyjne
        cout << endl;

        delete[] visited;
    }
    friend ostream& operator<<(ostream& out, Graph& g) {
        out << "Macierz sasiedztwa (" << (g.directed ? "Skierowany" : "Nieskierowany") << "):" << endl;
        out << "   ";
        for (int i = 0; i < g.n; i++) out << i << " ";
        out << endl;

        for (int i = 0; i < g.n; i++) {
            out << i << ": ";
            for (int j = 0; j < g.n; j++) {
                out << g.adjMatrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};


int main() {

    cout << "--- TEST 1: ---" << endl;
    Graph g1;
    cout << g1;
    g1.dfs(0);
    g1.bfs(0);
    cout << endl;


    cout << "--- TEST 2 ---" << endl;
    int n2 = 5;
    edge edges[] = { {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4} };
    int m2 = sizeof(edges) / sizeof(edges[0]);

    Graph g2(n2, m2, edges, false); // false = nieskierowany
    cout << g2;
    g2.dfs(0);
    g2.bfs(0);
    cout << endl;

    return 0;
}