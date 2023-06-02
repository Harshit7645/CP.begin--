#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
bool goodgroup(ll x,vector<ll>a,ll K)
{
    int n=a.size();
    int sum=0;
    rep(i,0,n)
    {
        sum+=min(x,a[i]);
    }
    if(sum>=x*K)
    return true;
    else
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,i,k;
        cin>>n>>k;
        ll a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        ll st=0,en=200000000000000/k,mid=(st+en+1)/2;
        while(st<en){
        ll ans=0;
        for(i=0;i<n;i++){
        ans+=min(a[i],mid);
        }
        if(ans>=mid*k)st=mid;
        else en=mid-1;
        mid=(st+en+1)/2;
        }
        cout<<st<<endl;
    }
}