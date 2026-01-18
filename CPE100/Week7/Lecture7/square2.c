#include <stdio.h>

int f();
int g();

int main(void){
    for (int x = 1; x <= 10; x ++){
        printf("%5d", f(x));
    }
    puts("");
}

int f(int y) {
    return (g(y, y+1));
}

int g(int a, int b){
     return(a * a * b * b *b);
}