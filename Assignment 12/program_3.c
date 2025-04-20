#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Tree node definition
typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new tree node
Node* createNode(int data) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find index of a value in inorder[]
int search(int inorder[], int start, int end, int value) 
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == value)
            return i;
    return -1;
}

// Function to build tree from inorder and preorder
Node* buildTree(int inorder[], int preorder[], int start, int end, int* preIndex) 
{
    if (start > end) return NULL;

    int current = preorder[*preIndex];
    (*preIndex)++;
    Node* node = createNode(current);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, current);

    node->left = buildTree(inorder, preorder, start, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, end, preIndex);

    return node;
}

// Inorder traversal
void printInorder(Node* root) 
{
    if (root) 
    {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Postorder traversal
void printPostorder(Node* root) 
{
    if (root) 
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    int inorder[SIZE]   = {1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[SIZE]  = {25, 8, 1, 13, 19, 5, 9, 4, 10, 3};
    int preIndex = 0;

    Node* root = buildTree(inorder, preorder, 0, SIZE - 1, &preIndex);

    printf("Inorder traversal of constructed tree: ");
    printInorder(root);
    printf("\n");

    printf("Postorder traversal of constructed tree: ");
    printPostorder(root);
    printf("\n");

    return 0;
}