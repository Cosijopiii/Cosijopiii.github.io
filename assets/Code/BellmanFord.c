#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5     // Number of vertices
#define E 8     // Number of edges
#define INF 1000000

typedef struct {
    int u, v, w;
} Edge;

// Print the path from source to target using predecessor array
void printPath(int pred[], int j) {
    if (pred[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(pred, pred[j]);
    printf(" -> %d", j);
}

void bellmanFord(Edge edges[], int source) {
    int dist[V];
    int pred[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        pred[i] = -1;
    }
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print results
    printf("Vertex\tDistance from %d\tPath\n", source);
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
    // Define edges: u, v, weight (directed graph)
    Edge edges[E] = {
        {0, 1, 10},
        {0, 3, 30},
        {0, 4, 100},
        {1, 2, 50},
        {2, 4, 10},
        {3, 2, 20},
        {3, 4, 60},
        {4, 3, -10} // example of negative weight
    };

    int source = 0;
    bellmanFord(edges, source);

    return 0;
}
