// Maimoona Aziz #67070503473
// Task: construct a graph and perform Depth-first Search (DFS) traversal.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Graph{
    int vertices;
    int graph[MAX][MAX];
}Graph;

Graph* createGraph(int v);
void insertEdge(Graph *g, int u, int v);
void DFS(Graph *g, int head, int visited[]);

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
    int visited[MAX] = {0};
    DFS(g, head, visited);
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

void DFS(Graph *g, int head, int visited[]) {
    

    visited[head] = 1;
    printf("%d ", head);

    for (int i = 0; i < g->vertices; i++){
        if (g->graph[head][i] == 1 && visited[i] == 0){
            DFS(g, i, visited);
        }
    }

}