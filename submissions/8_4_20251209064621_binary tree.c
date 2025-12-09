#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to print spaces for indentation
void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
        printf(" ");
    }
}

// Function to display a Binary Tree
void displayTree(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }

    // Adjust the space for better visualization
    int spaces = 4;

    // Recursively display the right subtree
    displayTree(root->right, level + 1);

    // Print spaces for indentation based on the level
    printSpaces(level * spaces);

    // Print the value of the current node
    printf("%d\n", root->data);

    // Recursively display the left subtree
    displayTree(root->left, level + 1);
}

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Display the Binary Tree
    printf("Binary Tree Structure:\n");
    displayTree(root, 0);

    return 0;
}
