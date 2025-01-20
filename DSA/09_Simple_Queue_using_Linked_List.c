#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a queue (initialize front and rear as NULL)
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    printf("%d enqueued to queue.\n", data);
}

// Function to remove an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! No element to dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("%d dequeued from queue.\n", temp->data);
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
}

// Function to peek at the front element of the queue
void peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is %d\n", queue->front->data);
    }
}

// Function to display all elements of the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with a menu-based system for queue operations
int main() {
    struct Queue* queue = createQueue();  // Create a queue
    int choice, data;

    while (1) {
        printf("\n*** Queue Menu ***\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                peek(queue);
                break;
            case 4:
                displayQueue(queue);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
