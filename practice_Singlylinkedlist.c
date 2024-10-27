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
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        printf("The list is empty. Inserting at the beginning...\n");
        *head=newnode;
    }

    if(index==1){
        newnode->next=*head;
        *head=newnode;
        return;
    }
    for (int i=1;temp!=NULL && i<index-1;i++){
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

void deleteatanyposition(struct Node** head, int index){
    struct Node* temp=*head;
    
    if(*head==NULL){
        printf("nothing to delete\n");
        return;
    }
    if(index==1){
        (*head)=(*head)->next;
        free(temp);
        return;
    }

    struct Node* prev=NULL;

    for (int i=1;temp!=NULL && i<index-1;i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("The position %d is not present.deletion is not possible");
        return;
    }
    prev->next=temp->next;
    free(temp);
}