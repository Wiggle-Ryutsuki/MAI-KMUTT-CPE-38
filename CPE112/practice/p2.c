// Creating a linked list || creating new nodes using a function
/*
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 1 2 3 4 
*/

#include <stdio.h>
#include <stdlib.h>

// Define struct for node
typedef struct node{
    int data;
    struct node* next;
}Node;

Node *createNode (int data);

int main(void){
    Node *first = createNode(10);

    first->next = createNode(20);

    first->next->next = createNode(30);  

    printf("Linked List: ");
    Node* temp = first;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node *createNode (int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = NULL;
}
