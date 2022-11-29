#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll  lcm(ll a,ll b)
{
    ll ans=0;
    ans=a*b/gcd(a,b);
    return ans;
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
        ll a[n];
        rep(i,0,n)
        {
            cin>>a[i];
        }
        ll f=0,g=0;
        if(n<=2)
        {
            PYES;
            continue;
        }
        ll b[n+1];
        b[0]=a[0];
        b[1]=a[0];
        rep(i,1,n)
        {
            b[i+1]=a[i];
            g=gcd(a[i],b[i]);
            g=a[i]/g;
            b[i]=g*b[i];
        }
        rep(i,0,n)
        {
            if(gcd(b[i],b[i+1])!=a[i])
            {
                f=1;
                break;
            }
        }
        if(f)
        PNO;
        else
        PYES;
    }
}