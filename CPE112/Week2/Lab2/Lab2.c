// Maimoona Aziz #67070503473
// Given an array of integers and a target sum, find two numbers in the array that add up to the target. Return their indices.

#include <stdio.h>

int main(void){
    int n; scanf("%d", &n); // sizr of array
    int target; scanf("%d", &target); // Target sum

    // Input integers into array
    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    // Check for target sum
    int a, b;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (array[i] + array[j] == target){
                a = j;
                b = i;
                break;
            }
        }
    }

    printf("%d %d", a, b);
}