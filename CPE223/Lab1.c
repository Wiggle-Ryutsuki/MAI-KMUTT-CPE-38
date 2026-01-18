// Chanya Tinnaphopworachot 67070503456
// Maimoona Aziz            67070503473
// Iris French              67070503478

#include <stdio.h>

void signAndMagnitude(long long number, int bits, long long max, int isNegative);
void onesComplement(long long number, int bits, long long max, int isNegative);
void twosComplement(long long number, int bits, long long min, long long max);

int main (void){
    int bits;
    long long min, max, number;
    char input[100]; // Get input as string (In case of "-0")
    int isNegative = 0;

    // Input the desired number of bits between 1 and 32 inclusively.
    printf("Enter the number of bits between 1 and 32: "); scanf("%i", &bits);

    // Validate
    if (bits < 1 || bits > 32){
        printf("Invalid number of bits.\n");
        return 0;
    }

    // Calculate minimum and maximum || max = 2^(n-1) - 1 || min = -(2^(n-1))
    min = -(1LL << (bits - 1));
    max = (1LL << (bits - 1)) - 1;

    // Input decimal between min and max as a string
    printf("Enter a number between %lld and %lld: ", min, max); scanf("%s", input);

    // check if first character is "-"
    if (input[0] == '-'){
        isNegative = 1;
    }

    // Convert string input to number
    sscanf(input, "%lld", &number);

    // Validate
    if (number < min || number > max){
        printf("Invalid value.\n");
        return 0;
    }

    // Print Results
    signAndMagnitude(number, bits, max, isNegative);
    onesComplement(number, bits, max, isNegative);
    twosComplement(number, bits, min, max);
}


void signAndMagnitude(long long number, int bits, long long max, int isNegative){
    int binary[bits]; //array to store the results//
    long long numCopy = number;

    //initialize array to store binary number//
    for (int i = 0; i < bits; i++){
        binary[i] = 0;
    }

    //checks if its a negative number//
    if (isNegative){
        number *= -1;
        binary[0] = isNegative;
    }

    //converts the number to a binary number//
    for (int i = bits-1; i > 0; i--){
        binary[i] = number & 1;
        number >>= 1;
    }

    if (number != 0) {
        // If number is not 0, that means there is not enough bits.//
        printf("The sign-magnitude doesn't represent %lld.\n", numCopy);

    } else {
        //prints the results//
        printf("Sign-Magnitude: ");
        for (int i = 0; i < bits ; i++){
            printf("%d",binary[i]);
        } printf("\n");
    }
}


void onesComplement(long long number, int bits, long long max, int isNegative){
    unsigned long long result;

    // Check if it can be represented
    if (number < -max || number > max){
        printf("1's complement doesn't represent %lld\n", number);
        return;
    }

    if (!isNegative) {
        // Positive
        result = (unsigned long long)number;
    } else {
        // Negative
        result = ~(unsigned long long)(-number);
    }

    result &= (1ULL << bits) - 1;

    printf("1's Complement: ");
    for (int i = bits-1; i >= 0; i--) {
        printf("%d", (int)((result >> i) & 1));

    }
    printf("\n");
}


void twosComplement(long long number, int bits, long long min, long long max){
    unsigned int result; // Can change this

    if (number < min || number > max){
        printf("2's compliment cannot represent %lld", number);
        return;
    }

    /* Code here
        ... */

    //printf(result); // Can change this
}
