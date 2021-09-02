#include <stdio.h>
#include <stdlib.h>

int n=12;
int inor[]={0,7,6,17,16,21,28,46,51,29,25,20};
int postor[]={0,7,6,17,16,21,28,46,51,29,25,20};
int preor[12];


struct node{
    int data;
    struct node *left;
    struct node *right;
};

int searchIndex(int *p,int size,int data){
    for (int i=0;i<size;i++){
        if (p[i]==data)
            return i;
    }
}
void reverseList(int *p){
    for (int i=0;i<n;i++){
        preor[i]=p[n-i-1];
    }
}
void BubbleSort(int *p,int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if (p[j]>p[j+1]){
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

struct node *newNode(int data){
    struct node *block=malloc(sizeof(struct node));
    block->data=data;
    block->left=NULL;
    block->right=NULL;
    return block;
}

struct node *insert(int *in,int *post,int inS,int inE){
    static int postIndex=0;
    if (inS>inE)
        return NULL;
    
    struct node *block=newNode(post[postIndex]);
    postIndex++;

    if (inS==inE)
        return block;
    
    int inIndex=searchIndex(in,n,block->data);
    block->left=insert(in,post,inS,inIndex-1);
    block->right=insert(in,post,inIndex+1,inE);
    return block; 
}

void preOrder(struct node *root){
    if (root==NULL)
        return ;
    printf("%d,",root->data);
    preOrder(root->left);
    preOrder(root->right);
    
}
int main(){
    struct node *root=NULL;
    
    BubbleSort(inor,n);
    reverseList(postor);
    
    
    root=insert(inor,postor,0,n-1);
    
    printf("The PreOrder is : \n");
    preOrder(root);

    
}

