#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans=(ans*i)%M;
    }
    return ans%M;
}
ll nCr(ll n,ll r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}

vector<ll> printDivisors(int n)
{
	// Note that this loop runs till square root
    vector<ll>req;
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				req.push_back(i);

			else // Otherwise print both
            {
                req.push_back(i);
                req.push_back(n/i);
            }
		}
	}
    return req;
}
void sieveOfEratosthenes(int N, int s[])
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries in it as false.
    vector <bool> prime(N+1, false);
 
    // Initializing smallest factor equal to 2
    // for all the even numbers
    for (int i=2; i<=N; i+=2)
        s[i] = 2;
 
    // For odd numbers less than equal to n
    for (int i=3; i<=N; i+=2)
    {
        if (prime[i] == false)
        {
            // s(i) for a prime is the number itself
            s[i] = i;
 
            // For all multiples of current prime number
            for (int j=i; j*i<=N; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;
 
                    // i is the smallest prime factor for
                    // number "i*j".
                    s[i*j] = i;
                }
            }
        }
    }
}

ll maxm=0;
ll dfs(ll node,vector<vector<ll>>&adj,vector<ll>&deg,vector<ll>&vis)
{
    if(deg[node]==1)
    {
        vis[node]=1;
        return 1;
    }
    if(vis[node]==1)
    return 0;
    ll sum=0;
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(vis[child]==1)
        continue;
        ll curr=dfs(child,adj,deg,vis);
        if(node==0)
        maxm=max(maxm,curr);
        sum+=curr;
        //cout<<node+1<<" "<<child+1<<" "<<curr<<"    ";
    }
    return sum+1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<ll>deg(n);
        vector<vector<ll>>adj(n);
        rep(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            deg[x]++;
            deg[y]++;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        //cout<<"hi";
        // rep(i,0,n)
        // {
        //     cout<<deg[i]<<" ";
        // }
        if(deg[0]==1)
        {
            cout<<"1\n";
            continue;
        }
        vector<ll>vis(n);
        ll ans=dfs(0,adj,deg,vis);
        cout<<ans-maxm<<endl;
    }
}   