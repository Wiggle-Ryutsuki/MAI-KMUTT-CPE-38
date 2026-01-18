// Maimoona Aziz #67070503473

#include <stdio.h>

int fibonacci(int a);

int main(void){
    // Input non-negative number
    int input; scanf("%d", &input);
    if (input < 0){
        printf("Fibonacci is not defined for negative numbers!\n");
        return 0;
    }
    // Call function for fibonacci
    int result = fibonacci(input);

    // Display output
    printf("Fibonacci of %d is %d", input, result);
}

// Function to compute fibonacci
int fibonacci(int a){
    if (a <= 1){
        return a;
    }
    return fibonacci(a - 1) + fibonacci(a - 2);
}