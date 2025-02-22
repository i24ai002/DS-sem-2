#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = 0, *newnode, *tail = 0;

void create()
{
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

void insert_at_beg()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for the node you want to add in beginning: ");
    scanf("%d",&newnode->data);
    head->prev = newnode;
    newnode->prev = 0;
    newnode->next = head;
    head = newnode;
}

void insert_at_end()
{
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for the node you want to add in end: ");
    scanf("%d",&newnode->data);
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_at_pos()
{
    int i=1, pos, count=0;
    struct node *temp;
    temp = head;
    printf("enter pos at which you want to insert a node: ");
    scanf("%d",&pos);
    while(temp!=0)
    {
        temp = temp->next;
        count++;
    }
    if(pos>count+1)
    {
        printf("invalid position!!");
    }
    else if(pos==1)
    {
        insert_at_beg();
    }
    else if(pos==count+1)
    {
        insert_at_end();
    }
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter data fot the node you want to add at position %d: ",pos);
        scanf("%d",&newnode->data);
        temp = head;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

int main()
{
    create();
    insert_at_beg();
    insert_at_end();
    insert_at_pos();
    display();
    return 0;
}

