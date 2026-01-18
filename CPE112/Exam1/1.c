// Maimoona Aziz #67070503473
// Task: Write a C program that takes a string as input, computes the sum of its ASCII values, and checks whether the result is a palindrome or not.

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void){
    // Get input
    char string[MAX];
    scanf("%s", &string);
    int length = strlen(string);

    // Sum up ASCII of the string
    int sum_string = 0;
    for (int i = 0; i < length; i++){
        sum_string += string[i];
    }
    
    // Reverse the sum
    int temp = sum_string;
    int sum_reverse = 0;
    int remain;
    while (temp != 0){
        
        remain = temp % 10;
        sum_reverse = sum_reverse * 10 + remain;

        temp /= 10;
    }

    

    
    
}
 