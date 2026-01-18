// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int decimal, convert;
    scanf("%d", &decimal);
    if (decimal < 0) {
        return 0;
    }
    scanf("%d", &convert);

    int divisible, remain, output = 0, place = 1;

    if (convert == 1) {
        divisible = 2;
    } else if (convert == 2) {
        divisible = 8;
    } else if (convert == 3) {
        divisible = 16;
    } else {
        printf("Invalid Choice");
        return 0;
    }
    if (convert == 1 || convert == 2){
        while (decimal > 0) {
            remain = decimal % divisible;
            output = output + remain * place;
            place *= 10;
            decimal /= divisible;
        }
        printf("%d\n", output);
    } else {
        while (decimal > 0) {
            remain = decimal % divisible;
            output = output * 16 + remain;
            decimal /= divisible;
        }
        remain = 0;
        while (output > 0) {
            remain = output % 16;
            if (remain >= 10) {
                printf("%c", remain - 10 + 'A');
            } else {
                printf("%d", remain);
            }
            output /= 16;
        }
    }
}