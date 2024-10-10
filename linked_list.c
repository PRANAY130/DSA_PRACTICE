#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

void createnode(int data){
    struct node* temp, *q;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        q=head;
        while(q!=NULL){
            q=q->next;
        }
        q->next=temp;
    }
}