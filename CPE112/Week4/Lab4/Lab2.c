// Maimoona Aziz #67070503473
// Create a program that can detect the input word and determine whether it is palindrome or not by using the "Stack"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 1000

char stack[CAP];
int top = -1;


void push (char data);
int isPalindrome(char word[]);

int main(void){
    char input[CAP];
    scanf("%s", input);

    if (isPalindrome(input)){
        printf("yes\n");
    } else {
        printf("no\n");
    }

}

void push (char data){
    if (top == CAP - 1){
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}

int isPalindrome(char word[]){
    int length = strlen(word);

    for (int i = 0; i < length; i++){
        push(word[i]);
    }

    int left = 0;
    int right = length-1;

    while (left < right){
        if (stack[left] != stack[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}