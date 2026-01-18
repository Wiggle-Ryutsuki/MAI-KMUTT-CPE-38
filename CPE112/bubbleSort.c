// Maimoona Aziz #67070503473
// Bubble sort algorithm

#include <stdio.h>

void bubbleSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, len);
}

void bubbleSort(int arr[], int n){
    int totalSwaps = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                totalSwaps++;
            }
        }
    }
    for (int k = 0; k < n; k++){
        printf("%d ", arr[k]);
    }
    printf("\nTotal swaps: %d\n", totalSwaps);
}