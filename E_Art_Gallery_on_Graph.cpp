#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
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
 
// Function to generate prime factors and its power
vector<pair<int,int>> generatePrimeFactors(int N)
{
    // s[i] is going to store smallest prime factor
    // of i.
    int s[N+1];
 
    // Filling values in s[] using sieve
    sieveOfEratosthenes(N, s);
 
    int curr = s[N];  // Current prime factor of N
    int cnt = 1;   // Power of current prime factor
    vector<pair<int,int>>v;
    // Printing prime factors and their powers
    while (N > 1)
    {
        N /= s[N];
 
        // N is now N/s[N].  If new N also has smallest
        // prime factor as curr, increment power
        if (curr == s[N])
        {
            cnt++;
            continue;
        }
 
        v.push_back({curr,cnt});
 
        // Update current prime factor as s[N] and
        // initializing count as 1.
        curr = s[N];
        cnt = 1;
    }
    return v;
}

int main()
{
    ll tt=1;
    std::cin>>tt;
    while(tt--)
    {
        ll n,m,k;
        std::cin>>n>>m>>k;
        vector<ll>dist(n,-1);
        vector<int>vis(n);
        vector<vector<ll>>nodes(n+1);
        rep(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        priority_queue<pair<int,int>>pq;
        rep(i,0,k)
        {
            ll p,h;
            cin>>p>>h;
            p--;
            dist[p]=h;
            pq.push({h,p});
        }   
        int cnt=0;
        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(dist[u]>d)
            continue;
            cnt++;
            if(d==0)
            continue;
            for(int v:nodes[u])
            {
                if(dist[v]<d-1)
                {
                    dist[v]=d-1;
                    pq.push({d-1,v});
                }
            }
        }
        cout<<cnt<<"\n";
        rep(i,0,n)
        {
            if(dist[i]!=-1)
            cout<<i+1<<" ";
        }
    }
}   