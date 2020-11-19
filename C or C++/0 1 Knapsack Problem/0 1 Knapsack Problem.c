#include<stdio.h>

int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int knapsack(int capacity, int weight[], int value[], int n)
{
   int i, w;
   int K[n+1][capacity+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= capacity; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight[i-1] <= w)
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][capacity];
}

int main()
{
    int weight[] = {2, 1, 3, 2};
    int value[] = {12, 10, 20, 15};
    int  capacity = 5;
    int n = 4;
    int max;

    max = knapsack(capacity, weight, value, n);
    printf("Maximum profit = %d\n", max);
    return 0;
}
