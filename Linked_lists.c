#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
    
};
void insertNode(int n,struct node *head,int data)
{
    struct node *temp;
    struct node *new=malloc(sizeof(struct node));
    new->link=NULL;
    new->data=data;
    
    n--;
    while (n!=1)
    {
        temp=temp->link;
        n--;
    }
    new->link=temp->link;
    temp->link=new;
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d,",temp->data);
        temp=temp->link;
    }
}
int main()
{
    struct node *head=malloc(sizeof(struct node));
    struct node *temp,*fn;
    head->data=1;
    head->link=NULL;
    temp=head;
    //printf("%d \n",head);
    for (int i=2;i<5;i++)
    {
        fn=malloc(sizeof(struct node));
        fn->data=i;
        fn->link=NULL;
        temp->link=fn;
        temp=temp->link;
    }
    insertNode(2,head,9);
    display(head);





   


}