#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

int M=1e9+7;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n+1)
    {
        ans=(ans*i)%M;
    }
    return ans%M;
}

ll power(ll a,ll b)
{
    ll ex=M-2;
    while(ex>0)
    {
        if(ex%2==1)
        a=(a*b)%M;
        b=(b*b)%M;
        ex/=2;
    }
    return a%M;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll x,y;
    map<ll,ll>m;
    rep(i,0,n)
    {
        cin>>x>>y;
        m[x]++;
    }
    ll fact[100001];
    fact[0]=1;
    fact[1]=1;
    rep(i,2,100001)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
    ll q=fact[n],p=1;
    for(auto x:m)
    {
        p=(p*fact[x.second])%M;
    }
    y=power(p,q);
    cout<<y%M<<"\n";
}   