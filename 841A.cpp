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
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        rep(i,0,n-1)
        {
            ll temp=arr[i]*arr[i+1];
            arr[i]=1;
            arr[i+1]=temp;
        }
        ll sum=0;
        rep(i,0,n)
        {
            sum+=arr[i];
        }
        cout<<sum*2022<<endl;
    }
}