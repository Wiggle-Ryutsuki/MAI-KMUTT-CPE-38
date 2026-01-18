#include <stdio.h>

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

int partition(int arr[], int low, int high){
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
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;

    return end;
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc-1);
        quickSort(arr, loc+1, high);
    }
}