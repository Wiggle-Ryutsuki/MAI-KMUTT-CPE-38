//Maimoona Aziz 67070503473
#include <stdio.h>

int main(void)
{
    double PI = 3.14159265358979323846;
    float radius, area;
    scanf("%f", &radius);

    area = PI * radius * radius;
    printf("%.3f", area);
}