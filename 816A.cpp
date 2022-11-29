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
        if(n!=1 && m!=1)
        cout<<(n+m-1)+min(n,m)-1<<"\n";
        else if(n==1 && m==1)
        cout<<0<<"\n";
        else 
        cout<<max(n,m)<<"\n";
    }
}