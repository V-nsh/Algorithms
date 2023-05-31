#include<stdio.h>
#include<time.h>
//Vansh Purohit SE3 42
int count, swap;

void printAr(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}


int partition(int *arr, int p, int r){
    int temp;
    int x = arr[r];
    int i = p-1;
    for(int j = p; j<=r-1; j++){
        count++;
        if (arr[j]< x)
        {
            swap++;
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    printf("\n");
    printAr(arr, 10);
    return i++;
}

void quicksort(int *arr, int p, int r){
    int q;
    if (p<r)
    {
        q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
    
}

// void printAr(int *arr, int count){
//     for (int i = 0; i < count; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

int main(){

    clock_t tStart = clock();

    int arr[11] = {91,31,105,2,27,53,298,8,917,10};
    // int arr[10] = {10, 5, 8, 9, 3, 6, 15, 12};

    quicksort(arr,0, 9);
    printf("\n");
    printAr(arr, 10);
    printf("\nNumber of comparisons: %d", count);
    printf("\nNumber of swaps: %d", swap);
    printf("\nTotal Number of Operations: %d\n", count + swap);

    printf("\nTime taken: %fs", (double)(clock()-tStart)/CLOCKS_PER_SEC);

    return 0;
}