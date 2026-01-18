// Maimoona Aziz #67070503473
// Task: Write a C program to create a binary search tree (BST) and find the minimum and maximum values in the tree.

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

void findMinimum(Tree* root);
void findMaximum(Tree* root);

int main(void) {
    Tree* root = NULL;
    int n, data;
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // printf("Enter the node values:\n");
    // Create binary tree
    for (int i = 0; i < n; ++i) {

        // Create root node
        if(i == 0){
            scanf("%d", &data);
            root = insertRoot(root, data);
            continue;
        }

        // insert non-root node
        scanf("%d", &data);
        Tree* newNode = createnode(data);
        Tree* currNode = root, *parent = NULL;
        while (currNode != NULL){
            parent = currNode;
            if (currNode->data > data){
                currNode = currNode->left;

            } else if (currNode->data < data){
                currNode = currNode->right;

            }
        }

        if (parent->data > data){
            parent->left = newNode;

        } else if (parent->data < data){
            parent->right = newNode;
        }
    }
    findMinimum(root);
    findMaximum(root);
}

// Function to create a new node
Tree* createnode(int data) {
    Tree* newnode = (Tree*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Insert on the left of the node
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

// Traverse all the way to left child node
void findMinimum(Tree* root) {
    Tree* currNode = root;
    while (currNode->left != NULL) {
        currNode = currNode->left;
    }
    printf("%d \n", currNode->data);
}

// Traverse all the way to right child node
void findMaximum(Tree* root) {
    Tree* currNode = root;
    while (currNode->right != NULL) {
        currNode = currNode->right;
    }
    printf("%d \n", currNode->data);
}