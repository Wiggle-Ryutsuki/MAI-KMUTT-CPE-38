#include <stdio.h>
#define MAX 10

int main(void){
    int num[MAX];
    for (int i = 0; i < MAX; i++){
        num[i] = MAX - i;
    }
}