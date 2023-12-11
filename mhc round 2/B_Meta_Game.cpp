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
vector<ll> primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    vector<ll>req;
    while (n % 2 == 0) 
    { 
        req.push_back(2);
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            req.push_back(i); 
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        req.push_back(n);
    return req;
}   
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("ready_go_part_1_validation_input.txt", "r", stdin);
    //freopen("ready_go_part_1_validation_output.txt", "w", stdout);
    ll tt;
    cin>>tt;
    rep(xx,1,tt+1)
    {
        cout<<"Case #"<<xx<<": ";
        ll n;
        cin>>n;
        ll a[n],b[n];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,n)
        {
            cin>>b[i];
        }
        vector<ll>v(n);
        rep(i,0,n)
        {
            if(a[i]>b[i])
            v[i]=1;
            else if(a[i]<b[i])
            v[i]=-1;
            else
            v[i]=0;
        }
        rep(i,0,n)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        ll c1=0,c2=0;
        ll f=0;
        if(v[0]==1)
        {
            if(n%2==0)
            {
                ll i=0,pos=-1;
                while(v[i]==1 && i<n)
                {
                    i++;
                }
                pos=i; 
                while(v[i]==-1 && i<n)
                {
                    i++;
                }
                if(i==n)
                cout<<abs(pos-n/2)<<endl;
                else
                cout<<"-1\n";
            }
        }
        else
        {
            if(n%2==0)
            {
                rep(i,0,n)
                {
                    if(v[i]==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                {
                    cout<<"-1\n";
                    continue;
                }
                ll i=0,pos=-1;
                while(v[i]==-1 && i<n)
                {
                    i++;
                }
                pos=i; 
                while(v[i]==1 && i<n)
                {
                    i++;
                }
                if(i==n)
                cout<<abs(pos-n/2)<<endl;
                else
                cout<<"-1\n";
            }
            else
            {
                ll cnt0=0;
                rep(i,0,n)
                {
                    if(v[i]==0)
                    {
                        cnt0++;
                    }
                }
                if(cnt0>=2)
                {
                    cout<<"-1\n";
                    continue;
                }
                if(v[0]==0 || v[n-1]==0)
                {
                    ll c3=0,c4=0;
                    rep(i,0,n)
                    {
                        c3+=(v[i]==1);
                        c4+=(v[i]==-1);
                    }
                    if(c3*c4==0)
                    {
                        cout<<n/2<<"\n";
                        continue;
                    }
                    else
                    {   
                        cout<<"-1\n";
                        continue;
                    }
                }
                ll i=0,pos=-1;
                while(v[i]==-1 && i<n)
                {
                    i++;
                }
                pos=i; 
                while(v[i]==1 && i<n)
                {
                    i++;
                }
                if(i==n)
                cout<<abs(pos-n/2)<<endl;
                else
                cout<<"-1\n";
            }
        }
        if(f)
        cout<<"-1\n";
    }
}  