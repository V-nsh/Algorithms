#include<stdio.h>
#include<time.h>


void mergArr(int *a, int l, int m, int r){
    int apoint = l, bpoint=0, cpoint=0, blimit, climit, i, j;
    
    blimit = m-l+1;
    climit = r-m;

    int b[blimit];
    int c[climit];

    
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
        if(b[bpoint] < c[cpoint]){
            a[apoint] = b[bpoint++];
        }else{
            a[apoint] = c[cpoint++];
        }
    }
    
    while(bpoint < blimit){
        a[apoint++] = b[bpoint++];
    }

    while (cpoint< climit)
    {
        a[apoint++] = c[cpoint++];
    }
    
}

void mergSrt(int arr[], int l, int r){

    if(l<r){
        int m = l+(r-l)/2;
        mergSrt(arr, l,m);
        mergSrt(arr, m+1, r);

        mergArr(arr, l, m , r);
    }
}
void printAr(int arr[], int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}