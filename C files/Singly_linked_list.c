# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

int main(){
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*ptr;

    // Allocating memory for Node in the linked list in heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;
    second -> data = 10;
    second -> next = third;
    third -> data = 15;
    third -> next = NULL;

    ptr=head;
    int i;
    while(ptr!=NULL){
        i=i+1;
        printf("the element %d is : %d \n",i,ptr->data);
        ptr=ptr->next;     
    }
}