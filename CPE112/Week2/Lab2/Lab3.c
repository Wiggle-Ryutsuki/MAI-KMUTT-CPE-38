// Maimoona Aziz #67070503473
// Create a program that records temperature data over multiple days, cities, and hours. also, Analyse the average temperature for each city in the recorded day and display the highest temperature recorded in the dataset.

#include <stdio.h>

int main(void){
    int days, city, hours; scanf("%d %d %d", &days, &city, &hours);
    float temp[days][city][hours];
    float city_TempSums[city];
    int city_TempCounts[city];
    float maxTemp = 0;

    for (int c = 0; c < city; c++) {
        city_TempSums[c] = 0;
        city_TempCounts[c] = 0;
    }

    // Input temperature
    for (int d = 0; d < days; d++){
        for (int c = 0; c < city; c++){
            for (int h = 0; h < hours; h++){
                scanf("%f", &temp[d][c][h]);
                city_TempSums[c] += temp[d][c][h];
                city_TempCounts[c]++;
                if (temp[d][c][h] > maxTemp){
                    maxTemp = temp[d][c][h];
                }
            }
        }
    }

    // Print report
    for (int d = 0; d < days; d++){
        printf("Day %d:\n", d+1);
        for (int c = 0; c < city; c++){
            printf("City %d: ", c+1);
            for (int h = 0; h < hours; h++){

                printf("%.2f ", temp[d][c][h]);
            }
            puts("");
        }
    }

    // Calculate average temperature
    printf("Average Temperature for Each City:\n");
    for (int c = 0; c < city; c++) {
        float average = city_TempSums[c] / city_TempCounts[c];
        printf("City %d: %.2f\n", c + 1, average);
    }

    // Print maximum temperature
    printf("Maximum Temperature Recorded: %.2f\n", maxTemp);
}