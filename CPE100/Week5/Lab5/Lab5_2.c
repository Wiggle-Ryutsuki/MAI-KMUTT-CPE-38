// Maimoona Aziz
// 67070503473

#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c, log10_a, log10_b, log10_c, log_a, log_b, log_c;
    scanf("%lf %lf %lf", &a, &b, &c);

    log10_a = log10(a);
    log10_b = log10(b);
    log10_c = log10(c);
    printf("Log10: a = %.2lf, b = %.2lf, c = %.2lf\n", log10_a, log10_b, log10_c);

    log_a = log(a);
    log_b = log(b);
    log_c = log(c);
    printf("Log base e: a = %.2lf, b = %.2lf, c = %.2lf\n", log_a, log_b, log_c);
}