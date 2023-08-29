/*
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
0 0 1 0 1
0 0 1 0 0
*/

#include<stdio.h>
#include<stdlib.h>

int k = 1;
int res[10];

void dfs(int a[10][10], int n, int v[10], int source){
    int i;
    v[source] = 1;
    for(i = 1; i <= n; i++){
        if(a[source][i] == 1 && v[i] == 0){
            dfs(a, n, v, i);
        }
    }
    res[k++] = source;
}

int main(){
    int n, i, j, count;
    int a[10][10], v[10];

    printf("Enter the no of nodes\n");
    scanf("%d", &n);
    printf("Enter the Adjacency matrix\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 1; i <= n; i++){
        v[i] = 0;
    }
    printf("Topological ordering using dfs\n");
    for(i = 1; i <= n; i++){
        if(v[i] == 0){
            dfs(a, n, v, i);
        }
    }
    for(i = n; i >=1; i--){
        printf("%d\t", res[i]);
    }
    return 0;
}