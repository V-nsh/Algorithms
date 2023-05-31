#include<stdio.h>
#include<stdlib.h>
#include"mrg.h"

struct Item{
    int weight;
    int value;
};

// struct Ratio{
//     float ratio;
//     int weight;
//     int value;
// };

struct Item *narr(int num){
    struct Item *arr = (struct Item *)malloc(sizeof(int)*num);
    int k;
    for (int i = 0; i < num; i++)
    {
        printf("\nInput weight:");
        scanf("%d", &k);
        arr[i].weight = k;
        printf("\nEnter Value:");
        scanf("%d", &k);
        arr[i].value = k;
    }
    return arr;
}

void knap(struct Item *arr, int wt, int num){
    
    int j, i =0;
    float ratio;
    struct Rat ratarr[num];
    int curw = 0;
    float max = 0.0;
    
    for (int i = 0; i < num; i++)
    {
        ratio = (float)arr[i].value/arr[i].weight;
        ratarr[i].ratio = ratio;
        ratarr[i].value = arr[i].value;
        ratarr[i].weight = arr[i].weight;
    }

    mergSrt(ratarr, 0, num);
    printf("\nSorted ratio:");
    for(int k = 0; k < num; k++){
        printf("\nweight:%d value:%d", ratarr[k].weight, ratarr[k].value);
    }

    for ( i = 0; i < num; i++)
    {
        if(curw + ratarr[i].weight <= wt){
            curw += ratarr[i].weight;
            max += (float)ratarr[i].value;
            printf("\n(if)Adding weight:%d and Value:%d", ratarr[i].weight, ratarr[i].value);

        }
        else{
            j = wt - curw;
            max += (ratarr[i].value*(j/(float)ratarr[i].weight));
            curw = wt+1;
            printf("\nAdding weight:%d and Value:%0.2f", j, ratarr[i].value*((float)((float)j/ratarr[i].weight)));
            break;
        }
    }
    printf("\nNet profit: %.2f", max);
}

void delarr(struct Item *arr){
    free(arr);
}

int main(){
    int num, wt;
    printf("Enter the number of items:\n");
    scanf("%d", &num);

    printf("\nEnter the maximum weight of sack: ");
    scanf("%d", &wt);

    struct Item *arr = narr(num);

    knap(arr, wt, num);

    delarr(arr);
    return 0;
}