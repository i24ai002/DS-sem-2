#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = 0, *newnode, *tail;

void create()
{
    struct node *tail = 0; 
    int choice = 1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data for the node: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        newnode->prev = 0;

        if(head == 0)
        {
            head = tail = newnode;  
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        } 
       
        
        printf("do you wish to continue(0,1)? ");
        scanf("%d", &choice);
    }
}
void display()
{
    struct node *temp; 
    temp = head;
    while(temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    create();
    display();
    return 0;
}