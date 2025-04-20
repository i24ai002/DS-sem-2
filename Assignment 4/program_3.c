#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

struct ListNode *create_node(int value)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
int has_cycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
void insert_node(struct ListNode **head, int value)
{
    struct ListNode *new_node = create_node(value);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct ListNode *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
int main()
{
    int n, value, pos;
    struct ListNode *head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &value);
        insert_node(&head, value);
    }
    printf("Enter the position to create a loop (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0 && pos <= n)
    {
        struct ListNode *temp = head;
        struct ListNode *loop_node = head;
        for (int i = 1; i < pos; ++i)
        {
            loop_node = loop_node->next;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = loop_node;
    }

    if (has_cycle(head))
    {
        printf("Loop detected.\n");
    }
    else
    {
        printf("No loop detected.\n");
    }
    return 0;
}