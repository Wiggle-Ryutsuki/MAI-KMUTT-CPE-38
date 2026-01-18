// Maimoona Aziz
// 67070503473

#include <stdio.h>
#include <string.h>

int main(void){
    char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    char str[100];
    scanf("%s", str);
    
    int num_v = 0, num_c = 0;
    for(int i = 0; i < strlen(str); i++){
        int vow = 0;
        for (int j = 0; j < strlen(vowels); j++){
            if (str[i] == vowels[j]){
                vow++;
                num_v++;
            }
        }
        if (vow == 0){
            num_c++;
        }
    }

    printf("Vowels: %d\n", num_v);
    printf("Consonants: %d\n", num_c);
}