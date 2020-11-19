#include<stdio.h>

int main()
{
    int i,j,k,n;

    printf("enter no of vertices :");
    scanf("%d",&n);
    printf("\n");
    int matrix[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Matrix[%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    printf (" \n\n shortest distances between every pair of vertices \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf ("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}
