// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int choice;
    float balance = 0.00, money = 0.00;

    while (1){
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Balance: %.2f Baht\n", balance);
                break;
            case 2:
                scanf("%f", &money);
                if (money < 0){
                    printf("Invalid deposit amount!\n");
                    break;
                }

                balance += money;
                printf("Balance: %.2f Baht\n", balance);
                money = 0.00;
                break;
            case 3:
                scanf("%f", &money);
                if (money <= 0){
                    printf("Invalid withdrawal amount!\n");
                    break;
                } else if (money > balance) {
                    printf("Insufficient funds!\n");
                    break;
                }

                balance -= money;
                printf("Balance: %.2f Baht\n", balance);
                money = 0.00;
                break;
            case 4:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
}