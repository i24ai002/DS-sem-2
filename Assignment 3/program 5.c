#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp;
void insert(int x)
{
    struct node *newnode;//*temp;
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

int main()
{
    int n,x;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    head = NULL;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter element %d: ",i+1);
        scanf("%d",&x);
        insert(x);
    }
    printf("array is: ");
    temp = head;
    int i = 0;
    while (temp!=NULL)
    {   
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }   
}