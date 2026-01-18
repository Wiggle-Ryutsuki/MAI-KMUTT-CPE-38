//Maimoona Aziz 
//67070503473

#include <stdio.h>

int main(void){
    // Step 1 get input for salary, tax rate, and performance rate
    float grossSalary;
    float tax;
    int performance;

    scanf("%f", &grossSalary);
    // Check if Salary is positive
    if(grossSalary < 0){
        printf("Gross salary must be positive\n");
        return 0;
    }

    scanf("%f", &tax);
     // Check if Tax rate is positive
    if(tax < 0){
        printf("Tax rate out of range\n");
        return 0;
    }
    
    scanf("%d", &performance);
    // Check if performance range is in range
    if(5 < performance || performance < 0){
        printf("Performance rating out of range\n");
        return 0;
    }

    // Step 2 Calculate salary with tax and bonus
    float taxAmount;
    float bonusAmount;
    taxAmount = (tax/100) * grossSalary;
    float bonus;
    if (performance == 5){
        bonusAmount = 0.2 * grossSalary;
        grossSalary = grossSalary - taxAmount + bonusAmount;
    } else if (performance == 4){
        bonusAmount = 0.1 * grossSalary;
        grossSalary = grossSalary - taxAmount + bonusAmount;
    } else if (performance == 3) {
        bonusAmount = 0.05 * grossSalary;
        grossSalary = grossSalary - taxAmount + bonusAmount;
    } else if (performance <= 2){
        grossSalary = grossSalary - taxAmount;
    }

    printf("%.2f", grossSalary);
}