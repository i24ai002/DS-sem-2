#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *head, *temp;
void insert(int x)
{
    struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if(head==NULL)
    {
        head = newnode;
        newnode->next = NULL;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->next = NULL;
        temp = newnode;
    }
}

void print()
{
    
    temp = head;
    while (temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int b;
    printf("enter the number of elements: ");
    scanf("%d",&b);
    int arr[b];
    int i = 1;
    printf("enter elements of array: \n");
    while(i<=b)
    {
        printf("enter element %d: ",i);
        scanf("%d",&arr[i]);
        insert(arr[i]);
        i++;
    }
    printf("linked list is: ");
    print();
}