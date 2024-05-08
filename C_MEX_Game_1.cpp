#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        map<ll,ll>m;
        rep(i,0,n)
        {
            m[arr[i]]++;
        }
        ll first=-1,max=0;
        for(auto x:m)
        {
            if(x.second==1)
            {
                first=x.first;
                break;
            }
        }
        ll f=0,ans=0;
        vector<ll>alice;
        // alice.push_back(first);
        // ll flagf=1;
        // rep(i,0,n)
        // {
        //     if(flagf && arr[i]==first)
        //     {
        //         flagf=0;
        //         continue;
        //     }
        //     if(f){
        //         alice.push_back(arr[i]);
        //     }
        //     f=1-f;
        // }
        ll ogfirst=first;
        m.erase(first);
        first=-1;
        for(auto x:m)
        {
            if(x.second==1)
            {
                first=x.first;
                break;
            }
        }
        ll flagl=1,flagf=1;
        // rep(i,0,n)
        // {
        //     if(flagf && arr[i]==ogfirst)
        //     {
        //         flagf=0;
        //         alice.push_back(arr[i]);
        //         f=1-f;
        //         continue;
        //     }
        //     else if(flagl && arr[i]==first)
        //     {
        //         flagl=0;
        //         f=1-f;
        //         continue;
        //     }
        //     if(f){
        //         alice.push_back(arr[i]);
        //     }
        //     f=1-f;
        // }
        // sort(alice.begin(),alice.end());
        // rep(i,0,alice.size())
        // {
        //     // cout<<alice[i]<<" ";
        //     if(alice[i]==ans)
        //     ans++;
        // }
        // ans=0;
        // rep(i,1,n)
        // {
        //     if(m[i]>=i+1)
        //     alice.push_back(i);
        // }
        ll np=0;
        m[ogfirst]++;
        rep(i,0,n+1)
        {
            if(m[i])
            np++;
            else
            break;
        }
        // cout<<first<<" "<<np<<"\n";
        if(first==-1)
        cout<<np<<"\n";
        else
        cout<<min(np,first)<<"\n";
    }
}   