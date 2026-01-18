#include <stdio.h>

void bubbleSort(int arr[], int n);

int main (void){
    int n; printf("Length of Array: "); scanf("%i", &n);
    int arr[n];
    printf("Enter list: ");
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                printf("Swap %i and %i\n", arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}