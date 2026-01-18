// Write a program in C to find the sum of all elements of the array.

#include <stdio.h>

int sumArray(int *array, int n);

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n]; printf("Input %d elements in the array: \n", n);
    // Get input from user to store in array
    for (int i = 0; i < n; i++){
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
    }
    
    // Function to calculate the sum of all numbers in the array
    int sum = sumArray(array, n);

    // Print sum
    printf("Sum of all elements stored in the array is: %d", sum);
}

int sumArray(int *array, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += array[i];
    }
    return sum;
}