// Maimoona Aziz #67070503473

#include <stdio.h>

int binary(int a);

int main(void){
    // Input number
    int input; scanf("%d", &input);
    // Call function for binary
    int result = binary(input);

    // Display output
    printf("%d", result);
}

// Function to compute binary
int binary(int a){
    if (a == 0){
        return 0;
    }
    return a % 2 + 10 * binary(a / 2);
}