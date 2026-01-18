// Maimoona Aziz #67070503473
// Write the program to convert the Infix expression into Postfix expression including the character of 'a-z' or 'A-Z' as the elements and operators '+', '-', '*', '/' in the expression. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAP 1000
char stack[CAP];
int top = -1;

void push (char data);
char pop ();
char peek ();
int precedence (char operator);

int main(void){
    char input[CAP];
    scanf("%s", input);

    char postFix[CAP];
    int j = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (isalnum(c)) { // Operand: Append to postfix expression
            postFix[j++] = c;
        } 
        else if (c == '(') { // Left parenthesis: Push onto stack
            push(c);
        } 
        else if (c == ')') { // Right parenthesis: Pop until '('
            while (top != -1 && peek() != '(') {
                postFix[j++] = pop();
            }
            if (top != -1) pop(); // Remove '('
        } 
        else { // Operator
            while (top != -1 && precedence(peek()) >= precedence(c) && peek() != '(') {
                postFix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postFix[j++] = pop();
    }

    postFix[j] = '\0'; 
    printf("%s\n", postFix);
}

void push (char data){
    if (top < CAP - 1){
        stack[++top] = data;
    }
}

char pop (){
    if (top >= 0){
        return stack[top--];
    }
    return '\0';
}

char peek (){
    if (top >= 0){
        return stack[top];
    }
    return '\0';
}

int precedence (char operator) {
    if (operator == '+' || operator == '-'){
        return 1;
    }
    if (operator == '*' || operator == '/'){
        return 2;
    }
    return 0;
}