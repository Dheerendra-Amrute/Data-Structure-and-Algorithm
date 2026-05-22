#include <stdio.h>
#include <stdlib.h>

//2. Write and implement program for the stack operations using Singly Linked List.

struct Node {
    int data;
    struct Node* next;
};

struct Node* Push(struct Node* head, int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL){
        return newnode;
    }

    struct Node*ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    printf("Push operation done successfully\n");
    return head;
}

struct Node* Pop(struct Node*head){
    if (head == NULL){
        printf("stack is underflow (empty list)");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node*ptr= head;
    struct Node*ptr1= head->next;

    while(ptr1->next!=NULL){
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    ptr->next=NULL;
    free(ptr1);
    printf("Pop operation done successfully\n");
    return head;
}

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

int main(){
    int data , choice;
    struct Node* head=NULL;
    
    linkedlist_Traverse(head);
while(1){
    printf(".....Stack operations.....\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            printf("enter the data to push: ");
            scanf("%d",&data);
            head=Push(head,data);
            break;
        case 2:
            head=Pop(head);
            break;
        case 3:
            linkedlist_Traverse(head);
            break;
        case 4:
            printf("Exiting the Program...\n");
            exit(0);
            break;
        default:
            printf("Enter the valid choice\n");
    }
}
    return 0;
}