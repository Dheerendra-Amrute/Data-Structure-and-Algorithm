#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void traverse_forward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* ptr = head;
    printf("Forward Traversal: NULL <-> ");
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void traverse_backward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    
    printf("Backward Traversal: NULL <-> ");
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

struct Node* insert_at_begin(struct Node* head, int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }
    
    printf("Element %d inserted at the beginning.\n", data);
    return newnode;
}

struct Node* delete_by_key(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    struct Node* ptr = head;
    
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->next;
    }

    if(ptr == NULL){
        printf("Element %d not found.\n", key);
        return head;
    }
    
    if(ptr == head){
        head = ptr->next;
    }

    if(ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }

    if(ptr->prev != NULL){
        ptr->prev->next = ptr->next;
    }

    free(ptr);
    printf("Element %d was deleted.\n", key);
    return head;
}


int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete by Key\n");
        printf("3. Traverse Forward\n");
        printf("4. Traverse Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert_at_begin(head, data);
                break;
            case 2:
                printf("Enter key of element to delete: ");
                scanf("%d", &key);
                head = delete_by_key(head, key);
                break;
            case 3:
                traverse_forward(head);
                break;
            case 4:
                traverse_backward(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}