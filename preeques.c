#include <stdio.h>
#include <math.h>
int main(){
    int n,count=0;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++){
        int flag=1;
        for (int j=2;j<(int) sqrt(arr[i])+1;j++){
            if (arr[i]%j==0){
                flag=0;
                break;
            }
        }
        if (flag){
            printf("%d ,",arr[i]);
            count++;
        }
    }
    printf("\nTotal number of primes are : %d\n",count);
}