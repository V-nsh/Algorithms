#include<stdio.h>
#include<string.h>

void strMatch(char* t, char* p){
    int m = strlen(t);
    int n = strlen(p);
    int s=0;

    for(int i = 0; i<= m-n; i++){
        int j;
        for(j=0; j<n; j++){
            if(t[i+j]!=p[j]){
                break;
            }
        }
        if(j==n){
            printf("\nThe pattern occurs at shift %d", i);
        }
    }
}

int main(){
    char t[50] = "abaabbaaabbb";
    char p[10] = "aabb";

    strMatch(t,p);

    return 0;
}