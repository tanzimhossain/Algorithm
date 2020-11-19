#include<stdio.h>
#include<math.h>

//Max Heapify Operation
void MaxHeapify(int array[], int length, int i)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest = i;
    if(left <  length && array[left] > array[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if(right <  length && array[right] > array[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(&array[i], &array[largest]);
        MaxHeapify(array, length, largest);
    }
}

//Min Heapify Operation
void MinHeapify(int array[], int length, int i)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int smallest = i;
    if(left <  length && array[left] < array[i])
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if(right <  length && array[right] < array[smallest])
    {
        smallest = right;
    }
    if(smallest != i)
    {
        swap(&array[i], &array[smallest]);
        MinHeapify(array, length, smallest);
    }
}

void BuildMaxHeap(int array[], int length)
{
    for(int i = floor(length/2) - 1; i >= 0; i--)
    {
        MaxHeapify(array, length, i);
    }
}

void BuildMinHeap(int array[], int length)
{
    for(int i = floor(length/2) - 1; i >= 0; i--)
    {
        MinHeapify(array, length, i);
    }
}

void HeapSort(int array[], int length)
{
    BuildMaxHeap(array, length);
    for(int i = length - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        length--;
        MaxHeapify(array, length, 0);
    }
}

int HeapMaximum(int array[])
{
    return array[0];
}

int Heap_Extract_Max(int array[], int length)
{
    if(length < 1)
    {
        printf("\nHeap Underflow\n");
    }
    int max = array[0];
    swap(&array[0], &array[length - 1]);
    length--;
    MaxHeapify(array, length, 0);
    return max;
}

void Heap_Increase_key(int array[], int i, int key)
{
    if(key < array[i - 1])
    {
        printf("New key is smaller than the current key");
    }
    array[i] = key;
    while(i > 0 && array[(i/2)-1] < array[i])
    {
        swap(&array[i], &array[(i/2)-1]);
        i = floor(i/2)-1;
    }
}

void Max_Heap_Insert(int array[], int key, int position, int length)
{
    length++;
    array[length - 1] = 2147483647;
    Heap_Increase_key(array, position, key);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    printf("##### RANDOMIZED QUICKSORT ALGORITHM TESTING #####\n");
    printf("\n=> Enter array size to create an array = ");
    scanf("%d", &length);
    int array[length];
    printf("\n=> Enter %d array element:\n", length);

    for(i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\n\n=> Before sort array elements are :: ");

    display(array, length);

    HeapSort(array, length);

    printf("\n\n=> After sort array elements are :: ");

    display(array, length);

    printf("\n\n");

    BuildMaxHeap(array, length);

    printf("Largest element of the array is :: %d", HeapMaximum(array));
    printf("\n\n");
    printf("Largest element of the array is :: %d", Heap_Extract_Max(array, length));
    printf("\n\n");
    Heap_Increase_key(array, 2, 85);
    display(array, length);
    printf("\n\n");
    return 0;
}
