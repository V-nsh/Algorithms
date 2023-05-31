#include<stdio.h>
#include<limits.h>
#define max 50

struct Complete{
    int iscompleted;
    int id;
    int bTime;
    int aTime;
    int ct;
    int cl;
    int waiting;
    int tAroundTime;
    int isEnqueue;
};

int n,time=0,compProc=0,co=0,co_in=0;
struct Complete a[max],b[max];
int main()
{
    int timeQ;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the time quantum: ");
    scanf("%d",&timeQ);

    for(int i=0;i<n;i++)
    {
        printf("Enter the process id : ");
        scanf("%d",&a[i].id);
        printf("Enter the burst time of process %d : ",a[i].id);
        scanf("%d",&a[i].bTime);
        a[i].iscompleted = a[i].isEnqueue = 0;
        printf("Enter the arrival time of process %d : ",a[i].id);
        scanf("%d",&a[i].aTime);
    }

    printf("\nProcesss \tCPU Burst \tArival Time\t\n");
    printf("\n-------------------------------------------------\n");

    for(int i=0;i<n;i++)
    {
        printf("\n\tP%d\t\t%d\t\t%d\t\n",a[i].id,a[i].bTime,a[i].aTime);
    }

    printf("Time Quantum : %d \n",timeQ);

    int e=-1,d=0;
    struct Complete temp,temp_sort;
    struct Complete pendingProcess;
    pendingProcess.aTime = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(a[j].aTime>a[j+1].aTime)
            {
                temp_sort=a[j];
                a[j]=a[j+1];
                a[j+1]=temp_sort;
            }
        }
    }

    printf("\nProcesss \tCPU Burst \tArival Time\t\n");
    printf("\n-------------------------------------------------\n");

    for(int i=0;i<n;i++)
    {
        printf("\n\tP%d\t\t%d\t\t%d\t\n",a[i].id,a[i].bTime,a[i].aTime);
    }

    while(compProc!=n)
    {
        if(co_in < n)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i].aTime <= time && a[i].isEnqueue == 0 && a[i].bTime > 0)
                {
                    e = (e+1) % max;
                    b[e]=a[i];
                    a[i].isEnqueue = 1;
                    co++;

                    co_in++;
                }
            }
        }

        if (pendingProcess.aTime != INT_MIN)
        {
            e=(e+1)%max;
            b[e] = pendingProcess;
            pendingProcess.aTime = INT_MIN;
            co++;
        }

        if(e>-1&&co>0)
        {
            temp=b[d];
            d=(d+1)%max;
            co--;
            if(temp.bTime > timeQ)
            {
                temp.bTime-=timeQ;
                time+=timeQ;
                temp.aTime=time;
                pendingProcess = temp;
            }
            else
            {
                time+=temp.bTime;
                temp.aTime=time;
                temp.bTime=0;
                temp.iscompleted=1;
                temp.cl = time;
                compProc++;

                pendingProcess.aTime = INT_MIN;
            }

            for (int k=0;k<n;k++)
            {
                if (temp.id == a[k].id)
                {
                    a[k].cl = temp.cl;
                    break;
                }
            }
        }
        else
            time++;
    }

    float avg=0;

    for(int i=0;i<n;i++)
    {
        a[i].tAroundTime = a[i].cl - a[i].aTime;
        a[i].waiting = a[i].tAroundTime - a[i].bTime;
        printf("\nP%d : %d\n",i,a[i].waiting);
        avg += a[i].waiting;
    }

    printf("AVG - %f ",avg/n);
}