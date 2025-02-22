#include<stdio.h>
#include<stdlib.h>
#define N 100  

int stack[N];
int top = -1;

void push()
{
    int x;
    printf("Enter the value to be pushed: ");   
    scanf("%d", &x);
    if(top >= N-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed to stack\n", x);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {   
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: ");
        for(int i=top; i>=0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    do 
    {
        printf("Enter 1.push  2.pop  3.peek  4.display  5.exit: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } 
    while(choice != 5);
    
    return 0;
}
