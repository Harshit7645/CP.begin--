#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
typedef __int128 lll;
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
        ll l,r;
        cin>>l>>r;
        //ll llog=log2(l),rlog=log2(r);
        //cout<<llog<<" "<<rlog<<"\n";
        //  vector<ll>move;
        ll l1=l,r1=r;
        // rep(i,2,32)
        // {
        //     ll val=pow(2,i);
        //     if(val>1e18)
        //     break;
        //     if(val>r)
        //     break;
        //     if(val-l1>0)
        //     move.push_back(val-l1);
        //     l1=max(l1,val);
        // }
        // rep(i,0,move.size())
        // {
        //     cout<<move[i]<<" ";
        // }
        // cout<<endl;
        // if(move.size()==0)
        // {
        //     ll ans=log2(l)/log2(log2(l));
        //     cout<<(ans*(r-l+1)%M)%M<<endl;
        // }
        //else
        {
            ll ans=0,cnt;
            l1=l;
            //ll x=log2(l1);
            //cout<<x<<" ";
            //while(l1<=r)
            // {
            //     if(ind>=move.size())
            //     break;
            //     ll val=x/log2(x);
            //     ans=(ans+(val*(move[ind])%M)%M)%M;
            //     //cout<<ans<<" ";
            //     l1+=move[ind];
            //     ind++;
            //     x++;
            // }
            // ll val=x/log2(x);
            // ans=(ans+(val*(r-(ll)pow(2,(ll)log2(r))+1)%M)%M)%M;
            // cout<<ans<<endl; 
            l1=l;
            r1=r;
            for(ll i=pow(2,__lg(l)),j;i<=r;i=j+1)
            {
                j=min(2*i-1,r);
                l1=max(i,l);
                r1=j;
                cnt=1;
                lll val=__lg(i),pwr=val;
                while(pwr<=r)
                {
                    ll range=min(pwr*val-1,(lll)r1)-max(pwr,(lll)l1)+1;
                    if(range>=0)
                    ans=(ans+range%M*cnt)%M;
                    pwr*=val;
                    cnt++;
                }
            }  
            //ll val=__lg(i);
            cout<<ans%M<<endl;
        }
    }
}   