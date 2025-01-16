#include<stdio.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char ch){
    if (top==MAX-1){
        printf("Stack overflow\n");
    }
    stack[++top]=ch;
}