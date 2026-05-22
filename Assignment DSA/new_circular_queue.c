#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode==NULL) {
        printf("Memory allocation failed.\n");
        return rear;
    }
    newnode->data = data;
    if (rear == NULL) {
        newnode->next = newnode;
        rear = newnode;
    } else {
        newnode->next = rear->next;
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueued %d to the circular queue.\n", data);
    return rear;
}