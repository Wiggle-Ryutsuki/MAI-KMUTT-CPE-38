// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    if (n <= 0){
        printf("Invalid input!\n");
        return 0;
    }

    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    int a, b;
    a = array[0];
    b = array[0];
    for (int i = 0; i < n; i++){
        if (a < array[i]){
            a = array[i];
        }
        if (b > array[i]){
            b = array[i];
        }
    }

    printf("Maximum element: %d\n", a);
    printf("Minimum element: %d\n", b);
}