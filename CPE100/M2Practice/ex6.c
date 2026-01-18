// Write a program in C to count the total number of duplicate elements in an array.

#include <stdio.h>

void countFrequency(int *array, int *freq, int n);

int main(void){
    int n; printf("Input the number of elements to store in the array: "); scanf("%d", &n);
    int array[n]; int freq[n];
    // Get input from user to store in array
    printf("Input %d elements in the array: \n", n);
    for (int i = 0; i < n; i++){
        printf("Element %d: ", i+1); scanf("%d", &array[i]);
        freq[i] = -1;
    }

    countFrequency(array, freq, n);

    for (int i = 0; i < n; i++){
        if (freq[i] != 0){
            printf("%d occurs %d times\n", array[i], freq[i]);
        }
    }
    
}

void countFrequency(int *array, int *freq, int n){
    for (int i = 0; i < n; i++){
        int count = 1;
        for (int j = i + 1; j < n; j++){
            if (array[i] == array[j]){
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0){
            freq[i] = count;
        }
    }
}