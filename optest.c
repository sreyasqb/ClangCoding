#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * link;
};
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;
    struct node *block=malloc(sizeof(struct node));
    block->data=6;
    block->link=NULL;
    head->link=block;
    block=malloc(sizeof(struct node));
    block->data=7;
    block->link=NULL;
    head->link->link=block;
    printf("%d",head->link->link->data);

}
