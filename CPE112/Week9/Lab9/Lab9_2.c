// Maimoona Aziz #67070503473
// Task: Write a C program to construct weighted directed graph and find the shortest path between a given starting node and a destination node using Dijkstra’s algorithm.

#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define MAX_E 1000

typedef struct Edge {
    int dest;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    int V;
    Edge** adjList;
} Graph;


Graph* createGraph(int V);
void insertEdge(Graph* graph, int src, int dest, int weight);
int minDistance(int dist[], int sptSet[], int V);
void printPath(int parent[], int j);


int main(void){
    int vertex, edge;
    scanf("%d %d", &vertex, &edge); // Insert Vertex and Edge

    Graph* graph = createGraph(vertex);

    // Get Edges
    for (int i = 0; i < edge; i++){
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        insertEdge(graph, s, d, w);
    }

    // Get Source and Destination
    int src, dest;
    scanf("%d %d", &src, &dest);

    //Dijkstra's Algorithm
    int V = graph->V;
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++){
        dist[i] = MAX_E;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++){
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        Edge* current = graph->adjList[u];
        while (current != NULL){
            if (sptSet[current->dest] == 0 && dist[u] != MAX_E && dist[u] + current->weight < dist[current->dest]){
                dist[current->dest] = dist[u] + current->weight;
                parent[current->dest] = u;
            }
            current = current->next;
        }
    }

    if (dist[dest] == MAX_E){
        printf("-1 ");
    } else {
        printPath(parent, dest);
        puts("");
        printf("%d ", dist[dest]);
    }


    // Free allocated memory
    for (int i = 0; i < vertex; i++){
        Edge* current = graph->adjList[i];
        while (current != NULL) {
            Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->adjList);
    free(graph);
}

Graph* createGraph(int V){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Edge**)malloc(V * sizeof(Edge*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void insertEdge(Graph* graph, int src, int dest, int weight){
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;
}

int minDistance(int dist[], int sptSet[], int V){
    int min = MAX_E, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j){
    if (parent[j] == -1){
        printf("%d ", j);
        return;
    }

    printPath(parent, parent[j]);
    printf("%d ", j);
}