#include <stdio.h>
#include <string.h>

int main(void){
    char str1[] = "CPE-KMUTT";
    char str2[] = "STRING";
    char str3[]= "CAT";
    char result[30];

    printf("The length of %s is %d.\n", str1, strlen(str1));
    strcpy(result, str2);
    printf("Concatinate %s + %s is %s.\n", str2, str3, strcat(result, str3));

    if(!strcmp(str2, str3)){
        printf("MATCH\n");
    } else {
        printf("NOT MATCH\n");
    }
}