// Maimoona Aziz #67070503473
// Write a C program to implement a hash table using the division method.

#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct Hash
{
    int key;
    char value[MAX];
    int occupied;
} Hash;

void innitTable(Hash hash[]);
int hash(int key);
void insertValue(Hash hashTable[], int key, char value[]);
void deleteValue(Hash hashTable[], int key);
void searchValue(Hash hashTable[], int key);
void printTable(Hash hash[]);
void toLowerCase(char str[]);

int main(void){
    // Initialize array to be not occupied
    Hash hashTable[MAX];
    void insertValue(Hash hash[], int index, char value[]);
    innitTable(hashTable);

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
            
            insertValue(hashTable, key, value);

        } else if (strcmp(command, "delete") == 0) {
            // Get key
            scanf("%d", &key);

            // Delete
            deleteValue(hashTable, key);

        } else if (strcmp(command, "search") == 0) {
            // Get key
            scanf("%d", &key);

            // Search
            searchValue(hashTable, key);

        } else if (strcmp(command, "end") == 0) {
            printTable(hashTable);
            break;
        
        } else {
            printf("Invalid Input.\n");
        }
    }
}


// Initialize array
void innitTable(Hash hash[]){
    for (int i = 0; i < MAX; i++){
        hash[i].occupied = 0;
    }
}


// Hash function
int hash(int key){
    return key % MAX;
}


// Print table
void printTable(Hash hash[]){
    int isEmpty = 1; // Table is empty
    for (int i = 0; i < MAX; i++){
        if (hash[i].occupied != 0){
            printf("Index %d: %d %s\n", i, hash[i].key, hash[i].value);
            isEmpty = 0; // Has at least one value;
        }
    }

    if (isEmpty != 0){
        printf("Table is empty.\n");
    }
}


// Insert function
void insertValue(Hash hashTable[], int key, char value[]){
    // Find index
    int index = hash(key);

    // Check if index is empty
    if (hashTable[index].occupied == 1){
        printf("Index %d is occupied.\n", index);
        return;
    }

    // Insert value and print || insert value, key, and set occupied to 1
    strcpy(hashTable[index].value, value);
    hashTable[index].key = key;
    hashTable[index].occupied = 1;
    printf("Inserted key %d at index %d.\n", hashTable[index].key, index);
}


// Delete function
void deleteValue(Hash hashTable[], int key){
    // Find index
    int index = hash(key);

    // Check if index is already empty
    if (hashTable[index].occupied == 0){
        return;
    }

    // Delete value || Erase value, key, and set occupied to 0
    strcpy(hashTable[index].value, "");
    hashTable[index].key = -1;
    hashTable[index].occupied = 0;
}


// Search function
void searchValue(Hash hashTable[], int key){
    // Find index
    int index = hash(key);

    // Check if index is not empty
    if (hashTable[index].occupied =! 0 && hashTable[index].key == key){
        printf("%d %s\n", index, hashTable[index].value);
    } else {
        printf("%d is not found.\n", key);
    }
}


// Convert inputted command to lowercase for full laziness
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}