// Doubly Linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}Node;

Node* createNode (int data);
void printList(Node* head);
Node* traverse(Node *head);

int main(void){
    Node *head = createNode(10);
    head->next = createNode(20); head->next->prev = head;
    head->next->next = createNode(30); head->next->next->prev = head->next;
    head->next->next->next = createNode(40); head->next->next->next->prev = head->next->next;

    int x;
    printf("1: Insert at head\n2: Insert at given node\n3:Insert at tail\n"); scanf("%d", &x);

    switch (x){
        case 1: {
            printList(head);
            int data;
            printf("Value: "); scanf("%d", &data);

            Node *newNode = createNode(data);
            newNode->next = head;
            if (head != NULL){
                head->prev = newNode;
            } else {
                printf("List is empty");
                return 1;
            }

            head = newNode;
            printList(head); 

            break;
        }

        case 2: {
            printList(head);
            int data, indx = -1;
            printf("Value: "); scanf("%d", &data);
            printf("Index: "); scanf("%d", &indx);

            Node *prevNode = traverse(head);

            if (prevNode == NULL){
                printf("Index cannot be NULL!");
                return 1;
            }

            if (head == NULL){
                printf("List is empty");
                return 1;
            }

            Node *newNode = createNode(data);
            newNode->next = prevNode;
            printList(head); 

            break;
        }
    }
}

Node* createNode (int data){
    // Hardcoded doubly linked list
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void printList(Node* head){
    Node *temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

Node* traverse(Node *head){
    if (head == NULL){
        return NULL;
    }

    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}