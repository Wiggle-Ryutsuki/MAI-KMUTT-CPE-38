// Write a program in C to print the first 50 natural numbers using recursion.

#include <stdio.h>

void printNum(int n);

int main(void){
    int n = 1;
    printNum(n);
}

void printNum(int n){
    if (n <= 50){
        printf("%d ", n);
        printNum(n + 1);
    }
}