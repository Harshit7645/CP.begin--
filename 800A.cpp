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
        ll a,b;
        cin>>a>>b;
        if((min(a,b)/2)%2==0){
        rep(i,0,min(a,b))
        {
            cout<<"01";
        }
        }
        else
        {
            rep(i,0,min(a,b))
            {
                cout<<"01";
            }
        }
        
        rep(i,0,a-b)
        {
            cout<<"0";
        }
        rep(i,0,b-a)
        {
            cout<<"1";
        }
        cout<<endl;
    }
}