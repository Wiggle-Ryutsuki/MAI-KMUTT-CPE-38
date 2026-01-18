// Write a program in C for the multiplication of two square matrices.

 #include <stdio.h>

 int main(void){
    int r1; printf("Input the row of the first matrix: "); scanf("%d", &r1);
    int c1; printf("Input the column of the first matrix: "); scanf("%d", &c1);
    int r2; printf("Input the row of the second matrix: "); scanf("%d", &r2);
    int c2; printf("Input the column of the second matrix: "); scanf("%d", &c2);
    int array1[r1][c1], array2[r2][c2], arrayProduct[r1][c2];

        // Check if multiplication is possible
    if (c1 != r2) {
        printf("Multiplication of matrices is not possible.\n");
        printf("Column of the first matrix and row of the second matrix must be the same.\n");
        return 1;
    }

    // Input values into arrays
    printf("Input elements in the first matrix :\n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    } puts("");
    printf("Input elements in the second matrix :\n");
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) { // Row of first matrix
        for (int j = 0; j < c2; j++) { // Column of second matrix
            int sum = 0;
            for (int k = 0; k < c1; k++)
                sum = sum + array1[i][k] * array2[k][j];
            arrayProduct[i][j] = sum;
        }
    }

    // Output sum matrix
    puts("");
    printf("Matrix 1:\n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            printf("%d ", array1[i][j]);
        }
        puts("");
    }
    puts("");
    printf("Matrix 2:\n");
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            printf("%d ", array2[i][j]);
        }
        puts("");
    }

    puts("");
    printf("Summed Matrix:\n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            printf("%d ", arrayProduct[i][j]);
        }
        puts("");
    }
 }