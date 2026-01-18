// Write a program that multiplies two matrices if the dimensions are compatible for multiplication. Print the resulting matrix.

 #include <stdio.h>

 int main(void){
    // Get rows and columns
    int row1, col1; printf("Input row size of the first matrix: ");scanf("%d", &row1);printf("Input column size of the first matrix: ");scanf("%d", &col1);
    int row2, col2; printf("Input row size of the second matrix: ");scanf("%d", &row2);printf("Input column size of the second matrix: ");scanf("%d", &col2);

    if (col1 != row2){
        printf("Column of first matrix must equal to Row of second matrix");
        return 1;
    }
     // Input matrix 1
    int mat1[row1][col1];
    printf("Input numbers into the first matrix: \n");
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col1; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    // Input matrix 2
    int mat2[row2][col2]; 
    printf("Input numbers into the second matrix: \n");
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < col2; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    // Calculate
    int pro[row1][col2];
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++){
            pro[i][j] = 0;
            for (int k = 0; k < col1; k++){
                pro[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Print Matrix 1
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col1; j++){
            printf("%3d", mat1[i][j]);
        }
        puts("");
    }   
    // Print Matrix 2
    puts("");
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < col2; j++){
            printf("%3d", mat2[i][j]);
        }
        puts("");
    }
    // Print Product
    puts("");
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < col2; j++){
            printf("%3d", pro[i][j]);
        }
        puts("");
    }
 }