#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        ll n;
        cin>>n;
        ll arr[n],s=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            s+=arr[i];
        }
        if(s==0){
        ll x=n-1;
        while(x>=0 && arr[x]==0)
        {
            x--;
        }
        ll f=0;
        rep(i,0,x)
        {
            s+=arr[i];
            if(s<=0)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            PNO;
            continue;
        }
        else
        PYES;
    }
    else
    PNO;
    }
}