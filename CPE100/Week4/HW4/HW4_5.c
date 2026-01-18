// Maimoona Aziz
// 67070503473

#include <stdio.h>

int main(void){
    int start, end, breakNum, skipNum,p = 0;
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &breakNum);
    scanf("%d", &skipNum);

    for (int i = start; i <= end; i++){
        if (i > breakNum){
            break;
        } else if (i % skipNum == 0){
            continue;
        } else if (i < 0){
            printf("%d ", i);
            p++;
        } else if (i == 1){
            printf("%d ", i);
            p++;
            continue;
        }
        for (int j = 2; j < i; j++){
            if(i % j == 0){
                printf("%d ", i);
                p++;
                break;
            } else {
                continue;
            }
        }
    }
    if(p == 0){
        printf("No Integer\n");
    }
}