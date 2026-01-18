#include <stdio.h>

int sum();

// Find the summation from x to y
int main(void) {
    int x, y;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    printf("The summation from %d to %d is %d", x, y, sum(x, y));
    puts("");
}

int sum(int a, int b){
    int sum = 0;
    for (int i = a; i <= b; i++){
        sum += i;
    }

    return sum;
}
