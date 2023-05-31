#include <stdio.h>

void insertionSort(int *arr, int num)
{
    int y, j, count = 0, comp = 0;
    for (int i = 1; i < num; i++)
    {
        y = arr[i];
        comp++;
        for (j = i - 1; j >= 0 && y < arr[j]; j--)
        {
            count++;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = y;
    }
    printf("\nnumber of comparisons: %d\n", comp);
    printf("number of swaps: %d\n", count);
}

void printAr(int *arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // int arr[10] = {91,31,105,2,27,53,298,8,917,10};
    int arr[5] = {21, 1, 11, 98, 54};

    insertionSort(arr, 5);

    printf("The sorted array is:\n");
    printAr(arr, 5);
    return 0;
}