#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("%d is enqueued\n",queue[rear]);
    }
    else if((rear+1)%N == front)
    {
        printf("QUEUE is FULL!!\n");
    }
    else
    {
        rear = (rear+1)%N;
        queue[rear] = x;
        printf("%d is enqueued\n",queue[rear]);
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else if(front == rear)
    {
        printf("%d is dequeued\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d is dequeued\n",queue[front]);
        front = (front+1)%N;
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

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY\n");
    }
    else
    {
        int i = front;  
        while (i != rear)
        {
            printf("%d  ", queue[i]);
            i = (i + 1) % N; 
        }
        printf("%d  ", queue[i]); 
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