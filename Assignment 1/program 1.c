// program to find maximum element in bitonic array
#include<stdio.h>
int main()
{
    int n;
    printf("enter the size of bitionic array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter elements of bitionic array\n ");
    for(int i=0 ; i<n ; i++)
    {
        printf("enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0 ; i<n ; i++)
    {
        printf("%d ",arr[i]);
    }
    int low = 0;
    int high = n-1;
    int mid,max;
    for(int i=0;i<n;i++)
    {
        mid = (high + low)/2;
        if(arr[mid-1]>arr[mid])
        {
            high = mid-1;
        }
        else if(arr[mid+1]>arr[mid])
        {
            low = mid+1;
        }
        else
        {
            max = arr[mid];
        }
    }
    printf("\nmaximum element in bitionic array is : %d", max);       
}