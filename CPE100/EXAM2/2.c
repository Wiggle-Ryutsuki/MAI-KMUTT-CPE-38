// Maimoona Aziz #67070503473
// Write a C program to identify saddle points in a matrix, based on the user's input for the matrix size and values.

#include <stdio.h>

int main (void){
    int row; int col; scanf("%d %d", &row, &col);
    int mat[row][col];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d   ", mat[i][j]);
        }
        puts("");
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int min = mat[i][j];
            for (int k = j + 1; k < col - 1; k++){
                printf("Checking [%d][%d] and [%d][%d], matrix = %d vs %d\n", i, j, i, k, mat[i][j], mat[i][k]);
                if (mat[i][j] > mat[i][k]){
                    min = mat[i][k];
                } else {
                    continue;
                }
                printf("min = %d\n", min);
            }
            
        }
    
        return 0;
    }  
} 