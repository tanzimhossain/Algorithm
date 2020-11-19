#include<stdio.h>
#include<string.h>

int arr_3[30][30];
char arr_4[30][30];

void print(char arr_1[], int i, int j)
{
    if(i==0 || j==0)
        return;
    if(arr_4[i][j]=='c')
    {
        print(arr_1,i-1,j-1);
        printf("%c",arr_1[i-1]);
    }
    else if(arr_4[i][j]=='u')
        print(arr_1, i-1, j);
    else
        print(arr_1, i, j-1);
}


void lcs(char arr_1[], char arr_2[], int m, int n)
{
    int i, j;
    for(i=0; i<=m; i++)
        arr_3[i][0]=0;
    for(i=0; i<=n; i++)
        arr_3[0][i]=0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(arr_1[i-1]==arr_2[j-1])
            {
                arr_3[i][j]=arr_3[i-1][j-1]+1;
                arr_4[i][j]='c';
            }
            else if(arr_3[i-1][j]>=arr_3[i][j-1])
            {
                arr_3[i][j]=arr_3[i-1][j];
                arr_4[i][j]='u';
            }
            else
            {
                arr_3[i][j]=arr_3[i][j-1];
                arr_4[i][j]='l';
            }
        }
}

int main()
{
    char arr_1[30],arr_2[30];
    int m, n;
    printf("Enter 1st Word:");
    scanf("%s",arr_1);
    printf("Enter 2nd Word:");
    scanf("%s",arr_2);
    m=strlen(arr_1);
    n=strlen(arr_2);
    lcs(arr_1,arr_2,m,n);
    printf("\nThe Longest Common Subsequence is :: ");
    print(arr_1,m,n);


    return 0;
}
