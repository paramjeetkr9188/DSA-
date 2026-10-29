#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*createnode(int data){
    struct node*n= (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

// inorder
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
//BST check
int isBST(struct node*root){
    struct node*prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
    
}
int main(){
    struct node*n=createnode(6);
    struct node*n1= createnode(4);
    struct node*n2= createnode(2);
    struct node*n3= createnode(7);
    struct node*n4= createnode(1);
    struct node*n5= createnode(9);
    struct node*n6= createnode(5);
    n->left=n1;
    n->right=n2;
    n1->right=n3;
    n1->left=n4;
    n2->left=n5;
    n2->right=n6;   
    inorder(n);
    printf("\n %d",isBST(n));
}
