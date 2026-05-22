#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create() {
    struct node* newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if(x == -1) {
        return NULL;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    newnode->left = create(); 
    printf("Enter right child of %d\n", x);
    newnode->right = create(); 
    return newnode;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root;
    int choice;
    
    printf("--- Binary Tree Creation ---\n");
    printf("Instructions: Enter integer values for nodes.\n");
    printf("Enter -1 when asked for data to indicate 'no child'.\n\n");

    root = create();
    while (1) {
        printf("\n\n--- Traversal Menu ---\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Result: ");
                preorder(root);
                break;
            case 2:
                printf("Result: ");
                inorder(root);
                break;
            case 3:
                printf("Result: ");
                postorder(root);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}