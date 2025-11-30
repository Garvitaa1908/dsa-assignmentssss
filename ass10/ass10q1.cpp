#include <stdio.h>
using namespace std;

int main() {
    int V, E;
    int adj[20][20] = {0};
    int u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;    
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("\nEnter a vertex to find its out-degree and in-degree: ");
    scanf("%d", &v);

    int out_deg = 0, in_deg = 0;

    for (i = 0; i < V; i++) {
        if (adj[v][i] == 1) out_deg++;  // outgoing
        if (adj[i][v] == 1) in_deg++;   // incoming
    }

    printf("Out-Degree of %d = %d\n", v, out_deg);
    printf("In-Degree of %d = %d\n", v, in_deg);

    printf("\nAdjacent vertices of %d: ", v);
    for (i = 0; i < V; i++)
        if (adj[v][i] == 1)
            printf("%d ", i);
    printf("\n");

    int edgeCount = 0;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            if (adj[i][j] == 1)
                edgeCount++;

    printf("\nTotal number of edges = %d\n", edgeCount);

    return 0;
}
