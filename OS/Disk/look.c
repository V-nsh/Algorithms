#include<stdio.h>
#include<stdlib.h>

int main(){
    int num, init, total = 0, side, temp, index;
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

    printf("Enter 1 for high and 0 for lower side head moment:");
    scanf("%d", &side);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }

    for (int i = 0; i < num; i++)
    {
        if (init < arr[i])
        {
            index = i;
            break;
        }
        
    }
    
    if(side == 1)
    {
        for (int i = index; i < num; i++)
        {
            total += abs(arr[i]-init);
            init = arr[i];
        }

        for(int i = index-1; i >= 0; i--){
            total += abs(arr[i]-init);
            init = arr[i];
        }
        
    }else{
        for(int i = index-1; i >= 0; i--){
            total += abs(arr[i]-init);
            init  = arr[i];
        }

        for(int i = index; i< num; i++){
            total+= abs(arr[i]- init);
            init = arr[i];
        }
    }
    

    printf("Total seek time: %d", total);

    return 0;
}