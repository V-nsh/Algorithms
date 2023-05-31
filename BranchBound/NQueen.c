#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int board[20];
int arr[20],c=0;

void queen(int row,int n);

int main()
{
    int n,i,j;
    printf("\n\nEnter number of Queens: ");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}

void print(int n)
{
    int i,j;
    if(c==0)
    {
        printf("\n\n Solution is :\n\n");
        for(i=1;i<=n;++i)
            printf("\t%d",i);

        for(i=1;i<=n;++i)
        {
            printf("\n\n%d",i);
            for(j=1;j<=n;++j) //for nxn board
            {
                if(board[i]==j)
                    printf("\tQ"); //queen at i,j position
                else
                    printf("\t-"); //empty slot
            }
        }

        printf("\n\nArray of columns of queens:\n");
        printf("[");

        for(i=1;i<=n;++i)
            printf("%d ",arr[i]);

        printf("]");
        c=1;
    }
}

int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        //checking column and digonal conflicts
        if(board[i]==column)
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))
                return 0;
    }
    return 1; //no conflicts
}

void queen(int row,int n)
{
    int column;
    for(column=1;column<=n;++column)
    {
        if(place(row,column))
        {
            board[row]=column;
            arr[row]=column;
            
            if(row==n)
                print(n);
            else
                queen(row+1,n);
        }
    }
}