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
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll l=0,r=2e9+2;
        while(l+1<r)
        {
            ll res=0,m=l+r>>1;
            rep(j,n/2,n)
            {
                res+=max(0ll,m-arr[j]);
            }
            if(res<=k)
            l=m;
            else 
            r=m;
        }
        cout<<l<<endl;
}