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
        string a,b;
        cin>>a>>b;
        ll f=0;
        rep(i,0,a.length())
        {
            //string temp=a.substr(i,2);
            rep(j,0,b.length())
            {
                if(a[i]==b[j] && (i==a.length()-1 && j==b.length()-1))//||(a[i]==b[j] && i==0 && j==0)))
                {
                    f=1;
                    PYES;
                    cout<<"*"<<a[i]<<"\n";
                    break;
                }
                else if(a[0]==b[0])
                {
                    f=1;
                    PYES;
                    cout<<a[i]<<"*\n";
                    break;
                }
            }
            if(f)
            break;
        }
        if(!f){
        rep(i,0,a.length()-1)
        {
            string temp=a.substr(i,2);
            rep(j,0,b.length()-1)
            {
                string s1=b.substr(j,2);
                if(temp==s1)
                {
                    f=1;
                    PYES;
                    cout<<"*"<<temp<<"*\n";
                    break;
                }
            }
            if(f)
            break;
        }
        }
        if(!f)
        PNO;
    }
}