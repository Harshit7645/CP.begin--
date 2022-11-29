#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
ll binpow1(ll,ll,ll);
long long binpow1(long long a, long long b, long long m) {
    ll res;
    if(b==0)
    return 1;
    res=binpow1(a,b/2,m);
    if(b%2)
    return (((res*res)%m)*a)%m;
    else
    return (res*res)%m;

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,m=1000000007,res;
        cin>>a>>b>>c;
        ll ans;
        ans=binpow1(b,c,m-1);
        res=binpow1(a,ans,m);
        cout<<res<<endl;
    }
}