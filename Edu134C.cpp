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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],b[n];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        rep(i,0,n)
        {
            cin>>b[i];
        }
        //sort(b,b+n);
        ll j=0;
        rep(i,0,n)
        {
            while(a[i]>b[j])
            j++;
            cout<<abs(a[i]-b[j])<<" ";
        }
        cout<<"\n";
        j=0;
        rep(i,0,n)
        {
            j=max(i,j);
            while(j+1<n && a[j+1]<=b[j])
            j++;
            cout<<abs(b[j]-a[i])<<" ";
        }
        cout<<"\n";
    }
}