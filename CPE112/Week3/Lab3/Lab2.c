// Given n people standing in a circle and a number k, every k-th person is eliminated(deleted) in rounds until only one person remains.
// Maimoona Aziz #67070503473

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createCircularList(struct node **head, int n)
{
    struct node *newNode, *temp;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->next = *head;

        if (*head == NULL)
        {
            *head = newNode;
            newNode->next = *head; 
        }
        else
        {
            temp = *head;
            while (temp->next != *head) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = *head;
        }
    }
}

int lastStanding(int n, int k)
{
    struct node *head = NULL;
    createCircularList(&head, n);

    struct node *ptr = head, *prev = NULL;
    
    while (ptr->next != ptr) // Until only one node remains
    {
        for (int i = 1; i < k; i++) // Move k-1 steps
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = ptr->next; // Remove k-th node
        free(ptr);
        ptr = prev->next; // Move to next node
    }

    int survivor = ptr->data;
    free(ptr);
    return survivor;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if (n < 1 || k < 1)
    {
        printf("Invalid");
        return 0;
    }

    printf("%d\n", lastStanding(n, k));
    return 0;
}
