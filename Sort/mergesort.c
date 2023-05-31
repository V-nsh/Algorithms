#include<stdio.h>

void merge(int a[], int b[], int beg, int mid, int end){
    int i = beg;
    int j = mid;

    for (int k = beg; k < end; k++)
    {
        if (i<mid && (j>= end || a[i]<=a[j]))
        {
            b[k]= a[i];
            i++;
        }else{
            b[k] = a[j];
            j++;
        }
        
    }
    
}

void split(int b[], int a[], int beg, int end){
    if(end - beg <= 1){
        return;
    }
    int mid = (end-beg)/2;

    split(a, b, beg, mid);
    split(a,b, mid, end);

    merge(b, a, beg, mid, end);
}

void copyarr(int a[], int b[], int beg, int end){
    for(int i = beg; i<end; i++){
        b[i] = a[i];
    }
}

void mergsort(int a[], int b[], int size){
    copyarr(a, b, 0, size);
    split(b, a, 0, size);
}

void printAr(int *arr, int count){
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[10] = {91,31,105,2,27,53,298,8,917,10};
    int b[10];
    mergsort(arr, b, 10);
    printAr(arr, 10);
    return 0;
}

// void mergSrt(int x[], int n){
//     int aux[100];
//     int i,j,k, l1, l2, u1, u2, size;
//     size = 1;

//     while(size < n){
//         l1 = 0;
//         k = 0;
//         while(l1 + size <n){
//             l2 = l1+size;
//             u1 = l2-1;
//             u2 = (l2+size-1 < n)? l2+size-1 : n-1;

//             for(i = l1, j = l2; i<= u1 && j<=u2; k++){
//                 if(x[i]<=x[j]){
//                     aux[k] = x[i++];
//                 }else{
//                     aux[k] = x[j++];
//                 }
//             }
//             for(; i<= u1; k++){
//                 aux[k] = x[i++];
//             }
//             for(;j<=u2; k++){
//                 aux[k] = x[i++];
//             }
//             l1 =u2+1;
//         }
//         for(i = l1; k<n; i++ ){
//             aux[k++] = x[i];
//         }
//         for ( i = 0; i < n; i++)
//         {
//             x[i] = aux[i];
//         }
//         size*=2;
//     }
// }