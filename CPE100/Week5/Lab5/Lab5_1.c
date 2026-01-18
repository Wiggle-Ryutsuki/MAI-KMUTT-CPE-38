// Maimoona Aziz
// 67070503473

#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c, squa_a, squa_b, squa_c, root_a, root_b, root_c;
    scanf("%lf %lf %lf", &a, &b, &c);

    squa_a = pow(a, 2);
    squa_b = pow(b, 2);
    squa_c = pow(c, 2);
    printf("Square: a = %.2lf, b = %.2lf, c = %.2lf\n", squa_a, squa_b, squa_c);

    root_a = sqrt(a);
    root_b = sqrt(b);
    root_c = sqrt(c);
    printf("Square root: a = %.2lf, b = %.2lf, c = %.2lf\n", root_a, root_b, root_c);
}