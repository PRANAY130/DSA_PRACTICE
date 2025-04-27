#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices

int findMinKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V];   // To store the MST
    int key[V];      // To pick minimum weight edge
    int mstSet[V];   // To mark vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // First node is root, no parent

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = 1; // Add the picked vertex to MST

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
