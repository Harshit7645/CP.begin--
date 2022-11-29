#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll k=0;k<t;k++)
    {
        ll n,i,nones=0,ans;
        cin>>n;
        ll arr[n];
        vector<ll>v;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1)
            nones++;
            else{
                if(nones>0)
            v.push_back(nones);
            nones=0;
            }
        }
        if(nones>0)
        v.push_back(nones);
        ans=0;
        for(i=0;i<v.size();i++)
        {
            ans+=v[i]*(v[i]+1)/2;
        }
        cout<<ans<<"\n";
    }
}