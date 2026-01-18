// Maimoona Aziz
// 67070503473

#include <stdio.h>
int main(void){
    int n;
    int freq[100] = {0};
    int maxFreq = 0;
    scanf("%d", &n);
    if (n <= 0){
        printf("Array is empty\n");
        return 0;
    }

    int array[n];
    int unique[n];
    int uniqueCount = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++){
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (unique[j] == array[i]) {
                freq[j]++; 
                found = 1;
                break;
            }
        }

        if (!found){
            unique[uniqueCount] = array[i];
            freq[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    for (int i = 0; i < uniqueCount; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int count = 0;
    for (int i = 0; i < uniqueCount; i++){
        if (freq[i] == maxFreq){
            maxFreq = freq[i];
            count++;
        }
    }

    printf("Most frequent value");
    if (count > 1){
        printf("s"); 
    }
    printf(": ", maxFreq);

    for (int i = 0; i < uniqueCount; i++){
        if (freq[i] == maxFreq){
            printf("%d ", unique[i]);
        }
    }
    
    puts("");

    printf("Frequency: %d", maxFreq);
}