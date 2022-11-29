#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        // if(n%2==0 || m%2==0)
        // cout<<"Burenka\n";
        if(n==m)
        cout<<"Tonya\n";
        else if((n%2==0 && m%2==1) || (n%2==1 && m%2==0))
        cout<<"Burenka\n";
        else
        cout<<"Tonya\n";

    }
}