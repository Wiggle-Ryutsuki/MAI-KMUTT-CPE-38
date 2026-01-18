#include <stdio.h>

int main(void){
    int n; scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }

    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }

}