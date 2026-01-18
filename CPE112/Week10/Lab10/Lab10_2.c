// Maimoona Aziz #67070503473
// Write a C program to implement a hash table using the division method with linear probing for collision handling.

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct Hash
{
    int key;
    char value[MAX];
    int occupied;
} Hash;

void innitTable(Hash hash[], int max);
int hash(int key, int max);
void insertValue(Hash hashTable[], int key, char value[], int max);
void searchValue(Hash hashTable[], int key, int max);
void printTable(Hash hash[], int max);
void toLowerCase(char str[]);

int main(void){
    // Initialize array to be not occupied
    int max; scanf("%d", &max);
    Hash hashTable[max];
    innitTable(hashTable, max);

    while (1){ 
        // Get command
        int key; 
        int strlength = 50; char value[strlength]; 
        
        char command[MAX]; scanf("%s", &command);
        toLowerCase(command);

        // If INSERT
        if (strcmp(command, "insert") == 0) {
            // Get key
            scanf("%d", &key);
            // Get data
            scanf("%s", &value);
            
            insertValue(hashTable, key, value, max);

        } else if (strcmp(command, "search") == 0) {
            // Get key
            scanf("%d", &key);

            // Search
            searchValue(hashTable, key, max);

        } else if (strcmp(command, "exit") == 0) {
            printTable(hashTable, max);
            break;
        
        } else {
            printf("Invalid Input.\n");
        }
    }
}


// Initialize array
void innitTable(Hash hash[], int max){
    for (int i = 0; i < max; i++){
        hash[i].occupied = 0;
    }
}


// Hash function
int hash(int key, int max){
    return key % max;
}


// Print table
void printTable(Hash hash[], int max){
    int isEmpty = 1; // Table is empty
    printf("Hash Table:\n");
    for (int i = 0; i < max; i++){
        // If it is occupied
        if (hash[i].occupied == 1){
            printf("[%d] Key: %d, String: %s\n", i, hash[i].key, hash[i].value);
            isEmpty = 0; // Has at least one value;
        } else if (hash[i].occupied == 0){
            printf("[%d] ---\n", i, hash[i].key, hash[i].value);
        }
    }

    if (isEmpty != 0){
        printf("Table is empty.\n");
    }
}


// Insert function
void insertValue(Hash hashTable[], int key, char value[], int max){
    // Find index
    int index = hash(key, max);
    int start = index;

    // Check if index is empty
    while (hashTable[index].occupied == 1){
        if (hashTable[index].key == key) {
            strcpy(hashTable[index].value, value);
            printf("Updated key %d at index %d\n", key, index);
            return;
        }

        index = hash(index+1, max);
        if (index == start) {
            printf("Hash table is full.\n");
            return;
        }  
    }

    // Insert value and print || insert value, key, and set occupied to 1
    strcpy(hashTable[index].value, value);
    hashTable[index].key = key;
    hashTable[index].occupied = 1;
    printf("Inserted key %d at index %d\n", hashTable[index].key, index);
}


// Search function
void searchValue(Hash hashTable[], int key, int max){
    // Find index
    int index = hash(key, max);
    int start = index;

    // Check if index is not empty
    while (hashTable[index].occupied != 0){
        if (hashTable[index].occupied != 0 && hashTable[index].key == key){
            printf("Found: %s\n", hashTable[index].value);
            return;
        } 
        
        index = hash(index+1, max);
        if (index == start) {
            break;
        }
    }

    printf("%d is not found.\n", key);

}


// Convert inputted command to lowercase for full laziness
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}