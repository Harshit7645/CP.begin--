#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
ll binpow(ll,ll,ll);
long long binpow(long long a, long long b, long long m) {
    ll res;
    if(b==0)
    return 1;
    res=binpow(a,b/2,m);
    if(b%2)
    return (((res*res)%m)*a)%m;
    else
    return (res*res)%m;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,m;
        m=1000000007;
        cin>>a>>b;
        ll ans;
        ans=binpow(a,b,m);
        ans=ans%m;
        cout<<ans<<endl;
    }
}