#include <stdio.h>

#define SIZE 10

void printOutArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main (void) {
    int arr1[SIZE] = {19, 30, 28, 6, 2, 10, 44, 23, 8, 4};
    int arr2[SIZE] = {19, 30, 28, 6, 2, 10, 44, 23, 8, 4};
    int arr3[SIZE] = {19, 30, 28, 6, 2, 10, 44, 23, 8, 4};
    printf("Unsorted Array: "); printOutArray(arr1, SIZE);

    bubbleSort(arr1, SIZE);
    selectionSort(arr2, SIZE);
    insertionSort(arr3, SIZE);
}

void printOutArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    } printf("\n");
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Bubble Sorted Array: ");
    printOutArray(arr, n);
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Selection Sorted Array: ");
    printOutArray(arr, n);
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("Insertion Sorted Array: ");
    printOutArray(arr, n);
}