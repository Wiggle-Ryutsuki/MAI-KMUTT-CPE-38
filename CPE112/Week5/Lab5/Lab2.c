// Maimoona Aziz #67070503473

#include <stdio.h>
#include <string.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data);
void dequeue();
void peek();
void printQueue();
void toLowerCase(char str[]);

int main(void){
    char input[20];
    int data;

    while(1){
        scanf("%s", input);
        toLowerCase(input);

        if (strcmp(input, "enqueue") == 0){
            scanf("%d", &data);
            enqueue(data);

        } else if (strcmp(input, "dequeue") == 0){
            dequeue();
            printf("\n");

        }else if (strcmp(input, "peek") == 0){
            peek();

        } else if(strcmp(input, "end") == 0){
            printQueue();
            break;

        } else {
            printf("Invalid input\n");
        }
    } 
}

void enqueue(int data){
    // Check if queue is full
    if ((rear + 1) % MAX == front){
        printf("Queue is full\n");
        return;
    }

    // If queue is empty, set front to 0
    if (front == -1){
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

void dequeue(){
    // Check if queue is empty
    if (front == - 1){
        printf("Queue is empty");
        return;
    }

    printf("%d ", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek(){
    // Check if queue is empty
    if (front == -1){
        printf("Queue is empty \n");
    } else {
        printf("%d\n", queue[front]);
    }
}

void printQueue(){
    // Check if queue is empty
    if (front == -1){
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    // Print the last element
    printf("%d\n", queue[rear]);
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}