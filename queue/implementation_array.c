#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == N-1)
    {
        printf("QUEUE OVERFLOW!!");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("%d is added to the queue\n",x);
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("%d is added to the queue\n",x);
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE UNDERFLOW!!\n");
    }
    else if(front == rear)
    {
        printf("%d is removed from the queue\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is removed from the queue\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        int i = front;
        while(i != (rear+1))
        {
            printf("%d  ",queue[i]);
            i++;
        }
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("%d is the front element\n",queue[front]);
    }
}

int main()
{
    int choice;
    while(choice != 5)
    {  
        printf("\nenter 1.ENQUEUE  2.DEQUEUE  3.PEEK  4.DISPLAY  5.EXIT : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            int x;
            printf("enter the data for the queue: ");
            scanf("%d",&x);
            enqueue(x);
        } 
        if(choice == 2)
        {
            dequeue();
        }
        if(choice == 3)
        {
            peek();
        }
        if(choice == 4)
        {
            display();
        }
        if(choice == 5)
        {
            printf("EXITING.... ");
        }
    }    
    return 0;
}