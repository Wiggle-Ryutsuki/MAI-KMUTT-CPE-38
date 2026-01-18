// Maimoona Aziz
// 67070503473

#include <stdio.h>
int main(void){
    int num, temp, digit, reverse = 0;
    scanf("%d", &num);

    if (num < 0){
        printf("Negative value is not considered a palindrome.");
        return 0;
    }

    temp = num;
    while (temp > 0){
        digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp /= 10;
    }

    if(num == reverse){
        printf("%d is a palindrome.", num);
    } else {
        printf("%d is not a palindrome.", num);
    }
}