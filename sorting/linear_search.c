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
    
    int data, found = 0;
    printf("Enter the element you want to search for: ");
    scanf("%d", &data);

    for (int i = 0; i < n; i++)
    {
        if (data == arr[i])
        {
            printf("%d is present at index %d\n", data, i);
            found = 1; 
            break;
        }
    }

    if (!found)
    {
        printf("%d is not present in the array.\n", data);
    }

    return 0;
}
