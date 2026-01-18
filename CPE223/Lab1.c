// Chanya Tinnaphopworachot 67070503456
// Maimoona Aziz            67070503473
// Iris French              67070503478

#include <stdio.h>

void signAndMagnitude(long long number, int bits, long long max);
void onesCompliment(long long number, int bits, long long max);
void twosCompliment(long long number, int bits, long long min, long long max);

int main (void){
    int bits;
    long long min, max, number;

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

    // Input decimal between min and max
    printf("Enter a number between %lld and %lld: ", min, max); scanf("%lld", &number);

    // Validate
    if (number < min || number > max){
        printf("Invalid value.\n");
        return 0;
    }

    // Print Results
    //signAndMagnitude(number, bits, max);
    onesCompliment(number, bits, max);
    //twosCompliment(number, bits, min, max);
}


void signAndMagnitude(long long number, int bits, long long max){
    //unsigned int result; // Can change this

    /* Code here
        ... */

    //printf(result);
}


void onesCompliment(long long number, int bits, long long max){
    unsigned long long result;

    if (number < -max || number > max){
        printf("1's complement cannot represent %lld\n", number);
        return;
    }

    if (number >= 0) {
        result = (unsigned long long)number;
    } else {

        result = ~(unsigned long long)(-number);
    }

    result &= (1ULL << bits) - 1;


    printf("1's complement: ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (int)((result >> i) & 1));

    }
    printf("\n");
}


void twosCompliment(long long number, int bits, long long min, long long max){
    unsigned int result; // Can change this

    if (number < min || number > max){
        printf("2's compliment cannot represent %lld", number);
        return;
    }

    /* Code here
        ... */

    //printf(result); // Can change this
}
