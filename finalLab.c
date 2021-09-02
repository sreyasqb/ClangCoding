#include <stdio.h>
#include <stdlib.h>


struct node{

    int data;
    struct node* left;
    struct node* right;
    int rc;
    int lc;
};

struct node *newnode(int value){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->rc=0;
    temp->lc=0;
    
}


int isFull(int n){
    while (n%2 == 0)
        n/=2;
     
    if (n == 1)
        return 1;
    else
        return 0;
}



struct node * insert(struct node *root,int value){

    if (root==NULL){
        return newnode(value);
    }
    if (root->lc == root->rc) {
        root->left = insert(root->left, value);
        root->lc += 1;
    }
    else if (root->lc > root->rc) {
        if (isFull(root->lc+1)) {
            root->right = insert(root->right, value);
            root->rc += 1;
        }
        else {
            root->left = insert(root->left, value);
            root->lc += 1;
        }
    }
    return root;

}

void leaves(struct node *root){

    
    if (root==NULL)
        return ;
    if (root->left==NULL && root->right==NULL){
    
        printf("%d , ",root->data);
        return;
    }
    if (root->left)
       leaves(root->left);
    if (root->right)
       leaves(root->right);
}


void postorder(struct node* root){

    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d , ", root->data);
    }
    
}

int main(){

    int n;
    struct node *root=NULL;
    printf("Enter the no of elements u want : ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nTHE ARRAY IS : \n");
    for (int i=0;i<n;i++){
        printf("%d , ",arr[i]);
    }
    printf("\n");
   
    for (int i =0;i<n;i++){
        root=insert(root,arr[i]);
    }
    printf("\nTHE POSTORDER TRAVERSAL OF THE TREE IS : \n");
    postorder(root);
    printf("\n\n");
     if (isFull(n+1))
        printf("IT IS A FULL TREE\n");
    else
        printf("NOT A FULL TREE\n");
    printf("\nTHE LEAVES OF THE TREE IS : \n");
    leaves(root);
    printf("\n\n");
    
    
    



}