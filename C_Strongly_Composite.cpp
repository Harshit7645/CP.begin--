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
    return (fact(n)/((fact(r))*(fact(n-r))));
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
void primes(int N, int s[]){
   vector <bool> prime(N+1, false);
   for (int i=2; i<=N; i+=2)
      s[i] = 2;
   for (int i=3; i<=N; i+=2){
      if (prime[i] == false){
         s[i] = i;
         for (int j=i; j*i<=N; j+=2){
            if (prime[i*j] == false){
               prime[i*j] = true;
               s[i*j] = i;
            }
         }
      }
   }
}
vector<pair<ll,ll>> generatePrimeFactors(int N) {
   int s[N+1];
   primes(N, s);
   //cout<<"Factor\tPower"<<endl;
   vector<pair<ll,ll>>req;
   int prime = s[N];
   int power = 1;
   while (N > 1){
      N /= s[N];
      if (prime == s[N]){
         power++;
         continue;
      }
      //cout<<prime<<"\t"<<power<<endl;
      req.push_back({prime,power});
      prime = s[N];
      power = 1;
   }
   return req;
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
        ll num=1;
        ll oddpow=0,ans=0;
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            ll x=arr[i];
            for(ll j=2;j*j<=x;j++)
            {
                while(x%j==0){
                x/=j;
                m[j]++;
                }
            }
            if(x>1)
            m[x]++;
        }
        // for(auto x:m)
        // cout<<x.first<<" "<<x.second<<"\n";
        ans=0;
        for(auto x:m)
        {
            ans+=x.second/2;
            if(x.second%2==1)
            oddpow++;
        }
        ans+=oddpow/3;
        cout<<ans<<"\n";
    }
}   