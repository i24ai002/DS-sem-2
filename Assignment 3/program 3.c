#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};

int main()
{
    struct node*head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    
    struct node*current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    
    head->link = current;
    struct node*ptr = NULL;
    ptr = head;
    
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    
    return 0;
}


