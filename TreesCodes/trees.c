#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *newnode(int value){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int value){
    
    if (root==NULL){
        return newnode(value);
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if (value>root->data){
        root->right=insert(root->right,value);
    }
    return root;

}

void inorder(struct node *root){

    if (root!=NULL){
        inorder(root->left);
        printf("%d,",root->data);
        inorder(root->right);
    }

}

int main(){

    struct node *root=NULL;
    root = insert(root, 50);
    root=insert(root, 20);
    root=insert(root, 30);
    root=insert(root, 40);
    root=insert(root, 70);
    root=insert(root, 60);
    root=insert(root, 80);
    inorder(root);



}