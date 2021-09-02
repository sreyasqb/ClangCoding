#include <stdio.h>

void enqueue(int value,int *f,int *r,int arr[]){

    arr[*r]=value;
    (*r)++;
}

void dequeue(int *f,int *r,int arr[]){
    (*f)++;
}

void display(int f,int r,int arr[]){
    
    for (int i=f;i<r;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}


int main(){
    int size=5,front=0,rear=0;
    int arr[size];
    enqueue(6,&front,&rear,arr);
    display(front,rear,arr);
    enqueue(7,&front,&rear,arr);
    display(front,rear,arr);
    dequeue(&front,&rear,arr);
    display(front,rear,arr);
    enqueue(9,&front,&rear,arr);
    display(front,rear,arr);
}