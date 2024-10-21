#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int data, i;


    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        // Create a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

void InsertAtBeginning(struct Node **head,int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        printf("The linked list is empty");
        return;
    }
    newNode->next=*head;
    *head=newNode;

}

void insertAtEnd(struct Node **head,int data){
    struct Node *temp=NULL;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        printf("The linked list is empty");
        return;
    }
    temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtAnyPosition(struct Node **head, int data, int position){
    struct Node *temp=NULL;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if (position==1){
        newNode->next=*head;
        *head=newNode;
    }
    else {
        temp=*head;
        for(int i=0;i<=position-2;i++){
            temp=temp->next;
        }
        if (temp==NULL){
            printf("Position is invalid");
            return;
        }
        if(temp->next=NULL){
            printf("At the end");
            temp->next=newNode;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

}

int main(){
    struct Node * head = NULL;\
    int n;
    printf("Enter the number of nodes youy want to create : ");
    scanf("%d" , &n);
    head = createLinkedList(n);
    return 0;
}