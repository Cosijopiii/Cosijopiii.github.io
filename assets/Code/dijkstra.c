#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5
#define INF 1000000

// Find the vertex with the minimum distance that hasn't been visited
int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print path using predecessor array
void printPath(int pred[], int j) {
    if (pred[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(pred, pred[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    int pred[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        pred[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break; // Remaining vertices are inaccessible

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }

    printf("Vertex\tDistance from %d\tPath\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d\t\tINF\t\t-\n", i);
        } else {
            printf("%d\t\t%d\t\t", i, dist[i]);
            printPath(pred, i);
            printf("\n");
        }
    }
}

int main() {
    // Example graph (adjacency matrix), 0 means no edge
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 20, 0, 60},
        {0, 0, 0, 0, 0}
    };

    int source = 0;
    dijkstra(graph, source);
    return 0;
}
