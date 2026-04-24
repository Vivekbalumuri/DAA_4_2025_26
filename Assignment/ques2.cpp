#include <bits/stdc++.h>
using namespace std;

class Hamiltonian {
public:
    int V;
    vector<vector<int>> graph;
    vector<int> path;

    Hamiltonian(int v) {
        V = v;
        graph.assign(V, vector<int>(V, 0));
        path.assign(V, -1);
    }

    bool isSafe(int v, int pos) {
        if (graph[path[pos - 1]][v] == 0)
            return false;
        for (int i = 0; i < pos; i++) {
            if (path[i] == v)
                return false;
        }

        return true;
    }

    bool solveUtil(int pos) {
        if (pos == V) {
            return graph[path[pos - 1]][path[0]] == 1;
        }
        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                if (solveUtil(pos + 1))
                    return true;
                path[pos] = -1;
            }
        }

        return false;
    }
    void solve() {
        path[0] = 0; 

        if (!solveUtil(1)) {
            cout << "No Hamiltonian Cycle exists\n";
            return;
        }

        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";

        cout << path[0] << endl;
    }
};
int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    Hamiltonian obj(V);
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> obj.graph[i][j];
        }
    }
    obj.solve();
    return 0;
}
