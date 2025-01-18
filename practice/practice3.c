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

void infix_to_postfix(char infix[],char postfix[]){
    int i,j=0;
    char ch;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];

        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if (ch==')'){
            while(!isempty && peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else if(isoperator(ch)){
            while(!isempty() && precedence(peek())>=precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(!isempty()){
        postfix[j++]=pop();
    }
    postfix[j]='/0';
}