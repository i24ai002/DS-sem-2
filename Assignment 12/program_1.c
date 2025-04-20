#include <stdio.h>
#include <stdlib.h>

#define N 9       // Number of elements in array
#define BUCKETS 7 // Number of buckets
#define MAX 100   // Max value assumed in array for bucket range

// Node structure for linked list (used in buckets)
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Function to insert into sorted linked list
void insertSorted(Node** bucket, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL || (*bucket)->data >= value) 
    {
        newNode->next = *bucket;
        *bucket = newNode;
    } 
    else 
    {
        Node* current = *bucket;
        while (current->next != NULL && current->next->data < value) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[N] = {12, 45, 33, 87, 56, 9, 11, 7, 67};

    // Create buckets
    Node* buckets[BUCKETS] = {NULL};

    // Bucket range
    int range = (MAX + BUCKETS - 1) / BUCKETS;

    // Distribute elements into buckets
    for (int i = 0; i < N; i++) 
    {
        int index = arr[i] / range;
        if (index >= BUCKETS) index = BUCKETS - 1;
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets into original array
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) 
    {
        Node* current = buckets[i];
        while (current != NULL) 
        {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp); // Free memory
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, N);

    return 0;
}
