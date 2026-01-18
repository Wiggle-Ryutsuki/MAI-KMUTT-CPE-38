// Maimoona Aziz #67070503473

#include <stdio.h>
#include <math.h>

int sumOfElements(int *arr, int n);
int productOfElements(int *arr, int n);
int sumOfPowers(int *arr, int n);

int main (void){
    int n; scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", arr[i]);
    }
    for (int i = 0; i < n; i++){
        if (arr[i] > 10 || arr[i] < -10){
            return 1;
        }
    }
    int choice; scanf("%d", &choice);
    if (choice < 1 || choice > 3){
        return 1;
    }

    int result;
    if (choice = 1){
        result = sumOfElements(&arr, n);
    } else if (choice = 2) {
        result = productOfElements(&arr, n);
    } else {
        result = sumOfPowers(&arr, n);
    }

    printf("%d", result);
} 

// Function to calculate the sum of elements
int sumOfElements(int *arr, int n){
    int result = 0;
    for (int i = 0; i < n; i++){
        result += arr[i];
    }
    return result;
}

// Function to calculate the product of elements
int productOfElements(int *arr, int n){
    int result = 1;
    for (int i = 0; i < n; i++){
        result *= arr[i];
    }
    return result;
}

// Function to calculate the sum of each element raised to the power of itself
int sumOfPowers(int *arr, int n){
    int array[n];
    int result = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < arr[i]; j++){
            arr[i] = array[i] * array[i];
        }
    }

    result = sumOfElements(&array, n);
    return result;
}
