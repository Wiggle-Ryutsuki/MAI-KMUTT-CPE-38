// Maimoona Aziz #67070503473
// Task: construct a graph and perform Breadth-first Search (BFS) traversal.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Graph{
    int vertices;
    int graph[MAX][MAX];
}Graph;

Graph* createGraph(int v);
void insertEdge(Graph *g, int u, int v);
void BFS(Graph *g, int head);

int main(void) {
    int vertex, edge;
    
    scanf("%d %d", &vertex, &edge);
    Graph *g = createGraph(vertex);
    
    int u, v;
    for (int i = 0; i < edge; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(g, u, v);
    }
    
    int head; scanf("%d", &head);
    BFS(g, head);
    free(g);
}

Graph* createGraph(int v){
    Graph *g = malloc(sizeof(Graph));
    g->vertices = v;

    // Initialize all edges to 0
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            g->graph[i][j] = 0;
        }
    }

    return g;
}

void insertEdge(Graph *g, int u, int v) {
    g->graph[u][v] = 1;
    g->graph[v][u] = 1;
}

void BFS(Graph *g, int head) {
    int visited[MAX] = {0};
    int queue[MAX]; int front = 0; int rear = 0;
    
    // Add head to queue and mark as visited
    visited[head] = 1;
    queue[rear++] = head;

    // While queue not empty, remove vertex from queue, print
    while (front < rear){
        int current = queue[front++];
        printf("%d ", current);

        // next vertice, mark as visited, enqueeue
        for (int i = 0; i < MAX; i++){
            if (g->graph[current][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}