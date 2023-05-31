#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int source;
    int dest;
    int weight;
};

struct Graph{
    int vert;
    int edge;
    struct Edge* edges;
};

struct Graph* createGraph(int v, int e){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vert = v;
    graph->edge = e;
    graph->edges = (struct Edge*)malloc(graph->edge*sizeof(struct Edge));

    return graph;
}

int find(int parent[], int vert){
    if(parent[vert] == vert){
        return vert;
    }else{
        return find(parent, parent[vert]);
    }
}

void uni(int parent[], int x, int y){
    parent[x] = y;
}

// int findCycle(struct Graph* graph){
//     int parent[graph->vert];
//     for (int i = 0; i < graph->vert; i++)
//     {
//         parent[i] = -1;
//     }
    
//     for (int i = 0; i < graph->vert; i++)
//     {
//         int x = find(parent, graph->edges[i].source);
//         int y = find(parent, graph->edges[i].dest);

//         if(x==y){
//             return 1;
//         }
//         uni(parent, x, y);
//     }
    
//     return 0;
// }

void sortedge(struct Graph* graph){
    struct Graph* temp = createGraph(graph->vert, graph->edge);
    for (int i = 0; i < graph->edge; i++)
    {
        for(int j =0; j< graph->edge; j++){
            if(graph->edges[j].weight > graph->edges[j+1].weight){
                temp[j] = graph[j];
                graph[j] = graph[j+1];
                graph[j+1] = graph[j];
            }
        }
    }
    
}

void kruskal(struct Graph* graph){
    // struct Graph* mst = createGraph(graph->vert, graph->edge);
    int count  = 0;
    sortedge(graph);
    int cost;
    int parent[graph->vert];
    printf("Edges : %d\nVertices: %d\n", graph->edge, graph->vert);

    printf("test\n");

    for (int i = 0; i < graph->edge; i++)
    {
        printf("\ntest\n");
        count++;
        int x = find(parent, graph->edges[i].source);
        int y = find(parent, graph->edges[i].dest);

        if (x==y)
        {
            continue;
        }else{
            uni(parent, x, y);
            cost += graph->edges[i].weight;
        }
        
    }

    printf("The minimm cost is: %d count:%d", cost, count);
}

int main(){
    int vert, edge;
    printf("Enter the number of vertices:");
    scanf("%d", &vert);
    printf("Enter the number of edges:");
    scanf("%d", &edge);
    struct Graph* graph = createGraph(vert, edge);

    for (int i = 0; i < edge; i++)
    {
        printf("Enter source of edge %i:", i+1);
        scanf("%d", &graph->edges[i].source);
        printf("Enter the destination vertex of edge %i:", i+1);
        scanf("%d", &graph->edges[i].dest);
        printf("Enter cost of edge %i:", i+1);
        scanf("%d", &graph->edges[i].weight);
    }

    printf("Edges : %d\nVertices: %d\n", graph->edge, graph->vert);

    for (int i = 0; i < edge; i++)
    {
        printf("Edge%d: %d\n", i, graph->edges[i].weight);
    }
    

    kruskal(graph);

    return 0;
}