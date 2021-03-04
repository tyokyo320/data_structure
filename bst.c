//  Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *getNewNode(int data);
struct BstNode *insert(struct BstNode *root, int data);
bool Search(struct BstNode *root, int data);
int min(struct BstNode *root);
int max(struct BstNode *root);
struct BstNode *findMin(struct BstNode *root);
struct BstNode *findMax(struct BstNode *root);
struct BstNode *delete (struct BstNode *root, int data);
void inorderTreeWalk(struct BstNode *root);

int main(int argc, char const *argv[])
{
    struct BstNode *root = NULL; // Creating an empty tree

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    int number;
    printf("Enter number be searched\n");
    scanf("%d", &number);
    if (Search(root, number) == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    printf("Min number:%d\n", findMin(root));
    printf("Max number:%d\n", findMax(root));
    root = delete (root, 12);
    inorderTreeWalk(root);
}

struct BstNode *getNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode *insert(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

bool Search(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

// iterative
int min(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// recursion
int max(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is empty\n");
        return -1;
    }

    else if (root->right == NULL)
    {
        return root->data;
    }
    // Search in right subtree
    return findMax(root->right);
}

struct BstNode *findMin(struct BstNode *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct BstNode *findMax(struct BstNode *root)
{
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct BstNode *delete (struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            struct BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct BstNode *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 children
        else
        {
            struct BstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

void inorderTreeWalk(struct BstNode *root)
{
    if (root != NULL)
    {
        inorderTreeWalk(root->left);
        printf("%d ", root->data);
        inorderTreeWalk(root->right);
    }
}