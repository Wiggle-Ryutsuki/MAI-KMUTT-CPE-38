// Write a program to determine whether the entered character is a vowel or not
// Maimoona Aziz #67070503473

#include <stdio.h>

int main(void){
    char input;
    printf("Please enter a character: ");scanf("%c", &input);

    switch (input){
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            printf("Is a vowel\n");
            break;
        default:
            printf("Not a vowel\n");
    }
}