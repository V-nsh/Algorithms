#include<stdio.h>
#include<stdlib.h>

// struct Rat{
//     float ratio;
//     int weight;
//     int value;
// };

struct Edge{
    int src, dest, weight;
};

struct Graph{
    int v, e;
    int *parent;
    struct Edge* edge;
};

void mergArr(struct Graph *a, int l, int m, int r){
    int apoint = l, bpoint=0, cpoint=0, blimit, climit, i, j;
    
    blimit = m-l+1;
    climit = r-m;

    struct Graph b[blimit];
    struct Graph c[climit];


    for (i = 0; i < blimit; i++)
    {
        b[i] = a[l+i];
    }
    
    for (j = 0; j < climit; j++)
    {
        c[j] = a[m+j+1];
    }
    
    for (; bpoint<blimit && cpoint < climit; apoint++ )
    {

        if(b[bpoint].edge->weight < c[cpoint].edge->weight){
            a[apoint] = b[bpoint++];
        }else{
            a[apoint] = c[cpoint++];
        }
    }

    while (bpoint< blimit)
    {
        a[apoint++] = b[cpoint++];
    }
    
    while(cpoint < climit){
        a[apoint++] = c[bpoint++];
    }
}

void mergSrt(struct Graph *arr, int l, int r){

    if(l<r){
        int m = l+(r-l)/2;
        mergSrt(arr, l,m);
        mergSrt(arr, m+1, r);

        mergArr(arr, l, m , r);
    }
}