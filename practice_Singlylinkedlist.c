#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createlinkedlist(int n){
    int data;
    struct Node* head=NULL;
    struct Node* newnode=NULL;
    struct Node* temp=NULL;
    for (int i = 0 ; i<n ; i++){
        printf("Enter the element: ");
        scanf("%d",&data);
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=data;
        newnode->next=NULL;

        if (head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;
    }
    return head;
}

void displaylinkedlist(struct Node** head){
    struct Node* temp=*head;
    if (*head==NULL){
        printf("The list is empty ");
        return;
    }
    printf("The linked list is \n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertatanyposition(struct Node** head, int data, int index){
    struct Node* newnode=NULL;
    struct Node* temp=*head;
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        printf("The list is empty. Inserting at the beginning...\n");
        *head=newnode;
    }
    for (int i=0;temp!=NULL && i<=index-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("The position %d is not present.insertion is not possible");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}