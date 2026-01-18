// Write a program to take n integer inputs from the user, store them in a 1D array, and calculate the sum of all elements. Output the result.

 #include <stdio.h>

 int main(void){
    int n; printf("Input length of array: ");scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    printf("Sum is %d", sum);
 }