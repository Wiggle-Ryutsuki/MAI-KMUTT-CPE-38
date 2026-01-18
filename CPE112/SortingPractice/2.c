#include <stdio.h>


int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    for (int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }

        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
}