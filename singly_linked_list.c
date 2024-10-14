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

void printList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node * head = NULL;\
    int n;
    printf("Enter the number of nodes youy want to create : ");
    scanf("%d" , &n);
    head = createLinkedList(n);
    printList(head);
    return 0;
}