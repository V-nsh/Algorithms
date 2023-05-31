#include<stdio.h>

int LRU(int *pages, int no_ps, int frames){
    int fr[frames];
    int index[no_ps];
    int faults = 0, hits = 0, flag = 1, j = frames, f1=0, f2 =0;

    // for(int i  =  0; i < frames; i++){
    //     fr[i] = pages[i];
    // }

    // for (int i = frames-1; i >=0; i--)
    // {
    //     for(int j = 0; j < frames; j++){
    //         if (pages[i] == index[j])
    //         {
    //             f1 = 1;
    //         }
    //     }
    //     if(flag == 0){
    //     index[i] = pages[j];
    //     }
    //     printf("%d\t", index[i]);
    // }
    
    
    for (int i = 0; i < frames; i++)
    {
        fr[i] = pages[i];
        index[i] = -1;
        for (int j = frames-1; j >= 0; j--)
        {
            if (index[j] != pages[i])
            {
                index[j] = pages[i];
            }
        }
        // printf("%d\t", index[i]);
        faults++;
    }

    for (int i = frames; i < no_ps; i++)
    {
        flag = 1;
        for(int j = frames; j < no_ps; j++){
            if (fr[j] == pages[i])
            {
                hits++;
                flag = 0;
                faults--;
            }
        }

        faults++;

        for(int m = i; m >=0; m--){
            for(int n = 0; n <i; n++){
                if(pages[m] == index[n]){
                    f2 = 1;
                }
            }
        }
        
        if(f2 == 0){
            index[i] = pages[i];
        }

        if (flag  == 1)
        {
            int temp  = index[0];
            for (int k = 0; k < frames; k++)
            {
                if(fr[k] == temp){
                    temp = k;
                }
            }
            
            fr[temp] = index[frames-1];
            // index[i] = pages[i];

            for (int l = 0; l < i; l++)
            {
                index[l] = index[l+1];
                if(l == i-1){
                    index[l] = pages[i];
                }
            }
            
        }
        // printf("%d\t", index[i]); 
    }
    

    for (int i = 0; i < no_ps; i++)
    {
        printf("%d\t", index[i]); 
    }
    return hits;
}

int main(){
    // int pages[50];
    int frames  = 3;

    int pages[20] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int no_ps = 15;

    int hits = LRU(pages, no_ps, frames);
    // LRU(pages, no_ps, frames);
    printf("\n%d", hits);

    return 0;
}