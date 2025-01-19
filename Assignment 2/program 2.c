#include <stdio.h>

int main() 
{
    int n;
    printf("enter the number of elements you want to enter: ");
    scanf("%d",&n);
    int arr1[n],arr2[n];
    printf("enter the elements of array: ");
    
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr1[i]);
    }

    for (int i=0; i<n; i++) 
    {
        if (i % 2 == 0) 
        { 
            arr2[i] = arr1[i];
        } 
        else 
        { 
            arr2[i] = arr1[i - 1] * arr1[i + 1];
        }
    }

    printf("second array: ");
    for (int i=0; i<n; i++) 
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}