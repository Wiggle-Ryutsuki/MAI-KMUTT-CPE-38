#include <stdio.h>

#define SIZE 10

void printOutArray(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);


int main (void){
    int arr1[SIZE] = {19, 18, 13, 11, 8 , 3 , 17, 20, 40, 30};
    printf("Unsorted Array: "); printOutArray(arr1, SIZE); printf("\n");

    quickSort(arr1, 0, SIZE-1);
    printf("Quick Sorted Array: "); printOutArray(arr1, SIZE); printf("\n");

    int arr2[SIZE] = {19, 18, 13, 11, 8 , 3 , 17, 20, 40, 30};
    mergeSort(arr2, 0, SIZE-1);
    printf("Merge Sorted Array: "); printOutArray(arr2, SIZE); printf("\n");
}

void printOutArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end){
        if (start < end){
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

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = (high + low) /2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int i = low, j = mid+1, k = 0;
    int temp[high-low+1];

    while (i <= mid && j <= high){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i]; i++;
        } else {
            temp[k] = arr[j]; j++;
        } k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++; k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++; k++;
    }

    for (int l = low; l <= high; l++){
        arr[low + l] = temp[l];
    }
}