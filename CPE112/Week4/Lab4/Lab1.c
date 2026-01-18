// Maimoona Aziz #67070503473

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 10
int stack[CAP];
int top = -1;

int push (int data);
void pop ();
void peek();
void printStack();

int main(void){
    char input[10];
    int data;
    while (1){
        scanf("%s", &input);
        if (strcmp(input, "PUSH") == 0){
            scanf("%d", &data);
            push(data);
        } else if (strcmp(input, "POP") == 0){
            pop();
        } else if (strcmp(input, "PEEK") == 0){
            peek();
        } else if (strcmp(input, "END") == 0){
            printStack();
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
}

int push (int data){
    if (top == CAP - 1){
        printf("Stack is full\n");
        return -1;
    }
    stack[++top] = data;
    return 0;
}

void pop (){
    if (top == -1){
        printf("Stack is empty\n");
    } else {
        printf("%d \n", stack[top]);
        top--;
    }
}

void peek(){
    if (top == -1){
        printf("Stack is empty\n");
    } else {
        printf("%d \n", stack[top]);
    }
}

void printStack() {
    if (top == -1){
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }
}