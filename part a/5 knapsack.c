#include<stdio.h>
#include<stdlib.h>

int n, W, w [10], v[10], V[10][10], x[10];

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

void print(){
    int i, j;
    i = n, j = W;

    while(i != 0 && j != 0){
        if(V[i][j] != V[i-1][j]){
            x[i] = 1;
            j = j - w[i];
        }
        i = i-1;
    }

}

int main(){
    int i, j;

    printf("Read no of objects\n");
    scanf("%d", &n);

    printf("Read weights of objects\n");
    for(i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }

    printf("Read the profits\n");
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }

    printf("Read knapsack capacity\n");
    scanf("%d", &W);

    for(i = 0; i <= n; i++){
        for(j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                V[i][j] = 0;
            }
            else if(j - w[i] < 0){
                V[i][j] = V[i-1][j];
            }
            else{
                V[i][j] = max(V[i-1][j], V[i-1][j - w[i]] + v[i]);
            }
        }
    }
    print();
    printf("Max profit is %d\n", V[n][W]);
    printf("Objects inclded are \n");
    for(i = 1; i <= n; i++){
        if(x[i] == 1){
            printf("%d object is included\n", i);
        }
    }

}