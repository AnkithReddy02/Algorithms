// Hackerearth.

#include<bits/stdc++.h>
using namespace std::chrono;
// You need to specify the std::chrono:: namespace qualifier in front of high_resolution_clock, microseconds, and duration_cast, eg:

#include <chrono>
using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define int long long
#define ll long long
#define PII pair<int,int>
#define INF 1e18
#define endl '\n'

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define ceil(x) ((int)(ceil(x)))
typedef unsigned uint;
typedef long double intd;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(int t) {cerr << t;} void _print(string t) {cerr << t;} void _print(char t) {cerr << t;} void _print(intd t) {cerr << t;} void _print(double t) {cerr << t;} void _print(uint t) {cerr << t;} template <class T, class V> void _print(pair <T, V> p); template <class T> void _print(vector <T> v); template <class T> void _print(set <T> v); template <class T, class V> void _print(map <T, V> v); template <class T> void _print(multiset <T> v); template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";} template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";} template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";} template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";} template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);} ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;} void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);} bool revsort(ll a, ll b) {return a > b;} void swap(int &x, int &y) {int temp = x; x = y; y = temp;} ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;} void google(int t) {cout << "Case #" << t << ": ";} vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;} ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;} ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;} ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;} ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

int max(int a,int b) {return a>b ? a : b; } int min(int a,int b) {return a<b? a : b; } void input(int a[],int n) {for(int i=0;i<n;i++) {cin >> a[i]; } }
int binomialCoeff(int n, int k) {int C[n + 1][k + 1]; int i, j; for (i = 0; i <= n; i++) {for (j = 0; j <= min(i, k); j++) {if (j == 0 || j == i) C[i][j] = 1; else C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; } } return C[n][k]; }


const int N = 11;


vector<int> discTime(N);
vector<int>  low(N);
vector<int>  parent(N);
vector<int>  articulation(N);
int currTime = 0;
vector<vector<int>> graph(N);
vector<PII> bridges;
void dfs(int u)
{
    discTime[u] = low[u] = currTime++;


    int children = 0;


    for(int i=0;i<(int)graph[u].size();i++)
    {
        int v = graph[u][i];
        if(discTime[v]==0)
        {

            children += 1;

            parent[v] = u;

            dfs(v);

            low[u] = min(low[u],low[v]);

            // root && children > 1;
            if(parent[u]==-1 && children > 1)
            {
                articulation[u] = 1;
            }

            if(parent[u]!=-1 && discTime[u]<=low[v])
            {
                articulation[u] = 1;
            }

            if(discTime[u] < low[v])
            {
                bridges.push_back({min(u,v),max(u,v)});
            }


        }
        else
        {
            if(parent[u]!=v)
            {
                low[u] = min(low[u],discTime[v]);
            }
        }
    }

}
auto solve()
{


    int n,m;

     vector<int> v(N,0);

    vector<vector<int>> s(N);

    while(1)
    {
        cin >> n;
        cin >>  m;

        if(n==0&&m==0)
        {
            break;
        }
    
        graph=  s;
        currTime = 1;
        

        parent = discTime = articulation = low = v;

        // debug(articulation);

        while(m--)
        {
            int x,y;
    
            cin >> x >> y;
    
            graph[x].push_back(y);
            // graph[y].push_back(x);
        }
    
        parent[1] = -1;

        debug(graph);
    
        dfs(1);
    
    
        vector<int> artres;
    
        for(int i=0;i<n;i++)
        {
            if(articulation[i])
            {
                artres.push_back(i);
            }
        }
    
    
    
        cout << (int)artres.size() << endl;
    
        // for(int x : artres)
        // {
        //     cout << x << " "; 
        // }
        // if((int)artres.size())
        // {
        //     cout << endl;
        // }
    
        sort(all(bridges));
    
        cout << (int)bridges.size() << endl;
        for(auto x : bridges)
        {
            cout << x.first << " " << x.second << endl;
        }
    
    }

    
}
int32_t main() 
{

    fastio();
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    // manipulated_seive(MAX_SIZE);

    int t;
    t = 1;
    // cin >> t;





    for(int i=1;i<=t;i++)
    {
        // google(i);
        auto start1 = high_resolution_clock::now();
        solve();
        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
        
        

        debug(duration . count() / 1000);


    }
}
