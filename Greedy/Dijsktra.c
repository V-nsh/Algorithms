#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int vert;

struct adjMat{
    int dist;
    int cost;
};

void initmat(struct adjMat adjmat[vert][vert], int vert, int edge){
    // struct adjMat adjmat[vert][vert];
    //struct adjMat** adjmat = malloc(sizeof(struct adjMat)*vert*vert*sizeof(int**));

    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; i < vert; i++)
        {
            // adjmat[i][j].dist = -1;
            adjmat[i][j].cost = 0;

        }
        
    }
}

void addedge(struct adjMat arr[vert][vert],int i, int j, int w){
    arr[i][j].dist = __INT_MAX__;
    arr[i][j].cost = w;
}

void dijsktra(struct adjMat adjmat[vert][vert], int vert){
    int path[vert];
    int final = 0;

    printf("The shortest path is : 1\n");
    for (int i = 0; i < vert-1; i++)
    {
        for (int j = 0; i < vert; i++)
        {
            if(adjmat[i][j].cost!=0 && (final < adjmat[i][j].dist)){
                final = final + adjmat[i][j].cost;
                adjmat[i][j].dist = final;
                path[i] = i;
                printf("%d", i);
            }
        }
        // printf("%d>", path[i]);
    }
    printf("\nDistance to reach the final vertex: %d", final);
}

int main(){
    int edge, wt, stedge, stvert;
    printf("Enter the number of edges :\n");
    scanf("%d", &edge);
    printf("\nEnter the number of vertices :\n");
    scanf("%d", &vert);

    // struct adjMat **adjmat = malloc(sizeof(struct adjMat)*(vert*vert));
    struct adjMat adjmat[vert][vert];
    // adjmat = initmat(adjmat, vert, edge);
    initmat(adjmat, vert, edge);

    for (int i = 0; i < edge; i++)
    {
        printf("Enter the starting vertex of edge %i: ", i+1);
        scanf("%d", &stedge);
        printf("Enter the tailing vertex of edge %i: ", i+1);
        scanf("%d", &stvert);
        printf("Enter the distance between these vertices: ");
        scanf("%d", &wt);
        addedge(adjmat, stedge, stvert, wt);
    }

    dijsktra(adjmat, vert);
    
    return 0;
}