#include <stdio.h>

void swap (int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main (void){
    int n; printf("Length of Array: "); scanf("%i", &n);
    int arr[n];
    printf("Array: ");
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

// Swap Function
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition Function
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

// Quick Sort Function
void quickSort(int arr[], int low, int high){
    if (low < high){
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc-1);
        quickSort(arr, loc+1, high);
    }
}