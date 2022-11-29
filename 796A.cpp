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
        ll x;
        cin>>x;
        ll f=0;
        ll ans=0;
        if(x==1)
        {
            cout<<3<<endl;
            continue;
        }
        if(x%2==1)
        {
            if(x>1)
            cout<<"1\n";
            else
            cout<<"3\n";
        }
        else
        {
            if(!(x&(x-1)))
            {
                cout<<x+1<<endl;
            }
            else
            cout<<(x&~(x-1))<<endl;
        }
    }
}