// Maimoona Aziz #67070503473

#include <stdio.h>

int sum();

int main(void) {
    int x, y, z;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    printf("%d\n", sum(x, y, z));
}

// Main function that calculates summation
int sum(int a, int b, int c){
    int sum = 0;
    for (int i = a; i <= b; i++){
        if (i % c == 0){
            sum += i;
        }
    }
    return sum;
}
