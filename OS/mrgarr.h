#include<stdio.h>

struct process{
    int burst;
    int remburst;
    int wait;
    int arrival;
    int comp;
};

void mergArr(struct process* p, int l, int m, int r){
    int ppoint = l, bpoint = 0, cpoint = 0, blimit, climit, i,j;

    blimit = m-l+1;
    climit = r-m;

    struct process b[blimit];
    struct process c[climit];

    for ( i = 0; i < blimit; i++)
    {
        b[i] = p[l+i];
    }
    
    for ( j = 0; j < climit; j++)
    {
        c[j] = p[m+j+1];
    }
    
    for ( ; bpoint<blimit && cpoint< climit; ppoint++)
    {
        if (b[bpoint].arrival < c[cpoint].arrival)
        {
            p[ppoint] =b[bpoint++];
        }else{
            p[ppoint] = c[cpoint++];
        }
        
    }

    while(bpoint <blimit){
        p[ppoint++] = b[bpoint++];
    }
    
    while(cpoint < climit){
        p[ppoint] = c[cpoint++];
    }

}

void mergSrt(struct process* p, int l, int r){
    if(l<r){
        int m = l + (l-r)/2;
        mergSrt(p, l,m);
        mergSrt(p, m+1, r);

        mergArr(p, l, m, r);
    }
}