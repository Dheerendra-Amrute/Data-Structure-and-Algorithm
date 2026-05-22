#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linkedlist_Traverse(struct Node*ptr){
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
    newnode->next=head;
    newnode->data=data;
    return newnode;
}

struct Node* insert_at_end(struct Node*head,int data){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node*ptr= head;
    while (ptr!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->data=data;
    newnode->next=NULL;
    return head;
}

struct Node* insert_At_index(struct Node*head, int data, int index){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node*p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    newnode->data=data;
    newnode->next=p->next;
    p->next=newnode;
    return head;
}

struct Node* insert_after_key(struct Node*head,int data, int key){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node*ptr = head;
    while(key!= ptr->data){
        ptr=ptr->next;
    }
    newnode->data=data;
    newnode->next=ptr->next;
    ptr->next=newnode;
    return head;
}

struct Node* insert_before_key(struct Node*head,int data, int key){
    struct Node*newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node*ptr = head;
    struct Node*prevptr;
    while(key!= ptr->data){
        prevptr=ptr;
        ptr=ptr->next;
    }

    newnode->data=data;
    newnode->next=prevptr->next;
    prevptr->next=newnode;
    return head;
}


int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;
    second -> data = 10;
    second -> next = third;
    third -> data = 15;
    third -> next = NULL;

    printf("elements before Insertion\n");
    linkedlist_Traverse(head);
    head=insert_at_begin(head,100);
    printf("elements after Insertion at begining\n");
    linkedlist_Traverse(head);
    insert_At_index(head,56,1);
    printf("elements after Insertion at index\n");
    linkedlist_Traverse(head);
    insert_after_key(head,99,7);
    printf("elements after Insertion after the key\n");
    linkedlist_Traverse(head);
    insert_before_key(head,1563,7);
    printf("elements after Insertion before the key\n");
    linkedlist_Traverse(head);
}