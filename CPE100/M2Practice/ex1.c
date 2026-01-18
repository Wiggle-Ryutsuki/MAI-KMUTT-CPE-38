// Write a program in C to store elements in an array and print them.

#include <stdio.h>

int main(void){
    int array[10];
    // Get input from user to store in array
    printf("Input 10 elements in the array: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
    }
    
    // Output array
    printf("Elements in array are: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
}