#include <stdio.h>
#include <stdlib.h>

int MFKnapsack(int n, int weights[10], int values[10], int W, int knapsack[100][100])
{
    int value;

    if (knapsack[n][W] < 0)
    {
        if (W < weights[n - 1])
        {
            value = MFKnapsack(n - 1, weights, values, W, knapsack);
        }
        else
        {
            int value1 = MFKnapsack(n - 1, weights, values, W, knapsack);
            int value2 = MFKnapsack(n - 1, weights, values, W - weights[n - 1], knapsack) + values[n - 1];
            value = (value1 > value2) ? value1 : value2;
        }
        knapsack[n][W] = value;
    }
    return knapsack[n][W];
}

void main()
{
    int n, weights[10], values[10], W, knapsack[100][100], ans;

    printf("Enter the number of Elements\n");
    scanf("%d", &n);
    printf("Enter the weights of all the elements\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of all the elements\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum capacity of the Knapsack\n");

    scanf("%d", &W);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                knapsack[i][j] = 0;
            }
            else
            {
                knapsack[i][j] = -1;
            }
        }
    }

    ans = MFKnapsack(n, weights, values, W, knapsack);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            printf("%d\t", knapsack[i][j]);
        }
        printf("\n");
    }

    int i = n;
    int j = W;

    while (knapsack[i][j] > 0)
    {
        if (knapsack[i][j] != knapsack[i - 1][j])
        {
            printf("%d is included\n", i);
            j = j - weights[i - 1];
            i = i - 1;
        }
        else
        {
            i = i - 1;
        }
    }

    printf("The maximum capacity possible is:%d\n", ans);
}
