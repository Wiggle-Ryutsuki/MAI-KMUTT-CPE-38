// Maimoona Aziz #67070503473
// Selection sort algorithm

#include <stdio.h>

void selectionSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, len);
}

void selectionSort(int arr[], int n){
    int totalSwaps = 0;

    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            totalSwaps++;
        }
    }
    for (int k = 0; k < n; k++){
        printf("%d ", arr[k]);
    }
    printf("\nTotal swaps: %d\n", totalSwaps);
}