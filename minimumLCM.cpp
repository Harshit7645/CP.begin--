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
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
  
// Function to print the divisors
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
        vector<ll>req;
        req=printDivisors(n);
        ll lc=INT64_MAX,ans=1;
        rep(i,0,req.size())
        {
            if(req[i]==0 || req[i]==n)
            continue;
            if(lcm(req[i],n-req[i])<lc)
            {
                lc=lcm(req[i],n-req[i]);
                ans=req[i];
            }
        }
        cout<<ans<<" "<<n-ans<<endl;
    }
}