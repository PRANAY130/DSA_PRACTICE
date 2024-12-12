#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Define the structure for a stack to store characters
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

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %c\n", data);
        return;
    }
    stack->items[++(stack->top)] = data;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! No element to pop.\n");
        return '\0';
    }
    return stack->items[(stack->top)--];
}

// Function to peek at the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->items[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to get precedence of operators
int precedence(char operator) {
    if (operator == '^') return 3;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '+' || operator == '-') return 1;
    return 0;
}

// Function to reverse a string
void reverse(char* expr) {
    int length = strlen(expr);
    for (int i = 0; i < length / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[length - i - 1];
        expr[length - i - 1] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    struct Stack* stack = createStack();
    int length = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < length; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Convert infix to postfix on the reversed expression
    for (int i = 0; i < length; i++) {
        char ch = infix[i];

        // If operand, add to result
        if (isalnum(ch)) {
            prefix[prefixIndex++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(stack, ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                prefix[prefixIndex++] = pop(stack);
            }
            pop(stack);  // Pop '('
        }
        // Operator case
        else if (isOperator(ch)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                prefix[prefixIndex++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(stack)) {
        prefix[prefixIndex++] = pop(stack);
    }

    prefix[prefixIndex] = '\0';  // Null-terminate the string

    // Reverse the postfix expression to get the prefix
    reverse(prefix);
}

// Main function with menu-based system for infix-to-prefix conversion
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
