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
        ll l=0,r=n-1,wl=arr[0],wr=arr[n-1],left=-1,right=-1,f=-1;
        while(l<r)
        {
            if(wl<wr)
            {
           // f=0;
            l++;
            wl+=arr[l];
            }
            else if(wl>wr)
            {
                //f=1;
            r--;
            wr+=arr[r];
            }
            else{
                left=l;
                right=r;
                l++;
                wl+=arr[l];
            }
        }
        if(left!=-1)
        {
            cout<<left+1+n-right<<endl;
        }
        else
        cout<<"0\n";
    }
}