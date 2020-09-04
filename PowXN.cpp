#include<bits/stdc++.h>
using namespace std;

int PowCal(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }
    
    if(n%2==0)
    return PowCal(x*x,n/2);
    
    return PowCal(x*x,n/2) * x;
}
int main()
{
    int x;
    int n;
    cin >> x >> n;
    
    int result = PowCal(x,n);
    cout << result << endl;
}
