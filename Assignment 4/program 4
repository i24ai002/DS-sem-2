#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*prev;
    struct node*next;
};
struct node*head;
void insertatbeg(int x)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    if(head==NULL)
    {
        new->next=NULL;
        new->prev=NULL;
        head=new;
    }
    else
    {
        new->next=head;
        new->prev=NULL;
        head->prev=new;
        head=new;
    }
}
void print()
{
    struct node*temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;

    }
    printf("\n");
}
void insertatend(int x)
{
    struct node*new;
    struct node*temp=head;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    if(head==NULL)
    {
        new->next=NULL;
        new->prev=NULL;
        head=new;
    }
    else
    {
        temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
        new->next=NULL;
    }
}
void insertatpos(int x,int pos)
{
    struct node*temp;
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    temp=head;
    int i=1;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    new->prev=temp;
    temp->next=new;
    temp->next->prev=new;
}
int main()
{
    int n,x,pos;
    head=NULL;
    printf("enter number of elements you want to insert: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter element: ");
        scanf("%d",&x);
        insertatend(x);
    }
    int i,c;
    while (i=1)
    {
        printf("\n\n1.to insert at begning.\n2.to insert at end.\n3.to insert at middle.\n4.to insert after given position.\n5.to print linked list.\n6.to exit\n");
       printf("enter choice:");
       scanf("%d",&c);
       switch(c)
       {
        case 1:printf("\nenter element you want to insert at beginning: ");
                scanf("%d",&x);
                n++;
                insertatbeg(x);
                continue;
        case 2:printf("\nenter element you want to insert at end: ");
                scanf("%d",&x);
                n++;
                insertatend(x);
                continue;
        case 3:printf("\nenter element you want to insert at middle: ");
                if(n%2==0)
                {
                    pos=n/2;
                }
                else
                {
                    pos=(n+1)/2;
                }
                scanf("%d",&x);
                insertatpos(x,pos);
                continue;;       
        case 4:printf("\nenter pos at which you want to enter: ");
            scanf("%d",&pos);
            printf("\nenter element you want to insert at pos: ");
                scanf("%d",&x);
                n++;
                insertatpos(x,pos);
                continue;
        case 5:print();
            continue;
        case 6: return 0;
       }
    }   
}
