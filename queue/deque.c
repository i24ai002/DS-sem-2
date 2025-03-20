#include <stdio.h>
#include <stdlib.h>
#define N 5

int deque[N];
int front = -1, rear = -1;

void enqueue_front()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if (front == (rear + 1) % N)
    {
        printf("QUEUE is FULL!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
        printf("Element %d is enqueued at front.\n", x);
    }
    else if (front == 0)
    {
        front = N - 1;
        deque[front] = x;
        printf("Element %d is enqueued at front.\n", x);
    }
    else
    {
        front--;
        deque[front] = x;
        printf("Element %d is enqueued at front.\n", x);
    }
}

void enqueue_rear()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if ((rear + 1) % N == front)
    {
        printf("QUEUE is FULL!!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
        printf("Element %d is enqueued at rear.\n", x);
    }
    else if (rear == N - 1)
    {
        rear = 0;
        deque[rear] = x;
        printf("Element %d is enqueued at rear.\n", x);
    }
    else
    {
        rear++;
        deque[rear] = x;
        printf("Element %d is enqueued at rear.\n", x);
    }
}

void dequeue_front()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else if (front == rear)
    {
        printf("Element %d is dequeued from front.\n", deque[front]);
        front = rear = -1;
    }
    else
    {
        printf("Element %d is dequeued from front.\n", deque[front]);
        front = (front + 1) % N;
    }
}

void dequeue_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else if (front == rear)
    {
        printf("Element %d is dequeued from rear.\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Element %d is dequeued from rear.\n", deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("Element %d is dequeued from rear.\n", deque[rear]);
        rear--;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
        return;
    }
    int i = front;
    printf("Deque elements are: ");
    while (i != rear)
    {
        printf("%d  ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[rear]);
}

void get_front()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("Front element is: %d\n", deque[front]);
    }
}

void get_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE is EMPTY!!\n");
    }
    else
    {
        printf("Rear element is: %d\n", deque[rear]);
    }
}

int main()
{
    int choice = 0;
    while (choice != 8)
    {
        printf("\nEnter:\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Get Front\n6. Get Rear\n7. Display\n8. EXIT\n");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue_front();
        else if (choice == 2)
            enqueue_rear();
        else if (choice == 3)
            dequeue_front();
        else if (choice == 4)
            dequeue_rear();
        else if (choice == 5)
            get_front();
        else if (choice == 6)
            get_rear();
        else if (choice == 7)
            display();
        else if (choice == 8)
            printf("Exiting...\n");
        else
            printf("Invalid choice!!\n");
    }
}
