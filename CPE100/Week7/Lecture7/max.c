#include <stdio.h>

int max(int a, int b, int c){
    if (a > b){
        if (a > c){
            return a;
        } else {
            return c;
        }
    } else {
        if (b > c){
            return b;
        } else {
            return c;
        }
    }
}

int main(void) {
    int x = 10, y = 20, z = 100;
    printf("The maximum of 3 variables is %d", max(x, y, z));
    puts("");
}
