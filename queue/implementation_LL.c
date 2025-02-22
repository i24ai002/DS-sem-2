#include <stdio.h>
#include <stdlib.h>

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
    
    if (front == 0 && rear == 0) 
    {
        front = rear = newnode;
    } 
    else 
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() 
{
    if (front == 0 && rear == 0) 
    {
        printf("QUEUE is EMPTY!!\n");
    } 
    else 
    {
        struct node *temp;
        temp = front;
        printf("%d is dequeued\n", temp->data);
        front = temp->next;
        free(temp);
    }
}

void peek() 
{
    if (front == 0 && rear == 0) 
    {
        printf("QUEUE is EMPTY!!\n");
    } 
    else 
    {
        printf("%d is the front element\n", front->data);
    }
}

void display() 
{
    struct node *temp;
    if (front == 0 && rear == 0) 
    {
        printf("QUEUE is EMPTY!!\n");
    } 
    else 
    {
        temp = front;
        while (temp != 0) 
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() 
{
    int choice = 0;
    
    while (choice != 5) 
    {  
        printf("\nEnter 1.ENQUEUE  2.DEQUEUE  3.PEEK  4.DISPLAY  5.EXIT: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                {
                    int x;
                    printf("Enter the data for the queue: ");
                    scanf("%d", &x);
                    enqueue(x);
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("EXITING....\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
    }    
    return 0;
}