//Maimoona Aziz 
//67070503473

#include <stdio.h>

int main(void){
    // step 1 get input
    int num;
    scanf("%d", &num);

    // step 2 if number is more than 10 and less than 100
    if(10 <= num){
        if(num <= 100){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No\n");
    }
}