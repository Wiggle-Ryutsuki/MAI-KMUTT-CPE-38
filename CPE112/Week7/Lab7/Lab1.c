// Maimoona Aziz #67070503473
// Task: Write a C program to create a binary search tree

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

void preorder(Tree* root);
void inorder(Tree* root);
void postorder(Tree* root);

int main(void) {
    Tree* root = NULL;
    int n, data;
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // printf("Enter the node values:\n");
    for (int i = 0; i < n; ++i) { // While i still less than number of nodes

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
    preorder(root); printf("\n");
    inorder(root); printf("\n");
    postorder(root); printf("\n");
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

void preorder(Tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);

        preorder(root->left);
        preorder(root->right);
    } else {
        return;
    }
}

void inorder(Tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    } else {
        return;
    }
}

void postorder(Tree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}