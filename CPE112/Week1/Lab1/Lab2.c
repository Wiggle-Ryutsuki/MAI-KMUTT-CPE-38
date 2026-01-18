// Create a program that converts a given decimal number into its hexadecimal equivalent.
// Maimoona Aziz # 67070503473

#include <stdio.h>

int main(void){
    // Get input
    int decimal;
    scanf("%d", &decimal);
    if (decimal < 0) {
        return 1;
    }

    if (decimal == 0){
        printf("0");
        return 0;
    }

    int remain, output = 0, place = 1;

    // Calculate remainder and attach to output variable
    while (decimal > 0) {
        remain = decimal % 16;
        output = output * 16 + remain;
        decimal /= 16;
    }

    // Print
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