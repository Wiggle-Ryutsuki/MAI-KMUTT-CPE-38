// Reverse a linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode (int x);
void printList(Node *head);
Node* reverseList(Node *head);

int main(void){
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printList(head);
    head = reverseList(head);
    puts("");
    printList(head);
}

Node* createNode (int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

void printList(Node *head){
    Node *temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node* reverseList(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}