// https://cses.fi/problemset/task/1753 -- STRING HASHING

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define int long long
int gcdExtended(int a, int b, int* x, int* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
         
        // m is added to handle negative x
        int res = (x % m + m) % m;
       return res;
    }
}
int32_t main()
{
	fastio();
	string s;

	cin >> s;

	int p = 31;
	int m = 1e9+9;

	int n = s.length();

	string t;
	cin >> t;

	int powx[n+1],inv[n+1];

	// intialization
	powx[0] = 1;
	inv[0] = 0;

	// precomputation of power and inverse.
	for(int i=1;i<=n;i++)
	{
		powx[i] = (p*powx[i-1])%m;
		inv[i] = modInverse(powx[i-1],m);
	}

	// hash precomputation.


	/*

	hash[0] = 0; // represents 0 characetrs hash
	inv[0] = 0;
	// in general inv[1] = 1;
	// i and j are 1 based index
	// whole program is one based index.
	hash[i..j] = ((hash[j]%m - hash[i-1]%m + m)*inv[i]) % m
	inv[i] = modInverse(powx[i-1],m);
	for(int i=0;i<n;i++)
	{
		hash[i+1] = (hash[i] + (s[i] - 'a' + 1)*powx[i])%m;
	}

	*/
	int hash[n+1],hash2[n+1];

	hash[0] = 0;
	hash2[0] = 0;

	for(int i=0;i<s.length();i++)
	{
		hash[i+1] = (hash[i] + (s[i]-'a'+1)*powx[i] )%m;

	}

	int i = 1;
	int j = s.length() ;

	vector<int> v;
	while(i!=s.length()&&j!=1)
	{
		int lhash = ((hash[i]%m - hash[0]%m + m)*inv[1])%m;
		int rhash = ((hash[s.length()]%m - hash[j-1]%m + m)*inv[j])%m;

		if(lhash==rhash)
		{
			v.push_back(i);
		}

		i++;
		j--;
	}

	for(int x : v)
	{
		cout << x << " ";
	}

	

	


}
