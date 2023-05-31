#include <stdio.h>

struct process{
    int burst;
    int turnTime;
    int arrivalTime;
    int wait;
};

double calcwait(struct process* p, int num){
    int curw = 0;
    double avgwait;
    
    for (int i = 0; i < num; i++)
    {
        p[i].wait = p[i].burst;
    }
    

    for (int i = 0; i < num-1; i++)
    {
        curw += p[i].wait;
        p[i].wait = curw - p[i+1].arrivalTime;
        printf("%d %d\n", p[i].wait, p[i+1].arrivalTime);
    }
    
    for(int i=0;i<num-1;i++){
        avgwait += p[i].wait;
    }

    avgwait = avgwait/num;
    return avgwait;
}

double calcturn(struct process* p, int num){
    // printf("\n");
    // for (int i = 0; i < num; i++)
    // {
    //     printf("burst time of p%d: %d\n", i, p[i].burst);
    //     printf("Arrival time of p%d: %d\n", i, p[i].arrivalTime);
    // }
    
    int curw = 0;
    double avgturn = 0.0;
    for (int i = 0; i < num; i++)
    {
        curw += p[i].burst;
        p[i].wait = curw;

        p[i].turnTime = p[i].wait - p[i].arrivalTime;
        avgturn += p[i].turnTime;
    }
    
    avgturn = avgturn/num;
    
    return avgturn;
}

int main(){
    struct process p[50];
    int num, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter burst time of process %d :" , i);
        scanf("%d", &p[i].burst);
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter arrival time of process %d :", i);
        scanf("%d", &p[i].arrivalTime);
    }

    printf("The average waiting time is: %.2f", calcwait(p, num));
    printf("\nThe average turnaround time is: %.2f", calcturn(p, num));

    return 0;
}