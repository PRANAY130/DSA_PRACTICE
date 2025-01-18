#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>;
#include<string.h>

#define max 100
char stack[max];
int top=-1;

void push(char ch){
    if(top==max-1){
        printf("The stack is empty\n");
        return;
    }
    stack[++top]=ch;
}

char pop(){
    if(top=-1){
        printf("The stack is empty\n");
        return;
    }
    char data=stack[top--];
    return data;
}

char peek(){
    char data=stack[top];
    return data;
}

int isempty(){
    return (top==-1);
}

int isfull(){
    return (top==max-1);
}

int isoperator(char data){
    return (data=='+'||data=='-'||data=='*'||data=='/'||data=='%'||data=='^');
}

int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    if(ch=='*'||ch=='/'||ch=='%'){
        return 2;
    }
    if(ch=='^'){
        return 3;
    }
    return 0;
}

void infix_to_postfix(){}