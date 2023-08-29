#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int table[1000];

void shifttableComputation(char p[]){
    int m, i, j;

    m = strlen(p);
    for(i = 0; i < 1000; i++){
        table[i] = m;
    }
    for(j = 0; j <= m-2; j++){
        table[p[j]] = m-1-j;
    }
}

int horspool(char p[], char t[]){
    int m, n, i, j, k;

    shifttableComputation(p);

    m = strlen(p);
    n = strlen(t);

    i = m-1;
    while(i <= n-1){
        k = 0;
        while((k <= m-1) && t[i-k] == p[m-1-k]){
            k++;
        }
        if(k == m){
            return i-m+1;
        }
        else{
            i = i + table[t[i]];
        }
    }
    return -1;
}

int main(){
    char str[100], ptr[100];
    int res;

    printf("Enter the text\n");
    scanf("%s", str);
    printf("Enter the pattern\n");
    scanf("%s", ptr);

    res = horspool(ptr, str);
    if(res == -1){
        printf("Not Found\n");
    }
    else{
        printf("Pattern found at position %d\n", res+1);
    }
}