#include <stdio.h>
const int m1i=2,m1j=3,m2i=2,m2j=3;
int matrix1[][3]={1,2,11,7,9,1};
int matrix2[][3]={31,6,3,-90,9,1};

void Display()
{   printf("This is the matrix : \n");
    for (int i=0;i<m1i;i++)
    {
        printf("[");
        for (int j=0;j<m1j;j++)
            printf("%d,",matrix1[i][j]);
        if (i<m1i-1)
            printf("]\n");
    }
    printf("]\n\n");
    printf("This is Matrix 2 :\n");
    for (int i=0;i<m2i;i++)
    {
        printf("[");
        for (int j=0;j<m2j;j++)
            printf("%d,",matrix1[i][j]);
        if (i<m2i-1)
            printf("]\n");
    }
    printf("]\n\n");

}

void Equal()
{
    int i=0,j=0;
    if (m1i==m2i && m2j==m1j)
    {
        
        for (i=0;i<m1i;i++)
        {
            for (j=0;j<m2j;j++)
            {
                if (matrix1[i][j]!=matrix2[i][j])
                    break;
            }
            if (j <(m2j-1))
            {
                printf("The 2 matrices aren't equal \n");
                break;
            }
             
        }
        if (i==m1i)
            printf("The 2 matrices are equal\n");
    }
    else
        printf("The 2 matrices aren't equal\n");
}

void Transpose()
{
    int tarr[m1j][m1i];
    for (int i=0;i<m1j;i++)
    {
        for (int j=0;j<m1i;j++)
        {   
            tarr[i][j]=matrix1[i][j];
            printf("Trans[%d,%d]=%d  , ",i,j,tarr[i][j]);
        }
        printf("\n");
    }

}
void Addition()
{
    if (m1i==m2i && m1j==m2j)
    {
        
        int addmatrix[m1i][m1j];
        for (int i=0;i<m1i;i++)
        {
            for (int j=0;j<m1j;j++)
            {
                addmatrix[i][j]=matrix1[i][j]+matrix2[i][j];
                printf("ADD[%d,%d]=%d  , ",i,j,addmatrix[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("You can't add 2 matrices of different orders\n");
}
void Multiply()
{
    if (m1j==m2i)
    {
        int marr[m1i][m2j];
        for (int i=0;i<m1i;i++)
        {
            for (int j=0;j<m2j;j++)
            {
                marr[i][j]=0;
                for (int k=0;k<m2i;k++)
                {
                    marr[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
                
                printf("Mult[%d,%d]=%d  , ",i,j,marr[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("You can't multiply these 2 matrices\n");
}


int main()
{
    //printf("To add the matrices : :\n");
    //Display();
    //Equal();
    
   // Transpose();
    //Addition();
    //Multiply();

    

}