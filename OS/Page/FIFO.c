#include<stdio.h>

int pfaults(int *pages, int no_ps, int frames){
    int faults  = 0, hit = 0, flag  = 1;
    int fr[frames];

    for (int i = 0; i < no_ps; i++)
    {
        flag  =1;
        for (int j = 0; j < frames; j++)
        {
            if (fr[j] == pages[i])
            {
                hit++;
                flag  = 0;
                faults--;
            }
        }
        faults++;
        if (flag  == 1)
        {
            fr[(faults-1)%frames] = pages[i];
        }
    }
    return hit;
}

int main(){
    // int pages[50];
    int frames  = 3;

    int pages[20] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int no_ps = 15;

    int faults = pfaults(pages, no_ps, frames);
    printf("%d", faults);

    return 0;
}