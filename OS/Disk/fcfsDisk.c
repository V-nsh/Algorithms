#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, init, total = 0;
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

    for (int i = 0; i <num; i++){
        total += abs(arr[i]-init);
        init = arr[i];
    }

    printf("Total seek time: %d", total);

    return 0;
}