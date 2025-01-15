#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node (which is a linked list node)
struct Node {
    int data;
    struct Node* next;
};

// Function to create a stack (initialize as empty linked list)
struct Node* createStack() {
    return NULL;  // Empty stack initialized to NULL
}

// Function to push an element onto the stack (Insert at the beginning)
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;  // New node points to current top
    *top = newNode;  // Top now becomes the new node
    printf("%d pushed onto stack.\n", data);
}

// Function to pop an element from the stack (Delete from the beginning)
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! No element to pop.\n");
        return;
    }

    struct Node* temp = *top;
    printf("%d popped from stack.\n", temp->data);
    *top = (*top)->next;  // Move the top to the next node
    free(temp);  // Free the popped node's memory
}

// Function to peek at the top element of the stack (Just return the top node's data)
void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to display the stack (Print all elements)
void printStack(struct Node* top) {
    struct Node* temp = top;

    if (temp == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with switch-case for operations
int main() {
    struct Node* stack = createStack();  // Initialize an empty stack
    int choice, data;

    while (1) {
        printf("\n*** Stack Menu ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                printStack(stack);
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
