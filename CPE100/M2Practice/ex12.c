// Write a program in C for adding two matrices of the same size.

 #include <stdio.h>

 int main(void){
    int m; printf("Input the size of M: "); scanf("%d", &m);
    int n; printf("Input the size of N: "); scanf("%d", &n);
    int array1[m][n], array2[m][n], arraySum[m][n];

    // Input values into arrays
    printf("Input elements in the first matrix :\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    } puts("");
    printf("Input elements in the second matrix :\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    // Sum matrix
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            arraySum[i][j] = array1[i][j] + array2[i][j];
        }
    }

    // Output sum matrix
    puts("");
    printf("Matrix 1:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", array1[i][j]);
        }
        puts("");
    }
    puts("");
    printf("Matrix 2:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", array2[i][j]);
        }
        puts("");
    }

    puts("");
    printf("Summed Matrix:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arraySum[i][j]);
        }
        puts("");
    }
 }