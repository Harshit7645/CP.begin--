#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    ll M=1000000007;
    while(t--)
    {
        ll a,n;
        cin>>a>>n;
        if(a>=0)
        {
            ll c=pow(a,n/2);
            cout<<c%M<<endl;
        }
        else
        cout<<1<<endl;
    }
}