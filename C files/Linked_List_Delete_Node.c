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

struct Node* Delete_from_Begin(struct Node*head){
    //struct Node*temp=(struct Node*) malloc(sizeof(struct Node));
    int deleted_data = head->data;
    printf("deleted data = %d\n", deleted_data);
    head= head->next;
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

    printf("linked list :\n");
    linkedlist_Traverse(head);
    printf("linked list after Deleting first element \n");
    head=Delete_from_Begin(head);
    linkedlist_Traverse(head);

}