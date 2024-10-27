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
        newnode->next=head;

        if (head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;
    }
    temp->next=head;
    return head;
}

void displaylinkedlist(struct Node** head){
    struct Node* temp=*head;
    if (*head==NULL){
        printf("The list is empty\n ");
        return;
    }
    printf("The linked list is \n");
       do{ 
        printf("%d->",temp->data);
        temp=temp->next;}
    while(temp!=head);
    printf("Head\n");
}

void insertatanyposition(struct Node** head, int data, int index){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        printf("The list is empty. Inserting at the beginning...\n");
        newnode->next=newnode;
        *head=newnode;
    }

    if(index==1){
        insertatbeginning(head,data);
        return;
    }
    for (int i=1;temp->next!=head && i<index-1;i++){
        temp=temp->next;
    }
    if(temp->next==*head && index!=1){
        printf("The position %d is not present.insertion at the end\n");
        insertatend(head,data);

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
        (*head)=temp->next;
        free(temp);
        return;
    }

    struct Node* prev=NULL;

    for (int i=1;temp!=NULL && i<index;i++){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        printf("The position %d is not present.deletion is not possible\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void insertatbeginning(struct Node** head, int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    newnode->data=data;
    newnode->next=NULL;
    if (*head==NULL){
        printf("The list is empty\n");
        newnode->next=newnode;
        *head=newnode;
        return;
    }
    while (temp->next!=head){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    *head=newnode;

}

void insertatend(struct Node** head, int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    newnode->data=data;
    newnode->next=NULL;
    if (*head==NULL){
        printf("The list is empty\n");
        newnode->next=newnode;
        *head=newnode;
        return;
    }
    while (temp->next!=head){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void deleteatbeginning(struct Node** head){
    struct Node* temp=*head;
    struct Node* last=*head;
    if(*head==NULL){
        printf("nothing to delete\n");
        return;
    }
    while(last->next!=*head){
        last=last->next;
    }
    if((*head)->next==*head){
        free(*head);
        return;
    }
    *head=(*head)->next;
    last->next=(*head);
    free(temp);
}

void deleteatend(struct Node** head){
    struct Node* temp=*head;   
    struct Node* prev=NULL; 

    if(*head==NULL){
        printf("nothing to delete\n");
        return;
    }

    while(temp->next!=*head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return;  
}

void searchelement(struct Node** head,int key){
    struct Node* temp=*head;
    int position=0;
    while(temp!=NULL){
        position++;
        if(temp->data==key){
            printf("The element %d is at %d position\n",key,position);
            return;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("The element is not present in the list\n");
    }     
}


int main(){
    struct Node* head = NULL;
    int n, choice, data, key, position;

    // Create a linked list with 'n' elements
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    head = createlinkedlist(n);

    while(1){
        printf("Here are all the choices\n");
        printf("Enter 1 for insert at beginning\n");
        printf("Enter 2 for insert at end\n");
        printf("Enter 3 for insert at any position\n");
        printf("Enter 4 for delete at beginning\n");
        printf("Enter 5 for delete at end\n");
        printf("Enter 6 for delete at any position\n");
        printf("Enter 7 for search\n");
        printf("Enter 8 for printing the list\n");
        printf("Enter 9 for exiting\n");

        printf("\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertatbeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertatend(&head, data);
                break;
            case 3:
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertatanyposition(&head, data, position);
                break;
            case 4:
                deleteatbeginning(&head);
                break;
            case 5:
                deleteatend(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteatanyposition(&head, position);
                break;
            case 7:
                printf("Enter value of element to search: ");
                scanf("%d", &key);
                searchelement(&head,key);
                break;
            case 8:
                displaylinkedlist(&head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");           

        }
    }
}