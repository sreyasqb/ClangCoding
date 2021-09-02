#include <stdio.h>
#include <stdlib.h>
int n=5;

struct Dnode{
    int data;
    struct node *next;
    struct node *prev;
};


struct node{
    int data;
    struct node *link;

};

struct node* insertSLL(struct node *head,int value){
    struct node *temp=head,*block=malloc(sizeof(struct node));
    block->data=value;
    block->link=NULL;
    while (temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=block;
    return head;
}
void displaySLL(struct node *head){
    struct node *temp=head;
    while (temp){
        printf("%d,",temp->data);
        temp=temp->link;
    }

}

struct node *deleteSLL(struct node *head){

    struct node *temp=head;
    while (temp->link->link!=NULL){
        temp=temp->link;
    }
    temp->link=NULL;
    return head;

}


void enqueue(int *p,int *f,int *r,int value){
    if (*r-*f<n){
        *(p+*r%n)=value;
        (*r)++;
    }
    else
        printf("\nOUT OF INDEX");
}

void dequeue(int *f,int *r){
    if (*r!=*f){
        (*f)++;
    }
    else
        printf("STACK IS ALREADY EMPTY");
}

void displayQ(int *p,int f,int r){
    for (int i=f;i<r;i++){
        printf("%d,",*(p+i%n));
    }
    printf("\n\n");
}

struct Dnode* insertDLL(struct Dnode *head,int value){

    struct Dnode *temp=head;
    struct Dnode *block=malloc(sizeof(struct Dnode));
    block->next=NULL;
    block->data=value;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    block->prev=temp;
    temp->next=block;

    return head;

}


int main(){

    //SLL

    // struct node *head=malloc(sizeof(struct node));
    // head->data=5;
    // head->link=NULL;
    // head=insertSLL(head,6);
    // head=insertSLL(head,7);
    // head=insertSLL(head,8);
    // head=deleteSLL(head);
    // displaySLL(head);


    //CIRCULAR QUEUE

    // int front=0,rear=0;
    // int arr[n];
    // enqueue(arr,&front,&rear,5);
    // enqueue(arr,&front,&rear,6);
    // enqueue(arr,&front,&rear,7);
    // enqueue(arr,&front,&rear,8);
    // enqueue(arr,&front,&rear,9);
    // displayQ(arr,front,rear);
    // dequeue(&front,&rear);
    // enqueue(arr,&front,&rear,10);
    // dequeue(&front,&rear);
    // enqueue(arr,&front,&rear,11);
    // displayQ(arr,front,rear);

    //DLL

    // struct Dnode *head=malloc(sizeof(struct Dnode));
    // head->data=5;
    // head->next=NULL;
    // head->prev=NULL;
    // head=insertDLL(head,6);
    // printf("%d,",head->data);
    // head=head->next;
    // printf("%d,",head->data);
    // head=head->prev;
    // printf("%d,",head->data);





}