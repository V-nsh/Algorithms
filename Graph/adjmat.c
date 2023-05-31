#include<stdio.h>

struct Adjmat{
    // int **arr;
    int weight;
};

void initmat(int vert){
    struct Adjmat **mat = (struct Adjmat**)malloc(sizeof(struct adjmat**)*vert);
    for (int i = 0; i < vert; i++)
    {
        for (int j = 0; j < vert; j++)
        {
            mat[i][j].weight = 0;
        }
        
    }
    
}

void addedge(struct Adjmat **arr,int i, int j, int w){
    arr[i][j].weight = w;
}