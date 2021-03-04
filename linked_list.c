#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create(int value);
void insert_at_begin(Node **head, Node *node);
void insert_at_end(Node **head, Node *node);
void insert_at_index(Node **head, Node *node, int index);
void deleteNode(Node **head, int key);
void printLL(Node *head);

void test1()
{
    Node *head = NULL;

    insert_at_begin(&head, create(1));
    insert_at_begin(&head, create(2));
    insert_at_begin(&head, create(3));
    insert_at_begin(&head, create(4));
    insert_at_begin(&head, create(5));

    assert(head->data == 5);
    assert(head->next->data == 4);
    assert(head->next->next->data == 3);
    assert(head->next->next->next->data == 2);
    assert(head->next->next->next->next->data == 1);
}

void test2()
{
    Node *head = NULL;

    insert_at_end(&head, create(5));
    insert_at_end(&head, create(4));
    insert_at_end(&head, create(3));
    insert_at_end(&head, create(2));
    insert_at_end(&head, create(1));

    assert(head->data == 5);
    assert(head->next->data == 4);
    assert(head->next->next->data == 3);
    assert(head->next->next->next->data == 2);
    assert(head->next->next->next->next->data == 1);
}

void test3()
{
    Node *head = NULL;

    insert_at_index(&head, create(3), 30);

    head = create(1);
    insert_at_index(&head, create(2), 2);
    insert_at_index(&head, create(2), 20);
    insert_at_index(&head, create(5), 2);

    assert(head->data == 1);
    assert(head->next->data == 5);
    assert(head->next->next->data == 2);
}

void test4()
{
    Node *head = NULL;

    insert_at_begin(&head, create(1));
    insert_at_begin(&head, create(2));

    printLL(head);
}

int main(int argc, char const *argv[])
{
    // just a pointer
    // head -> NULL

    // test1();
    // test2();
    // test3();
    test4();

    printf("All test Pass!\n");
    return 0;
}

/**
 * @param head: pointer to *head
 * @param node: pointer to  node
 *
 */
void insert_at_begin(Node **head, Node *node)
{
    node->next = *head;
    *head = node;
}

void insert_at_end(Node **head, Node *node)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        *head = node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
}

/**
 * @param index: 0 <= index
 *
 */
void insert_at_index(Node **head, Node *node, int index)
{
    if (index == 0)
    {
        node->next = *head;
        *head = node;
        return;
    }

    // head->1->2->NULL;
    if (*head == NULL)
    {
        if (index > 1)
        {
            printf("out of range: %d\n", index);
            return;
        }
        else
        {
            node->next = *head;
            *head = node;
            return;
        }
    }
    else
    {
        Node *temp = *head;
        for (int i = 1; i < index - 1; i++)
        {
            temp = temp->next;

            if (temp == NULL)
            {
                printf("-out of range: %d\n", index);
                return;
            }
        }
        node->next = temp->next;
        temp->next = node;
    }
}

Node *create(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void deleteNode(Node **head, int key)
{
    // store head node
    Node *temp = *head, *prev;

    // if head node itself holds the keys to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // change head
        free(temp);         // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // if key was not present in linked list
    if (temp == NULL)
    {
        return;
    }

    // unlink the node from linked list
    prev->next = temp->next;

    free(temp); // free memory
}

void printLL(Node *head)
{
    Node *temp = head;
    printf("List is:");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}