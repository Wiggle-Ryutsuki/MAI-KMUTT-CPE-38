// Maimoona Aziz #67070503473
// Task: construct a graph and find vertex that exists in the graph or not.

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Graph{
    int vertices;
    int graph[MAX][MAX]; //adjacent table
}Graph;

Graph* createGraph(int v);
void insertEdge(Graph *g, int u, int v);

int main(void) {
    int vertex, edge;
    
    scanf("%d %d", &vertex, &edge);
    Graph *g = createGraph(vertex);
    
    int u, v;
    for (int i = 0; i < edge; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(g, u, v);
    }
    
    int numSearch; scanf("%d", &numSearch);
    int s, d;
    for (int i = 0; i < numSearch; i++){
        scanf("%d %d", &s, &d);
        if (g->graph[s][d] == 1){
            printf("%d %d are in the graph.\n", s, d);
        } else {
            printf("%d %d are not in the graph.\n", s, d);
        }
    }
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