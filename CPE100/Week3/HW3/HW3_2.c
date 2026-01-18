// Maimoona Aziz
// 67070503473
#include <stdio.h>

int main(void) {
    // Step 1 get input for price, promotion, and type
    float price;
    int has_promotion;
    int type;

    scanf("%f", &price);
    // Check if price is positive
    if(price < 0){
        printf("Input must be positive\n");
        return 0;
    }

    scanf("%d", &has_promotion);
     // Check if has_promotion is in range
    if(has_promotion != 0 && has_promotion != 1){
        printf("Input invalid\n");
        return 0;
    }
    
    scanf("%d", &type);
    // Check if product type is in range
    if(3 < type || type < 0){
        printf("Type out of range\n");
        return 0;
    }

    float discount;
    float tax;
    if(has_promotion == 1){
        // For electronics and clothing
        if(type == 1 || type == 2){
            if(price >= 5000){
                 // Apply 25% discount
                discount = 0.25 * price;
                price = price - discount;
            } else if (price >= 2000){
                 // Apply 15% discount
                discount = 0.15 * price;
                price = price - discount;
            } else if(price < 2000){
                 // Apply 10% discount
                discount = 0.10 * price;
                price = price - discount;
            }
        } else if(type == 3){ // For general goods
            if(price >= 5000){
                 // Apply 20% discount
                discount = 0.20 * price;
                price = price - discount;
            } else if (price >= 2000){
                 // Apply 10% discount
                discount = 0.10 * price;
                price = price - discount;
            } else if(price < 2000){
                 // Apply 5% discount
                discount = 0.05 * price;
                price = price - discount;
            }
        }
    } else {
        // Apply 7% tax then print
        tax = price * 0.07;
        price = price + tax;
        printf("Net price after discount and tax: %.2f Baht\n", price);
        return 0;
    }
    // Apply 7% tax then print
    tax = price * 0.07;
    price = price + tax;
    printf("Net price after discount and tax: %.2f Baht\n", price);
}
