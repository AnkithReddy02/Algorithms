#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    
    cin >> k;
    
    int n = pow(2,k);
    
    int a[n][n],b[n][n],c[n][n];
    
    printf("Enter Matrix 1 : \n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    
    
    printf("Enter Matrix 2 : \n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> b[i][j];
        }
    }
    
    printf("Matrix 1 * Matrix 2 : \n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sum = 0;
            
            for(int k=0;k<n;k++)
            {
                sum += a[i][k]*b[k][j];
            }
            
            c[i][j] = sum;
            
            cout << c[i][j] << " ";
            
        }
        cout << endl;
    }
}
