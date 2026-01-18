// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    // Step 1: get input
    int ITEM;
    float FUND;

    // Get Item input, check if it is 1, 2, or 3
    scanf("%d", &ITEM);
    if(3 < ITEM || ITEM < 1){
        printf("Invalid choice!");
        return 0;
    }
    // Get Item input, check if it is 1, 2, or 3
    scanf("%f", &FUND);

    if(ITEM == 1 && FUND >= 7){
        FUND = FUND - 7;
        printf("Dispensing your drink: Water\n");

        if(FUND == 0){
            printf("No change");
            return 1;
        }
        printf("Here is your change: %.2f\n", FUND);
        return 1;

    } else if(ITEM == 2 && FUND >= 13){
        FUND = FUND - 13;
        
        printf("Dispensing your drink: Soda\n");
        if(FUND == 0){
            printf("No change");
            return 1;
        }
        printf("Here is your change: %.2f\n", FUND);
        return 1;

    }else if(ITEM == 3 && FUND >= 20){
        FUND = FUND - 20;
        
        printf("Dispensing your drink: Juice\n");
        if(FUND == 0){
            printf("No change");
            return 1;
        }
        printf("Here is your change: %.2f\n", FUND);
        return 1;
    }
    printf("Insufficient funds\n");
}