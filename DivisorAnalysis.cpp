#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll powi(ll b,ll exp);
ll powi(ll b,ll exp)
{
    ll ans=1,i,m=1000000007;
    for(i=1;i<=exp;i++)
    {
        ans=(ans*b)%m;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    vector<ll>x,k;
    ll m=powi(10,9)+7;
    for(ll u=0;u<n;u++)
    {
        ll r,z;
        cin>>r>>z;
        x.push_back(r);
        k.push_back(z);
    }
    ll nod=1;
    rep(i,0,n)
    {
        nod*=(k[i]+1)%m;
    }
    ll sum=0,j,ans=1;
    rep(i,0,n)
    {
        sum=0;
        for(j=0;j<=k[i];j++)
        {
            sum+=powi(x[i],j)%m;
        }
        ans*=sum;
    }
    ll pod,N=1;
    rep(i,0,n)
    {
        N*=powi(x[i],k[i])%m;
    }
    pod=powi(N,nod/2)%m;
    cout<<nod%m<<" "<<ans%m<<" "<<pod<<" ";

}