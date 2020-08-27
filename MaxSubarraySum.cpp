/******************REFER GFG *****************************/


#include<bits/stdc++.h>
#define MAX(a,b,c) max(a,max(b,c))
using namespace std;

int crossingsum(int a[],int low,int middle , int high)
{
    int max_left_sum = INT_MIN;
    
    int sum = 0;
    
    for(int i=middle;i>=low;i--)
    {
        sum += a[i];
        
        if(max_left_sum < sum)
        {
            max_left_sum =   sum;
        }
    }
    
    int max_right_sum = INT_MIN;
    
    sum = 0;
    
    for(int i=middle+1;i<=high;i++)
    {
        sum += a[i];
        
        if(max_right_sum < sum)
        {
            max_right_sum = sum;
        }
    }
    
    return MAX(max_left_sum + max_right_sum  ,  max_right_sum ,  max_left_sum);   
    
    
    
    
    
    
}



int maxsubarraysum(int a[],int low,int high)
{
    if(low==high)
    {
        return a[low];
    }
    
    int middle = (low + high)/2 ;
    
    return MAX(maxsubarraysum(a,low,middle),maxsubarraysum(a,middle+1,high),crossingsum(a,low,middle,high));
}
int main()
{
    int n;
    cin >> n;
    
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    cout << maxsubarraysum(a,0,n-1) << endl;
}
