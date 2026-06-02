/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left,*right;
};

struct node* createnode(int x){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->right=newnode->left=NULL;
    return newnode;
}

struct node* insertnode(struct node* root,int x){
    if(root==NULL){
        return createnode(x);
    }
    
    if(x < root->data){
        root->left=insertnode(root->left,x);
    }
    else{
        root->right=insertnode(root->right,x);
    }
    return root;
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}
int main()
{
    
    struct node* root=NULL;
    
    root=insertnode(root,60);
    insertnode(root,100);
    insertnode(root,20);
    insertnode(root,30);
    insertnode(root,70);
    inorder(root);

    return 0;
}