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
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n)
        {
            cin>>a[i];
        } 
        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }
        ll b[n];
        rep(i,0,n)
        {
            b[i]=i+1;
        }
        rep(i,0,n-1)
        {
            if(b[i]==a[i])
            {
                swap(b[i],b[i+1]);
                i++;
            }
        }
        if(b[n-1]==a[n-1])
        {
            swap(b[n-1],b[n-2]);
        }
        rep(i,0,n)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}