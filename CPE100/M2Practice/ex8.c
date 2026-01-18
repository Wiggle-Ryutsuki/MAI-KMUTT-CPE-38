// Write a program in C to calculate the sum of numbers from 1 to n using recursion.

#include <stdio.h>

int sumRange(int n);

int main(void){
    int n; printf("Input range: "); scanf("%d", &n); // Range

    int sum = sumRange(n);

    printf("%d", sum);
}

int sumRange(int n){ 
    int sum;
    if (n == 1){
        return 1;
    } else {
        sum = n + sumRange(n - 1);
    }
    return sum;
}