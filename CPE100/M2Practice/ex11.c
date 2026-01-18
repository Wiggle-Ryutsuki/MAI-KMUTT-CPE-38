 // Write a program in C for a 2D array of size 3x3 and print the matrix.

 #include <stdio.h>

 int main(void){
    int m; printf("Input the size of M: "); scanf("%d", &m);
    int n; printf("Input the size of N: "); scanf("%d", &n);
    int array[m][n];

    printf("Input elements in the matrix :\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d] [%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", array[i][j]);
        }
        puts("");
    }
 }