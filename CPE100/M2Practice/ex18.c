// Take two 2D arrays (matrices) of the same dimensions as input and create a third matrix that holds their sum. Print the result.

 #include <stdio.h>

 int main(void){
    int n; printf("Input size of matrix: ");scanf("%d", &n);
     
    int mat1[n][n];
    printf("Input numbers into the first matrix: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    int mat2[n][n]; 
    printf("Input numbers into the second matrix: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    int sum[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", mat1[i][j]);
        }
        puts("");
    }   
    puts("");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", mat2[i][j]);
        }
        puts("");
    }
    puts("");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", sum[i][j]);
        }
        puts("");
    }
 }