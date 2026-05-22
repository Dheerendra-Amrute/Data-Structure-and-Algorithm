#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedlist_Traverse(struct Node* ptr){
    if(ptr == NULL){
        printf("The list is empty.\n");
        return;
    }
    printf("List: ");
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* insert_at_end(struct Node* head, int data){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    
    if (head == NULL) {
        return newnode;
    }

    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    
    p->next = newnode;
    return head;
}

struct Node* move_to_beginning(struct Node* head, int key){
    if(head == NULL || head->next == NULL || head->data == key){
        printf("Cannot move: list is empty, has one element, or key is already at the head.\n");
        return head;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    while(q != NULL && q->data != key){
        p = p->next;
        q = q->next;
    }

    if(q != NULL){
        p->next = q->next;
        q->next = head;
        head = q;
        printf("Element %d moved to the beginning.\n", key);
    } else {
        printf("Element with key %d not found.\n", key);
    }

    return head;
}

int main(){
    struct Node* head = NULL;
    int choice, data, key;

    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    head = insert_at_end(head, 40);
    head = insert_at_end(head, 50);

    while(1){
        printf("\n--- Move Node Menu ---\n");
        printf("1. Move a node to the beginning\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value (key) of the node to move: ");
                scanf("%d", &key);
                head = move_to_beginning(head, key);
                break;
            case 2:
                linkedlist_Traverse(head);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}