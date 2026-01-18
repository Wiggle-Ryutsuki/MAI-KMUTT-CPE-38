// Maimoona Aziz #67070503473
// Write a C program to multiply two 2D matrices and compute the transpose of the resultant matrix.

#include <stdio.h>

int main(void){
    int r1; scanf("%d", &r1); // Row of first matrix
    int c1; scanf("%d", &c1); // Column if first matrix
    int array1[r1][c1];

    // Input values into first matrix
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            scanf("%d", &array1[i][j]);
        }
    }

    int r2; scanf("%d", &r2); // Row of second matrix
    int c2; scanf("%d", &c2); // Column of second matrix
    int array2[r2][c2];

    // Input values into second matrix
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            scanf("%d", &array2[i][j]);
        }
    }

    int arrayProduct[r1][c2];

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrices cannot be multiplied\n");
        return 1;
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) { // Row of first matrix
        for (int j = 0; j < c2; j++) { // Column of second matrix
            int product = 0;
            for (int k = 0; k < c1; k++)
                product = product + array1[i][k] * array2[k][j];
            arrayProduct[i][j] = product;
        }
    }

    // Transpose matrix
    int tranProduct[r1][c2];
    for (int i = 0; i < r1; i++) { // Row of first matrix
        for (int j = 0; j < c2; j++) { // Column of second matrix
            tranProduct[i][j] = arrayProduct[j][i];
        }
    }

    // Output transposed product matrix
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            printf("%d ", tranProduct[i][j]);
        }
        puts("");
    }
}