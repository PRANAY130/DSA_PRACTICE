#include<stdio.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch){
    if (top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=ch;
}
char pop(){
    if(top==-1){
        printf("The stack is empty.\n");
        return;
    }
    char popped_element=stack[top--];
    return popped_element;
}

char peek(){
    char peeked_element=stack[top];
    return peeked_element;
}

int isempty(){
    return (top==-1);
}

int isfull(){
    return (top==MAX-1);
}