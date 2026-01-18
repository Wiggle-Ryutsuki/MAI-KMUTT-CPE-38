// Write a program to find the transpose of an n x m matrix entered by the user. Output the transposed matrix.

 #include <stdio.h>

 int main(void){
    int m, n; printf("Input row size of matrix: ");scanf("%d", &m);printf("Input column size of matrix: ");scanf("%d", &n);
     
    int mat[m][n];
    printf("Input numbers into the matrix: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    int trans[n][m]; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            trans[i][j] = mat[j][i];
        }
    }

    puts("");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", mat[i][j]);
        }
        puts("");
    }   
    puts("");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%3d", trans[i][j]);
        }
        puts("");
    }
    puts("");
 }