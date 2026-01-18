#include <stdio.h>

int swap();

// Find the summation from x to y
int main(void) {
    int x, y;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    printf("X: %d\nY: %d\n", x, y);

    swap(&x, &y);
    printf("X: %d\nY: %d\n", x, y);
}

int swap(int *a, int *b){
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;

    return (*a, *b);
}
