#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* Createnode(int data){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;

}

struct node* insertion(int data, struct node* root){
    if (root==NULL){
        root=Createnode(data);
        return root;
    }
    else if (data>root->data){
        root->right=insertion(data,root->right);
    }
    else if (data<root->data){
        root->left=insertion(data,root->left);
    }
    return root;
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

int main(){
    int choice,data;
    int i=1;
    struct node* root=NULL;
    printf("1.Insert\n");
    printf("2.Inorder\n");
    printf("3.Postorder\n");
    printf("4.Preorder\n");
    printf("6.EXIT\n");
    while(i==1){
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the data you want to insert\n");
            scanf("%d",&data);
            root=insertion(data,root);
            break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 6:
                i=2;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        
        }
    }
    return 0;
}