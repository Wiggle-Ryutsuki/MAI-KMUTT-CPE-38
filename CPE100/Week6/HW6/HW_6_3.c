// Maimoona Aziz
// 67070503473

#include <stdio.h>
#include <string.h>

int main(void){
    char str1[1000];
    char str2[1000];
    char newStr1[1000];
    char newStr2[1000];
    int freq1[26] = {0};
    int freq2[26] = {0};

    scanf("\n%[^\n]s", str1);
    scanf("\n%[^\n]s", str2);

    int i = 0, k = 0;
    while (str1[i] != '\0') {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] + 32;
        }
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            newStr1[k++] = str1[i];
        }
        i++;
    }

    int j = 0, l = 0;
    while (str2[j] != '\0') {
        if (str2[j] >= 'A' && str2[j] <= 'Z') {
            str2[j] = str2[j] + 32;
        }
        if (str2[j] >= 'a' && str2[j] <= 'z') {
            newStr2[l++] = str2[j];
        }
        j++;
    }

    for (int m = 0; m < k; m++) {
        freq1[newStr1[m] - 'a']++;
    }

    for (int n = 0; n < l; n++) {
        freq2[newStr2[n] - 'a']++; 
    }

    int isAnagram = 1;
    for (int i = 0; i < 26; i++){
        if (freq1[i] != freq2[i]){
            isAnagram = 0;
            break;
        }
    }

    if (!isAnagram){
        printf("The strings are not anagrams");
    } else {
        printf("The strings are anagrams");
    }
}