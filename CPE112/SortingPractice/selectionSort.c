#include <stdio.h>

void selectSort(int arr[], int n);

int main (void){
    int n; printf("Length of Array: "); scanf("%i", &n);
    int arr[n];
    printf("Enter list: ");
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    selectSort(arr, n);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void selectSort(int arr[], int n){
    for (int i = 0; i < n; i++){
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
        }
    }
}