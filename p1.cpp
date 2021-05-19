#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ff first
#define ss second
#define fi(s,n) for (int i = s; i < n; i++)
#define fj(n) for (int j = 0; j < n; j++)
#define fk(n) for (int k = 1; k <= n; k++)
#define pb push_back
#define mp make_pair
//#define sort(rg) sort(rg.begin(), rg.end())
const int mod = 1e9 + 7;
const int prime=1e9 + 9;
// **** CODE STARTS HERE ******//
bool cmpd(ll a, ll b)
{
    return a > b;
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.ss == b.ss)
    {
        return a.ff < b.ff;
    }

    return a.ss > b.ss;
}

ll fact(ll a)
{
    ll val = 1;
    for (ll i = 1; i <= a; i++)
    {
        val = (val % mod * i % mod) % mod;
    }
    return val;
}
ll sqck(ll n)
{
    if (ceil(sqrt(n)) - sqrt(n) == 0)
    {
        return true;
    }
    else
        return false;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
class job 
{
    public:
    int a;
    int b;
    int c;
};
bool cmpt(job p ,job q)
{
    return p.c<q.c;
}   
vector<vector<ll>> dp(5001,vector<ll>(5001,-1));
ll n;
vector<ll> occ;
ll a[5001];
ll helper(ll i,ll done)
{
    //cout<<i<<" "<<done<<endl;
  //  cout<<occ.size()<<endl;
    if(done==occ.size())
    {
        return 0;
    }
    if(i==n)
    {
        return 1e7; 
    }
    if (dp[i][done] != -1)
    {
        return dp[i][done];
    }
    if(a[i]==1)
    {
        return helper(i+1,done);
    }

        return (dp[i][done]=min(helper(i+1,done),abs(i-occ[done])+helper(i+1,done+1)));
    
}
void solve()
{
    
    cin>>n;   

  
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                occ.pb(i);
            }
        }
    cout<<helper(0,0)<<endl;
}

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
     
                solve();
            
    // checktime;
    return 0;
}