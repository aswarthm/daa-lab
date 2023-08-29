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
    int i, j, n, a[MAX], b[MAX], c[MAX];
    int c1, c2, c3;

    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    count = 0;
    mergeSort(a, 0, n-1);
    printf("The sorted elements are: ");
    for(i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("Count = %d\n", count);

    printf("Size \t Asc \t Desc \t Rand \n");

    for(i = 16; i < 600; i = i*2){
        for(j = 0; j < i; j++){
            a[j] = j;
            b[j] = i - j;
            c[j] = rand()%i;
        }

        count = 0;
        mergeSort(a, 0, i-1);
        c1 = count;

        count = 0;
        mergeSort(b, 0, i-1);
        c2 = count;

        count = 0;
        mergeSort(c, 0, i-1);
        c3 = count;

        printf("%d \t %d \t %d \t %d \n", i, c1, c2, c3);
    }
    printf("\n");
    return 0;
}

