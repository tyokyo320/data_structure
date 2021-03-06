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
    root = insert(root, 15);
    root = insert(root, 8);
    root = insert(root, 12);

    int number;
    printf("Enter number be searched\n");
    scanf("%d", &number);
    if (Search(root, number) == true)
        printf("Found\n");
    else
        printf("Not Found\n");
    printf("Min number:%d\n", min(root));
    printf("Max number:%d\n", max(root));

    root = delete (root, 15);
    inorderTreeWalk(root);
}

// 原二叉排序树为空时，新插入的节点为根节点
struct BstNode *getNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 在二叉排序树插入关键字为data的新节点(递归)
struct BstNode *insert(struct BstNode *root, int data)
{
    if (root == NULL)
        root = getNewNode(data);
    // 树中存在相同关键字的节点，插入失败
    else if (root->data == data)
        return root;
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// 二叉排序树的查找
bool Search(struct BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
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
        root = root->left;

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
        return root->data;

    // Search in right subtree
    return max(root->right);
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

// 二叉排序树的删除
struct BstNode *delete (struct BstNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
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

// 中序遍历输出递增的有序数列
void inorderTreeWalk(struct BstNode *root)
{
    if (root != NULL)
    {
        inorderTreeWalk(root->left);
        printf("%d ", root->data);
        inorderTreeWalk(root->right);
    }
}