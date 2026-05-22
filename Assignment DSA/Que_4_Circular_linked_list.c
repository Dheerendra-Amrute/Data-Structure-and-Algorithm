#include <stdio.h>
#include <stdlib.h>

// Circular Queue operations using Circular Linked List

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* rear) {
    if (rear == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct Node* temp = rear->next;
    printf("Queue elements: ");
    while (temp != rear) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", rear->data); // Print the last (rear) element
}

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

struct Node* dequeue(struct Node* rear) {
    if (rear == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    struct Node* front = rear->next;
    if (rear == front) { // Only one node
        printf("Dequeued %d from the circular queue.\n", front->data);
        free(front);
        return NULL;
    } else {
        printf("Dequeued %d from the circular queue.\n", front->data);
        rear->next = front->next;
        free(front);
        return rear;
    }
}

int main() {
    struct Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Circular Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                rear = enqueue(rear, data);
                break;
            case 2:
                rear = dequeue(rear);
                break;
            case 3:
                traverse(rear);
                break;
            case 4:
                printf("Exiting...\n");
                // Free all nodes before exit
                while (rear != NULL)
                    rear = dequeue(rear);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}