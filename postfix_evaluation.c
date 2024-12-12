#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit() function

#define MAX 100  // Maximum size of the stack

// Define the structure for a stack
struct Stack {
    int items[MAX];
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
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->items[++(stack->top)] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! No element to pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack();

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isdigit(ch)) {
            push(stack, ch - '0');  // Convert char digit to integer
        }
        // If the character is an operator, pop two elements, apply the operator, and push the result
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (ch) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
                default:
                    printf("Invalid operator encountered: %c\n", ch);
                    return -1;
            }
        }
    }

    // The result of the expression is the only element left in the stack
    int result = pop(stack);
    free(stack);
    return result;
}

// Main function
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
