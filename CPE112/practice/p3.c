// Creating a linked list || using scanf
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
void appendNode(Node **first, int data);

int main(void){
    int n, data;
    Node *first = NULL; // Create a first
    printf("Enter length of linked list: ");scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Node %d: ", i);
        scanf("%d", &data);
        appendNode(&first, data);
    }

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

    return newNode;
}

void appendNode (Node **first, int data){
    Node *newNode = createNode(data);

    if (*first == NULL){
        *first = newNode;
        return;
    }

    Node *temp = *first;
    while (temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
}
