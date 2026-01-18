// Maimoona Aziz #67070503473
// Task: Create a program for tree construction for Inorder Traversal


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary tree node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Tree;

Tree* createnode(int data);
Tree* insertLeft(Tree* root, int data);
Tree* insertRight(Tree* root, int data);
Tree* insertRoot(Tree* root, int data);

void inorder(Tree* root);

//No need to edit in the main() function
int main(void) {
    Tree* root = NULL;
    int j;
    int n, data;
    char dir[10];
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // printf("Enter the node values:\n");
    for (int i = 0; i < n; ++i) {

        // insert/create root node
        if(i==0){
            scanf("%d", &data);
            root = insertRoot(root, data);
            continue;
        }

        // insert non-root node
        scanf("%s", dir);
        scanf("%d", &data);
        struct node* temp = root;
        for(j = 0; j<strlen(dir)-1; j++){
            if(dir[j]=='R'){
                temp = temp->right;
            }
            else if(dir[j]=='L'){
                temp = temp->left;
            }
        }
        if(dir[j]=='R'){
            temp = insertRight(temp, data);
        }
        else if(dir[j]=='L'){
            temp = insertLeft(temp, data);
        }
    }

    inorder(root); 
}

// Function to create a new node
Tree* createnode(int data) {
    Tree* newnode = (Tree*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Tree* insertLeft(Tree* root, int data) {
    Tree* newNode = createnode(data);
    root->left = newNode;
    return root->left;
}

// Insert on the right of the node
Tree* insertRight(Tree* root, int data) {
    Tree* newNode = createnode(data);
    root->right = newNode;
    return root->right;
}

// Function to insert a node
Tree* insertRoot(Tree* root, int data) {
    if (root == NULL){
        root = createnode(data);
    }
    return root;
}

// Inorder traversal: Left -> Root -> Right
void inorder(Tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    } else {
        return;
    }
}