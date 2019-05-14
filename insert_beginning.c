// Linked List: Inserting a node at beginning

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;	// global variable, can be accessed anywhere
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
	
}