#include<stdio.h>
#include "mrgarr.h"
#include<stdbool.h>

// struct process{
//     int burst;
//     int remburst;
//     int wait;
//     int arrival;
//     int comp;
// };

double avgWait(struct process* p, int num, int quant){
    int curw = 0, i =0;
    int j  = 0 ;
    double avgwait = 0.0;
    bool done = true;

    // mergSrt(p, 0, num);

    for (int i = 0; i < num; i++)
    {
        p[i].wait =p[i].burst;
        p[i].remburst =p[i].burst;
    }
    while(done){
        for (; j<num; j++)
        // while(p[j].remburst > 0)
        {   
            if(p[j].remburst > 0){
                if (quant < p[j].remburst)
                {
                    curw += quant;
                    p[j].remburst -= quant;
                    p[j].wait =  curw;
                }
                else{
                    curw += p[j].remburst;
                    p[j].remburst = 0;
                    p[j].wait =  curw;

                }
            }
            done = true;
            for ( i = 0; i < num; i++)
            {
                if(p[i].remburst != 0){
                    done = false;
                }
            }
        printf("\n Finding wait:\n remburst of process %d: %d",i, p[i].remburst);
            
            // j++;
        }
        // i++;
        // printf("\n Finding wait:\n remburst of process %d: %d",i, p[i].remburst);
    }

    printf("\n");
    for (int i = 0; i < num; i++)
    {
        printf("burst time of p%d: %d\n", i, p[i].burst);
        printf("Arrival time of p%d: %d\n", i, p[i].arrival);
        printf("Wait time of p%d: %d\n", i, p[i].wait);
        printf("\n");
        avgwait += p[i].wait;
    }
    
    avgwait = avgwait/num;
    return avgwait;
}

int main(){
    struct process p[50];
    int num, quant;
    printf("Enter the number of processes: ");
    scanf("%d", &num);

    printf("Enter the time quantum: ");
    scanf("%d",&quant);

    for (int i = 0; i < num; i++)
    {
        printf("Enter burst time of process %d :" , i);
        scanf("%d", &p[i].burst);
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter arrival time of process %d :", i);
        scanf("%d", &p[i].arrival);
    }

    avgWait(p, num, quant);

    return 0;
}