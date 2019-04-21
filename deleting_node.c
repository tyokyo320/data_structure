/* To delete a node from linked list, we need to do following steps.
   
   1) Find previous node of the node to be deleted.
   2) Change the next of previous node.
   3) Free memory for the node to be deleted. */


#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data);
void deleteNode(struct Node **head_ref, int key);
void printList(struct Node *node);

int main(int argc, char const *argv[])
{
	// start with the empty list
	struct Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List:");
	printList(head);
	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1:");
	printList(head);

	return 0;
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **head_ref, int key)
{
	// store head node
	struct Node* temp = *head_ref, *prev;

	// if head node itself holds the keys to be deleted
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;	// change head
		free(temp);	// free old head
		return;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while(temp != NULL && temp->data != key)
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

	free(temp);	// free memory
}

// this function prints contents of linked list starting from
// the given node
void printList(struct Node *node)
{
	while(node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}
}