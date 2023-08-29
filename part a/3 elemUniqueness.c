#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int count;

void merge(int a[MAX], int low, int mid, int high){
    int i, j, k, b[MAX];
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }        
        count++;
    }
    while(i <= mid){
        b[k++] = a[i++];
        //count++;
    }
    while(j <= high){
        b[k++] = a[j++];
        //count++;
    }
    for(i = low; i <= high; i++){
        a[i] = b[i];
    }
}

void mergeSort(int a[MAX], int low, int high){
    int mid;
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(){
    int a[MAX], b[MAX], c[MAX];
    int i, j, n, c1, c2, c3;
    int ret = 0;

    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n-1);
    for(i = 0; i < n-2; i++){
        if(a[i] == a[i+1]){
            ret = 1;
            break;
        }
    }
    
    if(ret){
        printf("Array contains duplicate elements\n");
    }
    else{
        printf("Array contains unique elements\n");
    }

    return 0;
}

