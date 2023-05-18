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
struct Interval{
    int start;
    int end;
};
vector<Interval>solve(vector<Interval>A)
{
    int n=A.size(),i=0,j=0;
    vector<Interval>ans;
    ans.push_back({A[0]});
    for(i=1;i<n;i++)
    {
        if(ans[ans.size()-1].end>=A[i].start)
        ans[ans.size()-1].end=max(ans[ans.size()-1].end,A[i].end);
        else
        ans.push_back(A[i]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<Interval>v={{1,10},{2,9},{3,8},{15,18},{16,19},{18,22},{20,25}};
    vector<Interval>ans;
    ans=solve(v);
    for(auto x:ans)
    cout<<x.start<<" "<<x.end<<"\n";
}   