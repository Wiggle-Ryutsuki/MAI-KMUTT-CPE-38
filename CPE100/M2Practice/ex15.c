// Prompt the user for n integer values, store them in a 1D array, and then display the array in reverse order.

 #include <stdio.h>

 int main(void){
    int n; printf("Input length of array: ");scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Original: ");
    for (int i = 0; i < n; i++){
        printf("%2d", arr[i]);
    }
    puts("");

    printf("Reversed: ");
    for (int i = n-1; i >= 0; i--){
        printf("%2d", arr[i]);
    }
    puts("");
 }