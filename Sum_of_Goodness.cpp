#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define M 1000000007

unsigned long long fac[200005];

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
   
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    fac[0]=1;
    for (int i = 1; i <= 200000; i++)
        fac[i] = (fac[i - 1] * i) % M;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        // rep(i,0,n)
        // cout<<arr[i]<<" ";
        // cout<<"\n";
        ll ans=0;
        rep(i,0,n)
        {
            int avail,req;
            if(arr[i]-1<=i)
            {
                ll test=nCrModPFermat(i,arr[i]-1,M);
                test*=power(2,n-i-1,M);
                test=test%M;
                ans+=test;
                ans=ans%M;
            }
        }
        cout<<ans<<"\n";
    }
}   