// Maimoona Aziz #67070503473
// Create a C program to compute the mean, standard deviation, and mode of student scores.
#include <stdio.h>
#include <math.h>

int main (void){
    // Get student score
    int n;scanf("%d", &n);
    int scores[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &scores[i]);
    }

    // Student score much be in range 0 - 100
    int m = n;
    for (int i = 0; i < n; i++){
        if (scores[i] < 0 || scores[i] > 100){
            scores[i] = -1;
            m--;
        }
    }
    int freq[m];
    int nscore[m];
    for (int i = 0; i < n; i++){
        if (scores[i] != -1){
            nscore[i] = scores[i];
            freq[i] = -1;
        }

    }

    // Calculate Mean (Average)
    float mean = 0; 
    // Sum of all scores
    for (int i = 0; i < m; i++){
        mean += nscore[i];
    }
    mean = mean/m; // Divide sum by number of scores

    printf("%.2f\n", mean);

    // Calculate Standard Deviation
    double s = 0;
    for (int i = 0; i < m; i++){
        s += pow((nscore[i] - mean), 2);
    }
    s = s/(m-1);
    s = sqrt(s);
    if (s < 0){
        printf("No valid score.\n");
        return 0;
    }
    printf("%.2lf\n", s);


    // Calculate Mode (Most frequent)
    for (int i = 0; i < m; i++){
        int count = 1;
        for (int j = i + 1; j < m; j++){
            if (nscore[i] == nscore[j]){
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0){
            freq[i] = count;
        }
    }

    int min = nscore[0];
    for (int i = 0; i < m; i++){
        for (int j = i + 1; j < m; j++){
            if (freq != 0){
                if (freq[i] == freq [j]){
                    if (nscore[i] > nscore[j]){
                        min = nscore[j];
                    } else {
                        min = nscore[i];
                    }
                } else {
                    continue;
                }
            }
        }

    }

    printf("%d\n", min);
}