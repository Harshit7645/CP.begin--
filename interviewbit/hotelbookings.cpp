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
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
static bool myCompare(pair<int,int> &p1, pair<int,int> &p2) {
    if(p1.first == p2.first) {
        return p1.second > p2.second; // if two times have same value then 'arrival time' must appear first in the sorted array
    }
    return p1.first < p2.first;
}
bool solve(vector<int>arrive,vector<int>depart,int K)
{
    int n=arrive.size();
    vector<pair<int,int>>ans;
    int i=0;
    for(i=0;i<n;i++)
    {
        ans.push_back({arrive[0],1});
        ans.push_back({depart[i],0});
    }  
    int maxrooms=0,cntofrooms=0;
    sort(ans.begin(),ans.end(),myCompare); 
    for(i=0;i<ans.size();i++)
    {
        if(ans[i].second==1){
        cntofrooms++;
        maxrooms=max(maxrooms,cntofrooms);
        }
        else
        cntofrooms--;
        if(maxrooms<=K)
        return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int>x={1,2,3};
    vector<int>y={2,3,4};
    int k=1;
    int t=solve(x,y,k);
    cout<<t;
}   