// Maimoona Aziz
// 67070503473

#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    if (n < 0){
        return 0;
    }

    int array[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    int mode;
    scanf("%d", &mode);
    if (mode < 1 || mode > 2){
        return 0;
    }

    if (mode == 1){
        for (int i = 0; i < n; i++){
            if (array[i] == 0){
                for (int j = i; j > 0 && array[j - 1] != 0; j--){
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
    } else if (mode == 2){
        for (int i = 0; i < n; i++){
            if (array[i] != 0){
                for (int j = i; j > 0 && array[j - 1] == 0; j--){
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
        }
    }

    printf("Modified Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}