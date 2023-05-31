#include<stdio.h>
#include<time.h>
int count, swap;

void mergArr(int *a, int l, int m, int r){
    int apoint = l, bpoint=0, cpoint=0, blimit, climit, i, j;
    
    blimit = m-l+1;
    climit = r-m;

    int b[blimit];
    int c[climit];

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

int main(){
    // int arr[5]  = {1,11,21,54,89};
    clock_t tStart = clock();
    int arr[10] = {91,31,105,2,27,53,298,8,917,10};
    mergSrt(arr, 0, 9);

    printAr(arr, 10);

    printf("\nNumber of splits: %d", count);
    printf("\nNumber of swaps: %d", swap);
    printf("\nTotal Number of Operations: %d\n", count + swap);

    printf("\nTime taken: %fs", (double)(clock()-tStart)/CLOCKS_PER_SEC);
    return 0;
}