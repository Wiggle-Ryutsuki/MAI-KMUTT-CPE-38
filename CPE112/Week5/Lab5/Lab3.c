// Maimoona Aziz #67070503473

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int data;
    int priority;
} PriorityQueue;

PriorityQueue queue[MAX];
int front = -1, rear = -1;

void enqueue(int data, int priority);
void dequeue();
int peek();
void end();
void toLowerCase(char str[]);

// Define main function
int main(void){
    char input[20];
    int data;
    int priority;

    while(1){
        scanf("%s", input);
        toLowerCase(input);

        if (strcmp(input, "enqueue") == 0){
            scanf("%d %d", &data, &priority);
            enqueue(data, priority);

        } else if (strcmp(input, "dequeue") == 0){
            dequeue();

        }else if (strcmp(input, "peek") == 0){
            peek();

        } else if(strcmp(input, "end") == 0){
            end();
            break;

        } else {
            printf("Invalid input\n");
        }
    } 
}

void enqueue(int data, int priority){
    // Check if queue is full
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    // If queue is empty
    if (front == -1) {
        front = rear = 0;
        queue[rear].data = data;
        queue[rear].priority = priority;
        return;
    }

    rear++;
    // Insert the new element
    queue[rear].data = data;
    queue[rear].priority = priority;
}

void dequeue(){
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    int index = peek();

    for (int i = index; i < rear; i++){
        queue[i].data = queue[i+1].data;
        queue[i].priority = queue[i+1].priority;
    }
    
    front++;    
    if (front > rear){
        front = rear = -1; // Reset if empty
    }
}

int peek(){
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        int MaxPri = -1, index;
        for (int i = 0; i <= rear; i++){
            if (MaxPri < queue[i].priority) {
                MaxPri = queue[i].priority;
                index = i;
            }
        }

        printf("%d %d\n", queue[index].data, queue[index].priority);
        return index;
    }
}

void end() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    while (rear >= front) {
        printf("%d %d\n", queue[rear].data, queue[rear].priority);
        rear--;
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}