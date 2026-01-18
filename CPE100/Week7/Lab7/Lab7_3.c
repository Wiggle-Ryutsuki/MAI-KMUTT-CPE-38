// Maimoona Aziz #67070503473

#include <stdio.h>

float UserInput(float n);
float CalculateAverage(float sum, float n);
void DisplayAverageAndGradeClassification(float average);

int main(void) {
    float n, sum, average;
    scanf("%f", &n);

    sum = UserInput(n);
    average = CalculateAverage(sum, n);
    DisplayAverageAndGradeClassification(average);

}


float UserInput(float n){
    float b;
    float sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%f", &b);
        if (b < 0){
            return 0;
        }
        sum += b;
    }
    return sum;
}
    

float CalculateAverage(float sum, float n){
    float average = sum / n;
    return average;
}


void DisplayAverageAndGradeClassification(float average){
    printf("%.2f\n", average);

    if (average >= 90) {
        printf("A\n");
    } else if (average >= 80) {
        printf("B\n");
    } else if (average >= 70) {
        printf("C\n");
    } else if (average >= 60) {
        printf("D\n");
    } else {
        printf("F\n");
    }
}