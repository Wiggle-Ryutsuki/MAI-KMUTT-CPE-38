//Create a program that outputs the numeric triangle according to the size given by the input.
// Maimoona Aziz # 67070503473

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int num = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}