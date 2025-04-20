//best and worst time complexity 0(n^2)
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Selection Sort Algorithm
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)  
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Swap only if min index is different
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Sorted array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}