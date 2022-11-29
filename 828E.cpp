#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll f=0;
        ll x=-1,y=-1;
        rep(i,a+1,min(2*a+1,c+1))
        {
            rep(j,b+1,min(2*b+1,d+1))
            {
                if((i*j)%(a*b)==0)
                {
                    x=i,y=j;
                    f=1;
                    break;
                }
            }
            if(f)
            break;
        }
        cout<<x<<" "<<y<<"\n";

    } 
}