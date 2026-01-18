// Insert an element after a given node

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void createList(Node **head, int data);
void insertIntoList(Node *prevNode, int x);

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
    int index, n;
    printf("Enter where you want to place an element: "); scanf("%d", &index);
    printf("Enter value of element: "); scanf("%d", &n);

    int count = 0;
    Node *find = head;
    while(find != NULL && count < index){
        find = find->next;
        count++;
    }

    insertIntoList(find, n);

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

void insertIntoList(Node *prevNode, int x){
    if (prevNode == NULL){
        printf("Given node cannot be NULL!\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}