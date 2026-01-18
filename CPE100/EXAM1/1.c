// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int num, sum, print;
    scanf("%d", &num);
    if (num < 0){
        return 0;
    }
    for (int i = 1; i <= num; i++){
        sum = 0;
        for (int j = 1; j < i; j++){
            if (i == j){
                continue;
            } else if (i % j == 0){
                sum += j;
            }
        }
        if (sum == i){
            printf("%d\n", sum);
            print++;
        }
    }
    if (print == 0){
        printf("No perfect number.\n");
    }
}