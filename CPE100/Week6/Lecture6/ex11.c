#include <stdio.h>
#include <string.h>

int main(void){
    char str[30];
    int len = 0;
    
    scanf("%[^\n]s", str);
    printf("%s\n", str);

    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }
    printf("Length: %d\n", len);
}