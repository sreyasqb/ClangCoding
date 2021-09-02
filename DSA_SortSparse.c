#include <stdio.h>
const int n=5;
const int m=5;
int sparse_arr[5][5]={0,1,2,3,0,0,0,0,4,0,0,0,5,0,0,0,0,6,0,7,8,9,0,0,0};
void sparse()
{
    int zc=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (sparse_arr[i][j]==0)
                zc++;
        }
    }
    
    if (zc>n*m-zc)
    {
        int fin_arr[3][n*m-zc];
        int k=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (sparse_arr[i][j]!=0)
                {
                    fin_arr[0][k]=sparse_arr[i][j];
                    fin_arr[1][k]=i;
                    fin_arr[2][k]=j;
                    k++;
                }
            }
        }
        printf("\nThe sparse matrix is :-\n");
        for (int i=0;i<3;i++)
        {
            printf("[");
            for (int j=0;j<n*m-zc;j++)
                printf("%d,",fin_arr[i][j]);
            if (i<n-1)
                printf("]\n");
        }
    }
    else
        printf("not a sparse matrix\n");  
}
void sparseAdd()
{
    const int n=5;
    int arr1[5][5]={0,1,2,0,11,0,10,0,4,0,0,0,5,0,0,0,0,6,0,7,8,9,0,0,0},arr2[5][5]={0,1,2,3,0,0,0,0,4,0,0,0,5,0,0,0,0,6,0,7,8,9,0,0,0};
    int zc1=0,zc2=0;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr1[i][j]!=0)
                zc1++;
            if (arr2[i][j]!=0)
                zc2++;
        }
    }
    int csr1[3][zc1],csr2[3][zc2];
    int k=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr1[i][j]!=0)
            {
                csr1[0][k]=arr1[i][j];
                csr1[1][k]=i;
                csr1[2][k]=j;
                k++;
            }
        }
    }
    k=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr2[i][j]!=0)
            {
                csr2[0][k]=arr2[i][j];
                csr2[1][k]=i;
                csr2[2][k]=j;
                k++;
            }
        }
    }
    printf("\nThe sparse matrix 1 in CSR is :-\n");
    for (int i=0;i<3;i++)
    {
        printf("[");
        for (int j=0;j<zc1;j++)
            printf("%d,",csr1[i][j]);
        if (i<n-1)
            printf("]\n");
    }
    printf("\nThe sparse matrix 2 in CSR is :-\n");
    for (int i=0;i<3;i++)
    {
        printf("[");
        for (int j=0;j<zc2;j++)
            printf("%d,",csr2[i][j]);
        if (i<n-1)
            printf("]\n");
    }

    int i1=0,i2=0,len=0;
    int fin_arr[3][zc1+zc2];
    while (i1<zc1 && i2<zc2)
    {   
        if (csr1[1][i1]==csr2[1][i2])
        {
            if (csr1[2][i1]==csr2[2][i2])
            {
                fin_arr[0][len]=csr1[0][i1]+csr2[0][i2];
                fin_arr[1][len]=csr1[1][i1];
                fin_arr[2][len]=csr2[2][i2];
                i1++;
                i2++;
                len++;
            }
            else if(csr1[2][i1]<csr2[2][i2])
            {
                fin_arr[0][len]=csr1[0][i1];
                fin_arr[1][len]=csr1[1][i1];
                fin_arr[2][len]=csr1[2][i1];
                i1++;
                len++;
            }
            else
            {
                fin_arr[0][len]=csr2[0][i2];
                fin_arr[1][len]=csr2[1][i2];
                fin_arr[2][len]=csr2[2][i2];
                i2++;
                len++;
            }
        }
        
        else if (csr1[1][i1]<csr2[1][i2])
        {
            fin_arr[0][len]=csr1[0][i1];
            fin_arr[1][len]=csr1[1][i1];
            fin_arr[2][len]=csr1[2][i1];
            i1++;
            len++;
        }
        else
        {
            
            fin_arr[0][len]=csr2[0][i2];
            fin_arr[1][len]=csr2[1][i2];
            fin_arr[2][len]=csr2[2][i2];
            i2++;
            len++;
            
        }
    }
    printf("\nThe sum of the sparse matrices are :-\n");
    for (int i=0;i<3;i++)
    {
        printf("[");
        for (int j=0;j<len;j++)
            printf("%d,",fin_arr[i][j]);
        if (i<n-1)
            printf("]\n");
    }
}
void polyAdd()
{
    const int n=4,m=3;
    int poly1[2][4]={1,2,3,4,5,4,3,1};//{1,5,2,4,3,3,4,1};
    int poly2[2][3]={7,8,4,5,4,0},len=0;//{7,5,8,4,4,0};
    int fin_arr[2][10],i1=0,i2=0;
    while (i1<n && i2<m)
    {
        if (poly1[1][i1]==poly2[1][i2])
        {
            fin_arr[0][len]=poly1[0][i1]+poly2[0][i2];
            fin_arr[1][len]=poly1[1][i1];
            i1++;
            i2++;
        }
        else if (poly1[1][i1]>poly2[1][i2])
        {
            fin_arr[0][len]=poly1[0][i1];
            fin_arr[1][len]=poly1[1][i1];
            i1++;
        }
        else if (poly1[1][i1]<poly2[1][i2])
        {
            fin_arr[0][len]=poly2[0][i2];
            fin_arr[1][len]=poly2[1][i2];
            i2++;
        }
        
        len++;
    }
    while (i1<n){
        fin_arr[0][len]=poly1[0][i1];
        fin_arr[1][len]=poly1[1][i1];
        i1++;
        len++;
    }
    while (i2<m){
        fin_arr[0][len]=poly2[0][i2];
        fin_arr[1][len]=poly2[1][i2];
        i2++;
        len++;
    }
    printf("This is the polynomial 1: \n");
    for (int i=0;i<2;i++)
    {
        printf("[");
        for (int j=0;j<n;j++)
            printf("%d,",poly1[i][j]);
        if (i<1)
            printf("]\n");
    }
    printf("]\nThis is the polynomial 2: \n");
    for (int i=0;i<2;i++)
    {
        printf("[");
        for (int j=0;j<m;j++)
            printf("%d,",poly2[i][j]);
        if (i<1)
            printf("]\n");
    }
    printf("]\n");
    printf("\nThis is the sum of polynomials: \n");
    for (int i=0;i<len-3;i++)
    {
        printf("[");
        for (int j=0;j<len;j++)
            printf("%d,",fin_arr[i][j]);
        if (i<1)
            printf("]\n");
    }
    printf("]\n");
}

void display()
{
    for (int i=0;i<n;i++)
    {
        printf("[");
        for (int j=0;j<m;j++)
            printf("%d,",sparse_arr[i][j]);
        if (i<n-1)
            printf("]\n");
    }
    printf("]\n\n");
}


int main()
{
    display();
    sparse();
    sparseAdd();
    polyAdd();
}