#include <stdio.h>
#include <stdlib.h>

int graph[20][20];
int visited[20]; // stack
int n;

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int j = 0; j < n; j++) {
        if (graph[vertex][j] == 1 && visited[j] == 0) {
            DFS(j);
        }
    }
}
int main() {
    int i, j;
    int start_vertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start_vertex);

    printf("\nDepth First Traversal: ");
    DFS(start_vertex);
    printf("\n");

    return 0;
}