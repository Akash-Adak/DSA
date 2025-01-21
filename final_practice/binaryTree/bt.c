#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void manualInsert(struct Node** node) {
    int value;
    printf("Enter the root Node: ");
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // clear invalid input
    }
    *node = createNode(value);
    insertNodes(*node);
}

void insertNodes(struct Node* node) {
    bool left, right;
    int value;

    printf("Do you want to enter left of %d (1 for yes, 0 for no): ", node->value);
    while (scanf("%d", &left) != 1 || (left != 0 && left != 1)) {
        printf("Invalid input. Please enter 1 for yes or 0 for no: ");
        while(getchar() != '\n'); // clear invalid input
    }
    if (left) {
        printf("Enter the value of the left of %d: ", node->value);
        while (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter an integer: ");
            while(getchar() != '\n'); // clear invalid input
        }
        node->left = createNode(value);
        insertNodes(node->left);
    }

    printf("Do you want to enter right of %d (1 for yes, 0 for no): ", node->value);
    while (scanf("%d", &right) != 1 || (right != 0 && right != 1)) {
        printf("Invalid input. Please enter 1 for yes or 0 for no: ");
        while(getchar() != '\n'); // clear invalid input
    }
    if (right) {
        printf("Enter the value of the right of %d: ", node->value);
        while (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter an integer: ");
            while(getchar() != '\n'); // clear invalid input
        }
        node->right = createNode(value);
        insertNodes(node->right);
    }
}

void prettyDisplay(struct Node* node, int level) {
    if (node == NULL) {
        return;
    }
    prettyDisplay(node->right, level + 1);
    if (level > 0) {
        for (int i = 0; i < level - 1; i++) {
            printf("|\t");
        }
        printf("|----->%d\n", node->value);
    } else {
        printf("%d\n", node->value);
    }
    prettyDisplay(node->left, level + 1);
}

void preOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->value);
    inOrder(node->right);
}

void postOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->value);
}

int main() {
    struct Node* root = NULL;
    manualInsert(&root);
    printf("\nPretty Display:\n");
    prettyDisplay(root, 0);

    freeTree(root);
    
    return 0;
}
