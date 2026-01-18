// Maimoona Aziz
// 67070503473
#include <stdio.h>

int main(void) {
    // Step 1 get input for score
    float score;

    scanf("%f", &score);
    // Check if score is between 0 and 100
    if(score < 0 || score > 100){
        printf("Invalid score!\n");
        return 0;
    }

    // Step 2 Apply grade
    if(score >= 90){
        printf("A\n");
    } else if(score >= 85){
        printf("B+\n");
    }else if(score >= 80){
        printf("B\n");
    } else if(score >= 75){
            printf("C+\n");
    } else if(score >= 70){
            printf("C\n");
    } else if(score >= 65){
            printf("D+\n");
    } else if(score >= 60){
            printf("D\n");
    } else if(score < 60){
            printf("F\n");
    }
}
