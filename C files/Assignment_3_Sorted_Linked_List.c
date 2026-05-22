#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
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

struct Node* insert_in_sorted_order(struct Node* head, int data){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    
    if (head == NULL || head->data >= data) {
        newnode->next = head;
        return newnode;
    }

    struct Node* p = head;
    while (p->next != NULL && p->next->data < data) {
        p = p->next;
    }
    
    newnode->next = p->next;
    p->next = newnode;
    
    return head;
}

struct Node* delete_by_key(struct Node* head, int key){
    if(head == NULL){
       printf("List is empty, cannot delete.\n");
       return NULL;
    }

    struct Node* p = head;
    struct Node* q = head->next;

    if(p->data == key){
        head = p->next;
        free(p);
        printf("Element %d was deleted.\n", key);
        return head;
    }

    while(q != NULL && q->data != key){
        p = p->next;
        q = q->next;
    }

    if(q != NULL){
        p->next = q->next;
        free(q);
        printf("Element %d was deleted.\n", key);
    } else {
        printf("Element with key %d not found.\n", key);
    }

    return head;
}

void search_by_key(struct Node* head, int key){
    struct Node* ptr = head;
    int pos = 1;
    while(ptr != NULL){
        if(ptr->data == key){
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        if(ptr->data > key){
            break; 
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Element %d was not found in the list.\n", key);
}

int main(){
    struct Node* head = NULL;
    int choice, data, key;

    while(1){
        printf("\n--- Sorted Linked List Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search for an Element\n");
        printf("4. Traverse List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert_in_sorted_order(head, data);
                break;
            case 2:
                printf("Enter the value (key) to delete: ");
                scanf("%d", &key);
                head = delete_by_key(head, key);
                break;
            case 3:
                printf("Enter the value (key) to search for: ");
                scanf("%d", &key);
                search_by_key(head, key);
                break;
            case 4:
                printf("\nElements in the list are:\n");
                linkedlist_Traverse(head);
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