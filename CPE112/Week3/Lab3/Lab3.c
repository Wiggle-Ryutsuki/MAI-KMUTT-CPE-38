// Create a program using the doubly linked list and print out the result of list that you have created
// Maimoona Aziz #67070503473

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) {  // If no node exists
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

void deleteNode(int x) {
    struct node *temp = head;
    
    while (temp != NULL) {
        if (temp->data == x) {
            if (temp->prev != NULL) 
                temp->prev->next = temp->next;
            else 
                head = temp->next;  // Deleting head, update head pointer

            if (temp->next != NULL) 
                temp->next->prev = temp->prev;
            else 
                tail = temp->prev;  // Deleting tail, update tail pointer

            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void searchNeighbors(int x) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            if (temp->prev == NULL) 
                printf("NULL ");
            else 
                printf("%d ", temp->prev->data);

            if (temp->next == NULL) 
                printf("NULL\n");
            else 
                printf("%d\n", temp->next->data);

            return;
        }
        temp = temp->next;
    }
    printf("none\n");
}

void printForward() {
    if (head == NULL) {
        printf("none\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward() {
    if (tail == NULL) {
        printf("none\n");
        return;
    }

    struct node *temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(void) {
    char command[4];
    int x;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "END") == 0)
            break;
        else if (strcmp(command, "ADD") == 0) {
            scanf("%d", &x);
            addNode(x);
        }
        else if (strcmp(command, "DEL") == 0) {
            scanf("%d", &x);
            deleteNode(x);
        }
        else if (strcmp(command, "SCH") == 0) {
            scanf("%d", &x);
            searchNeighbors(x);
        }
    }

    printForward();
    printBackward();
}
