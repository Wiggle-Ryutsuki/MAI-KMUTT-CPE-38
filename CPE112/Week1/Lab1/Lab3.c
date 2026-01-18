// Create a void function that sorts array in accessing order.
// Maimoona Aziz # 67070503473

#include <stdio.h>

void sortAscending(int arr[], int size);

int main(void){
    int n; scanf("%i", &n);
    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%i", &array[i]);
    }

    sortAscending(array, n);
    for (int i = 0; i < n; i++){
        printf("%i ", array[i]);
    }
}

void sortAscending(int arr[], int size)
{
    int a, b, temp;
    for (a = 0; a < size; a++){
        for (b = a+1; b < size; b++){
            if (arr[a] > arr[b]){
                temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
            }
        }
    }
}