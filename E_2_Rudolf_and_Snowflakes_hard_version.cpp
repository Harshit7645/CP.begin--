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
vector<pair<ll,ll>> printDivisors(int n)
{
	// Note that this loop runs till square root
    vector<pair<ll,ll>>req;
	for (int i=2; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			// If divisors are equal, print only one
			if (n/i == i)
				req.push_back({i,i});

			else // Otherwise print both
            {
                req.push_back({i,n/i});
            }
		}
	}
    return req;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    set<ll>nums;
    rep(k,2,1000001) 
    {
        ll val = 1 + k;
        ll p = k*k;
        rep(cnt,3,64)
        {
            val += p;
            if (val > 1e18) break;
            nums.insert(val);
            if (p > (long long)(1e18) / k) 
            break;
            p *= k;
        }
    }
    while(tt--)
    {
        ll n;
        cin>>n;
        if(n<=6)
        {
            PNO;
            continue;
        }
        if(nums.find(n)!=nums.end())
        PYES;
        else
        {
            ll d=(1-4*(1-n));
            ll x=(-1+sqrt(d))/2;
            if(1+x+x*x==n || 1+(x+1)+(x+1)*(x+1)==n || 1+(x-1)*(x-1)+(x-1)==n)
            PYES;
            else
            PNO;
        }
    }
}   