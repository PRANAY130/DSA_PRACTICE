#include <stdio.h>
#include <limits.h>

#define V 4  // Number of cities

int findNearestCity(int graph[V][V], int visited[], int currentCity) {
    int nearestCity = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currentCity][i] && graph[currentCity][i] < minDistance) {
            minDistance = graph[currentCity][i];
            nearestCity = i;
        }
    }

    return nearestCity;
}

int tspGreedy(int graph[V][V]) {
    int visited[V] = {0};
    int totalCost = 0;
    int currentCity = 0;

    visited[currentCity] = 1;

    for (int count = 1; count < V; count++) {
        int nextCity = findNearestCity(graph, visited, currentCity);

        if (nextCity == -1) {
            // No unvisited cities left
            break;
        }

        visited[nextCity] = 1;
        totalCost += graph[currentCity][nextCity];
        currentCity = nextCity;
    }

    // Return to starting city
    totalCost += graph[currentCity][0];

    return totalCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int ans = tspGreedy(graph);

    printf("Approximate minimum cost (Greedy) to visit all cities: %d\n", ans);

    return 0;
}
