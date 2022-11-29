#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int countsort()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    map<ll,ll>m;
    rep(i,0,n)
    {
        cin>>arr[i];
        m[arr[i]]++;
    }
    ll k=0;
    for(auto x:m)
    {
        for(ll i=0;i<x.second;i++)
        arr[k++]=x.first;
    }
    rep(i,0,n)
    cout<<arr[i]<<" ";
}