// program to find number of inversion pairs
#include<stdio.h>
int main()
{
    printf("enter the number of elements you want to enter: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array is\n");
    int inv=0;
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                if(i<j)
                {
                    inv++;
                }
            }
        }
    }
    printf("\nnumber of inversion pairs possible for the given array is %d",inv);
}