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
    ll n,m;
    cin>>n>>m;
    ll arr[m];
    rep(i,0,m)
    cin>>arr[i];
    sort(arr,arr+m);
    ll diff=1e9;
    rep(i,0,m-n+1)
    {
        diff=min(diff,arr[i+n-1]-arr[i]);
    }
    cout<<diff<<endl;
}