// Maimoona Aziz
// 67070503473
#include <stdio.h>

int main(void) {
    long n, m, a = 0, b = 1, c = 0, isFibo = 0;
    scanf("%ld %ld", &n, &m);

    while (c <= m){
        c = a + b;
        if (c >= n && c <= m && c > 1){
            long j;
            long i;
            for (i = 2; i * i <= c; i++) {
                if (c % i == 0){
                    break;
                }
            }
            if (i * i > c){
                printf("%ld\n", c);
                isFibo++;
            }
        }
        a = b;
        b = c; 
    }

    if (isFibo == 0){
        printf("No Output\n");
    }
}
