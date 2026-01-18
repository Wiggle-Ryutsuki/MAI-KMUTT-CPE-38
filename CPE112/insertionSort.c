// Maimoona Aziz #67070503473
// Insertion sort algorithm

#include <stdio.h>

void insertionSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, len);
}

void insertionSort(int arr[], int n){
    int totalShifts = 0;

    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while (j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            totalShifts++;
            j--;
        }
        arr[j+1] = key;
    }
    for (int k = 0; k < n; k++){
        printf("%d ", arr[k]);
    }
    printf("\nTotal shifts: %d\n", totalShifts);
}