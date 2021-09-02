#include <stdio.h>
int x=7;
void swap(int *a,int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
void bubbleSort(int arr[]){
    for (int i=0;i<x-1;i++)
    {
        for (int j=0;j<x-i-1;j++)
        {
            if (arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}
void insertSort(int arr[]){
    int j,key;
    for (int i=1;i<x;i++){
        j=i-1;
        key=arr[i];
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void selectionSort(int arr[]){
    for (int i=0;i<x;i++){
        for (int j=i+1;j<x;j++){
            if (arr[i]>arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
        }
    }

}
int linearSearch(int arr[],int value){
    for (int i=0;i<x;i++){
        if (arr[i]==value)
            return i;
    }
    return -1;
}
int binarySearch(int arr[],int value){
    int a=0,b=x;
    while(1){
        if (value>arr[(a+b)/2]){
            a=(a+b)/2;
        }
        else if( value<arr[(a+b)/2]){
            b=(a+b)/2;
        }
        else{
            return (a+b)/2;
        }
    }
    return -1;
}
void merge(int arr[],int a,int mid,int b){
    int n1=mid-a+1;
    int n2=b-mid;
    int la[n1];
    int ra[n2];
    for (int i=0;i<n1;i++){
        la[i]=arr[a+i];
    }
    for (int j=0;j<n2;j++){
        ra[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=a;
    while (i<n1 && j<n2){
        if (la[i]<ra[j]){
            arr[k]=la[i];
            i++;
        }
        else{
            arr[k]=ra[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        arr[k]=la[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=ra[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int a,int b){
    if (a<b){
        int mid=a+(b-a)/2;
        mergeSort(arr,a,mid);
        mergeSort(arr,mid+1,b);
        merge(arr,a,mid,b);
    }
    
}
void countSort(int arr[],int div){
    int result[x];
    int count[10]={0};
    for (int i=0;i<x;i++){
        count[(arr[i]/div)%10]++;
    }
    for (int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for (int i=x-1;i>-1;i--){
        result[count[(arr[i]/div)%10]-1]=arr[i];
        count[(arr[i]/div)%10]--;
    }
    for (int i=0;i<x;i++){
        arr[i]=result[i];
    }
}
void radixSort(int arr[]){
    int max=arr[0];
    for (int i=1;i<x;i++){
        if (arr[i]>max)
            max=arr[i];
    }
    for (int div=1;max/div>0;div*=10)
    {
        countSort(arr,div);
    }
}


void display(int arr[]){
    for (int i=0;i<x;i++)
        printf("%d,",arr[i]);
}
int main()
{
    // printf("Enter the len of list:");
    // scanf("%d",&x);
    // const int n=x;
    int arr[7/*n*/]={14,5,17,21,11,13,25};
    // for (int i=0;i<n;i++)
    // {
    //     printf("Enter element %d: ",i+1);
    //     scanf("%d",&arr[i]);
    // }
    
    
    printf("The array is :\n");
    display(arr);
    printf("\nindex of 17 using linear search is: %d",linearSearch(arr,17));
    printf("\nindex of 17 using binary search is: %d",binarySearch(arr,17));
    printf("\nThe sorted array using insert Sort :\n");
    insertSort(arr);
    display(arr);
    printf("\nThe sorted array using bubble Sort :\n");
    bubbleSort(arr);
    display(arr);
    printf("\nThe sorted array using selection Sort :\n");
    selectionSort(arr);
    display(arr);
    printf("\nThe sorted array using merge Sort :\n");
    mergeSort(arr,0,x-1);
    display(arr);
    printf("\nThe sorted array using radix Sort :\n");
    radixSort(arr);
    display(arr);
   
}