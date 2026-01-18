// Maimoona Aziz #67070503473
// Write a C program to implement a hash table using the division method with chaining for collision handling.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct HashNode{
    int key;
    char value[MAX];
    struct HashNode* next;
} HashNode;

void innitTable(HashNode* hash[], int max);
int hash(int key, int max);
void insertValue(HashNode* hashTable[], int key, char value[], int max);
void deleteValue(HashNode* hashTable[], int key, int max);
void searchValue(HashNode* hashTable[], int key, int max);
void printTable(HashNode* hash[], int max);
void toLowerCase(char str[]);

int main(void){
    // Initialize array to be not occupied
    int max; scanf("%d", &max);
    HashNode* hashTable[max];
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

        } else if (strcmp(command, "delete") == 0) {
            // Get key
            scanf("%d", &key);

            // Delete
            deleteValue(hashTable, key, max);

        } else if (strcmp(command, "exit") == 0) {
            printTable(hashTable, max);
            break;
        
        } else {
            printf("Invalid Input.\n");
        }
    }
}


// Initialize array
void innitTable(HashNode* hash[], int max){
    for (int i = 0; i < max; i++){
        hash[i] = NULL;
    }
}


// Hash function
int hash(int key, int max){
    return key % max;
}


// Print table
void printTable(HashNode* hash[], int max){
    printf("Hash Table:\n");
    for (int i = 0; i < max; i++) {
        // Print id
        printf("[%d]", i);
        HashNode* current = hash[i];
        // Print value
        while (current) {
            printf(" -> %s", current->value);
            current = current->next;
        }
        printf("\n");
    }
}


// Insert function
void insertValue(HashNode* hashTable[], int key, char value[], int max){
    // Find index
    int index = hash(key, max);
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));

    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        HashNode* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    printf("Inserted key %d at index %d\n", key, index);
}


void deleteValue(HashNode* hashTable[], int key, int max){
    // Find index
    int index = hash(key, max);

    HashNode* current = hashTable[index];
    HashNode* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashTable[index] = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Deleted %d from index %d\n", key, index);
            return;
        }

        prev = current;
        current = current->next;
    }
    printf("Key %d not found for deletion\n", key);
}


// Search function
void searchValue(HashNode* hashTable[], int key, int max){
    // Find index
    int index = hash(key, max);

    HashNode* current = hashTable[index];

    // Check if index is not empty
    while (current != NULL){
        if (current->key == key){
            printf("Found: %s\n", current->value);
            return;
        }
        current = current->next;
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