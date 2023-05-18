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
int maxsubarray(vector<int>a)
{
    int i=0,n=a.size(),sum=0,maxsum=0,f=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        f=1;
    }
    if(!f)
    {
        int large=-1e9;
        for(i=0;i<n;i++)
        {
            large=max(large,a[i]);
        }
        return large;
    }
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum<0)
        {
            sum=0;
        }
        if(a[i]>0)
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int>a={-2,-5};
    int ans=maxsubarray(a);
    cout<<ans<<"\n";
}   