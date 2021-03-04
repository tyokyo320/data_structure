// Linked list: Inserting a node at nth position

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head;
void Insert(int data, int n);
void Print();

int main(int argc, char const *argv[])
{
	head = NULL;  // empty list
	Insert(2, 1); // List: 2
	Insert(3, 2); // List: 2,3
	Insert(4, 1); // List: 4,2,3
	Insert(5, 2); // List: 4,5,2,3
	Print();

	return 0;
}

void Insert(int data, int n)
{
	struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node *));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	struct Node *temp2 = head;
	for (int i = 0; i < n - 2; ++i)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Print()
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
