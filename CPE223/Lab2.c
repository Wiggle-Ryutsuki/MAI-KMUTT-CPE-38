// Chanya Tinnaphopworachot 67070503456
// Maimoona Aziz            67070503473
// Iris French              67070503478


// calculates the 44th Fibonacci number without using any special library. 
#include <stdio.h>

int main(void){
    int n = 44;

    long long current;
    long long prev1 = 0;
    long long prev2 = 1;

    for (int i = 2; i <= n; i++){
        current = prev1 + prev2;
        prev2 = prev 1;
        prev1 = current;
    }

    printf("44th Fibonacci: %lld\n", current);
}