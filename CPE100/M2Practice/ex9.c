//  Write a program in C to add two numbers using pointers.

#include <stdio.h>

void sumNum(int *n, int *m, int *sum);

int main(void){
    int n; printf("Input number: "); scanf("%d", &n);
    int m; printf("Input number: "); scanf("%d", &m);
    int sum = 0;

    sumNum(&n, &m, &sum);

    printf("%d", sum);
}

void sumNum(int *n, int *m, int *sum){ 
    *sum = *n + *m;
}