#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head = 0, *newnode, *temp;
    int choice = 1;
  
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data for the node: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        
        if(head==0)
        {
            temp = head = newnode; 
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("do you wish to continue (0,1)? ");
        scanf("%d",&choice);
    }
    
    temp = head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter data of the node you want to add at the END: ");
    scanf("%d",&newnode->data);
    newnode->next = 0;
    
    temp = head;
    while(temp->next!=0)
    {
        temp = temp->next;
    }
    
    temp->next = newnode;
    
    temp = head;
    printf("\nfinal linked list: ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}