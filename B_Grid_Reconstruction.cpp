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
    ll tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll x=1,y=2*n;
        ll arr[2][n];
        rep(i,0,2)
        {
            rep(j,0,n)
            {
                arr[i][j]=0;
            }
        }
        arr[1][n-1]=2*n;
        arr[0][0]=2*n-1;
        rep(i,1,n)
        {
            arr[0][i]=x;
            arr[1][i-1]=x+1;
            x+=2;
            i++;
        }
        rep(i,2,n)
        {
            arr[0][i]=x;
            arr[1][i-1]=x+1;
            x+=2;
            i++;
        }
        rep(i,0,2)
        {
            rep(j,0,n)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}   