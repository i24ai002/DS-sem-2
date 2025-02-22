#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = 0;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if(top==0)
    {
        printf("stack is empty!!");
    }
    else
    {
        printf("\n%d popped out of stack",top->data);
        top = top->link;
        free(temp);
    }
}

void peek()
{
    if(top==0)
    {
        printf("stack is empty!!");
    }
    else
    {
        printf("\n%d is the top element of the stack\n",top->data);
    }
}

void display()
{
    struct node *temp;
    temp = top;
    printf("stack: ");
    if(top==0)
    {
        printf("stack is empty!!");
    }
    else 
    {
        while(temp!=0)
        {
            printf("%d  ",temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    int choice = 1, x;
    while(choice)
    {
        printf("enter the value you want to push in stack: ");
        scanf("%d",&x);
        push(x);

        printf("do you wish to continue(0,1)? ");
        scanf("%d",&choice);
    }
    pop();
    peek();
    display();
    return 0;
}