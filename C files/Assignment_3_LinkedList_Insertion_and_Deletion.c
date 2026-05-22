#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linkedlist_Traverse(struct Node*ptr){
    if(ptr == NULL){
        printf("The list is empty.\n");
        return;
    }
    int i=1;
    while(ptr!=NULL){
        printf("The Element %d is %d\n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}

// this function return struct Node* type data (head)
struct Node* insert_at_begin(struct Node*head, int data){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=head;
    return newnode;
}

struct Node* insert_at_end(struct Node*head,int data){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;

    if(head == NULL){
        return newnode;
    }
    
    struct Node*ptr = head;
    while (ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return head;
}

struct Node* insert_At_index(struct Node*head, int data, int index){
    if (index < 0) {
        printf("Invalid index.\n");
        return head;
    }
    if (index == 0) {
        return insert_at_begin(head, data);
    }
    
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node*p = head;
    int i=0;
    while(i != index-1 && p != NULL){
        p=p->next;
        i++;
    }
    
    if (p == NULL) {
        printf("Index out of bounds.\n");
        free(newnode);
        return head;
    }

    newnode->data=data;
    newnode->next=p->next;
    p->next=newnode;
    return head;
}

struct Node* delete_at_begin(struct Node* head){
    if(head == NULL){
        printf("List is already empty.\n");
        return NULL;
    }
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* delete_at_end(struct Node* head){
    if(head == NULL){
        printf("List is already empty.\n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node* delete_by_key(struct Node* head, int key){
     if(head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;

    if(p->data == key){
        head = delete_at_begin(head);
        return head;
    }

    while(q != NULL && q->data != key){
        p = p->next;
        q = q->next;
    }

    if(q == NULL){
        printf("Element with key %d not found.\n", key);
    } else {
        p->next = q->next;
        free(q);
    }
    return head;
}


int main(){
    struct Node*head = NULL;
    int choice, data, index, key;

    while(1){
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a specific Index\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete element by value\n");
        printf("7. Traverse Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insert_at_begin(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index (0-based): ");
                scanf("%d", &index);
                head = insert_At_index(head, data, index);
                break;
            case 4:
                head = delete_at_begin(head);
                printf("Deleted element from the beginning.\n");
                break;
            case 5:
                head = delete_at_end(head);
                printf("Deleted element from the end.\n");
                break;
            case 6:
                printf("Enter the value (key) to delete: ");
                scanf("%d", &key);
                head = delete_by_key(head, key);
                break;
            case 7:
                printf("\nElements in the list are:\n");
                linkedlist_Traverse(head);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}