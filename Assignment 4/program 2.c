#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *arrayToLinkedList(int arr[], int size)
{
    if (size == 0)
    {
        return NULL;
    }

    struct node *head = NULL, *current = NULL;

    for (int i = 0; i < size; i++)
    {
        struct node *newNode = createNode(arr[i]);
        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    return head;
}

void remove_duplicates(struct node *head)
{
    struct node *temp1 = head;
    struct node *temp2;
    struct node *duplicate;

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;

        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                duplicate = temp2->next;
                temp2->next = temp2->next->next;
                free(duplicate);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getLength(struct node *head)
{
    int length = 0;
    struct node *current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

int main()
{
    int num;
    printf("enter the number of elements in linked list: ");
    scanf("%d", &num);

    int array[num];

    printf("enter the elements: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }

    struct node *linked_list = arrayToLinkedList(array, num);
    printf("the original linked list is: ");
    display(linked_list);
    printf("the linked list after removing duplicates: ");
    remove_duplicates(linked_list);
    display(linked_list);
    return 0;
}
