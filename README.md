# -dev-1220505060

ikinci dönem ödevi
#include <stdio.h>
#include <stdlib.h>

// Ağaç düğümü yapısı
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Düğümleri bağlı listeye ekleme fonksiyonu
void flattenTree(struct Node* root, struct Node** head_ref) {
    if (root == NULL) {
        return;
    }

    flattenTree(root->right, head_ref);
    flattenTree(root->left, head_ref);

    root->right = *head_ref;
    root->left = NULL;

    *head_ref = root;
}

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->right;
    }
    printf("\n");
}

// Test fonksiyonu
void test() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    struct Node* head = NULL;
    flattenTree(root, &head);

    printf("Bağlı Liste: ");
    printList(head);
}

int main() {
    test();
    return 0;
}
