#include<stdio.h>

void selSort(int *arr, int num){
    int large, temp, lnum, count=0, comp=0;

    for (int i = num-1; i > 0; i--)
    {
        lnum = arr[0];
        large = 0;
        for (int j = 1; j <= i; j++)
        {
            count++;
            if (arr[j]>lnum)
            {
                comp++;
                large = j;
                lnum = arr[j];
            }
            
        }
        arr[large] = arr[i];
        arr[i] = lnum;
    }
    printf("\nnumber of comparisons: %d\n", count);
    printf("number of swaps: %d\n", comp);
}

void printAr(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    // int arr[10] = {91,31,105,2,27,53,298,8,917,10};
    int arr[5]  = {1,21,11,89,54};


    selSort(arr, 5);

    printf("The sorted array is:\n");
    printAr(arr, 5);
    return 0;
}