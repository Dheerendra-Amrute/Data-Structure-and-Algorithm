#include <stdio.h>
#include <stdlib.h>

int graph[20][20];
int visited[20];
int queue[20];
int front = -1, rear = -1;
int n;

void enqueue(int vertex) {
    if (rear == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = vertex;
}

int dequeue() {
    int vertex;
    vertex = queue[front];
    front = front + 1;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return vertex;
}

int isQueueEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void BFS(int vertex) {
    int i;

    // Mark the starting vertex as visited and add it to the queue
    visited[vertex] = 1;
    enqueue(vertex);

    while (!isQueueEmpty()) {
        
        // Dequeue a vertex and print it
        int current_vertex = dequeue();
        printf("%d ", current_vertex);

        // Get all adjacent vertices
        for (i = 0; i < n; i++) {
            // If an adjacent vertex is found and not visited
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
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
    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start_vertex);

    printf("\nBreadth First Traversal: ");
    BFS(start_vertex);
    printf("\n");

    return 0;
}