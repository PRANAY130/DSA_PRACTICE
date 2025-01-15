#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Push an element onto the stack
void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

// Peek the top element of the stack
char peek() {
    return stack[top];
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Get the precedence of the operator
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    }
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Reverse a string without swapping
void reverseString(char input[], char output[]) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[len - i - 1] = input[i];
    }
    output[len] = '\0'; // Null-terminate the reversed string
}

// Convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    char reversedInfix[MAX_SIZE];
    reverseString(infix, reversedInfix); // Step 1: Reverse the infix expression

    // Replace '(' with ')' and vice versa
    for (int i = 0; reversedInfix[i] != '\0'; i++) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    char postfix[MAX_SIZE];
    infixToPostfix(reversedInfix, postfix); // Step 2: Convert reversed infix to postfix

    reverseString(postfix, prefix); // Step 3: Reverse the postfix to get prefix
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
