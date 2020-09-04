#include<bits/stdc++.h>
using namespace std;

int MaxElement(int a[],int start,int end)
{
    if(start==end)
    {
        return a[start];
    }
    
    int mid = (start+end)/2;
    
    return max(MaxElement(a,start,mid),MaxElement(a,mid+1,end));
}

int MinElement(int a[],int start,int end)
{
    if(start==end)
    {
        return a[start];
    }
    
    int mid = (start+end)/2;
    
    return min(MinElement(a,start,mid),MinElement(a,mid+1,end));
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
    
    int maxi = MaxElement(a,0,n-1);
    int mini = MinElement(a,0,n-1);
    
    cout << "Max Element in array is : " << maxi << endl;
    cout << "Min Element in array is : " << mini << endl;
    
    
    
}
