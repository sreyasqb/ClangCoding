#include <stdio.h>
#include <stdlib.h>
// 500       1000      2000
//[4,1000]->[6,2000]->[8,NULL]

//Singly linked list
struct node {
  int data;
  struct node *link;
};

struct node * insert(struct node *head,int value){
  struct node *block=malloc(sizeof(struct node));
  block->data=value;
  block->link=NULL;
  struct node *temp=head;
  //head [6,1000]->[7,2000]->[8,NULL]
  while (temp->link!=NULL){
    temp=temp->link;
  }
  temp->link=block;
  return head;
}

struct node *delete();



int main(){

  struct node *head;
  head=malloc(sizeof(struct node));
  //500
  //[ ]

  head->data=6;
  head->link=NULL;
  //500
  //[6,NULL]
  //500         1000
  //[6,1000]->[7,NULL]
  // struct node *block=malloc(sizeof(struct node));
  // block->data=7;
  // block->link=NULL;
  // // [6]->[7]
  // head->link=block;
  //head=500->data
  //head->link=1000 1000->data
  //[6,1000]->[7,NULL]
  // printf("%d",head->link->data);
  head=insert(head,7);
  head=insert(head,8);
  printf("%d",head->link->link->data);

}