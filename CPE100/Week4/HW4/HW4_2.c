// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    if (num <= 0) {
        printf("The input is invalid\n");
        return 0;
    }

    // print spaces
    for (int i = num; i >= 1; i -= 2){
        for (int j = 1; j < (num - i); j += 2){
            printf(" ");
        }
        for (int k = 1; k <= i; k++){
            printf("*");
        }

        printf("\n");
    }

    int h;
    if (num % 2 == 1){
        h = 3;
    } else {
        h = 2;
    }
    for (int i = h; i <= num; i += 2){
        for (int j = 1; j < (num - i); j += 2){
            printf(" ");
        }
        for (int k = 1; k <= i; k++){
            printf("*");
        }

        printf("\n");
    }
}