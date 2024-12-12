#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isalnum() function
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Define the structure for a stack
struct Stack {
    char items[MAX];
    int top;
};

// Function to create a stack (initialize the top as -1)
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char ch) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow! Cannot push %c\n", ch);
        return;
    }
    stack->items[++(stack->top)] = ch;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! No element to pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Function to get the top element of the stack without popping it
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}

// Function to define precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack();
    char postfix[MAX];
    int j = 0;  // Index for postfix array

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it onto the stack
        else if (ch == '(') {
            push(stack, ch);
        }
        // If the character is ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);  // Pop '('
        }
        // If the character is an operator
        else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    // Pop all remaining operators in the stack and add to postfix
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);

    // Free allocated memory
    free(stack);
}

// Main function
int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
