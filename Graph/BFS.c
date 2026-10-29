
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q) {
    return q->r == q->f;
}

int isFull(struct queue *q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Number of vertices in the graph
    int total_vertices = 7;

    // Array to track visited vertices (0 = unvisited, 1 = visited)
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // Adjacency Matrix representation of the graph
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    // Starting node for BFS traversal
    int start_node = 0;

    printf("BFS Traversal: ");
    printf("%d ", start_node);
    visited[start_node] = 1;
    enqueue(&q, start_node);

    // BFS exploration loop
    while (!isEmpty(&q)) {
        int node = dequeue(&q);

        for (int j = 0; j < total_vertices; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    printf("\n");
    free(q.arr);
    return 0;
}
