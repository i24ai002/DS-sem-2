//Given an array of non-negative integers, implement the Counting Sort algorithm to sort the array in ascending order.
//best and worst time complexity 0(n+k)

#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n) 
{
    if (n == 0) return;
    
    int max_val = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max_val) 
        {
            max_val = arr[i];
        }
    }
    
    int *count = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }
    
    int index = 0;
    for (int i = 0; i <= max_val; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i;
            count[i]--;
        }
    }
    
    free(count);
}

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter non-negative integers: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    counting_sort(arr, n);
    
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
