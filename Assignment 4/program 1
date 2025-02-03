#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node *head,*temp;
void insert(int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    if(head==NULL)
    {
        new->next=NULL;
        head=temp=new;
    }
    else
    {
        new->next=NULL;
        temp->next=new;
        temp=new;
    }
}
void print()
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        temp=t;
        printf("%d  ",t->data);
        t=t->next;
        free(temp);
    }
    printf("\n");
}
void rotate(int x)
{
    temp->next=head;
    struct node*t;
    int i=0;
    while (i<x)
    {   
        t=head;
        head=head->next;
        i++;
    }
    t->next=NULL;
}

int main()
{
    int n,x;
    printf("enter number of elements you want to insert: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter element: ");
        scanf("%d",&x);
        insert(x);
    }
    printf("enter by how much you want to rotate linked list: ");
    scanf("%d",&x);
    if(x<n)
    {
        printf("rotated linked list: ");
        rotate(x);
        print();
    }
    else if(x==n)
    {
        printf("rotated linked list: ");
        print();
    }
    else
    {
        printf("\ninvalid rotation");
    }

}
