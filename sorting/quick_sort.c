//best time complexity O(n logn)
//worst time complexity O(n^2)

#include <stdio.h>

// Partition function for QuickSort
int partition(int arr[], int lb, int ub) 
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) 
    {
        while (arr[start] <= pivot) 
        {
            start++;
        }
        while (arr[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Swap pivot element with end
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end; // Return pivot index
}

// QuickSort function
void quickSort(int arr[], int lb, int ub) 
{
    if (lb < ub) 
    {
        int pivotIndex = partition(arr, lb, ub);
        quickSort(arr, lb, pivotIndex - 1); // Sort left part
        quickSort(arr, pivotIndex + 1, ub); // Sort right part
    }
}

int main() 
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Apply QuickSort
    quickSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}