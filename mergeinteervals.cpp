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
vector<pair<int,int>>solve(vector<pair<int,int>>intervals,pair<int,int>newInterval)
{
    int n=intervals.size(),i=0,f=0;
    int merst=0,merend=0;
    vector<pair<int,int>>ans;
    if(intervals.size()==0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    merst=min(newInterval.first,newInterval.second);
    merend=max(newInterval.first,newInterval.second);
    int flag[n];
    for(i=0;i<n;i++)
    {
        flag[i]=0;
    }
    f=0,i=0;
    while(i<n)
    {
        if(merend>=intervals[i].first)
        {
            flag[i]=1;
        }
        i++;
    }
    i=0;
    while(i<n)
    {
        if(merst>intervals[i].second)
        flag[i]=0;
        i++;
    }
    // for(i=0;i<n;i++)
    // {
    //     cout<<flag[i]<<" ";
    // }
    f=0;
    int l=0,r=0,nextr=0;
    for(i=0;i<n;i++)
    {
        if(f==0 && flag[i]==1)
        {
            f=1;
            l=min(merst,intervals[i].first);
        }
        if((flag[i]==1 && flag[i+1]==0)||(flag[i]==1 && i==n-1))
        {
            ans.push_back({l,max(intervals[i].second,merend)});
        }
        if(flag[i]==0)
        {
            ans.push_back({intervals[i].first,intervals[i].second});
        }
    }
    //cout<<l<<"sefjbwif";
    if(f==0)
    {
        if(merend<intervals[0].first)
        {
            ans.insert(ans.begin(),{merst,merend});
        }
        else
        ans.push_back({merst,merend});
    }
    return ans;
}
int main()
{
    vector<pair<int,int>>inter={{1,2},{3,6}};
    pair<int,int>mer={10,8};
    vector<pair<int,int>>ans=solve(inter,mer);
    rep(i,0,ans.size())
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
}   