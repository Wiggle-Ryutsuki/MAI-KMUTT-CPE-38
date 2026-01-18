// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int num, character;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++){
        for (int j = 0; j < i; j++){
            character = 'a' + j + i - 1;
            printf("%c ", character);  
        }
        printf("\n");
    }
}