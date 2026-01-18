// Maimoona Aziz #67070503473

#include <stdio.h>

int main(void){
    // Get input
    char input[1000] = "";
    scanf("%s", input);

    // Loop through length of input
    int i = 0;
    int j = 0;
    char compressed[2000]; // Variable to hold compressed string
    while (input[i] != '\0'){
        char currentChar = input[i];
        int count = 1;

        // Append character
        compressed[j] = currentChar;
        j++;
        
        // Check if i == i + 1 then increment count
        while (input[i] == input[i + 1]){
            count++;
            i++;
        }
        // Append count to new string
        j += sprintf(&compressed[j], "%d", count); // Function in stdio.h that writes a formatted string into a char array.
        i++;
    }
    compressed[j] = '\0';

    // Find lengths
    int in = 0;
    int inputLen = 0;
    while (input[in] != '\0'){
        inputLen++;
        in++;
    }
    int com = 0;
    int comLen = 0;
    while (compressed[com] != '\0'){
        comLen++;
        com++;
    }

    // If length of compressed is the same as original, just print original, else print compressed
    if (comLen >= inputLen){
        printf("%s\n", input);
    } else {
        printf("%s\n", compressed);
    }
}