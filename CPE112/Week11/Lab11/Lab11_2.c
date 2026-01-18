// Maimoona Aziz #67070503473
// Write a C program to implement the Insertion Sort algorithm and trace the sorting process.

#include <stdio.h>

void insertionSort(int arr[], int n);

int main(void){
    int len; scanf("%d", &len);
    int arr[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, len);
    printf("--Sorted array--\n");
    for (int k = 0; k < len; k++){
        printf("%d ", arr[k]);
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        printf("--%d Pass--\n", i);
        int index = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > index){
            arr[j+1] = arr[j];
            j--;
        }
        printf("%d Pass to index %d\n", index, j+1);
        arr[j+1] = index;

        for (int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

/*
9 5 1 4 3
5 9 1 4 3
1 5 9 4 3
1 4 5 9 3
1 3 4 5 9
*/