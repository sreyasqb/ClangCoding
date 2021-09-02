#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void insert(struct node **head,int data){
    struct node *block=malloc(sizeof(struct node));
    block->data=data;
    block->link=NULL;
    struct node *temp=*head;
    while (temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=block;
}
void display(struct node *head){
    while (head->link!=NULL){
        printf("%d,",head->data);
        head=head->link;
    }
    printf("%d",head->data);
    
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;
    insert(&head,6);
    insert(&head,7);
    display(head);
    //printf("%d,%d",head->link,head->link->link);


}



