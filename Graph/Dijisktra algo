#include <stdio.h>

void dijkstra(int V, int graph[V][V], int source) {
    int distance[V];
    int parent[V];
    int visited[V];
    int INF = 999999;

    // Step 1: Initialize all vertices
    for (int v = 0; v < V; v++) {
        distance[v] = INF;
        parent[v] = -1;
        visited[v] = 0; // 0 means unvisited (false)
    }

    // Distance to the source itself is always 0
    distance[source] = 0;

    // Step 2: Loop V - 1 times
    for (int count = 0; count < V - 1; count++) {
        // Find the unvisited vertex with the minimum distance
        int min = INF;
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 && distance[v] <= min) {
                min = distance[v];
                u = v;
            }
        }

        // Mark vertex u as visited
        visited[u] = 1;

        // Update neighbors of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && visited[v] == 0) {
                int newDistance = distance[u] + graph[u][v];
                if (newDistance < distance[v]) {
                    distance[v] = newDistance;
                    parent[v] = u;
                }
            }
        }
    }

    // Step 3: Print shortest distance
    printf("\nShortest Distance from source:\n");
    for (int v = 0; v < V; v++) {
        printf("Vertex %d : %d\n", v, distance[v]);
    }

    // Step 4: Print parent array
    printf("\nParent Array:\n");
    for (int v = 0; v < V; v++) {
        printf("Vertex %d : %d\n", v, parent[v]);
    }
}

int main() {
    int V, source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(V, graph, source);

    return 0;
}
