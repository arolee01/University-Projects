#include <iostream>
#include <cstdlib> // Potrzebne do funkcji rand() i srand()
#include <ctime>   // Potrzebne do funkcji time()

using namespace std;

const double INF = 1000000000.0; // Stała oznaczająca nieskończoność

struct weightedEdge {
    int s;
    int t;
    double w;           //waga krawędzi
};

class WeightedGraph {
private:
    double** adjWeightMatrix;
    int n;                          //liczba węzłów
    bool directed;

public:
    //tworzy graf w oparciu o podaną listę krawędzi z wagami
    WeightedGraph(int n, int m, weightedEdge edges[], bool directed) {
        this->n = n;
        this->directed = directed;
        
        adjWeightMatrix = new double*[n];
        for (int i = 0; i < n; i++) {
            adjWeightMatrix[i] = new double[n];
            for (int j = 0; j < n; j++) {
                if (i == j) adjWeightMatrix[i][j] = 0;
                else adjWeightMatrix[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            adjWeightMatrix[edges[i].s][edges[i].t] = edges[i].w;
            if (!directed) {
                adjWeightMatrix[edges[i].t][edges[i].s] = edges[i].w;
            }
        }
    }

    //tworzy losowy graf 
    WeightedGraph(int n, int m, bool directed) {
        this->n = n;
        this->directed = directed;
        
        adjWeightMatrix = new double*[n];
        for (int i = 0; i < n; i++) {
            adjWeightMatrix[i] = new double[n];
            for (int j = 0; j < n; j++) {
                if (i == j) adjWeightMatrix[i][j] = 0;
                else adjWeightMatrix[i][j] = INF;
            }
        }

        srand(time(NULL));
        int count = 0;
        while (count < m) {
            int u = rand() % n;
            int v = rand() % n;
            if (u != v && adjWeightMatrix[u][v] == INF) {
                double w = (rand() % 20) + 1;
                adjWeightMatrix[u][v] = w;
                if (!directed) adjWeightMatrix[v][u] = w;
                count++;
            }
        }
    }

    WeightedGraph() {
        this->n = 5;
        this->directed = true;
        
        adjWeightMatrix = new double*[n];
        for (int i = 0; i < n; i++) {
            adjWeightMatrix[i] = new double[n];
            for (int j = 0; j < n; j++) {
                if (i == j) adjWeightMatrix[i][j] = 0;
                else adjWeightMatrix[i][j] = INF;
            }
        }

        adjWeightMatrix[0][1] = 10; 
        adjWeightMatrix[0][4] = 3;
        adjWeightMatrix[1][2] = 2;  
        adjWeightMatrix[2][3] = 9;
        adjWeightMatrix[3][2] = 7;
        adjWeightMatrix[4][1] = 4;  
        adjWeightMatrix[4][2] = 8;
        adjWeightMatrix[4][3] = 2;
    }

    void shortestPath(int s, int t, int* parent) {
        if (s == t) {
            cout << s << endl;
            return;
        }
        if (parent[t] == -1) {
            cout << "Brak sciezki" << endl;
            return;
        }

        int* path = new int[n];
        int count = 0;
        int curr = t;
        
        while (curr != -1) {
            path[count++] = curr;
            curr = parent[curr];
        }

        for (int i = count - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
        delete[] path;
    }

    void Dijkstra(int s) {
        double* dist = new double[n];
        int* parent = new int[n];
        bool* visited = new bool[n];

        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }
        dist[s] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            if (dist[u] == INF) break;
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (adjWeightMatrix[u][v] != INF) {
                    if (dist[u] + adjWeightMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjWeightMatrix[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "Dijkstra (start: " << s  << ")" << endl;
        cout << "Wezel\tOdleglosc\tPoprzednik" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "\t";
            if (dist[i] == INF) cout << "INF";
            else cout << dist[i];
            cout << "\t\t" << parent[i] << endl;
        }

        // Zadanie 2: Testowanie shortestPath na końcu metody Dijkstra
        cout << "Sciezki" << endl;
        for (int i = 0; i < n; i++) {
            if (i != s) {
                cout << "Droga do " << i << ": ";
                shortestPath(s, i, parent);
            }
        }

        delete[] dist;
        delete[] parent;
        delete[] visited;
    }

    // Zadanie 3: Algorytm Warshalla-Floyda
    void WarshallFloyd() {
        double** dist = new double*[n];
        int** next = new int*[n];

        for (int i = 0; i < n; i++) {
            dist[i] = new double[n];
            next[i] = new int[n];
            for (int j = 0; j < n; j++) {
                dist[i][j] = adjWeightMatrix[i][j];
                if (adjWeightMatrix[i][j] != INF && i != j) {
                    next[i][j] = j;
                } else {
                    next[i][j] = -1;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            next[i][j] = next[i][k];
                        }
                    }
                }
            }
        }

        cout << "Warshall-Floyd" << endl;
        cout << "Macierz odleglosci:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) cout << "INF\t";
                else cout << dist[i][j] << "\t";
            }
            cout << endl;
        }


        cout << "Sciezki dla kazdej pary:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] != INF) {
                    cout << i << "->" << j << " (koszt " << dist[i][j] << "): " << i;
                    int curr = i;
                    while (curr != j) {
                        curr = next[curr][j];
                        cout << "->" << curr;
                    }
                    cout << endl;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            delete[] dist[i];
            delete[] next[i];
        }
        delete[] dist;
        delete[] next;
    }

    friend ostream& operator<<(ostream& out, WeightedGraph& g);

    ~WeightedGraph() {
        for (int i = 0; i < n; i++) delete[] adjWeightMatrix[i];
        delete[] adjWeightMatrix;
    }
};

ostream& operator<<(ostream& out, WeightedGraph& g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (g.adjWeightMatrix[i][j] == INF) out << "INF\t";
            else out << g.adjWeightMatrix[i][j] << "\t";
        }
        out << endl;
    }
    return out;
}

int main() {
    // 1. Test na grafie domyślnym
    cout << "TEST 1: Graf domyslny (skierowany)" << endl;
    WeightedGraph g1;
    cout << g1 << endl;

    g1.Dijkstra(0);
    g1.WarshallFloyd();

    // 2. Test na grafie losowym
    cout << "TEST 2: Graf Losowy (nieskierowany)" << endl;
    WeightedGraph g2(5, 7, false);
    cout << g2 << endl;
    
    g2.Dijkstra(0);
    g2.WarshallFloyd();

    return 0;
}