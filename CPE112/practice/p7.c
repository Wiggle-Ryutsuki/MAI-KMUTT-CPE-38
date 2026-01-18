// Find the middle node in a linked list and print

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int x);
int middleFinder(Node *head);

int main (void){
    // Hardcode a linked list
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    Node *temp = head;
    while (temp){
        printf("%i ", temp->data);
        temp = temp->next;
    }

    puts("");
    printf("%i", middleFinder(head));
}

Node* createNode(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

int middleFinder(Node *head){
    Node* tort_ptr = head;
    Node* hare_ptr = head;
    while(hare_ptr != NULL && hare_ptr->next != NULL){
        tort_ptr = tort_ptr->next;
        hare_ptr = hare_ptr->next->next;
    }
    return tort_ptr->data;
}