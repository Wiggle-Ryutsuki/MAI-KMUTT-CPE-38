//Implementing two insertion functions of linked list: Insertion at the head of a linked list & Insertion at the rear of a linked list.
// Maimoona Aziz #67070503473

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displayList(struct node **start) // display sublist
{
    struct node *ptr = *start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("Empty list\n");
        return;
    }

    while (ptr != NULL) // loop until ptr is null
    {
        printf("%d ", ptr->data); // print value of current node
        ptr = ptr->next;       // move ptr to next node
    }
    puts("");
}

void insertNodeBegin(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) // linked list init
    {
        *head = newNode;
    }
    else
    {
        struct node *ptr = *head;
        // Linked list traversal to the rear
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

int main()
{
    struct node *head = NULL;
    int n, command, data; // Number of nodes to be inserted, command, data
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid");
        return 0;
    }
    scanf("%d", &command);
    if (command != 1 && command != 2)
    {
        printf("Invalid");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        if (command == 1)
        {
            insertNodeBegin(&head, data);
        }
        else if (command == 2)
        {
            insertNodeEnd(&head, data);
        }
    }
    displayList(&head);
}