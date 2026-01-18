// Maimoona Aziz #67070503473
// Task: Write a C program that supports the following commands for managing a singly linked list: insert at head || inserrt at tail || end

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for node
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int data);
void printList(Node* head);
void checkPrime (Node* head);

int main(void){
    Node *head = NULL;

    char input[10];
    int data;
    while (1){
        scanf("%s", &input);

        if (strcmp(input, "HEAD") == 0){
            scanf("%d", &data);
            
            Node *newNode = createNode(data);
            if (head == NULL){
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            printList(head);
        } else if (strcmp(input, "TAIL") == 0){
            scanf("%d", &data);
            Node *newNode = createNode(data);

            // Traverse to the tail
            Node *tail = head;
            while (tail->next != NULL){
                tail = tail->next;
            }
            // Allocate and then point
            if (tail == NULL){
                head = newNode;
                tail = head;

            } else {
                tail->next = newNode;
            }
            printList(head);
            
        } else if (strcmp(input, "END") == 0){
            printList(head);
            checkPrime (head);
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
}

Node* createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void printList(Node* head){
    if (head == NULL){
        printf("List is empty\n");
    } else {
        Node *temp = head;
        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    puts("");
}

void checkPrime (Node* head){
    Node *temp = head;
    int count;
    int arr[20];
    int x = 0;
    while (temp){
        int n = temp->data;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0){
                count++;
            } else {
                arr[x] = n;
            }
        }
        temp = temp->next;
        x++;
    }

    if (count == 0){
        printf("No prime number\n");
    } else {
        for (int i = 0; i < x; i++){
            printf("%d ", arr[i]);
        }
    }
    puts("");
}
