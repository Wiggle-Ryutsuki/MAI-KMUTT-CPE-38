// Maimoona Aziz #67070503473

#include <stdio.h>

int printTriangle(int rows, int num);

int main(void) {
    int tri, rows;
    scanf("%d", &tri);
    
    int num = 1;
    while (tri != 0){
        scanf("%d", &rows);
        num = printTriangle(rows, num);
        tri--;
    }
    return 0;
}

int printTriangle(int rows, int num){
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num); 
            num++;
        }
        printf("\n");
    }
    return num;
}