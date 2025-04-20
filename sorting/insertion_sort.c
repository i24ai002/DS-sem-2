//best time complexity O(n)
//worst time complexity O(n^2)

#include<stdio.h>

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

    //Insertion Sort algorithm
    int i,j,temp;
    for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i-1;
    
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }    

    //Print elements
    for(i =0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}