#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int value;
    int key;
    struct pair *next;
};

void display(struct pair array[], int size);
void search(struct pair array[], int size);
void insert(struct pair array[], int size);

int main(int argc, char const *argv[])
{
    int size, temp, j;

    printf("Enter the size of the table: ");
    scanf("%d", &size);

    struct pair hash_tabie[size];

    while (j < size)
    {
        hash_tabie[j].next = NULL;
        j++;
    }

    j = 0;
    while (j < size)
    {
        hash_tabie[j].value = -1;
        j++;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &temp);
        hash_tabie[temp % size].value = temp;
        hash_tabie[temp % size].key = temp % size;
    }
    printf("\n");
    display(hash_tabie, size);

    // search(hash_tabie, size);
    insert(hash_tabie, size);
    display(hash_tabie, size);

    return 0;
}

void display(struct pair array[], int size)
{
    printf("Value\tKey\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n", array[i].value, array[i].key);
        struct pair *ptr;
        ptr = array[i].next;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void search(struct pair array[], int size)
{
    int se;
    printf("Enter the elements you want to search: ");
    scanf("%d", &se);

    if (array[se % size].value == se)
    {
        printf("Element Exist at %d", se % size);
    }
    else
    {
        printf("Element does not exist\n");
    }
}

void insert(struct pair array[], int size)
{
    int inp;

    printf("Enter the element you want to insert: ");
    scanf("%d", &inp);
    if (array[inp % size].value == -1)
    {
        array[inp % size].value = inp;
    }
    else
    {
        struct pair *kvpair;
        kvpair = (struct pair *)malloc(sizeof(struct pair *));
        kvpair->value = inp;
        kvpair->next = NULL;
        array[inp % size].next = kvpair;
    }
}