#include <stdio.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main(void){
    int n; printf("Length of Array: "); scanf("%i", &n);
    int arr[n];
    printf("Array: ");
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
        int mid = (low + high)/2;
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
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        } k++;
    }

    while (j <= high){
        temp[k] = arr[j];
        j++; k++;
    }
    
    while (i <= mid){
        temp [k] = arr[i];
        i++; k++;
    }

    for (int l = low; l <= high; l++){
        arr[low + l] = temp[l];
    }
}