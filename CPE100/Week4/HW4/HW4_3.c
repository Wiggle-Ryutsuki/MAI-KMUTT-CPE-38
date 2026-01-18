// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int start, end, sum = 0;
    scanf("%d", &start);
    scanf("%d", &end);

    for (int i = start; i <= end; i++){
        int j;
        if (i <= 1) {
            continue;
        }

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                break;
            }
        }

        if ((j * j) > i) {
            int temp = i;
            while (temp > 0) {
                if (temp % 10 == 3){
                    break;
                }
                temp /= 10;
            }
            if (temp == 0){
                sum += i;
            }
        }
    }
    printf("%d\n", sum);
}