// Quick sort algorithm

#include <stdio.h>

void swap (int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort (int arr[], int low, int high, int n);

int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        printf("Index[%i]: ", i);
        scanf("%i", &arr[i]);
    }

    quickSort(arr, 0, n-1, n);

    // Print array
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void quickSort (int arr[], int low, int high, int n){
    if (low < high){
        int loc = partition (arr, low, high);

        // Print array
        for (int i = 0; i < n; i++){
            printf("%i ", arr[i]);
        } printf("\n");

        quickSort (arr, low, loc-1, n);
        quickSort (arr, loc+1, high, n);
    }
}

int partition (int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end){
        while (arr[start] <= pivot){
            start++;
        }
    
        while (arr[end] > pivot){
            end--;
        }
    
        if (start < end){
            swap(&arr[start], &arr[end]);
        }
    }

    swap(&arr[low], &arr[end]);
    return end;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
