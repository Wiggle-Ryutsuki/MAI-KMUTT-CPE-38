// Creating a linked list
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

int main(void){
    Node *first = (Node *)malloc(sizeof(Node));
    first->data = 10;

    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 20;

    Node *third = (Node *)malloc(sizeof(Node));
    third->data = 30;   

    first->next = second;
    second->next = third;
    third->next = NULL;

    printf("Linked List: ");
    Node* temp = first;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(first);
    free(second);
    free(third);
}
