#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE]; // Array to hold stack elements
int top = -1;        // Initialize top of stack to -1

// Check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("Pushed %d to stack\n", value);
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int popped_value = stack[top--];
        printf("Popped %d from stack\n", popped_value);
        return popped_value;
    }
}

// Peek the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        printf("Top element is %d\n", stack[top]);
        return stack[top];
    }
}

// Display all elements of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    peek();
    pop();
    display();
    pop();
    pop();

    return 0;
}
