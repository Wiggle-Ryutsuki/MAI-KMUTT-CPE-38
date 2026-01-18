// Write a program in C to copy the elements of one array into another array.

#include <stdio.h>

void copyArray(int *array, int *copy, int n);

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n]; printf("Input %d elements in the array: \n", n);
    // Get input from user to store in array
    for (int i = 0; i < n; i++){
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
    }
    
    // Function to duplicate array
    int copy[n];
    copyArray(array, copy, n);

    // Output array
    printf("The elements stored in the first array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    puts("");

    printf("The elements copied into the second array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", copy[i]);
    }
}

void copyArray(int *array, int *copy, int n){
    for (int i = 0; i < n; i++){
        copy[i] = array[i];
    }
}