#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *prefix(char *p){
    int m = strlen(p);
    int *pi = (int*)malloc(m*sizeof(int));
    pi[0] = 0;
    int k = 0;

    for(int q = 1; q<m; q++){
        // if((p[k+1] != p[q])){
        //     k = pi[k-1];
        //     q--;
        //     // k = q;
        // }
        // if(p[k+1] == p[q]){
        //     k++;
        //     pi[q] = k;
        // }else{
        //     pi[q] = 0;
        // }

        if(p[q] == p[k]){
            k++;
            pi[q] = k; 
        }else{
            if(k != 0){
                k = pi[k-1];
                k--;
            }else{
                pi[q] = 0;
            }
        }
        // pi[q] = k;
    }
    return pi;
}

void kmp(char  *t, char *p){
    int n = strlen(t);
    int m = strlen(p);
    int *pi = prefix(p);
    int q = 0;
    int j = 0, i =0;

    while(i<n)
    {
        if(t[i] == p[j]){
            i++,j++;
        }

        if(j == m){
            printf("\nPattern found at shift: %d", i-j);
            q++;
            j = pi[j-i];
        }
        if( i <n && (p[j] != t[i])){
            if(j != 0){
                j = pi[j-1];
            }else{
                i++;
            }
        }
    }
    
}

// Vansh Purohit SE3 42
int main(){
    char text[50] = "abaabbaaabbb";
    // char pat[10] = "ababd";//00120
    char pat[50] = "aabb";
    int m = strlen(text);
    int n = strlen(pat);
    printf("Text:");
    for (int i = 0; i < m; i++)
    {
        printf("%c", text[i]);
    }
    printf("\nPattern:");
    for (int i = 0; i < n; i++)
    {
        printf("%c", pat[i]);
    }
    
    kmp(text, pat);

    return 0;
}