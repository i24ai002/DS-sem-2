#include <stdio.h>

// Merge function that merges two sorted halves and counts inversions
long long merge(int arr[], int temp[], int left, int mid, int right) 
{
    int i = left;     // Starting index of left subarray
    int j = mid + 1;  // Starting index of right subarray
    int k = left;     // Starting index of merged array
    long long inv_count = 0;

    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            // Inversion found: All remaining elements in left subarray are > arr[j]
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy merged result back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Merge sort function that also counts inversions
long long mergeSort(int arr[], int temp[], int left, int right) 
{
    long long inv_count = 0;
    if (left < right) 
    {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() 
{
    int n;
    printf("enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("enter %d distinct integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long inversions = mergeSort(arr, temp, 0, n - 1);
    printf("number of inversions: %lld\n", inversions);

    return 0;
}
