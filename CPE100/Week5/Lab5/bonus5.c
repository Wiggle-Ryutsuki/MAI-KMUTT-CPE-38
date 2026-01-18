// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int decimal, remain, binary = 0, place = 1;
    scanf("%d", &decimal);

    if (decimal < 0){
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    while (decimal > 0){
        remain = decimal % 2;
        binary += remain * place;
        place *= 10;
        decimal /= 2;
    }
    printf("%d\n", binary);

    if (binary == 0){
        printf("0\n");
    } else {
        while (binary > 0){
            remain = binary % 10;
            printf("%d", remain);
            binary /= 10;
        }
    }
    
}
