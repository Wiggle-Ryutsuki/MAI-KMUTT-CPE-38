typedef struct inventory{
    int id;
    char name;
    char description;
    struct inventory* next;
} Inventory;