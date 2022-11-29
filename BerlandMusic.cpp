#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll t;
    cin>>t;
    for(ll x=0;x<t;x++)
    {
        ll n,i;
        cin>>n;
        vector <ll> v(n);
        rep(i,0,n)
        {
            cin>>v[i];
        }
        string s;
        cin>>s;
        vector<pair<ll,ll>> liked,disliked;
        map<ll,ll>m;
        rep(i,0,n)
        {
            if(s[i]=='1')
            liked.push_back({v[i],0});
            else
            disliked.push_back({v[i],0});
        }
        sort(liked.begin(),liked.end());
        sort(disliked.begin(),disliked.end());
        rep(i,0,liked.size())
        {
            m[liked[i].first]=i+1+disliked.size();
        }
        rep(i,0,disliked.size())
        {
            m[disliked[i].first]=i+1;
        }
        for(i=0;i<n;i++)
        {
            cout<<m[v[i]]<<" ";
        }
        cout<<endl;
    }
}