// Quick sort algorithm

#include <stdio.h>

void swap (int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort (int arr[], int low, int high, int n);

int main(void){
    int n; printf("Enter size of array: ");scanf("%i", &n);
    int arr[n];
    printf("Enter numbers: \n");
    for (int i = 0; i < n; i++){
        printf("Index[%i]: ", i);
        scanf("%i", &arr[i]);
    }

    quickSort(arr, 0, n-1, n);

    // Print array
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}

void quickSort (int arr[], int low, int high, int n){
    if (low < high){
        int loc = partition (arr, low, high);

        // Print array
        for (int i = 0; i < n; i++){
            printf("%i ", arr[i]);
        } printf("\n");

        quickSort (arr, low, loc-1, n);
        quickSort (arr, loc+1, high, n);
    }
}

int partition (int arr[], int low, int high){
    int pivot = arr[low];
    int start = low;
    int end = high;

    while (start < end){
        while (arr[start] <= pivot){
            start++;
        }
    
        while (arr[end] > pivot){
            end--;
        }
    
        if (start < end){
            //swap(&arr[start], &arr[end]);
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    //swap(&arr[low], &arr[end]);
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;

    return end;
}

/*void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/