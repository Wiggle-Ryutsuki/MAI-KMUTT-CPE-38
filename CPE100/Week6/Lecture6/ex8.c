#include <stdio.h>
#define MAX 10

int main(void){
    int num1[MAX], num2[MAX];
    
    for (int i = 0; i < MAX; i++){
        num1[i] = i + 1;
        printf("%d ", num1[i]);
    }
    
    puts("");
    
    for (int i = 0; i < MAX; i++){
        num2[i] = num1[MAX - i - 1];
        printf("%d ", num2[i]);
    }
}