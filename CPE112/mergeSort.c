// Merge sort algorithm

#include <stdio.h>

void merge (int arr[], int low, int mid, int high, int size);
void mergeSort (int arr[], int low, int high, int size);

int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        printf("Index[%i]: ", i);
        scanf("%i", &arr[i]);
    }

    mergeSort (arr, 0, n-1, n);

    // Print array
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void mergeSort (int arr[], int low, int high, int size){
    if (low < high){
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid, size);
        mergeSort(arr, mid+1, high, size);
        merge(arr, low, mid, high, size);
    }
}

void merge (int arr[], int low, int mid, int high, int size){
    int i = low;
    int j = mid+1;
    int k = low;

    int b[size];

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid){
        while (j <= high){
            b[k] = arr[j];
            j++; k++;
        }
    } else {
        while (i <= mid){
            b[k] = arr[i];
            i++; k++;
        }
    }

    for (k = low; k <= high; k++){
        arr[k] = b[k];
    }

    // Print array
    for (int i = 0; i < size; i++){
        printf("%i ", arr[i]);
    } printf("\n");
}

/*
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right, int size) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    // Print array after every merge
    printArray(arr, size);
}

void mergeSort(int arr[], int left, int right, int size) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Initial array:\n");
    printArray(arr, size);
    printf("\nSorting steps:\n");

    mergeSort(arr, 0, size - 1, size);

    printf("\nFinal sorted array:\n");
    printArray(arr, size);

    return 0;
}

*/