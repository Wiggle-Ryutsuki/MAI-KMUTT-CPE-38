// Maimoona Aziz
// 67070503473
#include <stdio.h>

int main(void) {
    int num, pos, digits = 0, place = 1, remain;
    scanf("%d", &num);
    scanf("%d", &pos);

    // Count digits
    int temp = num;
    while (temp > 0){
        temp /= 10;
        digits ++;
    }

    // Adjust digits
    if (pos >= digits){
        pos %= digits;
    }

    if (pos == 0){
        printf("%d", num);
        return 0;
    }

    // Calculate power to move last digit to the front
    for (int i = 0; i < digits; i++) {
        place *= 10;
    }

    // Shift digits
    for (int j = 0; j < pos; j++){
        remain = num % 10;
        num = num + remain * place;
        num /= 10;
    }
    printf("%d\n", num);
}