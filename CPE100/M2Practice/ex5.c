// Write a program in C to count the total number of duplicate elements in an array.

#include <stdio.h>

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n]; printf("Input %d elements in the array: \n", n);
    // Get input from user to store in array
    for (int i = 0; i < n; i++){
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (array[j] == array[i]){
                count++;
            }
        }
    }
    printf("Total number of duplicate elements found in the array: %d\n", count);
}