//INSERTION SORT ALGORITHM IMPLEMENTATION

#include<stdio.h>

void InsertionSort(int array[], int length)
{
    int key, i;
    for(int j = 1; j < length; j++)
    {
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key)
        {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

void display(int array[], int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int length, i;
    printf("##### INSERTION SORT ALGORITHM TESTING #####\n");
    printf("\n=> Enter array size to create an array = ");
    scanf("%d", &length);
    int array[length];
    printf("\n=> Enter %d array element:\n", length);

    for(i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\n\n=> Before sort array elements are: ");
    display(array, length);

    InsertionSort(array, length);

    printf("\n\n=> After sort array elements are: ");
    display(array, length);
    printf("\n\n");

    return 0;
}
