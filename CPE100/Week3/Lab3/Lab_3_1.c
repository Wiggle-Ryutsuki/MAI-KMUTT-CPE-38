//Maimoona Aziz
//67070503473

#include <stdio.h>

int main(void){
    // step 1 get input
    int num;
    scanf("%d", &num);

    // step 2 calculate with mod, 0 = even 1 = odd
    if(num % 2 == 0){
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}