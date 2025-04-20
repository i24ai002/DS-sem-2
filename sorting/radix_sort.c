//best and worst time complexity O(nk)

#include<stdio.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) 
{
    int output[n]; // Output array
    int count[10] = {0};

    // Count occurrences of each digit at current place value
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Compute cumulative frequency
    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    // Build the output array
    for (int i = n-1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy sorted elements back into the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) 
{
    int max = getMax(arr, n);

    // Apply counting sort for each digit place (1s, 10s, 100s, ...)
    for (int exp = 1; max/exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}