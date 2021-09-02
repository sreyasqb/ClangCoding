#include <stdio.h>
#include <stdlib.h>

int n=15;
int inor[]={25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};
int preor[]={25,15,10,4,12,22,18,24,50,35,31,44,70,66,90};


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

struct node *insert(int *in,int *pre,int inS,int inE){
    static int preIndex=0;
    if (inS>inE)
        return NULL;
    
    struct node *block=newNode(pre[preIndex]);
    preIndex++;

    if (inS==inE)
        return block;
    
    int inIndex=searchIndex(in,n,block->data);
    block->left=insert(in,pre,inS,inIndex-1);
    block->right=insert(in,pre,inIndex+1,inE);
    return block; 
}

void postOrder(struct node *root){
    if (root==NULL)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d,",root->data);
}
int main(){
    struct node *root=NULL;
    
    BubbleSort(inor,n);
    // for (int i=0;i<n;i++)
    //     printf("%d -- %d \n",preor[i],inor[i]);
    
    root=insert(inor,preor,0,n-1);
    printf("THE POSTORDER IS :\n");
    postOrder(root);
}

