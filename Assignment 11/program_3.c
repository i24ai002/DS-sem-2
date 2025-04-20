//Given an array of non-negative integers, implement the Radix Sort algorithm to sort the array in ascending order.
//best and worst time complexity 0(nk)

#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int arr[], int n) 
{
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {

        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort used by Radix Sort
void countingSort(int arr[], int n, int exp) 
{
    int output[n];
    int count[10] = {0};
    
    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Update count array to store positions
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) 
{
    int max = getMax(arr, n);
    
    // Apply counting sort for each digit (place value)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d non-negative integers: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    radixSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}