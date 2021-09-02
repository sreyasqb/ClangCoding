#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *block=malloc(sizeof(struct node));
    block->data=data;
    block->left=NULL;
    block->right=NULL;
    return block;
}

struct node *insert(struct node * root,int data){
    if (root==NULL)
        return newNode(data);
    if (data<root->data){
        root->left=insert(root->left,data);
    }
    else if (data>root->data){
        root->right=insert(root->right,data);
    }
    return root; 
}

int main(){
    struct node *root=NULL;
    int n=10;
    int arr[]={8,7,4,2,3,1,10,9,12,11};

    root=insert(root,arr[0]);
    for (int i=1;i<n;i++)
        insert(root,arr[i]);

    printf("%d\n",root->right->left->data);
    
}

