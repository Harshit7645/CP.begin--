#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b)   for(ll i=a;i<b;i++)
int main()
{
    ll n,m,i;
    cin>>n>>m;
    vector <pair<ll,ll>>v(n);
    rep(i,0,m)
    {
        ll x;
        cin>>x;
        auto it =find(v.begin(),v.end(),x);
        if(it!=v.end())
        it->first++;
        else
        v.push_back({0,x});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if(n>m)
    cout<<"0\n";
    else{
        auto itr=v.begin()+n-1;
        cout<<itr->first<<endl;
    }
}