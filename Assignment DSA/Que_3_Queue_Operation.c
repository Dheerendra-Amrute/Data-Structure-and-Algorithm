#include <stdio.h>
#include <stdlib.h>

//3. Write and implement program for the Queue operations using Singly Linked List.

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
struct Node* enqueue(struct Node*head, int data){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;

    if(head == NULL){
        return newnode;
    }
    struct Node*ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    printf("Enqueued %d to the queue.\n", data);
    return head;
}

struct Node* dequeue(struct Node* head){
    if(head == NULL){
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    printf("Dequeued an element from the queue.\n");
    return head;
}

int main(){
    struct Node*head = NULL;
    int choice, data;

    while(1){
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                head = enqueue(head, data);
                break;
            case 2:
                head = dequeue(head);
                break;
            case 3:
                linkedlist_Traverse(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

