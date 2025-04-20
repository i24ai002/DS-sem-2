#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert into the binary search tree
Node* insert(Node* root, int value) 
{
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) 
{
    if (root) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) 
{
    if (root) 
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(Node* root) 
{
    if (root) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() 
{
    int values[10];
    Node* root = NULL;

    printf("Enter 10 integer values:\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("Value %d: ", i + 1);
        scanf("%d", &values[i]);
        root = insert(root, values[i]);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    return 0;
}
