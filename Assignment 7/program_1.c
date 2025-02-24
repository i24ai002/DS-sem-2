#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct 
{
    int top;
    int items[MAX];
} Stack;

void init(Stack *s) 
{
    s->top = -1;
}

int isEmpty(Stack *s) 
{
    return s->top == -1;
}

void push(Stack *s, int value) 
{
    if (s->top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int evaluatePostfix(char *exp) 
{
    Stack s;
    init(&s);
    
    for (int i = 0; exp[i] != '\0'; i++) 
    {
        if (isdigit(exp[i])) 
        {
            push(&s, exp[i] - '0');
        } 
        else 
        {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (exp[i]) 
            {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
            }
        }
    }
    return pop(&s);
}

int main() 
{
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}