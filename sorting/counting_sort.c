//time complexity 0(n+k)

#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the element with highest key value: ");
    scanf("%d", &k);

    // Counting Sort algorithm
    int brr[n];
    int count[k + 1];

    // Initialize count array to zero
    for (int i = 0; i <= k; i++) 
    {
        count[i] = 0;
    }

    // Count occurrences
    for (int i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }

    // Compute cumulative frequency
    for (int i = 1; i <= k; i++) 
    {
        count[i] += count[i-1];
    }

    // Place elements in sorted order
    for (int i = n-1; i >= 0; i--) 
    {
        brr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", brr[i]);
    }

    return 0;
}