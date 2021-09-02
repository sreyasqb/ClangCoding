#include <stdio.h>
#include <stdlib.h>
#define n 7



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

void inorder(struct node *root,int *p){
    if (root==NULL)
        return;
    static int x=0;
    
    inorder(root->left,p);
    p[x]=root->data;
    x++;
    inorder(root->right,p);
}
int checkMirror(int *p1,int *p2){
    for (int i=0;i<n;i++){
        if (p1[i]!=p2[n-i-1])
            return 0;
    }
    return 1;
}

int main(){

    int tree1[n]={1,3,2,5,4};
    int tree2[n]={1,2,3,4,5};
    int in1[n];
    int in2[n];
    
    struct node *root1=NULL;
    struct node *root2=NULL;
   
    for (int i=0;i<n;i++){
        root1=insert(root1,tree1[i]);
        root2=insert(root2,tree2[i]);
    }
     
    inorder(root1,in1);
    inorder(root2,in2);
    
    printf("checkmirror binary value is : %d",checkMirror(in1,in2));
    



}

