/******************************************************************************

NUMBER OF INVERSIONS USING MERGE_SORT.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void count(int a[],int l,int m,int h,int *inversions)
{
    int p = l;
    int q = m+1;
    
    
    while(p<=m)
    {
        while(q<=h&&a[p]>=a[q])
        {
            q++;
        }
        
        if(q<=h&&a[p]<a[q])
        *inversions = *inversions + (h-q+1);
        
        p++;
    }
    
    int temp[h-l+1];
    
    int in = 0;
    
    int i = l;
    int j = m+1;
    
    
    while(i<=m&&j<=h)
    {
        if(a[i] > a[j])
        {
            temp[in++] = a[j];
            j++;
        }
        else
        {
            temp[in++] = a[i];
            i++;
        }
    }
    while(i<=m)
    {
        temp[in++] = a[i];
        i++;
    }
    while(j<=h)
    {
        temp[in++] = a[j];
        j++;
    }
    in = 0;
    for(int i=l;i<=h;i++)
    {
        a[i] = temp[in++];
    }
}



void count_inversions(int a[],int l,int h,int *inversions)
{
    if(l<h)
    {
        int m = (l+h)/2;
        
        count_inversions(a,l,m,inversions);
        count_inversions(a,m+1,h,inversions);
        count(a,l,m,h,inversions);
    }
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
    
    int count_inv;
    
    int *inversions=&count_inv;
    
    *inversions = 0;
    
    count_inversions(a,0,n-1,inversions);
    
    cout << *inversions << endl;
}
