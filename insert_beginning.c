// Linked List: Inserting a node at beginning

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head; // global variable, can be accessed anywhere
void Insert(int x);
void Print();

int main(int argc, char const *argv[])
{
	head = NULL; // empty list
	printf("How many numbers?\n");
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter the number\n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}

	return 0;
}

void Insert(int x)
{
	// malloc返回指向起始地址的指针
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print()
{
	struct Node *temp = head;
	printf("List is: ");
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}