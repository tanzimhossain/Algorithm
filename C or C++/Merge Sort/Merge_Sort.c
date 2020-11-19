//MERGE SORT ALGORITHM IMPLEMENTATION

#include<stdio.h>

void Merge(int array[], int p, int q, int r)
{
    int length1 = q-p+1;
    int length2 = r-q;
    int i,j;
    int left_array[length1];
    int right_array[length2];

    for(i = 0; i < length1; i++)
    {
        left_array[i] = array[p+i];
    }
    for(j = 0; j < length2; j++)
    {
        right_array[j] = array[q+j+1];
    }

    left_array[length1] = 2147483647;
    right_array[length2] = 2147483647;
    i = j = 0;

    for(int k = p; k <= r; k++)
    {
        if(left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
    }
}

void MergeSort(int array[], int p, int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        MergeSort(array, p, q);
        MergeSort(array, q+1, r);
        Merge(array, p, q, r);
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
    printf("##### MERGE SORT ALGORITHM TESTING #####\n");
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

    int p = 0;
    int r = length - 1;

    MergeSort(array, p, r);

    printf("\n\n=> After sort array elements are: ");
    display(array, length);
    printf("\n\n");

    return 0;
}
