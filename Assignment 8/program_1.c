#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *front = 0;

void enqueue(int x, int priority)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->priority = priority;
    newnode->next = NULL;
    
    if(front == NULL || priority > front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        struct node *temp = front;
        while(temp->next != NULL && temp->next->priority >= priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("%d with priority %d is enqueued\n", x, priority);
}

void dequeue()
{
    if(front == NULL)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        struct node *temp = front;
        printf("%d with priority %d is dequeued\n", front->data, front->priority);
        front = front->next;
        free(temp);
    }
}

void peek()
{
    if(front == NULL)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("%d with priority %d is the front element\n", front->data, front->priority);
    }
}

void isfull()
{
    printf("QUEUE cannot be FULL when implemented using Linked List.\n");
}

void isempty()
{
    if (front == NULL) 
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("QUEUE is not fully EMPTY.\n");
    }
}

void display()
{
    struct node *temp = front;
    if(front == NULL)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("(%d, %d)", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice;
    while(choice != 7)
    {  
        printf("\nenter 1.ENQUEUE  2.DEQUEUE  3.PEEK  4.isFULL  5.isEMPTY  6.DISPLAY  7.EXIT : ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            int x, priority;
            printf("enter the data and priority for the queue: ");
            scanf("%d %d", &x, &priority);
            enqueue(x, priority);
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
            isfull();
        }
        if(choice == 5)
        {
            isempty();
        }
        if(choice == 6)
        {
            display();
        }
        if(choice == 7)
        {
            printf("EXITING.... ");
        }
    }    
    return 0;
}