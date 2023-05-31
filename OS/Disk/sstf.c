#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, init, total = 0, min, n, index;
    int arr[50];

    printf("Enter number of requests: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter request %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter initial position: ");
    scanf("%d", &init);

    for (int i = 0; i < num; i++)
    {
        min = 9999;
        for (int j = 0; j < num; j++)
        {
            n = abs(arr[j]-init);
            if(min > n){
                min = n;
                index = j;
            }
        }
        total += min;
        init = arr[index];

        arr[index] = 9999;
        
    }

    printf("Total seek time: %d", total);

    return 0;
}