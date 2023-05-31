#include<stdio.h>

void bankers(int processes, int resources, int avail[resources], int alloc[processes][resources], int max[processes][resources]){
    int need[processes][resources];
    int seq[processes];
    int flag = 0, j, count = 0;

    for(int i = 0; i< processes; i++){
        for(int j = 0;j < resources; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < processes; i++)
        {
            flag  = 0;
            for (j = 0; j < resources; j++)
            {
                if (avail[j] > need[i][j])
                {
                    flag++;
                }
            }

            if (flag == resources)
            {
                seq[count] = i;
                count++;
                for (int l = 0; l < resources; l++)
                {
                    avail[l] += alloc[i][l];
                }
            }
        }
    }

    if(count == processes+1){
        seq[processes-1] = 0;
        
        printf("The process is in safe state.\n");
        printf("Safe Sequence is :\n");
        for (int i = 0; i < processes; i++)
        {
            printf("P%d -> ", seq[i]);    
        }
    }else{
        printf("The process is not in safe state.");
    }

    printf("\nNeeded resources:\n");
    for(int i = 0; i< processes; i++){
        for(int j = 0;j < resources; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }


}

int main(){
    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
 
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4
 
    int avail[3] = { 3, 3, 2 };
 

    bankers(5, 3, avail, alloc, max);

    return 0;
}