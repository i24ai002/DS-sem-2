#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;

void insertatbeg(int x)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else
    {
        new->next = head;
        new->prev = NULL;
        head->prev = new;
        head = new;
    }
}

void print()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertatend(int x)
{
    struct node *new;
    struct node *temp = head;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    if (head == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
        new->next = NULL;
    }
}

void insertatpos(int x, int pos)
{
    struct node *temp;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    temp = head;
    int i = 1;

    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    new->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = new;
    temp->next = new;
    new->prev = temp;
}

int main()
{
    int n, x, pos;
    head = NULL;
    printf("Enter number of elements you want to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &x);
        insertatend(x);
    }
    int c;
    while (1)
    {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at middle\n4. Insert after given position\n5. Print linked list\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\nEnter element to insert at beginning: ");
            scanf("%d", &x);
            n++;
            insertatbeg(x);
            break;
        case 2:
            printf("\nEnter element to insert at end: ");
            scanf("%d", &x);
            n++;
            insertatend(x);
            break;
        case 3:
            printf("\nEnter element to insert at middle: ");
            scanf("%d", &x);
            if (n % 2 == 0)
                pos = n / 2;
            else
                pos = (n + 1) / 2;
            insertatpos(x, pos);
            n++;
            break;
        case 4:
            printf("\nEnter position after which you want to insert: ");
            scanf("%d", &pos);
            printf("\nEnter element to insert: ");
            scanf("%d", &x);
            insertatpos(x, pos);
            n++;
            break;
        case 5:
            print();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
