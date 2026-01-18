// Find Minimum and Maximum

 #include <stdio.h>

 int main(void){
    int n; printf("Input length of array: ");scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
        if (min > arr[i]){
            min = arr[i];
        }
    }

    printf("Max: %d\nMin: %d\n", max, min);
 }