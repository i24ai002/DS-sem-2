#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node *head, *tail;

void insAtBeg(int x) 
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    if (head != NULL) 
    {
        new->next = head;
        new->data = x;
        tail->next = new;
        head = new;
    } 
    else 
    {
        tail = head = new;
        tail->next = new;
        new->data = x;
    }
}

void insAtEnd(int x) 
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    if (tail != NULL) 
    {
        new->data = x;
        tail->next = new;
        new->next = head;
        tail = new;
    } 
    else 
    {
        tail = head = new;
        tail->next = new;
        new->data = x;
    }
}

void print() 
{
    struct node *temp;
    temp = tail->next;
    while (temp != tail) 
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    if (temp == tail) 
    {
        printf("%d", temp->data);
    }
    printf("\n");
}

void insAtPos(int pos, int x) 
{
    struct node *temp, *new;
    new = (struct node*)malloc(sizeof(struct node*));
    temp = head;
    int i = 1;
    while (i < pos - 1) 
    {
        temp = temp->next;
        i++;
    }
    new->data = x;
    new->next = temp->next;
    temp->next = new;
}

void delAtBeg() 
{
    struct node *temp;
    temp = head;
    head = head->next;
    tail->next = temp->next;
    free(temp);
}

void delAtEnd() 
{
    struct node *temp;
    temp = tail->next;
    while (temp->next != tail) 
    {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
}

int delAtPos(int pos) 
{
    if (head == NULL) 
    {
        printf("List is empty");
        return 0;
    }
    int i = 1;
    struct node *temp, *t;
    temp = head;
    while (i < pos) 
    {
        t = temp;
        temp = temp->next;
        i++;
    }
    t->next = temp->next;
    free(temp);
}

int main() 
{
    int n, i = 0, x, c, pos;
    head = tail = NULL;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);
    while (i < n) 
    {
        printf("Enter element: ");
        scanf("%d", &x);
        insAtEnd(x);
        i++;
    }
    while (1) 
    {
        printf("\n1. Insert an element at a specific position specified by the user.\n");
        printf("2. Insert an element at the beginning of the list\n");
        printf("3. Insert an element at the end of the list.\n");
        printf("4. Delete an element from a specific position specified by the user.\n");
        printf("5. Delete the first element from the list.\n");
        printf("6. Delete the last element from the list.\n");
        printf("7. Press 0 to exit\n\n\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c) 
        {
            case 1:
                printf("Enter position at which you want to insert: ");
                scanf("%d", &pos);
                printf("Enter element: ");
                scanf("%d", &x);
                insAtPos(pos, x);
                print();
                break;
            case 2:
                printf("Enter element you want to insert at beginning: ");
                scanf("%d", &x);
                insAtBeg(x);
                print();
                break;
            case 3:
                printf("Enter element you want to insert at end: ");
                scanf("%d", &x);
                insAtEnd(x);
                print();
                break;
            case 4:
                printf("Enter position at which you want to delete: ");
                scanf("%d", &pos);
                delAtPos(pos);
                print();
                break;
            case 5:
                delAtBeg();
                print();
                break;
            case 6:
                delAtEnd();
                print();
                break;
            case 0:
                return 0;
        }
    }
}
