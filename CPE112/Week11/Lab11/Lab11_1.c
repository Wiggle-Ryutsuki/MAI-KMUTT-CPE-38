// Maimoona Aziz #67070503473
// Write a C program to implement the Bubble Sort algorithm and display the array after each iteration.

#include <stdio.h>

void bubbleSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, len);
    printf("--Sorted array--\n");
    for (int k = 0; k < len; k++){
        printf("%d ", arr[k]);
    }
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        printf("--%d iteration--\n", i+1);
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                printf("Swap: %d & %d\n", arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        for (int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}