#include<bits/stdc++.h>
using namespace std;

int **allocate(int n)
{
    int **a = (int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        a[i] = (int *)malloc(sizeof(int)*n);
    }
    return a;
}

int **ADD(int**c,int **a,int **b,int Row_c,int Col_c,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            c[i+Row_c][j+Col_c] = a[i][j] + b[i][j];
            
        }
    }
    return c;
    
}


int **MatrixMultiply(int **a,int **b,int Row_A,int Col_A,int Row_B,int Col_B,int size)
{
    int **c = allocate(size);
    
    if(size==1)
    {
        c[0][0] = a[Row_A][Col_A] * b[Row_B][Col_B];
    }
    else
    {
        int new_size = size/2;
        
ADD(c,MatrixMultiply(a,b,Row_A,Col_A,Row_B,Col_B,new_size),MatrixMultiply(a,b,Row_A,Col_A+new_size,Row_B+new_size,Col_B,new_size),0,0,new_size);

ADD(c,MatrixMultiply(a,b,Row_A,Col_A,Row_B,Col_B+new_size,new_size),MatrixMultiply(a,b,Row_A,Col_A,Row_B+new_size,Col_B+new_size,new_size),0,new_size,new_size);

ADD(c,MatrixMultiply(a,b,Row_A+new_size,Col_A,Row_B,Col_B,new_size),MatrixMultiply(a,b,Row_A+new_size,Col_A+new_size,Row_B+new_size,Col_B,new_size),new_size,0,new_size);

ADD(c,MatrixMultiply(a,b,Row_A+new_size,Col_A,Row_B,Col_B+new_size,new_size),MatrixMultiply(a,b,Row_A+new_size,Col_A+new_size,Row_B+new_size,Col_B+new_size,new_size),new_size,new_size,new_size);



    }
    
    return c;
}


int main()
{
    int k ;
    
    
    printf("Enter The value of K (n = 2 ^ k) : ");
    
    cin >> k;
    
    int n = pow(2,k);
    
    printf("The value of n is : %d\n",n);
    
    int **a,**b;
    a = allocate(n);
    b = allocate(n);
    
    printf("Enter the Matrix 1 : \n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value of a[%d][%d] : ",i+1,j+1);
            
            cin >> a[i][j];
        }
    }
    
    
    printf("Enter the Matrix 2 : \n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value of b[%d][%d] : ",i+1,j+1);
            
            cin >> b[i][j];
        }
    }
    
    int**c = MatrixMultiply(a,b,0,0,0,0,n); 
    
    printf("The product of two matrices is : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << c[i][j] <<  " ";
        }
        cout << endl;
    }
}
