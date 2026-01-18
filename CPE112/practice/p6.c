// Insert an element at the end

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void createList(Node **head, int data);
void insertTail(Node *prevNode, int x);

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
    printf("Enter value of element: "); scanf("%d", &n);

    Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    insertTail(tail, n);

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

void insertTail(Node *tail, int x){
    if (tail == NULL){
        printf("Given node cannot be NULL!\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    
    newNode->next = tail->next;
    tail->next = newNode;
}