// Maimoona Aziz #67070503473
// Thank you Iris for lending me your transcript

#include <stdio.h>
#include <string.h>
void initializeSubjects();
float calculateGPAX(const char* prefix);

#define MAX 105

struct courses{
    int year;
    int term;
    char code[10];
    char subjectName[50];
    double credits;
    float grades;
} subject[MAX];

int main(void){
    initializeSubjects();

    float overallGPA = calculateGPAX("");
    printf("Overall GPAX: %.2f\n", overallGPA);

    float englishGPA = calculateGPAX("ENG");
    printf("English GPAX: %.2f\n", englishGPA);

    float mathGPA = calculateGPAX("MTH");
    printf("Math GPAX: %.2f\n", mathGPA);

    float scienceGPA = calculateGPAX("SCI");
    printf("Science GPAX: %.2f\n", scienceGPA);
}

// Function to read file into array
void initializeSubjects() {
    FILE *file = fopen("transcript.csv", "r");
    if (!file){
        printf("Error: Could not open file.\n");
        return;
    }
    char line[100];
    int i = 0;

    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) && i < MAX){
        sscanf(line, "%d,%d,\"%[^\"]\",\"%[^\"]\",%lf,%f",
               &subject[i].year,
               &subject[i].term,
               subject[i].code,
               subject[i].subjectName,
               &subject[i].credits,
               &subject[i].grades);
        i++;
    }
    fclose(file);
}

// Calculate GPAX
/* Points = grades * credits || GPAX = total points / total credits*/
float calculateGPAX(const char* prefix) {
    float points = 0, credits = 0;

    for (int i = 0; i < MAX; i++) {
        if (subject[i].credits > 0) {  
            // If prefix is provided, check if the subject code starts with that prefix
            if (prefix[0] == '\0' || strncmp(subject[i].code, prefix, strlen(prefix)) == 0) {
                points += subject[i].credits * subject[i].grades;
                credits += subject[i].credits;
            }
        }
    }

    if (credits == 0) {  
        return 0;
    }
    return points / credits;
}