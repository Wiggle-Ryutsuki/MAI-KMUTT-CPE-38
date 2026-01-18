// Maimoona Aziz #67070503473
// Task: Write a C program to create a binary search tree (BST) and support INSERT, DEL, and END

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
Tree* insertTree(Tree* root, int data);
Tree* deleteNode(Tree* root, int data);

void preorder(Tree* root);
void inorder(Tree* root);
void postorder(Tree* root);
void toLowerCase(char str[]);

int main(void) {
    Tree* root = NULL;
    int n, data;
    char input[20];

    while(1){
        scanf("%s", input);
        toLowerCase(input);
        if (strcmp(input, "insert") == 0){
            scanf("%d", &data);
            root = insertTree(root, data);

        } else if (strcmp(input, "del") == 0){
            scanf("%d", &data);
            root = deleteNode(root, data);

        } else if(strcmp(input, "end") == 0){
            break;

        } else {
            printf("Invalid input\n");
        }
    } 

    if (root == NULL){
        printf("Tree is empty.\n");
    } else {
        preorder(root); printf("\n");
        inorder(root); printf("\n");
        postorder(root); printf("\n");
    }
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

Tree* insertTree(Tree* root, int data){
    Tree* newNode = createnode(data);
    // Create root node
    if (root == NULL){
        return createnode(data);
    }

    // insert non-root node
    Tree* currNode = root, *parent = NULL;
    while (currNode != NULL){
        parent = currNode;
        if (currNode->data > data){
            currNode = currNode->left;
        } else if (currNode->data < data){
            currNode = currNode->right;
        } else {
            return root;
        }
    }

    if (parent->data > data){
        parent->left = newNode;

    } else if (parent->data < data){
        parent->right = newNode;
    }

    return root;
}

Tree* deleteNode(Tree* root, int data){
    Tree* delNode = root, *parent = NULL;
    // Traverse to that node
    while (delNode != NULL && delNode->data != data){
        parent = delNode;
        if (data < delNode->data){
            delNode = delNode->left;
        } else {
            delNode = delNode->right;
        }
    }

    if (delNode == NULL){
        printf("Node not found.\n");
        return root;
    }

    // Case 1: Check if node is a leaf
    if (delNode->left == NULL && delNode->right == NULL){
        // If leaf is the root
        if (parent == NULL){
            free(delNode);
            return NULL;
        }
        
        // Modify parent pointers;
        if (parent->left == delNode){
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(delNode);
    }

    // Case 2: Check if node has a single child
    else if (delNode->left == NULL || delNode->right == NULL){
        // Find child
        Tree *child;
        if (delNode->left != NULL){
            child = delNode->left;
        } else {
            child = delNode->right;
        }

        // Appoint child as head of family
        if (parent == NULL) {
            free(delNode);
            return child; // If node was root, child is now root
        }

        if (parent->left == delNode){
            parent->left = child;
        } else {
            parent->right = child;
        }
        
        // coup d'état
        free(delNode);
    }
    
    // Case 3: Check if node has 2 children
    else {
        // Find the in-order predecessor
        // Go left once
        Tree *pred = delNode->left;
        Tree *predParent = delNode;

        // Go right all the way
        while (pred->right != NULL){
            predParent = pred;
            pred = pred->right;
        }

        // Replace data with predecessor
        delNode->data = pred->data;

        // Delete predecessor
        if (predParent->left == pred) {
            predParent->left = pred->left;
        } else {
            predParent->right = pred->left;
        }
    
        free(pred);
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
    } else {
        return;
    }
}

// Function to make my life easier
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}