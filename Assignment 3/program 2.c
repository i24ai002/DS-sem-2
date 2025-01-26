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
    
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data for the 1st node: ");
    scanf("%d",&newnode->data);
    newnode->next = 0;
    
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter data for the 2nd node: ");
    scanf("%d",&temp->data);
    temp->next = 0;
    
    newnode->next = temp;
    head = newnode;
    
    printf("enter data for the node to add in the beginning: ");
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    
    newnode->next = head;
    head = newnode;
    
    temp = head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}