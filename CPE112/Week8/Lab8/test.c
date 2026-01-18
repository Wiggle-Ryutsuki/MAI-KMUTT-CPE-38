#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICE 100

typedef struct Graph{
    int nV; // number of nodes,vertice
    bool adj[MAX_VERTICE][MAX_VERTICE]; //adjacent table
}Graph;

Graph* createGraph(int vertice){ // init
    Graph *g = malloc(sizeof(Graph));
    g->nV = vertice;
    for(int i=0;i<vertice;i++){
        for(int j=0;j<vertice;j++){
            g->adj[i][j]= false;
        }
    }
    return g;
}
void addEdge(Graph* g, int src, int dest){
    g->adj[src][dest] = true;
    g->adj[dest][src] = true;
}


int main(){
    int vertice, edge;
    int src, dest;
    scanf("%d %d",&vertice, &edge);

    Graph *g = createGraph(vertice);

    for(int i=0;i<edge;i++){
        scanf("%d %d",&src,&dest);
        addEdge(g, src, dest);
    }

    // for(int i=0;i<vertice;i++){
    //     for(int j=0;j<vertice;j++){
    //         printf("%d ",g->adj[i][j]);
    //     }
    //     printf("\n");
    // }
    int count;
    int checkSrc, checkDest;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%d %d",&checkSrc, &checkDest);
        if(g->adj[checkSrc][checkDest] == true){
            printf("%d %d are in the graph.\n", checkSrc, checkDest);
        }
        else{
            printf("%d %d are not in the graph.\n", checkSrc, checkDest);
        }
    }
}