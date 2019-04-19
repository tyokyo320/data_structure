#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node{
	int data;
	struct Node *next;
}

int main(int argc, char const *argv[])
{
	// start with the empty list
	struct Node* head = NULL;

	// Insert 6. so linked list becomes 6->NULL
	append(&head, 6);

	

	return 0;
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, insert a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	// 1. allocate node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	// 2. put in the data
	new_node->data = new_data;

	// 3. make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point to the new node
	(*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
	// 1. check if the given prev_node is NULL
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	// 2. allocate new node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct node));

	// 3. put in the data
	new_node->data = new_data;

	// 4. make next of new node as next of prev_node
	new_node->next = prev_node->;

	// 5. move the next of prev_node as new_node
	prev_node->next = new_node;

}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end */
void append(struct Node** head_ref, int new_data)
{
	// 1. allocate node
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;

	// 2. put in the data
	new_node->data = new_data;

	// 3. this new node is going to be the last node, so make next
	// 　　of it as NULL.
	new_node-> = NULL;

	// 4. if the linked list is empty, then make the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	// 5. else traverse till the last node
	while(list->next != NULL)
	{
		last = last->next;
	}

	// 6. change the next of last node
	last->next = new_node;
	return;
}

/* This function prints contents of linked list starting from head */
void printList(struct Node *node)
{
	while(node != NULL)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}