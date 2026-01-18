// Write an algorithm to find the sum of first N natural || Top DOWN
// Maimoona Aziz #67070503473
// Iris French #67070503478

#include <stdio.h>

int algorithm_top_down (int n){
    if (n == 1){
        return 1;
    }
    return n + algorithm_top_down (n - 1);
}

int main(void){
    int n;
    printf("Enter a number: ");scanf("%d", &n);
    if (n < 1){
        printf("Input must be a natural number");
        return 1;
    }
    printf("Output: %d\n", algorithm_top_down(n));
}