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
// preorder transversal
void preorder(struct node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// postorder
void postorder(struct node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d",root->data);
    }
}
// inorder
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
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
    preorder(n);
    postorder(n);
    inorder(n);
}
