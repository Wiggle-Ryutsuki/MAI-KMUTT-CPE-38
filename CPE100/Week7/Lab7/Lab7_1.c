// Maimoona Aziz #67070503473

#include <stdio.h>

int sum();

int main(void) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("%d\n", sum(x, y));
}

// Main function that calculates summation
int sum(int a, int b){
    int sum = 0;
    for (int i = a; i <= b; i++){
        sum += i;
    }

    return sum;
}
