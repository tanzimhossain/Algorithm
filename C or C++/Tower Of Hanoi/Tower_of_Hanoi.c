#include<stdio.h>

void Hanoi(int num, char source, char destination, char auxilliary)
{
    if(num == 1)
    {
        printf("Move disc from peg %c to peg %c\n", source, destination);
    }
    else
    {
        Hanoi(num - 1, source, auxilliary, destination);
        Hanoi(1, source, destination, auxilliary);
        Hanoi(num - 1, auxilliary, destination, source);
    }
}

int main()
{
    printf("##### TOWER OF HANOI WITH RECURSION ALGORITHM TESTING #####\n");
    int num;
    while(1)
    {
        printf("\nEnter number of disk: ");
        scanf("%d", &num);
        if(num > 0)
        {
            break;
        }
        else
        {
            printf("Number of disk cannot be negative or zero(0).\n");
        }
    }
    Hanoi(num, 'A', 'B', 'C');

    return 0;
}
