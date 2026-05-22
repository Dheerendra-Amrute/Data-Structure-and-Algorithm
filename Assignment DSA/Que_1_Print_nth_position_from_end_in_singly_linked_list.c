#include <stdio.h>
#include <stdlib.h>

//  1. Write and Implement a program to print the nth position node from the end of
//     the singly linked list.

struct Node{
    int data;
    struct Node* next;
};

struct Node* print_nth_position_form_end(struct Node* head , int position){
    struct Node* ptr = head;
    if(head == NULL){
        printf("the list is empty....");
        return head;
    }
    int i=0;
    while(ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    int position_from_end = i - position;
    ptr = head;

    if(position_from_end < 0){
        printf("The position is greater than the length of the list.\n");
        return head;
    }
    for(int j=0; j<position_from_end; j++){
        ptr = ptr->next;
    }
    printf("The element at position %d from the end is: %d\n", position, ptr->data);
}

int main(){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*) malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    int position;
    printf("Enter the position from the end: ");
    scanf("%d", &position);
    print_nth_position_form_end(head, position);
    return 0;
}