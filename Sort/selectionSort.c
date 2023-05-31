#include<stdio.h>

void selSort(int* arr, int num){
    int min, temp, comp = 0, count =0;
    for (int i = 0; i < num-1; i++)
    {
        min = i;
        for (int j = i+1; j < num; j++)
        {
            count++;
            if(arr[j] < arr[min]){
                comp++;
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        
    }
    printf("number of comparisons: %d\n", count);
    printf("number of swaps: %d\n", comp);
}

int main(){
    int arr[10] = {91,31,105,2,27,53,298,8,917,10};

    selSort(arr, 10);


    printf("The sorted array is:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}