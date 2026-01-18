#include <stdio.h>

int square();

int main(void){
    for (int x = 1; x <= 10; x ++){
        printf("%5d", square(x));
    }
    puts("");
}

int square(int y) {
    return (y * y);
}