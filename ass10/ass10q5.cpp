#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> selected(V, false);
    selected[0] = true;  

    int edges = 0, totalWeight = 0;

    cout << "Edges in MST:\n";

    while (edges < V - 1) {
        int minWeight = 999999;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {  
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] != 0 && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " (weight " << minWeight << ")\n";
        totalWeight += minWeight;
        selected[v] = true;
        edges++;
    }

    cout << "Total MST weight = " << totalWeight << endl;

    return 0;
}
