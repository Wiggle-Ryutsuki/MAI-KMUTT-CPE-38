// Maimoona Aziz
// 67070503473

#include <stdio.h>
int main(void){
    int len;
    scanf("%d", &len);
    if (len < 0){
        printf("Invalid Input\n");
        return 0;
    }

    int array[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &array[i]);
    }

    printf("Array: ");
    for (int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    
    puts("");

    printf("Reversed Array: ");
    for (int i = len - 1; i >= 0; i--){
        printf("%d ", array[i]);
    }
}