#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else {
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

// 先序遍历
void printPreOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
// 中序遍历
void printInOrder(struct Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// 后序遍历
void printPostOrder(struct Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}
// 先序遍历 非递归
void printPreOrderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* temp = root;
    while (temp != NULL || top != -1) {
        while (temp != NULL) {
            printf("%d ", temp->data);
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top--];
        temp = temp->right;
    }
}
// 中序遍历 非递归
void printInOrderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* temp = root;
    while (temp != NULL || top != -1) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top--];
        printf("%d ", temp->data);
        temp = temp->right;
    }
}
// 后序遍历 非递归
void printPostOrderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* temp = root;
    struct Node* lastVisit = NULL;
    while (temp != NULL || top != -1) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left;
        }
        temp = stack[top];
        if (temp->right == NULL || temp->right == lastVisit) {
            printf("%d ", temp->data);
            top--;
            lastVisit = temp;
            temp = NULL;
        } else {
            temp = temp->right;
        }
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Pre-order traversal: ");
    printPreOrder(root);
    printf("\n");
    printPreOrderNonRecursive(root);
    printf("\n");
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");
    printInOrderNonRecursive(root);
    printf("\n");
    printf("Post-order traversal: ");
    printPostOrder(root);
    printf("\n");
    printPostOrderNonRecursive(root);
    printf("\n");

    return 0;
}
