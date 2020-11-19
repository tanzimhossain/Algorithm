#include<stdio.h>

int Fibonacci(int num)
{
    if(num == 0)
    {
        return 0;
    }
    else if(num == 1)
    {
        return 1;
    }
    else
    {
        return (Fibonacci(num - 1) + Fibonacci(num - 2));
    }
}

int main()
{
    printf("##### FIBONACCI NUMBERS WITH RECURSION ALGORITHM TESTING #####\n");
    int num;
    while(1)
    {
        printf("\nEnter a non negative number: ");
        scanf("%d", &num);
        if(num >= 0)
        {
            break;
        }
    }

    printf("\n\nFibonacci number of position %d is = %d",num,Fibonacci(num));
    printf("\n\n");
    return 0;
}
