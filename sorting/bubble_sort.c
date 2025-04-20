//best case time complexity O(n)
//worst case time complexity O(n^2)
#include<stdio.h>

int main()
{
    int n;
    printf("enter the number of elements you want to sort: ");
    scanf("%d",&n);
    int arr[n];

    printf("enter %d elements: ", n);
    for (int i=0; i<n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n-1; i++)//passes
    {
        int flag = 0;
        for(int j=0; j<n-1-i; j++)//comparisons
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1; 
            }
        }
        if(flag==0)
            break;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}