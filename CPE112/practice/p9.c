// Singly linked list practice
// Create list
// Search for index and data || find length || Insertion || Deletion
// Reverse

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int x);
void printList(Node* head);
Node* traverse(Node* head, int n);
void appendNode(Node **first, int data);

int main(void){
    printf("Choose an option:\n1: Insertion\n2: Deletion\n3: Searching\n4: Reversing\n");
    int a; scanf("%d", &a);
    int insert, delete, search;

    switch(a){
        case 1:
            printf("1: Insertion at the head\n2: Insertion after a given node\n3: Insertion at the tail\n");
            scanf("%d", &insert);

            switch (insert){
                case 1: {
                    // Hardcoded list
                    Node *head = createNode(10);
                    head->next = createNode(20);
                    head->next->next = createNode(30);
                    head->next->next->next = createNode(40);

                    printf("Linked List:\n");
                    printList(head);

                    int x;
                    printf("Enter value to insert to head: "); scanf("%d", &x);

                    // Allocate memory for new data
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->data = x;
                    newNode->next = head;
                    head = newNode;

                    printList(head);

                    break;
                }

                case 2: {
                    // Hardcoded list
                    Node *head = createNode(10);
                    head->next = createNode(20);
                    head->next->next = createNode(30);
                    head->next->next->next = createNode(40);

                    printf("Linked List:\n");
                    printList(head);

                    int n, x;
                    printf("Enter the index you want to insert your data after: "); scanf("%d", &n);
                    Node *prevNode = traverse(head, n);
                    if (prevNode == NULL){
                        printf("Given node cannot be NULL!");
                        return 1;
                    }

                    printf("Enter value: "); scanf("%d", &x);

                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->data = x;
                    
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;

                    printList(head);

                    break;
                }

                case 3: {
                    // Hardcoded list
                    Node *head = createNode(10);
                    head->next = createNode(20);
                    head->next->next = createNode(30);
                    head->next->next->next = createNode(40);

                    printf("Linked List:\n");
                    printList(head);

                    int x;
                    printf("Enter value to insert to tail: "); scanf("%d", &x);

                    Node *tail = head;
                    while (tail->next != NULL){
                        tail = tail->next;
                    }

                    // Allocate memory for new data
                    Node *newNode = (Node *)malloc(sizeof(Node));
                    newNode->data = x;
                    newNode->next = tail->next;
                    tail->next = newNode;

                    printList(head);

                    break;                  
                }
            }
            break;

        case 2:
            printf("1: Deletion at the head\n2: Deletion after a given node\n3: Deletion at the tail\n");
            scanf("%d", &delete);

            switch (delete){
                case 1: {
                    int x;
                    Node *head = NULL;

                    printf("Enter length of your list: "); scanf("%d", &x);
                    int n;
                    for (int i = 0; i < x; i++){
                        printf("Element [%i]: ", i);
                        scanf("%d", &n);
                        appendNode(&head, n);
                    }
                    puts(""); 

                    printf("Linked List:\n");
                    printList(head);

                    if (head != NULL){
                        Node *temp = head;
                        head = head->next;
                        free(temp);
                    }

                    printList(head);
                    
                    break;
                }

                case 2: {
                    int x;
                    Node *head = NULL;
                    printf("Enter length of your list: "); scanf("%d", &x);
                    int n;
                    for (int i = 0; i < x; i++){
                        printf("Element [%i]: ", i);
                        scanf("%d", &n);
                        appendNode(&head, n);
                    }
                    puts(""); 

                    printf("Linked List:\n");
                    printList(head);

                    int y;
                    printf("Enter the index you want to delete your data after: "); scanf("%d", &y);
                    Node *prevNode = traverse(head, y);
                    if (prevNode == NULL){
                        printf("Given node cannot be NULL!");
                        return 1;
                    }

                    if (prevNode->next != NULL){
                        Node *temp = prevNode->next;
                        prevNode->next = prevNode->next->next;
                        free(temp);
                    }

                    printList(head);
                    
                    break;
                }

                case 3: {
                    int x;
                    Node *head = NULL;

                    printf("Enter length of your list: "); scanf("%d", &x);
                    int n;
                    for (int i = 0; i < x; i++){
                        printf("Element [%i]: ", i);
                        scanf("%d", &n);
                        appendNode(&head, n);
                    }
                    puts(""); 

                    printf("Linked List:\n");
                    printList(head);

                    Node *tail = head;
                    while (tail->next->next != NULL){
                        tail = tail->next;
                    }

                    if (tail != NULL){
                        free(tail->next);
                        tail->next = NULL;
                    }

                    printList(head);
                    
                    break;
                }
            }
            break;

        case 3:
            printf("1: Find length of a list\n2: Search data in given index\n");
            scanf("%d", &search);

            switch (search){
                case 1: {
                    // Hardcoded list
                    Node *head = createNode(10);
                    head->next = createNode(20);
                    head->next->next = createNode(30);
                    head->next->next->next = createNode(40);

                    int count = 0;
                    Node *temp = head;
                    while (temp){
                        count++;
                        temp = temp->next;
                    }

                    printf("Length: %d\n", count);
                    break;
                }

                case 2: {
                    // Hardcoded list
                    Node *head = createNode(10);
                    head->next = createNode(20);
                    head->next->next = createNode(30);
                    head->next->next->next = createNode(40);

                    int x;
                    printf("Index: "); scanf("%i", &x);

                    Node *temp = head;
                    int index = 0;
                    while (temp) {
                        if (index == x) { // Compare index, not pointer
                            printf("Data: %d", temp->data);
                            break;
                        }
                        temp = temp->next;
                        index++;  // Update index
                    }

                    if (temp == NULL) {
                        printf("Index out of range.\n");
                    }
                    
                    break;
                }
            }

            break;

        case 4: {
            printf("reversing");
        }
        default:
            printf("Invalid choice\n");
            return 1;
    }
    
}

Node* createNode(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

void appendNode(Node **first, int data){
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

void printList(Node* head){
    Node *temp = head;
    if (head == NULL) {
        printf("List is now empty.\n");
    }else{
        while (temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        puts("");
    }
}

// Returns node
Node* traverse(Node* head, int n){
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < n){
        temp = temp->next;
        count++;
    }
    return temp;
}