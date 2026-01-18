// Maimoona Aziz #67070503473
// Write a C program to implement the Selection Sort algorithm and display the array after each iteration.

#include <stdio.h>

void selectionSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, len);
    printf("--Sorted array--\n");
    for (int k = 0; k < len; k++){
        printf("%d ", arr[k]);
    }
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        printf("--%d iteration--\n", i+1);
        int min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            printf("Swap: %d & %d\n", arr[i], arr[min]);
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        } else if (min == i){
            printf("Swap: %d & %d\n", arr[i], arr[min]);
        }
        for (int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}