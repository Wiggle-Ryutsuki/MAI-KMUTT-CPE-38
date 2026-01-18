// Write a program in C to store n elements in an array and print the elements using a pointer.

#include <stdio.h>

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n];

    printf("Input the elements to store in the array:\n");
    for (int i = 0; i < n; i++){
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++){
        printf("Element %d: %d\n", i, array[i]);
    }
}