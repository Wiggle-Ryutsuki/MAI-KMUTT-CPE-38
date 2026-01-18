// Create a void function that sorts array in accessing order.
// Maimoona Aziz # 67070503473

#include <stdio.h>

void sortAscending(int arr[], int size);

int main(void){
    int a = 10;
    int *ptr = &a;

    if (ptr == a){
        printf("true");
    } else {
        printf("false");
    }
}