#include <stdio.h>

void insertSort(int arr[], int n);

int main(void){
    int n; printf("Length of Array: "); scanf("%i", &n);
    int arr[n];
    printf("Enter List: ");
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    insertSort(arr, n);

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void insertSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}