#include <stdio.h>
#define MAX 10

int main(void){
    int num1[MAX], num2[MAX + 1];
    
    for (int i = 0; i < MAX; i++){
        num1[i] = i + 1;
        printf("%d ", num1[i]);
    }
    
    puts("");
    
    for (int i = 0; i < MAX; i++){
        num2[i] = num1[MAX - i - 1];
        printf("%d ", num2[i]);
    }
    
    puts("");

    for (int i = MAX; i > 3; i--){
        num2[i] = num2[i - 1]; 
    }
    num2[3] = 100;
    
    for (int i = 0; i < MAX + 1; i++){
        printf("%d ", num2[i]);
    }
    
}