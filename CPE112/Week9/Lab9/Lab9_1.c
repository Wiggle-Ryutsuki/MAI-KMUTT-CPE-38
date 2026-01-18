// Maimoona Aziz #67070503473
// Task: Construct a graph and find the Minimum Spanning Tree using Kruskal's Algorithm.

#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct Edge {
    int s, d, w;
}Edge;

typedef struct Graph{
    int vertices, numEdges;                                      
    int graph[MAX][MAX];
    Edge edgeList[MAX * MAX];
}Graph;

typedef struct PriorityQueue{
    Edge edges[MAX * MAX];
    int size;
} PriorityQueue;

// Union find || Disjoint set
int parent[MAX], rank[MAX];
=======
#define MAX_E 1000
#define MAX_V 100

// Edge
typedef struct {
    int src, dest, weight;
} Edge;

// Graph (Number of Vertices, Edges, and info of edges)
typedef struct{
    int V, E;
    Edge edges[MAX_E];
} Graph;

// Subset (Output graph)
typedef struct {
    int parent;
    int rank;
} Subset;

// Priority Queue
typedef struct { 
    Edge* heap[MAX_E];
    int size;
} PriorityQueue;

>>>>>>> c1d0bf1862c1ac4f829490229942cd1614ec77a4

// Create functions
Graph* createGraph(int v, int e);
PriorityQueue* createPQ();

// Priority Queue Functions
void swap(Edge** a, Edge** b);
void enqueue (PriorityQueue* pq, Edge* edge);
Edge* dequeue(PriorityQueue* pq);
void heapify(PriorityQueue* pq, int i);

// Kruskal Functions
int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);


int main(void) {
    // Get vertex and edge
    int vertex, edge;
    scanf("%d %d", &vertex, &edge);

    // Create Graph, Priority Queue, and Subset Graph
    Graph* graph = createGraph(vertex, edge); 
    PriorityQueue* pq = createPQ();
    
    Subset* subsets = (Subset*)malloc(vertex * sizeof(Subset));
    // Create (vertex number) of subsets with single elements
    for (int v = 0; v < vertex; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    // Insert source, destination, and weight into graph
    for (int i = 0; i < edge; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    // enqueue edges to queue
    for (int i = 0; i < graph->E; i++) {
        Edge* edge = (Edge*)malloc(sizeof(Edge));
        edge->src = graph->edges[i].src;
        edge->dest = graph->edges[i].dest;
        edge->weight = graph->edges[i].weight;
        enqueue(pq, edge);

    }
    for (int i = (pq->size - 2) / 2; i >= 0; i--) {
        heapify(pq, i);
    }

    //printf("\nPRIORITY QUEUE\n");
    //for(int i = 0; i < pq->size; i++){
    //    printf("%d %d %d\n", pq->heap[i]->src, pq->heap[i]->dest, pq->heap[i]->weight);
   // }

    // Kruskals Algorithm
    Edge result[vertex];
    int e = 0;
    int i = 0;
    int totalWeight = 0;

    while (e < vertex - 1 && pq->size > 0) {
        Edge* nextEdge = dequeue(pq);
        int x = find(subsets, nextEdge->src);
        int y = find(subsets, nextEdge->dest);

        if (x != y) {
            result[e++] = *nextEdge;
            Union(subsets, x, y);
        }
    }

    for (i = 0; i < e; i++) {
        int src = result[i].src;
        int dest = result[i].dest;
        int weight = result[i].weight;
        if(src > dest){
            int temp = src;
            src = dest;
            dest = temp;
        }

<<<<<<< HEAD
void insertEdge(Graph *g, int s, int d, int w) {
    g->graph[s][d] = w;
    g->graph[d][s] = w;
}

=======
        printf("%d %d %d\n", src, dest, weight);
        totalWeight += result[i].weight;
    }

    printf("Total Weight: %d\n", totalWeight);
    
    // Free everything in the end
    free(graph);
    free(pq);
    free(subsets);
}

// Create graph
Graph* createGraph(int v, int e){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = v;
    graph->E = e;

    return graph;
}

// Create Priority Queue
PriorityQueue* createPQ(){
    PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    PQ->size = 0;

    return PQ;
}

// enqueue to PQ
void enqueue (PriorityQueue* pq, Edge* edge){
    // Check if queue is full
    if (pq->size >= MAX_E){
        printf("Priority queue is full!\n");
        return;
    }

    // Insert edge at the end
    int i = pq->size;
    pq->heap[i] = edge;
    pq->size++;

    // Check order and swap
    // If edge is more than 0 and parent edge weight is more than edge
    while (i > 0){
        int parent = (i - 1) / 2;
        if (pq->heap[i]->weight < pq->heap[parent]->weight ||
            (pq->heap[i]->weight == pq->heap[parent]->weight &&
             (pq->heap[i]->src < pq->heap[parent]->src ||
              (pq->heap[i]->src == pq->heap[parent]->src && pq->heap[i]->dest < pq->heap[parent]->dest)))) {
            swap(&pq->heap[i], &pq->heap[parent]);
            i = parent;
        } else {
            break;
        }
    }  
}

// dequeue out of queue
Edge* dequeue(PriorityQueue* pq){
    // Check if queue is empty  
    if (pq->size <= 0) {  
        return NULL;  
    }  
    if (pq->size == 1) {
        pq->size--;
        return pq->heap[0];
    }
  
    // Save the root 
    Edge* root = pq->heap[0];  
    pq->heap[0] = pq->heap[pq->size - 1];  
    pq->size--;  
      
    // Restore heap property  
    heapify(pq, 0);  
      
    return root; 
}

// Swap elements
void swap(Edge** a, Edge** b){
    Edge* temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain organization of queue
void heapify(PriorityQueue* pq, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size) {
        if (pq->heap[left]->weight < pq->heap[smallest]->weight ||
            (pq->heap[left]->weight == pq->heap[smallest]->weight &&
             (pq->heap[left]->src < pq->heap[smallest]->src ||
              (pq->heap[left]->src == pq->heap[smallest]->src && pq->heap[left]->dest < pq->heap[smallest]->dest)))) {
            smallest = left;
        }
    }

    if (right < pq->size) {
        if (pq->heap[right]->weight < pq->heap[smallest]->weight ||
            (pq->heap[right]->weight == pq->heap[smallest]->weight &&
             (pq->heap[right]->src < pq->heap[smallest]->src ||
              (pq->heap[right]->src == pq->heap[smallest]->src && pq->heap[right]->dest < pq->heap[smallest]->dest)))) {
            smallest = right;
        }
    }

    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

// Find cycle
int find(Subset subsets[], int i){
    if (subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y){
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank){
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank){
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}
>>>>>>> c1d0bf1862c1ac4f829490229942cd1614ec77a4
