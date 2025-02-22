#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = 0, *rear = 0;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(rear == 0)
    {
        printf("%d is enqueued\n",x);
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        printf("%d is enqueued\n",x);
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    struct node *temp = front;
    if(front == 0 && rear == 0)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else if(front == rear)
    {
        front = rear = 0;
        free(temp);
    }
    else
    {
        printf("%d is dequeued\n",front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if(front == 0 && rear == 0)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("%d is the front element\n",front->data);
    }
}

void display()
{
    struct node *temp = front;
    if(front == 0 && rear == 0)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        while(temp->next != front)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }
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