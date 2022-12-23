#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        map<ll,ll>m;
        rep(i,0,n)
        {
            m[arr[i]]++;
        }
        ll f=0;
        for(auto x:m)
        {
            if(x.second>=3)
            {
                f=1;
                cout<<x.first<<"\n";
                break;
            }
        }
        if(f==0)
        cout<<"-1\n";
    }
}