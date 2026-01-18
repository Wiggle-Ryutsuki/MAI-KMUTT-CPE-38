// Maimoona Aziz #67070503473

#include <stdio.h>

int GCD(int num1, int num2);

int main(void){
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    int result = GCD(num1, num2);

    printf("The GCD of %d and %d is %d", num1, num2, result);
}

int GCD(int num1, int num2){
    while (num2 != 0){
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return num1;
}