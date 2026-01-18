// Maimoona Aziz #67070503473

#include <stdio.h>

int ft_strlen(char *a);

int main(void){
    // Get input
    char input[100]; scanf("%s", input);

    // Count number of characters
    int length = ft_strlen(input);

    // Output
    printf("%d", length);
}

// Function to count number of characters in a string
int ft_strlen(char *a){
    int length = 0;
    int i = 0;
    while (a[i] != '\0'){
        length++;
        i++;
    }
    return length;
}