// Take an n x n matrix as input and calculate the sum of its diagonal elements. Print the sum.

#include <stdio.h>

int main (void){
    int row, col; printf("Input row size of the matrix: ");scanf("%d", &row);printf("Input column size of the matrix: ");scanf("%d", &col);
     // Input matrix 1
    int mat[row][col];
    printf("Input numbers into the matrix: \n");
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Calculate diagonal multiplication
    int resultl = 1;
    int resultr = 1;
    for (int i = 0; i < row; i++){
        resultl *= mat[i][i];
        resultr *= mat[i][row - i - 1];
    }

        // Print Matrix 1
    printf("Result: %d\n", resultl);
    printf("Result: %d\n", resultr);
}