// Insert an element to the head of the linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void createList(Node **head, int data);
void pushList(Node **head, int x);

int main(void){
    Node *head = NULL;
    createList(&head, 10);
    createList(&head, 20);
    createList(&head, 30);
    createList(&head, 40);
    createList(&head, 50);

    printf("Linked list: ");
    Node *temp = head;
    while (temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\n");
    int n;
    printf("Enter an Element to be in the Front: "); scanf("%d", &n);
    pushList(&head, n);

    printf("Linked list: ");
    Node *print = head;
    while (print){
        printf("%d ", print->data);
        print = print->next;
    }
}

void createList(Node **head, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) { 
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
}

void pushList(Node **head, int x){
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->data = x;
    newHead->next = *head;
    *head = newHead;
}