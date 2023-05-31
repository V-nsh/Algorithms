#include<stdio.h>
#include<stdlib.h>

struct Rat{
    float ratio;
    int weight;
    int value;
};

int count, swap;

void mergArr(struct Rat *a, int l, int m, int r){
    int apoint = l, bpoint=0, cpoint=0, blimit, climit, i, j;
    
    blimit = m-l+1;
    climit = r-m;

    struct Rat b[blimit];
    struct Rat c[climit];

    count++;
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
        swap++;
        if(b[bpoint].ratio >= c[cpoint].ratio){
            a[apoint] = b[bpoint++];
        }else{
            a[apoint] = c[cpoint++];
        }
    }

    while (cpoint< climit)
    {
        a[apoint++] = c[cpoint++];
    }
    
    while(bpoint < blimit){
        a[apoint++] = b[bpoint++];
    }
}

void mergSrt(struct Rat *arr, int l, int r){

    if(l<r){
        int m = l+(r-l)/2;
        mergSrt(arr, l,m);
        mergSrt(arr, m+1, r);

        mergArr(arr, l, m , r);
    }
}