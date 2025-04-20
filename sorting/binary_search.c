//for binary search the data should be sorted 
//best time complexity O(1)
//worst time complexity O(log n)
#include <stdio.h>

int BinarySearch(int arr[], int n, int data) 
{
    int l = 0, r = n-1;
    while (l < r) 
    {
        int mid = (l + r) / 2;
        if (data == arr[mid])
        {
            return mid;
        }
        else if (data < arr[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1; 
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int data;
    printf("Enter the element you want to search for: ");
    scanf("%d", &data);

    int result = BinarySearch(arr, n, data);
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
