#include <stdio.h>
#include <stdlib.h>

void input(int a[3][3]) 
{
    printf("enter the array: ");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void product(int a[3][3], int b[3][3], int c[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void result(int c[3][3]) 
{
    printf("\nthe resultant matrix is:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int a[3][3], b[3][3], c[3][3];

    input(a);
    input(b);
    product(a, b, c);
    result(c);

    return 0;
}
