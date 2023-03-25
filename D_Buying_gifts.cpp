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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n),b(n);
        vector<pair<ll,ll>>duo;
        rep(i,0,n)
        {
            cin>>a[i]>>b[i];
            duo.push_back({a[i],b[i]});
        }
        sort(duo.begin(),duo.end());
        vector<ll>suffmax(n+1);
        suffmax[n-1]=duo[n-1].second;
        suffmax[n]=-1e9;
        //ll tmax=-1;
        repr(i,n-2,0)
        {
            //tmax=max(tmax,duo[i].second);
            suffmax[i]=max(suffmax[i+1],duo[i].second);
        }
        multiset<ll>m;
        ll ans=10e9;
        ll x=0,y=0;
        rep(i,0,n)
        {
            x=duo[i].first,y=duo[i].second;
            ans=min(ans,abs(x-suffmax[i+1]));
            ll temp=0;
            if(!m.empty())
            {
                auto it=m.lower_bound(x);
                if(it!=m.end())
                {
                    temp=*it;
                    if(temp>suffmax[i+1])
                    ans=min(ans,abs(temp-x));
                }
                if(it!=m.begin())
                {
                    it--;
                    temp=*it;
                    if(temp>suffmax[i+1])
                    ans=min(ans,abs(x-temp));
                }
            }
            m.insert(duo[i].second);
        }
        cout<<ans<<"\n";
    }
}