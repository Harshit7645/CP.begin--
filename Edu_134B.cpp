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
        ll n,m,sx,sy,d;
        cin>>n>>m>>sx>>sy>>d;
        if(sx-d>=1 && sx+d<m && sy-d>=1 && sy+d<n)
        cout<<n+m-2<<"\n";
        else
        cout<<"-1\n";

        //cout<<sx-d<<" "<<sx+d;
    }
}