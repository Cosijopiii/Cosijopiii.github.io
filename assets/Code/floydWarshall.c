#include <stdio.h>
#define INF 1000000
#define V 4

// Print the distance matrix or predecessor matrix
void printMatrixInt(int mat[V][V], int step, const char* label) {
    printf("%s at Step %d:\n", label, step);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (mat[i][j] == INF)
                printf("%4s ", "INF");
            else
                printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Reconstruct and print the shortest path from u to v
void printPath(int pred[V][V], int u, int v) {
    if (u == v) {
        printf("%d", u);
    } else if (pred[u][v] == -1) {
        printf("No path from %d to %d\n", u, v);
    } else {
        printPath(pred, u, pred[u][v]);
        printf(" -> %d", v);
    }
}

// Floyd-Warshall algorithm with path reconstruction
void floydWarshall(int graph[V][V]) {
    int dist[V][V], pred[V][V];

    // Initialize distance and predecessor matrices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (i == j || graph[i][j] == INF)
                pred[i][j] = -1;
            else
                pred[i][j] = i;
        }
    }

    printMatrixInt(dist, 0, "Distance");
    printMatrixInt(pred, 0, "Predecessor");

    // Main algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
        printMatrixInt(dist, k + 1, "Distance");
        printMatrixInt(pred, k + 1, "Predecessor");
    }

    // Final output
    printf("Final Distance Matrix:\n");
    printMatrixInt(dist, V, "Distance");

    printf("Final Predecessor Matrix:\n");
    printMatrixInt(pred, V, "Predecessor");

    // Example: show path from node 0 to each node
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Shortest path from %d to %d: ", i, j);
            if (i == j)
                printf("%d\n", i);
            else if (pred[i][j] == -1)
                printf("No path\n");
            else {
                printPath(pred, i, j);
                printf(" (Distance: %d)\n", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}
