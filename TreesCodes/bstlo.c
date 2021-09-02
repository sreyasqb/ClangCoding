#include <stdio.h>
#include <stdlib.h>
#define n 7


int loarr[n];
int arr[]={5,3,2,6,7,1,9};

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


int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

void printCurrentLevel(struct node* root, int level)
{
    static int x=0;
    if (root == NULL)
        return;
    if (level == 1){
        printf("%d ,",root->data);
        loarr[x]=root->data;
        x++;
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printCurrentLevel(root, i);
}

void PrintrevLevelOrder(int *p){
    for (int i=0;i<n;i++){
        printf("%d ,",p[n-i-1]);
    }
}


int main(){
    
    struct node *root=NULL;

    
    for (int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    printf("\nThe level order is : \n");
    printLevelOrder(root);
    printf("\nThe Reverse Level Order is : \n");
    PrintrevLevelOrder(loarr);
    
    
    
}
