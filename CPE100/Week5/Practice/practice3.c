// Maimoona Aziz
// 67070503473
#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
     if (num < 0){
        printf("Invalid input\n");
        return 0;
     }
    for (int i = 1; i <= num; i++){
        for (int j = 1; j <= num - i; j++){
            printf("%2c", ' ');
        }
        for (int k = 1; k <= i; k++){
            printf("%d ", k);
        }
        for (int l = 1; l <= i-1; l++){
            printf("%d ", i - l);
        }
        printf("\n");
    }
}