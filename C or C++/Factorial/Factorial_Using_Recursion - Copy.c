#include<stdio.h>

long long int Factorial(long long int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return (num * Factorial(num - 1));
    }
}

int main()
{
    printf("##### FACTORIAL WITH RECURSION ALGORITHM TESTING #####\n");
    long long int num;
    while(1)
    {
        printf("\nEnter a non negative number to find factorial: ");
        scanf("%lld", &num);
        if(num >= 0)
        {
            break;
        }
    }

    printf("\n\nFactorial of %lld is = %lld",num,Factorial(num));
    printf("\n\n");
    return 0;
}
