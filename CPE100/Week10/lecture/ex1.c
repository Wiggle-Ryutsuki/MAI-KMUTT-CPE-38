#include <stdio.h>

int main(void){
    unsigned int account; //account number
    char name[30]; // Account name
    double balance; // Account balance

    FILE *cfPtr; // cfPTR = clients.dat file pointer

    //fopen opens file. Exit program if unable to create file
    if ((cfPtr = fopen("clients.dat", "w")) == NULL){
        puts("File could not be opened");
    } else {
        puts("Enter the account name and balance.");
        puts("Enter 'EOF' to end input.");
        printf("%s", "? ");
        scanf("%d%29s%lf", &account, name, &balance);

        // Write account, name, and balance into the file with fprintf
        while (!feof(stdin)){
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%lf", &account, name, &balance);
        } // end
        fclose(cfPtr);
    }
}