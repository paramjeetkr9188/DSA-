#include <stdio.h>

void primMST(int V, int graph[V][V]) {
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge
    int inMST[V];    // 1 if vertex is included in MST, 0 otherwise
    int INF = 999999;

    // Step 1: Initialize all keys as INF and inMST as 0 (false)
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        inMST[i] = 0;
    }

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;

    // The MST will have V vertices, so loop V - 1 times
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value from the set of vertices not yet in MST
        int min = INF;
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (inMST[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Add the picked vertex to the MST Set
        inMST[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // inMST[v] == 0 ensures vertex is not yet included
            // graph[u][v] < key[v] checks if the new edge weight is smaller than existing key
            if (graph[u][v] != 0 && inMST[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST and total weight
    int totalCost = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
        totalCost += graph[parent[i]][i];
    }
    printf("\nTotal Cost of Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(V, graph);

    return 0;
}
