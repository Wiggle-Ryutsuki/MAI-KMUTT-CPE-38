// Work in a group of 3 || Write an algorithm to find the sum of first N natural || Bottom UP
// Maimoona Aziz #67070503473
// Iris French #67070503478

#include <stdio.h>

int algorithm_btm_up (int n){
    int result = 1;
    for (int i = 2; i <= n; i++){
        result += i;
    }
    return result;
}

int main(void){
    int n;
    printf("Enter a number: ");scanf("%d", &n);
    if (n < 1){
        printf("Input must be a natural number");
        return 1;
    }
    printf("Output: %d\n", algorithm_btm_up(n));
}