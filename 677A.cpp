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
    ll n,h;
    cin>>n>>h;
    ll arr[n];
    ll ans=n;
    rep(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]>h)
        ans++;
    }
    //cin>>arr[i];
    cout<<ans<<endl;
}