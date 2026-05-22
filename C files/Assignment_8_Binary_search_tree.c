#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// create function
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// search function
struct node* search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

// insert function
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Helper function to find the minimum value node (for deletion)
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete function
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL){
        return root;
    }
    if (key < root->data){
        root->left = deleteNode(root->left, key);
}
    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Added Function: Inorder traversal to display the tree
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* BST = NULL; 
    int choice, val;

    while (1) {
        printf("\n\n--- Implementation of Binary Search Tree ---\n");
        printf("1. Insert Element\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Tree (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &val);
            BST = insert(BST, val); 
            break;

        case 2:
            printf("Enter element to search: ");
            scanf("%d", &val);
            struct node* result = search(BST, val);
            if (result != NULL) {
                printf("Element found: %d\n", result->data);
            } else {
                printf("Element not found\n");
            }
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &val);
            BST = deleteNode(BST, val); 
            printf("Node deleted (if it existed).\n");
            break;
        
        case 4:
            printf("Tree Contents: ");
            inorder(BST);
            printf("NULL\n");
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}