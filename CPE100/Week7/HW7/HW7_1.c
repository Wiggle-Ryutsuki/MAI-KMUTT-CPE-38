// Maimoona Aziz #67070503473

#include <stdio.h>

int countDigits(int num);
int power(int a, int b);
int checkArmstrong(int num);

int main(void){
    int num;
    scanf("%d", &num);
    if (num < 0){
        printf("Armstrong Number cannot be negative\n");
        return 0;
    }

    if (checkArmstrong(num, digits)){
        printf("%d is an Armstrong number", num);
    } else {
        printf("%d is not an Armstrong number", num);
    }
}

// Function to count digits
int countDigits(int num){
    int digits = 0;
    while (num != 0){
        digits++;
        num /= 10;
    }
    return digits;
}

// Homemade pow function
int power(int a, int b){
    int c = 1;
    for (int i = 0; i < b; i++){
        c *= a;
    }
    return c;
}

// Functions to check if it is Armstrong Number
int checkArmstrong(int num){
    int tempNum = num;
    int digits = countDigits(num);
    int sum = 0;

    while (tempNum != 0){
        int digit = tempNum % 10;
        sum += power(digit, digits);
        tempNum /= 10;
    }

    return (sum == num);
}
