#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

struct Stack* createstack(){
    struct Stack* newstack=(struct Stack*)malloc(sizeof(struct Stack));
    newstack->top=-1;
    return newstack;
}

int isFull(struct Stack* newstack){
    return (newstack->top==MAX-1);
}

int isEmpty(struct Stack* newstack){
    return (newstack->top==-1);
}

void push(struct Stack* newstack,int data){
    if(isFull(newstack)){
        printf("The stack is full\n");
        return;
    }
    newstack->items[++(newstack->top)]=data;
    printf("The element %d is pushed\n",newstack->items[newstack->top]);
}

void pop(struct Stack* newstack){
    if(isEmpty(newstack)){
        printf("The stack is empty\n");
        return;
    }
    int poppedElement=newstack->items[(newstack->top)--];
    printf("The element %d is popped\n",poppedElement);
}

void peek (struct Stack* newstack){
    if (isEmpty(newstack)){
        printf("The stack is empty\n");
        return;
    }
    int peekedone=newstack->items[(newstack->top)];
    printf("%d\n",peekedone);
}

void displaystack(struct Stack* newstack){
    if(isEmpty(newstack)){
        printf("The stack is empty\n");
    }
    for(int i=newstack->top;i>-1;i--){
        printf("%d ",newstack->items[i]);
    }
    printf("\n");
}

int main(){
    struct Stack* newstack=createstack();
    int data,choice;
    while(1){
        printf("\n*** Stack Menu ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(newstack, data);
                break;
            case 2:
                pop(newstack);
                break;
            case 3:
                peek(newstack);
                break;
            case 4:
                displaystack(newstack);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
    }
