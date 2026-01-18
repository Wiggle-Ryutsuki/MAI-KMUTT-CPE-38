// Write a program in C to read n number of values in an array and display them in reverse order.

#include <stdio.h>

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n]; printf("Input %d elements in the array: \n", n);
    // Get input from user to store in array
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
    }
    
    // Output array
    printf("The values stored into the array are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    puts("");

    printf("The values stored into the array in reverse are: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}