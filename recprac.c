#include <stdio.h>
int lowInd(int arr[],int len){
    static int i=0;
    static int minInd = 0;
    if (i==len)
        return minInd;
    if (arr[i]<=arr[minInd]){
        minInd=i;
    }
    i++;
    lowInd(arr,len);
}
int main(){
    int arr[]={3,4,2,1,-1};
    printf("%d",lowInd(arr,5));
}