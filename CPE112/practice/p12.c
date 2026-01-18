// Queues

#include <stdio.h>
#include <string.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data);
void dequeue();
void peek();
void printQueue();

int main(void){
    char input[20];
    
    int data;

    while(1){
        scanf("%s", &input);
        if (strcmp(input, "ENQUEUE") == 0){
            scanf("%d", &data);
            enqueue(data);
        } else if (strcmp(input, "DEQUEUE") == 0){
            dequeue();
        }else if (strcmp(input, "PEEK") == 0){
            peek();
        } else if(strcmp(input, "END") == 0){
            printQueue();
            break;
        } else {
            printf("Invalid input\n");
        }
    } 
}

void enqueue(int data){
    if (rear > MAX - 1){
        printf("Queue is full\n");
    }
    if (front == -1){
        front++;
        rear++;
        queue[front] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue(){
    if (front == rear - 1){
        printf("Queue is empty\n");
    }

    front++;
}

void peek(){
    if (front == rear - 1){
        printf("Queue is empty\n");
    } else {
        printf("%d \n", queue[front]);
    }
}

void printQueue(){
    if (front == rear - 1){
        printf("Queue is empty\n");
    } else {
        for (int i = 0; i < rear; i++){
            printf("%d \n", queue[i]);
        }
    }
}