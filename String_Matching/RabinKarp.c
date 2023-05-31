#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// int hashFunc(char *p, char *t){
//     int num = strlen(p);
//     int index = 0, ind1 =0;
//     for (int i = num; i >= 0; i--)
//     {
//         index += p[i]*(pow(10,i));
//         printf("index at power %d: %d\n", i, index);
//     }

//     printf("%d",index);
//     return index;
// }

int rbkp(char *p, char *t){
    int m = strlen(p);
    int n = strlen(t);
    int k;
    int prime = 5381;
    int p_hash = 0;
    int t_hash = 0;

    for (int i = 0; i < m; i++)
    {
        p_hash = p_hash*10 + ((p[i]-'0')%prime);
        t_hash = t_hash*10 + ((t[i]-'0')%prime);
    }

    for (int j = 0; j < n-m; j++)
    {
        if(t_hash == p_hash){
            for(k = 0; k<m; k++){
                if(t[j+k]!=p[k]){
                    break;
                }
            }
            if(k==m){
                printf("\nThe patter occurs at shift: %d", j);
            }
        }

        if (j < n-m)
        {
            t_hash = t_hash - (t[j]-'0')*pow(10,m-1);
            t_hash = t_hash*10 + (t[j+m]-'0');

            if(t<0){
                t += prime;
            }
        }
        
    }
    
}

int main(){
    char ch[50] = "abaabbaaabbb";
    char pat[50] = "aabb";
    rbkp(pat,ch);

    return 0;
}