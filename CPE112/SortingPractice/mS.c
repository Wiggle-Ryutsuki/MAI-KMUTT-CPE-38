#include <stdio.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = (high + low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}