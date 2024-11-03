#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * createLinkedList (int n){
    struct Node * head = NULL;
    struct Node * temp = NULL;
    struct Node * newNode = NULL;
    int data , i;

    for(i=1;i<=n;i++){
        printf("Enter the data for node %d :" , i);
        scanf("%d", &data);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->next=NULL;

        if(head==NULL){
            head = newNode;
        } else {
            temp->next=newNode;
        }
        temp=newNode;
    }
    return head;
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
        printf("The position %d is not present.insertion is not possible\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}


int main(){
    struct Node * head = NULL;\
    int n;
    printf("Enter the number of nodes youy want to create : ");
    scanf("%d" , &n);
    head = createLinkedList(n);
    return 0;
}