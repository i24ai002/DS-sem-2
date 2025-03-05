#include <stdio.h>
#include <stdlib.h>
#define N 5

int S1[N], S2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) 
{
    if (top1 == N-1) 
    {
        printf("STACK OVERFLOW!!\n");
    } 
    else 
    {
        top1++;
        S1[top1] = data;
    }
}

void push2(int data) 
{
    if (top2 == N-1) 
    {
        printf("STACK OVERFLOW!!\n");
    }
    else 
    {
        top2++;
        S2[top2] = data;
    }
}

int pop1() 
{
    if (top1 == -1) 
    {
        printf("STACK UNDERFLOW!!\n");
        return -1;
    }
    return S1[top1--];
}

int pop2() 
{
    if (top2 == -1) 
    {
        printf("STACK UNDERFLOW!!\n");
        return -1;
    }
    return S2[top2--];
}

void enqueue() 
{
    int x;
    if (top1 == N-1) 
    {
        printf("QUEUE OVERFLOW!!\n");
    }
    printf("Enter the data for the QUEUE: ");
    scanf("%d", &x);
    push1(x);
    count++;
}

void dequeue() 
{
    if (top1 == -1) 
    {
        printf("QUEUE UNDERFLOW!!\n");
    }

    while (top1 != -1) 
    {
        push2(pop1());
    }

    printf("%d is dequeued\n", pop2());
    count--;

    while (top2 != -1) 
    {
        push1(pop2());
    }
}

void display() 
{
    if (top1 == -1) 
    {
        printf("QUEUE UNDERFLOW!!\n");
    }

    printf("Queue elements: ");
    for (int i = 0; i <= top1; i++) 
    {
        printf("%d ", S1[i]);
    }
    printf("\n");
}

int main() 
{
    int choice;
    
    while (choice != 4) 
    {
        printf("\nEnter 1.ENQUEUE  2.DEQUEUE  3.DISPLAY  4.EXIT: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("EXITING...\n");
                return 0;
            default:
                printf("Enter a VALID choice!\n");
        }
    }
}
