// Maimoona Aziz
// 67070503473

#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c, result1, result2, difference;
    scanf("%lf %lf %lf", &a, &b, &c);

    result1 = (pow(a, b) + c) / (log10(a) + log(c));
    printf("Result1 = %.2lf\n", result1);

    result2 = pow((sqrt(a) + sqrt(b)), 2) / log(c);
    printf("Result2 = %.2lf\n", result2);

    difference = result1 - result2;
    printf("Difference between result1 and result2 = %.2lf\n", difference);

    if ( difference > 0){
        printf("Positive\n");
    } else if (difference < 0){
        printf("Negative\n");
    } else {
       printf("Zero\n");
    }
}