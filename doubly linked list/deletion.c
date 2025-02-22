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

void delete_from_beg()
{
    struct node *temp;
    if(head==0)
    {
        printf("list is EMPTY!!");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = 0;
        temp->next = 0;
        free(temp);
    }
}

void delete_from_end()
{
    struct node *temp;
    if(head==0)
    {
        printf("list is EMPTY!!");
    }
    else
    {
        temp = tail;
        tail = temp->prev;
        tail->next = 0;
        temp->prev = 0;
        free(temp);
    }
}

void delete_from_pos()
{
    int i=1, pos, count=0;
    struct node *temp;
    printf("enter position at which you want to delete a node: ");
    scanf("%d",&pos);
    temp = head;
    while(temp!=0)
    {
        temp = temp->next;
        count++;
    }
    if(pos == 1)
    {
        delete_from_beg();
    }
    else if(pos == count)
    {
        delete_from_end();
    }
    else if(pos > count)
    {
        printf("invalid position!!");
    }
    else
    {
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp-> next = 0;
        temp->prev = 0;
    }
}

void display()
{
    struct node *temp; 
    int count = 0;
    temp = head;
    while(temp != 0)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
}

int main()
{
    create();
    delete_from_beg();
    delete_from_end();
    delete_from_pos();
    display();
    return 0;
}