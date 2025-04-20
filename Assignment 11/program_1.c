//Find the kth element using QuickSort
//best time complexity 0(n)
//worst time complexity 0(n^2)

#include <stdio.h>

// Partition function
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Pivot element
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// QuickSelect function to find kth smallest element
int quickSelect(int arr[], int low, int high, int k) 
{
    if (low <= high) 
    {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k - 1)
            return arr[pivotIndex]; // Found the kth smallest element
        else if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k); // Search in left part
        else
            return quickSelect(arr, pivotIndex + 1, high, k); // Search in right part
    }
    return -1; // Invalid case
}

int main() 
{
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    if (k > 0 && k <= n)
        printf("The %dth smallest element is %d\n", k, quickSelect(arr, 0, n - 1, k));
    else
        printf("Invalid value of k\n");
    
    return 0;
}