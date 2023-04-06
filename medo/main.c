#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void flatten(struct node* root) {
    if (root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left != NULL) {
        struct node* rightSubtree = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right != NULL) {
            root = root->right;
        }
        root->right = rightSubtree;
    }
}

void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->right;
    }
}

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);
    printf("Düzleþtirilmiþ liste: ");
    printList(root);
    return 0;
}
